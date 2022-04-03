# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/04/03 16:18:30 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hotrace
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I./inc

VPATH		=	src:src/utils:src/dict:src/hash

SRCS		=	main.c hash.c search_htable.c store_htable.c \
				ft_putendl_fd.c ft_putstr_fd.c ft_strlen.c ft_strcmp.c \
				get_next_line_before.c get_next_line_utils.c \
				dict_addback.c dict_clear.c dict_delone.c dict_new.c \
				dict_search_item.c \

OBJS		=	$(SRCS:.c=.o)

DEPS		=	$(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm: $(NAME)
	norminette

.PHONY: all clean fclean re nm nmgrep bonus norm
