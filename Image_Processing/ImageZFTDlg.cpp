// ImageZFTDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Image_Processing.h"
#include "ImageZFTDlg.h"
#include "afxdialogex.h"


// CImageZFTDlg �Ի���

IMPLEMENT_DYNAMIC(CImageZFTDlg, CDialogEx)

CImageZFTDlg::CImageZFTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageZFTDlg::IDD, pParent)
{

}

CImageZFTDlg::~CImageZFTDlg()
{
}

void CImageZFTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CImageZFTDlg, CDialogEx)
	ON_MESSAGE(WM_INITDIALOG, &CImageZFTDlg::OnInitdialog)
	ON_COMMAND(ID_ZFT_YT, &CImageZFTDlg::OnZftYt)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CImageZFTDlg ��Ϣ�������


afx_msg LRESULT CImageZFTDlg::OnInitdialog(WPARAM wParam, LPARAM lParam)
{
	return 0;
}


void CImageZFTDlg::OnZftYt()
{
	// TODO:  �ڴ���������������
}


void CImageZFTDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	// TODO: Add your message handler code here

	CRect rectpic;
	GetDlgItem(IDC_STATIC_KJ)->GetWindowRect(&rectpic);

	int x, y;
	x = rectpic.Width();
	y = rectpic.Height();

	CWnd *pWnd = GetDlgItem(IDC_STATIC_KJ);
	CDC *pDC = pWnd->GetDC();

	/***********************/
	/*�ص�:��ֱ��ͼ ��ɫ
	/**********************/
	CPen *RedPen = new CPen();                              //�������ʶ���
	RedPen->CreatePen(PS_SOLID, 1, RGB(255, 0, 0));           //��ɫ����
	CGdiObject *RedOlderPen = pDC->SelectObject(RedPen);    //ѡ�е�ǰ��ɫ���ʲ�������ǰ�Ļ���

	/*��ͼ*/
	pDC->Rectangle(9, 16, 312, 147);      //��һ�����ο�
	pDC->MoveTo(15, 20);                //����������
	pDC->LineTo(15, 128);               //Y����
	pDC->LineTo(305, 128);              //X����

	pDC->MoveTo(305, 128);              //����X��ͷ
	pDC->LineTo(300, 123);              //�����ϱ߼�ͷ
	pDC->MoveTo(305, 128);
	pDC->LineTo(300, 133);              //�����±߼�ͷ

	pDC->MoveTo(15, 20);                //����Y��ͷ
	pDC->LineTo(10, 25);                //������߼�ͷ
	pDC->MoveTo(15, 20);
	pDC->LineTo(20, 25);                //�����ұ߼�ͷ

	/**********************************************************************/
	/* TextOut��������:
	/* �ú����õ�ǰѡ������塢������ɫ��������ɫ��һ���ַ���д��ָ��λ��
	/* BOOL TextOut(HDC hdc,int x,int y,LPCTSTR str,int numStr)
	/* ��ʾ:x��ʼ����,y��ʼ����,�ַ���,�ַ������ַ�����
	/*
	/* SetTextColor��������:
	/* ����ָ���豸����(HDC)��������ɫ
	/* SetTextColor (HDC, COLORREF) ��:SetTextColor(HDC,RGB(255,0,0));
	/**********************************************************************/

	CString str;
	int i;
	for (i = 0; i <= 5; i++)                    //дX��̶���
	{
		str.Format(_T("%d"), i * 50);               //0-255֮�����6���̶�ֵ
		pDC->SetTextColor(RGB(255, 0, 255));   //����������ɫ
		pDC->TextOut(15 + 48 * i, 130, str);       //�������
		pDC->MoveTo(15 + 48 * i, 128);            //����X��̶�
		pDC->LineTo(15 + 48 * i, 125);
	}
	for (i = 0; i <= 5; i++)                        //дY��̶���
	{
		pDC->MoveTo(15, 128 - 20 * i);            //����Y��̶�
		pDC->LineTo(18, 128 - 20 * i);
	}

	/*����ֱ��ͼ��Ҫ�Ĵ���*/
	for (i = 1; i<256; i++)
	{
		pDC->MoveTo(15 + i, 128);
		if ((128 - 16) >(Red[i] / 40))
			pDC->LineTo(15 + i, 128 - (Red[i] / 40));
		else
			pDC->LineTo(15 + i, 16);            //�������εĻ����θ�
	}


	/**********************/
	/*�ص�:��ֱ��ͼ ��ɫ
	/**********************/
	CPen *GreenPen = new CPen();                             //�������ʶ���
	GreenPen->CreatePen(PS_SOLID, 1, RGB(0, 255, 0));          //��ɫ����
	CGdiObject *GreenOlderPen = pDC->SelectObject(GreenPen);

	pDC->Rectangle(9, 167, 312, 308);     //��һ�����ο�
	pDC->MoveTo(15, 171);               //����������
	pDC->LineTo(15, 288);               //Y����
	pDC->LineTo(305, 288);              //X����

	pDC->MoveTo(305, 288);              //����X��ͷ
	pDC->LineTo(300, 283);              //�����ϱ߼�ͷ
	pDC->MoveTo(305, 288);
	pDC->LineTo(300, 293);              //�����±߼�ͷ

	pDC->MoveTo(15, 171);                //����Y��ͷ
	pDC->LineTo(10, 176);                //������߼�ͷ
	pDC->MoveTo(15, 171);
	pDC->LineTo(20, 176);                //�����ұ߼�ͷ

	for (i = 0; i <= 5; i++)                   //дX��̶���
	{
		str.Format(_T("%d"), i * 50);               //0-255֮�����6���̶�ֵ
		pDC->SetTextColor(RGB(255, 0, 255));   //����������ɫ
		pDC->TextOut(15 + 48 * i, 290, str);       //�������

		pDC->MoveTo(15 + 48 * i, 288);            //����X��̶�
		pDC->LineTo(15 + 48 * i, 285);
	}
	for (i = 0; i <= 5; i++)                        //дY��̶���
	{
		pDC->MoveTo(15, 288 - 20 * i);            //����Y��̶�
		pDC->LineTo(18, 288 - 20 * i);
	}

	/*����ֱ��ͼ��Ҫ�Ĵ���*/
	for (i = 1; i<256; i++)
	{
		pDC->MoveTo(15 + i, 288);
		if ((288 - 167) >(Green[i] / 40))
			pDC->LineTo(15 + i, 288 - (Green[i] / 40));
		else
			pDC->LineTo(15 + i, 167);            //�������εĻ����θ�
	}


	/**********************/
	/*�ص�:��ֱ��ͼ ��ɫ
	/***************((*****/
	CPen *BluePen = new CPen();                            //�������ʶ���
	BluePen->CreatePen(PS_SOLID, 1, RGB(0, 0, 255));         //��ɫ����
	CGdiObject *BlueOlderPen = pDC->SelectObject(BluePen);

	pDC->Rectangle(9, 327, 312, 468);      //��һ�����ο�
	pDC->MoveTo(15, 331);                //����������
	pDC->LineTo(15, 448);                //Y����
	pDC->LineTo(305, 448);               //X����

	pDC->MoveTo(305, 448);               //����X��ͷ
	pDC->LineTo(300, 443);               //�����ϱ߼�ͷ
	pDC->MoveTo(305, 448);
	pDC->LineTo(300, 453);               //�����±߼�ͷ

	pDC->MoveTo(15, 331);                //����Y��ͷ
	pDC->LineTo(10, 336);                //������߼�ͷ
	pDC->MoveTo(15, 331);
	pDC->LineTo(20, 336);                //�����ұ߼�ͷ


	for (i = 0; i <= 5; i++)                   //дX��̶���
	{
		str.Format(_T("%d"), i * 50);               //0-255֮�����6���̶�ֵ
		pDC->SetTextColor(RGB(255, 0, 255));   //����������ɫ
		pDC->TextOut(15 + 48 * i, 450, str);       //�������

		pDC->MoveTo(15 + 48 * i, 448);            //����X��̶�
		pDC->LineTo(15 + 48 * i, 445);
	}
	for (i = 0; i <= 5; i++)                        //дY��̶���
	{
		pDC->MoveTo(15, 448 - 20 * i);            //����Y��̶�
		pDC->LineTo(18, 448 - 20 * i);
	}

	/*����ֱ��ͼ��Ҫ�Ĵ���*/
	for (i = 1; i<256; i++)
	{
		pDC->MoveTo(15 + i, 448);
		if ((448 - 327) >(Blue[i] / 40))
			pDC->LineTo(15 + i, 448 - (Blue[i] / 40));
		else
			pDC->LineTo(15 + i, 327);            //�������εĻ����θ�
	}


	//�ָ���ǰ�Ļ���
	pDC->SelectObject(RedOlderPen);
	pDC->SelectObject(GreenOlderPen);
	pDC->SelectObject(BlueOlderPen);
	delete RedPen;
	delete GreenPen;
	delete BluePen;
	ReleaseDC(pDC);
	return;

}
