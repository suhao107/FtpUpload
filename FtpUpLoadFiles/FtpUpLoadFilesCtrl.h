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
// FtpUpLoadFilesCtrl.h : CFtpUpLoadFilesCtrl ActiveX 控件类的声明。


// CFtpUpLoadFilesCtrl : 有关实现的信息，请参阅 FtpUpLoadFilesCtrl.cpp。

#define TIME_IN_US 1  
#define TIMETYPE curl_off_t
#define TIMEOPT CURLINFO_TOTAL_TIME_T
#define MINIMAL_PROGRESS_FUNCTIONALITY_INTERVAL     3000000

struct FtpProgress {
	TIMETYPE lastruntime; /* type depends on version, see above */
	CURL *curl;
	void* m_dlg;
	double nCurrUpLoadFileSize;//当前上传文件速率
	bool IsUploadStop;
};

class CFtpUpLoadFilesCtrl : public COleControl
{
	DECLARE_DYNCREATE(CFtpUpLoadFilesCtrl)

// 构造函数
public:
	CFtpUpLoadFilesCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	BOOL IsInvokeAllowed(DISPID);
// 实现
protected:
	~CFtpUpLoadFilesCtrl();

	DECLARE_OLECREATE_EX(CFtpUpLoadFilesCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CFtpUpLoadFilesCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CFtpUpLoadFilesCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CFtpUpLoadFilesCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
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
	CWinThread * UploadThread;    //线程
	CURL *m_pCurlFtp;
	long uploaded_len = 0;
	static long long m_intCurrentSizes;//当前传输总量
	struct FtpProgress m_gFtpProgress;
private:
	void AnalysisFilePath(CString files);
	bool AnalysisFtp(CString ftp);
	static UINT __cdecl UploadRunting(LPVOID lpParam);//线程
	void setCurlFtpCfg();
	CString GetFileTitleFromFileName(const CString& path);
	static size_t getContentLengthFunc(void *ptr, size_t size, size_t nmemb, void *stream);
	static size_t discardFunc(void *ptr, size_t size, size_t nmemb, void *stream);
	static size_t readfunc(void *ptr, size_t size, size_t nmemb, void *stream);
	static int handleProgress(void *p, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow);
};

