char	*ft_strcpy(char *dst, const char *src)
{
	char	*cp;

	cp = dst;
	while ((*cp++ = *src++))
		;
	return (dst);
}
