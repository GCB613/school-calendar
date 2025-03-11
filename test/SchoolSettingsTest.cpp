#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "SchoolSettings.h"
#include <memory>

using namespace testing;

class SchoolSettingsTest : public Test
{
public:
	void SetUp() final
	{
		schoolSettings = std::make_unique<SchoolSettings>();
	}

	std::unique_ptr<SchoolSettings> schoolSettings = nullptr;
};

TEST_F(SchoolSettingsTest, getPosixTimeZone)
{
	EXPECT_EQ(schoolSettings->getPosixTimeZone(), "EST-05:00:00EDT+01:00:00,M3.2.0/02:00:00,M11.1.0/02:00:00");
}

TEST_F(SchoolSettingsTest, getWeekends)
{
	auto weekends = schoolSettings->getWeekends();
	ASSERT_EQ(weekends.size(), 2ull);
	EXPECT_EQ(weekends.at(0), 0);
	EXPECT_EQ(weekends.at(1), 6);
}

TEST_F(SchoolSettingsTest, getHolidays)
{
	auto weekends = schoolSettings->getHolidays();
	ASSERT_EQ(weekends.size(), 11ull);
	EXPECT_EQ(weekends.at(0), 20250101); // New Year's Day
	EXPECT_EQ(weekends.at(1), 20250120); // Martin Luther King Jr. Day
	EXPECT_EQ(weekends.at(2), 20250217); // President's Day
	EXPECT_EQ(weekends.at(3), 20250526); // Memorial Day
	EXPECT_EQ(weekends.at(4), 20250616); // Juneteenth
	EXPECT_EQ(weekends.at(5), 20250704); // Independence Day
	EXPECT_EQ(weekends.at(6), 20250901); // Labor Day
	EXPECT_EQ(weekends.at(7), 20251013); // Columbus Day
	EXPECT_EQ(weekends.at(8), 20251111); // Veterans Day
	EXPECT_EQ(weekends.at(9), 20251127); // Thanksgiving Day
	EXPECT_EQ(weekends.at(10), 20251225); // Christmas Day
}

TEST_F(SchoolSettingsTest, getStartTime)
{
	EXPECT_EQ(schoolSettings->getStartTime(), 930);
}

TEST_F(SchoolSettingsTest, getEndTime)
{
	EXPECT_EQ(schoolSettings->getEndTime(), 1415);
}
