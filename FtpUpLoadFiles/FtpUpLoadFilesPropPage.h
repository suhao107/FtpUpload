#pragma once

// FtpUpLoadFilesPropPage.h : CFtpUpLoadFilesPropPage ����ҳ���������


// CFtpUpLoadFilesPropPage : �й�ʵ�ֵ���Ϣ������� FtpUpLoadFilesPropPage.cpp��

class CFtpUpLoadFilesPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CFtpUpLoadFilesPropPage)
	DECLARE_OLECREATE_EX(CFtpUpLoadFilesPropPage)

// ���캯��
public:
	CFtpUpLoadFilesPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_FTPUPLOADFILES };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

