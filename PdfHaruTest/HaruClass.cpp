#include "stdafx.h"
#include "HaruClass.h"

#include <stdexcept>
#include <malloc.h>

void __stdcall error_handler2(HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data)
{
	char sError[50];
	sprintf_s(sError, "Ошибка: номер=%04X, детали=%d\n", (unsigned int)error_no, (int)detail_no);
	throw std::runtime_error(sError);
}

HaruClass::HaruClass()
{
	m_hDllHandle = NULL;
	m_Pdf = NULL;

	m_nTopField = 0;
	m_nBottomField = 0;
	m_nLeftField = 0;
	m_nRightField = 0;
}


HaruClass::~HaruClass()
{
	if (m_Pdf)
	{
		PDF_Free(m_Pdf);
		m_Pdf = NULL;
	}
}

int HaruClass::InitDll(const char * sLibName)
{
	m_hDllHandle = LoadLibraryA(sLibName);

	if (m_hDllHandle != NULL)
	{
		PDF_New = (HPDF_New)GetProcAddress(m_hDllHandle,
			"HPDF_New");
		PDF_GetVersion = (HPDF_GetVersion)GetProcAddress(m_hDllHandle,
			"HPDF_GetVersion");
		PDF_LoadTTFontFromFile = (HPDF_LoadTTFontFromFile)GetProcAddress(m_hDllHandle,
			"HPDF_LoadTTFontFromFile");
		PDF_GetFont = (HPDF_GetFont)GetProcAddress(m_hDllHandle,
			"HPDF_GetFont");
		PDF_AddPage = (HPDF_AddPage)GetProcAddress(m_hDllHandle,
			"HPDF_AddPage");
		PDF_Page_SetSize = (HPDF_Page_SetSize)GetProcAddress(m_hDllHandle,
			"HPDF_Page_SetSize");
		PDF_Page_SetFontAndSize = (HPDF_Page_SetFontAndSize)GetProcAddress(m_hDllHandle,
			"HPDF_Page_SetFontAndSize");
		PDF_Page_BeginText = (HPDF_Page_BeginText)GetProcAddress(m_hDllHandle,
			"HPDF_Page_BeginText");
		PDF_Page_EndText = (HPDF_Page_EndText)GetProcAddress(m_hDllHandle,
			"HPDF_Page_EndText");
		PDF_Page_TextRect = (HPDF_Page_TextRect)GetProcAddress(m_hDllHandle,
			"HPDF_Page_TextRect");
		PDF_SaveToFile = (HPDF_SaveToFile)GetProcAddress(m_hDllHandle,
			"HPDF_SaveToFile");

		PDF_Page_GetHeight = (HPDF_Page_GetHeight)GetProcAddress(m_hDllHandle,
			"HPDF_Page_GetHeight");
		PDF_Page_GetWidth = (HPDF_Page_GetWidth)GetProcAddress(m_hDllHandle,
			"HPDF_Page_GetWidth");

		PDF_Page_SetTextLeading = (HPDF_Page_SetTextLeading)GetProcAddress(m_hDllHandle,
			"HPDF_Page_SetTextLeading");
		PDF_Page_GetCurrentTextPos = (HPDF_Page_GetCurrentTextPos)GetProcAddress(m_hDllHandle,
			"HPDF_Page_GetCurrentTextPos");

		PDF_Page_MoveTo = (HPDF_Page_MoveTo)GetProcAddress(m_hDllHandle,
			"HPDF_Page_MoveTo");
		PDF_Page_LineTo = (HPDF_Page_LineTo)GetProcAddress(m_hDllHandle,
			"HPDF_Page_LineTo");
		PDF_Page_Stroke = (HPDF_Page_Stroke)GetProcAddress(m_hDllHandle,
			"HPDF_Page_Stroke");
		PDF_Page_Rectangle = (HPDF_Page_Rectangle)GetProcAddress(m_hDllHandle,
			"HPDF_Page_Rectangle");

		PDF_Font_MeasureText = (HPDF_Font_MeasureText)GetProcAddress(m_hDllHandle,
			"HPDF_Font_MeasureText");
		PDF_Page_GetCharSpace = (HPDF_Page_GetCharSpace)GetProcAddress(m_hDllHandle,
			"HPDF_Page_GetCharSpace");
		PDF_Page_GetWordSpace = (HPDF_Page_GetWordSpace)GetProcAddress(m_hDllHandle,
			"HPDF_Page_GetWordSpace");
		PDF_Page_TextWidth = (HPDF_Page_TextWidth)GetProcAddress(m_hDllHandle,
			"HPDF_Page_TextWidth");

		PDF_SetPassword = (HPDF_SetPassword)GetProcAddress(m_hDllHandle,
			"HPDF_SetPassword");
		PDF_SetPermission = (HPDF_SetPermission)GetProcAddress(m_hDllHandle,
			"HPDF_SetPermission");
		PDF_SetEncryptionMode = (HPDF_SetEncryptionMode)GetProcAddress(m_hDllHandle,
			"HPDF_SetEncryptionMode");

		PDF_Free = (HPDF_Free)GetProcAddress(m_hDllHandle,
			"HPDF_Free");

		return 1;
	}
	return 0;
}

