#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

static int	arg_process(char **ptr, va_list *ap)
{
	t_arg	arg = {};
	int		i;

	arg.specifier = NULL;
	*ptr += extract_flags(*ptr, &arg);
	*ptr += extract_width(*ptr, &arg);
	*ptr += extract_precision(*ptr, &arg);
	*ptr += extract_length(*ptr, &arg);
	if (**ptr == '%')
		return (write(1, *ptr, 1));
	arg.len = extract_specifier(*ptr, &arg, ap);
	if (arg.len == 0)
		return (0);
	i = print_arg(&arg);
	free(arg.specifier);
	return (i);
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
			write(1, ptr1, ptr2++ - ptr1);
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
