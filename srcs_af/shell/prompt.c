/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:38:33 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/24 10:26:45 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_prompt(t_shell *shell)
{
	char	*new_prompt;

	new_prompt = ft_calloc(PATH_MAX + 1, sizeof(char));
	if (new_prompt == NULL)
		return ;
	if (getcwd(new_prompt, PATH_MAX) == NULL)		// getcwd = get current working directory
	{
		free(new_prompt);
		return ;
	}
	new_prompt = ft_append_str("\033[1;32m", new_prompt, FALSE, TRUE);
	new_prompt = ft_append_str(new_prompt, " \033[0;35m> \033[0m", TRUE, FALSE);
	free(shell->prompt);
	shell->prompt = new_prompt;
}
