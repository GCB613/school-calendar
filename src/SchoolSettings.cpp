#include "SchoolSettings.h"

std::string SchoolSettings::getPosixTimeZone() const
{
	return "EST-05:00:00EDT+01:00:00,M3.2.0/02:00:00,M11.1.0/02:00:00";
}

std::vector<int> SchoolSettings::getWeekends() const
{
	std::vector<int> weekends;
	weekends.push_back(0);
	weekends.push_back(6);
	return weekends;
}

std::vector<int> SchoolSettings::getHolidays() const
{
	std::vector<int> holidays;
	holidays.push_back(20250101);
	holidays.push_back(20250120);
	holidays.push_back(20250217);
	holidays.push_back(20250526);
	holidays.push_back(20250616);
	holidays.push_back(20250704);
	holidays.push_back(20250901);
	holidays.push_back(20251013);
	holidays.push_back(20251111);
	holidays.push_back(20251127);
	holidays.push_back(20251225);
	return holidays;
}

int SchoolSettings::getStartTime() const
{
	return 930;
}

int SchoolSettings::getEndTime() const
{
	return 1415;
}
