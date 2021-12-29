// FtpUpLoadFiles.cpp : CFtpUpLoadFilesApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "FtpUpLoadFiles.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CFtpUpLoadFilesApp theApp;

const GUID CDECL _tlid = { 0xDEDDF17A, 0x385B, 0x495F, { 0x88, 0x5D, 0x3, 0xD7, 0x14, 0xB7, 0x66, 0x56 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CFtpUpLoadFilesApp::InitInstance - DLL 初始化

BOOL CFtpUpLoadFilesApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CFtpUpLoadFilesApp::ExitInstance - DLL 终止

int CFtpUpLoadFilesApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
