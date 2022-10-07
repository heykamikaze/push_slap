/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:18:50 by nbenjami          #+#    #+#             */
/*   Updated: 2022/03/20 16:56:28 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		s3 = (char *)malloc(s1_len + s2_len + 1);
		if (s3 == NULL)
		{
			free (s3);
			return (NULL);
		}
		ft_strlcpy(s3, s1, s1_len + 1);
		ft_strlcat(s3, s2, (s1_len + s2_len + 1));
		return (s3);
	}
	return (NULL);
}
