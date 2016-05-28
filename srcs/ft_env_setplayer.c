/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_setplayer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:24:16 by cledant           #+#    #+#             */
/*   Updated: 2016/05/28 15:09:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_env_setplayer(t_env *env)
{
	if (ft_strstr(env->gnl->content, "$$$ exec p") != NULL)
	{
		env->player = ft_atoi(env->gnl->content + 10);
		return (1);
	}
	if (env->player == 0)
	{
		ft_env_reset(env);
		return (0);
	}
	return (1);
}
