#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <types.h>
#include "esp_attr.h"
#include "loadrom.h"
#include "fileio.h"
#include "genplus_main.h"

/* TODO: */
EXT_RAM_ATTR unsigned char romfile[MAXROMSIZE];

int load_archive(char *filename, unsigned char *buffer, int maxsize, char *extension)
{
    /* TODO: load rom */
    memcpy(buffer, romfile, maxsize);

    /* set extention */
    strncpy(extension, "BIN", 3);
    extension[3] = 0;

    /* TODO: */
    return maxsize;
}

/* TODO: */
unsigned char* get_romfile()
{
    return romfile;
}
