/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_isolate_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 13:39:14 by cledant           #+#    #+#             */
/*   Updated: 2016/05/28 15:11:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_reset(t_env *env, char ***new)
{
	if (new != NULL)
		ft_strdel_char2(new);
	ft_env_reset(env);
}

int				ft_env_isolate_map(t_env *env)
{
	char	**new;
	t_list	*cpy_env;
	size_t	i;

	if ((new = ft_strnew_char2(env->size_line)) == NULL)
	{
		ft_env_reset(env);
		return (0);
	}
	cpy_env = env->gnl;
	i = 0;
	while (cpy_env != NULL && ft_strstr(cpy_env->content,
				"Plateau") == NULL)
		cpy_env = cpy_env->next;
	while (cpy_env != NULL && i < 2)
	{
		cpy_env = cpy_env->next;
		i++;
	}
	i = 0;
	while (cpy_env != NULL)
	{
		if ((new[i] = ft_strdup(cpy_env->content + 4)) == NULL)
		{
			ft_reset(env, &new);
			return (0);
		}
		cpy_env = cpy_env->next;
		i++;
	}
	return (1);
}
