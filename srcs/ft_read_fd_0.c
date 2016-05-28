/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 10:47:49 by cledant           #+#    #+#             */
/*   Updated: 2016/05/28 15:08:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

t_list		*ft_read_fd_0(void)
{
	t_list	*read_1;
	t_list	*gnl;
	t_list	*cpy_read_1;
	int		fd;

	read_1 = NULL;
	fd = open("./check", O_RDWR | O_APPEND);
	if ((read_1 = ft_lstreadraw_file(0)) == NULL)
		return (NULL);
	cpy_read_1 = read_1;
	while (cpy_read_1 != NULL)
	{
		ft_putstr_fd(cpy_read_1->content, fd);
		cpy_read_1 = cpy_read_1->next;
	}
	ft_putendl_fd("READ 1 OK", fd);
	if ((gnl = ft_lstgnl(read_1)) == NULL)
	{
		ft_putendl_fd("GNL CHIE", fd);
		ft_lstdel(&read_1, ft_lstfree_malloc);
		return (NULL);
	}
	ft_putendl_fd("GNL OK", fd);
	while (gnl != NULL)
	{
		ft_putendl_fd(gnl->content, fd);
		gnl = gnl->next;
	}
	ft_lstdel(&read_1, ft_lstfree_malloc);
	close(fd);
	return (gnl);
}
