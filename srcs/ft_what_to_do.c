/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_to_do.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:37:48 by cledant           #+#    #+#             */
/*   Updated: 2016/07/19 13:38:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_seek_position(t_env *env, char *me, char *opp,
					size_t (*p)[4])
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < env->size_line)
	{
		while (j < env->size_col)
		{
			if (ft_strchr(me, env->map[i][j]) != NULL)
			{
				(*p)[0] = i;
				(*p)[1] = j;
			}
			if (ft_strchr(opp, env->map[i][j]) != NULL)
			{
				(*p)[2] = i;
				(*p)[3] = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

size_t			ft_what_to_do(t_env *env, char *me, char *opp)
{
	size_t	player[4];

	ft_bzero(player, sizeof(size_t) * 4);
	ft_seek_position(env, me, opp, &player);
	if (player[0] >= player[2])
		return ((player[1] >= player[3]) ? 1 : 2);
	else
		return ((player[1] >= player[3]) ? 3 : 4);
}
