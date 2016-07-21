/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:34:13 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 22:04:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_delete_list(t_list **new)
{
	if (*new != NULL)
		ft_lstdel(new, ft_lstfree_malloc);
	return (0);
}

static int		ft_create_list(char *cpy, t_list **new, char **new_c)
{
	if (*cpy != '\n')
	{
		if ((*new_c = ft_add_char(*new_c, *cpy)) == NULL)
			return (ft_delete_list(new));
	}
	else
	{
		if ((*new_c = ft_add_char(*new_c, 0)) == NULL)
			return (ft_delete_list(new));
		if ((*new = ft_lstnewpushback(*new, *new_c,
						ft_strlen(*new_c) + 1)) == NULL)
		{
			ft_strdel(new_c);
			return (0);
		}
		ft_strdel(new_c);
	}
	return (1);
}

static t_list	*ft_lstnext_line(t_list *new, t_list *list)
{
	t_list	*cpy_list;
	char	*cpy;
	size_t	i;
	char	*new_c;

	i = 0;
	new_c = NULL;
	cpy_list = list;
	while (cpy_list != NULL)
	{
		cpy = cpy_list->content;
		while (i < cpy_list->content_size - 1)
		{
			if (ft_create_list(cpy, &new, &new_c) == 0)
				return (NULL);
			cpy++;
			i++;
		}
		i = 0;
		cpy_list = cpy_list->next;
	}
	return (new);
}

t_list			*ft_lstgnl(t_list *read_1)
{
	t_list	*new;

	new = NULL;
	if ((new = ft_lstnext_line(new, read_1)) == NULL)
		return (NULL);
	return (new);
}
