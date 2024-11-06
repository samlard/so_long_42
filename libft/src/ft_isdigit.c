/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:16:11 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/20 22:38:06 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char			c;
	char			i;
	unsigned char	b;
	int				j;

	c = 'a';
	i = '2';
	b = '9';
	j = '1';
	printf("%d\n", ft_isdigit(c));
	printf("%d\n", ft_isdigit(i));
	printf("%d\n", ft_isdigit(b));
	printf("%d\n", ft_isdigit(j));
}
*/
