#include "URLMake.h"

using namespace std;

std::string getURLForHimawari8()
{
	stringstream ss;
	string url("http://himawari8-dl.nict.go.jp/himawari8/img/D531106/1d/550/");
	string backStr("_0_0.png");

	time_t now = time(nullptr);;
	tm *timeInfo = localtime(&now);

	string year;
	int yr = (timeInfo->tm_year+1900);

	string month;
	int mth= (timeInfo->tm_mon + 1);

	string day;
	int dy = timeInfo->tm_mday;

	if (mth==1)
	{
		--yr;
		mth = 12;
	}
	else
	{
		--mth;
	}

	if (mth==2&&dy>28)
	{
		dy = 28;
	}

	ss << yr;
	ss >> year;
	ss.clear();
	url += year;
	url += "/";

	ss << mth;
	ss >> month;
	ss.clear();
	if (month.size()==1)
	{
		url += "0";
	}
	url += month;
	url += "/";

	ss << dy;
	ss >> day;
	ss.clear();
	if (day.size() == 1)
	{
		url += "0";
	}
	url += day;
	url += "/";

	string hour;
	ss << timeInfo->tm_hour;
	ss >> hour;
	ss.clear();

	if (hour.size() == 1)
	{
		url += "0";
	}
	url += hour;

	string minute;

	int min = ((timeInfo->tm_min/10)*10);
	ss << min;
	ss >> minute;
	ss.clear();

	if (minute.size() == 1)
	{
		url += "0";
	}
	url += minute;

	url += "00";

	url += backStr;

	return url;
}