/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:15:08 by lilizarr          #+#    #+#             */
/*   Updated: 2022/10/03 12:55:01 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <time.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;

	if (size == SIZE_MAX || count == SIZE_MAX)
		return (NULL);
	data = malloc(count * size);
	if (data)
		ft_bzero(data, count * size);
	else
		return (NULL);
	return (data);
}

size_t	ft_strlen(const char *str)
{	
	size_t	counter;

	counter = 0;
	while (str[counter])
	{
		counter++;
	}
	return (counter);
}

static int	pow10(int power)
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	while (i++ <= power)
		result *= 10;
	return (result);
}

static char	*create_string(int n_cpy, int s_size, int sign_char, int sign_num)
{
	char	*s;
	int		cnt;
	int		res;

	cnt = 0;
	s = ft_calloc((s_size + sign_char + 1), sizeof(char));
	printf("\t\t\t%d | %d |%d  \t |%s| \n", s_size, sign_char, s_size + sign_char, s);
	if (!s)
		return (NULL);
	if (sign_char == 2 && s)
	{
		s[cnt] = '-';
		cnt++;
		sign_num = -1;
	}
	printf("\t\t\t%d | %d |%d | %d \t |%s| \n", n_cpy, s_size, sign_char, sign_num, s);
	while (--s_size >= 0)
	{
		res = (n_cpy / pow10(s_size)) * sign_num;
		n_cpy = n_cpy % (pow10(s_size));
		printf("\t %d | %d | %d | %d\t\t %c \n ", n_cpy, res, s_size, pow10(s_size), (res) + '0');
		s[cnt] = res + '0';
		cnt++;
	}
	s[cnt] = (sign_num * n_cpy) + '0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		s_size;
	int		n_cpy;
	int		sign_char;
	int		sign_num;

	s_size = 0;
	sign_char = 1;
	n_cpy = n;
	sign_num = -1;
	if (n < 0)
	{
		sign_num = 1;
		sign_char++;
	}	
	printf("\t**  %d | %d | %d| %d\n  ", n_cpy, sign_char , sign_num, sign_num * n_cpy);
	while ((sign_num * n_cpy) <= -10)
	{
		n_cpy = n_cpy / 10;
		printf("\tw* %d | %d *\n  ", n_cpy, s_size);
		s_size++;
	}
	n_cpy = n * sign_num;
	return (create_string(n_cpy, s_size, sign_char, sign_num));
}

int	main(void)
{
	int	num;
	int	sign;
	int	cnt;
	// Value of INT_MAX is +2147483647.
	// Value of INT_MIN is -2147483648.
	cnt = 0;
	srand(clock());
	
	while (++cnt <= 100 )
	{
		sign = (rand() % 1 - 2);
		num =  rand() % INT_MAX * sign;
		printf("%s | %d\n", ft_itoa(num), num);
	}
	return (0);
}