#pragma once


// CImageZFTDlg �Ի���

class CImageZFTDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CImageZFTDlg)

public:
	CImageZFTDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CImageZFTDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ZFT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnInitdialog(WPARAM wParam, LPARAM lParam);
public:
	int* Red;
	int* Green;
	int* Blue;

	afx_msg void OnZftYt();
	afx_msg void OnPaint();

	afx_msg void OnBnClickedStaticRgb();
};
