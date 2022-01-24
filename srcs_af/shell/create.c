/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:13:36 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/24 12:49:48 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
// create the Shell struct extracting the vars from the env variables and macros
t_shell create_shell(char **env)
{
	t_shell	shell;

	shell.env = create_env(env);
	shell.prompt = NULL;
	set_env(&shell, "PWD", getcwd(NULL, 0), 1);		//defined
	update_prompt(&shell);
	init_container(&shell.cmd_container);
	shell.in_exec = 0;
	return(shell);
}
