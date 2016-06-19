#include <stdlib.h>
#include <math.h>

static void	ft_reverse(char *str, int len)
{
	int		temp;
	int		i;
	int		j;

	i = 0;
	j = len - 1;
	while (i < j && i < 20)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i += 1;
		j -= 1;
	}
}

static int	intToStr(int x, char *str, int d)
{
	int i = 0;
	while (x && i < 20)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d && i < 20)
		str[i++] = '0';
	ft_reverse(str, i);
	str[i] = '\0';
	return (i);
}

char	*ft_ftoa(float fl, int afterpoint)
{
	float	fpart;
	char	*str;
	int		ipart;
	int		i;

	str = (char *)malloc(sizeof(char) * 21);
	ipart = (int)fl;
	fpart = fl - (float)ipart;
	i = intToStr(ipart, str, 0);
	if (afterpoint != 0 && i < 19)
	{
		str[i] = '.';
		fpart = fpart * pow(10, afterpoint);
		intToStr((int)fpart, str + i + 1, afterpoint);
	}
	else
		str[++i] = '\0';
	return (str);
}
