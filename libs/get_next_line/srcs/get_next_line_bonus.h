/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:33:02 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/31 17:40:13 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# elif BUFFER_SIZE <= 0 || BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define OPEN_MAX 10240

char	*get_next_line(int fd);
char	*read_line(int fd, char *save);
char	*ft_get_line(char *save);
char	*save_next_line(char *save);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);

#endif // GET_NEXT_LINE_BONUS_H
