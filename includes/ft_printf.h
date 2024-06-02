/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:23:49 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/31 12:11:21 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define DEC_BASE "0123456789"
# define HEX_BASE_LOW "0123456789abcdef"
# define HEX_BASE_HIGH "0123456789ABCDEF"
# define POINTER_PREFIX "0x"
# define NULL_DISPLAY "(null)"
# define NIL_DISPLAY "(nil)"

int			ft_printf(const char *str, ...);
size_t		putchar_count(int c);
size_t		putstr_count(char *str);
size_t		putnbr_base10_count(int nbr, char *base);
size_t		put_u_base10_count(unsigned int nbr, char *base);
size_t		putptr_base_count(void *ptr, char *base, int first_loop_flag);
size_t		ft_strlen(const char *str);

#endif 
