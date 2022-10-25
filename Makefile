SRCS_DIR	= ./src/
SRCS_FILES	=  main.c \
				asset_floor_celling.c \
				asset_floor_celling_utils.c \
				check_asset.c \
				error_map.c \
				error_map_utils.c \
				init_game.c \
				main_utils.c \
				pars_map.c \
               	print_map.c \
               	stock_map.c \
				minimap.c

SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

LIBFT		= ./utils
MAKELIB		= ${MAKE} -C ${LIBFT}

LIBX		= ./mlx

MAKELIBX	= @${MAKE} -C ${LIBX}


O_DIR		= ./objs/
HEADS		= -I./inc/ -I${LIBFT} -I${LIBX}

OBJS_FILES	:= ${SRCS_FILES:.c=.o}
OBJS		:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}

OBJS		+= ${LIBFT}/libutils.a

OBJS		+= ${LIBX}/libmlx.a

LIBS		= -framework OpenGL -framework AppKit


NAME		= cub3D

CC			= cc
AR			= ar rcs
MKDIR		= mkdir
CP			= cp -f
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${O_DIR} ${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} -fsanitize=address

${O_DIR}:
			${MKDIR} ${O_DIR}

${O_DIR}%.o:${SRCS_DIR}%.c | inc/cub3d.h
			${CC} ${CFLAGS} ${HEADS} -o $@ -c $<

${LIBFT}/libutils.a:
			${MAKELIB} all

${LIBX}/libmlx.a:
			@${MAKELIBX} all

clean:
			${RM} ${OBJS} ${OBJSB}
			@${RM} -r ${O_DIR}
			@${MAKELIB} clean
			@${MAKELIBX} clean

fclean:		clean
			${RM} ${NAME}
			@${RM} -r ${NAME}.dSYM
			@${MAKELIB} fclean

re:			fclean all

.PHONY:		all clean fclean re debug
