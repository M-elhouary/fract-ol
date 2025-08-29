/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <mel-houa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:56:30 by mel-houa          #+#    #+#             */
/*   Updated: 2025/05/20 02:28:49 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Memory allocation faild");
	exit(EXIT_FAILURE);
}

void	data_init(t_fract *fract)
{
	fract->escape_value = 4;
	fract->iter_def = 80;
	fract->zoom = 1.0;
}

void	evants_init(t_fract *fract)
{
	mlx_key_hook(fract->mlx_window, key_handler, fract);
	mlx_hook(fract->mlx_window, 17, 0, close_handler, fract);
	mlx_mouse_hook(fract->mlx_window, mouse_handler, fract);
}

void	fract_init(t_fract *fract)
{
	fract->mlx_connection = mlx_init();
	if (fract->mlx_connection == NULL)
		malloc_error();
	fract->mlx_window = mlx_new_window(fract->mlx_connection, WIDTH, HEIGHT,
			fract->name);
	if (fract->mlx_window == NULL)
	{
		mlx_destroy_display(fract->mlx_connection);
		free(fract->mlx_connection);
		malloc_error();
	}
	fract->img.img_ptr = mlx_new_image(fract->mlx_connection, WIDTH, HEIGHT);
	if (fract->img.img_ptr == NULL)
	{
		mlx_destroy_window(fract->mlx_connection, fract->mlx_window);
		mlx_destroy_display(fract->mlx_connection);
		free(fract->mlx_connection);
		malloc_error();
	}
	fract->img.pixels_ptr = mlx_get_data_addr(fract->img.img_ptr,
			&fract->img.bit_per_pex, &fract->img.line_len, &fract->img.endian);
	evants_init(fract);
	data_init(fract);
}
