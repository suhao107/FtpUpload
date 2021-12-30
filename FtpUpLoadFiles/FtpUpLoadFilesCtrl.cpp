// FtpUpLoadFilesCtrl.cpp : CFtpUpLoadFilesCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "FtpUpLoadFiles.h"
#include "FtpUpLoadFilesCtrl.h"
#include "FtpUpLoadFilesPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


long long CFtpUpLoadFilesCtrl::m_intCurrentSizes = 0;


IMPLEMENT_DYNCREATE(CFtpUpLoadFilesCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CFtpUpLoadFilesCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CFtpUpLoadFilesCtrl, COleControl)
	DISP_FUNCTION_ID(CFtpUpLoadFilesCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CFtpUpLoadFilesCtrl, "UpLoadFiles", dispidUpLoadFiles, UpLoadFiles, VT_I4, VTS_PBSTR VTS_PBSTR)
	DISP_FUNCTION_ID(CFtpUpLoadFilesCtrl, "getUploadProgress", dispidgetUploadProgress, getUploadProgress, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CFtpUpLoadFilesCtrl, "getCurrCompleteFiles", dispidgetCurrCompleteFiles, getCurrCompleteFiles, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CFtpUpLoadFilesCtrl, "setThreadStop", dispidsetThreadStop, setThreadStop, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CFtpUpLoadFilesCtrl, "getTaskComlete", dispidgetTaskComlete, getTaskComlete, VT_I4, VTS_NONE)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CFtpUpLoadFilesCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO: ������Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CFtpUpLoadFilesCtrl, 1)
	PROPPAGEID(CFtpUpLoadFilesPropPage::guid)
END_PROPPAGEIDS(CFtpUpLoadFilesCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CFtpUpLoadFilesCtrl, "FtpUpLoadFiles.class",
	0x58caa706, 0x580, 0x4888, 0xbb, 0x5b, 0x44, 0x7a, 0x34, 0xc1, 0x98, 0x4f)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CFtpUpLoadFilesCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DFtpUpLoadFiles = { 0x5C3172B8, 0xCE50, 0x4DCB, { 0xB7, 0x68, 0x60, 0x50, 0x6B, 0xBC, 0xB4, 0xB6 } };
const IID IID_DFtpUpLoadFilesEvents = { 0x1F0FBEBE, 0x7F6F, 0x4339, { 0x80, 0x33, 0xB2, 0x64, 0x14, 0x3, 0xCD, 0x5A } };

// �ؼ�������Ϣ

static const DWORD _dwFtpUpLoadFilesOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CFtpUpLoadFilesCtrl, IDS_FTPUPLOADFILES, _dwFtpUpLoadFilesOleMisc)

// CFtpUpLoadFilesCtrl::CFtpUpLoadFilesCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CFtpUpLoadFilesCtrl ��ϵͳע�����

BOOL CFtpUpLoadFilesCtrl::CFtpUpLoadFilesCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_FTPUPLOADFILES,
			IDB_FTPUPLOADFILES,
			afxRegApartmentThreading,
			_dwFtpUpLoadFilesOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CFtpUpLoadFilesCtrl::CFtpUpLoadFilesCtrl - ���캯��

CFtpUpLoadFilesCtrl::CFtpUpLoadFilesCtrl()
{
	InitializeIIDs(&IID_DFtpUpLoadFiles, &IID_DFtpUpLoadFilesEvents);
	m_gUpCompleteFiles.RemoveAll();
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CFtpUpLoadFilesCtrl::~CFtpUpLoadFilesCtrl - ��������

CFtpUpLoadFilesCtrl::~CFtpUpLoadFilesCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

// CFtpUpLoadFilesCtrl::OnDraw - ��ͼ����

void CFtpUpLoadFilesCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CFtpUpLoadFilesCtrl::DoPropExchange - �־���֧��

void CFtpUpLoadFilesCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CFtpUpLoadFilesCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CFtpUpLoadFilesCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}

BOOL CFtpUpLoadFilesCtrl::IsInvokeAllowed(DISPID)
{
	// You can check to see if COleControl::m_bInitialized is FALSE 
	// in your automation functions to limit access. 
	return TRUE;
}


// CFtpUpLoadFilesCtrl::AboutBox - ���û���ʾ�����ڡ���

void CFtpUpLoadFilesCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_FTPUPLOADFILES);
	dlgAbout.DoModal();
}


// CFtpUpLoadFilesCtrl ��Ϣ�������


LONG CFtpUpLoadFilesCtrl::UpLoadFiles(BSTR* PathFile, BSTR* FtpData)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	assert(PathFile);
	assert(FtpData);
	CString temp(*PathFile);
	AnalysisFilePath(temp);
	temp = *FtpData;
	bool ret = AnalysisFtp(temp);
	if (!ret)
		return 1;//��ʾftpsever��Ϣ��ȫ
	UploadThread = AfxBeginThread((AFX_THREADPROC)UploadRunting, (LPVOID)this);
	return 0;
}


BSTR CFtpUpLoadFilesCtrl::getUploadProgress()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	strResult.Format(L"size: %d, bytes: %d, press: %d", 20, 30, 40);

	return strResult.AllocSysString();
}


BSTR CFtpUpLoadFilesCtrl::getCurrCompleteFiles()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString strResult;
	strResult.Format(L"%s", L"F:\\1111\\Speed.txt|F:\\1111\\Speed.txt|F:\\1111\\Speed.txt|F:\\1111\\Speed.txt");
	return strResult.AllocSysString();
}


LONG CFtpUpLoadFilesCtrl::setThreadStop()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	//����
	m_gFtpProgress.IsUploadStop = true;
	return 1;
}


LONG CFtpUpLoadFilesCtrl::getTaskComlete()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//���

	return 0;
}

bool CFtpUpLoadFilesCtrl::Upload()
{
	USES_CONVERSION;
	curl_global_init(CURL_GLOBAL_ALL);
	m_pCurlFtp = curl_easy_init();
	if (!m_pCurlFtp)
	{
		return 1;
	}
	else
	{
		CString m_remoteUrl = L"ftp://" + m_cFtpIP + L"/";
		m_gFtpProgress.curl = m_pCurlFtp;
		m_gFtpProgress.lastruntime = 0;
		m_gFtpProgress.m_dlg = this;
		m_gFtpProgress.nCurrUpLoadFileSize = 0;  //��ǰ�����ļ�ʱ�̴����С
		m_gFtpProgress.IsUploadStop = false;
		setCurlFtpCfg();

		FILE *hd_src;
		CFile localFile;
		CString url, base_url;
		char remote_file_path[1024] = { 0 };
		for (int i = 0, size = m_gSelectFilePath.GetSize(); i < size; ++i)
		{
			CString temp = m_gSelectFilePath.GetAt(i);
			DWORD nRet = localFile.Open(temp, CFile::modeRead | CFile::shareDenyRead);
			// �����ϴ����ļ���С
			curl_easy_setopt(m_pCurlFtp, CURLOPT_INFILESIZE_LARGE, (curl_off_t)localFile.GetLength());
			localFile.Close();
			// �����ϴ����ļ���
			string filepath = W2A(temp);
			hd_src = fopen(filepath.c_str(), "rb");
			curl_easy_setopt(m_pCurlFtp, CURLOPT_READDATA, hd_src);
			// �����ļ���
			curl_easy_setopt(m_pCurlFtp, CURLOPT_FTP_CREATE_MISSING_DIRS, 1);

			//����Զ��·��
			CString fileName = GetFileTitleFromFileName(temp);
			url = m_remoteUrl + fileName;
			sprintf(remote_file_path, "%s", T2A(url));
			curl_easy_setopt(m_pCurlFtp, CURLOPT_URL, remote_file_path);

			//��ʼ�ϴ�
			CURLcode res = curl_easy_perform(m_pCurlFtp);
			if (res != CURLE_OK)
			{
				if (m_gFtpProgress.IsUploadStop)
				{
					//�ϴ���ȡ����!
					if (hd_src > 0) fclose(hd_src);
					curl_easy_strerror(res);
					curl_global_cleanup();
					return 0;
				}
				else
				{
					//�ϴ�ʧ�ܣ�
					if (hd_src > 0) fclose(hd_src);
					curl_easy_strerror(res);
					return 1;
				}
			}
			else
			{
				m_gUpCompleteFiles.Add(temp);
			}
			//�ر��ļ���
			if (hd_src > 0)
				fclose(hd_src);
		}
	}
}

