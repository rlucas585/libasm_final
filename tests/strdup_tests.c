/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strdup_tests.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 17:02:41 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 17:09:16 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <libasm.h>
#include <tests.h>

static int		one_strdup_test(const char *str)
{
	char		*ret1;
	char		*ret2;
	static int	x = 1;

	ret1 = strdup(str);
	ret2 = ft_strdup(str);
	if (strcmp(ret1, ret2))
	{
		printf("ft_strdup test %d:"RED" Failure\n"NORMAL, x);
		printf("strdup: %s\n"
				"ft_strdup: %s\n", ret1, ret2);
		printf("\n\n");
		free(ret1);
		free(ret2);
		return (1);
	}
	else
		printf("ft_strdup test %d:"GREEN" Success\n"NORMAL, x);
	x++;
	free(ret1);
	free(ret2);
	return (0);
}

int				strdup_tests(void)
{
	printf(MAGENTA"ft_strdup tests\n-------------------------------------\n"
			NORMAL);
	if (one_strdup_test("test string 1"))
		return (1);
	if (one_strdup_test(""))
		return (1);
	if (one_strdup_test("sdlkfjaklfjaklfaknvavjkadsfkadsfkljasklcjaesklja"
				"kajsklfejkfvaklsjvklaejklaesjfklejfklaejfklejklfj"))
		return (1);
	printf("\n\n");
	return (0);
}

