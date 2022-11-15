// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"
#include <vector>

#pragma comment( lib, "gdiplus.lib" )
#include "gdiplus.h"
using namespace Gdiplus;

//Gdiplus::GdiplusStartupInput m_gdiplusStartupInput;
//ULONG_PTR m_gdiplusToken;
//Image * m_pImage;  //图片对象

#endif //PCH_H
