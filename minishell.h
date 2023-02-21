/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domy <domy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:30:17 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/21 15:49:02 by domy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <sys/wait.h>

int	g_exit_status;

typedef struct s_data
{
    char	*path;
    char	**mat;
    int		*ascii;
	int		ascii_s;
    bool	signalset;
}				t_data;


void    display_prompt(t_data *data);
void    init_prompt(void);
int		ft_cd(char *args);
void    ft_echo(char *args, int i, int j);
void    adjustmat(t_data *data);
int		check_ascii(t_data *data, char *input);
char	*sost_space(t_data *data, char *input);
void	re_sost_space(t_data *data);
void	splitting(t_data *data, char *input);


#endif