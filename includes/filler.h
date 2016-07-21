/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:44:21 by cledant           #+#    #+#             */
/*   Updated: 2016/07/21 01:31:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BIG_BUFF 200000
# define SPEED 500000000
# include "libft.h"

typedef struct		s_env
{
	t_list			*gnl;
	size_t			player;
	size_t			size_col;
	size_t			size_line;
	char			**map;
	size_t			p_size_col;
	size_t			p_size_line;
	char			**piece;
	size_t			speed_max;
	size_t			plan;
	char			*play;
}					t_env;

t_list				*ft_lstnewpushback(t_list *new, void *buff, size_t size);
t_list				*ft_lstreadraw_file(int fd);
t_list				*ft_lstgnl(t_list *read_1);
t_list				*ft_read_fd_0(void);
t_env				*ft_env_init(void);
void				ft_env_destroy(t_env **env);
void				ft_env_reset(t_env *env);
int					ft_env_setplayer(t_env *env);
int					ft_env_setsize(t_env *env);
int					ft_env_setpiecesize(t_env *env);
int					ft_env_isolate_map(t_env *env);
int					ft_env_isolate_piece(t_env *env);
char				*ft_turn(t_env *env);
void				ft_putendl_fd_char2(char **str, int fd);
char				*ft_add_char(char *dst, char add);
int					ft_can_fit(t_env *env, size_t i[2], char *me, char *opp);
size_t				ft_what_to_do(t_env *env, char *me, char *opp);
char				*ft_create_char(size_t i, size_t j);
int					ft_is_bot_free(t_env *env, char *opp);
int					ft_is_top_free(t_env *env, char *opp);
char				*ft_opp_up_left(t_env *env, char *me, char *opp);
char				*ft_opp_up_right(t_env *env, char *me, char *opp);
char				*ft_opp_down_left(t_env *env, char *me, char *opp);
char				*ft_opp_down_right(t_env *env, char *me, char *opp);
char				*ft_up_left(t_env *env, char *me, char *opp);
char				*ft_down_left(t_env *env, char *me, char *opp);
char				*ft_up_right(t_env *env, char *me, char *opp);
char				*ft_down_right(t_env *env, char *me, char *opp);
char				*ft_down_right_two(t_env *env, char *me, char *opp);
char				*ft_up_right_two(t_env *env, char *me, char *opp);
char				*ft_up_left_two(t_env *env, char *me, char *opp);
char				*ft_down_left_two(t_env *env, char *me, char *opp);
char				*ft_up_left_three(t_env *env, char *me, char *opp);
char				*ft_down_left_three(t_env *env, char *me, char *opp);

#endif
