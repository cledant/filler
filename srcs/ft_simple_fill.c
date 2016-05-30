/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 11:14:15 by cledant           #+#    #+#             */
/*   Updated: 2016/05/30 18:27:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_seek_and_destroy(t_env *env, char *me, char *other)
{
	char	*play;

	if (ft_seek_first(env, me) == 0)
		return (NULL);
//	ft_size_ennemy(env, other);
	ft_set_goal(env);
	ft_set_init(env);
	play = ft_put_piece(env);
	return (play);
}
