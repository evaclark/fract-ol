/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:34:49 by eclark            #+#    #+#             */
/*   Updated: 2022/08/02 16:51:49 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main()
{
    t_data  var;

    var.mlx = mlx_init();
    var.win = mlx_new_window(var.mlx, 1000, 1000, ":)");
	var.img = mlx_new_image(var.mlx, 1000, 1000);
	var.addr = mlx_get_data_addr(var.img, &var.bits_pp, &var.line_size, &var.endian);
    my_mlx_pixel_put(&var, 400, 600, 0xAAFF00);
	mlx_put_image_to_window(var.mlx, var.win, var.img, 0, 0);
	mlx_hook(var.win, 2, 1L<<0, key_check, &var);
    mlx_loop(var.mlx);
}
