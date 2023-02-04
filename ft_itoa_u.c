/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:17:32 by shammouc          #+#    #+#             */
/*   Updated: 2021/12/14 15:53:49 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nb_malloc(unsigned int n)
{
	int	res;

	res = 1;
	while (n >= 10)
	{
		res++;
		n = n / 10;
	}
	return (res);
}

char	*ft_itoa_u(unsigned int n)
{
	char			*str;
	int				i;
	long			nb;

	i = nb_malloc(n);
	nb = n;
	if (n == 0)
		return (ft_strdup("0"));
	str = malloc((sizeof(char) * i + 1));
	if (!str)
		return (NULL);
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
