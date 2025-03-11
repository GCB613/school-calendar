#include <iostream>
#include <chrono>
#include <string>
#include "TimeChecker.h"
#include "SchoolSettings.h"

namespace
{
	time_t getEpoch()
	{
		return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	}

	std::string timeString(time_t epoch)
	{
		struct tm* timeinfo;
		timeinfo = localtime(&epoch);

		int year = timeinfo->tm_year + 1900;
		int month = timeinfo->tm_mon + 1;
		int day = timeinfo->tm_mday;
		int hour = timeinfo->tm_hour;
		int minute = timeinfo->tm_min;
		int second = timeinfo->tm_sec;

		char buffer[64];
		sprintf(buffer, "%04d-%02d-%02dT%02d:%02d:%02d", year, month, day, hour, minute, second);
		std::string text(buffer);
		return text;
	}

	time_t stringToTime(const std::string& str)
	{
		try
		{
			return std::stoll(str);
		}
		catch (...)
		{
			return 0;
		}
	}
}

int main()
{
	auto schoolSettings = std::make_unique<SchoolSettings>();
	auto timeChecker = std::make_unique<TimeChecker>(schoolSettings.get());

	while (true)
	{
		std::cout << "School Calendar\n";
		std::cout << "1. Check current time\n";
		std::cout << "2. Check epoch time\n";
		std::cout << "Select Option (-1 to exit): ";

		std::string input;
		std::getline(std::cin, input);

		if (input == "-1")
			break;
		else if (input == "1")
		{
			auto epoch = getEpoch();
			std::cout << "Current time: " << timeString(epoch) << " is " << std::string(timeChecker->schoolIsInSession(epoch) ? "IN" : "NOT IN") << "\n";
		}
		else if (input == "2")
		{
			std::cout << "Epoch Time: ";
			std::string timeInput;
			std::getline(std::cin, timeInput);
			time_t epoch = stringToTime(timeInput);
			std::cout << "Current time: " << timeString(epoch) << " is " << std::string(timeChecker->schoolIsInSession(epoch) ? "IN" : "NOT IN") << "\n";
		}
		else
			std::cout << "Unknown option\n";

		std::cout << "\n";
	}

	std::cout << "Good bye!\n";

	return 0;
}
