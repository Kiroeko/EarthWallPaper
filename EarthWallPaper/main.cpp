#include "main.h"

using namespace std;

int main()
{
	cout << "这个程序将使用向日葵8号拍摄的实时地球照片作为你的电脑桌面壁纸" << endl;
	int i = 0;

	while(true)
	{
		fstream vep("C:\\earth.bmp");
		if (vep.is_open())
		{
			vep.close();
			system("del C:\\earth.bmp");
		}
		else
		{
			vep.close();
		}

		if (downloadPics(getURLForHimawari8()))
		{
			SetWallPaper();

			++i;
			cout << "第"<<i<<"次更新桌面壁纸" << endl;
		}
		else
		{
			cerr << "失去与向日葵8号的联系" << endl;
		}

		Sleep(600000);
	}

	return 0;
}
