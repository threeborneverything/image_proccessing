#pragma once
#include "afxwin.h"


// EditDlg �Ի���

class EditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EditDlg)

public:
	EditDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EditDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_KernelSize };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit1;
	int kernelSize;
	CEdit m_Edit2;
	afx_msg void OnEnChangeEdit2();
	int m_Edit3;
};
