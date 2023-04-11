/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:18:27 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/03/13 19:24:23 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/project_gen.h"

void	ft_write_char(int fd, char c, int nb)
{
	for (int i = 0; i < nb; i++)
		write(fd, &c, 1);
}

void	write_str(int fd, char *str)
{
	int	len;

	len = strlen(str);
	for (int i = 0; i < len; i++)
		write(fd, &str[i], 1);
}

void	generate_title(int fd, char *title)
{
	int	size_margin;
	int	len_title;

	len_title = strlen(title);
	size_margin = (40 - strlen(title)) / 2;

	// line 1
	write_str(fd, "# ");
	if (len_title % 2 != 0)
		ft_write_char(fd, '#', 37);
	else
		ft_write_char(fd, '#', 38);
	write_str(fd, " #\n");
	
	// line 2
	write_str(fd, "#");
	ft_write_char(fd, ' ', size_margin);
	write_str(fd, title);
	ft_write_char(fd, ' ', size_margin);
	write_str(fd, "#\n");

	// line 3
	write_str(fd, "# ");
	if (len_title % 2 != 0)
		ft_write_char(fd, '#', 37);
	else
		ft_write_char(fd, '#', 38);
	write_str(fd, " #\n\n");
}

void	generate_variables(int fd, t_file *project)
{
	write_str(fd, "NAME		=	");
	write_str(fd, project->name);
	ft_write_char(fd, '\n', 2);

	write_str(fd, "UNAME		=	$(shell uname)\n\nNOCOLOR		=	\
\\033[0m\nBGREEN		=	\\033[1;32m\n\n");

	write_str(fd, "HEADER		=	");
	if (project->use_struct)
		write_str(fd, "includes/");
	write_str(fd, project->name);
	write_str(fd, ".h\n\n");

	write_str(fd, "MAKEFILE	=	Makefile\n\n");

	if (project->is_libft)
	{
		if (project->use_struct)
			write_str(fd, "LIBFT_DIR	=	includes/libft/\nLIBFT_A		=	\
$(LIBFT_DIR)libft.a\n\n");
		else
			write_str(fd, "LIBFT_DIR	=	libft/\nLIBFT_A		=	\
$(LIBFT_DIR)libft.a\n\n");

	}
	
	write_str(fd, "CFLAGS 		= 	-Wall -Wextra -Werror\n\n\
RM 			= 	rm -rf\n\nAR 			= 	ar\n\n\
ARFLAGS 	= 	-rcs\n\n\n");
}

char	*ft_strtoupper(char *str)
{
	char	*new_str;
	int		i;
	int		len;

	len = strlen(str);
	new_str = calloc(len, sizeof(char));
	i = -1;
	while (++i < len)
		new_str[i] = ft_toupper(str[i]);
	return (new_str);
}

void	generate_paths(int fd, t_file *project)
{
	if (project->use_struct && project->is_folder)
	{
		write_str(fd, "SRCS_PATH	=	sources/\n\n");

		// write source path
		int	i = -1;
		while (++i < project->nb_folder)
		{
			write_str(fd, "SRC_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_PATH		=	$(SRCS_PATH)");
			write_str(fd, project->folders[i]);
			write_str(fd, "/\n");
		}
		write_str(fd, "\n");

		// write obj path
		i = -1;
		while (++i < project->nb_folder)
		{
			write_str(fd, "OBJ_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_PATH		=	$(SRC_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_PATH).objs/\n");
		}
		write_str(fd, "\n");

		// write obj dirs
		i = -1;
		write_str(fd, "OBJS_DIRS	=	");
		while (++i < project->nb_folder)
		{
			write_str(fd, "$(OBJ_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_PATH) ");
		}
		write_str(fd, "\n\n\n");
	}
	else if (project->use_struct && !project->is_folder)
		write_str(fd, "SRCS_PATH	=	sources/\n\nOBJS_DIRS	=	$(SRCS_PATH).objs/\n\n\n");
	else if (!project->use_struct && !project->is_folder)
		write_str(fd, "OBJS_DIRS	=	.objs/\n\n\n");
	else if (!project->use_struct && project->is_folder)
	{
		// write source path
		int	i = -1;
		while (++i < project->nb_folder)
		{
			write_str(fd, "SRC_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_PATH		=	");
			write_str(fd, project->folders[i]);
			write_str(fd, "/\n");
		}
		write_str(fd, "\n");

		// write obj path
		i = -1;
		while (++i < project->nb_folder)
		{
			write_str(fd, "OBJ_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_PATH		=	$(SRC_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_PATH).objs/\n");
		}
		write_str(fd, "\n");

		// write obj dirs
		i = -1;
		write_str(fd, "OBJS_DIRS	=	");
		while (++i < project->nb_folder)
		{
			write_str(fd, "$(OBJ_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_PATH) ");
		}
		write_str(fd, "\n\n\n");
	}
}

