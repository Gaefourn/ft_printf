/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:13:17 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/11 06:26:09 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
		write(1, "(null)", 6);
	while (str[i])
		i++;
	write(1, str, i);
}

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (! base[i] || !base[i + 1])
		return (0);
	while (base[i])
	{
		j = i + 1;
		if ((base[i] >= '0' && base[i] <= '9') ||( base[i] >= 'a' &&
		base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z'))
		{
			while (base[j++])
				if (base[i] == base[j])
					return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

void	ft_putnbr_base(int n, char *base)
{
	long int nb;
	int		i;

	nb = n;
	i = 0;
	if (ft_check_base(base) == 0)
		return ;
	while(base[i])
		i++;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= i)
	{
		ft_putnbr_base(nb / i, base);
		ft_putnbr_base(nb % i, base);
	}
	else
		ft_putchar(base[nb]);
}
