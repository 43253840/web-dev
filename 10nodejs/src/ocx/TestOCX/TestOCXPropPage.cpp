// TestOCXPropPage.cpp : CTestOCXPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "TestOCX.h"
#include "TestOCXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CTestOCXPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CTestOCXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CTestOCXPropPage, "TESTOCX.TestOCXPropPage.1",
	0x1f087bbc, 0x7d7b, 0x455f, 0x9f, 0x84, 0x6e, 0x4d, 0x7d, 0xad, 0x75, 0x6)

// CTestOCXPropPage::CTestOCXPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CTestOCXPropPage ��ϵͳע�����

BOOL CTestOCXPropPage::CTestOCXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_TESTOCX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CTestOCXPropPage::CTestOCXPropPage - ���캯��

CTestOCXPropPage::CTestOCXPropPage() :
	COlePropertyPage(IDD, IDS_TESTOCX_PPG_CAPTION)
{
}

// CTestOCXPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CTestOCXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CTestOCXPropPage ��Ϣ�������
