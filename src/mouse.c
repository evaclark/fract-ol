/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:22:24 by eclark            #+#    #+#             */
/*   Updated: 2022/08/03 14:25:27 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(int uod, t_data *var)
{

}

void	mouse_hook(int keycode, t_data *var)
{
	if (keycode == MOUSE_SCROLL_UP)
	{
		zoom_in();
	}
	if (keycode == MOUSE_SCROLL_DOWN)
	{
		zoom_out();
	}
	/*function to print fractal*/
}
