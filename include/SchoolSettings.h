#pragma once
#ifndef SCHOOL_CALENDAR_SCHOOL_SETTINGS_H
#define SCHOOL_CALENDAR_SCHOOL_SETTINGS_H

#include <vector>
#include <string>

/*
* class to simulate data that would be retrieved from a database
*/
class SchoolSettings
{
public:

	/*
	* get the timezone of the school in posix format
	*/
	std::string getPosixTimeZone() const;

	/*
	* get list of days that are considered weekends
	* 0 = Sunday
	* 1 = Monday
	* 2 = Tuesday
	* 3 = Wednesday
	* 4 = Thursday
	* 5 = Friday
	* 6 = Saturday
	*/
	std::vector<int> getWeekends() const;

	/*
	* get list of holidays
	* holidays are listed in format YYYYMMDD
	*/
	std::vector<int> getHolidays() const;

	/*
	* get the start time of the school day in military time
	* time is given in format HHMM
	*/
	int getStartTime() const;

	/*
	* get the end time of the school day in military time
	* time is given in format HHMM
	*/
	int getEndTime() const;
};

#endif//SCHOOL_CALENDAR_SCHOOL_SETTINGS_H
