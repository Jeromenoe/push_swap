# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnoe <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 11:32:26 by jnoe              #+#    #+#              #
#    Updated: 2019/01/22 14:51:19 by jnoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH	=	includes/

SRC_PATH	=	srcs/

SRC_NAME1 	= push_swap.c	\
			  ft_tri.c		\
			  ft_is_tri.c		\
			  ft_start_a_to_b.c		\
			  ft_first_start_a_to_b.c    	\
			  ft_comp.c    	\
			  ft_a_to_b.c		\
			  ft_b_to_a.c    	\
			  ft_tri_a.c    \
			  ft_tri_b.c    \
			  ft_count.c	\
			  ft_check.c  	\
			  ft_exit.c		\
			  ft_list.c    \
			  ft_list_instr.c    \
			  ft_median.c	\
			  ft_instr_push_swap.c	\
			  ft_instr_rotate.c	\
			  ft_instr_reverse_rotate.c	\
			  ft_free.c		\
			  ft_affichage.c

SRC_NAME2 	= checker.c		\
			  ft_check.c 	\
			  ft_exit.c		\
			  ft_list.c    \
			  ft_list_instr.c 	\
			  ft_free.c

OBJ_PATH	=	objs/

CPPFLAGS	=	-Iincludes

LDFLAGS		=	-Llibft
LDLIBS		=	-lft

NAME1		=	push_swap
NAME2		=	checker

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

OBJ_NAME1	=	$(SRC_NAME1:.c=.o)
OBJ_NAME2	=	$(SRC_NAME2:.c=.o)

SRC1		=	$(addprefix $(SRC_PATH),$(SRC_NAME1))
SRC2		=	$(addprefix $(SRC_PATH),$(SRC_NAME2))
OBJ1		=	$(addprefix $(OBJ_PATH),$(OBJ_NAME1))
OBJ2		=	$(addprefix $(OBJ_PATH),$(OBJ_NAME2))

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	make -C libft/
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ1) -o $@

$(NAME2): $(OBJ2)
	make -C libft/
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ2) -o $@

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

lib_make_fclean:
	make -C libft/ fclean

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: lib_make_fclean fclean all

.PHONY:	all, clean, fclean, re
