/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_helmath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <mel-houa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:56:52 by mel-houa          #+#    #+#             */
/*   Updated: 2025/04/17 22:56:55 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_scale(double unscaled_num, double new_min, double new_max,
		double old_max)
{
	double	old_min;
	double	normalized;
	double	new_range;
	double	mapped_value;

	old_min = 0;
	normalized = (unscaled_num - old_min) / (old_max - old_min);
	new_range = new_max - new_min;
	mapped_value = new_range * normalized + new_min;
	return (mapped_value);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = z.x + c.x;
	result.y = z.y + c.y;
	return (result);
}
