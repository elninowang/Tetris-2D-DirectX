int Begin(){
	if( iNum==0)	return 1;
	if( iNum==1 ){
		if( iState==0 )	return 3;
		else if( iState==1 )	return 0;
	}
	if( iNum==2 ){
		if( iState==0 )	return 2;
		if( iState==1 )	return 1;
	}
	if( iNum==3 ){
		if( iState==0 )	return 2;
		if( iState==1 )	return 1;
	}
	if( iNum==4 ){
		if( iState==0 )	return 2;
		if( iState==1 )	return 1;
		if( iState==2 )	return 2;
		if( iState==3 )	return 1;
	}
	if( iNum==5 ){
		if( iState==0 )	return 2;
		if( iState==1 )	return 1;
		if( iState==2 )	return 2;
		if( iState==3 )	return 1;
	}
	if( iNum==6 ){
		if( iState==0 )	return 2;
		if( iState==1 )	return 1;
		if( iState==2 )	return 2;
		if( iState==3 )	return 1;
	}
}
int Check(int __iNum,int __iState,int xPos,int yPos){
	if( __iNum==0)			return Check00(xPos,yPos);
	if( __iNum==1 ){
		if( __iState==0 )	return Check10(xPos,yPos);
		if( __iState==1 )	return Check11(xPos,yPos);
	}
	if( __iNum==2 ){
		if( __iState==0 )	return Check20(xPos,yPos);
		if( __iState==1 )	return Check21(xPos,yPos);
	}
	if( __iNum==3 ){
		if( __iState==0 )	return Check30(xPos,yPos);
		if( __iState==1 )	return Check31(xPos,yPos);
	}
	if( __iNum==4 ){
		if( __iState==0 )	return Check40(xPos,yPos);
		if( __iState==1 )	return Check41(xPos,yPos);
		if( __iState==2 )	return Check42(xPos,yPos);
		if( __iState==3 )	return Check43(xPos,yPos);
	}
	if( __iNum==5 ){
		if( __iState==0 )	return Check50(xPos,yPos);
		if( __iState==1 )	return Check51(xPos,yPos);
		if( __iState==2 )	return Check52(xPos,yPos);
		if( __iState==3 )	return Check53(xPos,yPos);
	}
	if( __iNum==6 ){
		if( __iState==0 )	return Check60(xPos,yPos);
		if( __iState==1 )	return Check61(xPos,yPos);
		if( __iState==2 )	return Check62(xPos,yPos);
		if( __iState==3 )	return Check63(xPos,yPos);
	}
}
void Show(){
	if( iNum==0)	Show00();
	if( iNum==1 ){
		if( iState==0 )	Show10();
		if( iState==1 )	Show11();
	}
	if( iNum==2 ){
		if( iState==0 )	Show20();
		if( iState==1 )	Show21();
	}
	if( iNum==3 ){
		if( iState==0 )	Show30();
		if( iState==1 )	Show31();
	}
	if( iNum==4 ){
		if( iState==0 )	Show40();
		if( iState==1 )	Show41();
		if( iState==2 )	Show42();
		if( iState==3 )	Show43();
	}
	if( iNum==5 ){
		if( iState==0 )	Show50();
		if( iState==1 )	Show51();
		if( iState==2 )	Show52();
		if( iState==3 )	Show53();
	}
	if( iNum==6 ){
		if( iState==0 )	Show60();
		if( iState==1 )	Show61();
		if( iState==2 )	Show62();
		if( iState==3 )	Show63();
	}
}
/*void del(){
	if( iNum==0)	del00();
	if( iNum==1 ){
		if( iState==0 )	del10();
		if( iState==1 )	del11();
	}
	if( iNum==2 ){
		if( iState==0 )	del20();
		if( iState==1 )	del21();
	}
	if( iNum==3 ){
		if( iState==0 )	del30();
		if( iState==1 )	del31();
	}
	if( iNum==4 ){
		if( iState==0 )	del40();
		if( iState==1 )	del41();
		if( iState==2 )	del42();
		if( iState==3 )	del43();
	}
	if( iNum==5 ){
		if( iState==0 )	del50();
		if( iState==1 )	del51();
		if( iState==2 )	del52();
		if( iState==3 )	del53();
	}
	if( iNum==6 ){
		if( iState==0 )	del60();
		if( iState==1 )	del61();
		if( iState==2 )	del62();
		if( iState==3 )	del63();
	}
}
*/
int CheckDown(){
	if( Check(iNum,iState,xNow,yNow+1)==1 )
		return 1;
	else return 0;
}
int CheckLeft(){
	if( Check(iNum,iState,xNow-1,yNow)==1 )
		return 1;
	else return 0;
}
int CheckRight(){
	if( Check(iNum,iState,xNow+1,yNow)==1 )
		return 1;
	else return 0;
}
int CheckTurn(){
	int iTempState;
	iTempState=(iState>=aFullState[iNum]-1)?0:iState+1;
	if( Check(iNum,iTempState,xNow,yNow)==1 )
		return 1;
	else if( Check(iNum,iTempState,xNow-1,yNow)==1 )
		return 2;
	else if( Check(iNum,iTempState,xNow+1,yNow)==1 )
		return 3;
	else if( iNum==1 && iState==0 && Check(iNum,iTempState,xNow-2,yNow)==1 )
		return 4;
	else if( yNow<1 && Check(iNum,iTempState,xNow,yNow+1)==1 )
		return 5;
	else if( yNow<2 && Check(iNum,iTempState,xNow,yNow+2)==1 )
		return 6;
	else if( yNow<3 && iNum==1 && iState==1 && Check(iNum,iTempState,xNow,yNow+3)==1 )
		return 7;
	else return 0;
}
void WritePannel(){
	if( iNum==0)	Write00();
	if( iNum==1 ){
		if( iState==0 )	Write10();
		if( iState==1 )	Write11();
	}
	if( iNum==2 ){
		if( iState==0 )	Write20();
		if( iState==1 )	Write21();
	}
	if( iNum==3 ){
		if( iState==0 )	Write30();
		if( iState==1 )	Write31();
	}
	if( iNum==4 ){
		if( iState==0 )	Write40();
		if( iState==1 )	Write41();
		if( iState==2 )	Write42();
		if( iState==3 )	Write43();
	}
	if( iNum==5 ){
		if( iState==0 )	Write50();
		if( iState==1 )	Write51();
		if( iState==2 )	Write52();
		if( iState==3 )	Write53();
	}
	if( iNum==6 ){
		if( iState==0 )	Write60();
		if( iState==1 )	Write61();
		if( iState==2 )	Write62();
		if( iState==3 )	Write63();
	}
}
/*void Showother(){
	if( _iNum==0)	Showother00();
	if( _iNum==1 ){
		if( _iState==0 )	Showother10();
		if( _iState==1 )	Showother11();
	}
	if( _iNum==2 ){
		if( _iState==0 )	Showother20();
		if( _iState==1 )	Showother21();
	}
	if( _iNum==3 ){
		if( _iState==0 )	Showother30();
		if( _iState==1 )	Showother31();
	}
	if( _iNum==4 ){
		if( _iState==0 )	Showother40();
		if( _iState==1 )	Showother41();
		if( _iState==2 )	Showother42();
		if( _iState==3 )	Showother43();
	}
	if( _iNum==5 ){
		if( _iState==0 )	Showother50();
		if( _iState==1 )	Showother51();
		if( _iState==2 )	Showother52();
		if( _iState==3 )	Showother53();
	}
	if( _iNum==6 ){
		if( _iState==0 )	Showother60();
		if( _iState==1 )	Showother61();
		if( _iState==2 )	Showother62();
		if( _iState==3 )	Showother63();
	}
}
*/
void Down(int iRow){
	int i,j;
	for( j=iRow;j>=cyLogHigh;j-- ){
		for(i=0;i<cxLog;i++){
			if( j>0 )
				Pannel[i][j]=Pannel[i][j-1];
			else Pannel[i][j]=0;
		}
	}
	cyLogHigh++;
}
void MakeDown(){
	fFlag=1;
	int iMax=0;
	int i,j;
	for(j=cyLog-1;j>=cyLogHigh;j--){
		for( i=0;i<cxLog;i++ ){
			if( Pannel[i][j]==0 ){
				fFlag=0;
				break;
			}
		}
		if( fFlag==1 ){
			Down(j);
			iMax++;
			j++;
		}
		fFlag=1;
	}
/*	if( max==1 ) score+=SCORE1;
	else if( max==2 ) score+=SCORE2;
	else if( max==3 ) score+=SCORE3;
	else if( max==4 ) score+=SCORE4;
*/
}

