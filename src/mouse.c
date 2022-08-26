/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:22:24 by eclark            #+#    #+#             */
/*   Updated: 2022/08/26 13:55:30 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(double zoom, t_data *var)
{
	double	center_r;
	double	center_i;

	center_r = var->min_r - var->max_r;
	center_i = var->max_i - var->min_i;
	var->max_r = var->max_r + (center_r - zoom * center_r) / 2;
	var->min_r = var->max_r + zoom * center_r;
	var->min_i = var->min_i + (center_i - zoom * center_i) / 2;
	var->max_i = var->min_i + zoom * center_i;
}

int	mouse_hook(int keycode, int x, int y, t_data *var)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		x = 0;
		y = 0;
		zoom(0.7, var);
		mlx_clear_window(var->mlx, var->win);
		draw(var, var->n);
	}	
	if (keycode == MOUSE_WHEEL_DOWN)
	{
		zoom(1.3, var);
		mlx_clear_window(var->mlx, var->win);
		draw(var, var->n);
	}
	return (0);
}
