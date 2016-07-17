/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:58:54 by cledant           #+#    #+#             */
/*   Updated: 2016/07/17 19:37:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		*ft_play(t_env *env, char *me, char *opp)
{
	return (ft_right_left(env, me, opp));
}

char			*ft_turn(t_env *env)
{
	if (env->player == 1)
		return (ft_play(env, "oO", "xX"));
	else if (env->player == 2)
		return (ft_play(env, "xX", "oO" ));
	else
		return (NULL);
}
