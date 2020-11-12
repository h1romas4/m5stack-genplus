#include <M5Core2.h>
extern "C" {
#include "genplus_main.h"
#include "fileio.h"
#include "esp_attr.h"
}

#define SOUND_FREQUENCY 48000
#define SOUND_SAMPLES_SIZE  2048

#define VIDEO_WIDTH  320
#define VIDEO_HEIGHT 240

EXT_RAM_ATTR static uint16_t frame_buffer[VIDEO_WIDTH * VIDEO_HEIGHT];
EXT_RAM_ATTR static short sound_buffer[SOUND_SAMPLES_SIZE];

void setup()
{
    // init M5stack
    M5.begin();
    // load rom (TODO: ROM SIZE FIXED 131072 BYTE)
    File fs = SD.open("/COLUMNS.BIN");
    fs.read(get_rom_area(), 131072);
    // initialize emulator
    genplus_init(frame_buffer, VIDEO_WIDTH, VIDEO_HEIGHT, SOUND_FREQUENCY);
    // close fs
    fs.close();
}

void loop()
{
    // update M5Stack
    M5.update();
    // update emulator
    genplus_loop(sound_buffer);
    // display
    M5.Lcd.drawBitmap(0, 0, VIDEO_WIDTH, VIDEO_HEIGHT, frame_buffer);
}
