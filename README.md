# m5stack-genplus

[Genesis-Plus-GX](https://github.com/ekeeke/Genesis-Plus-GX) M5Stack Core2 porting

![](https://raw.githubusercontent.com/h1romas4/m5stack-genplus/master/docs/boot-01.jpg)

## Require

```
$ xtensa-esp32-elf-gcc -v
gcc version 5.2.0 (crosstool-NG crosstool-ng-1.22.0-96-g2852398)
```

## Build

```
git clone --recursive https://github.com/h1romas4/m5stack-genplus.git
cd m5stack-genplus
# This repository includes eps-idf
export IDF_PATH=$(pwd)/esp-idf
make flash monitor
```

## Run

`main/genplus.cpp`
```
    // load rom (TODO: ROM SIZE FIXED 131072 BYTE)
    File fs = SD.open("/COLUMNS.BIN");
    fs.read(get_romfile(), 131072);
```

`components/genplus/component.mk`
```
CFLAGS := \
    -DMAXROMSIZE=131072 \
```

## Dependencies

|name|version|hash|
|-|-|-|
|[esp-idf](https://github.com/espressif/esp-idf)|latest-3.3|`b64b375`|
|[arduino](https://github.com/espressif/arduino-esp32)|latest|`3da04ce`|
|[M5Core2](https://github.com/m5stack/M5Core2)|latest|`cc551d4`|

## License

[Genesis-Plus-GX](https://github.com/ekeeke/Genesis-Plus-GX/blob/master/LICENSE.txt) License

## Thanks!

[Genesis-Plus-GX](https://github.com/ekeeke/Genesis-Plus-GX)
