#pragma once

// TestOCXCtrl.h : CTestOCXCtrl ActiveX �ؼ����������


// CTestOCXCtrl : �й�ʵ�ֵ���Ϣ������� TestOCXCtrl.cpp��

class CTestOCXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CTestOCXCtrl)

// ���캯��
public:
	CTestOCXCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual BOOL CTestOCXCtrl::IsInvokeAllowed (DISPID);

// ʵ��
protected:
	~CTestOCXCtrl();

	DECLARE_OLECREATE_EX(CTestOCXCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CTestOCXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CTestOCXCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CTestOCXCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		dispidtest = 1L
	};
protected:
	LONG test(LONG a, LONG b);
};

