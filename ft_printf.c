/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:12:39 by shammouc          #+#    #+#             */
/*   Updated: 2021/12/14 15:49:44 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "ft_printf.h"

static char	*transforme(char c, va_list str)
{
	unsigned int		i;
	unsigned long long	j;

	if (c == 'd')
		return (ft_itoa(va_arg(str, int)));
	else if (c == 's')
		return (ft_strdup(va_arg(str, char *)));
	else if (c == 'x')
		return (ft_itoa_base(va_arg(str, int), "0123456789abcdef"));
	else if (c == 'X')
	{
		i = (unsigned int)va_arg(str, int);
		return (ft_itoa_base(i, "0123456789ABCDEF"));
	}
	else if (c == 'i')
		return (ft_itoa(va_arg(str, int)));
	else if (c == 'u')
		return (ft_itoa_u((unsigned int)va_arg(str, int)));
	else if (c == 'p')
	{
		j = (unsigned long long)va_arg(str, void *);
		return (ft_itoa_base_2(j, "0123456789abcdef"));
	}
	return (NULL);
}

static int	char_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	affiche(char c, va_list str)
{
	int	i;

	i = 0;
	if (c == '%')
	{
		ft_putchar('%');
		i++;
	}
	else if (c == 'c')
	{
		ft_putchar(va_arg(str, int));
		i++;
	}
	return (i);
}

static int	calcul(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = ft_strdup("(null)");
	ft_putstr(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;
	int		res;

	i = -1;
	res = 0;
	va_start(ptr, str);
	while (i++, str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%' || str[i + 1] == 'c')
				res = res + affiche(str[i + 1], ptr);
			else if (char_in(str[i + 1], "spdiuxX") == 1)
				res = res + calcul(transforme(str[i + 1], ptr));
			i++;
		}
		else if (str[i])
		{
			ft_putchar(str[i]);
			res++;
		}
	}
	va_end(ptr);
	return (res);
}
