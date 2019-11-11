/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 04:32:29 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/11 05:32:47 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str(t_struct *p)
{
	int		i;
	char	*copy;
	char	h;

	h = (*p)->flags['0'] == 1 ? '0' : ' ';
	copy = (char *)va_arg((*p)->ap, void *);
	if ((*p)->flags['.'] == 1)
		copy = ft_dot(p, copy);
	if ((*p)->width != 0)
		ft_less(p, copy, h);
	else
		ft_putstr(copy);
	(*p)->count += ft_strlen(copy);
}

char	*ft_dot(t_struct *p, char *copy)
{
	int	i;

	i = 0;
	while (i < (*p)->precision)
		i++;
	copy[i] = '\0';
	return (copy);
}

void	ft_less(t_struct *p, char *copy, char c)
{
	int i;
	int	len;

	i = -1;
	len = ft_strlen(copy);
	if ((*p)->flags['-'] == 1)
	{
		ft_putstr(copy);
		while (++i < ((*p)->width - len))
		{
			ft_putchar(c);
			(*p)->count++;
		}
	}
	else
	{
		while (++i < ((*p)->width - len))
		{
			ft_putchar(c);
			(*p)->count++;
		}
		ft_putstr(copy);
	}
	(*p)->count += len;
}
