/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/08/23 16:57:32 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;

	data = malloc(count * size);
	if (data)
		ft_bzero(data, count * size);
	else
		return (NULL);
	return (data);
}
int	ft_isdigit(int ch)
{
	if (ch >= 48 && ch <= 57)
		return (1);
	else
		return (0);
}

char	*ft_strchr(const char *s, int c)
{	
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if ((*s == '\0') && (c == '\0'))
		return ((char *)s);
	else
		return (NULL);
}

int	ft_isprint(int ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	else
		return (0);
}

int	ft_isalpha(int ch)
{
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
		return (1);
	else
		return (0);
}

void	ft_print_result2(char c)
{
	write(1, &c, 1);
}

void	ft_print_result(int n)
{
	if (n >= 0)
	{
		if (n >= 10)
			ft_print_result(n / 10);
		ft_print_result2(n % 10 + '0');
	}
	else
	{
		ft_print_result2('-');
		if (n <= -10)
			ft_print_result(n / -10);
		ft_print_result2(n % -10 * -1 + '0');
	}
}
/*
0        ||| (1) 
546      ||| (2) 
-4886    ||| (3) 
548      ||| (4) 
54854    ||| (5) 
74       ||| (6) 
0        ||| (7) 
0        ||| (8) 
0        ||| (9) 
0        ||| (10) 
47       ||| (11) 
-47      ||| (12) 
0        ||| (13) 
0        ||| (14) 
2147483647       ||| (15) 
-2147483647      ||| (16) 
-2147483647      ||| (17) 
2147483647       ||| (18) 
0        ||| (19) 
-46      ||| (20) 
0        ||| (21) 
         ||| (20)   */

/* int	ft_atoi(const char *str)
{
	long	num;
	int		pos;
	int		neg;
	int		sign;

	num = 0;
	pos = 0;
	neg = 0;
	sign = 1;
	while ((ft_isdigit(*s) || ft_strchr( +-\t\n\r\v\f, *s) != NULL) && *s)
	{
		if (*s == '+' && pos++ >= 0)
			sign = 1;
		if (*s == '-' && neg++ <= 0)
			sign = -1;
		if (neg > 2 || pos > 2 || pos + neg > 1)
			sign = 0;
		if (ft_isdigit(*s))
			num = num * 10 + (*s - '0');
		if ((num > 0 && !ft_isdigit(*s)))
			return ((int)num * sign);
		s++;
	}
	return ((int)num * sign);
} */

/* int	ft_atoi(const char *s)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((ft_isdigit(*s) || ft_strchr(" +-\t\n\r\v\f", *s) != NULL) && *s)
	{
		//printf("\t|%d||%c|%c \t%ld\n", sign, *s, *(s + 1), num);
		if (*s == '+')
			sign = 1;
		if (*s == '-')
			sign = -1;
		if ((*s == '+' || *s == '-') && (*(s + 1) == '+' || *(s + 1) == '-'))
			return (0);
		//printf("\t|%d|%d|%d|%d||%c|%c \t%ld\n", sign, pos, neg, pos + neg,   *s, *(s + 1), num);
		if (ft_isdigit(*s))
			num = num * 10 + (*s - '0');
		if ((num > 0 && !ft_isdigit(*s)))
			return ((int)num * sign);
		s++;
	}
	return ((int)num * sign);
} */

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

static int	max_values(long long num, int sign)
{
	if ((num / INT_MAX) != 1)
	{
		if (sign == 1)
			return ((int)LONG_MAX);
		else
			return ((int)LONG_MIN);
	}
	return ((int)((sign * num) % LONG_MIN));
}

// static int check_isspace(char c)
// {
// 	int 	value;

// 	if (c == '\0')
// 		value = 0;
// 	else
// 	{
// 		/* code */
// 	}
	
