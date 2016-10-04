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
	char buff[BUFFSIZE];                              // »º´æ  

	imgFile.Open("earth.png", CFile::modeCreate | CFile::modeWrite | CFile::typeBinary);

	DWORD dwStatusCode;
	httpFile->QueryInfoStatusCode(dwStatusCode);

	if (dwStatusCode == HTTP_STATUS_OK)
	{
		int size = 0;
		do
		{
			size = httpFile->Read(buff, BUFFSIZE);    // ¶ÁÈ¡Í¼Æ¬  
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