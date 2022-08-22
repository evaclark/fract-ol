/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:38:38 by eclark            #+#    #+#             */
/*   Updated: 2022/08/22 10:31:21 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window(t_data *f)
{
	int 	x;
	int		y;
	double	cr;
	double	ci;
	
	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			cr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			ci = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
			Mandelbrot(f, x, y, cr, ci);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int main(int argc, char **argv)
{
	if (argc == 2 || argc == 4)
		fractal_checker(ft_atoi(argv[1]));
	else
	{
		ft_printf("%s\n", "no");
	}
	return (0);
}
