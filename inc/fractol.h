/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:21:38 by eclark            #+#    #+#             */
/*   Updated: 2022/08/18 16:56:19 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "ft_printf.h"
# include "mlx.h"
# include "keydef.h"

# define MAX_ITERATIONS 90
# define WIDTH 900
# define HEIGHT 900

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bits_pp;
	int		line_size;
	int		endian;
	int		*data;
	double	min_r;
	double	min_i;
	double	max_r;
	double	max_i;
	double	zr;
	double	zi;
	double	ki;
	double	kr;
	double	zoom;
}				t_data;

/*window*/
int	key_check(int keycode, t_data *var);
int	close_win(t_data *var, int exit_code);

/*fractol*/
void	fractal_checker(int n, t_data *var);
void	Mandelbrot(t_data *f, int x, int y, double cr, double ci);
void	Julia(t_data *var, int x, int y, double zr, double zi);
void	window(t_data *f);

/*utils*/
int	ft_atoi(const char *str);
void	init_mandel(t_data *m);
void	init_julia(t_data *j);

/*mouse*/
int	mouse_hook(int keycode, t_data *z);
#endif
