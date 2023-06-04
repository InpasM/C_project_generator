/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 09:33:34 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/06/02 14:35:32 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/project_gen.h"

static void	create_project_h(t_file *project)
{
	char	*tmp_path;
	char	*h_name;
	int		tmp_filefd;

	if (project->use_struct)
		tmp_path = ft_strjoin(ft_strjoin(ft_strjoin(project->pwd_path, "/includes/"), project->name), ".h");
	else
		tmp_path = ft_strjoin(ft_strjoin(ft_strjoin(project->pwd_path, "/"), project->name), ".h");
	tmp_filefd = open(tmp_path, O_RDWR | O_CREAT | O_TRUNC, 0644);

	// write text into the file.h
	generate_header(tmp_filefd, ft_strjoin(project->name, ".h"), 1);
	h_name = ft_strjoin(ft_strtoupper(project->name), "_H");
	write_str(tmp_filefd, "#ifndef ");
	write_str(tmp_filefd, h_name);
	write_str(tmp_filefd, "\n# define ");
	write_str(tmp_filefd, h_name);
	write_str(tmp_filefd, "\n");
	if (project->is_libft)
	{
		if (project->use_struct)
			write_str(tmp_filefd, "# include \"libft/includes/libft.h\"");
		else
			write_str(tmp_filefd, "# include \"libft/libft.h\"");
	}
	write_str(tmp_filefd, "\n#endif");
	close (tmp_filefd);
	free(tmp_path);
}

void	create_file_c(t_file *project, int i)
{
	char	*tmp_path;
	int		tmp_filefd;
	int		j;

	j = -1;
	while (project->c_file[i][++j][0])
	{
		if (project->use_struct && project->is_folder)
			tmp_path = ft_strjoin(ft_strjoin(ft_strjoin(ft_strjoin(project->pwd_path, "/sources/"), project->folders[i]), "/"), project->c_file[i][j]);
		else if (project->use_struct && !project->is_folder)
			tmp_path = ft_strjoin(ft_strjoin(project->pwd_path, "/sources/"), project->c_file[i][j]);
		else if (!project->use_struct && project->is_folder)
			tmp_path = ft_strjoin(ft_strjoin(ft_strjoin(ft_strjoin(project->pwd_path, "/"), project->folders[i]), "/"), project->c_file[i][j]);
		else if (!project->use_struct && !project->is_folder)
			tmp_path = ft_strjoin(ft_strjoin(project->pwd_path, "/"), project->c_file[i][j]);
		tmp_filefd = open(tmp_path, O_RDWR | O_CREAT, 0644);

		// write text into the file.h
		generate_header(tmp_filefd, project->c_file[i][j], 1);
		if (project->use_struct && project->is_folder)
			write_str(tmp_filefd, "#include \"../../includes/");
		else if (project->use_struct && !project->is_folder)
			write_str(tmp_filefd, "#include \"../includes/");
		else if (!project->use_struct && project->is_folder)
			write_str(tmp_filefd, "#include \"../");
		else if (!project->use_struct && !project->is_folder)
			write_str(tmp_filefd, "#include \"");
		write_str(tmp_filefd, project->name);
		write_str(tmp_filefd, ".h\"\n");
		if (i == 0 && j == 0)
			write_str(tmp_filefd, "\nint	main()\n{\n	return (0);\n}\n");
		close (tmp_filefd);
	}
}

void	generate_file(t_file *project)
{
	int		i;

	create_project_h(project);

	if (project->use_struct && project->is_folder)
	{
		i = -1;
		while (project->folders[++i][0])
			create_file_c(project, i);
	}
	else if (!project->use_struct && project->is_folder)
	{
		i = -1;
		while (project->folders[++i][0])
			create_file_c(project, i);
	}
	else if (project->use_struct && !project->is_folder)
		create_file_c(project, 0);
	else if (!project->use_struct && !project->is_folder)
		create_file_c(project, 0);
}

void	generate_folder(t_file *project, char **envp)
{
	char	**args_tmp;
	char	*args_mkdir[] = {"/usr/bin/mkdir", "-p", NULL};
	char	*args_gcl[] = {"/usr/bin/git", "clone", "https://github.com/InpasM/libft.git", NULL};
	
	// mkdir main project directory`
	args_tmp = ft_arradd_back(args_mkdir, project->pwd_path);
	execute_cmd(args_tmp[0], args_tmp, envp);
	if (project->use_struct)
	{
		// mkdir includes
		args_tmp = ft_arradd_back(args_mkdir, ft_strjoin(project->pwd_path, "/includes/"));
		execute_cmd(args_tmp[0], args_tmp, envp);

		// mkdir sources
		args_tmp = ft_arradd_back(args_mkdir, ft_strjoin(project->pwd_path, "/sources/"));
		execute_cmd(args_tmp[0], args_tmp, envp);

		// git clone libft
		if (project->is_libft)
		{
			args_tmp = ft_arradd_back(args_gcl, ft_strjoin(project->pwd_path, "/includes/libft"));
			execute_cmd(args_tmp[0], args_tmp, envp);
		}
		if (project->is_folder)
		{
			for (int i = 0; project->folders[i][0]; i++)
			{
				args_tmp = ft_arradd_back(args_mkdir, ft_strjoin(ft_strjoin(project->pwd_path, "/sources/"), project->folders[i]));
				execute_cmd(args_tmp[0], args_tmp, envp);
			}
		}
	}
	else
	{
		if (project->is_libft)
		{
			args_tmp = ft_arradd_back(args_gcl, ft_strjoin(project->pwd_path, "/libft"));
			execute_cmd(args_tmp[0], args_tmp, envp);
		}
		if (project->is_folder)
		{
			for (int i = 0; project->folders[i][0]; i++)
			{
				args_tmp = ft_arradd_back(args_mkdir, ft_strjoin(ft_strjoin(project->pwd_path, "/"), project->folders[i]));
				execute_cmd(args_tmp[0], args_tmp, envp);
			}
		}
	}
}
