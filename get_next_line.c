/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:07:12 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/06 20:24:28 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	until_eol(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buffer; // Va avoir BUFFER_SIZE de char
	static char	*restant; // Va etre utilise quand on rappel la fonction
	char		*line; // String du debut de la ligne jusqu'au \n qui va etre return !!

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ((char *) malloc((BUFFER_SIZE + 1) * sizeof(char)));
	if (!buffer)
		return (NULL);
	buffer = read(fd, buffer, BUFFER_SIZE);
	if (!restant)
		return (first_line(buffer));
	restant = malloc(sizeof(char) * until_eol(buffer) + 1);
}

char	*first_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(sizeof(char) * until_eol(str) + 1);
	while (i <= until_eol(str))
	{
		line[i] = str[i];
		i++;
	}
	return (line);
}

// int	main(void)
// {
// 	int fd = open ("test", O_RDONLY);
// 	get_next_line(fd);
// }

int	main(void)
{
	int		i = 0;
	int		fd = open("test", O_RDONLY);
	char	*str;
	
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		i++;
		free(str);
	}
}
