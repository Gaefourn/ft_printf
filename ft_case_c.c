/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 03:41:28 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/11 05:55:53 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(t_struct *p)
{
	int		i;
	char	copy;

	i = -1;
	if ((*p)->flags['-'] == 1)
	{
		ft_putchar((char)va_arg((*p)->ap, void*));
		while (++i < (*p)->width - 1)
		{
			ft_putchar(' ');
			(*p)->count++;
		}
	}
	if ((*p)->flags['0'] == 1)
	{
		while (++i < (*p)->width - 1)
		{
			ft_putchar('0');
			(*p)->count++;
		}
		ft_putchar((char)va_arg((*p)->ap, void*));
	}
	else
		ft_putchar((char)va_arg((*p)->ap, void*));
	(*p)->count++;
}
