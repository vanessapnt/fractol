/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:45:20 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/12 17:03:11 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define WIDTH 400
#define HEIGHT 400

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx_data;

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("%d (ESC)\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("%d\n", keysym);
	return(0);
}

int	main(void)
{
	t_mlx_data data;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return(1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, HEIGHT, WIDTH, "mlx 42");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}

	//mlx_pixel_put(data.mlx_ptr, data.win_ptr, 250, 250, 0x00FF00);

	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);

	//mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	//mlx_destroy_display(data.mlx_ptr);
	//free(data.mlx_ptr);
}

