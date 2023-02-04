/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:17:32 by shammouc          #+#    #+#             */
/*   Updated: 2021/12/11 22:22:59 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	nb_malloc(int n)
{
	int	res;

	res = 1;
	if (n < 0)
	{
		res = res + 1;
		n = -n;
	}
	while (n >= 10)
	{
		res++;
		n = n / 10;
	}
	return (res);
}

static char	*int_min(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (NULL);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	long			nb;

	i = nb_malloc(n);
	nb = n;
	if (n == -2147483648 || n == 0)
		return (int_min(n));
	str = malloc((sizeof(char) * i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	str[i] = '\0';
	i--;
	while (nb > 0)
	{
		str[i] = (nb % 10 + '0');
		nb = nb / 10;
		i--;
	}
	return (str);
}
