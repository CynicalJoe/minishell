#include <readline/readline.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	**parse_commands(char **line)
{
	
}

void	lsh_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	while (1)
	{
		line = readline("🐘 esh >");
		printf("%s\n", line);
		args = parse_commands(line);
		//status = lsh_execute(args);

		//free(line);
		//free(args);
		if (!status)
			break ;
	}
}


int	main(int ac, char **av, char **env)
{
	// load config files if any

	// run our command loop
	lsh_loop();

	// Perform any shutdown and clean up
	
	return (EXIT_SUCCESS);
}