#
# Main Makefile. This is basically the same as a component makefile.
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)

COMPONENT_SRCDIRS := core core/z80 core/m68k core/input_hw core/sound core/cart_hw core/cart_hw/svp core/ntsc m5stack
COMPONENT_ADD_INCLUDEDIRS := core m5stack core/cart_hw core/cart_hw/svp core/cd_hw core/debug core/input_hw core/m68k core/ntsc core/sound core/themor core/z80
# COMPONENT_OBJS := \
#     core/z80/z80.o \
#     core/m68k/m68kcpu.o \
#     core/input_hw/input.o \
#     core/input_hw/gamepad.o \
#     core/input_hw/lightgun.o \
#     core/input_hw/mouse.o \
#     core/input_hw/activator.o \
#     core/input_hw/xe_1ap.o \
#     core/input_hw/teamplayer.o \
#     core/input_hw/paddle.o \
#     core/input_hw/sportspad.o \
#     core/input_hw/terebi_oekaki.o \
#     core/input_hw/graphic_board.o \
#     core/sound/sound.o \
#     core/sound/psg.o \
#     core/sound/ym2413.o \
#     core/sound/ym2612.o \
#     core/sound/blip_buf.o \
#     core/sound/eq.o \
#     core/cart_hw/sram.o \
#     core/cart_hw/svp/svp.o \
#     core/cart_hw/svp/ssp16.o \
#     core/cart_hw/ggenie.o \
#     core/cart_hw/areplay.o \
#     core/cart_hw/eeprom_93c.o \
#     core/cart_hw/eeprom_i2c.o \
#     core/cart_hw/eeprom_spi.o \
#     core/cart_hw/md_cart.o \
#     core/cart_hw/sms_cart.o \
#     core/ntsc/sms_ntsc.o \
#     core/ntsc/md_ntsc.o \
#     core/genesis.o \
#     core/vdp_ctrl.o \
#     core/vdp_render.o \
#     core/system.o \
#     core/io_ctrl.o \
#     core/mem68k.o \
#     core/memz80.o \
#     core/membnk.o \
#     core/state.o \
#     core/loadrom.o \
#     m5stack/config.o \
#     m5stack/error.o \
#     m5stack/fileio.o \
#     m5stack/scrc32.o \
#     m5stack/main.o

CFLAGS := \
    -DLSB_FIRST \
    -DUSE_16BPP_RENDERING \
    -DMAXROMSIZE=131072 \
    -DHAVE_ALLOCA_H \
    -DUSE_DYNAMIC_ALLOC \
    -DALT_RENDERER \
    -DALIGN_LONG \
    -DM5STACK \
    -fomit-frame-pointer \
    -Wno-strict-aliasing \
    -mlongcalls
