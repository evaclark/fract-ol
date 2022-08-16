/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:11:09 by eclark            #+#    #+#             */
/*   Updated: 2022/08/15 15:35:46 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
    char    *dst;

    dst = data->addr + (y * data->line_size + x * (data->bits_pp / 8));
    *(unsigned int*)dst = colour;
}
