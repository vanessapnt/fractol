#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"

typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*mlx_win_ptr;
}			t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

fractal_draw(t_fractal *fractal);

#endif