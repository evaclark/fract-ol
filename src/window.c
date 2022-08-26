/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:49:48 by eclark            #+#    #+#             */
/*   Updated: 2022/08/26 12:32:02 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_data *var, int exit_code)
{
	if (!var)
	{
		exit(exit_code);
	}
	if (var->img)
	{
		mlx_destroy_image(var->mlx, var->img);
	}
	if (var->mlx && var->win)
	{
		mlx_clear_window(var->mlx, var->win);
		mlx_destroy_window(var->mlx, var->win);
	}
	if (var->mlx)
	{
		free(var->mlx);
	}
	exit(exit_code);
	return (0);
}

int	key_check(int keycode, t_data *var)
{
	double	center_r;
	double	center_i;

	if (keycode == KEY_ESC)
	{
		close_win(var, 0);
		return (0);
	}
	if (keycode == 13)
	{
		center_r = var->min_r - var->max_r;
		center_i = var->max_i - var->min_i;
		var->max_r = var->max_r + (center_r - 0.3 * center_r) / 2;
		var->min_r = var->max_r + 0.3 * center_r;
		var->min_i = var->min_i + (center_i - 0.3 * center_i) / 2;
		var->max_i = var->min_i + 0.3 * center_i;
		mlx_clear_window(var->mlx, var->win);
		draw(var, var->n);
	}
	return (0);
}
