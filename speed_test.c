#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	main(void)
{
	int i = 0;
	char **str;
	// while (i++ < 100000) // 0.658
	// 	write(1, "wass\n", 5);
	str = malloc(UINT_MAX);
	while (1 && i < UINT_MAX / sizeof(char*))
	{
		str[i] = malloc(100000);
		i++;
	}
	return (0);
}