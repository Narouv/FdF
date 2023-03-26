/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:49:36 by rnauke            #+#    #+#             */
/*   Updated: 2022/08/08 18:18:50 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	convert_to_decimal(int i);
size_t	percent_sign(void);
size_t	convert_to_address(void *addy);
size_t	convert_to_char(unsigned char c);
size_t	convert_to_string(char *str);
size_t	convert_to_uint(unsigned int u_int);
size_t	convert_to_hex_lowercase(size_t l_hex);
size_t	convert_to_hex_uppercase(size_t u_hex);
char	*ft_itoa_printf(unsigned long long n);
char	*ft_itoah_printf(unsigned int n);
char	*ft_ulltoah_printf(unsigned long long n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlen(const char *s);
int		ft_toupper(int c);
char	*ft_itoa(int n);
#endif
