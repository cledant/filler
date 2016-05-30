/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 18:08:47 by cledant           #+#    #+#             */
/*   Updated: 2016/05/30 18:27:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_turn(t_env *env)
{
	char	*rep;

	if (env->player == 1)
		rep = ft_simple_fill(env, "Oo", "Xx");
	else
		rep = ft_simple_fill(env, "Xx", "Oo");
	if (rep != NULL)
	{
		ft_putendl(rep);
		ft_strdel(&rep);
	}
	else
		ft_putendl("0 0");
}
