/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:27:14 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/19 22:43:25 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

// client.c functions
void	validation(int ac, char **av);
void	send_bit(int srv_pid, char c);

// server.c functions
void	which_signal(int sig, siginfo_t *siginfo, void *context);


#endif