void CFtpUpLoadFilesCtrl::AnalysisFilePath(CString files)
{
	CString strGet("");
	m_gErrPath.RemoveAll();
	m_gSelectFilePath.RemoveAll();
	int i = 0;
	if (files != "")
	{
		while (AfxExtractSubString(strGet, files, i++, L'|'))
		{
			BOOL rec = PathFileExists(strGet);
			if (rec)
			{//����	
				m_gSelectFilePath.Add(strGet);
			}
			else 
			{// ������
				m_gErrPath.Add(strGet);
			}
			
		}	
	}
}

bool CFtpUpLoadFilesCtrl::AnalysisFtp(CString ftp)
{
	CString strGet(L"");
	int i = 0;
	if (ftp != "")
	{
		while (AfxExtractSubString(strGet, ftp, i++, L'|'))
		{
			if (i == 1)
				m_cFtpIP = strGet;
			else if(i == 2)
				m_cFtpUser = strGet;
			else if (i == 3)
				m_cFtpPassword = strGet;				
			else
				m_cFtpPort = strGet;
		}
		if (!m_cFtpIP.IsEmpty())
		{
			if (!m_cFtpUser.IsEmpty())
			{
				if (!m_cFtpPassword.IsEmpty())
				{
					if (!m_cFtpPort.IsEmpty())
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

UINT CFtpUpLoadFilesCtrl::UploadRunting(LPVOID lpParam)
{
	USES_CONVERSION;
	CFtpUpLoadFilesCtrl* this_ = (CFtpUpLoadFilesCtrl*)lpParam;
	if (this_)
	{
		this_->Upload();
		return 0;
	}
	else
	{
		return 1;
	}
	//curl_global_init(CURL_GLOBAL_ALL);
	//this_->m_pCurlFtp = curl_easy_init();
	//if (!this_->m_pCurlFtp)
	//{
	//	return 1;
	//}
	//else
	//{
	//	CString m_remoteUrl = L"ftp://" + this_->m_cFtpIP + L"/";
	//	this_->m_gFtpProgress.curl = this_->m_pCurlFtp;
	//	this_->m_gFtpProgress.lastruntime = 0;
	//	this_->m_gFtpProgress.m_dlg = this_;
	//	this_->m_gFtpProgress.nCurrUpLoadFileSize = 0;  //��ǰ�����ļ�ʱ�̴����С
	//	this_->m_gFtpProgress.IsUploadStop = false;
	//	this_->setCurlFtpCfg();

	//	FILE *hd_src;
	//	CFile localFile;
	//	CString url, base_url;
	//	char remote_file_path[1024] = { 0 };
	//	for (int i = 0, size = this_->m_gSelectFilePath.GetSize(); i < size; ++i)
	//	{
	//		CString temp = this_->m_gSelectFilePath.GetAt(i);		
	//		DWORD nRet = localFile.Open(temp, CFile::modeRead | CFile::shareDenyRead);
	//		// �����ϴ����ļ���С
	//		curl_easy_setopt(this_->m_pCurlFtp, CURLOPT_INFILESIZE_LARGE, (curl_off_t)localFile.GetLength());
	//		localFile.Close();
	//		// �����ϴ����ļ���
	//		string filepath = W2A(temp);
	//		hd_src = fopen(filepath.c_str(), "rb");		
	//		curl_easy_setopt(this_->m_pCurlFtp, CURLOPT_READDATA, hd_src);
	//		// �����ļ���
	//		curl_easy_setopt(this_->m_pCurlFtp, CURLOPT_FTP_CREATE_MISSING_DIRS, 1);
	//		
	//		//����Զ��·��
	//		CString fileName = this_->GetFileTitleFromFileName(temp);
	//		url = m_remoteUrl + fileName;
	//		sprintf(remote_file_path, "%s", T2A(url));
	//		curl_easy_setopt(this_->m_pCurlFtp, CURLOPT_URL, remote_file_path);

	//		//��ʼ�ϴ�
	//		CURLcode res = curl_easy_perform(this_->m_pCurlFtp);
	//		if (res != CURLE_OK)
	//		{
	//			if (this_->m_gFtpProgress.IsUploadStop)
	//			{
	//				//�ϴ���ȡ����!
	//				if (hd_src > 0) fclose(hd_src);
	//				curl_easy_strerror(res);
	//				curl_global_cleanup();
	//				return 0;
	//			}
	//			else
	//			{
	//				//�ϴ�ʧ�ܣ�
	//				if (hd_src > 0) fclose(hd_src);
	//				curl_easy_strerror(res);
	//				return 1;
	//			}
	//		}
	//		else
	//		{
	//			this_->m_gUpCompleteFiles.Add(temp);
	//		}
	//		//�ر��ļ���
	//		if (hd_src > 0) 
	//			fclose(hd_src);
	//	}
	//}
	return 0;
}

void CFtpUpLoadFilesCtrl::setCurlFtpCfg()
{
	USES_CONVERSION;
	curl_easy_setopt(m_pCurlFtp, CURLOPT_UPLOAD, 1L);
	char user_key[1024] = { 0 };
	sprintf(user_key, "%s:%s", T2A(m_cFtpUser), T2A(m_cFtpPassword));
	curl_easy_setopt(m_pCurlFtp, CURLOPT_USERPWD, user_key);
	curl_easy_setopt(m_pCurlFtp, CURLOPT_HEADERFUNCTION, getContentLengthFunc);
	curl_easy_setopt(m_pCurlFtp, CURLOPT_HEADERDATA, &uploaded_len);
	curl_easy_setopt(m_pCurlFtp, CURLOPT_WRITEFUNCTION, discardFunc);
	curl_easy_setopt(m_pCurlFtp, CURLOPT_READFUNCTION, readfunc);
	// ���Ȼص�����
	curl_easy_setopt(m_pCurlFtp, CURLOPT_NOPROGRESS, 0L);
	curl_easy_setopt(m_pCurlFtp, CURLOPT_XFERINFOFUNCTION, handleProgress);
	curl_easy_setopt(m_pCurlFtp, CURLOPT_XFERINFODATA, &m_gFtpProgress);
}

CString CFtpUpLoadFilesCtrl::GetFileTitleFromFileName(const CString & path)
{
	int nPos = path.ReverseFind('\\');
	CString tmpStr(path); //��ʱtmpStrΪ c:\\aa\\bb\\0015.dat
	if (nPos != -1) {
		tmpStr = tmpStr.Right(path.GetLength() - nPos - 1);
	}
	return tmpStr;
}

size_t CFtpUpLoadFilesCtrl::getContentLengthFunc(void * ptr, size_t size, size_t nmemb, void * stream)
{
	int r;
	long len = 0;

	r = sscanf((const char*)ptr, "Content-Length: %ld\n", &len);
	if (r) /* Microsoft: we don't read the specs */
		*((long *)stream) = len;
	return size * nmemb;
}

size_t CFtpUpLoadFilesCtrl::discardFunc(void * ptr, size_t size, size_t nmemb, void * stream)
{
	return size * nmemb;
}

size_t CFtpUpLoadFilesCtrl::readfunc(void * ptr, size_t size, size_t nmemb, void * stream)
{
	FILE *f = (FILE*)stream;
	size_t n;
	if (ferror(f))
		return CURL_READFUNC_ABORT;
	n = fread(ptr, size, nmemb, f) * size;
	return n;
}

int CFtpUpLoadFilesCtrl::handleProgress(void * p, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
	struct FtpProgress *myp = (struct FtpProgress *)p;
	CURL *curl = myp->curl;
	TIMETYPE curtime = 0;

	if (myp->IsUploadStop)
	{
		return 1;
	}
	curl_easy_getinfo(curl, TIMEOPT, &curtime);

	if ((curtime - myp->lastruntime) >= MINIMAL_PROGRESS_FUNCTIONALITY_INTERVAL) {
		myp->lastruntime = curtime;
#ifdef TIME_IN_US
		fprintf(stderr, "TOTAL TIME: %" CURL_FORMAT_CURL_OFF_T ".%06ld\r\n",
			(curtime / 1000000), (long)(curtime % 1000000));
#else
		fprintf(stderr, "TOTAL TIME: %f \r\n", curtime);
#endif
	}

	myp->nCurrUpLoadFileSize = ulnow;

	return 0;
}
