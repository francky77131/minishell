/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:32:45 by nbled             #+#    #+#             */
/*   Updated: 2023/02/23 03:48:50 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RED     "\x1b[31;1m"
# define GREEN   "\x1b[32;1m"
# define YELLOW  "\x1b[33;1m"
# define BLUE    "\x1b[34;1m"
# define MAGENTA "\x1b[35;1m"
# define CYAN    "\x1b[36;1m"
# define END    "\x1b[0m"

# include <readline/readline.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <termios.h>


typedef enum token
{
	WORD,
	PIPE,
	LFT_RDIR,
	RGT_RDIR,
} 	e_token;

typedef struct s_pile
{
	int				token;
	char			*str;
	struct s_pile	*prev;
	struct s_pile	*next;
}					t_pile;

typedef struct s_struct
{
	int				nb_of_word;
}					t_struct;

t_pile	*ft_lstnew(int value, char *str);
void	ft_lstadd_back(t_pile **pile, t_pile *n);
size_t	ft_lstsize(t_pile *pile);
t_pile	*ft_lstlast(t_pile *pile);
void	ft_lstclear(t_pile *start);
char	**ft_split(const char *s, char c);
size_t	count_words(const char *s, char c);
size_t	sizeof_word(const char *s, char c);
void	free_split(char **args);

#endif
