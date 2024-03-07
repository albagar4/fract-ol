/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:48:14 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/07 10:53:09 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_upper(unsigned long long nbr)
{
	char	*base;
	int		count;

	base = "0123456789ABCDEF";
	count = 0;
	if (nbr <= 15)
		count += ft_print_char(base[nbr]);
	else
	{
		count += ft_print_hex_upper(nbr / 16);
		count += ft_print_char(base[nbr % 16]);
	}
	return (count);
}
