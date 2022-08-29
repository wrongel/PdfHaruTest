
// PdfHaruTestDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "PdfHaruTest.h"
#include "PdfHaruTestDlg.h"
#include "afxdialogex.h"
#include "HaruClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CPdfHaruTestDlg::CPdfHaruTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PDFHARUTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	_tcscpy_s(m_sPath, _T(""));
}

void CPdfHaruTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPdfHaruTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPdfHaruTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CPdfHaruTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CPdfHaruTestDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// ����������� ��������� CPdfHaruTestDlg

BOOL CPdfHaruTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CPdfHaruTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CPdfHaruTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPdfHaruTestDlg::OnBnClickedOk()
{
	// �������� ������
	HaruClass pPdf;
	
	if (pPdf.InitDll("libhpdf.dll") == 0)
	{
		AfxMessageBox("������ ������������� ����������");
		return;
	}

	if (pPdf.InitPdf(HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT) == 0)
	{
		AfxMessageBox("������ �������� pdf �����");
		return;
	}

	// ������� ������, ��� �������, ������������ ��������� � ����� ��������
	pPdf.InitFont("C:\\Windows\\Fonts\\cour.ttf", 12, 1, 20, 15, 25, 15);

	// ����������� ������
	TCHAR tcsListTable[15][50];
	for (int i = 0; i < 15; i++)
		_stprintf_s(tcsListTable[i], "������ �%d\n�����\n����������\n�����", i);
	pPdf.CreateTable(0, 0, pPdf.GetPageWidth(1), pPdf.GetPageHeight(1) / 3.f, 3, 5, *tcsListTable, sizeof(tcsListTable[0]), HPDF_TALIGN_CENTER | HPDF_TALIGN_MIDDLE);

	// ������������ ������
	int n = 50;
	TCHAR** sListTable = new TCHAR*[n];
	for (int i = 0; i < n; i++)
	{
		sListTable[i] = new TCHAR[20];
		_stprintf_s(sListTable[i], 20, "�%d", i);
	}
	pPdf.CreateTable(0, 0, pPdf.GetPageWidth(1), pPdf.GetPageHeight(1) / 3.f, 5, 10, sListTable, HPDF_TALIGN_MIDDLE | HPDF_TALIGN_CENTER);

	// ������ CString

	CStringArray TableData;
	for (int i = 0; i < 20; i++)
		TableData.Add(_T("�������\n�����\n������������\n�� ������\n��������"));
	pPdf.CreateTable(0, 0, pPdf.GetPageWidth(1), pPdf.GetPageHeight(1) * 0.6f, 5, 4, TableData, HPDF_TALIGN_CENTER | HPDF_TALIGN_MIDDLE);


	_tcscpy_s(m_sPath, "test.pdf");
	if (pPdf.SavePdf(m_sPath))
		AfxMessageBox("������ ���� test.pdf");

	for (int i = 0; i < n; i++)
		delete[] sListTable[i];
	delete[] sListTable;
}

void CPdfHaruTestDlg::OnBnClickedButton1()
{
	// ������ ������
	HaruClass pPdf;

	if (pPdf.InitDll("libhpdf.dll") == 0)
	{
		AfxMessageBox("������ ������������� ����������");
		return;
	}

	if (pPdf.InitPdf(HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT) == 0)
	{
		AfxMessageBox("������ �������� pdf �����");
		return;
	}

	pPdf.InitFont("C:\\Windows\\Fonts\\cour.ttf", 16, 1, 20, 20, 25, 15);

	pPdf.AddString("�� ��������� ������������ �� ������ ����");
	pPdf.AddString("\n����� ����������� �� �������", HPDF_TALIGN_RIGHT);
	pPdf.AddString("\n� �� ������", HPDF_TALIGN_CENTER);

	CString sLong = "\n������������ �� ������ ������� ����� CString. ������� ����� ������, �� ������ ����������� �� ������ ��������. �� ����� ������� ����� � ����������� �������������."
		"������� �� ������ �������������?";
	pPdf.AddString(sLong, HPDF_TALIGN_JUSTIFY);
	CString sLong2 = "\n�� �� ����� ��� ������������";
	pPdf.AddString(sLong2 + sLong);

	pPdf.AddString("����� �� ������ ����������� �����", HPDF_TALIGN_MIDDLE | HPDF_TALIGN_CENTER);
	pPdf.AddString("\n��������������������������������������������������������������������������������������������������������");
		
	wchar_t wSTR[256];
	wcscpy(wSTR, L"\n������� ����� �������");
	pPdf.AddString(CW2A(wSTR), HPDF_TALIGN_LEFT);

	_tcscpy_s(m_sPath, "test0.pdf");
	if (pPdf.SavePdf(m_sPath))
		AfxMessageBox("������ ���� test0.pdf");
}


void CPdfHaruTestDlg::OnBnClickedButton2()
{
	TCHAR sFile[MAX_PATH];
	// ������ ��������� ������ 
	// rundll32.exe shell32.dll, OpenAs_RunDLL C:\\MyFile.pdf - ������ ������� � �������
	// rundll32.exe url.dll,FileProtocolHandler C:\\MyFile.pdf - ������� ��������������� �����������
	sprintf(sFile, "%s%s", "rundll32.exe url.dll, FileProtocolHandler ", m_sPath);
	::WinExec(sFile, SW_SHOWNORMAL);
}