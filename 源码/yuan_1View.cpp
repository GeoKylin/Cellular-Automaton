
// yuan_1View.cpp : Cyuan_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cyuan_1View ����/����

Cyuan_1View::Cyuan_1View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cyuan_1View::~Cyuan_1View()
{
}

BOOL Cyuan_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cyuan_1View ����

//////////////////////////////////  ���������  ///////////////////////////
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

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���_matrix
	////////////////////////////  �������  ///////////////////////////////////
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
				////////////////////////////////  ��ֵ����  ///////////////////////////////////
				//��ɫ�����
				red.zuo_shang = rule_red % 3;
				rule_red = rule_red / 3;
				red.you_shang = rule_red % 3;
				rule_red = rule_red / 3;
				red.zuo_xia = rule_red % 3;
				rule_red = rule_red / 3;
				red.you_xia = rule_red % 3;
				//��ɫ�����
				green.zuo_shang = rule_green % 3;
				rule_green = rule_green / 3;
				green.you_shang = rule_green % 3;
				rule_green = rule_green / 3;
				green.zuo_xia = rule_green % 3;
				rule_green = rule_green / 3;
				green.you_xia = rule_green % 3;
				//��ɫ�����
				blue.zuo_shang = rule_blue % 3;
				rule_blue = rule_blue / 3;
				blue.you_shang = rule_blue % 3;
				rule_blue = rule_blue / 3;
				blue.zuo_xia = rule_blue % 3;
				rule_blue = rule_blue / 3;
				blue.you_xia = rule_blue % 3;
				/////////////////////////////////  ��ʼ������  /////////////////////////////////
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
				/////////////////////////////////   ����      //////////////////////////////////			
				for (int i = 0; i < 8; i++)
				{
					Invalidate();
					////////////////////////////  ���û���  ///////////////////////////////////
					CPen blackp(PS_SOLID, 1, RGB(0, 0, 0));
					CPen redp(PS_SOLID, 1, RGB(255, 0, 0));
					CPen greenp(PS_SOLID, 1, RGB(0, 255, 0));
					CPen bluep(PS_SOLID, 1, RGB(0, 0, 255));
					CGdiObject *pOld = pDC->SelectObject(&blackp);
					//////////////////////////  ��ʾ���  /////////////////////////////////////		
					s.Format(_T("����: %d"), i);
					pDC->TextOut(570, 30, s);
					pDC->TextOut(560, 50, _T("������룺"));
					s.Format(_T("��ɫ: %3d"), h1);
					pDC->TextOut(570, 70, s);
					s.Format(_T("��ɫ: %3d"), h2);
					pDC->TextOut(570, 90, s);
					s.Format(_T("��ɫ: %3d"), h3);
					pDC->TextOut(570, 110, s);
					///////////////////////////  ��ͼ  ////////////////////////////////////////
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
					////////////////////////////  ����  /////////////////////////////////////
					for (int j = 0; j < pow(2.0, i); j++)
					{
						for (int k = 0; k < pow(2.0, i); k++)
						{
							//��ɫ
							if (_matrix[int(j*pow(2.0, count - i))][int(k*pow(2.0, count - i))] == 1)
							{
								for (int l = 0; l < pow(2.0, count - i - 1); l++)
								{
									//���Ͻ�
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + l)][int(k*pow(2.0, count - i)) + m] = red.zuo_shang;
									}
									//���Ͻ�
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i)) + l][int(k*pow(2.0, count - i) + pow(2.0, count - i - 1)) + m] = red.you_shang;
									}
									//���½�
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + pow(2.0, count - i - 1)) + l][int(k*pow(2.0, count - i)) + m] = red.zuo_xia;
									}
									//���½�
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + pow(2.0, count - i - 1)) + l][int(k*pow(2.0, count - i) + pow(2.0, count - i - 1)) + m] = red.you_xia;
									}
								}
							}
							//��ɫ
							else if (_matrix[int(j*pow(2.0, count - i))][int(k*pow(2.0, count - i))] == 0)
							{
								for (int l = 0; l < pow(2.0, count - i - 1); l++)
								{
									//���Ͻ�								
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + l)][int(k*pow(2.0, count - i)) + m] = green.zuo_shang;
									}
									//���Ͻ�
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i)) + l][int(k*pow(2.0, count - i) + pow(2.0, count - i - 1)) + m] = green.you_shang;
									}
									//���½�
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + pow(2.0, count - i - 1)) + l][int(k*pow(2.0, count - i)) + m] = green.zuo_xia;
									}
									//���½�
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + pow(2.0, count - i - 1)) + l][int(k*pow(2.0, count - i) + pow(2.0, count - i - 1)) + m] = green.you_xia;
									}
								}
							}
							//��ɫ
							else if (_matrix[int(j*pow(2.0, count - i))][int(k*pow(2.0, count - i))] == 2)
							{
								for (int l = 0; l < pow(2.0, count - i - 1); l++)
								{
									//���Ͻ�								
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + l)][int(k*pow(2.0, count - i)) + m] = blue.zuo_shang;
									}
									//���Ͻ�
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i)) + l][int(k*pow(2.0, count - i) + pow(2.0, count - i - 1)) + m] = blue.you_shang;
									}
									//���½�
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + pow(2.0, count - i - 1)) + l][int(k*pow(2.0, count - i)) + m] = blue.zuo_xia;
									}
									//���½�
									for (int m = 0; m < pow(2.0, count - i - 1); m++)
									{
										_matrix[int(j*pow(2.0, count - i) + pow(2.0, count - i - 1)) + l][int(k*pow(2.0, count - i) + pow(2.0, count - i - 1)) + m] = blue.you_xia;
									}
								}
							}
						}
					}
					///////////////////////////  ��ԭ  ////////////////////////////////////////
					pDC->SelectObject(&redp);
					Sleep(2000);
				}
				Sleep(2000);
			}
		}
	}
}


// Cyuan_1View ��ӡ

BOOL Cyuan_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cyuan_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cyuan_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// Cyuan_1View ���

#ifdef _DEBUG
void Cyuan_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cyuan_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cyuan_1Doc* Cyuan_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cyuan_1Doc)));
	return (Cyuan_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cyuan_1View ��Ϣ�������
