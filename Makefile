# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/04/01 15:09:13 by hyoshie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hotrace
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I./inc -I./libft

LIBFT_DIR	=	libft
OBJDIR		=	./obj

VPATH		=	src

SRCS		=	main.c\
				debug.c

OBJS		=	$(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

DEPS		=	$(OBJS:.o=.d)

LIBS 		=	-L$(LIBFT_DIR) -lft

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# -include $(DPS)

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) 

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
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
