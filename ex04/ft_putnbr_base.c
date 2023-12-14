/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:42:08 by anmateo-          #+#    #+#             */
/*   Updated: 2023/06/22 18:42:10 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] >= 127)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	num;

	if (check_base(base))
	{
		base_len = 0;
		while (base[base_len] != '\0')
			base_len++;
		num = nbr;
		if (num < 0)
		{
			write(1, "-", 1);
			num *= -1;
		}
		if (num >= base_len)
			ft_putnbr_base(num / base_len, base);
		write(1, &base[num % base_len], 1);
	}
}
