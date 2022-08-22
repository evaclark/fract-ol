/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:22:24 by eclark            #+#    #+#             */
/*   Updated: 2022/08/22 10:57:47 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(double zoom, t_data *f)
{
	
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

int	mouse_hook(int keycode, t_data *z)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(0.3, z);
		draw(z, z->n);
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
	{
		zoom(1.03, z);
		draw(z, z->n);
	}
	return (0);
}
