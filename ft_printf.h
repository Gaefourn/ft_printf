/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:24:21 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/11 03:30:01 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_check_base(char *base);
void			ft_putnbr_base(int n, char *base);
void			ft_look(t_struct *p);
int				ft_atoi(t_struct *p);

typedef	void	(*pointe)(t_struct*);

typedef			s_struct
{
	const char	*format;
	pointe		fct[255];
	int			count;
	int			width;
	int			precision;
	int			i;
	va_list		ap;
	int			flags[255];
}				t_struct;


#endif
