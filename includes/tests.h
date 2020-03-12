/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:21:31 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 17:07:09 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# define RED "\e[91m"
# define GREEN "\e[32m"
# define MAGENTA "\e[35m"
# define BLUE "\e[34m"
# define NORMAL "\e[0m"

int		write_tests(void);
int		read_tests(void);
int		strlen_tests(void);
int		strcpy_tests(void);
int		strcmp_tests(void);
int		strdup_tests(void);

#endif
