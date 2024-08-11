#ifndef DATE_H
#define DATE_H

/* Structure représentant une date.*/
typedef struct
{
    int day;
    int month;
    int year;
} Date;// Date est utilisé comme nouveau type ou un alias

/**
 * Cette fonction crée une nouvelle date.
 * */
Date create_date(int day, int month, int year);

/**
 * Cette fonction vérifie, si une année donnée
 * est bissextile ou pas. 
 */
int is_leap_year(int year);

/**
 * Renvoi le nombre de jours, entre deux dates
 */
int days_between(Date date1, Date date2);

/**
 * Ajoute des jours à une date donnée.
 */
Date add_days(Date date, int days);

/**
 * Soustraie des jours à une date donnée.
 */
Date subtract_days(Date date, int days);

#endif // !DATE_H
