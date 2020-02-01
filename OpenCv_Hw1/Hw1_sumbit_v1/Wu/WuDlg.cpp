
// WuDlg.cpp : �����n
//
#include <math.h>
#include "stdafx.h"
#include "Wu.h"
#include "WuDlg.h"
#include "afxdialogex.h"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\opencv.hpp"
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
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CWuDlg ��Ԓ���K



CWuDlg::CWuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWuDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CWuDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CWuDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CWuDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON4, &CWuDlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT3, &CWuDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT1, &CWuDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT4, &CWuDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON2, &CWuDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CWuDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT2, &CWuDlg::OnEnChangeEdit2)
	
	ON_BN_CLICKED(IDC_BUTTON5, &CWuDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CWuDlg ӍϢ̎��ʽ

BOOL CWuDlg::OnInitDialog()
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
	
	return TRUE;  // ���� TRUE����������������O�����c
}

void CWuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWuDlg::OnPaint()
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
HCURSOR CWuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWuDlg::OnBnClickedButton1()
{
	// TODO: �ڴ˼������헸�֪̎��ʽ��ʽ�a
	IplImage* img = cvLoadImage( "1.bmp" );
cvNamedWindow( "dog", CV_WINDOW_AUTOSIZE );
cvShowImage( "dog", img );

	int width0=img->width;
	CString s1;s1.Format(_T("%d"),width0);
	GetDlgItem(IDC_EDIT1)->SetWindowText(s1);
	int height0=img->height;
	CString s2;s2.Format(_T("%d"),height0);
	GetDlgItem(IDC_EDIT2)->SetWindowText(s2);
	int resolution=width0*height0;
	CString s3;s3.Format(_T("%d"),resolution);
	GetDlgItem(IDC_EDIT3)->SetWindowText(s3);
	int dpi=0xC30E0000/39.37;
	CString s4;s4.Format(_T("%d"),dpi);
	GetDlgItem(IDC_EDIT4)->SetWindowText(s4);
cvWaitKey(0);
cvReleaseImage( &img );
cvDestroyWindow( "dog" );
	
}


void CWuDlg::OnBnClickedOk()
{
	// TODO: �ڴ˼������헸�֪̎��ʽ��ʽ�a
	CDialogEx::OnOK();
}


void CWuDlg::OnBnClickedCancel()
{
	// TODO: �ڴ˼������헸�֪̎��ʽ��ʽ�a
	CDialogEx::OnCancel();
}

Mat src1,src2,rebuilt;
int slidermax = 50,slider;
double alpha,beta;
void feedbacktrackbar( int, void* )
{
 alpha = (double)slider/(double)slidermax;
 beta = (1.0-alpha);
 addWeighted(src1,alpha,src2,beta,NULL,rebuilt);
 imshow("Mix",rebuilt);
}
void CWuDlg::OnBnClickedButton4()
{
	// TODO: �ڴ˼������헸�֪̎��ʽ��ʽ�a
	
	src1 = imread("1.bmp");
	src2 = imread("god.bmp");
	slider = 0;
	namedWindow("Mix", 1);
	char Trackbar[20];
	sprintf_s(Trackbar,"WEIGHT",slidermax);
	createTrackbar(Trackbar,"Mix",&slider,slidermax,feedbacktrackbar);
	feedbacktrackbar(slider,NULL);
    waitKey(0);
}


void CWuDlg::OnEnChangeEdit3()
{
	// TODO:  ����@�� RICHEDIT ����헣�����헌�����
	// ���ʹ˸�֪������������ CDialogEx::OnInitDialog()
	// ��ʽ�ͺ��� CRichEditCtrl().SetEventMask()
	// ׌���� ENM_CHANGE ��� ORed �������֡�



	// TODO:  �ڴ˼������헸�֪̎��ʽ��ʽ�a
}


void CWuDlg::OnEnChangeEdit1()
{
	// TODO:  ����@�� RICHEDIT ����헣�����헌�����
	// ���ʹ˸�֪������������ CDialogEx::OnInitDialog()
	// ��ʽ�ͺ��� CRichEditCtrl().SetEventMask()
	// ׌���� ENM_CHANGE ��� ORed �������֡�



	// TODO:  �ڴ˼������헸�֪̎��ʽ��ʽ�a
}


