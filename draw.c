/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:54:44 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/15 19:39:20 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 0 - WIDTH -> -2 - 2
// 0 - HEIGTH -> 2 - -2

mandelbrot_julia(t_complex z, t_complex *c, t_fractal *fractal)
{
	if (!strncmp(fractal->name, "julia", 5))
	{
		c->x = julia_x;
		c->y = julia_y;
	}
	else
	{
		c->x = z.x;
		c->y = z.y;
		z.x = 0;
		z.y = 0;
	}
}

ft_pixels(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z.x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandelbrot_julia(z, &c, fractal);
	while (i < fractal->iterations)
	{
		z = ()
	}
}
// int x, y bc it's size
fractal_draw(t_fractal *fractal)
{
	int x;
	int y;

	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			ft_pixels(x, y, fractal);
		}
	}
}