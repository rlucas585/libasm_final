/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nocrit_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 13:36:52 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 17:07:20 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <libasm.h>
#include <tests.h>

int		main(void)
{
	if (write_tests())
		return (1);
	if (read_tests())
		return (1);
	if (strlen_tests())
		return (1);
	if (strcpy_tests())
		return (1);
	if (strcmp_tests())
		return (1);
	if (strdup_tests())
		return (1);
	return (0);
}
