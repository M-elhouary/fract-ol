/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <mel-houa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:56:09 by mel-houa          #+#    #+#             */
/*   Updated: 2025/04/29 23:18:56 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static char	*move_to_pos(char *s)
{
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*(s + 1) != '\0' && (((*s == '-') && (*(s + 1) != '.')) || ((*s == '+')
				&& (*(s + 1) != '.'))))
		s++;
	return (s);
}

static int	isvalid(char *s)
{
	s = move_to_pos(s);
	while (*s != '.' && *s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	if (*(s) == '.')
		s++;
	else
		return (1);
	if (*s)
	{
		while (*s)
		{
			if (!ft_isdigit(*s))
				return (0);
			s++;
		}
	}
	else
		return (0);
	return (1);
}

static int	validate_and_set_cords_julia(char *argv[])
{
	double (x), (y);
	if (!isvalid(argv[2]) || !isvalid(argv[3]))
	{
		ft_putstr_fd("Error:\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	x = atodbl(argv[2]);
	if (x < -2 || x > 2)
	{
		ft_putstr_fd("Error: x coordinate out of range\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	y = atodbl(argv[3]);
	if (y < -2 || y > 2)
	{
		ft_putstr_fd("Error: y coordinate out of range\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fract	fract;

	if ((argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "Julia", 5)))
	{
		fract.name = argv[1];
		if (!ft_strncmp(argv[1], "Julia", 5)
			&& validate_and_set_cords_julia(argv) == 0)
		{
			fract.julia_x = atodbl(argv[2]);
			fract.julia_y = atodbl(argv[3]);
		}
		fract_init(&fract);
		fract_rander(&fract);
		mlx_loop(fract.mlx_connection);
	}
	else
	{
		ft_putstr_fd("Must enter [./fractol] ", STDERR_FILENO);
		ft_putstr_fd("follwsed by [Mandelbrot] or [Julia x y]\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
