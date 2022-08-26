/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:38:38 by eclark            #+#    #+#             */
/*   Updated: 2022/08/26 14:04:17 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	f;

	init(&f);
	fractal_checker(&f, argc, argv);
	draw(&f, f.n);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_hook(f.win, 17, 0, close_win, (void *)&f);
	mlx_hook(f.win, 2, 0, key_check, &f);
	mlx_loop(f.mlx);
}
