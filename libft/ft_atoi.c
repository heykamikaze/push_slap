/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:10:22 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/20 20:18:06 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int		i;
	int		negative;
	long	nu;

	negative = 1;
	nu = 0;
	i = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\v'
		|| *str == ' ' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			ft_error();
		nu = (nu * 10) + (*str - '0');
		i++;
		if (i > 10 || (nu * negative) > INT_MAX || (nu * negative) < INT_MIN)
			ft_error();
		str++;
	}	
	return ((int)(nu * negative));
}
