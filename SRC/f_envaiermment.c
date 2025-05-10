/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_envaiermment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <mel-houa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:57:02 by mel-houa          #+#    #+#             */
/*   Updated: 2025/04/17 23:03:59 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fract *fract)
{
	mlx_destroy_image(fract->mlx_connection, fract->img.img_ptr);
	mlx_destroy_window(fract->mlx_connection, fract->mlx_window);
	mlx_destroy_display(fract->mlx_connection);
	free(fract->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int button, t_fract *fract)
{
	if (button == XK_ESCAPE)
		close_handler(fract);
	fract_rander(fract);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fract *fract)
{
	if (button == BUTTON_MOUS5)
		fract->zoom *= 0.95;
	else if (button == BUTTON_MOUS4)
		fract->zoom *= 1.05;
	(void)x;
	(void)y;
	fract_rander(fract);
	return (0);
}
