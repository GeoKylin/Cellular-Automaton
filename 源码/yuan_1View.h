
// yuan_1View.h : Cyuan_1View ��Ľӿ�
//

#pragma once


class Cyuan_1View : public CView
{
protected: // �������л�����
	Cyuan_1View();
	DECLARE_DYNCREATE(Cyuan_1View)

// ����
public:
	Cyuan_1Doc* GetDocument() const;

// ����
public:
	int _matrix[512][512];

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Cyuan_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // yuan_1View.cpp �еĵ��԰汾
inline Cyuan_1Doc* Cyuan_1View::GetDocument() const
   { return reinterpret_cast<Cyuan_1Doc*>(m_pDocument); }
#endif

