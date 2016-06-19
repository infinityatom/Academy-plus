#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int		main(void)
{
	printf("%0 10d\n", 69);
	//write(1, L"Hello world\n", 12 * 4);
	//printf("%lu\n", sizeof(char));
	//ft_printf("hello %yorld\n");
	printf("%s\n", "Hello world");
	printf("%ls\n", L"Hello world");
	//printf("%c\n", 'a');
	//printf("%C\n", 'a');
	//printf("%d\n", ft_printf("ana are: %ydar nu\n"));
	//printf("%d\n", printf("ana are: %ydar nu\n"));
	//printf("%d\n", ft_printf("ana are: %f\n", 21533.443214));
	//printf("%d\n", printf("ana are: %f\n", 21533.443214));
	//ft_printf("this:%c;\nana:%c;\nmere:%c;\n", 'a', 'b', 'c');
	//printf("%1$s %02$*3$.*4$s\n%3$d\n", "asd", "abc", 5, 2);
	//printf("here:%#20 +a\n", 10.5);
	//printf("%.10 .5f\n", 5.2);
	//printf("%.5 .10f\n", 5.2);
	//printf("%f\n", 5.2);
	//printf("%1$f %2$f\n", 5.2, 4.7);
	//printf("%1$f %2$f\n", 5.2, 4.7);
	//printf("%+1.2f %2$f\n", 5.2, 4.7);
	//printf("%2$f\n", 5.2, 4.7);
	//int i = write(1, "%s", 2);
	//printf("\ni:%d\n", i);
	return (0);
}