void CWuDlg::OnEnChangeEdit4()
{
	// TODO:  ����@�� RICHEDIT ����헣�����헌�����
	// ���ʹ˸�֪������������ CDialogEx::OnInitDialog()
	// ��ʽ�ͺ��� CRichEditCtrl().SetEventMask()
	// ׌���� ENM_CHANGE ��� ORed �������֡�



	// TODO:  �ڴ˼������헸�֪̎��ʽ��ʽ�a
}


void CWuDlg::OnBnClickedButton2()
{
	// TODO: �ڴ˼������헸�֪̎��ʽ��ʽ�a
	 Mat src, srcOfMerge;
  Mat mv[3];
  src = cvLoadImage( "1_2.png");

   split(src,mv);
   namedWindow("BGR", 1);
   namedWindow("RBG", 1);
   imshow( "BGR", src);

   Mat buf;
   buf=mv[0];
   mv[0]=mv[1];
   mv[1]=mv[2];
   mv[2]=buf;
   merge(mv,3,srcOfMerge);
   imshow("RBG",srcOfMerge);
  cvWaitKey(0);
  cvDestroyWindow( "BGR" );
cvDestroyWindow( "RBG");
}


void CWuDlg::OnBnClickedButton3()
{
	// TODO: �ڴ˼������헸�֪̎��ʽ��ʽ�a
	IplImage *src=cvLoadImage("1.bmp");  
    if (src == NULL)  
        exit(0);  
    IplImage *res=cvCreateImage(cvGetSize(src), src->depth, src->nChannels);  
    if (res == NULL)  
        exit(0);  
  
  int N=src->width;  
    for (int i=0; i<src->height; i++)  
    {  
        for (int j=0; j<src->width; j++)  
        {  
            CvScalar color=cvGet2D(src, i, j);  
            cvSet2D(res, i, N-j-1, color);
        }  
    }  
  
    cvNamedWindow("src");  
    cvNamedWindow("res");  
    cvShowImage("src", src);  
    cvShowImage("res", res);  
	Mat outimg=res;
	imwrite("god.bmp",outimg);
    cvWaitKey(0);  
    cvReleaseImage(&src);  
    cvReleaseImage(&res);  
    cvDestroyAllWindows(); 
	
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: �ڴ˼������헸�֪̎��ʽ��ʽ�a
	CDialogEx::OnOK();
}


void CWuDlg::OnEnChangeEdit2()
{
	// TODO:  ����@�� RICHEDIT ����헣�����헌�����
	// ���ʹ˸�֪������������ CDialogEx::OnInitDialog()
	// ��ʽ�ͺ��� CRichEditCtrl().SetEventMask()
	// ׌���� ENM_CHANGE ��� ORed �������֡�



	// TODO:  �ڴ˼������헸�֪̎��ʽ��ʽ�a
}



void CWuDlg::OnBnClickedButton5()
{
	// TODO: �ڴ˼������헸�֪̎��ʽ��ʽ�a
	IplImage* img = cvLoadImage("eye.jpg"); 
IplImage* gray = cvCreateImage( cvSize( img -> width, img -> height ), 8, 1 );
IplImage* gaussiansmooth = cvCreateImage( cvSize( img -> width, img -> height ), 8, 3 );
IplImage* imgthreshold = cvCreateImage( cvSize( img -> width, img -> height ), 8, 1 );

Mat thresholdimg = cvCreateImage( cvSize( img -> width, img -> height ), IPL_DEPTH_8U, 1 );
cvCvtColor(img,gray,CV_RGB2GRAY);
Mat img1=img;
Mat gray1=gray;
Mat gaussiansmooth1=gaussiansmooth;
Mat imgthreshold1=imgthreshold;
Mat grad;
	GaussianBlur(gray1, gaussiansmooth1,Size(3,3), 0, 0, BORDER_DEFAULT ) ;
	namedWindow("Original image", 1);
    imshow( "Original image", img1);
	namedWindow("smooth image", 1);
    imshow( "smooth image", gaussiansmooth1);

	Mat grad_x, grad_y, abs_grad_x, abs_grad_y;
Sobel(gaussiansmooth1, grad_x, gaussiansmooth1.depth(), 1, 0);  
Sobel(gaussiansmooth1, grad_y, gaussiansmooth1.depth(), 0, 1);  
    convertScaleAbs( grad_x, abs_grad_x );
    convertScaleAbs( grad_y, abs_grad_y );

	
   addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
   imshow( "mix xy", grad );
 Canny(grad,thresholdimg,10,10 * 3,3);  
   imshow("mix xycanny",thresholdimg);
//Mat value=grad_y/grad_x;
//Mat theta; 
//theta[2]=atan(value[2]);
}
