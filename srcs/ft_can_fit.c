/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_fit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:31:29 by cledant           #+#    #+#             */
/*   Updated: 2016/07/18 12:59:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_check_fit(t_env *env, size_t (*c)[5], char *me, char *opp)
{
	if (env->piece[(*c)[1]][(*c)[0]] == '.')
		return (1);
	else if (ft_strchr(me, env->map[(*c)[3]][(*c)[2]]) != NULL)
		(*c)[4]++;
	else if (ft_strchr(opp, env->map[(*c)[3]][(*c)[2]]) != NULL)
		return (0);
	if ((*c)[4] > 1)
		return (0);
	return (1);
}

int		ft_can_fit(t_env *env, size_t i[2], char *me, char *opp)
{
	size_t	c[5];

	ft_bzero(c, sizeof(size_t) * 5);
	c[3] = i[1];
	c[2] = i[0];
	while (c[1] < env->p_size_line)
	{
		if (c[3] >= env->size_line)
			return (0);
		while (c[0] < env->p_size_col)
		{
			if (c[2] >= env->size_col || ft_check_fit(env, &c, me, opp) == 0)
				return (0);
			c[0]++;
			c[2]++;
		}
		c[0] = 0;
		c[2] = i[0];
		c[1]++;
		c[3]++;
	}
	if (c[4] == 0)
		return (0);
	return (1);
}
