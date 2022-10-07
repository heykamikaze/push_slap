/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:53:36 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/20 16:56:08 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	void	*new;

	len = ft_strlen (s) + 1;
	new = malloc (len);
	if (new == NULL)
	{
		free (new);
		return (NULL);
	}
	return ((char *) ft_memcpy (new, s, len));
}