void	generate_sources(int fd, t_file *project)
{
	int		i;
	int		j;

	if (project->is_folder)
	{
		// write source path
		i = -1;
		while (++i < project->nb_folder)
		{
			write_str(fd, "SRC_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_FILES		=	");
			j = -1;
			while (project->c_file[i][++j][0])
			{
				write_str(fd, project->c_file[i][j]);
				write_str(fd, "	");
			}
			write_str(fd, "\n\n");
		}

		// write obj path
		i = -1;
		while (++i < project->nb_folder)
		{
			write_str(fd, "SRCS_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "		=	$(addprefix $(SRC_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_PATH), $(SRC_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_FILES))\n");
		}
		write_str(fd, "\n");

		// write obj dirs
		i = -1;
		write_str(fd, "SRCS	=	");
		while (++i < project->nb_folder)
		{
			write_str(fd, "$(SRCS_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, ") ");
		}
		write_str(fd, "\n\n\n");
	}
	else
	{
		if (project->use_struct)
		{
			// write source path
			j = -1;
			write_str(fd, "SRC_FILES	=	");
			while (project->c_file[0][++j][0])
			{
				write_str(fd, project->c_file[0][j]);
				write_str(fd, "	");
			}
			write_str(fd, "\n\nSRCS	=	$(addprefix $(SRCS_PATH), $(SRC_FILES))\n\n\n");
		}
		else if (!project->use_struct)
		{
			// write source path
			j = -1;
			write_str(fd, "SRCS	=	");
			while (project->c_file[0][++j][0])
			{
				write_str(fd, project->c_file[0][j]);
				write_str(fd, "	");
			}
			write_str(fd, "\n\n\n");
		}
	}
}

void	generate_objects(int fd, t_file *project)
{
	int		i;

	if (project->is_folder)
	{
		// write objects path
		i = -1;
		while (++i < project->nb_folder)
		{
			write_str(fd, "OBJS_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "		=	$(addprefix $(OBJ_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_PATH),		\\\n						$(SRC_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_FILES:.c=.o))\n");
		}
		write_str(fd, "\n");

		// write obj files
		i = -1;
		write_str(fd, "OBJS	=	");
		while (++i < project->nb_folder)
		{
			write_str(fd, "$(OBJS_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, ")	");
		}
		write_str(fd, "\n\n");

		// write obj path
		i = -1;
		while (++i < project->nb_folder)
		{
			write_str(fd, "$(OBJ_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_PATH)\%.o: $(SRC_");
			write_str(fd, ft_strtoupper(project->folders[i]));
			write_str(fd, "_PATH)\%.c $(MAKEFILE) $(HEADER)\n");
			write_str(fd, "	$(CC) $(CFLAGS) -o $@ -c $<\n\n");
		}
		write_str(fd, "\n");
	}
	else
	{
		if (project->use_struct)
			write_str(fd, "OBJS	=	$(addprefix $(OBJS_DIRS),	\\\n\
								$(SRC_FILES:.c=.o))\n\n");
		else
			write_str(fd, "OBJS	=	$(addprefix $(OBJS_DIRS),	\\\n\
								$(SRCS:.c=.o))\n\n");

		write_str(fd, "$(OBJS_DIRS)\%.o: $(SRCS_PATH)\%.c $(MAKEFILE) $(HEADER)\n");
		write_str(fd, "	$(CC) $(CFLAGS) -o $@ -c $<\n\n\n");
	}

}

void	generate_rules(int fd, t_file *project)
{
	write_str(fd, "all:		");
	if (project->is_libft)
		write_str(fd, "make_libft ");

	write_str(fd, "$(OBJS_DIRS) $(NAME)\n\n");

	if (project->is_libft)
	{
		write_str(fd, "make_libft:\n			$(MAKE) -C $(LIBFT_DIR)\n\n");
		write_str(fd, "$(LIBFT_A):\n			$(MAKE) make_libft\n\n");
	}
	write_str(fd, "$(OBJS_DIRS):\n			mkdir -p $(OBJS_DIRS)\n\n");

	// NAME
	write_str(fd, "$(NAME):	");
	if (project->is_libft)
		write_str(fd, "$(LIBFT_A) ");
	write_str(fd, "$(OBJS)\n");

	// ##### linux or mac compilation #####
	write_str(fd, "ifeq ($(UNAME),Linux)\n");
	if (project->is_libft)
	{
		write_str(fd, "	$(AR) $(ARFLAGS) $(LIBFT_A) $(OBJS)\n");
		write_str(fd, "	$(CC) $(CFLAGS) -o $(NAME) ");
	}
	else
		write_str(fd, "	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)");
	if (project->is_libft)
		write_str(fd, "$(LIBFT_A) ");
	write_str(fd, "\n");
	write_str(fd, "	@echo \"$(BGREEN)Linux Compilation Done$(NOCOLOR)\"\n");
	write_str(fd, "else ifeq ($(UNAME),Darwin)\n");
	write_str(fd, "	$(CC) $(CFLAGS) -o $(NAME) ");
	if (project->is_libft)
		write_str(fd, "$(LIBFT_A) ");
	write_str(fd, "$(OBJS)\n");
	write_str(fd, "	@echo \"$(BGREEN)Mac OS Compilation Done$(NOCOLOR)\"\n");
	write_str(fd, "endif\n\n");

	// CLEAN
	write_str(fd, "clean:\n");
	if (project->is_libft)
		write_str(fd, "			$(MAKE) clean -C $(LIBFT_DIR)\n");
	write_str(fd, "			$(RM) $(OBJS)\n\n");

	// FCLEAN
	write_str(fd, "fclean:\n");
	if (project->is_libft)
		write_str(fd, "			$(MAKE) fclean -C $(LIBFT_DIR)\n");
	write_str(fd, "			$(MAKE) clean\n");
	write_str(fd, "			$(RM) $(NAME)\n");
	write_str(fd, "			$(RM) $(OBJS_DIRS)\n\n");

	// RE
	write_str(fd, "re:\n");
	write_str(fd, "			$(MAKE) fclean\n");
	write_str(fd, "			$(MAKE) all\n\n");

	// .PHONY
	write_str(fd, ".PHONY:		all clean fclean re ");
	if (project->is_libft)
		write_str(fd, "make_libft\n");
}

void	generate_makefile(t_file *project)
{
	int		fd_makefile;
	char	*path_makefile;

	path_makefile = ft_strjoin(project->pwd_path, "/Makefile");
	fd_makefile = open(path_makefile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	generate_header(fd_makefile, "Makefile", 0);

	generate_title(fd_makefile, "VARIABLES");
	generate_variables(fd_makefile, project);

	generate_title(fd_makefile, "PATHS");
	generate_paths(fd_makefile, project);

	generate_title(fd_makefile, "SOURCES");
	generate_sources(fd_makefile, project);

	generate_title(fd_makefile, "OBJECTS");
	generate_objects(fd_makefile, project);

	generate_title(fd_makefile, "RULES");
	generate_rules(fd_makefile, project);
	close(fd_makefile);
}

void	execute_cmd(char *cmd_path, char **arr_args, char **envp)
{
	pid_t	pid = fork();

	if (pid == 0)
		execve(cmd_path, arr_args, envp);
	else
		wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_file	project;

	(void)argc;
	(void)argv;

	project.folders[0][0] = '\0';
	project.c_file[0][0][0] = '\0';
	if (!get_user_input(&project))
		return (-1);		// free all
	project.pwd_path = ft_strjoin(ft_strjoin(getenv("PWD"), "/"), project.name);
	generate_folder(&project, envp);
	generate_makefile(&project);
	generate_file(&project);
	return (0);
}
