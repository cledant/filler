/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:01:54 by cledant           #+#    #+#             */
/*   Updated: 2016/07/17 20:03:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	static t_env	*env = NULL;
	char			*play;

	while (1)
	{
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
	if ((play = ft_turn(env)) == NULL)
		return (0);
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
