/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:15:52 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/13 14:03:12 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*a_dest;
	const unsigned char	*a_src;

	a_dest = (unsigned char *)dest;
	a_src = (const unsigned char *)src;
	if ((n == 0) || dest == src)
		return (dest);
	while (n != 0)
	{
		*(a_dest++) = *(a_src++);
		--n;
	}
	return (dest);
}

/*
** free a double pointer
*/
static char	**get_free(char **s)
{
	int	i;

	i = 0;
	if (!*s || !s)
		return (NULL);
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

/*
** Count the number of word
*/
static int	get_n_word(char *s, char c)
{
	int	m;

	m = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
		{
			++m;
			while (*s && *s != c)
				++s;
		}
	}
	return (m);
}

/*
** Malloc the right size
*/
static char	*get_mem(char *s, char c)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
	{
		free(dup);
		return (NULL);
	}
	else
		ft_memcpy(dup, (char *)s, (i + 1));
	dup[i] = '\0';
	return (dup);
}

/*
** Split
*/
char	**ft_split(char *s, char c)
{
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (get_n_word((char *)s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
		{
			split[i] = get_mem(s, c);
			if (!split[i])
				return (get_free(split));
			++i;
			while (*s && *s != c)
				++s;
		}
	}
	split[i] = 0;
	return (split);
}
