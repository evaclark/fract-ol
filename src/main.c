/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:34:49 by eclark            #+#    #+#             */
/*   Updated: 2022/08/04 17:16:42 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main()
{
    t_data  var;
	
	var.min_r = -2.0;
	var.min_i = -1.5;
	var.max_r = 1.0;
	var.max_i = var.min_i + (var.max_r + var.min_r) * HEIGHT / WIDTH;

    var.mlx = mlx_init();
    var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, ":)");
	var.img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	var.addr = mlx_get_data_addr(var.img, &var.bits_pp, &var.line_size, &var.endian);
	draw_fractal(&var);
	mlx_put_image_to_window(var.mlx, var.win, var.img, 0, 0);
	mlx_hook(var.win, 2, 1L<<0, key_check, &var);
    mlx_loop(var.mlx);
}
