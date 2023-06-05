/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_gen.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:24:49 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/06/05 18:21:32 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_GEN_H
# define PROJECT_GEN_H
# include "libft/includes/libft.h"
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <time.h>

//Regular text
# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

//Regular bold text
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

# define NOCOLOR "\e[0m"

# define C 1
# define CPP 2

typedef struct s_lib
{
	char	*name;
	char	*value;
	int		to_add;
}			t_lib;

typedef struct s_db
{
	int		add_db;
	int		fd_db;
	int		nb_lib;
	char	*file;
	// char	***lib;
	t_lib	***lib;
	// t_lib	***new_lib;
}			t_db;

typedef struct s_file
{
	char	name[98];
	char	h_file[100];
	char	header[900];
	int		type_project;
	int		is_libft;
	int		is_folder;
	int		use_struct;
	int		nb_folder;
	char	folders[20][50];
	char	c_file[20][50][20];
	char	*pwd_path;
	t_db	*db;
}			t_file;

void	add_element(int *is_elem, char *question);
void	execute_cmd(char *cmd_path, char **arr_args, char **envp);
void	generate_header(int fd, char *file_name, int version);
void	generate_file(t_file *project);
void	generate_folder(t_file *project, char **envp);
void	ft_write_char(int fd, char c, int nb);
void	write_str(int fd, char *str);

int		get_user_input(t_file *project, char **argv, char **envp);
int		parsing_database(t_file *project, char **argv, char **envp);

char	*ft_strtoupper(char *str);

#endif