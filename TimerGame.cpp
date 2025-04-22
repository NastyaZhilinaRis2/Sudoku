#include "TimerGame.h"
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <vector>
#include <msclr\marshal_cppstd.h>
void TimerGame::setStartTime()
{
	startTime = getCurrentTime();
}
void TimerGame::setStartTime(std::string time)
{
	int hh, mm, ss;
	std::vector<int> timeStart = getTimeInt(getCurrentTime());
	std::vector<int> timeStart2 = getTimeInt(time);
	if (!(timeStart.empty()))
	{
		hh = timeStart[0] - timeStart2[0];
		mm = timeStart[1] - timeStart2[1];
		ss = timeStart[2] - timeStart2[2];
	}
	startTime = msclr::interop::marshal_as<std::string>(hh.ToString()->PadLeft(2, '0') + ":" + mm.ToString()->PadLeft(2, '0') + ":" + ss.ToString()->PadLeft(2, '0'));
}
std::vector<int> TimerGame::getTimeInt(std::string strTime)
{
	std::vector<int> time;
	int hh, mm, ss;
	char dummy;
	std::stringstream stringstream(strTime);
	if (stringstream >> hh >> dummy >> mm >> dummy >> ss)
	{
		time.push_back(hh);
		time.push_back(mm);
		time.push_back(ss);
	}
	return time;
}
std::string TimerGame::getStartTime()
{
	return startTime;
}
std::string TimerGame::getCurrentTime()
{
	std::time_t currentTime = std::time(nullptr);
	std::stringstream ss;
	ss << std::put_time(std::localtime(&currentTime), "%H:%M:%S");
	std::string time = ss.str();
	return time;
}
System::String^ TimerGame::getDifferenceTime()
{
	System::String^ strTime;
	std::vector<int> timeStart = getTimeInt(getStartTime());
	std::vector<int> timeNow = getTimeInt(getCurrentTime());
	int hh, mm, ss;
	if (!(timeStart.empty() || timeNow.empty()))
	{
		hh = timeNow[0] - timeStart[0];
		mm = timeNow[1] - timeStart[1];
		ss = timeNow[2] - timeStart[2];
	}
	strTime = hh.ToString()->PadLeft(2, '0') + ":" + mm.ToString()->PadLeft(2, '0') + ":" + ss.ToString()->PadLeft(2, '0');

	return strTime;
}
void TimerGame::resetTime()
{
	startTime = "";
}


