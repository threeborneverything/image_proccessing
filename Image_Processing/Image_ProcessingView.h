
// Image_ProcessingView.h : CImage_ProcessingView ��Ľӿ�
//

#pragma once
#include "MyImage_.h"

class CImage_ProcessingView : public CScrollView
{
protected: // �������л�����
	CImage_ProcessingView();
	DECLARE_DYNCREATE(CImage_ProcessingView)

// ����
public:
	CImage_ProcessingDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CImage_ProcessingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
public:
	MyImage_ m_Image;
	MyImage_ mx_Image;
	MyImage_ x_Image[1024];
	int Red[256], Green[256], Blue[256];

	afx_msg void OnDrawline();
	afx_msg void OnFileSaveAs();
	afx_msg void OnShowred();
	afx_msg void OnViewToolbar();
	afx_msg void OnImageClass();
	afx_msg void OnImageClass168();
	afx_msg void OnImageClass64();
	afx_msg void OnImageClass32();
	afx_msg void OnImageClass16();
	afx_msg void OnImageClass4();
	afx_msg void OnImageClass8();
	afx_msg void OnImageClass2();
	afx_msg void ImageDifference();  
	afx_msg void ImageAdd();
	afx_msg void OnHistogram();
	afx_msg void OnImageEqualization();
	afx_msg void OnImageNormalization();
	afx_msg void OnImageMeanFiltering();
	afx_msg void OnMedianFiltering();
	afx_msg void OnImage_FFT();
	afx_msg void OnAotoFiltering();
	afx_msg void AotoFiltering(int ksize);
	afx_msg void OnShowRed();
	afx_msg void OnShowGreen();
	afx_msg void OnShowBlue();
	afx_msg void OnShowHSI();
	afx_msg void OnShowH();
	afx_msg void OnShowS();
	afx_msg void OnShowI();
	afx_msg void OnHoughLines();
	afx_msg void OnThresholdSegment();
	afx_msg void OnOtsuthreshold();
	afx_msg void OnHSIequalization();
	afx_msg void OnRGBequalization();
	afx_msg void OnRGBDivision();
};

#ifndef _DEBUG  // Image_ProcessingView.cpp �еĵ��԰汾
inline CImage_ProcessingDoc* CImage_ProcessingView::GetDocument() const
   { return reinterpret_cast<CImage_ProcessingDoc*>(m_pDocument); }
#endif

