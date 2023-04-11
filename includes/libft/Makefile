# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:23:25 by msapin            #+#    #+#              #
#    Updated: 2023/02/08 16:49:29 by mehdisapin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ###################################### #
#               VARIABLES		         #
# ###################################### #

NAME 		= 	libft.a

MAKEFILE 	= 	Makefile

HEADER 		= 	includes/libft.h

CFLAGS 		= 	-Wall -Wextra -Werror

RM 			= 	rm -rf

AR 			= 	ar

ARFLAGS 	= 	-rcs


# ###################################### #
#                 PATHS		             #
# ###################################### #

SRCS_PATH	=	./sources/

SRC_ARRAY_PATH		=	$(SRCS_PATH)ft_array/
SRC_CHECK_PATH		=	$(SRCS_PATH)ft_check/
SRC_CONVERT_PATH	=	$(SRCS_PATH)ft_convert/
SRC_DISPLAY_PATH	=	$(SRCS_PATH)ft_display/
SRC_FILE_PATH		=	$(SRCS_PATH)ft_file/
SRC_LIST_PATH		=	$(SRCS_PATH)ft_list/
SRC_MEMORY_PATH		=	$(SRCS_PATH)ft_memory/
SRC_PRINTF_PATH		=	$(SRCS_PATH)ft_printf/
SRC_STRING_PATH		=	$(SRCS_PATH)ft_string/

OBJ_ARRAY_PATH		=	$(SRC_ARRAY_PATH)obj_array/
OBJ_CHECK_PATH		=	$(SRC_CHECK_PATH)obj_check/
OBJ_CONVERT_PATH	=	$(SRC_CONVERT_PATH)obj_convert/
OBJ_DISPLAY_PATH	=	$(SRC_DISPLAY_PATH)obj_display/
OBJ_FILE_PATH		=	$(SRC_FILE_PATH)obj_file/
OBJ_LIST_PATH		=	$(SRC_LIST_PATH)obj_list/
OBJ_MEMORY_PATH		=	$(SRC_MEMORY_PATH)obj_memory/
OBJ_PRINTF_PATH		=	$(SRC_PRINTF_PATH)obj_printf/
OBJ_STRING_PATH		=	$(SRC_STRING_PATH)obj_string/

SRCS_DIR			=	$(SRC_ARRAY_PATH)						\
						$(SRC_CHECK_PATH)	$(SRC_CONVERT_PATH)	\
						$(SRC_DISPLAY_PATH)	$(SRC_FILE_PATH)	\
						$(SRC_LIST_PATH)	$(SRC_MEMORY_PATH)	\
						$(SRC_PRINTF_PATH)	$(SRC_STRING_PATH)

OBJS_DIR			=	$(OBJ_ARRAY_PATH)						\
						$(OBJ_CHECK_PATH)	$(OBJ_CONVERT_PATH)	\
						$(OBJ_DISPLAY_PATH)	$(OBJ_FILE_PATH)	\
						$(OBJ_LIST_PATH)	$(OBJ_MEMORY_PATH)	\
						$(OBJ_PRINTF_PATH)	$(OBJ_STRING_PATH)


# ###################################### #
#           	  SOURCES		         #
# ###################################### #

SRC_ARRAY_FILES		=	ft_arradd_back.c	ft_arrlen.c		ft_arrfree.c	\
						ft_arrdup.c

SRC_CHECK_FILES		=	ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
						ft_isdigit.c	ft_isprint.c	ft_memcmp.c		\
						ft_strchr.c		ft_strlen.c		ft_strncmp.c	\
						ft_strnstr.c	ft_strrchr.c	ft_intlen.c		\
						ft_strlen_null.c

SRC_CONVERT_FILES	=	ft_atoi.c		ft_itoa.c		ft_tolower.c	\
						ft_toupper.c

SRC_DISPLAY_FILES	=	ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	\
						ft_putstr_fd.c

SRC_FILE_FILES	=	get_next_line.c		get_file.c

SRC_LIST_FILES	=	ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c	\
					ft_lstdelone.c		ft_lstiter.c		ft_lstlast.c	\
					ft_lstmap.c			ft_lstnew.c			ft_lstsize.c	\
					ft_lstfree.c

SRC_MEMORY_FILES	=	ft_bzero.c	ft_calloc.c		ft_memchr.c	\
						ft_memcpy.c	ft_memmove.c	ft_memset.c

SRC_PRINTF_FILES	=	ft_printf.c	ft_printf_format.c	\
						ft_printf_format_utils.c	

