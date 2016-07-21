/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:40:17 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 18:34:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char			*ft_up_left(t_env *env, char *me, char *opp)
{
	size_t	i[2];

	ft_bzero(i, sizeof(size_t) * 2);
	while (i[1] < env->size_line)
	{
		while (i[0] < env->size_col)
		{
			if (ft_can_fit(env, i, me, opp) == 1)
				return (ft_create_char(i[1], i[0]));
			i[0]++;
		}
		i[0] = 0;
		i[1]++;
	}
	return (ft_strdup("0 0"));
}
