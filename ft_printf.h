/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*	 ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:46:29 by shammouc          #+#    #+#             */
/*   Updated: 2021/12/14 16:00:54 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char const*str);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa_base(unsigned int n, char *dest);
char	*ft_strdup(char const *src);
int		ft_strlen(const char *str);
char	*ft_itoa_base_2(unsigned long long n, char *dest);
int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
#endif 
