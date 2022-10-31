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

INC_FILES	= cub3d.h

#_______________ OBJS

OBJS_FILES		:= ${SRCS_FILES:.c=.o}
OBJS			:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}
PATH_SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}


O_DIR		= ./objs/
HEADS		= -I./inc/ -I${LIBFT} -I${LIBX}

LIBUTILS		= ./utils
MLXLIB			= ./mlx

OBJS		+= ${LIBFT}/libutils.a

OBJS		+= ${LIBX}/libmlx.a

MAKELIB			= ${MAKE} -C
CC				= gcc
AR              = ar rcs
MKDIR           = mkdir -p
RM              = rm -rf
CFLAGS          = -Wall -Wextra -Werror -g3 #-fsanitize=address -Imlx
MLXFLAGS        = -Lmlx -lmlx -framework OpenGL -framework AppKit

TSEP            = ${SEP}...${RESET}

NAME		= cub3D

CC			= cc
AR			= ar rcs
MKDIR		= mkdir
CP			= cp -f
RM			= rm -f

${NAME}:		${O_DIR} ${OBJS}
				@printf "\n"
				@${MAKELIB} ${LIBUTILS}
				@${MAKELIB} ${MLXLIB}
				@printf "${TSEP}\n"
				@printf "${GREEN} ✅ Successfully compiled ${NAME} .o's${RESET}\n"
				@${CC} ${CFLAGS} ${MLXFLAGS} -o ${NAME} ${OBJS} ${LIBUTILS}/libutils.a ${MLXLIB}/libmlx.a
				@printf "${GREEN} ✅ Successfully created ${NAME} executable${RESET}\n"
				@printf "${TSEP}\n"

${O_DIR}:
				@${MKDIR} ${O_DIR}
				@printf "\n${BUILD}${O_DIR} Directory Created ${RESET}\n\n"

${O_DIR}%.o:${SRCS_DIR}%.c
				@${CC} ${CFLAGS} -I${HEADS_DIR} -o $@ -c $<
				@printf "\e[1K\r${BUILD} 🚧 $@ from $<${RESET}"


clean :
				@${RM} ${O_DIR}

				@${MAKELIB} ${LIBUTILS} clean
				@${MAKELIB} ${MLXLIB} clean
				@printf "${RED} 🧹 Deleted ${NAME} .o's${RESET} \n"
				@printf "${RED} 🧹 Deleted mlx .o's${RESET} \n"

fclean :
				@${RM} ${O_DIR}
				@printf "${RED} 🧹 Deleted ${NAME} .o's${RESET} \n"
				@printf "${RED} 🧹 Deleted mlx .o's${RESET} \n"
				@${RM} ${NAME} ${NAME}.dSYM
				@${MAKELIB} ${LIBUTILS} fclean
				@${MAKELIB} ${MLXLIB} fclean
				@printf "${RED} 💥 Deleted ${NAME} files${RESET} \n"
				@printf "${RED} 💥 Deleted mlx files${RESET} \n"

re : 			fclean all

norm :
				@${MAKELIB} ${LIBUTILS} norm
				@printf "${DUCK} 🐥 Checking Norm for ${NAME}${RESET}\n"
				@norminette ${PATH_SRCS}

.PHONY : all clean fclean re norm
