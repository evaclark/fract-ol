/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:34:49 by eclark            #+#    #+#             */
/*   Updated: 2022/08/17 15:17:31 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main()
{
    t_data  var;
	
	var.ki = -0.766667;
	var.kr = -0.090000;
	var.min_r = -2.0;
	var.min_i = -1.5;
	var.max_r = 1.0;
	var.max_i = var.min_i + (var.max_r + var.min_r) * HEIGHT / WIDTH;
    
	var.mlx = mlx_init();
    var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, ":)");
	var.img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	var.data = (int *)mlx_get_data_addr(var.img, &var.bits_pp, &var.line_size, &var.endian);
	fractal_checker(2, &var);
	mlx_hook(var.win, 2, 1L<<0, key_check, &var);
    mlx_loop(var.mlx);
}
