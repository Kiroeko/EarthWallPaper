#ifndef _SET_WALL_PAPER_H_
#define _SET_WALL_PAPER_H_

#include <string>
#include <cstdlib>
#include <afxwin.h>
#include <atlimage.h>

void SetWallPaper();
void MixPics();
void UpDowmMix(const std::string &A, const std::string &B, const std::string &C);
void LRMix(const std::string &A, const std::string &B);

#endif
