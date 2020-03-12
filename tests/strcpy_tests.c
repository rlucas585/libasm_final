/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcpy_tests.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:50:16 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 16:55:09 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <libasm.h>
#include <tests.h>

static int		one_strcpy_test(const char *str)
{
	char		*ret1;
	char		*ret2;
	char		buf1[150];
	char		buf2[150];
	static int	x = 1;

	ret1 = strcpy(buf1, str);
	ret2 = ft_strcpy(buf2, str);
	if (strcmp(ret1, ret2) || strcmp(buf1, buf2))
	{
		printf("ft_strcpy test %d:"RED" Failure\n"NORMAL, x);
		printf("strcpy: %s\n"
				"ft_strcpy: %s\n", ret1, ret2);
		printf("\n\n");
		return (1);
	}
	else
		printf("ft_strcpy test %d:"GREEN" Success\n"NORMAL, x);
	x++;
	return (0);
}

int				strcpy_tests(void)
{
	printf(MAGENTA"ft_strcpy tests\n-------------------------------------\n"
			NORMAL);
	if (one_strcpy_test("texttexttexttexttexttext"))
		return (1);
	if (one_strcpy_test(""))
		return (1);
	if (one_strcpy_test("gjasklrgfjaklsgjaklgjakl\n"))
		return (1);
	printf("\n\n");
	return (0);
}
