
// HM3Dlg.cpp : 實作檔
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


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
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


// CHM3Dlg 對話方塊



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


// CHM3Dlg 訊息處理常式

BOOL CHM3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
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

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定
	AllocConsole();
	freopen ("CONOUT$", "w", stdout );
	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
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

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CHM3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CHM3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHM3Dlg::OnBnClickedButton1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
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
	// TODO: 在此加入控制項告知處理常式程式碼
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
