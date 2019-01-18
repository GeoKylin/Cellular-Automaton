
// yuan_1View.cpp : Cyuan_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "yuan_1.h"
#endif

#include "yuan_1Doc.h"
#include "yuan_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cyuan_1View

IMPLEMENT_DYNCREATE(Cyuan_1View, CView)

BEGIN_MESSAGE_MAP(Cyuan_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cyuan_1View 构造/析构

Cyuan_1View::Cyuan_1View()
{
	// TODO:  在此处添加构造代码

}

Cyuan_1View::~Cyuan_1View()
{
}

BOOL Cyuan_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cyuan_1View 绘制

//////////////////////////////////  定义规则类  ///////////////////////////
class rule
{
public:
	int you_shang;
	int you_xia;
	int zuo_xia;
	int zuo_shang;
};

void Cyuan_1View::OnDraw(CDC* pDC)
{
	Cyuan_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码_matrix
	////////////////////////////  定义参数  ///////////////////////////////////
	int step = 20;
	int count = 9;		//longth= pow(2.0, count)
	int location_x = 40, location_y = 10;
	CString s;
	rule red;
	rule green;
	rule blue;
	int h1, h2;

	for (h1 = 0; h1 < 81; h1++)
	{
		for (h2 = 0; h2 < 81; h2++)
		{
			for (int h3 = 0; h3 < 81; h3++)
			{
				/*************/
				h1 = 37;
				h2 = 0;
				h3 = 0;
				/*************/
				int rule_red = h1;
				int rule_green = h2;
				int rule_blue = h3;
				////////////////////////////////  赋值规则  ///////////////////////////////////
				//红色格规则
				red.zuo_shang = rule_red % 3;
				rule_red = rule_red / 3;
				red.you_shang = rule_red % 3;
				rule_red = rule_red / 3;
				red.zuo_xia = rule_red % 3;
				rule_red = rule_red / 3;
				red.you_xia = rule_red % 3;
				//绿色格规则
				green.zuo_shang = rule_green % 3;
				rule_green = rule_green / 3;
				green.you_shang = rule_green % 3;
				rule_green = rule_green / 3;
				green.zuo_xia = rule_green % 3;
				rule_green = rule_green / 3;
				green.you_xia = rule_green % 3;
				//蓝色格规则
				blue.zuo_shang = rule_blue % 3;
				rule_blue = rule_blue / 3;
				blue.you_shang = rule_blue % 3;
				rule_blue = rule_blue / 3;
				blue.zuo_xia = rule_blue % 3;
				rule_blue = rule_blue / 3;
				blue.you_xia = rule_blue % 3;
				/////////////////////////////////  初始化矩阵  /////////////////////////////////
				for (int i = 0; i < 512/2; i++)
				{
					for (int j = 0; j < 512/2; j++)
					{
						_matrix[i][j] = 1;
					}
				}
				for (int i = 0; i < 512/2; i++)
				{
					for (int j = 256; j < 512; j++)
					{
						_matrix[i][j] = 1;
					}
				}
				for (int i = 256; i < 512; i++)
				{
					for (int j = 0; j < 512 / 2; j++)
					{
						_matrix[i][j] = 1;
					}
				}
				for (int i = 256; i < 512; i++)
				{
					for (int j = 256; j < 512; j++)
					{
						_matrix[i][j] = 1;
					}
				}
				/////////////////////////////////   迭代      //////////////////////////////////			
				for (int i = 0; i < 8; i++)
				{
					Invalidate();
					////////////////////////////  设置画笔  ///////////////////////////////////
					CPen blackp(PS_SOLID, 1, RGB(0, 0, 0));
					CPen redp(PS_SOLID, 1, RGB(255, 0, 0));
					CPen greenp(PS_SOLID, 1, RGB(0, 255, 0));
					CPen bluep(PS_SOLID, 1, RGB(0, 0, 255));
					CGdiObject *pOld = pDC->SelectObject(&blackp);
					//////////////////////////  显示编号  /////////////////////////////////////		
					s.Format(_T("代数: %d"), i);
					pDC->TextOut(570, 30, s);
					pDC->TextOut(560, 50, _T("规则代码："));
					s.Format(_T("红色: %3d"), h1);
					pDC->TextOut(570, 70, s);
					s.Format(_T("绿色: %3d"), h2);
					pDC->TextOut(570, 90, s);
					s.Format(_T("蓝色: %3d"), h3);
					pDC->TextOut(570, 110, s);
					///////////////////////////  绘图  ////////////////////////////////////////
					for (int j = 0; j < 512; j++)
					{
						for (int k = 0; k < 512; k++)
						{
							if (_matrix[j][k] == 0)
							{
								pDC->SelectObject(&greenp);
								pDC->MoveTo(location_x + k, location_y + j);
								pDC->LineTo(location_x + k + 1, location_y + j + 1);
							}
							if (_matrix[j][k] == 1)
							{
								pDC->SelectObject(&redp);
								pDC->MoveTo(location_x + k, location_y + j);
								pDC->LineTo(location_x + k + 1, location_y + j + 1);
							}
							if (_matrix[j][k] == 2)
							{
								pDC->SelectObject(&bluep);
								pDC->MoveTo(location_x + k, location_y + j);
								pDC->LineTo(location_x + k + 1, location_y + j + 1);
							}
						}
					}
					////////////////////////////  迭代  /////////////////////////////////////
					for (int j = 0; j < pow(2.0, i); j++)
					{
						for (int k = 0; k < pow(2.0, i); k++)
						{
							//红色
							if (_matrix[int(j*pow(2.0, count - i))][int(k*pow(2.0, count - i))] == 1)
							{
								for (int l = 0; l < pow(2.0, count - i - 1); l++)
								{
									//左上角
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + l)][int(k*pow(2.0, count - i)) + m] = red.zuo_shang;
									}
									//右上角
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i)) + l][int(k*pow(2.0, count - i) + pow(2.0, count - i - 1)) + m] = red.you_shang;
									}
									//左下角
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + pow(2.0, count - i - 1)) + l][int(k*pow(2.0, count - i)) + m] = red.zuo_xia;
									}
									//右下角
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + pow(2.0, count - i - 1)) + l][int(k*pow(2.0, count - i) + pow(2.0, count - i - 1)) + m] = red.you_xia;
									}
								}
							}
							//绿色
							else if (_matrix[int(j*pow(2.0, count - i))][int(k*pow(2.0, count - i))] == 0)
							{
								for (int l = 0; l < pow(2.0, count - i - 1); l++)
								{
									//左上角								
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + l)][int(k*pow(2.0, count - i)) + m] = green.zuo_shang;
									}
									//右上角
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i)) + l][int(k*pow(2.0, count - i) + pow(2.0, count - i - 1)) + m] = green.you_shang;
									}
									//左下角
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + pow(2.0, count - i - 1)) + l][int(k*pow(2.0, count - i)) + m] = green.zuo_xia;
									}
									//右下角
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + pow(2.0, count - i - 1)) + l][int(k*pow(2.0, count - i) + pow(2.0, count - i - 1)) + m] = green.you_xia;
									}
								}
							}
							//蓝色
							else if (_matrix[int(j*pow(2.0, count - i))][int(k*pow(2.0, count - i))] == 2)
							{
								for (int l = 0; l < pow(2.0, count - i - 1); l++)
								{
									//左上角								
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + l)][int(k*pow(2.0, count - i)) + m] = blue.zuo_shang;
									}
									//右上角
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i)) + l][int(k*pow(2.0, count - i) + pow(2.0, count - i - 1)) + m] = blue.you_shang;
									}
									//左下角
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + pow(2.0, count - i - 1)) + l][int(k*pow(2.0, count - i)) + m] = blue.zuo_xia;
									}
									//右下角
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + pow(2.0, count - i - 1)) + l][int(k*pow(2.0, count - i) + pow(2.0, count - i - 1)) + m] = blue.you_xia;
									}
								}
							}
						}
					}
					///////////////////////////  还原  ////////////////////////////////////////
					pDC->SelectObject(&redp);
					Sleep(2000);
				}
				Sleep(2000);
			}
		}
	}
}


// Cyuan_1View 打印

BOOL Cyuan_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cyuan_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void Cyuan_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// Cyuan_1View 诊断

#ifdef _DEBUG
void Cyuan_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cyuan_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cyuan_1Doc* Cyuan_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cyuan_1Doc)));
	return (Cyuan_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cyuan_1View 消息处理程序
