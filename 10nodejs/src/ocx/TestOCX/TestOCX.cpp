// TestOCX.cpp : CTestOCXApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "TestOCX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CTestOCXApp theApp;

const GUID CDECL _tlid = { 0x3F91FFE5, 0xC6D9, 0x4CB6, { 0xBE, 0x23, 0x38, 0xE3, 0x72, 0x10, 0x6A, 0x16 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CTestOCXApp::InitInstance - DLL ��ʼ��

BOOL CTestOCXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CTestOCXApp::ExitInstance - DLL ��ֹ

int CTestOCXApp::ExitInstance()
{
	// TODO: �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
