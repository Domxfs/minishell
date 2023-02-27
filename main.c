/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domy <domy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:42:52 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/27 13:06:34 by domy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *search_in_envp(char **envp, char *str)
{
	int i;
	int j;
	int x;
	int stemp;
	char *tmp;
	int c;

	c = 0; 
	stemp = 0;
	i = 0;
	x = 0;
	j = 0;
	tmp = malloc(1000000);
	while (str[x] != '=')
		x++;
	x++;
	while (envp[i])
	{
		while (envp[i][j] == str[j])
		{
			c++;
			j++;
		}
		if (c == x)
		{
			while (envp[i][j] != '\0')
			{
				tmp[stemp] = envp[i][j];
				stemp++;
				j++;
			}
			tmp[stemp] = '\0';
			return (tmp);
		}
		else
		{
			c = 0;
			j = 0;
		}
		i++;
	}
	return (tmp);
}

void initstruct(t_data *data)
{
	data->path = malloc(1000000);
	data->mat = malloc(1000000);
	data->ascii = malloc(1000000);
}

// void ignore_signal(t_data *data)
// {
// 	data->signalset = true;
	
// 	signal(SIGINT, SIG_IGN);
// 	signal(SIGTSTP, SIG_IGN);
// 	signal(SIGQUIT, SIG_IGN);
// }

int main(int ac, char **av, char **envp)
{
	t_data data;

	initstruct(&data);
	// ignore_signal(&data);
	display_prompt(&data);
	firtpars(data, envp);
		
    return 0;
}


void firtpars(t_data data, char **envp)
{
	 while (data.end != 0)
	{
		data.input = readline("$ ");
		if (data.input == NULL)
		{
			//scrivi errore
			break;
		}
		if (ft_strlen(data.input) > 0)
			add_history(data.input);
		if (ft_strlen(data.input) == 0)
			continue;
		parsecomm(&data, envp);
		free(data.input);
	}
}