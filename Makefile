# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/04/03 19:12:11 by mkamei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hotrace
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	dict_addback.c \
				dict_clear.c \
				dict_delone.c \
				dict_new.c \
				dict_search_item.c \
				ft_putendl_fd.c \
				ft_putstr_fd.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strlen.c \
				get_next_line.c \
				get_next_line_utils.c \
				hash.c \
				llst_addback.c \
				llst_clear.c \
				llst_delone.c \
				llst_insert.c \
				llst_isempty.c \
				llst_last.c \
				llst_link.c \
				llst_new.c \
				my_strlcpy.c \
				search_htable.c \
				store_htable.c \
				main.c

OBJS		=	$(notdir $(SRCS:.c=.o))

DEPS		=	$(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