// 	return (value);
// }
int	ft_atoi(const char *s)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (ft_strlen(s) == 0)
		return ((int)num * sign);
	while (*s &&(ft_isdigit(*s) || ft_strchr(" +-\t\n\r\v\f", *s) != NULL))
	{	
		if (num == 0 && *s == '-')
			sign = -1;
		printf ("\n\t_%lld | %d \t\t|%d|", num, sign, (int)(*s));
		if (ft_isdigit(*s))
		{
			num = num * 10 + (*s - '0');
			if (num > INT_MAX)
				return (max_values(num, sign));
		}
		if ((num > 0 && !ft_isdigit(*s)))
			return ((int)num * sign);
		if ((*s == '+' || *s == '-') && ft_strchr(" +-\t\n\r\v\f", *(s + 1)))
			return (0);
		s++;
	}
	printf ("\n\t**%lld | %d", num, sign);
	return ((int)(sign * num));
}

int main(void)
{
	//char escape[] = {9, 10, 11, 12, 13, 0};
	/* char * escape = " +-\t\n\v\f\r";
	while (*escape)
	{
		printf("%d|", (int)*escape);
		escape++;
	}
	*/
	
	int		arg;
	int		i1 ;
	int		i2;
	char *n;

	write(1, "\n\t\t\t----------------TEST----------------\n", ft_strlen("\n\t\t\t----------------TEST----------------\n")); 
	n = "0 46754\0677"; 
	//assert(ft_atoi(n) == atoi(n));
	write(1, "\n\n", 2);
	i1 =  atoi(n);
	printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
	i2 = ft_atoi(n);
	printf("\n*ft |  %d  |\n",i2);
	printf(" *|  %d  |\n----------------\n",i1);

	write(1, "\n\t\t\t----------------TEST----------------\n", ft_strlen("\n\t\t\t----------------TEST----------------\n")); 
	n = "-9223372036854775806mm"; 
	//assert(ft_atoi(n) == atoi(n));
	write(1, "\n\n", 2);
	i1 =  atoi(n);
	printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
	i2 = ft_atoi(n);
	printf("\n*ft |  %d  |\n",i2);
	printf(" *|  %d  |\n----------------\n",i1);
	
 	write(1, "\n\t\t\t----------------TEST----------------\n", ft_strlen("\n\t\t\t----------------TEST----------------\n")); 
	n = "12-23";
	assert(ft_atoi(n) == atoi(n));
	write(1, "\n\n", 2);
	i1 = atoi(n);
	printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
	i2 = ft_atoi(n);
	printf("\n*ft |  %d  |\n",i2);
	printf(" *|  %d  |\n----------------\n",i1);

	write(1, "\n\t\t\t----------------TEST----------------\n", ft_strlen("\n\t\t\t----------------TEST----------------\n")); 
	n = "12+-23";
	assert(ft_atoi(n) == atoi(n));
	write(1, "\n\n", 2);
	i1 = atoi(n);
	printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
	i2 = ft_atoi(n);
	printf("\n*ft |  %d  |\n",i2);
	printf(" *|  %d  |\n----------------\n",i1);

	write(1, "\n\t\t\t----------------TEST----------------\n", ft_strlen("\n\t\t\t----------------TEST----------------\n")); 
	n = "99999git999999999999999999999";
	assert(ft_atoi(n) == atoi(n));
	write(1, "\n\n", 2);
	i1 = atoi(n);
	printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
	i2 = ft_atoi(n);
	printf("\n*ft |  %d  |\n",i2);
	printf("\n *|  %d  |\n----------------\n",i1);

	write(1, "\n\t\t\t**----------------TEST----------------\n", ft_strlen("\n\t\t\t----------------TEST----------------\n")); 
	n = "-99999999999999999999999999";
	//assert(ft_atoi(n) == atoi(n));
	write(1, "\n\n", 2);
	i1 = atoi(n);
	printf("\n\t\tString:|  %s  |\n",n);
	i2 = ft_atoi(n);
	printf("\n*ft |  %d  |\n",i2);
	printf("\n *|  %d  |\n----------------\n",i1);

	write(1, "\n\t\t\t----------------TEST----------------\n", ft_strlen("\n\t\t\t----------------TEST----------------\n")); 
	n = "0";
	assert(ft_atoi(n) == atoi(n));
	write(1, "\n\n", 2);
	i1 = atoi(n);
	printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
	i2 = ft_atoi(n);
	printf("\n*ft |  %d  |\n",i2);
	printf("\n *|  %d  |\n----------------\n",i1);

	printf("\n\tft_strchr| %s |\n", ft_strchr(" +-\t\n\r\v\f", *n));
	write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
	ft_print_result(i2);
	write(1, "|\n", 2);
	write(1, "\n * |  ", ft_strlen(" \n* |  " ));
	ft_print_result(i1);
	write(1, "|\n", 2);
	write(1, "\n", 1); 

	write(1, "\n\t\t\t----------------TEST----------------\n", ft_strlen("\n\t\t\t----------------TEST----------------\n")); 
	n = "";
	assert(ft_atoi(n) == atoi(n));
	i1 = atoi(n);
	printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
	i2 = ft_atoi(n);
	write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
	ft_print_result(i2);
	write(1, "|\n", 2);
	write(1, " * |  ", ft_strlen(" * |  " ));
	ft_print_result(i1);
	write(1, " |", 2); 
	/* int 	*res = (int *)malloc(sizeof(int));
	
	printf("%ld", addOvf(res, 2147483649));
	printf("\n %d\n", *res); 
	long	x = 2147483649;
	printf("\n %d\n", (int)x);*/

	arg = 0;
	while (++arg <= 26)
	{
		write(1, "\n\t\t\t---------------- ", ft_strlen("\n\t\t\t---------------- ")); 
		write(1, ft_itoa(arg), ft_strlen(ft_itoa(arg)));
		write(1, " TEST----------------\n", ft_strlen(" TEST----------------\n")); 
		if (arg == 1)
		{
			n = "0";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 2)
		{
			n = "546:5";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 3)
		{
			n = "-4886";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			write(1, "\n\n", 2);
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 4)
		{
			n = "+548";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 5)
		{
			n = "054854";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 6)
		{
			n = "000074";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 7)
		{
			n = "+-54";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 8)
		{
			n = "-+48";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 9)
		{
			n = "--47";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 10)
		{
			n = "++47";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 11)
		{
			n = "+47+5";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 12)
		{
			n = "-47-5";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 13)
		{
			n = "\e475";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 14)
		{
			n = "\t\n\r\v\f\0  469 \n";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 15)
		{
			n = "\n\n\n  -46\b9 \n5d6";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 16)
		{
			n = "";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 17)
		{
			n = "-2147483648";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 18)
		{
			n = "2147483647";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 19)
		{
			n = "\t\n\v\f\rd469 \n";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 20)
		{
			n = "-2147483660";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 21)
		{
			n = "2147483660";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 22)
		{
			n = "-99999999999999999999999999";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 23)
		{
			n = "99999999999999999999999999";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 24)
		{
			n = "--218-3647-";
			assert(ft_atoi(n) == atoi(n));
			i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %d  |\n", i2);
			printf("\n *|  %d  |\n----------------\n", i1);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
		}
		else if (arg == 25)
		{
			n = "0";
			//assert(ft_atoi(n) == atoi(n));
			//i1 = atoi(n);
			printf("\n\t\tString:|  %s  | %lu \n", n, strlen(n));
			i2 = ft_atoi(n);
			printf("\n*ft |  %s  |\n", ft_itoa(i2));
			printf("\n *|  %s  |\n----------------\n", ft_itoa(i1));
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, " |", 2);
			write(1, "\n*ft |  ", ft_strlen(" \n*ft |  " ));
			ft_print_result(i2);
			write(1, "|\n", 2);
			write(1, " * |  ", ft_strlen(" * |  " ));
			ft_print_result(i1);
			write(1, "|\n", 2);
			
		}
		printf ("\n");
	}
	
	printf ("\n");

	printf ("---\n");

	return (0);
}
