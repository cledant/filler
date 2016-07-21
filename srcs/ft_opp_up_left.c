/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opp_up_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 13:43:00 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 02:09:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_change_attack_1(t_env *env, size_t *mode, char *me)
{
	size_t	i;

	i = 0;
	while (i < env->size_col)
	{
		if (ft_strchr(me, env->map[0][i]) != NULL)
			*mode = 1;
		i++;
	}
	i = 0;
	while (i < env->size_line)
	{
		if (ft_strchr(me, env->map[i][0]) != NULL)
			*mode = 1;
		i++;
	}
}

static void		ft_change_attack_2(t_env *env, size_t *mode, char *me)
{
	size_t	i;

	i = 0;
	while (i < env->size_col)
	{
		if (ft_strchr(me, env->map[env->size_line - 1][i]) != NULL)
			*mode = 2;
		i++;
	}
	i = 0;
	while (i < env->size_line)
	{
		if (ft_strchr(me, env->map[i][env->size_col - 1]) != NULL)
			*mode = 2;
		i++;
	}
}

char			*ft_opp_up_left(t_env *env, char *me, char *opp)
{
	size_t	mode;

	mode = 0;
	ft_change_attack_1(env, &mode, me);
	if (mode == 1)
		ft_change_attack_2(env, &mode, me);
	if (mode == 0)
		return (ft_up_left(env, me, opp));
	else if (mode == 1)
		return (ft_down_left(env, me, opp));
	else
	{
		if (ft_is_bot_free(env, opp) == 1)
			return (ft_up_left_three(env, me, opp));
		if (ft_is_top_free(env, opp) == 1)
			return (ft_down_left_three(env, me, opp));
		else
			return (ft_up_left(env, me, opp));
	}
}
