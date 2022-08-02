/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:49:48 by eclark            #+#    #+#             */
/*   Updated: 2022/08/02 16:51:46 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_data *var)
{
	
	if(var->mlx)
	{
		free(var->mlx);
	}
	if(var->win)
	{
		free(var->win);
	}
	mlx_destroy_image(var->mlx, var->img);
	mlx_clear_window(var->mlx, var->win);
	mlx_destroy_window(var->mlx, var->win);
	return (0);
}

int key_check(int keycode, t_data *var)
{
    if (keycode == KEY_ESC)
    {
        close_win(var);
        return (0);
    }
    return (0);
}

