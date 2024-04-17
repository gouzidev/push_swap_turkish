/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:26:52 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/17 18:34:51 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	we_have_a_problem(int fd, char **str)
{
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		if (str)
		{
			free(*str);
			*str = NULL;
		}
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	char		*buff;
	int			bytes;

	if (we_have_a_problem(fd, &str))
		return (NULL);
	buff = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buff), NULL);
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	if (!str)
		return (free(str), NULL);
	line = ft_get_line(str);
	str = get_rest(str);
	return (line);
}
