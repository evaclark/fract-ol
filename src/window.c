/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:49:48 by eclark            #+#    #+#             */
/*   Updated: 2022/08/01 12:37:32 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../inc/keydef.h"
#include "../inc/fractol.h"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
}				t_data;

int	free_window(t_data *var)
{
	free(var->mlx);
	free(var->win);
	return (0);
}
int	close_win(t_data *var)
{
	free_window(var);
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
