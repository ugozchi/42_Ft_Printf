# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 15:20:49 by uzanchi           #+#    #+#              #
#    Updated: 2024/05/21 15:25:16 by uzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libftprintf.a
LIBFT		=	libft.a

SRCS_DIR	=	./sources/
HEAD_DIR	=	./includes/
LIBFT_DIR	=	./libft/

SRC			=	ft_print_data.c \
				ft_printf.c

SRCS		=	$(addprefix ${SRCS_DIR}, ${SRC})

OBJS		=	${SRCS:.c=.o}

all:			
				make ${LIBFT}
				make ${NAME}

${LIBFT}:
				make -C ${LIBFT_DIR}

${NAME}:		${OBJS} ${LIBFT}
				cp ${LIBFT_DIR}${LIBFT} ${NAME}
				ar rcs ${NAME} ${OBJS}

.c.o:
				${CC} ${CFLAGS} -I${HEAD_DIR} -I${LIBFT_DIR} -c $< -o $@
				
clean:
				make -C ${LIBFT_DIR} clean
				rm -f ${OBJS}

fclean:			clean
				make -C ${LIBFT_DIR} fclean
				rm -f ${NAME}

re:				fclean all

test:			all
				${CC} test.c -L. -lftprintf -I${HEAD_DIR} -I${LIBFT_DIR} -o test
				@echo "\n"
				./test

.PHONY:			all clean fclean re test