int HaruClass::InitPdf(_HPDF_PageSizes PageSize, _HPDF_PageDirection PageDirection)
{
	m_Pdf = PDF_New(error_handler2, NULL);

	if (!m_Pdf) 
		return 0;

	m_CurTextPoint.y = 0;
	m_nNumberOfPages = 0;
	m_PageSize = PageSize;
	m_PageDirection = PageDirection;

	return 1;
}

int HaruClass::InitFont(char* sTTFFileName, float nFontSize, float nTextLeading, int nTopField, int nBottomField, int nLeftField, int nRightField)
{
	try {
		// Загрузка объекта шрифта
		const char *font_name;
		//font_name = HPDF_LoadType1FontFromFile(pPdf, sAfmFileName, sPfbFileName);		// Загрузка Type 1 шрифта
		//font_name = HPDF_LoadTTFontFromFile(pPdf, "type1/gost_type.ttf", HPDF_TRUE);	// Загрузка ttf шрифта

		font_name = PDF_LoadTTFontFromFile(m_Pdf, sTTFFileName, HPDF_TRUE);
		m_CurTextHeight = nFontSize;
		m_CurTextLeading = nTextLeading * m_CurTextHeight;

		m_nTopField = nTopField * MmToPx;
		m_nBottomField = nBottomField * MmToPx;
		m_nLeftField = nLeftField * MmToPx;
		m_nRightField = nRightField * MmToPx;

		m_CurFont = PDF_GetFont(m_Pdf, font_name, "CP1251");
	}
	catch (const std::exception &err)
	{
		char sError[100];
		sprintf_s(sError, "%s%s", "Ошибка определения параметров шрифта\n", err.what());
		MessageBoxA(NULL, sError, "ОШИБКА", MB_OK | MB_ICONERROR);
		return 0;
	}

	return 1;
}

void HaruClass::SetFooter(BOOL bNumPages, char * sFooterText)
{
	m_bNumPages = bNumPages;
	if (sFooterText != nullptr)
		strcpy_s(m_sFooterText, sFooterText);
}

float HaruClass::GetPageWidth(BOOL bWithFields)
{
	try {
		if (m_CurTextPoint.y == 0)
			InitPage();
		if (bWithFields)
			return PDF_Page_GetWidth(m_CurPage) - m_nLeftField - m_nRightField;
		else
			return PDF_Page_GetWidth(m_CurPage);
	}
	catch (const std::exception &err)
	{
		MessageBoxA(NULL, err.what(), "ОШИБКА", MB_OK | MB_ICONERROR);
		return 0;
	}
}

