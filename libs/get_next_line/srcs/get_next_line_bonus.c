/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:11:39 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/31 17:39:18 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;
	char		*new_save;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(save[fd]), save[fd] = NULL, NULL);
	new_save = read_line(fd, save[fd]);
	if (!new_save)
		return (free(save[fd]), save[fd] = NULL, NULL);
	save[fd] = new_save;
	line = ft_get_line(save[fd]);
	if (!line)
		return (free(save[fd]), save[fd] = NULL, NULL);
	save[fd] = save_next_line(save[fd]);
	return (line);
}

char	*read_line(int fd, char *save)
{
	char	*res;
	char	*tmp;
	int		read_status;

	if (!save)
		save = ft_strdup("");
	res = malloc(BUFFER_SIZE + 1);
	if (!res || !save)
		return (free(res), free(save), NULL);
	read_status = 1;
	while (read_status > 0 && !ft_strchr(save, '\n'))
	{
		read_status = read(fd, res, BUFFER_SIZE);
		if (read_status == -1)
			return (free(res), free(save), NULL);
		res[read_status] = '\0';
		tmp = ft_strjoin(save, res);
		if (!tmp)
			return (free(res), free(save), NULL);
		free(save);
		save = tmp;
	}
	return (free(res), save);
}

char	*ft_get_line(char *save)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!save || !*save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	ft_memcpy(line, save, i);
	if (save[i] == '\n')
	{
		line[i++] = '\n';
	}
	line[i] = '\0';
	return (line);
}

char	*save_next_line(char *save)
{
	size_t	i;
	size_t	j;
	char	*next;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (free(save), NULL);
	next = malloc(ft_strlen(save) - i);
	if (!next)
		return (free(save), NULL);
	i++;
	while (save[i])
		next[j++] = save[i++];
	next[j] = '\0';
	return (free(save), next);
}
