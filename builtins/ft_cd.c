/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:08:19 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/06 16:03:29 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_cd(char *args)
{
	char	*env_path;
	int		cd_ret;

	if (!args || (ft_strcmp(args, "~") == 0))
		env_path = getenv("HOME");
	else if (ft_strcmp(args, "-") == 0)
		env_path = getenv("OLDPWD");
	else
		env_path = args;
	if (!env_path)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(args, 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (1);
	}
	cd_ret = chdir(env_path);
	if (cd_ret < 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(args, 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (1);
	}
	return (0);
}