#include "setWallPaper.h"

using namespace std;

void SetWallPaper()
{
	//把四张下载好的png保存为四个bmp格式文件
	CImage p1;
	p1.Load("C:\\1.png");
	p1.Save("C:\\1.bmp");
	p1.Destroy();
	system("del C:\\1.png");

	CImage p2;
	p2.Load("C:\\2.png");
	p2.Save("C:\\2.bmp");
	p2.Destroy();
	system("del C:\\2.png");

	CImage p3;
	p3.Load("C:\\3.png");
	p3.Save("C:\\3.bmp");
	p3.Destroy();
	system("del C:\\3.png");

	CImage p4;
	p4.Load("C:\\4.png");
	p4.Save("C:\\4.bmp");
	p4.Destroy();
	system("del C:\\4.png");

	//合并四个bmp文件，保存成earth.bmp
	MixPics();

	//把保存的earth.bmp设置为桌面壁纸
	SystemParametersInfo(SPI_SETDESKWALLPAPER,0, "C:\\earth.bmp", SPIF_SENDCHANGE);
}

//合并四个bmp文件，保存成earth.bmp
void MixPics()
{
	UpDowmMix("C:\\1.bmp","C:\\3.bmp","C:\\13.bmp");
	UpDowmMix("C:\\2.bmp","C:\\4.bmp","C:\\24.bmp");

	LRMix("C:\\13.bmp","C:\\24.bmp");

	system("del C:\\1.bmp");
	system("del C:\\2.bmp");
	system("del C:\\3.bmp");
	system("del C:\\4.bmp");
	system("del C:\\13.bmp");
	system("del C:\\24.bmp");
}

//拼接A和B两张bmp，使A在上，B在下，生成的新bmp文件为C
void UpDowmMix(const string &A,const string &B, const string &C)
{
	CImage img1, img2, img3;

	img1.Load(A.c_str());
	img2.Load(B.c_str());

	CBitmap bmp;
	CDC memDC;
	HDC hDC = NULL;
	CDC *pDC = NULL;
	CBitmap *pOld = NULL;
	HBITMAP hBitmap = NULL;

	//创建位图  
	hDC = img1.GetDC();
	pDC = CDC::FromHandle(hDC);
	bmp.DeleteObject();
	bmp.CreateCompatibleBitmap(pDC, img1.GetWidth(), img1.GetHeight() * 2);
	memDC.DeleteDC();
	memDC.CreateCompatibleDC(pDC);
	pOld = memDC.SelectObject(&bmp);

	::SetStretchBltMode(memDC.m_hDC, HALFTONE);
	::SetBrushOrgEx(memDC.m_hDC, 0, 0, NULL);

	// 背景置白色  
	CRgn rectRgn;
	rectRgn.CreateRectRgn(0, 0, img1.GetWidth(), img1.GetHeight() * 2);
	CBrush brush;
	brush.CreateSolidBrush(RGB(255, 255, 255));
	memDC.FillRgn(&rectRgn, &brush);

	//画图  
	img1.StretchBlt(memDC.m_hDC, CRect(0, 0, img1.GetWidth(), img1.GetHeight()), CRect(0, 0, img1.GetWidth(), img1.GetHeight()), SRCCOPY);
	img2.StretchBlt(memDC.m_hDC, CRect(0, img1.GetHeight(), img1.GetWidth(), img1.GetHeight() * 2), CRect(0, 0, img2.GetWidth(), img2.GetHeight()), SRCCOPY);

	hBitmap = (HBITMAP)memDC.SelectObject(pOld->m_hObject);
	img3.Attach(hBitmap);// 载入位图资源  
	img3.Save(C.c_str()); // 保存新的位图  

	img1.ReleaseDC();
	img1.Destroy();
	img2.Destroy();
	img3.Destroy();
}

//拼接A和B两张bmp，使A在左，B在右
void LRMix(const string &A, const string &B)
{
	CImage img1, img2, img3;

	img1.Load(A.c_str());
	img2.Load(B.c_str());

	CBitmap bmp;
	CDC memDC;
	HDC hDC = NULL;
	CDC *pDC = NULL;
	CBitmap *pOld = NULL;
	HBITMAP hBitmap = NULL;

	//创建位图  
	hDC = img1.GetDC();
	pDC = CDC::FromHandle(hDC);
	bmp.DeleteObject();
	bmp.CreateCompatibleBitmap(pDC, img1.GetWidth() * 2, img1.GetHeight());
	memDC.DeleteDC();
	memDC.CreateCompatibleDC(pDC);
	pOld = memDC.SelectObject(&bmp);

	::SetStretchBltMode(memDC.m_hDC, HALFTONE);
	::SetBrushOrgEx(memDC.m_hDC, 0, 0, NULL);

	// 背景置白色  
	CRgn rectRgn;
	rectRgn.CreateRectRgn(0, 0, img1.GetWidth() * 2, img1.GetHeight());
	CBrush brush;
	brush.CreateSolidBrush(RGB(255, 255, 255));
	memDC.FillRgn(&rectRgn, &brush);

	//画图  
	img1.StretchBlt(memDC.m_hDC, CRect(0, 0, img1.GetWidth(), img1.GetHeight()), CRect(0, 0, img1.GetWidth(), img1.GetHeight()), SRCCOPY);
	img2.StretchBlt(memDC.m_hDC, CRect(img1.GetWidth(), 0, img1.GetWidth() * 2, img1.GetHeight()), CRect(0, 0, img2.GetWidth(), img2.GetHeight()), SRCCOPY);

	hBitmap = (HBITMAP)memDC.SelectObject(pOld->m_hObject);
	img3.Attach(hBitmap);// 载入位图资源  
	img3.Save("C:\\earth.bmp"); // 保存新的位图  

	img1.ReleaseDC();
	img1.Destroy();
	img2.Destroy();
	img3.Destroy();
}
