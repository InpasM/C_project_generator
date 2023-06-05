/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_database.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:10:12 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/06/05 20:56:50 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/project_gen.h"

char	*rm_last_file(char *path)
{
	int		i = -1;
	int		count = 0;
	int		tmp_count = 0;
	char	*new_path;

	while (path[++i])
		if (path[i] == '/')
			count++;
	i = -1;
	while (path[++i])
	{
		if (path[i] == '/')
			tmp_count++;
		if (tmp_count == count)
			break ;
	}
	new_path = ft_calloc(i + 1, sizeof(char));
	if (!new_path)
		return (NULL);
	int	j = -1;
	while (++j < i + 1)
		new_path[j] = path[j];
	return (new_path);
}


int	is_lib_valid(char **tmp_lib)
{
	char	**tmp_category;
	int		j = -1;

	while (tmp_lib[++j])
	{
		tmp_category = ft_split(tmp_lib[j], '=');
		if (!(ft_strmatch(tmp_category[0], "name") || ft_strmatch(tmp_category[0], "git") \
			|| ft_strmatch(tmp_category[0], "flags") || ft_strmatch(tmp_category[0], "path")) \
			|| !tmp_category[1])
				return (0);
	}
	return (1);
}

int	count_lib(char	**all_lib)
{
	char	**tmp_lib;
	int		i = -1;
	int		count = 0;

	while (all_lib[++i])
	{
		tmp_lib = ft_split(all_lib[i], ',');
		if (is_lib_valid(tmp_lib))
			count++;
	}
	return (count);
}

int	reading_database(t_file *project)
{
	char	**tmp_split;
	char	**tmp_lib;
	char	**tmp_category;
	(void)tmp_category;
	(void)tmp_lib;

	tmp_split = ft_split(project->db->file, '\n');
	project->db->nb_lib = count_lib(tmp_split);
	// printf("count valid lib %d\n", project->db->nb_lib);
	project->db->lib = ft_calloc(project->db->nb_lib + 1, sizeof(t_lib *));
	if (!project->db->lib)
		return (-1);
	int	i = -1;
	int	k = 0;
	while (tmp_split[++i])
	{
		tmp_lib = ft_split(tmp_split[i], ',');
		project->db->lib[i] = ft_calloc(ft_arrlen(tmp_lib) + 1, sizeof(t_lib *));
		if (!project->db->lib[i])
			return (-1);
		int	j = -1;
		while (tmp_lib[++j])
		{
			tmp_category = ft_split(tmp_lib[j], '=');
			// if (is_lib_valid(tmp_category[0], tmp_category[1]))
			if ((ft_strmatch(tmp_category[0], "name") || ft_strmatch(tmp_category[0], "git") \
			|| ft_strmatch(tmp_category[0], "flags") || ft_strmatch(tmp_category[0], "path")) \
			&& tmp_category[1])
			{
				project->db->lib[i][k] = ft_calloc(3, sizeof(t_lib));
				project->db->lib[i][k]->name = ft_strdup_null(tmp_category[0]);
				project->db->lib[i][k]->value = ft_strdup_null(tmp_category[1]);
				project->db->lib[i][k]->to_add = 0;
				k++;
			}
			// else
			// 	project->db->lib[i][j]->to_add = -1;
		}
		// ft_arrfree(tmp_lib);
	}
	ft_arrfree(tmp_split);
	return (0);
}

int	parsing_database(t_file *project, char **argv, char **envp)
{
	char	*path_data;
	char	*path_datafile;
	char	**args_tmp;
	char	*args_mkdir[] = {"/usr/bin/mkdir", "-p", NULL};

	project->db = malloc(sizeof(t_db));
	if (!project->db)
		return (-1);
	project->db->add_db = 0;
	project->db->nb_lib = 0;
	path_data = ft_strjoin(rm_last_file(argv[0]), "database/");
	path_datafile = ft_strjoin(path_data, "database");
	if (access(path_data, F_OK) != 0)
	{
		args_tmp = ft_arradd_back(args_mkdir, path_data);
		execute_cmd(args_tmp[0], args_tmp, envp);
		project->db->fd_db = open(path_datafile, O_CREAT, 0644);
	}
	else if (access(path_datafile, F_OK) != 0)
		project->db->fd_db = open(path_datafile, O_CREAT, 0644);
	project->db->fd_db = open(path_datafile, O_RDONLY);
	if (project->db->fd_db == -1)
		return (ft_putstr_fd("database file unreadable\n", 2), -1);
	close(project->db->fd_db);
	project->db->fd_db = open(path_datafile, O_RDWR | O_APPEND, 0644);
	if (project->db->fd_db == -1)
		return (ft_putstr_fd("database file unwritable\n", 2), -1);
	project->db->file = get_file(project->db->fd_db);
	reading_database(project);
	// if (!is_database_valid(project))
	// 	return (-1);
	return (0);
}
