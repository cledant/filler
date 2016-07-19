/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opp_up_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 13:43:00 by cledant           #+#    #+#             */
/*   Updated: 2016/07/19 14:25:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_opp_up_right(t_env *env, char *me, char *opp)
{
	size_t	i;
	size_t	mode;

	i = 0;
	mode = 0;
	while (i < env->size_col)
	{
		if (ft_strchr(me, env->map[0][i]) != NULL)
			mode = 1;
		i++;
	}
	i = 0;
	while (i < env->size_line)
	{
		if (ft_strchr(me, env->map[i][env->size_col - 1]) != NULL)
			mode = 1;
		i++;
	}
	if (mode == 0)
		return (ft_up_right(env, me, opp));
	else
		return (ft_down_right(env, me, opp));
}
