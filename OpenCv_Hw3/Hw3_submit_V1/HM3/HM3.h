
// HM3.h : PROJECT_NAME ���ó�ʽ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CHM3App:
// Ո��醌�����e�� HM3.cpp
//

class CHM3App : public CWinApp
{
public:
	CHM3App();

// ����
public:
	virtual BOOL InitInstance();

// ��ʽ�a����

	DECLARE_MESSAGE_MAP()
};

extern CHM3App theApp;