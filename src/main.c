/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:34:49 by eclark            #+#    #+#             */
/*   Updated: 2022/08/18 13:12:27 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
    t_data  var;
	
	var.ki = -0.7;
	var.kr = 0.27015;
	var.min_r = -2.0;
	var.min_i = -1.5;
	var.max_r = 1.0;
	var.max_i = var.min_i + (var.max_r + var.min_r) * HEIGHT / WIDTH;
    
	var.mlx = mlx_init();
    var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, ":)");
	var.img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	var.data = (int *)mlx_get_data_addr(var.img, &var.bits_pp, &var.line_size, &var.endian);
	if (argc == 2)
		fractal_checker(ft_atoi(argv[1]), &var);
	mlx_hook(var.win, 2, 1L<<0, key_check, &var);
    mlx_loop(var.mlx);
}
