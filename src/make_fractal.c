/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:46:10 by eclark            #+#    #+#             */
/*   Updated: 2022/08/18 16:53:06 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    draw(t_data *var, int n)
{
		int	x;
		int	y;
		double	cr;
		double	ci;
	
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			cr = var->min_r + (double)x * (var->max_r - var->min_r) / WIDTH;
			ci = var->min_i + (double)y * (var->max_i - var->min_i) / HEIGHT;
			if (n == 2)
				Julia(var, x, y, cr, ci);
			else if (n == 1)
				Mandelbrot(var, x, y, cr, ci);
		}
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
}

void	fractal_checker(t_data *f, int argc, char **argv)
{  
	if (argc < 2)
	{
		ft_printf("%s\n", "Input 1 for Mandelbrot, 2 for Julia");
		close_win(f, 0);
	}
	else if (ft_atoi(argv[1]) == 1 && argc == 2)
	{
		init_mandel(f);
		f->n = 1;
	}
	else if (ft_atoi(argv[1]) == 2 && argc == 4)
	{
		init_julia(f, argv);
		f->n = 2;
	}
	else
		ft_printf("%s\n", "Input 1 for Mandelbrot, 2 for Julia");
}
