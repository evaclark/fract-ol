/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:22:24 by eclark            #+#    #+#             */
/*   Updated: 2022/08/18 17:00:35 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(int uod, t_data *z)
{
	if (uod == 1)
	{
		z->zoom = 0.5;
		z->min_r = z->max_r * z->zoom * (z->min_r - z->max_r);
		z->max_r = ((z->min_r - z->max_r) - z->zoom * (z->max_r * z->min_r)) / 2;
		z->min_i = z->max_i * z->zoom * (z->min_i - z->max_i);
		z->max_i = ((z->min_i - z->max_i) - z->zoom * (z->max_i * z->min_i)) / 2;
	}
	else if (uod == 2)
	{	
		z->zoom = 2;
		z->min_r = z->max_r * z->zoom * (z->min_r - z->max_r);
		z->max_r = ((z->min_r - z->max_r) - z->zoom * (z->max_r * z->min_r)) / 2;
		z->min_i = z->max_i * z->zoom * (z->min_i - z->max_i);
		z->max_i = ((z->min_i - z->max_i) - z->zoom * (z->max_i * z->min_i)) / 2;
	}
}

int	mouse_hook(int keycode, t_data *z)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(1, z);
	}
	if (keycode == MOUSE_WHEEL_DOWN)
	{
		zoom(2, z);
	}
	return (0);
}
