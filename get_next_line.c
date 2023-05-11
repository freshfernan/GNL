/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:22:10 by fefernan          #+#    #+#             */
/*   Updated: 2022/10/13 13:26:40 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int			fd;
	int			j;
	char		*line;

	j = 0;
	fd = open("sinpuntotxt", O_RDONLY);
	line = "1";
	while (line != NULL)
	{
		j++;
		line = get_next_line (fd);
		printf("\n---------%d-----------\n", j);
		printf ("\n*-*-*-:  *-%s-*\n", line);
	}
	return (0);
}

/*int main(void)
{
	int			j;
	char		*line;

    j = 0;
	line = "1";
	while (line != NULL)
	{
		j++;
		line = get_next_line (0);
		printf("\n---------%d-----------\n", j);
		printf ("\n*-*-*-:  *-%s-*\n", line);
	}
    return 0;
}*/

char	*get_next_line(int fd)
{
	char	*str[OPEN_MAX];
	int		n;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	str[fd] = NULL;
	n = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
	if (n > 0)
		str[fd] = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	while (n > 0 && buffer[0] != '\n')
	{
		str[fd] = ft_strjoin(str[fd], buffer);
		n = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
	}
	if (buffer[0] == '\n')
		str[fd] = ft_strjoin (str[fd], "\n");
	free(buffer);
	return (str[fd]);
}
