#pragma once
#include <string>
#include <vector>

#ifndef TIMERGAME_H
#define TIMERGAME_H
class TimerGame
{
private:
	std::string startTime;

public:
	void setStartTime();
	void setStartTime(std::string time);
	std::vector<int> getTimeInt(std::string strTime);
	std::string getStartTime();
	std::string getCurrentTime();
	System::String^ getDifferenceTime();
	void resetTime();
};
#endif
