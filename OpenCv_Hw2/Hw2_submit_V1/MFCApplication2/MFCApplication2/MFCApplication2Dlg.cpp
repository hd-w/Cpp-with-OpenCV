
// MFCApplication2Dlg.cpp : 實作檔
//
#include "iostream"
#include "iomanip"
#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\opencv.hpp"
#include <conio.h>
#include <stdio.h>
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


// CMFCApplication2Dlg 對話方塊



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication2Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication2Dlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 訊息處理常式

BOOL CMFCApplication2Dlg::OnInitDialog()
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
	AllocConsole();	freopen ("CONOUT$", "w", stdout );
	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication2Dlg::OnPaint()
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
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CDialogEx::OnOK();
}

int board_w;
int board_h;
void CMFCApplication2Dlg::OnBnClickedButton1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	IplImage* image = cvLoadImage( "1.bmp" );
	IplImage *gray_image = cvCreateImage(cvGetSize(image),8,1);

	board_w=11;
	board_h=8;
	int board_n = board_w * board_h;
CvSize board_sz = cvSize( board_w, board_h );
CvPoint2D32f* corners = new CvPoint2D32f[ board_n ];
int corner_count;
int found = cvFindChessboardCorners(image, board_sz, corners, &corner_count,CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);
cvCvtColor(image, gray_image, CV_BGR2GRAY);
cvFindCornerSubPix(gray_image, corners, corner_count,cvSize(11,11),cvSize(-1,-1), cvTermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

cvDrawChessboardCorners(image, board_sz, corners,corner_count, found);


cvNamedWindow( "Corner detection" );
cvShowImage( "Corner detection", image );
}

int n_boards;
const int board_dt = 20;
void CMFCApplication2Dlg::OnBnClickedButton2()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	IplImage* image = cvLoadImage( "1.bmp" );
	IplImage *gray_image = cvCreateImage(cvGetSize(image),8,1);

	board_w=11;
	board_h=8;
	n_boards = 1;
	int board_n = board_w * board_h;
CvSize board_sz = cvSize( board_w, board_h );
CvPoint2D32f* corners = new CvPoint2D32f[ board_n ];
int corner_count;
int found = cvFindChessboardCorners(image, board_sz, corners, &corner_count,CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);
cvCvtColor(image, gray_image, CV_BGR2GRAY);
cvFindCornerSubPix(gray_image, corners, corner_count,cvSize(11,11),cvSize(-1,-1), cvTermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

CvMat* image_points = cvCreateMat(n_boards*board_n,2,CV_32FC1);
CvMat* object_points = cvCreateMat(n_boards*board_n,3,CV_32FC1);
CvMat* point_counts = cvCreateMat(n_boards,1,CV_32SC1);
CvMat* intrinsic_matrix = cvCreateMat(3,3,CV_32FC1);
CvMat* distortion_coeffs = cvCreateMat(5,1,CV_32FC1);
CvMat* rotation_vectors = cvCreateMat(3,1,CV_32FC1);
CvMat* rotation_mat= cvCreateMat(3,3,CV_32FC1);
CvMat* translation_vectors = cvCreateMat(3,1,CV_32FC1);
CvMat* jacobian=cvCreateMat(3,1,CV_32FC1);

int successes = 0;
int step, frame = 0;

while(successes < n_boards) {

if(frame++ % board_dt == 0) {
int found = cvFindChessboardCorners(image, board_sz, corners, &corner_count,CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);
cvCvtColor(image, gray_image, CV_BGR2GRAY);
cvFindCornerSubPix(gray_image, corners, corner_count,cvSize(11,11),cvSize(-1,-1), cvTermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));



if( corner_count == board_n ) {
step = successes*board_n;
for( int i=step, j=0; j<board_n; ++i,++j ) {
CV_MAT_ELEM(*image_points, float,i,0) = corners[j].x;
CV_MAT_ELEM(*image_points, float,i,1) = corners[j].y;
CV_MAT_ELEM(*object_points,float,i,0) = j/board_w;
CV_MAT_ELEM(*object_points,float,i,1) = j%board_w;
CV_MAT_ELEM(*object_points,float,i,2) = 0.0f;
}
CV_MAT_ELEM(*point_counts, int,successes,0) = board_n;
successes++;
}
}
} 
CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0f;
CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0f;
cvCalibrateCamera2(
object_points, image_points,
point_counts, cvGetSize( image ),
intrinsic_matrix, distortion_coeffs,
NULL, NULL,0 
);

cvFindExtrinsicCameraParams2(object_points,image_points,intrinsic_matrix,distortion_coeffs,rotation_vectors,translation_vectors);
cvRodrigues2(    rotation_vectors,rotation_mat,jacobian=NULL       );
cvSave("Intrinsics.xml",intrinsic_matrix);
cvSave("Distortion.xml",distortion_coeffs);
 cvSave("rotation_vectors.xml",rotation_mat);
