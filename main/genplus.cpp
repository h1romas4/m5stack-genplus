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
    M5.begin();
    unsigned char* ptr = get_romfile();
    genplus_init(frame_buffer, VIDEO_WIDTH, VIDEO_HEIGHT, SOUND_FREQUENCY);
}

void loop()
{
    M5.update();
    genplus_loop(sound_buffer);
}
