/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_setplayer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:24:16 by cledant           #+#    #+#             */
/*   Updated: 2016/05/28 11:58:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_env_setplayer(t_env *env);
{
	char	*cpy;

	if (strstr(env->content, "$$$ exec p") != NULL)
	{
		cpy = env->content;
		cpy = cpy + 10;
		env->player = ft_atoi(cpy);
		return (1);
	}
	if (env->player == 0)
		return (0);
	return (1);
}
