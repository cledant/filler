/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_setpiecesize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 17:13:49 by cledant           #+#    #+#             */
/*   Updated: 2016/07/20 14:06:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_env_setpiecesize(t_env *env)
{
	t_list	*cpy_gnl;
	char	**split;

	cpy_gnl = env->gnl;
	while (cpy_gnl != NULL)
	{
		if (ft_strstr(cpy_gnl->content, "Piece") != NULL)
		{
			if ((split = ft_strsplit(cpy_gnl->content, ' ')) == NULL)
			{
				ft_env_destroy(&env);
				return (0);
			}
			env->p_size_line = ft_atoi(split[1]);
			env->p_size_col = ft_atoi(split[2]);
			ft_strdel_char2(&split);
			return (1);
		}
		cpy_gnl = cpy_gnl->next;
	}
	ft_env_destroy(&env);
	return (0);
}
