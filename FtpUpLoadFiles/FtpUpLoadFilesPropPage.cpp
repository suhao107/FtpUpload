// FtpUpLoadFilesPropPage.cpp : CFtpUpLoadFilesPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "FtpUpLoadFiles.h"
#include "FtpUpLoadFilesPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CFtpUpLoadFilesPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CFtpUpLoadFilesPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CFtpUpLoadFilesPropPage, "FTPUPLOADFILES.FtpUpLoadFilesPropPage.1",
	0x1f289220, 0x84e8, 0x41ce, 0x82, 0x5f, 0x38, 0x96, 0xd2, 0xa6, 0x1e, 0xe2)

// CFtpUpLoadFilesPropPage::CFtpUpLoadFilesPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CFtpUpLoadFilesPropPage ��ϵͳע�����

BOOL CFtpUpLoadFilesPropPage::CFtpUpLoadFilesPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_FTPUPLOADFILES_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CFtpUpLoadFilesPropPage::CFtpUpLoadFilesPropPage - ���캯��

CFtpUpLoadFilesPropPage::CFtpUpLoadFilesPropPage() :
	COlePropertyPage(IDD, IDS_FTPUPLOADFILES_PPG_CAPTION)
{
}

// CFtpUpLoadFilesPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CFtpUpLoadFilesPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CFtpUpLoadFilesPropPage ��Ϣ�������
