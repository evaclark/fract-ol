/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:18:09 by eclark            #+#    #+#             */
/*   Updated: 2022/08/18 16:26:31 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_data *j)
{
	j->max_r = 2.0;
	j->min_r = -2.0;
	j->min_i = -2.0;
	j->max_i = j->min_i + (j->max_r - j->min_r) * HEIGHT/WIDTH;
}

void	init_mandel(t_data *m)
{
	m->max_r = 1.0;
	m->min_r = -2.0;
	m->min_i = -1.5;
	m->max_i = m->min_i + (m->max_r - m->min_r) * HEIGHT/WIDTH;
}
