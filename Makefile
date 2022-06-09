CLIENT = client
SERVER = server
CLIENT_SRCS = srcs/ft_client.c
SERVER_SRCS = srcs/ft_server.c
LIBFT = libft/*.c
GCC = gcc -Wall -Werror -Wextra -I .
RM = rm -rf

all:${CLIENT} ${SERVER}

${CLIENT} : 
	${GCC} ${CLIENT_SRCS} ${LIBFT} -o ${CLIENT}

${SERVER} : 
	${GCC} ${SERVER_SRCS} ${LIBFT} -o ${SERVER}

clean:
	${RM} *.o
	${RM} libft/*.o

fclean:
	${RM} *.o ${CLIENT} ${SERVER}
	${RM} libft/*.o

re: fclean all

.PHONY: all clean fclean re