/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:38:38 by eclark            #+#    #+#             */
/*   Updated: 2022/08/16 15:33:00 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window(t_data *f)
{
	int x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			Mandelbrot(		
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int main()
{
	t_data f;

	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "test");
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	f.data = (int *)mlx_get_data_addr(f.img, &f.bits_pp, &f.line_size, &f.endian);
	window(&f);
	mlx_loop(f.mlx);
}
