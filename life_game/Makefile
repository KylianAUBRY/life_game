NAME	=	life

LIBDIR = ./minilibx-linux

SRCS	=	main.c	\
			ft_error.c \
			get_next_line.c \
			get_next_line_utils.c \
			utils.c \
			init.c \
			ft_free.c \
			ft_hand.c \
			ft_affi_hand.c \

OBJ =	${SRCS:.c=.o}

CC =	cc

CFLAGS	=	-Wall -Wextra -Werror -g

.c.o:
			$(CC) $(CFLAGS) -Iminilibx-linux  -Imlx_linux -c $< -o $(<:.c=.o)

$(NAME): ${OBJ}
		cd ./minilibx-linux && ./configure && $(MAKE)
		$(CC) ${OBJ} -Iminilibx-linux minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME) 
#-L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
all:	${NAME}

clean:
		rm -f ${OBJ}
		cd ${LIBDIR} && ${MAKE} clean

fclean:	clean
		rm -f ${NAME}
		cd ${LIBDIR} && ${MAKE} clean
		
re:	fclean all

.PHONY: all clean fclean re