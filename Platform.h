RECT RectClean(){
	RECT rc;
	rc.left=xBeg+(xNow-2)*cdLec;
	rc.right=xBeg+(xNow+4)*cdLec;
	rc.top=yBeg+(yNow-4)*cdLec;
	rc.bottom=yBeg+(yNow+1)*cdLec;
	return rc;
}
RECT RectTurnClean(){
	RECT rc;
	rc.left=xBeg+(xNow-3)*cdLec;
	rc.right=xBeg+(xNow+3)*cdLec;
	rc.top=yBeg+(yNow-4)*cdLec;
	rc.bottom=yBeg+(yNow+3)*cdLec;
	return rc;
}
RECT RectPlatClean(){
	RECT rc;
	rc.left=xBeg;
	rc.right=xBeg+cxLog*cdLec;
	rc.top=yBeg/*+(cyLogHigh-1)*cdLec*/;
	rc.bottom=yBeg+cyLog*cdLec;
	return rc;
}

int GetRand(int iD){
	if( iD==-1 )
		return rand()%7;
	else
		return rand()%aFullState[iD];
}
void ClearPannel(){
	int i,j;
	for(j=0;j<cyLog;j++)
		for(i=0;i<cxLog;i++)
			Pannel[i][j]=0;
}
void GameRestart(){
	ClearPannel();
	iNum=GetRand(-1);
	iState=GetRand(iNum);
	_iNum=GetRand(-1);
	_iState=GetRand(_iNum);
	iColorNow=1;
	xNow=cxLog/2-1;
	yNow=Begin();

	iTime=0;
	iTempTime=iSlowTime;
}
COLORREF GetColor(int iColor)
{
	switch(iColor)
	{
	case 1:
		return RGB(0,0,255);
	case 2:
		return RGB(255,255,0);
	case 3:
		return RGB(0,255,0);
	case 4:
		return RGB(255,0,0);
	}
}
COLORREF GetOppColor(int iColor)
{
	switch(iColor)
	{
	case 1:
		return RGB(255,255,0);
	case 2:
		return RGB(0,255,0);
	case 3:
		return RGB(255,0,0);
	case 4:
		return RGB(0,0,255);
	}
}
void DrawBox(int xLogX,int yLogY)
{
	int iNow;
	COLORREF cC,cOC;
	iNow=Pannel[xLogX][yLogY];
	if( iNow==0 )
		return;
	cC=GetColor( iNow );
	cOC=GetOppColor( iNow );

	hpen=CreatePen(PS_SOLID,1,cOC);
	hOldPen = (HPEN)SelectObject(hdc,hpen);
	hbrush=(HBRUSH)GetStockObject(BLACK_BRUSH);
	hOldBrush = (HBRUSH)SelectObject(hdc,hbrush);
	Rectangle(hdc,xBeg+xLogX*cdLec+1,yBeg+yLogY*cdLec+1,xBeg+(xLogX+1)*cdLec-1,yBeg+(yLogY+1)*cdLec-1);
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject(hpen);
	DeleteObject(hbrush);

	hpen=CreatePen(PS_SOLID,0,cC);
	hOldPen = (HPEN)SelectObject(hdc,hpen);
	hbrush=CreateSolidBrush(cC);;
	hOldBrush = (HBRUSH)SelectObject(hdc,hbrush);
	Rectangle(hdc,xBeg+xLogX*cdLec+4,yBeg+yLogY*cdLec+4,xBeg+(xLogX+1)*cdLec-4,yBeg+(yLogY+1)*cdLec-4);
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject(hpen);
	DeleteObject(hbrush);
}
void DrawBox(int xLogX,int yLogY,int iColor)
{
	//int iNow;
	COLORREF cC,cOC;
	
	cC=GetColor( iColor );
	cOC=GetOppColor( iColor );

	hpen=CreatePen(PS_SOLID,1,cOC);
	hOldPen = (HPEN)SelectObject(hdc,hpen);
	hbrush=(HBRUSH)GetStockObject(BLACK_BRUSH);
	hOldBrush = (HBRUSH)SelectObject(hdc,hbrush);
	Rectangle(hdc,xBeg+xLogX*cdLec+1,yBeg+yLogY*cdLec+1,xBeg+(xLogX+1)*cdLec-1,yBeg+(yLogY+1)*cdLec-1);
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject(hpen);
	DeleteObject(hbrush);

	hpen=CreatePen(PS_SOLID,0,cC);
	hOldPen = (HPEN)SelectObject(hdc,hpen);
	hbrush=CreateSolidBrush(cC);;
	hOldBrush = (HBRUSH)SelectObject(hdc,hbrush);
	Rectangle(hdc,xBeg+xLogX*cdLec+4,yBeg+yLogY*cdLec+4,xBeg+(xLogX+1)*cdLec-4,yBeg+(yLogY+1)*cdLec-4);
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject(hpen);
	DeleteObject(hbrush);
}
void DrawBoxes()
{
	int i,j;
	for( j=cyLog-1;j>=cyLogHigh;j--)
		for( i=0;i<cxLog;i++)
			DrawBox(i,j);
}
void Draw()
{
	hpen=(HPEN)GetStockObject( BLACK_PEN );
	hbrush=(HBRUSH)GetStockObject( GRAY_BRUSH );
	hOldPen = (HPEN)SelectObject(hdc,hpen);
	hOldBrush = (HBRUSH)SelectObject(hdc,hbrush);
	Rectangle(hdc,0,0,cxClient,cyClient);
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject(hpen);
	DeleteObject(hbrush);

	cdLow=( (2*cxClient)<cyClient )? cxClient:cyClient/2;
	cdLow=cdLow*9/10;

	xMid=cxClient/2;
	yMid=cyClient/2;

	cdLec=cdLow/cxLog;

	xBeg=xMid-cdLec*cxLog/2;
	yBeg=yMid-cdLec*cyLog/2;
	hpen=(HPEN)GetStockObject(WHITE_PEN);
	hOldPen = (HPEN)SelectObject(hdc,hpen);
	hbrush=CreateSolidBrush( RGB(0,0,0) );
	hOldBrush = (HBRUSH)SelectObject(hdc,hbrush);
	Rectangle(hdc,xBeg,yBeg,xBeg+cdLec*cxLog,yBeg+cdLec*cyLog);
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject(hpen);
	DeleteObject(hbrush);

	DrawBoxes();
	Show();
}
