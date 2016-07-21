/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_left_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 12:52:55 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 12:53:22 by cledant          ###   ########.fr       */
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
		if (ft_strchr(me, env->map[i][0]) != NULL)
			ret = 1;
		i--;
		if (i == 0)
			break;
	}
	return (ret);
}

char			*ft_up_left_four(t_env *env, char *me, char *opp)
{
	if (ft_check_me_col(env, me) == 0)
		return (ft_up_left(env, me , opp));
	else
		return (ft_up_left_two(env, me , opp));	
}
