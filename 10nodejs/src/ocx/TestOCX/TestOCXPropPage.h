#pragma once

// TestOCXPropPage.h : CTestOCXPropPage ����ҳ���������


// CTestOCXPropPage : �й�ʵ�ֵ���Ϣ������� TestOCXPropPage.cpp��

class CTestOCXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CTestOCXPropPage)
	DECLARE_OLECREATE_EX(CTestOCXPropPage)

// ���캯��
public:
	CTestOCXPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_TESTOCX };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

