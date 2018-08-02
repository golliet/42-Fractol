/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:44:49 by golliet            #+#    #+#             */
/*   Updated: 2018/02/28 11:20:14 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_sstrlen(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
