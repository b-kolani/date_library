#include "date.h"

/**
 * Fonction locale (static), pour obtenir
 * le nombre de jours d'un mois donné.
 */
static int	days_in_month(int month, int year)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return (31);
	case 4:
	case 6:
	case 9:
	case 11:
		return (30);
	case 2:
		return is_leap_year(year) ? 29 : 28;
	default:
		return (0); // Mois invalide
	}
}

// Crée une nouvelle date.
Date	create_date(int day, int month, int year)
{
	Date	date;

	date.day = day;
	date.month = month;
	date.year = year;
	return (date);
}

// Vérifie si une année est bissextile.
int	is_leap_year(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Calcule le nombre de jours entre deux dates.
int	days_between(Date date1, Date date2)
{
	int		days;
	Date	temp;

	days = 0;
	temp = date1;
	while (temp.year < date2.year || (temp.year == date2.year
			&& temp.month < date2.month) || (temp.year == date2.year
			&& temp.month == date1.month && temp.day < date2.day))
	{
		days++;
		temp = add_days(temp, 1);
	}
	return (days);
}

// Ajoute des jours à une date
Date	add_days(Date date, int days)
{
	int	days_in_current_month;

	while (days > 0)
	{
		days_in_current_month = days_in_month(date.month, date.year);
		if (date.day + days > days_in_current_month)
		{
			days -= (days_in_current_month - date.day + 1);
			date.day = 1;
			if (date.month == 12)
			{
				date.month = 1;
				date.year++;
			}
			else
				date.month++;
		}
		else
		{
			date.day += days;
			days = 0;
		}
	}
	return (date);
}

// Soustrait des jours d'une date
Date	subtract_days(Date date, int days)
{
	while (days > 0)
	{
		if (date.day - days < 1)
		{
			days -= date.day;
			if (date.month == 1)
			{
				date.month = 12;
				date.year--;
			}
			else
				date.month--;
			date.day = days_in_month(date.month, date.year);
		}
		else
		{
			date.day -= days;
			days = 0;
		}
	}
	return (date);
}
