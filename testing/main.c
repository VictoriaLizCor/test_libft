#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

//int ft_isalpha(int c);
// int ft_isalnum(int c);
// int ft_isdigit(int c);
// int ft_isascii(int ch);
// int ft_isprint(int ch);
// int ft_strlen(char *str);


int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
		return (c);
	}
	else
		return (c);
}


int    main(void)
{   
    write(1, "\n", 1);
  
    // printf("%i\n", ft_isprint(32));

	/* TESTING FT_STRLEN 
	printf("%d\n", ft_strlen("Linda Victoria Lizarraga Cortes"));

	int	counter;

	counter = 0;
	char *str = "Hola Mexico mâgico \n"; 
	while (str[counter])
	{
		printf("%c\n",str[counter]);
		printf("%d\n",str[counter]);
		counter++;
		write(1, "\n", 1);

	} */
	int ch = 85;

	printf("Upper case of %c = %c\n", ch,  ft_tolower(ch) );

	return (0);
	
}