SRC_STRING_FILES	=	ft_split.c		ft_strdup.c		ft_striteri.c	\
						ft_strjoin.c	ft_strlcat.c	ft_strlcpy.c	\
						ft_strmapi.c	ft_strtrim.c	ft_substr.c

SRCS_ARRAY		=	$(addprefix $(SRC_ARRAY_PATH), $(SRC_ARRAY_FILES))
SRCS_CHECK		=	$(addprefix $(SRC_CHECK_PATH), $(SRC_CHECK_FILES))
SRCS_CONVERT	=	$(addprefix $(SRC_CONVERT_PATH), $(SRC_CONVERT_FILES))
SRCS_DISPLAY	=	$(addprefix $(SRC_DISPLAY_PATH), $(SRC_DISPLAY_FILES))
SRCS_FILE		=	$(addprefix $(SRC_FILE_PATH), $(SRC_FILE_FILES))
SRCS_LIST		=	$(addprefix $(SRC_LIST_PATH), $(SRC_LIST_FILES))
SRCS_MEMORY		=	$(addprefix $(SRC_MEMORY_PATH), $(SRC_MEMORY_FILES))
SRCS_PRINTF		=	$(addprefix $(SRC_PRINTF_PATH), $(SRC_PRINTF_FILES))
SRCS_STRING		=	$(addprefix $(SRC_STRING_PATH), $(SRC_STRING_FILES))

SRCS		=	$(SRCS_ARRAY)												\
				$(SRCS_CHECK) $(SRCS_CONVERT) $(SRCS_DISPLAY) $(SRCS_FILE) 	\
				$(SRCS_LIST) $(SRCS_MEMORY) $(SRCS_PRINTF) $(SRCS_STRING)


# ###################################### #
#                OBJECTS		         #
# ###################################### #

OBJS_ARRAY		=	$(addprefix $(OBJ_ARRAY_PATH), 		\
					$(SRC_ARRAY_FILES:.c=.o))

OBJS_CHECK		=	$(addprefix $(OBJ_CHECK_PATH), 		\
					$(SRC_CHECK_FILES:.c=.o))

OBJS_CONVERT	=	$(addprefix $(OBJ_CONVERT_PATH), 	\
					$(SRC_CONVERT_FILES:.c=.o))

OBJS_DISPLAY	=	$(addprefix $(OBJ_DISPLAY_PATH), 	\
					$(SRC_DISPLAY_FILES:.c=.o))

OBJS_FILE		=	$(addprefix $(OBJ_FILE_PATH), 		\
					$(SRC_FILE_FILES:.c=.o))
					
OBJS_LIST		=	$(addprefix $(OBJ_LIST_PATH), 		\
					$(SRC_LIST_FILES:.c=.o))

OBJS_MEMORY		=	$(addprefix $(OBJ_MEMORY_PATH), 	\
					$(SRC_MEMORY_FILES:.c=.o))
					
OBJS_PRINTF		=	$(addprefix $(OBJ_PRINTF_PATH), 	\
					$(SRC_PRINTF_FILES:.c=.o))

OBJS_STRING		=	$(addprefix $(OBJ_STRING_PATH), 		\
					$(SRC_STRING_FILES:.c=.o))

OBJS	=	$(OBJS_ARRAY)													\
			$(OBJS_CHECK)	$(OBJS_CONVERT)	$(OBJS_DISPLAY)	$(OBJS_FILE)	\
			$(OBJS_LIST)	$(OBJS_MEMORY)	$(OBJS_PRINTF)	$(OBJS_STRING)


# ###################################### #
#               OBJ BUILD		         #
# ###################################### #

$(OBJ_ARRAY_PATH)%.o: 	$(SRC_ARRAY_PATH)%.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_CHECK_PATH)%.o: 	$(SRC_CHECK_PATH)%.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_CONVERT_PATH)%.o: $(SRC_CONVERT_PATH)%.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DISPLAY_PATH)%.o: $(SRC_DISPLAY_PATH)%.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_FILE_PATH)%.o: 	$(SRC_FILE_PATH)%.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_LIST_PATH)%.o: 	$(SRC_LIST_PATH)%.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_MEMORY_PATH)%.o: 	$(SRC_MEMORY_PATH)%.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(OBJ_PRINTF_PATH)%.o: 	$(SRC_PRINTF_PATH)%.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_STRING_PATH)%.o: 	$(SRC_STRING_PATH)%.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<


# ###################################### #
#                 RULES			         #
# ###################################### #

all: 		$(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): 	$(OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: 	
			$(MAKE) clean
			$(RM) $(NAME)
			$(RM) $(OBJS_DIR)

re:			
			$(MAKE) fclean
			$(MAKE) all

.PHONY: 	all clean fclean re