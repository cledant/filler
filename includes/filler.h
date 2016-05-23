/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:44:21 by cledant           #+#    #+#             */
/*   Updated: 2016/05/23 18:12:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

t_list		*ft_lstreadraw_file(int fd);
t_list		*ft_lstread_file_no_gnl(int fd);
t_list		*ft_lstnewpushback(t_list *new, void *buff, size_t size);
size_t		ft_strnlen(const char *s, size_t size);
char		*ft_strjoin_n_s2(char const *s1, char const *s2, size_t size);

#endif
