CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iinclude/
SRC_DIR = src/
SRCS =	${SRC_DIR}ft_printf.c\
		${SRC_DIR}format.c\
		${SRC_DIR}utils.c\
		${SRC_DIR}utils1.c\
		${SRC_DIR}utils2.c\
		${SRC_DIR}print.c\
		${SRC_DIR}print1.c\
		${SRC_DIR}formatted_flags.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a

all : ${NAME}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

main :
	${CC} ${CFLAGS} ${SRCS} src/main.c -o ft_printf.exe && ./ft_printf.exe
