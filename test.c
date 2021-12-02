/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:58:14 by ngobert           #+#    #+#             */
/*   Updated: 2021/12/02 11:17:14 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_returnline(char	*statique)
{
	int		i;
	char	*returnline;
	
	i = 0;
	if (!statique)
		return (NULL);
	while (statique[i] && statique[i] != '\n')
		i++;
	returnline = malloc(sizeof(char) * (i + 1));
	if (!returnline)
		return (NULL);
	i = 0;
	while (statique[i] && statique[i] != '\n')
	{
		returnline[i] = statique[i];
		i++;
	}
	if (statique[i] == '\n')
	{
		returnline[i] = statique[i];
		i++;
	}
	returnline[i] = '\0';
	return (returnline);
}