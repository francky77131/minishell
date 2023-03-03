/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 02:51:46 by nbled             #+#    #+#             */
/*   Updated: 2023/03/03 06:09:04 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (NULL);
	while (str[i])
	{

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

void	get_token_sign(t_pile *start)
{
	start->token = WORD;
	if (ft_strstr(start->str, "|") != NULL)
		start->token = PIPE;
	else if (ft_strstr(start->str, ">>") != NULL)
		start->token = RGT_HRDC;
	else if (ft_strstr(start->str, "<<") != NULL)
		start->token = LFT_HRDC;
	else if (ft_strstr(start->str, "<") != NULL)
		start->token = LFT_RDIR;
	else if (ft_strstr(start->str, ">") != NULL)
		start->token = RGT_RDIR;
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	get_token(t_pile *start)
{
	t_pile	*tmp;

	tmp = start;
	while (start)
	{
		get_token_sign(start);
		start = start->next;
	}
	start = tmp;
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
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
		if (str[0] && quote_check(str) == 0)
		{
			splited = ft_split(str);
			start = ft_lstnew(0, splited[0]);
			while (i < ft_count_words(str))
			{
				tmp = ft_lstnew(i, splited[i]);
				ft_lstadd_back(&start, tmp);
				i++;
			}
			get_token(start);
			char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL) 
	{
		printf("Le répertoire de travail actuel est : %s\n", cwd);
	}
	else
	{
		perror("Erreur lors de l'appel à getcwd()");
		return 1;
	}
			tmp = start;
			while (tmp)
			{
				printf("maillon "RED"%d = %s Token = %d\n"END, tmp->value, tmp->str, tmp->token);
				tmp = tmp->next;
			}
			ft_lstclear(start);
		}
	}
}

//pour env juste a recuperer l'env du main et a l'ecrire en entier si on entre la commande env dans minishell
//fonction get_env pour recuperer la valeur d'une variable avec le $PATH par ex

//echo est a coder juste avec un printf(blabla...\n) et un printf(blabla...) avec le flag -n qui retire le \n

// int main() 
//{
	// if (getcwd(cwd, sizeof(cwd)) != NULL) 
	// {
	// 	printf("Le répertoire de travail actuel est : %s\n", cwd);
	// }
	// else
	// {
	// 	perror("Erreur lors de l'appel à getcwd()");
	// 	return 1;
	// }
// }

// int main()
// {
// 	if (chdir("/chemin/vers/nouveau/repertoire") == 0) //lui mettre un chemin en utilisant la fonction au dessus avec le pwd
// 	{
// 		printf("Le répertoire de travail actuel a été changé.\n");
// 	}
// 	else
// 	{
// 		perror("Erreur lors de l'appel à chdir()");
// 		return 1;
// 	}
// 	return 0;
// }

//si str[0] = '$' alors je free str et je le remalloc a la taille de la var d'env