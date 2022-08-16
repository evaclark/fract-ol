/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:21:38 by eclark            #+#    #+#             */
/*   Updated: 2022/08/16 14:54:06 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "keydef.h"

# define MAX_ITERATIONS 80
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
	char	*addr;
	char	*buff;
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

/*image*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int colour);

/*fractol*/
char	*fractal_checker(int n, t_data *var);
int		Mandelbrot(double ci, double cr);
void	Julia(t_data *var, double zi, double zr);

/*mouse*/
int	mouse_hook(int keycode, t_data *z);
#endif
