/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_right_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 15:59:15 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 16:09:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline int	ft_check_me_col(t_env *env, char *me)
{
	size_t	i;
	int		ret;

	ret = 0;
	i = env->size_line - 1;
	while (1)
	{
		if (ft_strchr(me, env->map[i][env->size_col - 1]) != NULL)
			ret = 1;
		i--;
		if (i == 0)
			break;
	}
	return (ret);
}

char				*ft_up_right_three(t_env *env, char *me, char *opp)
{
	if (ft_check_me_col(env, me) == 0)
		return (ft_down_right(env, me , opp));
	else
		return (ft_down_right_two(env, me , opp));	
}
