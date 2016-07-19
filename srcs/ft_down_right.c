/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:39:28 by cledant           #+#    #+#             */
/*   Updated: 2016/07/19 14:46:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_clean(char **line, char	**col)
{
	if (*line != NULL)
		ft_strdel(line);
	if (*col != NULL)
		ft_strdel(col);
}

static char		*ft_create_char(size_t i, size_t j)
{
	char	*line;
	char	*col;
	char	*ret;

	if ((line = ft_itoa(i)) == NULL)
		return (NULL);
	if ((col = ft_itoa(j)) == NULL)
	{
		ft_clean(&line, &col);
		return (NULL);
	}
	if ((ret = ft_strnew(ft_strlen(line) + ft_strlen(col) + 1)) == NULL)
	{
		ft_clean(&line, &col);
		return (NULL);
	}
	ft_strcat(ret, line);
	ft_strcat(ret, " ");
	ft_strcat(ret, col);
	ft_clean(&line, &col);
	return (ret);
}

char			*ft_down_right(t_env *env, char *me, char *opp)
{
	size_t	i[2];

	i[0] = env->size_col - 1;
	i[1] = env->size_line - 1;
	while (i[1])
	{
		while (i[0])
		{
			if (ft_can_fit(env, i, me , opp) == 1)
				return (ft_create_char(i[1], i[0]));
			i[0]--;
			if (i[0] == 0)
				break ;
//			ft_putnbr_fd(i[1], 2);
//			ft_putstr_fd(" ", 2);
//			ft_putnbrendl_fd(i[0], 2);
		}
		i[0] = env->size_col - 1;
		i[1]--;
		if (i[1] == 0)
			break ;
	}
	return (ft_strdup("0 0"));
}
