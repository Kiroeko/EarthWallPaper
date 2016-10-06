#include "HttpPicDownLoad.h"
#define BUFFSIZE 65536

using namespace std;

bool downloadPics(vector<string> urls)
{
	string p1 = urls[0];
	string p2 = urls[1];
	string p3 = urls[2];
	string p4 = urls[3];

	bool flag = true;

	if (!downPicFromURL(p1,"C:\\1.png"))
	{
		flag = false;
	}
	if (!downPicFromURL(p2, "C:\\2.png"))
	{
		flag = false;
	}
	if (!downPicFromURL(p3, "C:\\3.png"))
	{
		flag = false;
	}
	if (!downPicFromURL(p4, "C:\\4.png"))
	{
		flag = false;
	}

	return flag;
}

bool downPicFromURL(const string &url,const string &saveName)
{
	bool flag = true;
	CString URL = url.c_str();

	CInternetSession session;
	CHttpFile *httpFile = (CHttpFile *)session.OpenURL(URL);
	CStdioFile imgFile;
	char buff[BUFFSIZE];                              // 缓存  

	imgFile.Open(saveName.c_str(), CFile::modeCreate | CFile::modeWrite | CFile::typeBinary);

	DWORD dwStatusCode;
	httpFile->QueryInfoStatusCode(dwStatusCode);

	if (dwStatusCode == HTTP_STATUS_OK)
	{
		int size = 0;
		do
		{
			size = httpFile->Read(buff, BUFFSIZE);    // 读取图片  
			imgFile.Write(buff, size);
		} while (size > 0);
	}
	else
	{
		flag = false;
	}

	httpFile->Close();
	session.Close();

	return flag;
}
