/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:24:21 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/11 06:30:46 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

typedef struct	s_struct
{
	const char	*format;
	int			count;
	int			width;
	int			precision;
	int			i;
	va_list		ap;
	int			flags[255];
	int			len;
}				t_struct;

typedef	void	(*pointe)(t_struct*);

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_check_base(char *base);
void			ft_putnbr_base(int n, char *base);
void			ft_look(t_struct *p, pointe fct[255]);
int				ft_atoi(t_struct *p);
void			ft_str(t_struct *p);
char			*ft_dot(t_struct *p, char *copy);
void			ft_less(t_struct *p, char *copy, char c);
void			ft_c(t_struct *p);
int				ft_strlen(char *str);
int				ft_nbrlen(int nb);
int				ft_printf(const char* format, ...);

#endif
