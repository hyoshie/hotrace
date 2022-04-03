# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/04/03 18:25:09 by mkamei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hotrace
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I./inc

OBJDIR		=	./obj

VPATH		=	src:src/utils:src/dict:src/hash

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
				get_next_line_utils2.c \
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

OBJS		=	$(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

DEPS		=	$(OBJS:.o=.d)

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

-include $(DEPS)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm: $(NAME)
	norminette

nm: $(NAME)
	@nm -u $(NAME) | awk '{print $$2}' | awk -F'@' '{print $$1}' | egrep -v "^_" | egrep -v "open|close|read|write|printf|malloc|free|perror|strerror|exit" | egrep -v "^X" | egrep -v "cos|sin|tan|floor|ceil|pow|sqrt|remainder"

# ignore unknown error
nmgrep:
	-@nm -u $(NAME) | awk '{print $$2}' | awk -F'@' '{print $$1}' | egrep -v "^_" | egrep -v "open|close|read|write|printf|malloc|free|perror|strerror|exit" | egrep -v "^X" | egrep -v "cos|sin|tan|floor|ceil|pow|sqrt|remainder" | xargs -I{} bash -c "echo '[[' {} ']]'; grep -rn {} src lib/libft/*/*.c"

.PHONY: all clean fclean re nm nmgrep bonus norm
