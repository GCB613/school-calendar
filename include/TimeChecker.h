#pragma once
#ifndef SCHOOL_CALENDAR_TIME_CHECKER_H
#define SCHOOL_CALENDAR_TIME_CHECKER_H

#include <vector>
#include <string>

class SchoolSettings;

class TimeChecker
{
public:
	TimeChecker(SchoolSettings* schoolSettings)
		: m_schoolSettings(schoolSettings) {}

	bool schoolIsInSession(time_t epoch) const;

private:
	SchoolSettings* m_schoolSettings = nullptr;
};

#endif//SCHOOL_CALENDAR_TIME_CHECKER_H
