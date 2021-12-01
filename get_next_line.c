/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:39:23 by ngobert           #+#    #+#             */
/*   Updated: 2021/12/01 16:25:59 by ngobert          ###   ########.fr       */
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
	// static char	*statique = NULL;	// Va etre utilise quand on rappel la fonction
	//char		*line;				// String du debut de la ligne jusqu'au \n qui va etre return !!
	size_t			ret_val;			// Pour la return value du read

	ret_val = 1;
	if (fd < 0 || BUFFER_SIZE <= 0) // Check si fd et buffer_size sont bon
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // Malloc un buffer
	if (!buffer)
		return (NULL);
	ret_val = read(fd, buffer, BUFFER_SIZE);
	printf("%zu", ret_val);
	// while (check_eol(buffer) && ret_val != 0) // tant que ya pas de \n
	// {
	// 	ret_val = read(fd, buffer, BUFFER_SIZE);
	// 	printf("%zu", ret_val);
	// 	buffer[ret_val] = '\0';
	// 	if (ret_val == 0)
	// 		return ("bite");
	// }
	char *dest;
	char hihi[] = "caca";
	dest = malloc(sizeof(char) * ft_strlen(hihi));
	return (dest);
}

int	main(void)
{
	int		i = 0;
	int		fd = open("test", O_RDONLY);
	char	*str;
	
	// while ((str = get_next_line(fd)) != NULL)
	// {
		str = get_next_line(fd); // a enlever
		printf("%s", str);
		i++;
		free(str);
	// }
}
