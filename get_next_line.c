/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:39:23 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/30 16:11:08 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	check_eol(char *statique)
{
	int	i;

	i = 0;
	if (!statique)
		return (0);
	while (statique[i])
	{
		if (statique[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer;			// Va avoir un BUFFER_SIZE de char
	static char	*statique = NULL;	// Va etre utilise quand on rappel la fonction
	char		*line;				// String du debut de la ligne jusqu'au \n qui va etre return !!
	int			ret_val;			// Pour la return value du read

	ret_val = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (check_eol(statique) && ret_val != 0)
	{
		ret_val = read(fd, buffer, BUFFER_SIZE);
		if (ret_val == -1)
			return (ft_free(buffer));
		buffer[ret_val] = '\0';
		statique[fd] = ft_strjoin(statique[fd], buffer);
	}
	return (line);
}

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
