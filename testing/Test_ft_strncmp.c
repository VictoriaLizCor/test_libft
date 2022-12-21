/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/08/15 12:15:44 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* int check_strings(const char *s1, const char *s2, size_t n)
{
	unsigned int	ch1;
	unsigned int	ch2;
	size_t			cnt;
	size_t			s1_len;
	size_t			s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ch1 = s1[s1_len];
	ch2 = s2[s2_len];
	cnt = 0;
	while (*(s1 + cnt) && *(s2 + cnt) && cnt < n)
	{
		write(1, s1 + cnt, 1);
		write(1, "|", 1);
		write(1, s2 + cnt, 1);
		write(1, "\n", 1);
		write(1, &ch1, 1);
		write(1, "|", 1);
		write(1, &ch2, 1);
		write(1, "\n", 1);
		if (ch1 > ch2 && s1_len > s2_len)
			ch1 = 1;
		else if (ch1 < ch2 && s1_len > s2_len)
			ch1 = -1;
		else
			ch1 = 0;
		cnt++;
	}
	if (*s1 || *s2)
	{
		cnt++;
	}
	if (s1_len > s2_len)
		return (1);
	else if (s1_len < s2_len)
		return (-1);
	else
		return (0);
} */

size_t	ft_strlen(const char *str)
{	
	size_t	cnt;

	cnt = 0;
	while (str[cnt])
	{
		cnt++;
	}
	return (cnt);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	size_t	cnt;

	cnt = 0;
	if (n > 0)
	{
		while (cnt + 1 < n && !!(s1[cnt]) && !!(s2[cnt]) && s1[cnt] == s2[cnt])
		{
			cnt++;
		}
		if ((unsigned char)(s1[cnt]) - (unsigned char)(s2[cnt]) > 0)
			return (1);
		else if ((unsigned char)(s1[cnt]) - (unsigned char)(s2[cnt]) < 0)
			return (-1);
		else
			return (0);
	}
	else
		return (0);
}

int main()
{
	// iguales = 0
	// str1 > str2 = 1
	// str1 < str2 = -1
	printf ("1 = %d\n", ft_strncmp("salut", "salut", 5)); //0
	printf ("2 = %d\n",ft_strncmp("test", "testss", 7)); //-1
	printf ("3 = %d\n",ft_strncmp("testss", "test", 7)); //1
	printf ("4 = %d\n",ft_strncmp("test", "tEst", 4)); //1
	printf ("5 = %d\n",ft_strncmp("", "test", 4)); //-1
	printf ("6 = %d\n",ft_strncmp("test", "", 4)); //1
	printf ("7 = %d\n",ft_strncmp("abcdefghij", "abcdefgxyz", 3)); // 0
	printf ("8 = %d\n",ft_strncmp("abcdefgh", "abcdwxyz", 4)); // 0
	printf ("9 = %d\n",ft_strncmp("zyxbcdefgh", "abcdwxyz", 0)); // 0
	printf ("10 = %d\n",ft_strncmp("abcdefgh", "", 0)); // 0
	printf ("11 = %d\n",ft_strncmp("test\200", "test\0", 6)); //1

	printf("--------\n");
	printf ("1 = %d\n", strncmp("salut", "salut", 5)); //0
	printf ("2 = %d\n",strncmp("test", "testss", 7)); //-1
	printf ("3 = %d\n",strncmp("testss", "test", 7)); //1
	printf ("4 = %d\n",strncmp("test", "tEst", 4)); //1
	printf ("5 = %d\n",strncmp("", "test", 4)); //-1
	printf ("6 = %d\n",strncmp("test", "", 4)); //1
	printf ("7 = %d\n",strncmp("abcdefghij", "abcdefgxyz", 3)); // 0
	printf ("8 = %d\n",strncmp("abcdefgh", "abcdwxyz", 4)); // 0
	printf ("9 = %d\n",strncmp("zyxbcdefgh", "abcdwxyz", 0)); // 0
	printf ("10 = %d\n",strncmp("abcdefgh", "", 0)); // 0
	printf ("11 = %d\n",strncmp("test\200", "test\0", 6)); //1
	return (0);
}
/* 
1 = 0
2 = -115
3 = 115
4 = 32
5 = -116
6 = 116
7 = 0
8 = 0
9 = 0
10 = 0
11 = 128
--------
1 = 0
2 = -1
3 = 1
4 = 1
5 = -1
6 = 1
7 = 0
8 = 0
9 = 0
10 = 0
11 = 1 */