float HaruClass::GetPageHeight(BOOL bWithFields)
{
	try {
		if (m_CurTextPoint.y == 0)
			InitPage();
		if (bWithFields)
			return (HPDF_REAL)(PDF_Page_GetHeight(m_CurPage) - m_nTopField - m_nBottomField - m_CurTextLeading);
		else
			return PDF_Page_GetHeight(m_CurPage);
	}
	catch (const std::exception &err)
	{
		MessageBoxA(NULL, err.what(), "ОШИБКА", MB_OK | MB_ICONERROR);
		return 0;
	}
}

int HaruClass::InitPage()
{
	try {
		m_CurPage = PDF_AddPage(m_Pdf);
		m_nNumberOfPages++;
		PDF_Page_SetSize(m_CurPage, m_PageSize, m_PageDirection);		// A4 в пикселях, разрешение 72dpi 841.89 Х 595.276;
		m_CurTextPoint.x = (HPDF_REAL)(m_nLeftField);
		m_CurTextPoint.y = (HPDF_REAL)(PDF_Page_GetHeight(m_CurPage) - m_nTopField);
		PDF_Page_SetFontAndSize(m_CurPage, m_CurFont, m_CurTextHeight);
		
		// Интервал как в ворде 1, 1.5, 2 и тд
		PDF_Page_SetTextLeading(m_CurPage, m_CurTextLeading);
		
		AddFooter();
	}
	catch (const std::exception &err)
	{
		char sError[100];
		sprintf_s(sError, "%s%s", "Ошибка инициализации новой страницы\n", err.what());
		MessageBoxA(NULL, sError, "ОШИБКА", MB_OK | MB_ICONERROR);
		return 0;
	}
	return 1;
}

char * HaruClass::AddSimpleText(char * sString, HPDF_UINT TextAlign)
{
	int nWriteSymb = 0;
	int nStrings = 0;

	if (m_CurTextPoint.y == 0 || m_CurTextPoint.y - m_nBottomField - m_CurTextLeading < 0)		// Если первый заход или если нет места под новую строку
		InitPage();

	nStrings = TextStringCount(sString, (HPDF_REAL)(PDF_Page_GetWidth(m_CurPage) - m_nLeftField - m_nRightField));

	PDF_Page_BeginText(m_CurPage);
	PDF_Page_TextRect(m_CurPage, m_CurTextPoint.x, m_CurTextPoint.y, (HPDF_REAL)(PDF_Page_GetWidth(m_CurPage) - m_nRightField),
		(HPDF_REAL)(m_nBottomField + m_CurTextLeading), sString, nStrings, TextAlign, (HPDF_UINT*)&nWriteSymb);		// Боттом по сути фикция, если текст не влезает в область то все равно напечатается но выдаст 0х1076, это ознаает что либо надо применять мой алгоритм, либо не печатать дальше текст

	if (PDF_Page_GetCurrentTextPos(m_CurPage).y)
		m_CurTextPoint.y = PDF_Page_GetCurrentTextPos(m_CurPage).y - m_CurTextLeading + m_CurTextHeight;		// -(pCurTextLeading - pCurTextHeight) межстрочный интервал включая строку
	PDF_Page_EndText(m_CurPage);
	
	if (strlen(sString) != nWriteSymb)	
		return &sString[nWriteSymb];
	else
		return NULL;
}

