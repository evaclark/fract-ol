/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:07:27 by eclark            #+#    #+#             */
/*   Updated: 2022/08/26 15:37:32 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_data *f, int n)
{
	double	cr;
	double	ci;

	f->y = -1;
	while (++f->y < HEIGHT)
	{
		f->x = -1;
		while (++f->x < WIDTH)
		{
			cr = f->min_r + (double)f->x * (f->max_r - f->min_r) / WIDTH;
			ci = f->min_i + (double)f->y * (f->max_i - f->min_i) / HEIGHT;
			if (n == 2)
				julia(f, cr, ci);
			else if (n == 1)
				mandelbrot(f, cr, ci);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	message(t_data *f)
{
	ft_printf("%s\n", "Input 1 for Mandelbrot, 2 for Julia");
	ft_printf("%s\n", "+ values kr & ki for Julia fractol eg:");
	ft_printf("%s\n", "./fract-ol 2 0.28 0.008");
	close_win(f, 0);
}

void	fractal_checker(t_data *f, int argc, char **argv)
{
	if (argc < 2)
		message(f);
	else if (ft_atoi(argv[1]) == 1 && argc == 2)
	{
		init_mandel(f);
		f->n = 1;
	}
	else if (ft_atof(argv[2]) > 2.0 || ft_atof(argv[2]) < -2.0)
		message(f);
	else if (ft_atof(argv[3]) > 2.0 || ft_atof(argv[3]) < -2.0)
		message(f);
	else if (ft_atoi(argv[1]) == 2 && argc == 4)
	{
		init_julia(f, argv);
		f->n = 2;
	}
	else
		message(f);
}
