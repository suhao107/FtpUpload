// FtpUpLoadFilesCtrl.cpp : CFtpUpLoadFilesCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "FtpUpLoadFiles.h"
#include "FtpUpLoadFilesCtrl.h"
#include "FtpUpLoadFilesPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CFtpUpLoadFilesCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CFtpUpLoadFilesCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CFtpUpLoadFilesCtrl, COleControl)
	DISP_FUNCTION_ID(CFtpUpLoadFilesCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
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


// CFtpUpLoadFilesCtrl::AboutBox - ���û���ʾ�����ڡ���

void CFtpUpLoadFilesCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_FTPUPLOADFILES);
	dlgAbout.DoModal();
}


// CFtpUpLoadFilesCtrl ��Ϣ�������
