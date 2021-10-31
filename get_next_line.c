/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:07:12 by ngobert           #+#    #+#             */
/*   Updated: 2021/10/31 16:25:32 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	i;
	static char *gnl[BUFFER_SIZE + 2];

	i = 0;
	read(fd, gnl, BUFFER_SIZE);
	while (i <= BUFFER_SIZE)
	{
		if (gnl[i] == '\0')
			return (gnl);
		i++;
	}
	return (gnl);
}

int	main(void)
{
	int i = 0;
	int fd = open("test", O_RDONLY);
	char *str;
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		i++;
		free(str);
	}
}
