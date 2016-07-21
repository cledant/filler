/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_isolate_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 13:39:14 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 19:12:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_reset(t_env *env, char ***new)
{
	if (new != NULL)
		ft_strdel_char2(new);
	ft_env_destroy(&env);
}

static int		ft_copy(t_env *env, t_list *cpy_env, char ***new)
{
	size_t	i;

	i = 0;
	while (cpy_env != NULL && i < env->size_line)
	{
		if (((*new)[i] = ft_strdup(cpy_env->content + 4)) == NULL)
		{
			ft_reset(env, new);
			return (0);
		}
		cpy_env = cpy_env->next;
		i++;
	}
	env->map = *new;
	return (1);
}

int				ft_env_isolate_map(t_env *env)
{
	char	**new;
	t_list	*cpy_env;
	size_t	i;

	if ((new = ft_strnew_char2(env->size_line)) == NULL)
	{
		ft_env_destroy(&env);
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
	return (ft_copy(env, cpy_env, &new));
}
