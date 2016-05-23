/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:48:25 by cledant           #+#    #+#             */
/*   Updated: 2016/05/23 20:27:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

int		main(void)
{
	t_list	*list;
	t_list	*cpy_list;
	int		fd;

	fd = 0;
	list = ft_lstread_file(fd);
	cpy_list = list;
	while (list != NULL)
	{
//		ft_putendl("============");
		ft_putendl(list->content);
//		ft_putendl("============");
		list = list->next;
	}
	ft_lstdel(&cpy_list, &ft_lstfree_malloc);
	return (0);
}
