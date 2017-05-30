
void DrawBox(int xLogX,int yLogY,int iColor);
void Show00(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow+1,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow+1,yNow-1,iColorNow);
}
void Show10(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow,yNow-2,iColorNow);
	DrawBox(xNow,yNow-3,iColorNow);
}
void Show11(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow-1,yNow,iColorNow);
	DrawBox(xNow+1,yNow,iColorNow);
	DrawBox(xNow+2,yNow,iColorNow);
}
void Show20(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow-1,yNow-1,iColorNow);
	DrawBox(xNow-1,yNow-2,iColorNow);
}
void Show21(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow-1,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow+1,yNow-1,iColorNow);
}
void Show30(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow+1,yNow-1,iColorNow);
	DrawBox(xNow+1,yNow-2,iColorNow);
}
void Show31(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow-1,yNow-1,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow+1,yNow,iColorNow);
}
void Show40(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow+1,yNow-1,iColorNow);
	DrawBox(xNow,yNow-2,iColorNow);
}
void Show41(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow-1,yNow,iColorNow);
	DrawBox(xNow+1,yNow,iColorNow);
}
void Show42(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow-1,yNow-1,iColorNow);
	DrawBox(xNow,yNow-2,iColorNow);
}
void Show43(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow-1,yNow-1,iColorNow);
	DrawBox(xNow+1,yNow-1,iColorNow);
}
void Show50(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow,yNow-2,iColorNow);
	DrawBox(xNow+1,yNow,iColorNow);
}
void Show51(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow-1,yNow,iColorNow);
	DrawBox(xNow+1,yNow,iColorNow);
	DrawBox(xNow+1,yNow-1,iColorNow);
}
void Show52(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow,yNow-2,iColorNow);
	DrawBox(xNow-1,yNow-2,iColorNow);
}
void Show53(){
	DrawBox(xNow-1,yNow,iColorNow);
	DrawBox(xNow-1,yNow-1,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow+1,yNow-1,iColorNow);
}
void Show60(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow-1,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow,yNow-2,iColorNow);
}
void Show61(){
	DrawBox(xNow-1,yNow-1,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow+1,yNow-1,iColorNow);
	DrawBox(xNow+1,yNow,iColorNow);
}
void Show62(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow,yNow-1,iColorNow);
	DrawBox(xNow,yNow-2,iColorNow);
	DrawBox(xNow+1,yNow-2,iColorNow);
}
void Show63(){
	DrawBox(xNow,yNow,iColorNow);
	DrawBox(xNow-1,yNow-1,iColorNow);
	DrawBox(xNow-1,yNow,iColorNow);
	DrawBox(xNow+1,yNow,iColorNow);
}

int Check00(int xPos,int yPos){
	if( xPos<0 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<1 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos+1][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos+1][yPos-1]!=0 ) return 0;
	return 1;
}
int Check10(int xPos,int yPos){
	if( xPos<0 || xPos>(cxLog-1) ) return 0;
	if( yPos>(cyLog-1) || yPos<3 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos][yPos-2]!=0 ) return 0;
	if( Pannel[xPos][yPos-3]!=0 ) return 0;
	return 1;
}
int Check11(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1)-2 ) return 0;
	if( yPos>(cyLog-1) || yPos<0 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos-1][yPos]!=0 ) return 0;
	if( Pannel[xPos+1][yPos]!=0 ) return 0;
	if( Pannel[xPos+2][yPos]!=0 ) return 0;
	return 1;
}
int Check20(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1) ) return 0;
	if( yPos>(cyLog-1) || yPos<2 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos-1][yPos-1]!=0 ) return 0;
	if( Pannel[xPos-1][yPos-2]!=0 ) return 0;
	return 1;
}
int Check21(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<1 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos-1][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos+1][yPos-1]!=0 ) return 0;
	return 1;
}
int Check30(int xPos,int yPos){
	if( xPos<0 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<2 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos+1][yPos-1]!=0 ) return 0;
	if( Pannel[xPos+1][yPos-2]!=0 ) return 0;
	return 1;
}
int Check31(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<1 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos-1][yPos-1]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos+1][yPos]!=0 ) return 0;
	return 1;
}
int Check40(int xPos,int yPos){
	if( xPos<0 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<2 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos+1][yPos-1]!=0 ) return 0;
	if( Pannel[xPos][yPos-2]!=0 ) return 0;
	return 1;
}
int Check41(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<1 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos-1][yPos]!=0 ) return 0;
	if( Pannel[xPos+1][yPos]!=0 ) return 0;
	return 1;
}
int Check42(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1) ) return 0;
	if( yPos>(cyLog-1) || yPos<2 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos-1][yPos-1]!=0 ) return 0;
	if( Pannel[xPos][yPos-2]!=0 ) return 0;
	return 1;
}
int Check43(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<1 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos-1][yPos-1]!=0 ) return 0;
	if( Pannel[xPos+1][yPos-1]!=0 ) return 0;
	return 1;
}
int Check50(int xPos,int yPos){
	if( xPos<0 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<2 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos][yPos-2]!=0 ) return 0;
	if( Pannel[xPos+1][yPos]!=0 ) return 0;
	return 1;
}
int Check51(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<1 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos-1][yPos]!=0 ) return 0;
	if( Pannel[xPos+1][yPos]!=0 ) return 0;
	if( Pannel[xPos+1][yPos-1]!=0 ) return 0;
	return 1;
}
int Check52(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1) ) return 0;
	if( yPos>(cyLog-1) || yPos<2 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos][yPos-2]!=0 ) return 0;
	if( Pannel[xPos-1][yPos-2]!=0 ) return 0;
	return 1;
}
int Check53(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<1 )	return 0;
	if( Pannel[xPos-1][yPos]!=0 ) return 0;
	if( Pannel[xPos-1][yPos-1]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos+1][yPos-1]!=0 ) return 0;
	return 1;
}
int Check60(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1) ) return 0;
	if( yPos>(cyLog-1) || yPos<2 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos-1][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos][yPos-2]!=0 ) return 0;
	return 1;
}
int Check61(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<1 )	return 0;
	if( Pannel[xPos-1][yPos-1]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos+1][yPos-1]!=0 ) return 0;
	if( Pannel[xPos+1][yPos]!=0 ) return 0;
	return 1;
}
int Check62(int xPos,int yPos){
	if( xPos<0 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<2 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos][yPos-1]!=0 ) return 0;
	if( Pannel[xPos][yPos-2]!=0 ) return 0;
	if( Pannel[xPos+1][yPos-2]!=0 ) return 0;
	return 1;
}
int Check63(int xPos,int yPos){
	if( xPos<1 || xPos>(cxLog-1)-1 ) return 0;
	if( yPos>(cyLog-1) || yPos<1 )	return 0;
	if( Pannel[xPos][yPos]!=0 ) return 0;
	if( Pannel[xPos-1][yPos-1]!=0 ) return 0;
	if( Pannel[xPos-1][yPos]!=0 ) return 0;
	if( Pannel[xPos+1][yPos]!=0 ) return 0;
	return 1;
}

