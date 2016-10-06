#ifndef _HTTP_PIC_DOWNLOAD_H_
#define _HTTP_PIC_DOWNLOAD_H_

#include <string>
#include <vector>

#include <afx.h>
#include <afxinet.h>

bool downloadPics(std::vector<std::string> urls);
bool downPicFromURL(const std::string &url, const std::string &saveName);

#endif
