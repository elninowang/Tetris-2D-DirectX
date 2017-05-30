// RusGame.cpp : Defines the entry point for the application.
//

#include <stdio.h>
#include "stdafx.h"
#include "ddraw.h"
#include "RusGame.h"
#include "variables.h"
#include "show.h"
#include "rus.h"
#include "Platform.h"
#include "DirectX.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name


// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChangeSpeed(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_RUSGAME, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_RUSGAME);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_RUSGAME);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)GetStockObject(GRAY_BRUSH);
	wcex.lpszMenuName	= (LPCTSTR)IDC_RUSGAME;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	
	switch (message) 
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam); 
		wmEvent = HIWORD(wParam); 
		// Parse the menu selections:

		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_FILE_RESTART:
			GameRestart();
			break;
		case ID_FILE_CHANGESPEED:
			DialogBox(hInst, (LPCTSTR)IDD_SPEED, hWnd, (DLGPROC)ChangeSpeed);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_CREATE:
		if( !InitDirectX(hWnd ) )
		{
			MessageBox(hWnd, TEXT("DirectX interface wrong!"), TEXT("ERROR"), NULL);
			CleanUp();
			SendMessage( hWnd, WM_DESTROY, 0, 0 );
		}
		hdc=GetDC(hWnd);
		ReleaseDC(hWnd,hdc);

		ClearPannel();
		iNum=GetRand(-1);
		iState=GetRand(iNum);
		_iNum=GetRand(-1);
		_iState=GetRand(_iNum);
		iColorNow=1;
		xNow=cxLog/2-1;
		yNow=Begin();

		SetTimer(hWnd,1,TIME,NULL);
		isRun=true;
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		SetMapMode(hdc,MM_TEXT);
		DrawDirectX(hWnd);
		EndPaint(hWnd, &ps);
		break;
	case WM_SIZE:
		cxClient=LOWORD(lParam);
		cyClient=HIWORD(lParam);
		break;
	case WM_KEYDOWN:
		switch( wParam)
		{
		case VK_LEFT:
			if( CheckLeft()==1 )
			{
				xNow--;
				DrawDirectX(hWnd);
			}
			break;
		case VK_RIGHT:
			if( CheckRight()==1 )
			{
				xNow++;
				DrawDirectX(hWnd);
			}
			break;
		case VK_DOWN:
			iTime=0;
			iRealTime=iFastTime;
			break;
		case ' ':
			if( fFlag=CheckTurn() )
			{
				iState=( iState>=aFullState[iNum]-1 )?0:(++iState);
				if( fFlag==2 ) xNow--;
				else if( fFlag==3 ) xNow++;
				else if( fFlag==4 ) xNow-=2;
				else if( fFlag==5 ) yNow++;
				else if( fFlag==6 ) yNow+=2;
				else if( fFlag==7 ) yNow+=3;
			}
			DrawDirectX(hWnd);
			break;
		}
		break;
	case WM_KEYUP:
		if( wParam==VK_DOWN )
		{
			iTime=0;
			iRealTime=iTempTime;
		}
		break;
	case WM_LBUTTONDOWN:
		if( LOWORD(lParam)<xBeg+xNow*cdLec && CheckLeft()==1 )
		{
			xNow--;
			DrawDirectX(hWnd);
		}
		if( LOWORD(lParam)>xBeg+(xNow+1)*cdLec && CheckRight()==1 )
		{
			xNow++;
			DrawDirectX(hWnd);
		}
		break;
	case WM_RBUTTONDOWN:
		if( fFlag=CheckTurn() )
		{
			iState=( iState>=aFullState[iNum]-1 )?0:(++iState);
			if( fFlag==2 ) xNow--;
			else if( fFlag==3 ) xNow++;
			else if( fFlag==4 ) xNow-=2;
			else if( fFlag==5 ) yNow++;
			else if( fFlag==6 ) yNow+=2;
			else if( fFlag==7 ) yNow+=3;
		}
		DrawDirectX(hWnd);
		break;		
	case WM_MBUTTONDOWN:
		iTime=0;
		iRealTime=iFastTime;
		break;
	case WM_MBUTTONUP:
		iTime=0;
		iRealTime=iTempTime;
		break;
	case WM_TIMER:
		if( isRun==true )
		{
			iTime++;
			if( iTime==iRealTime )
			{
				if( CheckDown()==1 )
				{
					yNow++;
					DrawDirectX(hWnd);
				}
				else
				{
					WritePannel();
					if( cyLogHigh<0 )
					{
						DrawDirectX(hWnd);
						MessageBox(hWnd,TEXT("Sorry! You failed this game!"),TEXT("Failed"),0);
						GameRestart();
						DrawDirectX(hWnd);
					}
					MakeDown();
					iNum=_iNum;
					iState=_iState;
					(iColorNow==4)?iColorNow=1:iColorNow++;
					_iNum=GetRand(-1);
					_iState=GetRand(_iNum);
					xNow=4;
					yNow=Begin();
					if( Check(iNum,iState,xNow,yNow)==0 )
					{
						DrawDirectX(hWnd);
						MessageBox(hWnd,TEXT("Sorry! You failed this game!"),TEXT("Failed"),0);
						GameRestart();
						DrawDirectX(hWnd);
					}
					DrawDirectX(hWnd);
					iRealTime=iTempTime;
				}
				iTime=0;
			}
		}
		break;		
	case WM_DESTROY:
		KillTimer(hWnd,1);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		iRealTime = 0;
		return TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
		{
			iTime = 0;
			iRealTime = iTempTime;
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}
LRESULT CALLBACK ChangeSpeed(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	TCHAR str[100];
	int iDlgTime;
	switch (message)
	{
	case WM_INITDIALOG:
		SetDlgItemInt(hDlg, IDC_EDIT1, iRealTime, TRUE);
		iRealTime = 0;
		return TRUE;
	case WM_COMMAND:
		if ( LOWORD(wParam) == IDOK )
		{
			iDlgTime = iTempTime;
			iTempTime=GetDlgItemInt(hDlg, IDC_EDIT1, NULL, TRUE );
			if( iTempTime>0 && iTempTime<=100 )
			{
				iTime=0;
				iRealTime=iTempTime;
				EndDialog(hDlg, LOWORD(wParam));
			}
			else
			{
				MessageBox(hDlg,TEXT("The speed must a number between 1 and 100"),TEXT("Input error"),NULL); 
				iTempTime=iDlgTime;
				SetDlgItemInt(hDlg, IDC_EDIT1, iTempTime, TRUE);
			}
			return TRUE;
		}
		if ( LOWORD(wParam) == IDCANCEL) 
		{
			EndDialog(hDlg, LOWORD(wParam));
			iRealTime = iTempTime;
			return TRUE;
		}
		break;
	}
	return FALSE;
}