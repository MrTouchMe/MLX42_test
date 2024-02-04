#include "../include/animations.h"

#define BPP sizeof(int32_t)

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

/**
 * In MLX42 Colors are as follows:
 * 0000 0000 A (1st byte) -> uint8_t because it's 8 bits
 * 0000 0000 R (2nd byte)
 * 0000 0000 G (3rd byte)
 * 0000 0000 B (4th byte)
 **/
int32_t	mlx_get_pixel(mlx_image_t *image, uint32_t x, uint32_t y)
{
	if (x > image->width || y > image->height)
		return 0xFF000000;
	uint8_t* pixelstart = image->pixels + (y * image->width + x) * BPP;
	return get_rgba(*(pixelstart), *(pixelstart + 1),
	* (pixelstart + 2), *(pixelstart + 3));
}
