/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_tests.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:26:56 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 16:54:37 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <libasm.h>
#include <tests.h>

static int		one_strlen_test(const char *str)
{
	int			ret1;
	int			ret2;
	static int	x = 1;

	ret1 = strlen(str);
	ret2 = ft_strlen(str);
	if (ret1 != ret2)
	{
		printf("ft_strlen test %d:"RED" Failure\n"NORMAL, x);
		printf("strlen: %d\n"
				"ft_strlen: %d\n", ret1, ret2);
		printf("\n\n");
		return (1);
	}
	else
		printf("ft_strlen test %d:"GREEN" Success\n"NORMAL, x);
	x++;
	return (0);
}

int				strlen_tests(void)
{
	printf(MAGENTA"ft_strlen tests\n-------------------------------------\n"
			NORMAL);
	if (one_strlen_test("tests/texts/darth_plagueis.txt"))
		return (1);
	if (one_strlen_test(""))
		return (1);
	if (one_strlen_test("afjewfjjkaeshgdsjgklvadjsklgvnadsklgjadklsgja"
				"dsjkfkrslajflasnfjkesnfklesjfklesfklnesklvnsrklvnrkl"
				"safjklenfkaenjknasfnjkasfnjkasnveklasfklsamacklnae"
				"ksafjeaklfjleksjvklsnvansklvnaeklvneklsnveklsnveksv"
				"klsjveklsjfkldsnvkldnsvklnseklvnesknv"))
		return (1);
	if (one_strlen_test("Water. Earth. Fire. Air."
				"Long ago, the four nations lived together in harmony. Then, "
				"everything changed when the Fire Nation attacked. Only the "
				"Avatar, master of all four elements, could stop them,"
				" but when the world needed him most, he vanished. A hundred "
				"years passed and my brother "
				"and I discovered the new Avatar, an airbender named Aang, and "
				"although his airbending skills are great, he has a lot to "
				"learn before he's ready to save anyone. But I believe Aang "
				"can save the world."))
		return (1);
	printf("\n\n");
	return (0);
}
