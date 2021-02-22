BOOTLOADER = atmel-dfu
BOOTMAGIC_ENABLE = lite


# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
         ./lib/mode_icon_reader.c \
         ./lib/timelogger.c \
