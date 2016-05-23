/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreadraw_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:48:56 by cledant           #+#    #+#             */
/*   Updated: 2016/05/23 14:55:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_list		*ft_lstreadraw_file(int fd)
{
	char	*buff[BUFF_SIZE + 1];
	t_list	*new;

	new = NULL;
	ft_bzero(buff, BUFF_SIZE);
	while ((read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((new = ft_lstnewpushback(new, buff, BUFF_SIZE + 1)) == NULL)
			return (NULL);
		ft_bzero(buff, BUFF_SIZE);
	}
	return (new);
}
