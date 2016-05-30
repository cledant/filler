/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:19:27 by cledant           #+#    #+#             */
/*   Updated: 2016/05/30 15:50:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void inline		ft_set_tab_int_(int (*val)[2], int x, int y)
{
	(*val)[0] = x;
	(*val)[1] = y;
}

t_env			*ft_env_init(void)
{
	t_env	*new;

	if ((new = (t_env *)malloc(sizeof(t_env) * 1)) == NULL)
		return (NULL);
	new->player = 0;
	new->size_col = 0;
	new->size_line = 0;
	new->gnl = NULL;
	new->map = NULL;
	new->p_size_col = 0;
	new->p_size_line = 0;
	new->piece = NULL;
	ft_set_tab_int(&env->start, -1, -1);
	ft_set_tab_int(&env->init, -1, -1);
	ft_set_tab_int(&env->goal, -1, -1);
	ft_set_tab_int(&env->e_top, -1, -1);
	ft_set_tab_int(&env->e_bot, -1, -1);
	ft_set_tab_int(&env->e_right, -1, -1);
	ft_set_tab_int(&env->e_left, -1, -1);
	return (new);
}
