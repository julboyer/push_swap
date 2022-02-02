NAME= push_swap

SRCS_LIST = $(addprefix ./srcs/, ${SRCS})

LIBFT = ./libft/libft.a

SRCS =	main.c \
		ft_strcmp.c \
		ft_strdup.c \
		instructions_utils.c \
		lst_data.c \
		psw_topos.c \
		quicksort.c \
		ft_strlen.c \
		ft_strcpy.c \
		ft_abs.c

OBJ = ${SRCS_LIST:.c=.o}

UTILS_LIST = $(addprefix ./utils/, ${UTILS})

UTILS =	checkargs.c \
		ft_atol.c \
		ft_split.c \
		lst_utils.c \
		stack_rops.c \
		is_sorted.c

UTILS_OBJ = ${UTILS_LIST:.c=.o}

HEADERS = ./includes

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SANITIZE = -g3 -fsanitize=address

%.o : %.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADERS} ${SANITIZE}

all :	${NAME}

$(NAME) :	${UTILS_OBJ} ${OBJ}
			${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${UTILS_OBJ} -I ${HEADERS} -D BUFFERSIZE=100 ${SANITIZE}

clean :	
		${RM} ${OBJ} ${UTILS_OBJ}

fclean :	clean
			${RM} ${NAME}

re :	fclean all

bonus :		all


.PHONY: all clean fclean re so