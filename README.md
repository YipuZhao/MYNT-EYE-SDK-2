# MYNT® EYE S SDK

[![](https://img.shields.io/badge/MYNT%20EYE%20S%20SDK-2.3.0-brightgreen.svg?style=flat)](https://github.com/slightech/MYNT-EYE-S-SDK)

## Overview

MYNT® EYE S SDK is a cross-platform library for MYNT® EYE Standard cameras.

The following platforms have been tested:

* Windows 10
* Ubuntu 16.04 / 14.04
* Jetson TX2

Please follow the guide doc to install the SDK on different platforms.

## Documentations

* [API Doc](https://github.com/slightech/MYNT-EYE-S-SDK/releases): API reference, some guides and data spec.
  * en: [![](https://img.shields.io/badge/Download-PDF-blue.svg?style=flat)](https://github.com/slightech/MYNT-EYE-S-SDK/files/2764152/mynt-eye-s-sdk-apidoc-2.3.0-en.pdf) [![](https://img.shields.io/badge/Download-HTML-blue.svg?style=flat)](https://github.com/slightech/MYNT-EYE-S-SDK/files/2764156/mynt-eye-s-sdk-apidoc-2.3.0-en.zip) [![](https://img.shields.io/badge/Online-HTML-blue.svg?style=flat)](https://slightech.github.io/MYNT-EYE-S-SDK/)
  * zh-Hans: [![](https://img.shields.io/badge/Download-PDF-blue.svg?style=flat)](https://github.com/slightech/MYNT-EYE-S-SDK/files/2764160/mynt-eye-s-sdk-apidoc-2.3.0-zh-Hans.pdf) [![](https://img.shields.io/badge/Download-HTML-blue.svg?style=flat)](https://github.com/slightech/MYNT-EYE-S-SDK/files/2764173/mynt-eye-s-sdk-apidoc-2.3.0-en.zip) [![](https://img.shields.io/badge/Online-HTML-blue.svg?style=flat)](http://doc.myntai.com/resource/api/mynt-eye-s-sdk-apidoc-2.3.0-zh-Hans/mynt-eye-s-sdk-apidoc-2.3.0-zh-Hans/index.html)
* [Guide Doc](https://github.com/slightech/MYNT-EYE-S-SDK-Guide/releases): How to install and start using the SDK.
  * en: [![](https://img.shields.io/badge/Download-PDF-blue.svg?style=flat)](https://github.com/slightech/MYNT-EYE-S-SDK-Guide/files/2764143/mynt-eye-s-sdk-guide-2.3.0-en.pdf) [![](https://img.shields.io/badge/Download-HTML-blue.svg?style=flat)](https://github.com/slightech/MYNT-EYE-S-SDK-Guide/files/2764145/mynt-eye-s-sdk-guide-2.3.0-en.zip) [![](https://img.shields.io/badge/Online-HTML-blue.svg?style=flat)](https://slightech.github.io/MYNT-EYE-S-SDK-Guide/)
  * zh-Hans: [![](https://img.shields.io/badge/Download-PDF-blue.svg?style=flat)](https://github.com/slightech/MYNT-EYE-S-SDK-Guide/files/2764150/mynt-eye-s-sdk-guide-2.3.0-zh-Hans.pdf) [![](https://img.shields.io/badge/Download-HTML-blue.svg?style=flat)](https://github.com/slightech/MYNT-EYE-S-SDK-Guide/files/2764163/mynt-eye-s-sdk-guide-2.3.0-zh-Hans.zip) [![](https://img.shields.io/badge/Online-HTML-blue.svg?style=flat)](http://doc.myntai.com/resource/sdk/mynt-eye-s-sdk-guide-2.3.0-zh-Hans/mynt-eye-s-sdk-guide-2.3.0-zh-Hans/index.html)

> Supported languages: `en`, `zh-Hans`.

## Firmwares

[MYNTEYE_BOX]: http://doc.myntai.com/mynteye/s/download

Get firmwares from our online disks: [MYNTEYE_BOX][].

## Usage

In short,

```bash
$ make
Usage:
  make help            show help message
  make apidoc          make api doc
  make opendoc         open api doc (html)
  make init            init project
  make build           build project
  make test            build test and run
  make install         install project
  make samples         build samples
  make tools           build tools
  make ros             build ros wrapper
  make clean|cleanall  clean generated or useless things
```

Init project, build samples and run someone.

```bash
make init
make samples
./samples/_output/bin/device/camera_d
```

## Mirrors

国内镜像：[码云](https://gitee.com/mynt/MYNT-EYE-S-SDK)。

## License

This project is licensed under the [Apache License, Version 2.0](LICENSE). Copyright 2018 Slightech Co., Ltd.