int HaruClass::AddString(char * sString, HPDF_UINT TextAlign)
{
	try {
		// Написание текста
		char* sBufSimpleString = AddSimpleText(sString, TextAlign);
		// Если есть строки превышающие ширину блока
		if (sBufSimpleString)
		{
			char* sBufString;
			int nStrings = 0;
			int nStrLenght = strlen(sString);
			char sTestStr[MAX_PATH];		// Для моноширинного шрифта не важно какая строка проверяется
			memset(sTestStr, 'A', MAX_PATH);
			// При немоноширинном шрифте непостоянная величина от строки к строке в зависимости от символов в ней
			m_nOneStrChar = PDF_Font_MeasureText(m_CurFont, (HPDF_BYTE*)sTestStr, nStrLenght, (HPDF_REAL)(PDF_Page_GetWidth(m_CurPage) -
				m_nLeftField - m_nRightField), m_CurTextHeight, PDF_Page_GetCharSpace(m_CurPage), PDF_Page_GetWordSpace(m_CurPage), HPDF_FALSE, NULL);

			sBufString = new char[nStrLenght + nStrLenght / m_nOneStrChar + 1];		// + 1 потому что null terminated, возможно нужно +2 из-за nStrLenght / nOneStrChar + 1
			sBufString[0] = '\0';
		
			if (strcmp(sBufSimpleString, sString))							// Если уже напечатали простую строку, то убрать верт выравнивание
				TextAlign &= 0xF;

			// Разделение строк на подстроки, вставка /n в точке разрыва
			while (sBufSimpleString - 1 != NULL)							// -1 потому что в цикле используется со смещением
			{
				std::string a(sBufSimpleString);
				char* sStringN = strchr(sBufSimpleString, '\n') + 1;		// + 1 чтобы исключить /n в конце строки
				int npos = (int)(sStringN - sBufSimpleString);
				std::string b = a.substr(0, npos).c_str();
				nStrings = MultiString(b.c_str(), sBufString);

				sBufSimpleString = sStringN;								// Обрезка исходной строки для следующей итерации
			} 

			// После формирования нормального блока можно проверять влезает ли он на страницу
			CheckNewPageText(sBufString, nStrings, TextAlign);
			delete[] sBufString;
		}

		return 1;
	}
	catch (const std::exception &err)
	{
		MessageBoxA(NULL, err.what(), "ОШИБКА", MB_OK | MB_ICONERROR);
		return 0;
	}
}


int HaruClass::AddString(CStringA sCString, /*HPDF_TextAlignment*/ HPDF_UINT TextAlign)
{
	int nRet = 0;
	char* sString = new char[sCString.GetLength() + 1];
	memcpy(sString, sCString, sCString.GetLength() + 1);

	nRet = AddString(sString, TextAlign);
	delete[] sString;
	return nRet;
}


const int HaruClass::MultiString(const char* sString, char * sBuffer)
{
	int nStringLenght = strlen(sString);
	int nOldLenghtBuf = strlen(sBuffer);						// Смещение в зависимости от того что уже есть в буфере
	int nStringCount = 1;										// Текущая строка в цикле
	int nStringAmount = strlen(sString) / m_nOneStrChar + 1;		// Всего строк, на которые надо разделить строку

	sprintf_s(sBuffer, nOldLenghtBuf + nStringLenght + 1, "%s%s", sBuffer, sString);
	while (nStringCount != nStringAmount)
	{
		// Вставлять в конец строки длинной nOneStrChar символ /n 
		sBuffer[nOldLenghtBuf + m_nOneStrChar * nStringCount + nStringCount - 1] = '\0';
		sprintf_s(sBuffer, strlen(sBuffer) + nStringLenght - m_nOneStrChar * nStringCount + 2,"%s%s%s", sBuffer, "\n", &sString[m_nOneStrChar * nStringCount]);
		nStringCount++;
	}

	return nStringCount;
}


