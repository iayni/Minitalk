/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:43:59 by iayni             #+#    #+#             */
/*   Updated: 2022/02/28 19:34:39 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	ft_putnbr(int n)
{
	int		len;
	int		b_len;
	char	*base;

	base = "0123456789";
	b_len = 10;
	len = 0;
	if (n < b_len)
		len += write(1, &base[n], 1);
	else
	{
		len += ft_putnbr(n / b_len);
		len += write(1, &base[n % b_len], 1);
	}
	return (len);
}
