/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_right_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:09:07 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 18:25:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char			*ft_up_right_two(t_env *env, char *me, char *opp)
{
	size_t	i[2];

	i[1] = 0;
	i[0] = env->size_col - 1;
	while (1)
	{
		while (i[1] < env->size_line)
		{
			if (ft_can_fit(env, i, me, opp) == 1)
				return (ft_create_char(i[1], i[0]));
			i[1]++;
		}
		i[1] = 0;
		if (i[0] == 0)
			break ;
		i[0]--;
	}
	return (ft_strdup("0 0"));
}
