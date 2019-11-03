/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:48:37 by audumont          #+#    #+#             */
/*   Updated: 2019/10/27 11:38:01 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

static int				ft_count(char *str, char c)
{
	int					count;
	int					is_word;
	int					index;

	index = 0;
	count = 0;
	is_word = 0;
	while (str[index])
	{
		if (!is_word && str[index] != c)
		{
			count++;
			is_word = 1;
		}
		else if (is_word && str[index] == c)
			is_word = 0;
		index++;
	}
	return (count);
}

static int				ft_index(char *str, char c, unsigned int index)
{
	int					isword;
	unsigned int		count;
	unsigned int		pos;

	isword = 0;
	count = 0;
	pos = 0;
	while (str[pos])
	{
		if (!isword && str[pos] != c)
		{
			count++;
			if (count == index + 1)
				break ;
			isword = 1;
		}
		else if (isword && str[pos] == c)
			isword = 0;
		pos++;
	}
	return (pos);
}

static char				*ft_word(char *str, char c)
{
	unsigned int		index;
	unsigned int		len;
	char				*word;

	len = 0;
	index = 0;
	while (str[len] && str[len] != c)
		len++;
	word = (char*)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	while (index < len)
		word[index++] = *str++;
	word[index] = '\0';
	return (word);
}

static void				ft_free(char **words, int index)
{
	int					index2;

	index2 = 0;
	while (index2 < index)
	{
		free(words[index2]);
		index2++;
	}
	free(words);
}

char					**ft_split(const char *s, char c)
{
	unsigned int		count_words;
	char				**words;
	unsigned int		index;
	char				*word;

	if (!s)
		return (0);
	count_words = ft_count((char*)s, c);
	word = (char*)s;
	words = (char**)malloc(sizeof(char *) * (count_words + 1));
	if (!words)
		return (0);
	index = 0;
	while (index < count_words)
	{
		words[index] = ft_word(word + ft_index(word, c, index), c);
		if (!words[index])
		{
			ft_free(words, index);
			return (0);
		}
		index++;
	}
	words[index] = 0;
	return (words);
}
