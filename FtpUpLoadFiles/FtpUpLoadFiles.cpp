// FtpUpLoadFiles.cpp : CFtpUpLoadFilesApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "FtpUpLoadFiles.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CFtpUpLoadFilesApp theApp;

const GUID CDECL _tlid = { 0xDEDDF17A, 0x385B, 0x495F, { 0x88, 0x5D, 0x3, 0xD7, 0x14, 0xB7, 0x66, 0x56 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CFtpUpLoadFilesApp::InitInstance - DLL ��ʼ��

BOOL CFtpUpLoadFilesApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CFtpUpLoadFilesApp::ExitInstance - DLL ��ֹ

int CFtpUpLoadFilesApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

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
