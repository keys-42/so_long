#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int	i;
	int	k;
	int	flag;

	flag = 0;
	i = 0;
	k = 0;
	while (k < 501)
	{
		write(1, "1", 1);
		k++;
	}
	write(1, "\n", 1);
	while (i < 250)
	{
		k = 0;
		if (i == 1)
		{
				write(1, "1", 1);
				write(1, "PC", 2);
			while (k < 247)
			{
				write(1, "00", 2);
				k++;
			}
				write(1, "E", 1);
				write(1, "1", 1);
				write(1, "1", 1);
		}
		else if(i%2 == 0)
		{
			while (k < 250)
			{
				write(1, "10", 2);
				k++;
			}
		}
		else
		{
				write(1, "11", 2);
			while (k < 249)
			{
				write(1, "01", 2);
				k++;
			}
		}
		write(1, "1", 1);
		write(1, "\n", 1);
		i++;
	}
	k = 0;
	while (k < 501)
	{
		write(1, "1", 1);
		k++;
	}
	write(1, "\n", 1);
	return (0);
}
