/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:53:43 by macbook           #+#    #+#             */
/*   Updated: 2020/04/30 16:11:23 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>

void	ft_bzero(void *s, size_t n);
char	*ft_c_to_str(char type);
size_t	ft_intlen_base(unsigned long int nb, char *base);
char	*ft_itoa_base(unsigned long int nb, char *base);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putstr(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlcpy(char *str, const char *src, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strdup(const char *str);

#endif
