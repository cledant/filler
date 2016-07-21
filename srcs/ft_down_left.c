/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:39:28 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 18:09:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char			*ft_down_left(t_env *env, char *me, char *opp)
{
	size_t	i[2];

	i[0] = 0;
	i[1] = env->size_line - 1;
	while (1)
	{
		while (i[0] < env->size_col)
		{
			if (ft_can_fit(env, i, me, opp) == 1)
				return (ft_create_char(i[1], i[0]));
			i[0]++;
		}
		i[0] = 0;
		if (i[1] == 0)
			break ;
		i[1]--;
	}
	return (ft_strdup("0 0"));
}