int HaruClass::CheckNewPageText(char * sBuffer, const int nStrings, HPDF_UINT TextAlign)
{
	// В ворде стандартные поля 2 сверху, 2 снизу, 3 слева, 1.5 справа
	// Изменения также в AddString

	int nStrLenghtBuf = strlen(sBuffer);
	int nWriteSymb = 0;

	PDF_Page_BeginText(m_CurPage);
	PDF_Page_TextRect(m_CurPage, m_CurTextPoint.x, m_CurTextPoint.y, (HPDF_REAL)(PDF_Page_GetWidth(m_CurPage) - m_nRightField),
		(HPDF_REAL)(m_nBottomField), sBuffer, nStrings, TextAlign, (HPDF_UINT*)&nWriteSymb);

	while (nStrLenghtBuf != nWriteSymb)						// Пока не напечатаны все символы
	{
		int nCurWriteSymb = 0;
		char* sNextPString = new char[nStrLenghtBuf - nWriteSymb + 1];			// +1 потому что null terminated

		strcpy_s(sNextPString, nStrLenghtBuf - nWriteSymb + 1, &sBuffer[nWriteSymb]);
		InitPage();
		PDF_Page_BeginText(m_CurPage);
		PDF_Page_TextRect(m_CurPage, m_CurTextPoint.x, m_CurTextPoint.y, (HPDF_REAL)(PDF_Page_GetWidth(m_CurPage) - m_nRightField),
			(HPDF_REAL)(m_nBottomField), &sBuffer[nWriteSymb], 0, TextAlign, (HPDF_UINT*)&nCurWriteSymb);
		nWriteSymb += nCurWriteSymb;
		delete[] sNextPString;
	}
	m_CurTextPoint.y = PDF_Page_GetCurrentTextPos(m_CurPage).y - m_CurTextLeading + m_CurTextHeight;
	PDF_Page_EndText(m_CurPage);

	return 1;
}

int HaruClass::AddFooter()
{
	char sNumber[8];
	sprintf_s(sNumber, "%d", m_nNumberOfPages);
	PDF_Page_BeginText(m_CurPage);
	if (m_bNumPages)
	{
		PDF_Page_TextRect(m_CurPage, (HPDF_REAL)(m_nLeftField), (HPDF_REAL)(m_nBottomField),
			(HPDF_REAL)(PDF_Page_GetWidth(m_CurPage) - m_nRightField), 0, sNumber, 0, HPDF_TALIGN_RIGHT, NULL);
	}
	PDF_Page_TextRect(m_CurPage, (HPDF_REAL)(m_nLeftField), (HPDF_REAL)(m_nBottomField), (HPDF_REAL)(PDF_Page_GetWidth(m_CurPage) - m_nRightField),
		0, m_sFooterText, 0, HPDF_TALIGN_LEFT, NULL);
	PDF_Page_EndText(m_CurPage);

	return 1;
}


int HaruClass::AddStringToTableCell(HPDF_REAL fLeft, HPDF_REAL fTop, HPDF_REAL fRight, HPDF_REAL fBottom, char * sText, HPDF_UINT TextAlign)
{
	try {
		int nStrings = TextStringCount(sText, fRight - fLeft);
		int nWriteSymb = 0;
		HPDF_REAL fNewTop = fTop;

		PDF_Page_BeginText(m_CurPage);
		PDF_Page_TextRect(m_CurPage, fLeft, fTop, fRight, fBottom, sText, nStrings, TextAlign, (HPDF_UINT*)&nWriteSymb);

		if (PDF_Page_GetCurrentTextPos(m_CurPage).y)
			fNewTop = PDF_Page_GetCurrentTextPos(m_CurPage).y - m_CurTextLeading + m_CurTextHeight;

		if (strlen(sText) != nWriteSymb)
		{
			// Написание текста
			char* sBufSimpleString = &sText[nWriteSymb];

			// Если есть строки превышающие ширину блока
			if (sBufSimpleString)
			{
				char* sBufString;
				int nStrLenght = strlen(sText);
				// Проверка длинны строки на превышение ширины блока
				m_nOneStrChar = PDF_Font_MeasureText(m_CurFont, (HPDF_BYTE*)sBufSimpleString, strlen(sBufSimpleString), fRight - fLeft, m_CurTextHeight, PDF_Page_GetCharSpace(m_CurPage),
					PDF_Page_GetWordSpace(m_CurPage), HPDF_FALSE, NULL);			// При немоноширинном шрифте непостоянная величина от строки к строке в зависимости от символов в ней

				if (m_nOneStrChar == 0)
					throw std::exception("Текст не помещается в таблицу");

				sBufString = new char[nStrLenght + nStrLenght / m_nOneStrChar + 1];		// + 1 потому что null terminated, возможно нужно +2 из-за nStrLenght / nOneStrChar + 1
				sBufString[0] = '\0';

				// Разделение строк на подстроки, вставка /n в точке разрыва
				while (sBufSimpleString - 1 != NULL)									// -1 потому что в цикле используется со смещением
				{
					std::string a(sBufSimpleString);
					char* sStringN = strchr(sBufSimpleString, '\n') + 1;		// + 1 чтобы исключить /n в конце строки
					int npos = (int)(sStringN - sBufSimpleString);
					std::string b = a.substr(0, npos).c_str();
					MultiString(b.c_str(), sBufString);

					sBufSimpleString = sStringN;								// Обрезка исходной строки для следующей итерации
				}

				// После формирования нормального блока можно проверять влезает ли он на страницу
				PDF_Page_TextRect(m_CurPage, fLeft, fNewTop, fRight, fBottom, sBufString, nStrings, TextAlign, NULL);
				delete[] sBufString;
			}
		}
		PDF_Page_EndText(m_CurPage);
		return 1;
	}
	catch (const std::exception &err)
	{
		MessageBoxA(NULL, err.what(), "ОШИБКА", MB_OK | MB_ICONERROR);
		return 0;
	}
}

