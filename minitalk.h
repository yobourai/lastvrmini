/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:30:19 by yobourai          #+#    #+#             */
/*   Updated: 2024/09/05 22:08:18 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
char	*ft_bin(int a);
void	ft_send_signal(char *pid, char *s);
void	ft_handler(int sig, siginfo_t *info, void *context);
int		ft_power(unsigned int a, unsigned int b);
int		ascii(char *str);
void	ft_putchar(char c);

#endif
