/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:16:04 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/12 14:51:19 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static char	*remove_line_break(char *line)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (ft_substr(line, 0, len));
}

static bool	append_line(t_list **list, char *line)
{
	t_list	*new_node;

	new_node = ft_lstnew(line);
	if (!new_node)
		return (false);
	ft_lstadd_back(list, new_node);
	return (true);
}

static char	**list_to_array(t_list *list, int height)
{
	char	**arr;
	int		i;

	arr = malloc(sizeof(char *) * (height + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < height)
	{
		arr[i] = list->content;
		list = list->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

static char	**cleanup(t_list **list, char *tmp)
{
	if (tmp)
		free(tmp);
	if (list)
		ft_lstclear(list, free);
	return (NULL);
}

char	**read_file(int fd)
{
	t_list	*list;
	char	*line;
	char	*tmp;
	char	**lines;
	int		height;

	list = NULL;
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = remove_line_break(line);
		free(line);
		if (!tmp || !append_line(&list, tmp))
			return (cleanup(&list, tmp));
		height++;
	}
	lines = list_to_array(list, height);
	if (!lines)
		return (cleanup(&list, NULL));
	ft_lstclear(&list, ft_noop);
	return (lines);
}
