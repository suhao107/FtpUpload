// FtpUpLoadFilesPropPage.cpp : CFtpUpLoadFilesPropPage 属性页类的实现。

#include "stdafx.h"
#include "FtpUpLoadFiles.h"
#include "FtpUpLoadFilesPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CFtpUpLoadFilesPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CFtpUpLoadFilesPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CFtpUpLoadFilesPropPage, "FTPUPLOADFILES.FtpUpLoadFilesPropPage.1",
	0x1f289220, 0x84e8, 0x41ce, 0x82, 0x5f, 0x38, 0x96, 0xd2, 0xa6, 0x1e, 0xe2)

// CFtpUpLoadFilesPropPage::CFtpUpLoadFilesPropPageFactory::UpdateRegistry -
// 添加或移除 CFtpUpLoadFilesPropPage 的系统注册表项

BOOL CFtpUpLoadFilesPropPage::CFtpUpLoadFilesPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_FTPUPLOADFILES_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CFtpUpLoadFilesPropPage::CFtpUpLoadFilesPropPage - 构造函数

CFtpUpLoadFilesPropPage::CFtpUpLoadFilesPropPage() :
	COlePropertyPage(IDD, IDS_FTPUPLOADFILES_PPG_CAPTION)
{
}

// CFtpUpLoadFilesPropPage::DoDataExchange - 在页和属性间移动数据

void CFtpUpLoadFilesPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CFtpUpLoadFilesPropPage 消息处理程序
