/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:44:21 by cledant           #+#    #+#             */
/*   Updated: 2016/07/19 11:26:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BIG_BUFF 200000
# define SPEED 500000000
# include "libft.h"

typedef struct		s_env
{
	size_t			player;
	size_t			size_col;
	size_t			size_line;
	t_list			*gnl;
	char			**map;
	size_t			p_size_col;
	size_t			p_size_line;
	char			**piece;
	size_t			speed_max;
	size_t			plan;
}					t_env;

t_list				*ft_lstnewpushback(t_list *new, void *buff, size_t size);
t_list				*ft_lstreadraw_file(int fd);
t_list				*ft_lstgnl(t_list *read_1);
t_list				*ft_read_fd_0(void);
t_env				*ft_env_init(void);
void				ft_env_reset(t_env *env);
int					ft_env_setplayer(t_env *env);
int					ft_env_setsize(t_env *env);
int					ft_env_setpiecesize(t_env *env);
int					ft_env_isolate_map(t_env *env);
int					ft_env_isolate_piece(t_env *env);
char				*ft_turn(t_env *env);
void				ft_putendl_fd_char2(char **str, int fd);
char				*ft_add_char(char *dst, char add);
char				*ft_right_left(t_env *env, char *me, char *opp);
int					ft_can_fit(t_env *env, size_t i[2], char *me, char *opp);

#endif
