/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:04:09 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/03 17:33:44 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	putchar_count(int c);
size_t	putstr_count(char *str);
size_t	putnbr_base10_count(int nbr, char *base);
size_t	putUnbr_base10_count(unsigned int nbr, char *base);
size_t	putptr_base_count(void *ptr, char *base, int first_loop_flag);

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

static size_t	display_data(char specifier, va_list args)
{
	size_t	count; // valeur de retour = nb char affiché

	count = 0;
	if (specifier == 'c')
		count = putchar_count(va_arg(args, int));
// imprime 1 char
	else if (specifier == 's')
		count = putstr_count(va_arg(args, char *));
// imprime une string
	else if (specifier == 'p')
		count = putptr_base_count(va_arg(args, void *), HEX_BASE_LOW, 1);
// argument de pointeur void * imprimé en hexadec
	else if (specifier == 'd' || specifier == 'i')
		count = putnbr_base10_count(va_arg(args, int), DEC_BASE);
// imprime un nb decimal (base 10) imprime un nombre entier (base 10)
	else if (specifier == 'u')
		count = putUnbr_base10_count(va_arg(args, unsigned int), DEC_BASE);
// imprime un nombre decimal non signe (base 10)
	else if (specifier == 'x')
		count = putUnbr_base10_count(va_arg(args, unsigned int), HEX_BASE_LOW);
// imprime un nombre en hexadecimal minuscule 
	else if (specifier == 'X')
		count = putUnbr_base10_count(va_arg(args, unsigned int), HEX_BASE_HIGH);
// imprime un nombre en hexadecimal majuscule 
	else if (specifier == '%')
		count = putchar_count('%');
// imrpime '%' / sorte de putchar 
	return (count);
}

size_t	putchar_count(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	putstr_count(char *str)
{
	size_t	count;

	if (!str)
	{
		write(1, NULL_DISPLAY, ft_strlen(NULL_DISPLAY));
		return (6);
	}
	count = 0;
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

size_t	putnbr_base10_count(int nbr, char *base)
{
	int		base_length;
	long	long_nbr;
	size_t	count;

	base_length = ft_strlen(base);
	long_nbr = nbr;
	count = 0;
	if (long_nbr < 0)
	{
		count += putchar_count('-');
		long_nbr *= -1;
	}
	if (long_nbr >= base_length)
		count += putnbr_base10_count(long_nbr / base_length, base);
	count += putchar_count(base[long_nbr % base_length]);
	return (count);
}

size_t	putUnbr_base10_count(unsigned int nbr, char *base)
{
	unsigned long long	lnbr;
	unsigned int		base_length;
	size_t				count;

	lnbr = nbr;
	base_length = ft_strlen(base);
	count = 0;
	if (lnbr >= base_length)
		count += putnbr_base10_count(lnbr / base_length, base);
	count += putchar_count(base[lnbr % base_length]);
	return (count);
}

size_t	putptr_base_count(void *ptr, char *base, int first_loop_flag)
{
	unsigned long long	nbr;
	size_t				base_length;
	size_t				count;

	nbr = (unsigned long long)ptr;
	base_length = ft_strlen(base);
	count = 0;
	if (ptr == NULL)
	{
		count += putstr_count(NIL_DISPLAY);
		return (count);
	}
	if (first_loop_flag == 1)
		count += putstr_count(POINTER_PREFIX);
	if (nbr >= base_length)
		count += putptr_base_count((void *)(nbr / base_length), base, 0);
	count += putchar_count(base[nbr % base_length]);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	size_t	printed_count;

	va_start(args, str);
	printed_count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			printed_count += display_data(*++str, args);
			str++;
		}
		else
			printed_count += putchar_count(*str++);
	}
	va_end(args);
	return (printed_count);
}

#include <stdio.h>

int	main()
{
	unsigned int	u = 50;
	char	c = 'Y';
	char	*str = "Coucou";
	void	*ptr = &u;
	int	d = 102.99;
	int	i = 100;
	unsigned int	x = 156;
	unsigned int	X = 156;
	unsigned long int	addresse = (unsigned long int)&u;
	 
	printf("%%c : %c\n", c);
	printf("%%s : %s\n", str);
	printf("%%p : %p\n", ptr);
	printf("Adresse de u : %lu\n", addresse);
	printf("%%d : %d\n", d);
	printf("%%i : %i\n", i);
	printf("%%u : %u\n", u);
	printf("%%x : %x\n", x);
	printf("%%X : %X\n", X);
	printf("%%\n");

	ft_printf("%%c : %c\n", c);
	ft_printf("%%s : %s\n", str);
	ft_printf("%%p : %p\n", ptr);
	ft_printf("Adresse de u : %lu\n", addresse);
	ft_printf("%%d : %d\n", d);
	ft_printf("%%i : %i\n", i);
	ft_printf("%%u : %u\n", u);
	ft_printf("%%x : %x\n", x);
	ft_printf("%%X : %X\n", X);
	ft_printf("%%\n");
}
