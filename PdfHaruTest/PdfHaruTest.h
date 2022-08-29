
// PdfHaruTest.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CPdfHaruTestApp:
// О реализации данного класса см. PdfHaruTest.cpp
//

class CPdfHaruTestApp : public CWinApp
{
public:
	CPdfHaruTestApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CPdfHaruTestApp theApp;