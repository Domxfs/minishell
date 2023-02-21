/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:16:40 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/07 13:31:37 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_echo(char *args, int i, int j)
{
    int quotes;
    int quote;
    char *tmp;

    quote = 0;
    quotes = 0;
    tmp = malloc(10000);

    while(args[++i])
    {
        if(args[i] == '\"' && quote % 2 == 0)
            quotes++;
        else if(args[i] == '\'' && quotes % 2 == 0)
            quote++;
        else if(args[i] == '\"' && quote % 2 == 1)
            tmp[j++] = args[i];
        else if(args[i] == '\'' && quotes % 2 == 1)
            tmp[j++] = args[i];
        else
            tmp[j++] = args[i];
    }
    tmp[j] = '\0';
    printf("%s", tmp);
    return ;
}
