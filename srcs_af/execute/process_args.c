#include "../include/minishell.h"

char	*get_processed_quotes(t_shell *shell, char *arg, size_t len, size_t *i)
{
	char	*res;
	char	quote;

	res = NULL;
	quote = arg[*i];
	(*i)++;
	while (*i < len && arg[*i] != quote)
	{
		if (arg[*i] == '$' && quote == '\"' && (ft_isalnum(arg[*i + 1]) || arg[*i + 1] == '?'))
			res = ft_append_env_var_to_str(shell, res, get_env_var_name(arg, len, *i));
		if (arg[*i] != quote)
			res = ft_append_char_to_str(res, arg[*i]);
		(*i)++;
	}
	(*i)++;
	return (res);
}

char	*get_processed_arg(t_shell *shell, char *arg)
{
	char	*processed;
	size_t	len;
	size_t	i;

	processed = NULL;
	len = ft_strlen(arg);
	i = 0;
	while (i < len)
	{
		if (arg[i] == '\'' || arg[i] == '\"')
			processed = ft_append_str(processed, get_processed_quotes(shell, arg, len, &i), TRUE, TRUE);
		else if (arg[i] == '$' && (ft_isalnum(arg[i + 1]) || arg[i + 1] == '?'))
			processed = ft_append_env_var_to_str(shell, processed, get_env_var_name(arg, len, &i));
		else
		{
			processed = ft_append_char_to_str(processed, arg[i]);
			i++;
		}
	}
	return (processed);
}