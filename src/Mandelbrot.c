/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:33:33 by eclark            #+#    #+#             */
/*   Updated: 2022/08/26 14:31:48 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*equation for mandelbrot fractal set Zn+1 = Zn^2 + c where c is constant.
 * the Mandelbrot set is generated through iteration - with a constant given
 * z is the critical point 0 which increases by 1 each iteration. Zn must
 * remain bounded for all n > 0. */
void	mandelbrot(t_data *m, double cr, double ci)
{
	int		i;
	double	temp;

	m->zr = 0;
	m->zi = 0;
	i = -1;
	while (++i < MAX_ITERATIONS)
	{
		if (((m->zr * m->zr) + (m->zi * m->zi)) > 4.0)
		{
			break ;
		}
		temp = 2 * (m->zr * m->zi) + ci;
		m->zr = (m->zr * m->zr) - (m->zi * m->zi) + cr;
		m->zi = temp;
	}
	if (i == MAX_ITERATIONS)
		m->data[m->y * WIDTH + m->x] = 0;
	else
		m->data[m->y * WIDTH + m->x] = i * 50 + 11278615;
}
/*11278615 is decimal conversion of 0xAC1917 - a red*/
