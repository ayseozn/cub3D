/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:23:54 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/28 00:23:55 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	c;

	c = 0;
	while (src[c] != '\n')
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = '\n';
	dest[c + 1] = '\0';
	return (dest);
}
