/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:01:54 by cledant           #+#    #+#             */
/*   Updated: 2016/07/19 10:37:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	static t_env	*env = NULL;
	char			*play;
	size_t			time;

	time = 0;
	while (1)
	{
		if (env == NULL)
			if ((env = ft_env_init()) == NULL)
				return (0);
		ft_putendl_fd("COUCOU 0", 2);
		while (time < env->speed_max)
			time++;
		time = 0;
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
		if ((play = ft_turn(env)) == NULL)
			return (0);
		ft_putendl_fd("COUCOU 8", 2);
		ft_putendl_fd(play, 2);
		ft_putendl(play);
		ft_lstdel(&env->gnl, ft_lstfree_malloc);
		ft_strdel(&play);
		ft_strdel_char2(&env->map);
		env->size_col = 0;
		env->size_line = 0;
		ft_strdel_char2(&env->piece);
		env->p_size_col = 0;
		env->p_size_line = 0;
	}
	return (0);
}
