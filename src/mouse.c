/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:22:24 by eclark            #+#    #+#             */
/*   Updated: 2022/08/26 01:18:42 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int keycode, int x, int y, t_data *var)
{
	double	center_r;
	double	center_i;
	
	center_r = var->min_r - var->max_r;
	center_i = var->max_i - var->min_i;
	if (keycode == MOUSE_WHEEL_UP)
	{
		x =0;
		y = 0;
		var->max_r = var->max_r + (center_r - 0.7 * center_r) / 2;
		var->min_r = var->max_r + 0.7 * center_r;
		var->min_i = var->min_i + (center_i - 0.7 * center_i) / 2;
		var->max_i = var->min_i + 0.7 * center_i;
		mlx_clear_window(var->mlx, var->win);
		draw(var, var->n);
	}	
	if (keycode == MOUSE_WHEEL_DOWN)
	{
		var->max_r = var->max_r + (center_r - 1.3 * center_r) / 2;
		var->min_r = var->max_r + 1.3 * center_r;
		var->min_i = var->min_i + (center_i - 1.3 * center_i) / 2;
		var->max_i = var->min_i + 1.3 * center_i;
		mlx_clear_window(var->mlx, var->win);
		draw(var, var->n);
	}
	return (0);
}
