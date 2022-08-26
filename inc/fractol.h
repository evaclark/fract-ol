/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:21:38 by eclark            #+#    #+#             */
/*   Updated: 2022/08/26 14:24:57 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "ft_printf.h"
# include "mlx.h"

# define MAX_ITERATIONS 80
# define WIDTH 900
# define HEIGHT 900
# define KEY_ESC 53
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		n;
	int		*data;
	int		x;
	int		y;
	double	min_r;
	double	min_i;
	double	max_r;
	double	max_i;
	double	ki;
	double	kr;
	double	zr;
	double	zi;
}				t_data;

typedef struct s_utils
{
	double	sum;
	double	sign;
	double	decimal;
	int		n;
}				t_utils;
/*window*/
int		key_check(int keycode, t_data *var);
int		close_win(t_data *var, int exit_code);

/*fractol*/
void	fractal_checker(t_data *f, int argc, char **argv);
void	mandelbrot(t_data *m, double cr, double ci);
void	julia(t_data *j, double zr, double zi);
void	draw(t_data *var, int n);

/*utils*/
int		ft_atoi(const char *str);
double	ft_atof(char *str);

/*init*/
void	init(t_data *f);
void	init_mandel(t_data *m);
void	init_julia(t_data *j, char **argv);

/*mouse*/
int		mouse_hook(int keycode, int x, int y, t_data *var);
#endif
