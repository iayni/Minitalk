/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:24:07 by iayni             #+#    #+#             */
/*   Updated: 2022/02/28 16:42:04 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <time.h>

void	ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif