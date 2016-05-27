/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:05:20 by cledant           #+#    #+#             */
/*   Updated: 2016/05/26 18:20:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_read_from_fd(t_list	**list, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	ret = 0;
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_putendl_fd("coucou", 2);
		*list = ft_lstnewpushback(*list, buf, BUFF_SIZE + 1);
		ft_bzero(buf, BUFF_SIZE + 1);
		if (ret == 1 && fd == 0 && fd)
			break ; 
	}
	return (1);
}