cvSave("translation_vectors.xml",translation_vectors);
 Mat b = Mat(intrinsic_matrix,false);
cout << "intrinsic_matrix"<<endl << b << endl;
cout << endl;
}

void CMFCApplication2Dlg::OnBnClickedButton3()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CvMat *rotation_mat = (CvMat*)cvLoad("rotation_vectors.xml");
	CvMat *translation_vectors = (CvMat*)cvLoad("translation_vectors.xml");
		Mat R = Mat(rotation_mat,false);
        Mat T = Mat(translation_vectors,false);
   Mat Extrinsic[3][4];
 CV_Assert(R.rows == T.rows&&R.type() == T.type());
      int totalCols = R.cols + T.cols;
      cv::Mat mergedDescriptors(R.rows,totalCols, R.type());
      cv::Mat submat = mergedDescriptors.colRange(0, R.cols);
      R.copyTo(submat);
      submat = mergedDescriptors.colRange(R.cols, totalCols);
      T.copyTo(submat);
   cout << "Extrinsic matrix"<<endl << mergedDescriptors << endl;
   cout << endl;
}

void CMFCApplication2Dlg::OnBnClickedButton4()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CvMat *distortion_coeffs = (CvMat*)cvLoad("Distortion.xml");
	Mat b = Mat(distortion_coeffs,false);
	cout << "distortion_coeffs"<<endl << b << endl;
	cout << endl;
}




void CMFCApplication2Dlg::OnBnClickedButton6()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	IplImage* image = cvLoadImage( "Eyes.png" );
 IplImage *smooth = cvCreateImage(cvGetSize(image),8,1);
	IplImage *gray_image = cvCreateImage(cvGetSize(image),8,1);
	cvCvtColor(image, gray_image, CV_BGR2GRAY);
	 cvSmooth(gray_image, smooth, CV_MEDIAN , 3); 
	 cvShowImage("Median Smooth ",smooth);
	 cvSaveImage("smooth.bmp",smooth);
}


void CMFCApplication2Dlg::OnBnClickedButton7()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	IplImage* image = cvLoadImage( "Eyes.png" );
	IplImage *smooth = cvCreateImage(cvGetSize(image),8,1);
	IplImage *gray_image = cvCreateImage(cvGetSize(image),8,1);
	IplImage *canny = cvCreateImage(cvGetSize(image),8,1);
	cvCvtColor(image, gray_image, CV_BGR2GRAY);
	 cvSmooth(gray_image, smooth, CV_MEDIAN , 3); 
	 cvCanny(smooth ,canny ,85.0,104.0, 3 );
	  cvShowImage("canny ",canny);
	  cvSaveImage("eyecanny.bmp",canny);
}


void CMFCApplication2Dlg::OnBnClickedButton8()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	IplImage* src = NULL;  
    IplImage* dst = NULL;  
    IplImage* color = NULL;  
  
    src = cvLoadImage ("eyecanny.bmp", CV_LOAD_IMAGE_GRAYSCALE);  
    dst = cvCreateImage (cvGetSize(src), IPL_DEPTH_8U, 1);  
    if (src->nChannels == 1)  
    {  
        dst = cvCloneImage (src);  
    }  
    else  
    {  
        cvCvtColor (src, dst, CV_RGB2GRAY);  
    }  
  
    CvMemStorage* storage = cvCreateMemStorage (0);  
    cvSmooth (dst, dst, CV_GAUSSIAN, 5, 5);  
      
    CvSeq* circles = cvHoughCircles (dst, storage, CV_HOUGH_GRADIENT, 2, dst->width / 3, 300, 100, 0, 100);  
    color=cvCreateImage (cvGetSize(src), IPL_DEPTH_8U, 3);
	   
    cvCvtColor (dst, color, CV_GRAY2RGB);  
    for (int i = 0; i < circles->total; i++)  
    {  
        float* p = (float*)cvGetSeqElem (circles, i);  
        CvPoint pt = cvPoint (281,40);  
        cvCircle (color, pt, 15, CV_RGB(255, 0, 0), 1, 8, 0);  
    }  
	CvPoint pt = cvPoint(89,43);
  cvCircle (color,pt , 16, CV_RGB(255, 0, 0), 1, 8, 0);
      
    cvNamedWindow ("HoughCircle + cvCircle", 1);  
    cvShowImage ("HoughCircle + cvCircle", color);  
  
    cvWaitKey (0);  
  
    cvReleaseMemStorage (&storage);  
    cvReleaseImage (&src);  
    cvReleaseImage (&dst);  
    cvReleaseImage (&color); 

}
