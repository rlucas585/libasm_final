/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcmp_tests.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:56:33 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 17:04:01 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <libasm.h>
#include <tests.h>

static int		one_strcmp_test(const char *str1, const char *str2)
{
	int			ret1;
	int			ret2;
	static int	x = 1;

	ret1 = strcmp(str1, str2);
	ret2 = ft_strcmp(str1, str2);
	if (ret1 != ret2)
	{
		printf("ft_strcmp test %d:"RED" Failure\n"NORMAL, x);
		printf("strcmp: %d\n"
				"ft_strcmp: %d\n", ret1, ret2);
		printf("\n\n");
		return (1);
	}
	else
		printf("ft_strcmp test %d:"GREEN" Success\n"NORMAL, x);
	x++;
	return (0);
}

int				strcmp_tests(void)
{
	printf(MAGENTA"ft_strcmp tests\n-------------------------------------\n"
			NORMAL);
	if (one_strcmp_test("", "hello"))
		return (1);
	if (one_strcmp_test("afhakjgklajgklsj", "afhakjgklajgklsj"))
		return (1);
	if (one_strcmp_test("Test", "Rest"))
		return (1);
	if (one_strcmp_test("Best", "Rest"))
		return (1);
	if (one_strcmp_test("Fest", "Fest"))
		return (1);
	if (one_strcmp_test("Boom, you looking for this?",
				"Boom, you looking for that?"))
		return (1);
	printf("\n\n");
	return (0);
}

