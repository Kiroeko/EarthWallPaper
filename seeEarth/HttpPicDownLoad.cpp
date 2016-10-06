#include "HttpPicDownLoad.h"
#define BUFFSIZE 65536

using namespace std;

bool downPicFromURL(string url)
{
	bool flag = true;
	CString URL = url.c_str();

	CInternetSession session;
	CHttpFile *httpFile = (CHttpFile *)session.OpenURL(URL);
	CStdioFile imgFile;
	char buff[BUFFSIZE];                              // 缓存  

	imgFile.Open("C:\\earth.png", CFile::modeCreate | CFile::modeWrite | CFile::typeBinary);

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
