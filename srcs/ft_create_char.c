/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 15:09:50 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 18:10:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_clean(char **line, char **col)
{
	if (*line != NULL)
		ft_strdel(line);
	if (*col != NULL)
		ft_strdel(col);
}

char			*ft_create_char(size_t i, size_t j)
{
	char	*line;
	char	*col;
	char	*ret;

	if ((line = ft_itoa(i)) == NULL)
		return (NULL);
	if ((col = ft_itoa(j)) == NULL)
	{
		ft_clean(&line, &col);
		return (NULL);
	}
	if ((ret = ft_strnew(ft_strlen(line) + ft_strlen(col) + 1)) == NULL)
	{
		ft_clean(&line, &col);
		return (NULL);
	}
	ft_strcat(ret, line);
	ft_strcat(ret, " ");
	ft_strcat(ret, col);
	ft_clean(&line, &col);
	return (ret);
}
