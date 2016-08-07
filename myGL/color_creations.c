#include "myGL.h"

rgba	new_rgba(value r, value g, value b, value a)
{
	return ((r & 0xff)<<24) + ((g & 0xff)<<16) + ((b & 0xff)<<8) + (a & 0xff);
}

rgb		new_rgb(value r, value g, value b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}
