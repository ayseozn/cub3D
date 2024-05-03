/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:57:24 by aysozen           #+#    #+#             */
/*   Updated: 2024/03/28 05:56:48 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] <= 32 || (str[i] >= '0' && str[i] <= '9')))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	res;

	i = 0;
	s = 1;
	res = 0;
	while ((str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		&& str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9') || check_str(str))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * s);
}
/*
#include <stdio.h>

int main()
{
	char *str = " -123";
	printf("%d\n",ft_atoi(str));
	printf("%d\n", atoi(str));
}
*/
