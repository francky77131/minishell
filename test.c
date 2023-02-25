/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 02:51:46 by nbled             #+#    #+#             */
/*   Updated: 2023/02/23 06:31:20 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//donner des token a chque splitted.

char	*index_token(char *signe, char *s)
{
	int i;
	int len;
	
	i = 0;
	len = 0;
	while (s[len])
		len++;
	signe = malloc(sizeof(char) * len + 1);
	signe[0] = 'a';
	signe[1] = '\0';
	printf("%s\n", signe);
	return signe;
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (NULL);
	while (str[i])
	{
		printf("t\n");
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

char	**get_index_token(char **signe)
{
	int i;

	i = 0;
	signe[i] = index_token(signe[i], "o");
	i++;
	signe[i] = index_token(signe[i], "|");
	i++;
	signe[i] = index_token(signe[i], "<");
	i++;
	signe[i] = index_token(signe[i], ">");
	return signe;
}

int	get_token(void)
{
	int i;
	char	**signe;
	int j;
	int size;
	
	i = 0;
	j = 0;
	size = 0;
	signe = malloc(sizeof(char *) * 5);
	if (!signe)
		return (1);
	signe = get_index_token(signe);
	//printf("%s\n", signe[1]);
	// while (start)
	// {
	// 	j = 0;
	// 	while (signe[j])
	// 	{
			// if (ft_strstr(splitted[i], signe[j]) != NULL)
			// {
				// printf("e\n");
				// if (start)
				// {
				// 	printf("a\n");
				// 	start->token = i;
				// 	start = start->next;
				// 	free(splitted);
				// 	free_split(signe);
				// 	break;
				// }
			// }
	// 		//printf("c\n");
	// 		j++;
	// 	}
	// 	i++;
	// }
	//free_split(signe);
	return (0);
}

int	main(void)
{
	t_pile	*start;
	t_pile	*tmp;
	char	**splited;
	char	*str;
	size_t	i;

	i = 0;
	while (1)
	{
		i = 1;
		str = readline(BLUE"minishell : "END);
		splited = ft_split(str, ' ');
		start = ft_lstnew(0, splited[0]);
		//get_token(start, splited);
		while (i < count_words(str, ' '))
		{
			tmp = ft_lstnew(0 , splited[i]);
			ft_lstadd_back(&start, tmp);
			i++;
		}

		get_token();
		tmp = start;
		while (tmp->next)
		{
			printf("maillon "RED"%d = %s\n"END, tmp->token, tmp->str);
			tmp = tmp->next;
		}
		printf("maillon "RED"%d = %s\n"END, tmp->token, tmp->str);
		ft_lstclear(start);
			
	}
}





























// int	main(int argc, char **argv)
// {
// 	t_pile	*start;
// 	t_pile	*tmp;
// 	int		i;

// 	i = 1;
// 	start = ft_lstnew(0, argv[0]);

// 	while (i < argc)
// 	{
// 		tmp = ft_lstnew(i, argv[i]);
// 		ft_lstadd_back(&start, tmp);
// 		i++;
// 	}

// 	tmp = start;
// 	while (tmp->next)
// 	{
// 		printf("maillon "RED"%d = %s\n"END, tmp->token, tmp->str);
// 		tmp = tmp->next;
// 	}
// 	printf("maillon "RED"%d = %s\n"END, tmp->token, tmp->str);

// 	while (tmp->prev)
// 	{
// 		printf("maillon "BLUE"%d = %s\n"END, tmp->token, tmp->str);
// 		tmp = tmp->prev;
// 	}
// 	printf("maillon "BLUE"%d = %s\n"END, tmp->token, tmp->str);

// 	ft_lstclear(start);
// }