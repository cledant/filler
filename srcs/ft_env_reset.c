/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:40:12 by cledant           #+#    #+#             */
/*   Updated: 2016/05/28 15:16:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_env_reset(t_env *env)
{
	env->player = 0;
	env->size_col = 0;
	env->size_line = 0;
	if (env->gnl != NULL)
		ft_lstdel(&env->gnl, ft_lstfree_malloc);
	if (env->map != NULL)
		ft_strdel_char2(&env->map);
}
