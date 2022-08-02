/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:21:38 by eclark            #+#    #+#             */
/*   Updated: 2022/08/02 15:31:18 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "keydef.h"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bits_pp;
	int		line_size;
	int		endian;
	char	*addr;
}				t_data;

/*window*/
int	key_check(int keycode, t_data *var);

/*image*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int colour);

#endif
