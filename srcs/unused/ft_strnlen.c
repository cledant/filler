/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 18:03:39 by cledant           #+#    #+#             */
/*   Updated: 2016/05/23 18:23:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t len)
{
	size_t	length;

	length = 0;
	while (*s != '\0' && length < len)
	{
		length++;
		s++;
	}
	return (length);
}
