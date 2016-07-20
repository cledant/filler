/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 13:24:35 by cledant           #+#    #+#             */
/*   Updated: 2016/07/20 14:08:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_env_destroy(t_env **env)
{
	if ((*env)->gnl != NULL)
		ft_lstdel(&(*env)->gnl, ft_lstfree_malloc);
	if ((*env)->map != NULL)
		ft_strdel_char2(&(*env)->map);
	if ((*env)->piece != NULL)
		ft_strdel_char2(&(*env)->piece);
	if ((*env)->play != NULL)
		ft_strdel(&(*env)->play);
	ft_memdel((void **)env);
}
