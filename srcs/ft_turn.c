/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:58:54 by cledant           #+#    #+#             */
/*   Updated: 2016/05/28 15:12:36 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

char	*ft_turn(t_env *env)
{
	int fd;

	fd = open("./check", O_RDWR | O_APPEND);
	ft_putendl_fd("READ MAP SEULE", 2);
	ft_putendl_fd_char2(env->map, fd);
	ft_putendl_fd("FIN READ MAP SEULE", 2);
	close(fd);
	ft_env_reset(env);
	return (NULL);
}
