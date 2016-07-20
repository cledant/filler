/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_top_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:29:00 by cledant           #+#    #+#             */
/*   Updated: 2016/07/20 19:31:31 by cledant          ###   ########.fr       */
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
			return (1);
		i++;
	}
	return (0);
}
