#include "myLib.h"
#include <fcntl.h>
#include <unistd.h>

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("../Fdf/test_maps/42.fdf", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		ft_printf("%s\n", line);
	return (0);
}
