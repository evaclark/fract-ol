/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:28:56 by eclark            #+#    #+#             */
/*   Updated: 2022/08/03 14:21:28 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*this will take the integers for each section of a colout and convert it to
 * a binary form, creating one integer. 1 byte is 8 bits, and an int is 4 bytes
 * so each number will be bitshifted in order to seperate them by 8 bits, a byte
 * each. eg.
 * t = 4, r = 9
 * 4 << 24 = 100000000000000000000000000
 * 9 << 16 = 10010000000000000000
 * both numbers will then be compared using the OR operator, which returns 1 
 * when 1 OR 1 and 1 OR 0, but will return 0 when 0 OR 0.
 * 100000000000000000000000000 | 10010000000000000000 = 
 * 100000010010000000000000000 */

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int get_t(int trgb)
{
	return ((t >> 24) & 0xFF);
}

int get_r(int trgb)
{
	return ((t >> 16) & 0xFF);
}

int get_g(int trgb)
{
	return ((t >> 8) & 0xFF);
}

int get_b(int trgb)
{
	return (b & 0xFF);
}
