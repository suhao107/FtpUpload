#pragma once

// FtpUpLoadFilesPropPage.h : CFtpUpLoadFilesPropPage 属性页类的声明。


// CFtpUpLoadFilesPropPage : 有关实现的信息，请参阅 FtpUpLoadFilesPropPage.cpp。

class CFtpUpLoadFilesPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CFtpUpLoadFilesPropPage)
	DECLARE_OLECREATE_EX(CFtpUpLoadFilesPropPage)

// 构造函数
public:
	CFtpUpLoadFilesPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_FTPUPLOADFILES };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