int HaruClass::TextStringCount(char * sString, float nWidth)
{
	// Подсчет кол-ва строк
	int nStringCount = 1;
	int nStrLenght = strlen(sString);
	BOOL bSpaceFlag = false;
	BOOL bLongFlag = false;
	int nCharCount = 0;
	int nNextWordCharCount = 0;

	char sTestStr[MAX_PATH];		// Для моноширинного шрифта не важно какая строка проверяется
	memset(sTestStr, 'A', MAX_PATH);
	m_nOneStrChar = PDF_Font_MeasureText(m_CurFont, (HPDF_BYTE*)sTestStr, MAX_PATH, nWidth,
		m_CurTextHeight, PDF_Page_GetCharSpace(m_CurPage), PDF_Page_GetWordSpace(m_CurPage), HPDF_FALSE, NULL);

	for (int i = 0; i < nStrLenght; i++)
	{
		if (bSpaceFlag)
			nNextWordCharCount++;
		else
			nCharCount++;

		if (sString[i] == ' ' && !bLongFlag)
		{
			bSpaceFlag = true;
			nCharCount += nNextWordCharCount;
			nNextWordCharCount = 0;
		} 

		if (nCharCount == m_nOneStrChar)
			bLongFlag = true;

		if (bLongFlag || (sString[i] == '\n') || (nCharCount + nNextWordCharCount > m_nOneStrChar) || (nCharCount == m_nOneStrChar))
		{
			nStringCount++;
			nCharCount = 0;
			nNextWordCharCount = 0;
			bSpaceFlag = false;
			bLongFlag  = false;
		}
	}

	return nStringCount;
}

// Корректировка ширины ячеек в зависимости от содержимого. Не учитывается возможность изменить высоту ячейки в пределах общей высоты и перенос слов
int HaruClass::CorrectTableCells(float fWidth, float fHeight, int nStrings, int nColumns, char ** sTableText, CellInfo* CellsInfo)
{
	float fBaseWidth = fWidth / nColumns;
	float fBaseHeight = fHeight / nStrings;
	float* fMaxColumnWidth = new float[nColumns];
	float fMaxWidth = 0;

	// Переменные для разделения строк с \n
	CStringArray sStrArr;
	char csStr[MAX_PATH];

	// Вычисление требуемых длинн столбцов
	for (int j = 0; j < nColumns; j++)
	{
		fMaxColumnWidth[j] = 0;

		for (int i = 0; i < nStrings; i++)
		{
			CellsInfo[nColumns * i + j].fWidth = fBaseWidth;			// Инициализация ширины каждой ячейки
			CellsInfo[nColumns * i + j].fHeight = fBaseHeight;

			// Поиск \n и разделение на подстроки
			csStr[0] = '\0';
			StringSplit(sTableText[nColumns * i + j], sStrArr, '\n');
			// Определение строки максимальной длинны
			FindMaxString(sStrArr, csStr, MAX_PATH);

			if (PDF_Page_TextWidth(m_CurPage, csStr) > fMaxColumnWidth[j])
				fMaxColumnWidth[j] = PDF_Page_TextWidth(m_CurPage, csStr);
		}
		fMaxWidth += fMaxColumnWidth[j];
	}

	if (fMaxWidth > fWidth)
		return -1;		// Нет места под все столбцы (не учитывается высота и перенос)

	float fWidthDelta = (fWidth - fMaxWidth) / nColumns;		// На столько увеличить каждый столбец

	for (int j = 0; j < nColumns; j++)
		for (int i = 0; i < nStrings; i++)
			CellsInfo[nColumns * i + j].fWidth = fMaxColumnWidth[j] + fWidthDelta;

	delete[] fMaxColumnWidth;

	return 0;
}

