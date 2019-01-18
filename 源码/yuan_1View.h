
// yuan_1View.h : Cyuan_1View 类的接口
//

#pragma once


class Cyuan_1View : public CView
{
protected: // 仅从序列化创建
	Cyuan_1View();
	DECLARE_DYNCREATE(Cyuan_1View)

// 特性
public:
	Cyuan_1Doc* GetDocument() const;

// 操作
public:
	int _matrix[512][512];

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cyuan_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // yuan_1View.cpp 中的调试版本
inline Cyuan_1Doc* Cyuan_1View::GetDocument() const
   { return reinterpret_cast<Cyuan_1Doc*>(m_pDocument); }
#endif

