/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_hrander.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <mel-houa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:56:43 by mel-houa          #+#    #+#             */
/*   Updated: 2025/05/20 19:02:55 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = ((y * img->line_len) + (x * (img->bit_per_pex / 8)));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fract *fract)
{
	if (!ft_strncmp(fract->name, "Julia", 5))
	{
		c->x = fract->julia_x;
		c->y = fract->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_fract *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map_scale(x, -2, +2, WIDTH) * fract->zoom);
	z.y = (map_scale(y, -2, +2, HEIGHT) * fract->zoom);
	mandel_vs_julia(&z, &c, fract);
	while (i < fract->iter_def)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fract->escape_value)
		{
			color = map_scale(i, BLUE, PSYCHEDELIC_PURPLE, fract->iter_def);
			my_pixel_put(x, y, &fract->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fract->img, BLACK);
}

void	fract_rander(t_fract *fract)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fract);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx_connection, fract->mlx_window,
		fract->img.img_ptr, 0, 0);
}
