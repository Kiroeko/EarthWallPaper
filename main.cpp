#include "main.h"

using namespace std;

int main()
{
	while(true)
	{
		if (downPicFromURL(getURLForHimawari8()))
		{
			SetWallPaper();
		}
		else
		{
			cerr << "失去与向日葵8号的联系" << endl;
		}

		Sleep(600000);
	}

	return 0;
}