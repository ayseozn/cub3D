/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:23:59 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/28 00:24:00 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	str1;
	unsigned char	str2;

	while (*s1 || *s2)
	{
		str1 = (unsigned char)*s1++;
		str2 = (unsigned char)*s2++;
		if (str1 != str2)
			return (str1 - str2);
	}
	return (0);
}
