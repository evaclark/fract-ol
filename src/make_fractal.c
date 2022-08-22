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

/*void	colour(t_data *var, int x, int y)
{
	int	pixel;
	int	colour;
	
	colour = 0xFF660000;
	pixel = (y * var->line_size) + (x * 4);
	
	var->buff[pixel + 0] = colour & 0xFF;
	var->buff[pixel + 1] = (colour >> 8) & 0xFF;
	var->buff[pixel + 2] = (colour >> 16) & 0xFF;
	var->buff[pixel + 3] = (colour >> 24);
}*/

void    draw(t_data *var, int n)
{
	int	x;
    	int	y;
    	double	cr;
    	double	ci;

	mlx_clear_window(var->mlx, var->win);	
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

void	fractal_checker(int n)
{  
	if (n == 1)
	{
    	init_mandel(n);
    }
    else if (n == 2)
    {
		init_julia(n);
	}
}
