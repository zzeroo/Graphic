//#define DOGM_PIN_SI     PIN_C5  // SDO Serial Data Output auto select by CCS Compiler  (DOGM PORT 36)
//#define DOGM_PIN_SCL    PIN_C3  // SCL Serial Clock auto select by CCS Compiler (DOGM PORT 37)
//#define DOGM_PIN_A0     PIN_C0  // A0 PIN Display (DOGM PORT 38)
//#define DOGM_PIN_RES    PIN_A4  // RST PIN Display (DOGM PORT 39)
//#define DOGM_PIN_CS     PIN_A5  // CS1B PIN Display (DOGM PORT 40)


// Setup for ST7565R in SPI mode
/** The chip select pin */
#define GLCD_CS1 PIN_A5
/** The reset pin (this is required and should not be tied high) */
#define GLCD_RESET PIN_A4
/** The A0 pin, which selects command or data mode */
#define GLCD_A0 PIN_C0
/** The clock pin */
#define GLCD_SCL PIN_C3
/** The data pin */
#define GLCD_SDA PIN_C5

/** Screen width in pixels (tested with 128) */
#define SCREEN_WIDTH 128
/** Screen height in pixels (tested with 64) */
#define SCREEN_HEIGHT 64

/** Define this if your screen is incorrectly shifted by 4 pixels */
//#define ST7565_REVERSE

/** By default we only write pages that have changed.  Undefine this
    if you want less/faster code at the expense of more SPI operations. */
//#define ST7565_DIRTY_PAGES 1


#define GLCD_TOP_VIEW
#define ST7565_REVERSE



