/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:06:21 by golliet           #+#    #+#             */
/*   Updated: 2018/02/28 11:20:14 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr(int n)
{
	unsigned int	nb;

	nb = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		(ft_putnbr(nb / 10));
	ft_putchar(nb % 10 + '0');
}
