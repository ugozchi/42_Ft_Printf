CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libftprintf.a

SRCS_DIR	=	./sources/
HEAD_DIR	=	./includes/


SRC			=	ft_print_data.c \
				ft_printf.c \
				ft_strlen.c

SRCS		=	$(addprefix ${SRCS_DIR}, ${SRC})

OBJS		=	${SRCS:.c=.o}

all:			
				make ${NAME}

${NAME}:		${OBJS} 
				ar rcs ${NAME} ${OBJS}

.c.o:
				${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o $@
				
clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
