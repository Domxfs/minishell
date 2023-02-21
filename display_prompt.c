/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domy <domy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:25:00 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/21 15:49:16 by domy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    init_prompt(void)
{
    char    cwd[1024];
    char    *username = getenv("USER");
    char    computername[1024];
    
    if (username != NULL)
        printf("\033[0;31m%s@\033[0m", username);
    if (gethostname(computername, 1024) == 0)
        printf("\033[0;31m%s\033[0m:", computername);
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("\033[0;33m~%s\033[0m", &cwd[12]);   
    return ; 
}

void    display_prompt(t_data *data)
{
    char *input;
    char    **tmp;
    int i;
	int x;
	int ascii;
    
    i = 0;
	x = 0;
    init_prompt();
    input = readline("$ ");
	add_history(input);
	splitting(data, input);
    // check_heredocs(data);
	while (data->mat[i])
	{
		printf("%s   \n", data->mat[i]);
		i++;
	}
    free(input);
    return ;
}

// void check_heredocs(t_data *data)
// {
//     int i;
//     int x;

//     i = 0;
//     while (data->pipe_mat[i])
// 	{
// 		while (data->pipe_mat[i][x] != "<")
// 			x++;
// 		if (data->pipe_mat[i][x] == "<" && data->pipe_mat[i][x + 1] == "<")
// 		{
			
// 		}
// 	}
// }

