/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstread_file_no_gnl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 18:34:32 by cledant           #+#    #+#             */
/*   Updated: 2016/05/23 20:28:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static long int		ft_check_stop(char *buff)
{
	char	*cpy_buff;
	size_t	i;

	i = 0;
	cpy_buff = buff;
	while (i < BUFF_SIZE)
	{
		if (*cpy_buff == '\0' || *cpy_buff ==  '\n' || *cpy_buff == 26)
			return (i);
		i++;
		cpy_buff++;
	}
	return (-1);
}

static char			*ft_add_char(char **store, char *buff)
{
	char	*fuse;

	if ((fuse = ft_strjoin(*store, buff)) == NULL)
	{
		ft_strdel(store);
		return (NULL);
	}
	ft_strdel(store);
	return (fuse);
}

static t_list		*ft_add_list(char **store, char buff[BUFF_SIZE + 1],
						t_list **new)
{
	size_t	loc;
	char	*fuse;

	loc = ft_check_stop(buff);
	if ((fuse = ft_strjoin_n_s2(*store, buff, loc)) == NULL)
	{
		if (*new != NULL)
			ft_lstdel(new, &ft_free_content);
		return (NULL);
	}
	ft_strdel(store);
	if ((*store = ft_strdup(buff + loc + 1)) == NULL)
	{
		ft_strdel(&fuse);
		if (*new != NULL)
			ft_lstdel(new, &ft_free_content);
		return (NULL);
	}
	if ((*new = ft_lstnewpushback(*new, fuse, ft_strlen(fuse) + 1)) == NULL)
	{
		ft_strdel(store);
		ft_strdel(&fuse);
		return (NULL);
	}
	return (*new);
}

t_list		*ft_lstread_file_no_gnl(int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*store;
	t_list	*new;

	if ((store = ft_strnew(0)) == NULL)
		return (NULL);
	new = NULL;
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (ft_check_stop(buff) == -1)
		{
			if ((store = ft_add_char(&store, buff)) == NULL)
			{
				if (new != NULL)
					ft_lstdel(&new, &ft_free_content);
				return (NULL);
			}
		}
		else
		{
			if ((new = ft_add_list(&store, buff, &new)) == NULL)
				return (NULL);
		}
		ft_bzero(buff, BUFF_SIZE);
	}
	ft_putendl("*****");
	ft_putendl(store);
	ft_putendl("*****");
//	if ((new = ft_lstnewpushback(new, store, ft_strlen(store) + 1)) == NULL)
//	{
//		return (NULL);
//	}
	return (new);
}
