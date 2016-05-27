/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:48:25 by cledant           #+#    #+#             */
/*   Updated: 2016/05/26 20:47:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

int		main(void)
{
//	int		fd;
//	char	buf[11];
	t_list	*list;

	list = NULL;
	while (1)
	{
//		fd = open("./input", O_RDWR | O_CREAT | O_APPEND);
//		ft_putendl_fd("JE READ", fd);
		list = ft_lstreadraw_file(0);
//		ft_putendl_fd("FIN READ", fd);
//		while (list != NULL)
//		{
//			ft_putstr_fd(buf, fd);
//			list = list->next;
//		}
//		ft_putendl_fd("FIN TRUC", fd);
//		ft_putendl("0 0");
	}
	list = NULL;
	return (0);
}
