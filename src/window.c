/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:49:48 by eclark            #+#    #+#             */
/*   Updated: 2022/08/18 13:03:56 by eclark           ###   ########.fr       */
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

int key_check(int keycode, t_data *var)
{
    if (keycode == KEY_ESC)
    {
        close_win(var, 0);
        return (0);
    }
    return (0);
}

