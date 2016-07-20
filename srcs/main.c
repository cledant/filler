/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:01:54 by cledant           #+#    #+#             */
/*   Updated: 2016/07/20 14:06:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_wait(t_env *env)
{
	size_t		time;

	time = 0;
	while (time < env->speed_max)
		time++;
}

int				main(void)
{
	t_env		*env;

	if ((env = ft_env_init()) == NULL)
		return (0);
	ft_putendl_fd("COUCOU 0", 2);
	while (1)
	{
		ft_wait(env);
		ft_putendl_fd("COUCOU 1", 2);
		if ((env->gnl = ft_read_fd_0()) == NULL)
			return (0);
		ft_putendl_fd("COUCOU 2", 2);
		if (ft_env_setplayer(env) == 0)
			return (0);
		ft_putendl_fd("COUCOU 3", 2);
		if (ft_env_setsize(env) == 0)
			return (0);
		ft_putendl_fd("COUCOU 4", 2);
		if (ft_env_isolate_map(env) == 0)
			return (0);
		ft_putendl_fd("COUCOU 5", 2);
		if (ft_env_setpiecesize(env) == 0)
			return (0);
		ft_putendl_fd("COUCOU 6", 2);
		if (ft_env_isolate_piece(env) == 0)
			return (0);
		ft_putendl_fd("COUCOU 7", 2);
		if ((env->play = ft_turn(env)) == NULL)
			return (0);
		ft_putendl_fd("COUCOU 8", 2);
		ft_putendl_fd(env->play, 2);
		ft_putendl(env->play);
		ft_env_reset(env);
	}
	return (0);
}
