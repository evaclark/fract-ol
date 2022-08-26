/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:09:12 by eclark            #+#    #+#             */
/*   Updated: 2022/08/26 14:28:24 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(const char *str)
{
	int	sum;
	int	sign;

	sum = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = sign * -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	return (sum * sign);
}

double	ft_atof(char *str)
{
	t_utils	var;

	var.sum = 0.0;
	var.decimal = 0.0;
	var.sign = 1.0;
	var.n = -1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			var.sign = var.sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '.')
	{
		var.sum = var.sum * 10 + *str - '0';
		str++;
	}
	if (*str == '.' && *str++)
	{
		while (*str >= '0' && *str <= '9')
			var.decimal += pow(10, var.n--) * (*str++ - '0');
	}
	return (var.sign * (var.sum + var.decimal));
}
