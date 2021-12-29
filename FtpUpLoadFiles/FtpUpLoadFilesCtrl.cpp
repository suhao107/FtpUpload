// FtpUpLoadFilesCtrl.cpp : CFtpUpLoadFilesCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "FtpUpLoadFiles.h"
#include "FtpUpLoadFilesCtrl.h"
#include "FtpUpLoadFilesPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CFtpUpLoadFilesCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CFtpUpLoadFilesCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CFtpUpLoadFilesCtrl, COleControl)
	DISP_FUNCTION_ID(CFtpUpLoadFilesCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CFtpUpLoadFilesCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO: 根据需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CFtpUpLoadFilesCtrl, 1)
	PROPPAGEID(CFtpUpLoadFilesPropPage::guid)
END_PROPPAGEIDS(CFtpUpLoadFilesCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CFtpUpLoadFilesCtrl, "FtpUpLoadFiles.class",
	0x58caa706, 0x580, 0x4888, 0xbb, 0x5b, 0x44, 0x7a, 0x34, 0xc1, 0x98, 0x4f)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CFtpUpLoadFilesCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DFtpUpLoadFiles = { 0x5C3172B8, 0xCE50, 0x4DCB, { 0xB7, 0x68, 0x60, 0x50, 0x6B, 0xBC, 0xB4, 0xB6 } };
const IID IID_DFtpUpLoadFilesEvents = { 0x1F0FBEBE, 0x7F6F, 0x4339, { 0x80, 0x33, 0xB2, 0x64, 0x14, 0x3, 0xCD, 0x5A } };

// 控件类型信息

static const DWORD _dwFtpUpLoadFilesOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CFtpUpLoadFilesCtrl, IDS_FTPUPLOADFILES, _dwFtpUpLoadFilesOleMisc)

// CFtpUpLoadFilesCtrl::CFtpUpLoadFilesCtrlFactory::UpdateRegistry -
// 添加或移除 CFtpUpLoadFilesCtrl 的系统注册表项

BOOL CFtpUpLoadFilesCtrl::CFtpUpLoadFilesCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

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


// CFtpUpLoadFilesCtrl::CFtpUpLoadFilesCtrl - 构造函数

CFtpUpLoadFilesCtrl::CFtpUpLoadFilesCtrl()
{
	InitializeIIDs(&IID_DFtpUpLoadFiles, &IID_DFtpUpLoadFilesEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CFtpUpLoadFilesCtrl::~CFtpUpLoadFilesCtrl - 析构函数

CFtpUpLoadFilesCtrl::~CFtpUpLoadFilesCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CFtpUpLoadFilesCtrl::OnDraw - 绘图函数

void CFtpUpLoadFilesCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CFtpUpLoadFilesCtrl::DoPropExchange - 持久性支持

void CFtpUpLoadFilesCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}


// CFtpUpLoadFilesCtrl::OnResetState - 将控件重置为默认状态

void CFtpUpLoadFilesCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CFtpUpLoadFilesCtrl::AboutBox - 向用户显示“关于”框

void CFtpUpLoadFilesCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_FTPUPLOADFILES);
	dlgAbout.DoModal();
}


// CFtpUpLoadFilesCtrl 消息处理程序
