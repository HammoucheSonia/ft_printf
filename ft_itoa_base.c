/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:10:34 by shammouc          #+#    #+#             */
/*   Updated: 2021/12/14 15:56:20 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	nb_malloc(unsigned int n)
{
	int	res;

	res = 1;
	if (n < 0)
	{
		res = res + 1;
		n = -n;
	}
	while (n >= 16)
	{
		res++;
		n = n / 16;
	}
	return (res);
}

char	*ft_itoa_base(unsigned int n, char *dest)
{
	char			*str;
	int				i;
	unsigned long	nb;

	i = nb_malloc(n);
	nb = n;
	if (n == 0)
		return (ft_strdup("0"));
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
		str[i] = dest[nb % 16];
		nb = nb / 16;
		i--;
	}
	return (str);
}
