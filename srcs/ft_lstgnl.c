/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:34:13 by cledant           #+#    #+#             */
/*   Updated: 2016/05/27 19:42:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_list	*ft_lstnext_line(t_list *new, t_list *list)
{
	t_list	*cpy_list;
	char	*cpy;
	char	*new_c;
	size_t	i;

	i = 0;
	cpy_list = list;
	new_c = NULL;
	while (cpy_list != NULL)
	{
		cpy = cpy_list->content;
		while (i < cpy_list->content_size - 1)
		{
			if (*cpy != '\n')
			{
				if ((new_c = ft_add_char(new_c, *cpy)) == NULL)
				{
					if (new != NULL)
						ft_lstdel(&new, ft_lstfree_malloc);
					return (NULL);
				}
			}
			else
			{
				if ((new_c = ft_add_char(new_c, 0)) == NULL)
				{
					if (new != NULL)
						ft_lstdel(&new, ft_lstfree_malloc);
					return (0);
				}
				if ((new = ft_lstnewpushback(new, new_c,
								ft_strlen(new_c) + 1)) == NULL)
				{
					ft_strdel(&new_c);
					return (NULL);
				}
				ft_strdel(&new_c);
			}
			cpy++;
			i++;
		}
		i = 0;
		cpy_list = cpy_list->next;
	}
	return (new);
}

t_list			*ft_lstgnl(t_list *read_1, t_list *read_2)
{
	t_list	*new;

	new = NULL;
	if ((new = ft_lstnext_line(new, read_1)) == NULL)
		return (NULL);
	if ((new = ft_lstnext_line(new, read_2)) == NULL)
		return (NULL);
	return (new);
}
