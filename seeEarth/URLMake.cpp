#include "URLMake.h"

using namespace std;

vector<string> getURLForHimawari8()
{
	stringstream ss;
	string url("http://himawari8-dl.nict.go.jp/himawari8/img/D531106/2d/550/");

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
	int hr = (timeInfo->tm_hour);

	//时差
	if (hr >= 10)
	{
		hr -= 10;
	}
	else
	{
		hr = (24 + hr - 10);
	}

	ss << hr;
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

	string backStr1("00_0_0.png");
	string backStr2("00_1_0.png");
	string backStr3("00_0_1.png");
	string backStr4("00_1_1.png");

	backStr1 = url + backStr1;
	backStr2 = url + backStr2;
	backStr3 = url + backStr3;
	backStr4 = url + backStr4;

	vector<string> urls;
	urls.push_back(backStr1);
	urls.push_back(backStr2);
	urls.push_back(backStr3);
	urls.push_back(backStr4);

	return urls;
}