int HaruClass::StringSplit(const CStringA &sStr, CStringArray &sArr, char chDelimitior)
{
	int nStart = 0, nEnd = 0;
	sArr.RemoveAll();

	while (nEnd < sStr.GetLength())
	{
		nEnd = sStr.Find(chDelimitior, nStart);
		if (nEnd == -1)
			nEnd = sStr.GetLength();

		CString s = (CString)sStr.Mid(nStart, nEnd - nStart);
		if (s.IsEmpty() == 0)
			sArr.Add(s);

		nStart = nEnd + 1;
	}

	return sArr.GetSize();
}

void HaruClass::FindMaxString(const CStringArray &sArr, char * csMaxStr, int nMaxLength)
{
	int nLen = 0;
	for (int i = 0; i < sArr.GetSize(); i++)
	{
		if (sArr[i].GetLength() > nLen)
		{
			nLen = sArr[i].GetLength();
			strcpy_s(csMaxStr, nMaxLength, (CStringA)sArr[i]);
		}
	}
}

int HaruClass::SetPermission(const char * sOwnerPass, const char * sUserPass, int nPermissions)
{
	try {
		PDF_SetPassword(m_Pdf, sOwnerPass, sUserPass);
		PDF_SetPermission(m_Pdf, nPermissions);
		PDF_SetEncryptionMode(m_Pdf, HPDF_ENCRYPT_R3, 16);
	}
	catch (const std::exception &err)
	{
		char sError[100];
		sprintf_s(sError, "%s%s", "Ошибка задания параметров доступа\n", err.what());
		MessageBoxA(NULL, sError, "ОШИБКА", MB_OK | MB_ICONERROR);
		return 0;
	}

	return 1;
}

int HaruClass::SavePdf(char* sPdfFileName)
{
	try {
		PDF_SaveToFile(m_Pdf, sPdfFileName);
	}
	catch (...) {
		MessageBoxA(NULL, "Ошибка сохранения pdf файла", "ОШИБКА", MB_OK | MB_ICONERROR);
		return 0;
	}

	return 1;
}


