/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:19:27 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/07 10:52:36 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lower(unsigned long long nbr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (nbr <= 15)
		count += ft_print_char(base[nbr]);
	else
	{
		count += ft_print_hex_lower(nbr / 16);
		count += ft_print_char(base[nbr % 16]);
	}
	return (count);
}
