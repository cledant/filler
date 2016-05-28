/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:58:54 by cledant           #+#    #+#             */
/*   Updated: 2016/05/28 18:08:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

char	*ft_debug_map_piece(t_env *env)
{
	int		fd;
	size_t	i;

	fd = open("./check", O_RDWR | O_APPEND);
	ft_putendl_fd("READ MAP SEULE", fd);
	i = 0;
	while (i < env->size_line)
	{
		ft_putendl_fd(env->map[i], fd);
		i++;
	}
	ft_putendl_fd("FIN READ MAP SEULE", fd);
	ft_putendl_fd("READ PIECE SEULE", fd);
	i = 0;
	while (i < env->p_size_line)
	{
		ft_putendl_fd(env->piece[i], fd);
		i++;
	}
	ft_putendl_fd("FIN READ PIECE SEULE", fd);
	close(fd);
	ft_env_reset(env);
	return (NULL);
}
