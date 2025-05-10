/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <mel-houa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:56:20 by mel-houa          #+#    #+#             */
/*   Updated: 2025/05/02 23:17:48 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800 /// WIDTH & HEIGHT: Define the dimensions of the window
# define HEIGHT 800
# define XK_ESCAPE  65307 //  Keycode for the Escape key, used to exit the program
# define BUTTON_MOUS5  5 // UTTON_MOUS5 & BUTTON_MOUS4: Mouse button codes for zooming in and out.
# define BUTTON_MOUS4  4

//--------------ººColorsºº-----------------------//
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

//------------ººPsychedelic colorsºº---------------------//
# define MAGENTA_BURST 0xFF00FF
# define LIME_SHOCK 0xCCFF00
# define NEON_ORANGE 0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM 0x33CCCC
# define HOT_PINK 0xFF66B2
# define ELECTRIC_BLUE 0x0066FF
# define LAVA_RED 0xFF3300

//--------ººStructsºº-------//
// t_img: Represents an image, storing information needed to manipulate pixel data
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bit_per_pex;
	int		endian;
	int		line_len;

}			t_img;

//t_complex: Represents a complex number with real part x and imaginary part 
typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;


// t_fract: Holds the state of the fractal rendering, 
// including the type of fractal, window information, image data, and parameters specific to Julia sets
typedef struct s_fract
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iter_def;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fract;

//-----------------ººlibftºº------------//
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);

//-----------------ººfract_initºº--------------//
void		fract_init(t_fract *fract);

//------------------ººfract_hranderºº--------------//
void		handle_pixel(int x, int y, t_fract *fract);
void		fract_rander(t_fract *fract);
//-------------------ººfract_helmathºº---------------//
double		map_scale(double unscaled_num, double new_min, double new_max,
				double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

//--------------------ººfract_envºº------------------------//
int			close_handler(t_fract *fract);
int			key_handler(int keysym, t_fract *fract);
int			mouse_handler(int button, int x, int y, t_fract *fract);
//--------------------ººfract_ajulia_utilsºº---------------------//
double		atodbl(char *s);

#endif // FRACTOL_H
