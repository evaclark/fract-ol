/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:49:48 by eclark            #+#    #+#             */
/*   Updated: 2022/08/01 16:49:09 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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

int main()
{
	t_data	var;
	
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1000, 1000, ":)");
	mlx_hook(var.win, 2, 1L<<0, key_check, &var);
	mlx_loop(var.mlx);
}
