#include "myGL.h"

rgba	new_rgba(value r, value g, value b, value a)
{
	return ((r & 0xff)<<24) + ((g & 0xff)<<16) + ((b & 0xff)<<8) + (a & 0xff);
}

rgb		new_rgb(value r, value g, value b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

rgba	str_to_rgba(char *str)
{
	char	i;
	rgba	color;

	i = 0;
	color = 0;
	while (i < 8)
	{
		if (*str >= '0' && *str <= '9')
			color += *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			color += *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			color += *str - 'A' + 10;
		else
			return (0);
		color <<= 4;
		str += 1;
		i += 1;
	}
	return (color);
}

rgb		str_to_rgb(char *str)
{
	char	i;
	rgb		color;

	i = 0;
	color = 0;
	while (i < 6)
	{
		if (*str >= '0' && *str <= '9')
			color += *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			color += *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			color += *str - 'A' + 10;
		else
			return (0);
		color <<= 4;
		str += 1;
		i += 1;
	}
	return (color);
}
