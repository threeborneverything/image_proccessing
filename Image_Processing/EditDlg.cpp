// EditDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Image_Processing.h"
#include "EditDlg.h"
#include "afxdialogex.h"


// EditDlg �Ի���

IMPLEMENT_DYNAMIC(EditDlg, CDialogEx)

EditDlg::EditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(EditDlg::IDD, pParent)
	//, m_Edit2(0)
	, m_Edit3(0)
{

}

EditDlg::~EditDlg()
{
}

void EditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	//DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Text(pDX, IDC_EDIT2, m_Edit3);
	DDV_MinMaxInt(pDX, m_Edit3, 3, 1024);
}


BEGIN_MESSAGE_MAP(EditDlg, CDialogEx)
END_MESSAGE_MAP()


// EditDlg ��Ϣ�������
