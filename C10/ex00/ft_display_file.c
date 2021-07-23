#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		file;
	char	c;

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		file = open(argv[1], O_RDONLY);
		if (file < 1)
			write(2, "Cannot read file.\n", 18);
		else
			while (read(file, &c, 1) > 0)
				write(1, &c, 1);
		close(file);
	}
	return (0);
}
