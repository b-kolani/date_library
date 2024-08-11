#include "date.h"
#include <stdio.h>

void	test_is_leap_year(void)
{
	if (is_leap_year(2024))
		printf("Is a leap year.\n");
	else
		printf("Is not a leap year.\n");
}

void	test_create_date(void)
{
	Date	d;

	d = create_date(11, 8, 2024);
	printf("Created date: %d-%d-%d\n", d.day, d.month, d.year);
}

void	test_days_between(void)
{
	Date	d1;
	Date	d2;

	d1 = create_date(1, 1, 2024);
	d2 = create_date(11, 8, 2024);
	printf("Days between: %d\n", days_between(d1, d2));
}

void	test_add_days(void)
{
	Date	d;
	Date	new_date;

	d = create_date(1, 1, 2024);
	new_date = add_days(d, 30);
	printf("Date after adding 30 days: %d-%d-%d\n", new_date.day,
		new_date.month, new_date.year);
}

void	test_subtract_days(void)
{
	Date	d;
	Date	new_date;

	d = create_date(10, 8, 2024);
	new_date = subtract_days(d, 100);
	printf("Date after subtracting 100  days: %d-%d-%d\n", new_date.day,
		new_date.month, new_date.year);
}

int	main(void)
{
	test_is_leap_year();
	test_create_date();
	test_add_days();
	test_days_between();
	test_subtract_days();
	return (0);
}
