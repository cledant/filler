/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:48:11 by cledant           #+#    #+#             */
/*   Updated: 2016/05/27 19:40:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

int		main(void)
{
	t_list	*read_1;
	t_list	*read_2;
	t_list	*gnl;
	t_list	*cpy_gnl;
	t_list	*cpy_read_2;
	int		fd;

	read_1 = NULL;
	read_2 = NULL;
	fd = open("./check", O_RDWR | O_APPEND);
	if ((read_1 = ft_lstreadraw_file(0)) == NULL)
		return (0);
	ft_putendl_fd("READ 1 OK", fd);
	if ((read_2 = ft_lstreadraw_file(0)) == NULL)
	{
		ft_lstdel(&read_1, ft_lstfree_malloc);
		return (0);
	}
	cpy_read_2 = read_2;
	while (cpy_read_2 != NULL)
	{
		ft_putstr_fd(cpy_read_2->content, fd);
		cpy_read_2 = cpy_read_2->next;
	}
	ft_putendl_fd("READ 2 OK", fd);
	if ((gnl = ft_lstgnl(read_1, read_2)) == NULL)
	{
		ft_putendl_fd("GNL CHIE", fd);
		ft_lstdel(&read_1, ft_lstfree_malloc);
		ft_lstdel(&read_2, ft_lstfree_malloc);
		return (0);
	}
	ft_putendl_fd("GNL OK", fd);
	while (gnl != NULL)
	{
		ft_putendl_fd(gnl->content, fd);
		gnl = gnl->next;
	}
	ft_lstdel(&cpy_gnl, ft_lstfree_malloc);
	ft_lstdel(&read_1, ft_lstfree_malloc);
	ft_lstdel(&read_2, ft_lstfree_malloc);
	return (0);
}
