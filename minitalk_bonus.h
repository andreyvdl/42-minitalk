/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:44:47 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/23 15:47:37 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

// client_bonus.c functions
void	received(int sig);
void	validation(int ac, char **av);
void	send_bit(int srv_pid, char c);

// server_bonus.c functions
void	which_signal(int sig, siginfo_t *siginfo, void *context);

#endif