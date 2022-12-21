/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:15:08 by lilizarr          #+#    #+#             */
/*   Updated: 2022/10/03 12:06:16 by lilizarr         ###   ########.fr       */
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

static int	power_10(int power)
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
	if (!s)
		return (NULL);
	if (sign_char == 2 && s)
	{
		s[cnt] = '-';
		cnt++;
		sign_num = -1;
	}
	while (--s_size >= 0)
	{
		res = (n_cpy / power_10(s_size)) * sign_num;
		n_cpy = n_cpy % (power_10(s_size));
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
	while ((sign_num * n_cpy) <= -10)
	{
		n_cpy = n_cpy / 10;
		s_size++;
	}
	n_cpy = n * sign_num;
	return (create_string(n_cpy, s_size, sign_char, sign_num));
}

// char	*ft_itoa(int n)
// {
// 	char	*s;
// 	int		s_size;
// 	int		res;
// 	int		n_cpy;
// 	int		sign_char;
// 	int		cnt;
// 	int		sign_num;

// 	s_size = 0;
// 	sign_char = 1;
// 	n_cpy = n;
// 	sign_num = 1;
// 	if (n < 0)
// 	{
// 		sign_num = -1;
// 		sign_char++;
// 	}
// 	while ((sign_num * n_cpy) <= -10)
// 	{
// 		n_cpy = n_cpy / 10;
// 		printf("\t%d | %d |%d \n  ", n_cpy, res, s_size);
// 		s_size++;
// 	}
// 	cnt = 0;
// 	s = ft_calloc((s_size + sign_char), sizeof(char));
// 	if (sign_char == 2 && s)
// 	{
// 		s[cnt] = '-';
// 		cnt++;
// 	}
// 	printf("\t\t\t%d | %d |%d | %d \t |%s| \n", n_cpy, res, s_size, sign_char, s);
// 	n_cpy = n;
// 	while (--s_size >= 0)
// 	{
// 		res = n_cpy / (power_10(s_size));
// 		n_cpy = n_cpy % (power_10(s_size));
// 		printf("\t %d | %d | %d | %d\t  ", n_cpy, res, s_size, power_10(s_size));
// 		s[cnt] = (sign_num * res) + '0';
// 		cnt++;
// 		printf("\t%s \n", s);
// 	}
// 	s[cnt] = (sign_num * n_cpy) + '0';
// 	return (s);
// }

int	main(void)
{
	int	num;
	int sign;
	char buffer[10];
	// Value of INT_MAX is +2147483647.
	// Value of INT_MIN is -2147483648.
	srand(clock());
	sign = (rand() % 1 - 2);
	//num =  rand() % INT_MAX * sign;
	num = 99999999999;
	//num = 0;
	printf("%d\n", num);
	printf("%s   |\n", ft_itoa(num));
	//printf("%d", num/pow10(8));
	return (0);
}