#include "../inc/header.h"

int check_args(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (!ft_isaldigit(argv[i]))
		{
			ft_putstr_fd("checker: error with the given argument(s).\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (check_args(argc, argv))
	{
		return (1);
	}
	return (0);
}