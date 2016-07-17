/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreadraw_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:48:56 by cledant           #+#    #+#             */
/*   Updated: 2016/07/17 18:29:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_list		*ft_lstreadraw_file(int fd)
{
	char	*buff[BUFF_SIZE + 1];
	t_list	*new;
	int		ret;

	new = NULL;
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((new = ft_lstnewpushback(new, buff, ret + 1)) == NULL)
		{
			if (new != NULL)
				ft_lstdel(&new, ft_lstfree_malloc);
			return (NULL);
		}
		ft_bzero(buff, BUFF_SIZE + 1);
		if (ret != BUFF_SIZE)
			break ;
	}
	if (ret == -1)
	{
		if (new != NULL)
			ft_lstdel(&new, ft_lstfree_malloc);
		return (NULL);
	}
	return (new);
}
