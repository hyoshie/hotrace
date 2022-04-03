# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/04/03 11:25:48 by hyoshie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hotrace
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I./inc -I./libft

LIBFT_DIR	=	libft
OBJDIR		=	./obj

VPATH		=	src:src/list:src/hash

SRCS_LIST	=	main_list.c\
				debug.c

SRCS_HASH	=	main_hash.c\
				cell_clear.c\
				cell_delone.c\
				cell_new.c\
				hash_create_table.c\
				hash_delete.c\
				hash_delete_table.c\
				hash_func.c\
				hash_insert.c\
				hash_is_empty.c\
				hash_length.c\
				hash_search.c

OBJS_LIST	=	$(addprefix $(OBJDIR)/, $(notdir $(SRCS_LIST:.c=.o)))
OBJS_HASH	=	$(addprefix $(OBJDIR)/, $(notdir $(SRCS_HASH:.c=.o)))

DEPS		=	$(OBJS:.o=.d)

LIBS 		=	-L$(LIBFT_DIR) -lft

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# -include $(DPS)

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS_HASH)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_HASH) $(LIBS) 

list: $(OBJS_LIST)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o hr_list $(OBJS_LIST) $(LIBS) 

hash: $(OBJS_HASH)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o hr_hash $(OBJS_HASH) $(LIBS) 

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(RM) $(OBJS_LIST) $(OBJS_HASH) $(DEPS)
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
