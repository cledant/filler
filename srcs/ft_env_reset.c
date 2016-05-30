/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:40:12 by cledant           #+#    #+#             */
/*   Updated: 2016/05/30 15:50:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_env_reset(t_env *env)
{
	env->player = 0;
	env->size_col = 0;
	env->size_line = 0;
	env->p_size_col = 0;
	env->p_size_line = 0;
	if (env->gnl != NULL)
		ft_lstdel(&env->gnl, ft_lstfree_malloc);
	if (env->map != NULL)
		ft_strdel_char2(&env->map);
	if (env->piece != NULL)
		ft_strdel_char2(&env->piece);
	ft_set_tab_init(&env->start, -1, -1);
	ft_set_tab_init(&env->init, -1, -1);
	ft_set_tab_init(&env->goal, -1, -1);
	ft_set_tab_init(&env->e_top, -1, -1);
	ft_set_tab_init(&env->e_bot, -1, -1);
	ft_set_tab_init(&env->e_right, -1, -1);
	ft_set_tab_init(&env->e_left, -1, -1);
}