int HaruClass::CreateTable(float nXpos, float nYpos, float nWidth, float nHeight, int nStrings, int nColumns, char ** sTableText, HPDF_UINT TextAlign)
{
	CellInfo* pCellsInfo = NULL;		// Указатель на массив с информацией о ячейках

	try {
		int nStringNumber = 0;			// Счетчик для массива
		int nNpStrings = 0;				// Смещение по строкам с учетом новой страницы

		if (m_CurTextPoint.y == 0)		// Если первый заход
			InitPage();
		
		if (nXpos + nWidth > PDF_Page_GetWidth(m_CurPage) - m_nLeftField - m_nRightField)
			throw std::runtime_error("Ошибка: ширина таблицы превышает ширину страницы");
		if (_msize(sTableText) / sizeof(char*) != nStrings * nColumns)
			throw std::runtime_error("Ошибка: формат таблицы не совпадает с форматом массива данных");

		// Корректировка высоты и ширины ячеек на основе содержимого массива
		CellInfo* pCellsInfo = new CellInfo[nStrings * nColumns];
		if (CorrectTableCells(nWidth, nHeight, nStrings, nColumns, sTableText, pCellsInfo) == -1)
			throw std::exception("Нет места под все столбцы");

		// Рисование прямоугольниками
		for (int i = 0; i < nStrings; i++)
		{
			if (m_CurTextPoint.y - nYpos - m_CurTextLeading / 2 - (i - nNpStrings) * pCellsInfo[nStringNumber].fHeight - m_nBottomField < pCellsInfo[nStringNumber].fHeight - 0.001)		// Если не помещается новая строка; не 0, потому что учитываем погрешность
			{
				InitPage();
				nYpos = 0;
				nNpStrings = i;
			}

			float fCurWidth = 0;

			for (int j = 0; j < nColumns; j++)
			{
				PDF_Page_Rectangle(m_CurPage, m_CurTextPoint.x + nXpos + fCurWidth,
					m_CurTextPoint.y - nYpos - m_CurTextLeading / 2 - (i - nNpStrings) * pCellsInfo[nStringNumber].fHeight,
					pCellsInfo[nStringNumber].fWidth,
					-pCellsInfo[nStringNumber].fHeight);
				PDF_Page_Stroke(m_CurPage);

				AddStringToTableCell(m_CurTextPoint.x + nXpos + fCurWidth,
					m_CurTextPoint.y - nYpos - m_CurTextLeading / 2 - (i - nNpStrings) * pCellsInfo[nStringNumber].fHeight,
					m_CurTextPoint.x + nXpos + fCurWidth + pCellsInfo[nStringNumber].fWidth,
					m_CurTextPoint.y - nYpos - (i - nNpStrings + 1) * pCellsInfo[nStringNumber].fHeight, sTableText[nStringNumber], TextAlign);

				fCurWidth += pCellsInfo[nStringNumber].fWidth;

				nStringNumber++;
			}
		}

		m_CurTextPoint.y = (float)(m_CurTextPoint.y - m_CurTextLeading / 2 - nYpos - (nStrings - nNpStrings) * (nHeight / nStrings));		// Точка после таблицы, с которой начнется новый текст

		delete[] pCellsInfo;
		return 1;
	}
	catch (const std::exception &err)
	{
		MessageBoxA(NULL, err.what(), "ОШИБКА", MB_OK | MB_ICONERROR);
		delete[] pCellsInfo;
		return 0;
	}
}


int HaruClass::CreateTable(float nXpos, float nYpos, float nWidth, float nHeight, int nStrings, int nColumns, CStringArray &sTextArr, HPDF_UINT TextAlign)
{
	int nItems = sTextArr.GetSize();
	char** sTableText = new char*[nItems];

	for (int i = 0; i < nItems; i++)
	{
		CStringA sBuf(sTextArr[i]);
		int nSize = sBuf.GetLength() + 1;

		sTableText[i] = new char[nSize];
		strcpy_s(sTableText[i], nSize, sBuf);
	}

	CreateTable(nXpos, nYpos, nWidth, nHeight, nStrings, nColumns, sTableText, TextAlign);

	for (int i = 0; i < nItems; i++)
		delete[] sTableText[i];
	delete[] sTableText;

	return 0;
}


int HaruClass::CreateTable(float nXpos, float nYpos, float nWidth, float nHeight, int nStrings, int nColumns, char* sTextArr, int nStringLenght, HPDF_UINT TextAlign)
{	
	int nItems = nStrings * nColumns;
	char** sTableText = new char*[nItems];

	for (int i = 0; i < nItems; i++)
	{
		sTableText[i] = new char[nStringLenght];
		strcpy_s(sTableText[i], nStringLenght, sTextArr + i * nStringLenght);
	}

	CreateTable(nXpos, nYpos, nWidth, nHeight, nStrings, nColumns, sTableText, TextAlign);

	for (int i = 0; i < nItems; i++)
		delete[] sTableText[i];
	delete[] sTableText;

	return 0;
}