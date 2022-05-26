#include<iostream>
using namespace std;
int qipan[10][10],a,b,x11,y11,x22,y22; 
bool over = false,time1 = false,time2 = false,start1 = false,start2 = false;

void print(){
	for(int i = 1;i <= 9;i ++ ){
		for(int j = 1;j <= 9;j ++ ){
			cout << qipan[i][j] << " ";
			if(j == 3 || j == 6){
				cout << "|";
			}
		}
		if(i == 3 || i == 6){
			cout << endl << "------+------+------";
		}
		cout << endl;
	}	
}

int playercin(int number){
	if(number == 1){
		int x=0,y=0;
		cout<<"Player1 it is your turn!"<<endl;
		cin>>y>>x;
		x11=x;
		y11=y;
		time1 = true;
	}else{
		int x=0,y=0;
		cout<<"Player2 it is your turn!"<<endl;
		cin>>y>>x;
		x22=x;
		y22=y;
		time2 = true;
	}
}

int player1(int x1,int y1){
	if(qipan[x1][y1] == 0){
		start1 = true;
		qipan[x1][y1] = 1;
		print();
	}
	else{
		cout<<"this place has been filled,please choose another place."<<endl;
//		playercin(1);
	}
}

int player2(int x2,int y2){
	if(qipan[x2][y2] == 0){
		start2 = true;
		qipan[x2][y2] = 2;
		print();
	}
	else{
		cout<<"this place has been filled,please choose another place."<<endl;
//		playercin(2);
	}
}


int playeragain(int again){
	if(again == 1){
		int x=0,y=0;
		cout<<"Player1 it is your turn!"<<endl;
		cin>>y>>x;
		x11=x;
		y11=y;
	}else{
		int x=0,y=0;
		cout<<"Player2 it is your turn!"<<endl;
		cin>>y>>x;
		x22=x;
		y22=y;
	}
}

