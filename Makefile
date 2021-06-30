# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 17:16:37 by ebellon           #+#    #+#              #
#    Updated: 2021/06/30 17:58:54 by ebellon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc #-fsanitize=address

RM			=	rm -f

FLAGS		=	-Wall -Wextra -Werror

DEBUG_FLAGS	=	-Wall -Wextra -fsanitize=address

DEBUG_OUT	=	debug.out

INCS_DIR	=	Headers/

INCS		=	push_swap.h

INCS_FULL	=	$(addprefix $(INCS_DIR), $(INCS))

SRCS_DIR	=	Srcs/

SRCS		=	list_utils.c \
				operation.c \
				main.c

SRCS_FULL	=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS		=	$(SRCS_FULL:.c=.o)

MAKE_SUB	=	make -C

LIBS_DIR	=	./

LIBS		=	libft/

LIBS_FULL	=	$(addprefix $(LIBS_DIR), $(LIBS))

LIBS_FILES	=	./libft/libft.a

all:			libraries $(NAME)

%.o: 			%.c $(INCS_FULL)
				$(CC) $(FLAGS) -I $(INCS_DIR) -c $< -o $@

$(NAME): 		$(OBJS) $(LIBS_FILES)
				$(CC) -I $(INCS_DIR) $(OBJS) $(LIBS_FILES) -o $(NAME)

libraries:
				$(foreach lib,$(LIBS_FULL), $(MAKE_SUB) $(lib))

norme:			fclean
				@norminette $(SRCS_DIR)
				@norminette $(INCS_DIR)

norme_check:	fclean
				@norminette $(SRCS_DIR) | grep " KO!" | wc -l
				@norminette $(INCS_DIR) | grep " KO!" | wc -l

debug:			libraries $(OBJS)
				printf "\033c"
				$(CC) -I $(INCS_DIR) $(DEBUG_FLAGS) $(OBJS) $(LIBS_FILES) -o $(DEBUG_OUT)
				printf "\033c"
				ARG="9 8 6 4 5 2 7 3 1 0 10 11 12"; ./$(DEBUG_OUT) $$ARG

test:			libraries $(OBJS)
				$(CC) -I $(INCS_DIR) $(FLAGS) $(OBJS) $(LIBS_FILES) -o $(NAME)
				printf "\033c"

leaks:			all
				leaks --atExit -- ARG="1 2 3 4 5 6 7"; ./push_swap $$ARG

clean:
				@$(RM) $(OBJS)
				@$(foreach lib_dir,$(LIBS_FULL), $(MAKE_SUB) $(lib_dir) clean)

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(DEBUG_OUT)
				@$(foreach lib_dir,$(LIBS_FULL), $(MAKE_SUB) $(lib_dir) fclean)

re:				fclean all

.PHONY: all, libs, norme, norme_check, debug, test, leaks, clean, fclean, re