void Write00(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow+1][yNow]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow+1][yNow-1]=iColorNow; 
	if( cyLogHigh>yNow-1 ) cyLogHigh=yNow-1;
}
void Write10(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow][yNow-2]=iColorNow;
	Pannel[xNow][yNow-3]=iColorNow; 
	if( cyLogHigh>yNow-3 ) cyLogHigh=yNow-3;
}
void Write11(){
	Pannel[xNow-1][yNow]=iColorNow;
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow+1][yNow]=iColorNow;
	Pannel[xNow+2][yNow]=iColorNow;
	if( cyLogHigh>yNow ) cyLogHigh=yNow;
}
void Write20(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow-1][yNow-1]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow-1][yNow-2]=iColorNow; 
	if( cyLogHigh>yNow-2 ) cyLogHigh=yNow-2;
}
void Write21(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow-1][yNow]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow+1][yNow-1]=iColorNow; 
	if( cyLogHigh>yNow-1 ) cyLogHigh=yNow-1;

}
void Write30(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow+1][yNow-1]=iColorNow;
	Pannel[xNow+1][yNow-2]=iColorNow; 
	if( cyLogHigh>yNow-2 ) cyLogHigh=yNow-2;
}
void Write31(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow+1][yNow]=iColorNow;
	Pannel[xNow-1][yNow-1]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow; 
	if( cyLogHigh>yNow-1 ) cyLogHigh=yNow-1;
}
void Write40(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow+1][yNow-1]=iColorNow;
	Pannel[xNow][yNow-2]=iColorNow;
	if( cyLogHigh>yNow-2 ) cyLogHigh=yNow-2;
}
void Write41(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow-1][yNow]=iColorNow;
	Pannel[xNow+1][yNow]=iColorNow;
	if( cyLogHigh>yNow-1 ) cyLogHigh=yNow-1;
}
void Write42(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow-1][yNow-1]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow][yNow-2]=iColorNow;
	if( cyLogHigh>yNow-2 ) cyLogHigh=yNow-2;
}
void Write43(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow-1][yNow-1]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow+1][yNow-1]=iColorNow;
	if( cyLogHigh>yNow-1 ) cyLogHigh=yNow-1;
}
void Write50(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow+1][yNow]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow][yNow-2]=iColorNow; 
	if( cyLogHigh>yNow-2 ) cyLogHigh=yNow-2;
}
void Write51(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow-1][yNow]=iColorNow;
	Pannel[xNow+1][yNow]=iColorNow;
	Pannel[xNow+1][yNow-1]=iColorNow; 
	if( cyLogHigh>yNow-1 ) cyLogHigh=yNow-1;
}
void Write52(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow-1][yNow-2]=iColorNow;
	Pannel[xNow][yNow-2]=iColorNow;
	if( cyLogHigh>yNow-2 ) cyLogHigh=yNow-2;
}
void Write53(){
	Pannel[xNow-1][yNow]=iColorNow;
	Pannel[xNow-1][yNow-1]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow+1][yNow-1]=iColorNow;
	if( cyLogHigh>yNow-1 ) cyLogHigh=yNow-1;
}
void Write60(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow-1][yNow]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow][yNow-2]=iColorNow; 
	if( cyLogHigh>yNow-2 ) cyLogHigh=yNow-2;
}
void Write61(){
	Pannel[xNow+1][yNow]=iColorNow;
	Pannel[xNow-1][yNow-1]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow+1][yNow-1]=iColorNow; 
	if( cyLogHigh>yNow-1 ) cyLogHigh=yNow-1;
}
void Write62(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow][yNow-1]=iColorNow;
	Pannel[xNow][yNow-2]=iColorNow;
	Pannel[xNow+1][yNow-2]=iColorNow; 
	if( cyLogHigh>yNow-2 ) cyLogHigh=yNow-2;
}
void Write63(){
	Pannel[xNow][yNow]=iColorNow;
	Pannel[xNow-1][yNow]=iColorNow;
	Pannel[xNow+1][yNow]=iColorNow;
	Pannel[xNow-1][yNow-1]=iColorNow; 
	if( cyLogHigh>yNow-1 ) cyLogHigh=yNow-1;
}
/*
void ShowOther00(){
	DrawOtherBox(1,1);
	DrawOtherBox(2,1);
	DrawOtherBox(1,2);
	DrawOtherBox(2,2);
}
void ShowOther10(){
	DrawOtherBox(1,0);
	DrawOtherBox(1,1);
	DrawOtherBox(1,2);
	DrawOtherBox(1,3);
}
void ShowOther11(){
	DrawOtherBox(0,2);
	DrawOtherBox(1,2);
	DrawOtherBox(2,2);
	DrawOtherBox(3,2);
}
void ShowOther20(){
	DrawOtherBox(1,1);
	DrawOtherBox(1,2);
	DrawOtherBox(2,2);
	DrawOtherBox(2,3);
}
void ShowOther21(){
	DrawOtherBox(1,1);
	DrawOtherBox(2,1);
	DrawOtherBox(0,2);
	DrawOtherBox(1,2);
}
void ShowOther30(){
	DrawOtherBox(2,1);
	DrawOtherBox(1,2);
	DrawOtherBox(2,2);
	DrawOtherBox(1,3);
}
void ShowOther31(){
	DrawOtherBox(0,1);
	DrawOtherBox(1,1);
	DrawOtherBox(1,2);
	DrawOtherBox(2,2);
}
void ShowOther40(){
	DrawOtherBox(1,1);
	DrawOtherBox(1,2);
	DrawOtherBox(1,3);
	DrawOtherBox(2,2);
}
void ShowOther41(){
	DrawOtherBox(1,1);
	DrawOtherBox(0,2);
	DrawOtherBox(1,2);
	DrawOtherBox(2,2);
}
void ShowOther42(){
	DrawOtherBox(2,1);
	DrawOtherBox(1,2);
	DrawOtherBox(2,2);
	DrawOtherBox(2,3);
}
void ShowOther43(){
	DrawOtherBox(1,1);
	DrawOtherBox(2,1);
	DrawOtherBox(3,1);
	DrawOtherBox(2,2);
}
void ShowOther50(){
	DrawOtherBox(1,1);
	DrawOtherBox(1,2);
	DrawOtherBox(1,3);
	DrawOtherBox(2,3);
}
void ShowOther51(){
	DrawOtherBox(2,1);
	DrawOtherBox(0,2);
	DrawOtherBox(1,2);
	DrawOtherBox(2,2);
}
void ShowOther52(){
	DrawOtherBox(1,1);
	DrawOtherBox(2,1);
	DrawOtherBox(2,2);
	DrawOtherBox(2,3);
}
void ShowOther53(){
	DrawOtherBox(1,1);
	DrawOtherBox(2,1);
	DrawOtherBox(3,1);
	DrawOtherBox(1,2);
}
void ShowOther60(){
	DrawOtherBox(2,0);
	DrawOtherBox(2,1);
	DrawOtherBox(2,2);
	DrawOtherBox(1,2);
}
void ShowOther61(){
	DrawOtherBox(0,1);
	DrawOtherBox(1,1);
	DrawOtherBox(2,1);
	DrawOtherBox(2,2);
}
void ShowOther62(){
	DrawOtherBox(1,1);
	DrawOtherBox(1,2);
	DrawOtherBox(1,3);
	DrawOtherBox(2,1);
}
void ShowOther63(){
	DrawOtherBox(1,1);
	DrawOtherBox(1,2);
	DrawOtherBox(2,2);
	DrawOtherBox(3,2);
}
*/
