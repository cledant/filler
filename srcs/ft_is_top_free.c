/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_top_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:29:00 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 13:54:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_is_top_free(t_env *env, char *opp)
{
	size_t	i;

	i = 0;
	while (i < env->size_col)
	{
		if (ft_strchr(opp, env->map[0][i]) != NULL)
			return (0);
		i++;
	}
	return (1);
}
