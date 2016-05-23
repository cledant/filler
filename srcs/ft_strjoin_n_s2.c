/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:50:55 by cledant           #+#    #+#             */
/*   Updated: 2016/05/23 18:22:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_init(size_t *i, size_t *len, size_t *len2)
{
	*i = 0;
	*len = *len + *len2;
}

char			*ft_strjoin_n_s2(char const *s1, char const *s2, size_t size)
{
	size_t	len[2];
	char	*result;
	char	*cpy_result;
	size_t	i;

	len[0] = ft_strlen(s1);
	len[1] = ft_strnlen(s2, size);
	ft_init(&i, &len[0], &len[1]);
	if ((result = ft_strnew(len[0])) == NULL)
		return (NULL);
	cpy_result = result;
	while (*s1 != '\0')
	{
		*result = *s1;
		result++;
		s1++;
	}
	while (*s2 != '\0' && i < len[1])
	{
		*result = *s2;
		s2++;
		result++;
		i++;
	}
	return (cpy_result);
}
