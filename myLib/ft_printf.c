#include "mylib.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_putchar(char const c)
{
	write(1, &c, 1);
	return (1);
}

static int	arg_process(char **ptr, va_list *ap)
{
	*ptr += 1;
	if (**ptr == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (**ptr == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (**ptr == 'd')
		return (ft_putnbr(va_arg(*ap, int)));
	if (**ptr == 'f')
		return (ft_putfloat(va_arg(*ap, double)));
	if (**ptr == '%')
		return (ft_putchar('%'));
	*ptr -= 1;
	return (0);
}

static int	analyse(char const *format, va_list *ap)
{
	int			len;
	char		*ptr1;
	char		*ptr2;

	len = 0;
	ptr1 = (char *)format;
	ptr2 = (char *)format;
	while (*ptr2 != '\0')
	{
		if (*ptr2 == '%')
		{
			write(1, ptr1, ptr2 - ptr1);
			len += arg_process(&ptr2, ap);
			ptr1 = ++ptr2;
		}
		else
		{
			len += 1;
			ptr2 += 1;
		}
	}
	write(1, ptr1, ptr2 - ptr1);
	return (len);
}

int		ft_printf(char const * restrict format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = analyse(format, &ap);
	va_end(ap);
	return (len);
}
