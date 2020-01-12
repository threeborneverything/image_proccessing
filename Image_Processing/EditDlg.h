#pragma once
#include "afxwin.h"


// EditDlg 对话框

class EditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EditDlg)

public:
	EditDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~EditDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_KernelSize };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit1;
	int kernelSize;
	CEdit m_Edit2;
	afx_msg void OnEnChangeEdit2();
	int m_Edit3;
};
