/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_to_do.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:37:48 by cledant           #+#    #+#             */
/*   Updated: 2016/07/19 11:56:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

size_t		ft_what_do_do(t_env *env, char *me, char *opp)
{
	size_t	player[4];

	ft_bzero(other, sizeof(size_t) * 4);
	ft_seek_position(env, me, opp);
	if (player[0] >= player[2])
	{
		if (player[1] >= player[3])
			return (1);
		else
			return (2);
	}
}
