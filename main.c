#include "ft_pipex.h"

int	main(int argc, char **argv)
{
	if (argc < 5)
		ft_exit("To use, run: ./pipex file1 cmd1 cmd2 file2\n");
	ft_pipex(argc, argv);
}
