/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 10:47:49 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 18:35:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_list		*ft_read_fd_0(void)
{
	t_list	*read_1;
	t_list	*gnl;

	read_1 = NULL;
	if ((read_1 = ft_lstreadraw_file(0)) == NULL)
		return (NULL);
	if ((gnl = ft_lstgnl(read_1)) == NULL)
	{
		ft_lstdel(&read_1, ft_lstfree_malloc);
		return (NULL);
	}
	ft_lstdel(&read_1, ft_lstfree_malloc);
	return (gnl);
}
