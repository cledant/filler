# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2016/07/21 23:17:28 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRC_NAME = main.c ft_lstnewpushback.c ft_lstreadraw_file.c ft_lstgnl.c \
		   ft_add_char.c ft_read_fd_0.c ft_env_setplayer.c ft_env_setsize.c \
		   ft_env_isolate_map.c ft_turn.c ft_env_reset.c ft_env_init.c \
		   ft_env_isolate_piece.c ft_env_setpiecesize.c ft_up_left.c \
		   ft_can_fit.c ft_down_left.c ft_opp_up_left.c ft_create_char.c \
		   ft_opp_up_right.c ft_opp_down_left.c ft_opp_down_right.c \
		   ft_down_right.c ft_up_right.c ft_what_to_do.c ft_env_destroy.c \
		   ft_down_right_two.c ft_up_right_two.c ft_is_bot_free.c \
		   ft_is_top_free.c ft_down_left_two.c ft_up_left_two.c \
		   ft_up_left_three.c ft_down_left_three.c ft_up_left_four.c \
		   ft_down_left_four.c ft_down_right_three.c ft_up_right_three.c
 
SRC_PATH = ./srcs/

SRC =	$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =	$(SRC_NAME:.c=.o)

NAME = cledant.filler

all :	libft $(NAME)

libft :
	make -C $(LIBFT_PATH)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lft -I$(INCLUDES) -I$(INCLUDES_LIBFT) -L$(LIBFT_PATH)

$(OBJ) :
	$(CC) -c $(SRC) $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft
