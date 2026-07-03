/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 07:04:05 by nifromon          #+#    #+#             */
/*   Updated: 2025/03/27 07:42:10 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft_H/libft.h"

int	ft_ptrlen(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (15 < nbr)
		i += ft_ptrlen(nbr / 16);
	i++;
	return (i);
}
