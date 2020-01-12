// ImageZFTDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Image_Processing.h"
#include "ImageZFTDlg.h"
#include "afxdialogex.h"


// CImageZFTDlg 对话框

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


// CImageZFTDlg 消息处理程序


afx_msg LRESULT CImageZFTDlg::OnInitdialog(WPARAM wParam, LPARAM lParam)
{
	return 0;
}


void CImageZFTDlg::OnZftYt()
{
	// TODO:  在此添加命令处理程序代码
}


void CImageZFTDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	// TODO: Add your message handler code here

	CRect rectpic;
	GetDlgItem(IDC_STATIC_KJ)->GetWindowRect(&rectpic);

	int x, y;
	x = rectpic.Width();
	y = rectpic.Height();

	CWnd *pWnd = GetDlgItem(IDC_STATIC_KJ);
	CDC *pDC = pWnd->GetDC();

	/***********************/
	/*重点:画直方图 红色
	/**********************/
	CPen *RedPen = new CPen();                              //创建画笔对象
	RedPen->CreatePen(PS_SOLID, 1, RGB(255, 0, 0));           //红色画笔
	CGdiObject *RedOlderPen = pDC->SelectObject(RedPen);    //选中当前红色画笔并保存以前的画笔

	/*画图*/
	pDC->Rectangle(9, 16, 312, 147);      //画一个矩形框
	pDC->MoveTo(15, 20);                //绘制坐标轴
	pDC->LineTo(15, 128);               //Y竖轴
	pDC->LineTo(305, 128);              //X横轴

	pDC->MoveTo(305, 128);              //绘制X箭头
	pDC->LineTo(300, 123);              //绘制上边箭头
	pDC->MoveTo(305, 128);
	pDC->LineTo(300, 133);              //绘制下边箭头

	pDC->MoveTo(15, 20);                //绘制Y箭头
	pDC->LineTo(10, 25);                //绘制左边箭头
	pDC->MoveTo(15, 20);
	pDC->LineTo(20, 25);                //绘制右边箭头

	/**********************************************************************/
	/* TextOut函数功能:
	/* 该函数用当前选择的字体、背景颜色和正文颜色将一个字符串写到指定位置
	/* BOOL TextOut(HDC hdc,int x,int y,LPCTSTR str,int numStr)
	/* 表示:x起始坐标,y起始坐标,字符串,字符串中字符个数
	/*
	/* SetTextColor函数功能:
	/* 设置指定设备环境(HDC)的字体颜色
	/* SetTextColor (HDC, COLORREF) 如:SetTextColor(HDC,RGB(255,0,0));
	/**********************************************************************/

	CString str;
	int i;
	for (i = 0; i <= 5; i++)                    //写X轴刻度线
	{
		str.Format(_T("%d"), i * 50);               //0-255之间添加6个刻度值
		pDC->SetTextColor(RGB(255, 0, 255));   //设置字体颜色
		pDC->TextOut(15 + 48 * i, 130, str);       //输出字体
		pDC->MoveTo(15 + 48 * i, 128);            //绘制X轴刻度
		pDC->LineTo(15 + 48 * i, 125);
	}
	for (i = 0; i <= 5; i++)                        //写Y轴刻度线
	{
		pDC->MoveTo(15, 128 - 20 * i);            //绘制Y轴刻度
		pDC->LineTo(18, 128 - 20 * i);
	}

	/*绘制直方图主要的代码*/
	for (i = 1; i<256; i++)
	{
		pDC->MoveTo(15 + i, 128);
		if ((128 - 16) >(Red[i] / 40))
			pDC->LineTo(15 + i, 128 - (Red[i] / 40));
		else
			pDC->LineTo(15 + i, 16);            //超过矩形的画矩形高
	}


	/**********************/
	/*重点:画直方图 绿色
	/**********************/
	CPen *GreenPen = new CPen();                             //创建画笔对象
	GreenPen->CreatePen(PS_SOLID, 1, RGB(0, 255, 0));          //绿色画笔
	CGdiObject *GreenOlderPen = pDC->SelectObject(GreenPen);

	pDC->Rectangle(9, 167, 312, 308);     //画一个矩形框
	pDC->MoveTo(15, 171);               //绘制坐标轴
	pDC->LineTo(15, 288);               //Y竖轴
	pDC->LineTo(305, 288);              //X横轴

	pDC->MoveTo(305, 288);              //绘制X箭头
	pDC->LineTo(300, 283);              //绘制上边箭头
	pDC->MoveTo(305, 288);
	pDC->LineTo(300, 293);              //绘制下边箭头

	pDC->MoveTo(15, 171);                //绘制Y箭头
	pDC->LineTo(10, 176);                //绘制左边箭头
	pDC->MoveTo(15, 171);
	pDC->LineTo(20, 176);                //绘制右边箭头

	for (i = 0; i <= 5; i++)                   //写X轴刻度线
	{
		str.Format(_T("%d"), i * 50);               //0-255之间添加6个刻度值
		pDC->SetTextColor(RGB(255, 0, 255));   //设置字体颜色
		pDC->TextOut(15 + 48 * i, 290, str);       //输出字体

		pDC->MoveTo(15 + 48 * i, 288);            //绘制X轴刻度
		pDC->LineTo(15 + 48 * i, 285);
	}
	for (i = 0; i <= 5; i++)                        //写Y轴刻度线
	{
		pDC->MoveTo(15, 288 - 20 * i);            //绘制Y轴刻度
		pDC->LineTo(18, 288 - 20 * i);
	}

	/*绘制直方图主要的代码*/
	for (i = 1; i<256; i++)
	{
		pDC->MoveTo(15 + i, 288);
		if ((288 - 167) >(Green[i] / 40))
			pDC->LineTo(15 + i, 288 - (Green[i] / 40));
		else
			pDC->LineTo(15 + i, 167);            //超过矩形的画矩形高
	}


	/**********************/
	/*重点:画直方图 蓝色
	/***************((*****/
	CPen *BluePen = new CPen();                            //创建画笔对象
	BluePen->CreatePen(PS_SOLID, 1, RGB(0, 0, 255));         //蓝色画笔
	CGdiObject *BlueOlderPen = pDC->SelectObject(BluePen);

	pDC->Rectangle(9, 327, 312, 468);      //画一个矩形框
	pDC->MoveTo(15, 331);                //绘制坐标轴
	pDC->LineTo(15, 448);                //Y竖轴
	pDC->LineTo(305, 448);               //X横轴

	pDC->MoveTo(305, 448);               //绘制X箭头
	pDC->LineTo(300, 443);               //绘制上边箭头
	pDC->MoveTo(305, 448);
	pDC->LineTo(300, 453);               //绘制下边箭头

	pDC->MoveTo(15, 331);                //绘制Y箭头
	pDC->LineTo(10, 336);                //绘制左边箭头
	pDC->MoveTo(15, 331);
	pDC->LineTo(20, 336);                //绘制右边箭头


	for (i = 0; i <= 5; i++)                   //写X轴刻度线
	{
		str.Format(_T("%d"), i * 50);               //0-255之间添加6个刻度值
		pDC->SetTextColor(RGB(255, 0, 255));   //设置字体颜色
		pDC->TextOut(15 + 48 * i, 450, str);       //输出字体

		pDC->MoveTo(15 + 48 * i, 448);            //绘制X轴刻度
		pDC->LineTo(15 + 48 * i, 445);
	}
	for (i = 0; i <= 5; i++)                        //写Y轴刻度线
	{
		pDC->MoveTo(15, 448 - 20 * i);            //绘制Y轴刻度
		pDC->LineTo(18, 448 - 20 * i);
	}

	/*绘制直方图主要的代码*/
	for (i = 1; i<256; i++)
	{
		pDC->MoveTo(15 + i, 448);
		if ((448 - 327) >(Blue[i] / 40))
			pDC->LineTo(15 + i, 448 - (Blue[i] / 40));
		else
			pDC->LineTo(15 + i, 327);            //超过矩形的画矩形高
	}


	//恢复以前的画笔
	pDC->SelectObject(RedOlderPen);
	pDC->SelectObject(GreenOlderPen);
	pDC->SelectObject(BlueOlderPen);
	delete RedPen;
	delete GreenPen;
	delete BluePen;
	ReleaseDC(pDC);
	return;

}
