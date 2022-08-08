/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:14:30 by eclark            #+#    #+#             */
/*   Updated: 2022/08/05 16:17:00 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*include function for different values of ki and kr*/

void    Julia(t_data *var, int x, int y, double ki, double kr)
{
    int     i;
    int     in_set;
    double  temp;
    double  zr;
    double  zi;

    i = -1;
    zr = 0;
    zi = 0;
    in_set = 1;
    while (++i < MAX_ITERATIONS)
    {
        if (((zr * zr) + (zi * zi)) > 4.0)
        {
            in_set = 0;
            break;
        }
        temp = 2 * (zr * zi) + ki;
        zr = (zr * zr) - (zi * zi) + kr;
        zi = temp;
    }
}
