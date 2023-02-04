/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:00:30 by shammouc          #+#    #+#             */
/*   Updated: 2021/12/14 15:53:15 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nb_malloc(unsigned long long n)
{
	unsigned long long	res;

	res = 3;
	while (n >= 16)
	{
		res++;
		n = n / 16;
	}
	return (res);
}

char	*ft_itoa_base_2(unsigned long long n, char *dest)
{
	char					*str;
	unsigned long long		i;
	unsigned long long		nb;

	i = nb_malloc(n);
	nb = n;
	if (n == 0)
		return (ft_strdup("0x0"));
	str = malloc((sizeof(char) * i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	while (nb > 0)
	{
		str[i] = dest[nb % 16];
		nb = nb / 16;
		i--;
	}
	str[1] = 'x';
	str[0] = '0';
	return (str);
}
