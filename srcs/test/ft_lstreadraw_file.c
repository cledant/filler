/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreadraw_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:48:56 by cledant           #+#    #+#             */
/*   Updated: 2016/05/27 11:44:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

t_list		*ft_lstreadraw_file(int fd)
{
	char	*buff[BUFF_SIZE + 1];
	t_list	*new;
	int		ret;
	int		fd_2;
	int		i = 0;


	new = NULL;
	i = 0;
	fd_2 = open ("./input", O_RDWR | O_CREAT | O_APPEND);
	ft_putendl_fd("first", fd_2);
	ft_bzero(buff, BUFF_SIZE + 1);
	ft_putendl_fd("avant while", fd_2);
	while (i < 5)
	{
		ret = read(fd, buff, BUFF_SIZE);
//		if ((new = ft_lstnewpushback(new, buff, ret)) == NULL)
//			return (NULL);
		ft_putendl_fd("NOMBRE CHAR", fd_2);
		ft_putnbrendl_fd(ret, fd_2);
		ft_putendl_fd("FIN NOMBRE CHAR", fd_2);
		ft_putendl_fd("ITERATION", fd_2);
		ft_putnbrendl_fd(i, fd_2);
		ft_putendl_fd("FIN ITERATION", fd_2);
		ft_putendl_fd((char *)buff, fd_2);
		ft_bzero(buff, BUFF_SIZE);
		if (i == 5)
			ft_putendl("0 0");
		i++;
	}
	return (new);
}
