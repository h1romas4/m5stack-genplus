#include <stdint.h>
#include "esp_log.h"

#include "genplus_main.h"
#include "shared.h"
#include "md_ntsc.h"
#include "sms_ntsc.h"

md_ntsc_t *md_ntsc;
sms_ntsc_t *sms_ntsc;

struct _zbank_memory_map zbank_memory_map[256];

int sdl_input_update(void) {
    return 1;
}

int genplus_init(uint16_t *frame_buffer, uint16_t width, uint16_t height, uint16_t sound_frequency)
{
    // system init
    error_init();
    set_config_defaults();

    // video ram init
    memset(&bitmap, 0, sizeof(bitmap));
    bitmap.width      = width;
    bitmap.height     = height;
    bitmap.pitch      = width * 2;
    bitmap.data       = (uint8_t *)frame_buffer;
    bitmap.viewport.changed = 3;

    // load rom
    load_rom("COLUMS.BIN");
    printf("copyright: %s\n", rominfo.copyright);
    printf("product no: %s\n", rominfo.product);
    // printf("romstart: %u\n", rominfo.romstart);
    // printf("romend(genplus endian bug): %u\n", rominfo.romend);

    // emurator init
    audio_init(sound_frequency, 0);
    genplus_system_init();
    system_reset();

    // init result
    // t_bitmap bitmap;
    // t_snd snd;
    printf("mcycles_vdp: %d\n", mcycles_vdp);
    printf("system_hw: %d\n", system_hw);
    printf("system_bios: %d\n", system_bios);
    printf("system_clock: %d\n", system_clock);
    printf("SVP_cycles: %d\n", SVP_cycles);

    return 0;
}

int genplus_loop(short *sound_buffer)
{
    system_frame_gen(0);
    int sampling_size = audio_update(sound_buffer) * 2;
    // lcd_set_area(0, 0, 320 - 1, 240 - 1);
    // tft_write_half(frame_buffer, 320 * 240);
}
