/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:01:54 by cledant           #+#    #+#             */
/*   Updated: 2016/05/30 15:19:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

int		main(void)
{
	static t_env	*env = NULL;
	char			*play;

	if (env == NULL)
		if ((env = ft_env_init()) == NULL)
			return (0);
	if ((env->gnl = ft_read_fd_0()) == NULL)
		return (0);
	if (ft_env_setplayer(env) == 0)
		return (0);
	if (ft_env_setsize(env) == 0)
		return (0);
	if (ft_env_isolate_map(env) == 0)
		return (0);
	if (ft_env_setpiecesize(env) == 0)
		return (0);
	if (ft_env_isolate_piece(env) == 0)
		return (0);
	ft_turn(env);
	ft_lstdel(&env->gnl, ft_lstfree_malloc);
	ft_strdel_char2(&env->map);
	ft_strdel_char2(&env->piece);
	env->size_col = 0;
	env->size_line = 0;
	env->p_size_col = 0;
	env->p_size_line = 0;
	return (0);
}
