/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down_left_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 20:58:52 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 18:12:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char			*ft_down_left_two(t_env *env, char *me, char *opp)
{
	size_t	i[2];

	i[0] = 0;
	i[1] = env->size_line - 1;
	while (i[0] < env->size_col)
	{
		while (1)
		{
			if (ft_can_fit(env, i, me, opp) == 1)
				return (ft_create_char(i[1], i[0]));
			if (i[1] == 0)
				break ;
			i[1]--;
		}
		i[0]++;
		i[1] = env->size_line - 1;
	}
	return (ft_strdup("0 0"));
}
