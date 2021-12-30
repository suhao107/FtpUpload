#pragma once
#include <Windows.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <comutil.h>
#include   <afxpriv.h>
#include <curl/curl.h>
#ifdef _DEBUG
#pragma comment(lib,"libcurl-d.lib")
#else
#pragma comment(lib,"libcurl.lib")
#endif
#pragma comment(lib, "comsupp.lib")

using namespace std;
// FtpUpLoadFilesCtrl.h : CFtpUpLoadFilesCtrl ActiveX �ؼ����������


// CFtpUpLoadFilesCtrl : �й�ʵ�ֵ���Ϣ������� FtpUpLoadFilesCtrl.cpp��

#define TIME_IN_US 1  
#define TIMETYPE curl_off_t
#define TIMEOPT CURLINFO_TOTAL_TIME_T
#define MINIMAL_PROGRESS_FUNCTIONALITY_INTERVAL     3000000

struct FtpProgress {
	TIMETYPE lastruntime; /* type depends on version, see above */
	CURL *curl;
	void* m_dlg;
	double nCurrUpLoadFileSize;//��ǰ�ϴ��ļ�����
	bool IsUploadStop;
};

class CFtpUpLoadFilesCtrl : public COleControl
{
	DECLARE_DYNCREATE(CFtpUpLoadFilesCtrl)

// ���캯��
public:
	CFtpUpLoadFilesCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	BOOL IsInvokeAllowed(DISPID);
// ʵ��
protected:
	~CFtpUpLoadFilesCtrl();

	DECLARE_OLECREATE_EX(CFtpUpLoadFilesCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CFtpUpLoadFilesCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CFtpUpLoadFilesCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CFtpUpLoadFilesCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		dispidgetTaskComlete = 5L,
		dispidsetThreadStop = 4L,
		dispidgetCurrCompleteFiles = 3L,
		dispidgetUploadProgress = 2L,
		dispidUpLoadFiles = 1L
	};
protected:
	LONG UpLoadFiles(BSTR* PathFile, BSTR* FtpData);
	BSTR getUploadProgress();
	BSTR getCurrCompleteFiles();
	LONG setThreadStop();
	LONG getTaskComlete();
	bool Upload();
private:
	CString m_cFtpIP;
	CString m_cFtpPort;
	CString m_cFtpUser;
	CString m_cFtpPassword;
	CStringArray m_gSelectFilePath;
	CStringArray m_gErrPath;
	CStringArray m_gUpCompleteFiles;
	CWinThread * UploadThread;    //�߳�
	CURL *m_pCurlFtp;
	long uploaded_len = 0;
	static long long m_intCurrentSizes;//��ǰ��������
	struct FtpProgress m_gFtpProgress;
private:
	void AnalysisFilePath(CString files);
	bool AnalysisFtp(CString ftp);
	static UINT __cdecl UploadRunting(LPVOID lpParam);//�߳�
	void setCurlFtpCfg();
	CString GetFileTitleFromFileName(const CString& path);
	static size_t getContentLengthFunc(void *ptr, size_t size, size_t nmemb, void *stream);
	static size_t discardFunc(void *ptr, size_t size, size_t nmemb, void *stream);
	static size_t readfunc(void *ptr, size_t size, size_t nmemb, void *stream);
	static int handleProgress(void *p, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow);
};

