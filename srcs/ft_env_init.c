/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 11:19:27 by cledant           #+#    #+#             */
/*   Updated: 2016/05/28 11:23:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_env	*ft_env_init(void)
{
	t_env	*new;

	if ((new = (t_env *)malloc(sizeof(t_env * 1))) == NULL)
		return (NULL);
	new->player = 0;
	new->size_col = 0;
	new->size_col = 0;
	new->gnl = NULL;
	new->map = NULL;
	return (new);
}
