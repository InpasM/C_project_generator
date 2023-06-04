# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 22:43:06 by mehdisapin        #+#    #+#              #
#    Updated: 2023/06/04 22:43:15 by mehdisapin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ##################################### #
#               VARIABLES               #
# ##################################### #

UNAME		=	$(shell uname)

NOCOLOR		=	\033[0m
BGREEN		=	\033[1;32m

NAME		=	project_gen

MAKEFILE	=	Makefile

HEADER 		= 	includes/project_gen.h

LIBFT_DIR	=	includes/libft/
LIBFT_A		=	$(LIBFT_DIR)libft.a

CFLAGS 		= 	-Wall -Wextra -Werror

RM 			= 	rm -rf

AR 			= 	ar

ARFLAGS 	= 	-rcs


# ##################################### #
#                 PATHS                 #
# ##################################### #

SRCS_PATH	=	sources/

SRC_GENERATE_PATH		=	$(SRCS_PATH)generate/
SRC_INPUT_PATH			=	$(SRCS_PATH)input/
SRC_DATABASE_PATH			=	$(SRCS_PATH)database/

OBJ_GENERATE_PATH		=	$(SRC_GENERATE_PATH).objs/
OBJ_INPUT_PATH			=	$(SRC_INPUT_PATH).objs/
OBJ_DATABASE_PATH			=	$(SRC_DATABASE_PATH).objs/

OBJS_DIRS	=	$(OBJ_GENERATE_PATH)	$(OBJ_INPUT_PATH)	$(OBJ_DATABASE_PATH) 


# ##################################### #
#                SOURCES                #
# ##################################### #

SRC_GENERATE_FILES		=	makefile.c	header.c	project_structure.c

SRC_INPUT_FILES			=	get_input.c

SRC_DATABASE_FILES		=	parsing_database.c

SRCS_GENERATE		=	$(addprefix $(SRC_GENERATE_PATH), $(SRC_GENERATE_FILES))
SRCS_INPUT			=	$(addprefix $(SRC_INPUT_PATH), $(SRC_INPUT_FILES))
SRCS_DATABASE		=	$(addprefix $(SRC_DATABASE_PATH), $(SRC_DATABASE_FILES))

SRCS	=	$(SRCS_GENERATE)	$(SRCS_INPUT)	$(SRCS_DATABASE)


# ##################################### #
#                OBJECTS                #
# ##################################### #

OBJS_GENERATE		=	$(addprefix $(OBJ_GENERATE_PATH),		\
						$(SRC_GENERATE_FILES:.c=.o))

OBJS_INPUT			=	$(addprefix $(OBJ_INPUT_PATH),		\
						$(SRC_INPUT_FILES:.c=.o))

OBJS_DATABASE		=	$(addprefix $(OBJ_DATABASE_PATH),		\
						$(SRC_DATABASE_FILES:.c=.o))

OBJS	=	$(OBJS_GENERATE)	$(OBJS_INPUT)	$(OBJS_DATABASE)

$(OBJ_GENERATE_PATH)%.o: $(SRC_GENERATE_PATH)%.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_INPUT_PATH)%.o: $(SRC_INPUT_PATH)%.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DATABASE_PATH)%.o: $(SRC_DATABASE_PATH)%.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<



# ##################################### #
#                 RULES                 #
# ##################################### #

all:		make_libft $(OBJS_DIRS) $(NAME)

make_libft:
			$(MAKE) -C $(LIBFT_DIR)

$(LIBFT_A):
			$(MAKE) make_libft

$(OBJS_DIRS):
			mkdir -p $(OBJS_DIRS)

$(NAME):	$(LIBFT_A) $(OBJS)
ifeq	($(UNAME),Linux)
	$(AR) $(ARFLAGS) $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT_A)
	@echo "$(BGREEN)Linux Compilation Done$(NOCOLOR)"
else ifeq ($(UNAME),Darwin)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT_A) $(OBJS)
	@echo "$(BGREEN)Mac OS Compilation Done$(NOCOLOR)"
endif

clean:
			$(MAKE) clean -C $(LIBFT_DIR)
			$(RM) $(OBJS)

fclean:
			$(MAKE) fclean -C $(LIBFT_DIR)
			$(MAKE) clean
			$(RM) $(NAME)
			$(RM) $(OBJS_DIRS)

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY:		all clean fclean re make_libft

.SILENT:
