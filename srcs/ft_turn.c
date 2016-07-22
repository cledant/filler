/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:58:54 by cledant           #+#    #+#             */
/*   Updated: 2016/07/22 15:09:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		*ft_play(t_env *env, char *me, char *opp)
{
	if (env->plan == 0)
		env->plan = ft_what_to_do(env, me, opp);
	if (env->plan == 1)
		return (ft_opp_up_left(env, me, opp));
	else if (env->plan == 2)
		return (ft_opp_up_right(env, me, opp));
	else if (env->plan == 3)
		return (ft_opp_down_left(env, me, opp));
	else if (env->plan == 4)
		return (ft_opp_down_right(env, me, opp));
	else
		return (ft_up_right(env, me, opp));
}

char			*ft_turn(t_env *env)
{
	if (env->player == 1)
		return (ft_play(env, "oO", "xX"));
	else if (env->player == 2)
		return (ft_play(env, "xX", "oO"));
	else
		return (NULL);
}
