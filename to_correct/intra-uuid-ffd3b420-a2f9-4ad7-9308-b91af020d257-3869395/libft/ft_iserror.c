/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iserror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:35:29 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 14:30:19 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	is_error(char *str_1, char *str_2, char *err_msg, int exit_status)
{
	ft_putstr_fd("🤣 esh: ", STDERR_FILENO);
	if (str_1 != NULL)
		ft_putstr_fd(str_1, STDERR_FILENO);
	if (str_2 != NULL)
		ft_putstr_fd(str_2, STDERR_FILENO);
	if (err_msg != NULL)
		ft_putstr_fd(err_msg, STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	exit(exit_status);
}
