/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:46:10 by eclark            #+#    #+#             */
/*   Updated: 2022/08/15 15:36:19 by eclark           ###   ########.fr       */
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

void    draw_Mandelbrot(t_data *var)
{
	int		x;
	int		y;
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
			Mandelbrot(cr, ci);
			my_mlx_pixel_put(var, x, y, 0x345678);
		}
	}
}

void    draw_Julia(t_data *var)
{
	int		x;
    int		y;
    double	cr;
    double	ci;

	mlx_clear_window(var->mlx, var->win);	
	y = -1;
	while (++y < 1000)
	{
		x = -1;
		while (++x < 1000)
		{
			cr = var->min_r + (double)x * (var->max_r - var->min_r) / WIDTH;
			ci = var->min_i + (double)y * (var->max_i - var->min_i) / HEIGHT;
			Julia(var, cr, ci);
		}
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img, x, y);
}

char *fractal_checker(int n, t_data *var)
{
    if (n == 1)
    {
        draw_Mandelbrot(var);
    }
    else if (n == 2)
    {
        draw_Julia(var);
    }
    else
    {
        return ("ERROR please input 1 for Mandelbrot or 2 for Julia");
    }
	return (0);
}
