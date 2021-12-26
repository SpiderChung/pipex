/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:56:45 by schung            #+#    #+#             */
/*   Updated: 2021/12/26 13:09:07 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

# define WIN_WIDTH 1600
# define WIN_HEIGHT 800

# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_TAB 48
# define KEY_ESC 53
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_SHIFT 257

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_canvas
{
	float	x;
	float	y;
	float	max_x;
	float	max_y;
	float	center_x;
	float	center_y;
	float	zoom;
	float	a;
	float	b;
	int		iter;
}	t_canvas;

typedef struct s_temp
{
	float	x0;
	float	y0;
	float	temp_x;
	float	temp_y;
	float	temp_z;
	float	x;
	float	y;
	float	z;
	float	c;
	float	p;
	float	pc;
	int		iter;
	int		i;
}	t_temp;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_canvas	*canvas;
	int			num_frac;
	int			color;
	int			psycho;
}	t_data;


/*________fractol.c__________*/
int		key_hook(int keycode, t_data *vars);
int		mouse_hook(int mouse, int x, int y, t_data *vars);
int		key_hook_next(int keycode, t_data *vars);
int		hook_psycho(t_data *vars);

/*________frac_errors.c__________*/
int		frac_errors(int i);
int		set_color(t_data *img, t_temp *temp);
int		set_color_center(t_data *img);
void	set_init_param(t_data *img);
char	*ft_ftoa(float num, int size);

/*________frac_utils.c__________*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		ft_check_title(char *str);
void	get_fractal(t_data *img, int dx, int dy, float dz);
void	ft_menu(t_data *img);

/*________mandelbrot.c__________*/
void	mandelbrot_set(t_data *img, int dx, int dy, float dz);
void	iter_mandelbrot(t_data *img);
void	iter_xy_m(t_temp *temp);
void	set_temp(t_data *img, t_temp *temp);

/*________julia.c__________*/
void	julia_set(t_data *img, int dx, int dy, float dz);
void	iter_xy_j(t_temp *temp);
void	set_tmp_j(t_data *img, t_temp *temp);

/*________celtic_mandelbrot.c__________*/
void	celtic_mandelbrot_set(t_data *img, int dx, int dy, float dz);
void	iter_xy_celtic(t_temp *temp);
void	iter_celtic_mandelbrot(t_data *img);

#endif