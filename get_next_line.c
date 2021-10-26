/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:07:12 by ngobert           #+#    #+#             */
/*   Updated: 2021/10/26 22:34:16 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


//char	*get_next_line(int fd)
//{
//	
//}

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		write(1, str, 1);
		i++;
	}
}

int	main(void)
{
	int	fd;
	int	ret;
	char	buf[4096 + 1];
	
	ret = read(42, buf, 4096);
	buf[ret] = '\0';
	printf("%s", ret);
}