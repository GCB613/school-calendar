#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TimeChecker.h"
#include "SchoolSettings.h"
#include <memory>

using namespace testing;

class TimeCheckerTest : public Test
{
public:
	void SetUp() final
	{
		schoolSettings = std::make_unique<SchoolSettings>();
		timeChecker = std::make_unique<TimeChecker>(schoolSettings.get());
	}

	std::unique_ptr<SchoolSettings> schoolSettings = nullptr;
	std::unique_ptr<TimeChecker> timeChecker = nullptr;
};

TEST_F(TimeCheckerTest, checkTimeStamp)
{
	EXPECT_TRUE(timeChecker->schoolIsInSession(1736960400)); // 2025-01-15T12:00:00 EST
}
