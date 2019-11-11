/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 01:37:47 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/11 06:29:41 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_look(t_struct *p, pointe fct[255])
{
	pointe	check;

	while (p->format[p->i] &&
		!(check = fct[p->format[p->i]]))
	{
		if (p->format[p->i] == '-' || (p->format[p->i] == '0') ||
			(p->format[p->i] == '.'))
			p->flags[p->format[p->i]] = 1;
		if (p->format[p->i] >= '1' && p->format[p->i] <= '9')
			p->width = ft_atoi(p);
		if (p->format[p->i] == '.')
			p->precision = ft_atoi(p);
		p->i++;
	}
	if ((p->flags['-'] == 1) || (p->flags['.'] == 1))
		p->flags['0'] = 0;
}

int		ft_atoi(t_struct *p)
{
	int nb;

	nb = 0;
	if (p->format[p->i] == '.' && (!(p->format[++p->i] >= '0' &&
		p->format[p->i] <= '9')))
		return(1);
	while (p->format[p->i] >= '0' && p->format[p->i] <= '9')
	{
		nb = nb * 10 + (p->format[p->i] - '0');
		p->i++;
	}
	p->i--;
	return (nb);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_nbrlen(int nb)
{
	int size;

	size = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		size++;
	while (nb != 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}
