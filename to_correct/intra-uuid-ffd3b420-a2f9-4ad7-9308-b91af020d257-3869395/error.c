/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:10:42 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/01 10:19:35 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

bool	put_error(char *program, char *part1, char *part2)
{
	ft_putstr_fd(program, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(part1, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(part2, 2);
	return (FALSE);
}
