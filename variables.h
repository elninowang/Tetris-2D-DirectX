#define		TIME		10
//DC Imformation
PAINTSTRUCT ps;
HDC hdc;
HPEN hpen;
HPEN hOldPen;
HBRUSH hbrush;
HBRUSH hOldBrush;

//Client View
int cxClient;
int cyClient;
int cdLow;
int xMid;
int yMid;
RECT rcClean;

//Plat View
int xBeg;
int yBeg;
int xPlatMid;
int yPlatMid;
int cdLec;
int cxLog=10;
int Pannel[20][40];
int cyLog=20;

//Plat Informatiom
int aFullState[7]={1,2,2,2,4,4,4};
int xNow,yNow;
int iNum,iState,iColorNow;
int _iNum,_iState;
int cyLogHigh=cyLog-1;

//Flags
int fFlag;
bool isRun;

//Timer Variables
int iTime=0;
int iSlowTime=20;
int iFastTime=1;
int iTempTime=iSlowTime;
int iRealTime=iTempTime;

 