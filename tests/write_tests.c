/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_tests.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:22:33 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 16:54:56 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <libasm.h>
#include <tests.h>

static int		compare_files(FILE *f1, FILE *f2, int *line, int *col)
{
	char	ch1;
	char	ch2;

	*line = 1;
	*col = 0;

	ch1 = 'a';
	ch2 = 'a';
	while (ch1 != EOF && ch2 != EOF)
	{
		ch1 = fgetc(f1);
		ch2 = fgetc(f2);

		if (ch1 == '\n')
		{
			*line += 1;
			*col = 0;
		}
		if (ch1 != ch2)
			return (-1);
		*col += 1;
	}
	if (ch1 == EOF && ch2 == EOF)
		return (0);
	else
		return (-1);
}

int				one_write_test(const char *str)
{
	int			fd;
	int			fd2;
	FILE		*file1;
	FILE		*file2;
	int			line;
	int			col;
	int			ret1;
	int			ret2;
	static int	x = 1;

	fd = open("tmpfile1", O_WRONLY | O_CREAT, 0644);
	fd2 = open("tmpfile2", O_WRONLY | O_CREAT, 0644);
	ret1 = write(fd, str, strlen(str));
	ret2 = ft_write(fd2, str, strlen(str));
	file1 = fopen("tmpfile1", "r");
	file2 = fopen("tmpfile2", "r");
	if (compare_files(file1, file2, &line, &col) == -1 ||
			ret1 != ret2)
	{
		printf("ft_write test %d:"RED" Failure\n"NORMAL, x);
		close(fd);
		close(fd2);
		remove("tmpfile1");
		remove("tmpfile1");
		return (1);
	}
	else
		printf("ft_write test %d:"GREEN" Success\n"NORMAL, x);
	x++;
	close(fd);
	close(fd2);
	remove("tmpfile1");
	remove("tmpfile2");
	return (0);
}

int		write_tests(void)
{
	printf(MAGENTA"ft_write tests\n-------------------------------------\n"
			NORMAL);
	if (one_write_test("What to write\n"))
		return (1);
	if (one_write_test("A really long		 an really weird"
				"string that spansMULTIPLE lines"
				"and has some \n\nnewlines and tabs and %%%%%%%%other things"
				"in it too"))
		return (1);
	if (one_write_test(""))
		return (1);
	printf("\n\n");
	return (0);
}
