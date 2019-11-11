/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 01:30:51 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/11 04:42:23 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_fct(pointe fct[255])
{
	fct['c'] = &ft_c;
	fct['s'] = &ft_str;
	fct['d'] = &ft_num;
	fct['i'] = &ft_num;
	fct['x'] = &ft_base;
	fct['p'] = &ft_base;
	fct['X'] = &ft_base;
}

void	ft_reset_flags(t_struct *p)
{
	p->flags['-'] = 0;
	p->flags['.'] = 0;
	p->flags['0'] = 0;
	p->precision = 0;
	p->width = 0;
	p->len = 0;
}

/*
** CECI EST LA FONCTION QUI VA APPELLER LES FONCTIONS NECESSAIRES
** SELON LES BESOINS
*/

void	ft_init_p(t_struct *p, const char *format)
{
	p->format = format;
	p->count = 0;
	p->i = 0;
	ft_init_fct(p->fct);
	ft_reset_flags(p);
}


int	ft_printf(const char *format, ...)
{
	t_struct	p;

	ft_init_p(&p, format);
	va_start(p->ap, p->format);
	while (p->format[p->i])
	{
		if (p->format[p->i] == '%')
			ft_look(&p);
		else
		{
			ft_putchar(p->format[p->i]);
			++p->count;
		}
		++p->i;
	}
	return (p->count);
}
