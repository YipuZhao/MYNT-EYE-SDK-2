// Copyright 2018 Slightech Co., Ltd. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "mynteye/device/motions.h"

#include "mynteye/logger.h"
#include "mynteye/device/channel/channels.h"

MYNTEYE_BEGIN_NAMESPACE

Motions::Motions(std::shared_ptr<Channels> channels)
    : channels_(channels),
      motion_callback_(nullptr),
      motion_datas_enabled_(false),
      is_imu_tracking(false) {
  CHECK_NOTNULL(channels_);
  VLOG(2) << __func__;
}

Motions::~Motions() {
  VLOG(2) << __func__;
}

void Motions::SetMotionCallback(motion_callback_t callback) {
  motion_callback_ = callback;
  if (motion_callback_) {
    accel_range = channels_->GetControlValue(Option::ACCELEROMETER_RANGE);
    if (accel_range == -1)
      accel_range = channels_->GetAccelRangeDefault();

    gyro_range = channels_->GetControlValue(Option::GYROSCOPE_RANGE);
    if (gyro_range == -1)
      gyro_range = channels_->GetGyroRangeDefault();

    channels_->SetImuCallback([this](const ImuPacket &packet) {
      if (!motion_callback_ && !motion_datas_enabled_) {
        return;
      }
      for (auto &&seg : packet.segments) {
        auto &&imu = std::make_shared<ImuData>();
        // imu->frame_id = seg.frame_id;
        // if (seg.offset < 0 &&
        //     static_cast<uint32_t>(-seg.offset) > packet.timestamp) {
        //   LOG(WARNING) << "Imu timestamp offset is incorrect";
        // }
        imu->frame_id = seg.frame_id;
        imu->timestamp = seg.timestamp;
        imu->flag = seg.flag;
        imu->temperature = seg.temperature / 326.8f + 25;
        imu->accel[0] = seg.accel[0] * 1.f * accel_range / 0x10000;
        imu->accel[1] = seg.accel[1] * 1.f * accel_range / 0x10000;
        imu->accel[2] = seg.accel[2] * 1.f * accel_range / 0x10000;
        imu->gyro[0] = seg.gyro[0] * 1.f * gyro_range / 0x10000;
        imu->gyro[1] = seg.gyro[1] * 1.f * gyro_range / 0x10000;
        imu->gyro[2] = seg.gyro[2] * 1.f * gyro_range / 0x10000;

        std::lock_guard<std::mutex> _(mtx_datas_);
        motion_data_t data = {imu};
        if (motion_datas_enabled_) {
          motion_datas_.push_back(data);
        }

        motion_callback_(data);
      }
    });
  } else {
    channels_->SetImuCallback(nullptr);
  }
}

void Motions::DoMotionTrack() {
  channels_->DoImuTrack();
}

void Motions::StartMotionTracking() {
  if (!is_imu_tracking) {
    channels_->StartImuTracking();
    is_imu_tracking = true;
  } else {
    LOG(WARNING) << "Imu is tracking already";
  }
}

void Motions::StopMotionTracking() {
  if (is_imu_tracking) {
    channels_->StopImuTracking();
    is_imu_tracking = false;
  }
}

void Motions::EnableMotionDatas(std::size_t max_size) {
  if (max_size <= 0) {
    LOG(WARNING) << "Could not enable motion datas with max_size <= 0";
    return;
  }
  motion_datas_enabled_ = true;
  motion_datas_max_size = max_size;
}

Motions::motion_datas_t Motions::GetMotionDatas() {
  if (!motion_datas_enabled_) {
    LOG(FATAL) << "Must enable motion datas before getting them, or you set "
                  "motion callback instead";
  }
  std::lock_guard<std::mutex> _(mtx_datas_);
  motion_datas_t datas = motion_datas_;
  motion_datas_.clear();
  return datas;
}

MYNTEYE_END_NAMESPACE
