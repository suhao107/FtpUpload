#pragma once

// FtpUpLoadFilesCtrl.h : CFtpUpLoadFilesCtrl ActiveX �ؼ����������


// CFtpUpLoadFilesCtrl : �й�ʵ�ֵ���Ϣ������� FtpUpLoadFilesCtrl.cpp��

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
	};
};

