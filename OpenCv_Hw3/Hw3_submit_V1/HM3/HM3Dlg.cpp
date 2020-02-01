
// HM3Dlg.cpp : �����n
//
#include "stdafx.h"
#include "opencv2/core/core.hpp"  
#include "opencv2/imgproc/imgproc.hpp"  
#include "opencv2/features2d/features2d.hpp"  
#include "opencv2/nonfree/nonfree.hpp" 
#include <opencv2/video/video.hpp>
#include <iostream>
#include "HM3.h"
#include "HM3Dlg.h"
#include "afxdialogex.h"
#include "opencv2\highgui\highgui.hpp"


using namespace cv;  
using namespace std;  
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// �� App About ʹ�� CAboutDlg ��Ԓ���K

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��Ԓ���K�Y��
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧Ԯ

// ��ʽ�a����
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHM3Dlg ��Ԓ���K



CHM3Dlg::CHM3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHM3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHM3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHM3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CHM3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHM3Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CHM3Dlg ӍϢ̎��ʽ

BOOL CHM3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� [�P�...] ���ܱ����ϵ�y���ܱ�

	// IDM_ABOUTBOX �����ϵ�y�����֮�С�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �O���ˌ�Ԓ���K�ĈDʾ�������ó�ʽ����ҕ�����ǌ�Ԓ���K�r��
	// ��ܕ��Ԅӏ��´����I
	SetIcon(m_hIcon, TRUE);			// �O����Dʾ
	SetIcon(m_hIcon, FALSE);		// �O��С�Dʾ

	// TODO: �ڴ˼����~��ĳ�ʼ�O��
	AllocConsole();
	freopen ("CONOUT$", "w", stdout );
	return TRUE;  // ���� TRUE����������������O�����c
}

void CHM3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �������С�����o�������Č�Ԓ���K������Ҫ���еĳ�ʽ�a��
// �Ա��L�u�Dʾ�����ʹ���ļ�/�zҕģʽ�� MFC ���ó�ʽ��
// ��ܕ��Ԅ���ɴ����I��

void CHM3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �L�u���b�Ã���

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ���Dʾ������Ñ��˾���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ���L�Dʾ
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ��ʹ������ҷ��С��ҕ���r��
// ϵ�y�����@������ȡ���Θ��@ʾ��
HCURSOR CHM3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHM3Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ˼������헸�֪̎��ʽ��ʽ�a
	Mat image1=imread("plane1.jpg");
Mat iamgeGray1=imread("plane1.jpg",0);
Mat descriptors1;
vector<KeyPoint> keypoints1;

SiftFeatureDetector sift1(0.06f,10.0);
sift1.detect(iamgeGray1,keypoints1);

drawKeypoints(image1,keypoints1,image1,Scalar::all(-1) );
imshow("test1",image1);
int size1= keypoints1.size();
cout<<"Total image 1 feature point:"<<size1<<endl;

Mat image2=imread("plane2.jpg");
Mat iamgeGray2=imread("plane2.jpg",0);
Mat descriptors2;
vector<KeyPoint> keypoints2;

SiftFeatureDetector sift2(0.06f,10.0);
sift2.detect(iamgeGray2,keypoints2);

drawKeypoints(image2,keypoints2,image2,Scalar::all(-1) );
imshow("test2",image2);
int size2= keypoints2.size();  
cout<<"Total image 2 feature point:"<<size2<<endl;
}


void CHM3Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ˼������헸�֪̎��ʽ��ʽ�a
Mat frame; 
Mat foreground;	
VideoCapture capture("bgSub_video.mp4");
namedWindow("Extracted Foreground");
namedWindow("Source Video");

BackgroundSubtractorMOG mog;
bool stop(false);
while (waitKey(10)!=27)
{
if (!capture.read(frame))
{
break;
}

capture >> frame;
mog(frame, foreground, 0.01);
threshold(foreground, foreground, 128, 255, THRESH_BINARY_INV);

imshow("Extracted Foreground", foreground);
imshow("Source Video", frame);   
} 

}
