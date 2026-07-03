/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:34:45 by nifromon          #+#    #+#             */
/*   Updated: 2025/03/27 07:29:09 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft_H/libft.h"

static size_t	ull_len(unsigned long long nbr)
{
	size_t	i;

	i = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_ulltoa(unsigned long long n)
{
	size_t				i;
	unsigned long long	nbr;
	char				*result;

	nbr = n;
	i = ull_len(nbr) - 1;
	result = (char *)ft_calloc(ull_len(nbr) + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (nbr == 0)
		return (result[0] = '0', result);
	while (nbr > 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	return (result);
}
