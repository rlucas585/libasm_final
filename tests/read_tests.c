/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_tests.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:26:56 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 16:55:06 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <libasm.h>
#include <tests.h>

static int		one_read_test(const char *filename)
{
	int			fd;
	int			fd2;
	char		buf1[150];
	char		buf2[150];
	int			ret1;
	int			ret2;
	static int	x = 1;

	fd = open(filename, O_RDONLY, 0644);	
	ret1 = read(fd, buf1, 149);
	buf1[ret1] = '\0';
	close(fd);
	fd2 = open(filename, O_RDONLY, 0644);	
	ret2 = read(fd, buf2, 149);
	buf2[ret2] = '\0';
	close(fd2);
	if (strcmp(buf1, buf2) || ret1 != ret2)
	{
		printf("ft_read test %d:"RED" Failure\n"NORMAL, x);
		printf("read: %s\n"
				"ft_read: %s\n", buf1, buf2);
		printf("\n\n");
		return (1);
	}
	else
		printf("ft_read test %d:"GREEN" Success\n"NORMAL, x);
	x++;
	return (0);
}

int				read_tests(void)
{
	printf(MAGENTA"ft_read tests\n-------------------------------------\n"
			NORMAL);
	if (one_read_test("tests/texts/darth_plagueis.txt"))
		return (1);
	if (one_read_test("tests/texts/testread.txt"))
		return (1);
	if (one_read_test("notafilename.txt"))
		return (1);
	if (one_read_test("tests/texts/empty.txt"))
		return (1);
	printf("\n\n");
	return (0);
}
