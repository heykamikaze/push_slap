/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:23:10 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/20 16:56:49 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			p;
	char			*new_str;
	unsigned int	i;

	if ((!s) || (!f))
		return (NULL);
	p = ft_strlen(s) + 1;
	new_str = malloc(p);
	if (new_str == 0)
	{
		free (new_str);
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
