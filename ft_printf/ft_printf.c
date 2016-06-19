#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	arg_process(char **ptr, va_list *ap)
{
	while (extract_flags(**ptr))
		*ptr += 1;
	*ptr += extract_width(**ptr);
	*ptr += extract_precision(**ptr);
	*ptr += extract_length(**ptr);
	if (extract_specifier(**ptr) == 0)
		return (0);
	ap = NULL;
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
			len += arg_process(&(ptr2 + 1), ap);
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
