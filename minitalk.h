/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:27:14 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/17 17:23:46 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h> // getpid | write | pause | sleep | usleep
# include <signal.h> // signal | sigemptyset | sigaddset | sigaction | kill
# include <stdlib.h> // malloc | free | exit

// client.c functions
void	print_bit(int div);
void	send_bit(int pid, char c);

// server.c functions
void	add_one(int sig);
void	add_zero(int sig);

#endif