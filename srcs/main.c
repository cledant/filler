/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:01:54 by cledant           #+#    #+#             */
/*   Updated: 2016/05/28 12:12:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	play = ft_turn(env);
	ft_lstdel(&env->gnl, ft_lstfree_malloc);
	ft_strdel(&play);
	ft_strdel(&env->map);
	env->size_col = 0;
	env->size_line = 0;
	return (0);
}
