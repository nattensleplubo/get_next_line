/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:07:12 by ngobert           #+#    #+#             */
/*   Updated: 2021/10/30 18:20:03 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	fd = open("42", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return ("raté");
	printf("%d\n", fd);
	write(3, "caca\ngetnextline\nvivelecovid", 28);

	return ("covide");
}

int	main(void)
{
	get_next_line(1);
}
