#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int ac, char **av)
{
	time_t	t;
	int		min = (av[2]) ? atoi(av[2]) : 0;
	int		max = (av[3]) ? atoi(av[3]) : 1000;
	long	n = (long)RAND_MAX;
	printf("min: %d max: %d\n", min, max);
	srand((unsigned) time(&t));
	for(int i = 0; i < atoi(av[1]); i++)
	{
		while (n * (max - min) / s
		n = (long)rand();
		if (rand() * max /)
		printf("%d\n", (int)((double)rand() * (double)(max) / (double)(max)) + min);
	}
	return(0);
}
