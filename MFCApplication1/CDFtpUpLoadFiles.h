// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ����

#import "F:\\FanHan-Work\\FtpUpLoadFiles\\Debug\\FtpUpLoadFiles.ocx" no_namespace
// CDFtpUpLoadFiles ��װ����

class CDFtpUpLoadFiles : public COleDispatchDriver
{
public:
	CDFtpUpLoadFiles() {} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CDFtpUpLoadFiles(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDFtpUpLoadFiles(const CDFtpUpLoadFiles& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// _DFtpUpLoadFiles ����
public:
	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long UpLoadFiles(BSTR * PathFile, BSTR* FtpData)
	{
		long result;
		static BYTE parms[] = VTS_PBSTR VTS_PBSTR;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, parms, PathFile,FtpData);
		return result;
	}
	CString getUploadProgress()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString getCurrCompleteFiles()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long setThreadStop()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	
	long getTaskComlete()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	// _DFtpUpLoadFiles ����
public:

};
