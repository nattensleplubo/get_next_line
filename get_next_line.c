/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:07:12 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/03 18:35:44 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	until_eol(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*restant;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ((char *) malloc((BUFFER_SIZE + 1) * sizeof(char))); // fou le int de malloc dans une char ?
	if (!buffer)
		return (NULL);
	
}

int	main(void)
{
	int fd = open ("test", O_RDONLY);
	get_next_line(fd);
}

// int	main(void)
// {
// 	int		i = 0;
// 	int		fd = open("test", O_RDONLY);
// 	char	*str;
	
// 	while ((str = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", str);
// 		i++;
// 		free(str);
// 	}
// }