int main(){
//	qipan[4][9]=1;
//	qipan[5][9]=1;
//	qipan[6][9]=1;
	cout << "the game of qipan" << endl;
	print();
	cout << "player 1 is '1' , player 2 is '2' "<<endl<<endl;
	cout << "If you want to change the place (2,3) , you can type the '2 3' , then the qipan will become like this : " << endl <<endl ;
	qipan[2][3] = 1;
	print();
	cout<<endl<<endl;
	qipan[2][3] = 0;
	//开始
	 
	for(int iii = 1;over == false ; iii){
		bool game = true;
		start1 = false;
		start2 = false;
		time1 = false;
		time2 = false;
		for(int jjj = 1;start1 == false ; jjj){	
			if(time1 == false){	
				playercin(1);
			}else{
				playeragain(1);
			}
			player1(x11,y11);
		}
		for(int i = 1 ; i<=7 ; i = i+3){
			for(int j = 1; j <= 7 ; j = j+3 ){
				if( (qipan[i][j] == 1 && qipan[i][j+1] == 1 && qipan[i][j+2] == 1) || (qipan[i+1][j] == 1 && qipan[i+1][j+1] == 1 && qipan[i+1][j+2] == 1) || (qipan[i+2][j] == 1 && qipan[i+2][j+1] == 1 && qipan[i+2][j+2] == 1)){
//					cout<<"------------";
					int k=i , h=j;
					for(k;k <= i+2;k++){
						for(h;h <= j+2 ; h++){
//							cout<<"------------";
							qipan[k][h]=1;
//							cout << i<<" "<<j<<" "<<k<<" "<<h<<endl;
						}
						h=j;
					}
				}
				//横着的三个相等 
				
				if( (qipan[i][j] == 1 && qipan[i+1][j] == 1 && qipan[i+2][j] == 1) || (qipan[i][j+1] == 1 && qipan[i+1][j+1] == 1 && qipan[i+2][j+1] == 1) || (qipan[i][j+2] == 1 && qipan[i+1][j+2] == 1 && qipan[i+2][j+2] == 1) ){
					int k=i , h=j;
					for(k;k <= i+2 ;k++){
						for(h;h <= j+2 ; h++){
							qipan[k][h]=1;
						}
						h=j;
					}
				}
				//竖着的三个相等 
				
				if(qipan[i][j] == 1 && qipan[i+1][j+1] == 1 && qipan[i+2][j+2] == 1){
					int k=i , h=j;
					for(k;k <= i+2 ;k++){
						for(h;h <= j+2 ; h++){
							qipan[k][h]=1;
						}
						h=j;
					}
				}
				if(qipan[i+2][j] == 1 && qipan[i+1][j+1] == 1 && qipan[i][j+2] == 1){
					int k=i , h=j;
					for(k;k <= i+2 ;k++){
						for(h;h <= j+2 ; h++){
							qipan[k][h]=1;
						}
						h=j;
					}
				}
				//斜着的三个相等 
				
			}
		}
		for(int i=1;i<=9;i++){
			for(int j=1;j<=3;j++){
				if(qipan[i][j] == 0 || qipan[i][j] == 2){
					game = false;
				}
			}
		}
		if(game == true){
			cout<<"Congratuations! player1 wins!"<<endl;
			return 0;
		}
		//player1
		
		game = true; 
		for(int jjj = 1;start2 == false ;jjj){
			if(time2 == false){
				playercin(2);
			}else{
				playeragain(2);
			}
			player2(x22,y22);
		}
		for(int i = 1 ; i<=7 ; i = i+3){
			for(int j = 1; j <= 7 ; j = j+3 ){
				if((qipan[i][j] == 2 && qipan[i][j+1] == 2 && qipan[i][j+2] == 2) || (qipan[i+1][j] == 2 && qipan[i+1][j+1] == 2 && qipan[i+1][j+2] == 2) || (qipan[i+2][j] == 2 && qipan[i+2][j+1] == 2 && qipan[i+2][j+2] == 2)){
//					cout<<"------------";
					int k=i , h=j;
					for(k;k <= i+2;k++){
						for(h;h <= j+2 ; h++){
//							cout<<"------------";
							qipan[k][h]=2;
//							cout << i<<" "<<j<<" "<<k<<" "<<h<<endl;
						}
						h=j;
					}
				}
				//横着的三个相等 
				
				if((qipan[i][j] == 2 && qipan[i+1][j] == 2 && qipan[i+2][j] == 2) || (qipan[i][j+1] == 2 && qipan[i+1][j+1] == 2 && qipan[i+2][j+1] == 2) || (qipan[i][j+2] == 2 && qipan[i+1][j+2] == 2 && qipan[i+2][j+2] == 2)){
					int k=i , h=j;
					for(k;k <= i+2 ;k++){
						for(h;h <= j+2 ; h++){
							qipan[k][h]=2;
						}
						h=j;
					}
				}
				//竖着的三个相等 
				
				if(qipan[i][j] == 2 && qipan[i+1][j+1] == 2 && qipan[i+2][j+2] == 2){
					int k=i , h=j;
					for(k;k <= i+2 ;k++){
						for(h;h <= j+2 ; h++){
							qipan[k][h]=2;
						}
						h=j;
					}
				}
				if(qipan[i+2][j] == 2 && qipan[i+1][j+1] == 2 && qipan[i][j+2] == 2){
					int k=i , h=j;
					for(k;k <= i+2 ;k++){
						for(h;h <= j+2 ; h++){
							qipan[k][h]=2;
						}
						h=j;
					}
				}
				//斜着的三个相等 
				
			}
		}
		for(int i=1;i<=9;i++){
			for(int j=1;j<=3;j++){
				if(qipan[i][j] == 0 || qipan[i][j] == 1){
					game = false;
				}
			}
		}
		if(game == true){
			cout<<"Congratuations! player2 wins!"<<endl;
			return 0;
		}
		//player2 
	}
//	for(int i = 1;i <= 9;i ++ ){
//		for(int j = 1;j <= 9;j ++ ){
//			cout << qipan[i][j] << " ";
//			if(j % 3 == 0 && j != 9){
//				cout << "|";
//			}
//		}
//		if(i % 3 == 0 && i != 9){
//			cout << endl << "------+------+------";
//		}
//		cout << endl;
//	}





	return 0;
}
