#
# Main Makefile. This is basically the same as a component makefile.
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)

COMPONENT_SRCDIRS := core core/z80 core/m68k core/input_hw core/sound core/cart_hw core/cart_hw/svp core/ntsc m5stack
COMPONENT_ADD_INCLUDEDIRS := core m5stack core/cart_hw core/cart_hw/svp core/cd_hw core/debug core/input_hw core/m68k core/ntsc core/sound core/themor core/z80

CFLAGS := \
    -DLSB_FIRST \
    -DUSE_16BPP_RENDERING \
    -DMAXROMSIZE=131072 \
    -DHAVE_ALLOCA_H \
    -DALT_RENDERER \
    -DALIGN_LONG \
    -DM5STACK \
    -fomit-frame-pointer \
    -Wno-strict-aliasing \
    -mlongcalls

#    -DUSE_DYNAMIC_ALLOC \
