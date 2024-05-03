/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:21:20 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/28 00:23:17 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	texture_line(char *str, char *find)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == find[0] && str[i + 1] == find[1])
		{
			i += 2;
			while (str[i] <= 32 && str[i] != '\n')
				i++;
			return (i);
		}
		i++;
	}
	return (0);
}

char	*ft_strdup2(char *s1, char *find)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	i = texture_line(s1, find);
	j = 0;
	while (s1[i] != '\n' && s1[i])
	{
		ptr[j] = s1[i];
		i++;
		j++;
	}
	ptr[j] = 0;
	return (ptr);
}
