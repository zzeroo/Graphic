/**
 * @file   graphics.h
 * @author David <david@edeca.net>
 * @date   November, 2011
 * @brief  Header for black and white graphics library.
 * @sa     <a href="http://en.wikipedia.org/wiki/Bresenham's_line_algorithm">Bresenham's line algorithm on Wikipedia</a>
 * @details
 *
 * A graphics library for black and white graphic LCDs.  Supports lines, rectangles and text.
 *
 * Fonts are available separately in header files, see the fonts/ directory.
 *
 * This requires a hardware driver for the GLCD that provides a glcd_pixel() routine.  See
 * my ST7565 library for an example.
 *
 * The benefit of this approach is that it can be ported easily to any graphic LCD.  However,
 * speed benefits could be gained by writing routines that draw whole bytes at a time.
 *
 * Fonts and graphics can be converted from Windows TTF fonts or images using the muGUI
 * "Font and Bitmap Generator", which is free.
 *
 * Example usage:
 * @code
 *    // Draw some text with spacing 1, at location (10,10)
 *    draw_text("Example string", 10, 10, Tahoma10, 1);
 *
 *    // Draw a rectangle from (1,1) to (50,50)
 *    draw_rectangle(1, 1, 50, 50, 1);
 *
 *    // Draw a circle, centred at (32,32) with radius 10
 *    draw_circle(32, 32, 10, 1);
 * @endcode
 */
#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#define FONT_HEADER_TYPE		0
#define FONT_HEADER_ORIENTATION	1
#define FONT_HEADER_START		2
#define FONT_HEADER_LETTERS		3
#define FONT_HEADER_HEIGHT		4

#define FONT_TYPE_FIXED			0
#define FONT_TYPE_PROPORTIONAL	1

#define FONT_ORIENTATION_VERTICAL_CEILING	2

typedef struct {
	char x1;
	char y1;
	char x2;
	char y2;
} bounding_box_t;

/**
 * Draw a string on the screen at a specific location.
 *
 * @param string	The text to render
 * @param x			The x position, from 1 - SCREEN_WIDTH
 * @param y			The y position, from 1 - SCREEN_HEIGHT
 * @param font		The font used to render the text
 * @param spacing	The gap in pixels between letters
 */
bounding_box_t draw_text(char *string, unsigned char x, unsigned char y, ROM unsigned char *font, unsigned char spacing);
/**
 * Draw a single character on the screen at a specific location.
 *
 * @param c			The character to render
 * @param x			The x position, from 1 - SCREEN_WIDTH
 * @param y			The y position, from 1 - SCREEN_HEIGHT
 * @param font		The font used to render the text
 */
bounding_box_t draw_char(unsigned char c, unsigned char x, unsigned char y, ROM unsigned char *font);
//bounding_box_t draw_char(char c, char x, char y, char *font);
/**
 * Draw a simple rectangle.
 *
 * @param x1 		The x1 position, from 1 - SCREEN_WIDTH
 * @param x2 		The x2 position, from 1 - SCREEN_WIDTH
 * @param y1 		The y1 position, from 1 - SCREEN_HEIGHT
 * @param y2 		The y2 position, from 1 - SCREEN_HEIGHT
 * @param colour 	0 = OFF, any other value = ON
 */
void draw_rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, char colour);
/**
 * Draw a box with rounded corners.  The same as draw_rectangle(), but with corners
 * that are not filled.
 *
 * @param x1 		The x1 position, from 1 - SCREEN_WIDTH
 * @param x2 		The x2 position, from 1 - SCREEN_WIDTH
 * @param y1 		The y1 position, from 1 - SCREEN_HEIGHT
 * @param y2 		The y2 position, from 1 - SCREEN_HEIGHT
 * @param colour 	0 = OFF, any other value = ON
 */
void draw_box(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, char colour);
/**
 * Obtain the width of a string in pixels.
 *
 * @param string	The text to be measured
 * @param font		The font used to render the text
 * @param spacing	The gap between letters, in pixels
 */
char text_width(char *string, ROM char *font, char spacing);
/**
 * Obtain the height of a string in pixels.
 *
 * @note At present this will return the height of the font, rather than the
 * specific string.  For example the character 'o' is not as tall as 'L' and
 * does not have the descender of 'g'.
 *
 * @param string	The text to be measured
 * @param font		The font used to render the text
 */
char text_height(char *string, ROM char *font);
/**
 * Draw a line using Bresenham's algorithm.
 *
 * This code credit Tom Ootjers, originally from: http://tinyurl.com/czok7vx
 *
 * @param x1 		The x1 position, from 1 - SCREEN_WIDTH
 * @param x2 		The x2 position, from 1 - SCREEN_WIDTH
 * @param y1 		The y1 position, from 1 - SCREEN_HEIGHT
 * @param y2 		The y2 position, from 1 - SCREEN_HEIGHT
 * @param colour 	0 = OFF, any other value = ON
 */
void draw_line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, char colour);
/**
 * Draw a circle using an efficient circle algorithm.
 *
 * @param centre_x	The x position of the circle centre, from 1 - SCREEN_WIDTH
 * @param centre_y	The y position of the circle centre, from 1 - SCREEN_HEIGHT
 * @param radius	The circle radius, in pixels
 * @param colour 	0 = OFF, any other value = ON
 */
void draw_circle(char centre_x, char centre_y, char radius, char colour);
/**
 * Draw a filled circle using an efficient circle algorithm.
 *
 * This is separate from draw_circle as it will bring in the draw_line function,
 * which may not be desirable for small code footprint.
 *
 * @param centre_x	The x position of the circle centre, from 1 - SCREEN_WIDTH
 * @param centre_y	The y position of the circle centre, from 1 - SCREEN_HEIGHT
 * @param radius	The circle radius, in pixels
 * @param colour 	0 = OFF, any other value = ON
 */
void draw_filled_circle(char centre_x, char centre_y, char radius, char colour);

/**
 * Draw a filled rectangle.
 *
 * This is my first addition to the graphics library. <zzeroo />
 *
 * @param centre_x	The x position of the circle centre, from 1 - SCREEN_WIDTH
 * @param centre_y	The y position of the circle centre, from 1 - SCREEN_HEIGHT
 * @param radius	The circle radius, in pixels
 * @param colour 	0 = OFF, any other value = ON
 */
void draw_filled_rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, char colour);

/**
 * This function must be provided by the underlying graphics driver.  It will
 * be called by the routines in this library to plot individual pixels.
 *
 * @param x			The x position, from 1 - SCREEN_WIDTH
 * @param y			The y position, from 1 - SCREEN_HEIGHT
 * @param colour 	0 = OFF, any other value = ON
 */
extern void glcd_pixel(unsigned char x, unsigned char y, char colour);

#endif // _GRAPHICS_H_

