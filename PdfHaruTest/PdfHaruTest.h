
// PdfHaruTest.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CPdfHaruTestApp:
// � ���������� ������� ������ ��. PdfHaruTest.cpp
//

class CPdfHaruTestApp : public CWinApp
{
public:
	CPdfHaruTestApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CPdfHaruTestApp theApp;