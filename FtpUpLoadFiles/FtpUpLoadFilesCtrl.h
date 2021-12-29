#pragma once

// FtpUpLoadFilesCtrl.h : CFtpUpLoadFilesCtrl ActiveX 控件类的声明。


// CFtpUpLoadFilesCtrl : 有关实现的信息，请参阅 FtpUpLoadFilesCtrl.cpp。

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
	};
};

