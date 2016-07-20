/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_isolate_piece.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 17:03:58 by cledant           #+#    #+#             */
/*   Updated: 2016/07/20 13:40:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_reset(t_env *env, char ***new)
{
	if (new != NULL)
		ft_strdel_char2(new);
	ft_env_destroy(&env);
}

int				ft_env_isolate_piece(t_env *env)
{
	char	**new;
	t_list	*cpy_env;
	size_t	i;

	if ((new = ft_strnew_char2(env->p_size_line)) == NULL)
	{
		ft_env_destroy(&env);
		return (0);
	}
	cpy_env = env->gnl;
	i = 0;
	while (cpy_env != NULL && ft_strstr(cpy_env->content,
				"Piece") == NULL)
		cpy_env = cpy_env->next;
	while (cpy_env != NULL && i < 1)
	{
		cpy_env = cpy_env->next;
		i++;
	}
	i = 0;
	while (cpy_env != NULL && i < env->p_size_line)
	{
		if ((new[i] = ft_strdup(cpy_env->content)) == NULL)
		{
			ft_reset(env, &new);
			return (0);
		}
		cpy_env = cpy_env->next;
		i++;
	}
	env->piece = new;
	return (1);
}
