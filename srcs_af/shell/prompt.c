/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:38:33 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/07 14:27:08 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	update_prompt(t_shell *shell)
{
	char	*new_prompt;

	new_prompt = ft_calloc(PATH_MAX + 1, sizeof(char));
	if (new_prompt == NULL)
		return ;
	if (getcwd(new_prompt, PATH_MAX) != NULL)
	{
		new_prompt = ft_append_str("\033[1;34m welcome to MyMinishell:$> \033[0m",
				new_prompt, FALSE, FALSE);
	}
	else
	{
		free(new_prompt);
		return ;
	}
	free(shell->prompt);
	shell->prompt = new_prompt;
}
