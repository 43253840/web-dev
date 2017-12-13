// TestOCXCtrl.cpp : CTestOCXCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "TestOCX.h"
#include "TestOCXCtrl.h"
#include "TestOCXPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CTestOCXCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CTestOCXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CTestOCXCtrl, COleControl)
	DISP_FUNCTION_ID(CTestOCXCtrl, "test", dispidtest, test, VT_I4, VTS_I4 VTS_I4)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CTestOCXCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO: ����Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CTestOCXCtrl, 1)
	PROPPAGEID(CTestOCXPropPage::guid)
END_PROPPAGEIDS(CTestOCXCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CTestOCXCtrl, "TESTOCX.TestOCXCtrl.1",
	0x64947e15, 0x852e, 0x496e, 0xb3, 0xb1, 0xac, 0xcf, 0x57, 0x42, 0xbd, 0x4c)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CTestOCXCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DTestOCX = { 0x1DB9F27, 0x7338, 0x43E5, { 0xA9, 0xFD, 0xC2, 0x37, 0x3E, 0x9F, 0xF7, 0x44 } };
const IID IID_DTestOCXEvents = { 0xE0DD2328, 0xEA9, 0x41CF, { 0x85, 0x8D, 0x94, 0x73, 0x3, 0x9C, 0x33, 0xB3 } };

// �ؼ�������Ϣ

static const DWORD _dwTestOCXOleMisc =
	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CTestOCXCtrl, IDS_TESTOCX, _dwTestOCXOleMisc)

// CTestOCXCtrl::CTestOCXCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CTestOCXCtrl ��ϵͳע�����

BOOL CTestOCXCtrl::CTestOCXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_TESTOCX,
			IDB_TESTOCX,
			afxRegApartmentThreading,
			_dwTestOCXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CTestOCXCtrl::CTestOCXCtrl - ���캯��

CTestOCXCtrl::CTestOCXCtrl()
{
	InitializeIIDs(&IID_DTestOCX, &IID_DTestOCXEvents);
	// TODO: �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}



// CTestOCXCtrl::~CTestOCXCtrl - ��������

CTestOCXCtrl::~CTestOCXCtrl()
{
	// TODO: �ڴ�����ؼ���ʵ�����ݡ�
}


BOOL CTestOCXCtrl::IsInvokeAllowed (DISPID)
{
	return true;
}

// CTestOCXCtrl::OnDraw - ��ͼ����

void CTestOCXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CTestOCXCtrl::DoPropExchange - �־���֧��

void CTestOCXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CTestOCXCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CTestOCXCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO: �ڴ��������������ؼ�״̬��
}


// CTestOCXCtrl ��Ϣ�������


LONG CTestOCXCtrl::test(LONG a, LONG b)
{
	//AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������

	return a + b;
}

