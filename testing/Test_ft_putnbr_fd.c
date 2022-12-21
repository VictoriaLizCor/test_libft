/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:00:25 by lilizarr          #+#    #+#             */
/*   Updated: 2022/10/01 14:36:28 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>

void	check(bool succes)
{
	if (succes)
		write(1, "Yes\n", 4);
	else
		write(1, "*NO\n", 4);
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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	write(1, &c, 1);
}

/* void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num < 10)
		ft_putchar_fd(num + '0', fd);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
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

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	int		s_size;
	int		res;
	int		n_cpy;
	int		cnt;
	int		sign_num;

	s_size = 0;
	n_cpy = n;
	sign_num = -1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign_num = 1;
	}
	printf("\n\n\t%d | %d  \n  ", n_cpy, sign_num * n_cpy);
	while ((sign_num * n_cpy) <= -10)
	{
		n_cpy = n_cpy / 10;
		s_size++;
		printf("\t%d | %d \n  ", n_cpy, s_size);
	}
	cnt = 0;
	printf("\n\t||%d | %d | %d | %d", n_cpy, s_size, sign_num, n * sign_num);
	sign_num = -1;
	n_cpy = n * sign_num;
	printf("\t\t\t\t||%d | %d | %d | %d\n", n_cpy, s_size, sign_num, n * sign_num);
	while (--s_size >= 0)
	{
		res = (n_cpy / power_10(s_size)) * sign_num;
		n_cpy = n_cpy % (power_10(s_size));
		printf("\t**|%d | %d | %d | %d | %c\n  ", n_cpy, res, s_size, power_10(s_size),  res + '0');
		ft_putchar_fd (res + '0', fd);
		cnt++;
	}
	printf("\t*| %d | %d | %d | %d | %d\t  ", n_cpy, s_size, power_10(s_size), sign_num * n_cpy,  '0');
	ft_putchar_fd ((sign_num * n_cpy) + '0', fd);
	write(1, "\n", 1);
}
/* void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (num > 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	else
		ft_putchar_fd(num + '0', fd);
} */

int main(void)
{
	int fd = open("tripouille", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(0, fd);
	lseek(fd, SEEK_SET, 0);
	char s[42] = {0}; 
	printf("\n");
	read(fd, s, 2);
	printf("\n\t| %s |\n",s);
	/* 1 */
	check(!strcmp(s, "0")); 
	unlink("./tripouille");

	fd = open("tripouille", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(10, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 3);
	printf("\n\t| %s |\n",s);
	/* 2 */ 
	check(!strcmp(s, "10"));
	unlink("./tripouille");

	fd = open("tripouille", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(INT_MAX, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 11);
	/* 3 */ 
	check(!strcmp(s, "2147483647"));
	printf("\n\t| %s |\n",s);
	unlink("./tripouille");

	fd = open("tripouille", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(INT_MIN, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 12);
	/* 4 */
	printf("\n\t| %s |\n",s);
	check(!strcmp(s, "-2147483648"));
	unlink("./tripouille");

	fd = open("tripouille", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(-42, fd);
	lseek(fd, SEEK_SET, 0);
	s[read(fd, s, 4)] = 0;
	/* 5 ipenas */
	printf("\n\t| %s |\n",s);
	unlink("./tripouille");
	write(1, "\n", 1);
	return (0);
}
