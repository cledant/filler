/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:35:11 by cledant           #+#    #+#             */
/*   Updated: 2016/05/27 19:04:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_add_char(char *dst, char add)
{
	char	*new;
	char	*cpy_new;
	size_t	len;

	len = 0;
	if (dst != NULL)
		len = ft_strlen(dst);
	if ((new = ft_strnew(len + 1)) == NULL)
	{
		if (dst != NULL)
			ft_strdel(&dst);
		return (NULL);
	}
	cpy_new = new;
	if (dst != NULL)
		new = ft_strcpy(new, dst);
	while (*cpy_new != '\0')
		cpy_new++;
	*cpy_new = add;
	if (dst != NULL)
		ft_strdel(&dst);
	return (new);
}
