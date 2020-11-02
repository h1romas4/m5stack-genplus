
#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdint.h>

#define MAX_INPUTS 8

extern int debug_on;
extern int log_error;
extern int sdl_input_update(void);
extern unsigned char *rom;

int genplus_init(uint16_t *frame_buffer, uint16_t width, uint16_t height, uint16_t sound_frequency);
int genplus_loop(short *sound_buffer);

#endif /* _MAIN_H_ */
