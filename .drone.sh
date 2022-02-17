#!/bin/sh
# SPDX-License-Identifier: GPL-2.0-only
set -eux

nproc && grep Mem /proc/meminfo && df -hT .
apk add build-base dtc dtc-dev gcc-arm-none-eabi git python3 tar

gcc -shared -o faccessat.so faccessat.c
export LD_PRELOAD=$PWD/faccessat.so

make -j$(nproc) TOOLCHAIN_PREFIX=arm-none-eabi- "$@"
