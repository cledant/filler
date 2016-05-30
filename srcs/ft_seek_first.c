/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:50:21 by cledant           #+#    #+#             */
/*   Updated: 2016/05/30 16:44:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_seek_first(t_env *env, char *who)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (env->start[0] != -1 && env->start[1] != -1)
		return (0);
	while (j < size_col)
	{
		while (j < size_line)
		{
			if (env->map[i][j] == who[0] || env->map[i][j] == who[1])
			{
				env->start[0] = i;
				env->start[1] = j;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
