#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;
int qipan[10][10],a,b,x11,y11,x22,y22,atplace; 
bool over = false,time1 = false,time2 = false,start1 = false,start2 = false;

int daying(){
	for(int i = 1;i <= 9;i ++ ){
		for(int j = 1;j <= 9;j ++ ){
			cout << qipan[i][j] << " ";
			if(j % 3 == 0 && j != 9){
				cout << "|";
			}
		}
		if(i % 3 == 0 && i != 9){
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

int ap(int x,int y){
	if(x >= 1 && x <=3 && y >= 1 && y <= 3){
		if(x == y){
			if(x == 2){
				atplace = 5;
			}else if(x == 1){
				if(qipan[1][1] != 0 && qipan[1][2] != 0 && qipan[1][3] != 0 && qipan[2][1] != 0 && qipan[2][2] != 0 && qipan[2][3] != 0 && qipan[3][1] != 0 && qipan[3][2] != 0 && qipan[3][3] != 0 ){	
					atplace = 0;
				}else{		
					atplace = 1;
				}		
			}else{
				if(qipan[7][7] != 0 && qipan[7][8] != 0 && qipan[7][9] != 0 && qipan[8][7] != 0 && qipan[8][8] != 0 && qipan[8][9] != 0 && qipan[9][7] != 0 && qipan[9][8] != 0 && qipan[9][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 9;
				}	
			}
		}else if(x - y == 1){
			if(x == 2){
				if(qipan[4][1] != 0 && qipan[4][2] != 0 && qipan[4][3] != 0 && qipan[5][1] != 0 && qipan[5][2] != 0 && qipan[5][3] != 0 && qipan[6][1] != 0 && qipan[6][2] != 0 && qipan[6][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 4;
				}
			}else{
				if(qipan[7][4] != 0 && qipan[7][5] != 0 && qipan[7][6] != 0 && qipan[8][4] != 0 && qipan[8][5] != 0 && qipan[8][6] != 0 && qipan[9][4] != 0 && qipan[9][5] != 0 && qipan[9][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 8;
				}
			}
		}else if(x - y == -1){
			if(x == 1){
				if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 2;
				}
			}else{
				if(qipan[4][7] != 0 && qipan[4][8] != 0 && qipan[4][9] != 0 && qipan[5][7] != 0 && qipan[5][8] != 0 && qipan[5][9] != 0 && qipan[6][7] != 0 && qipan[6][8] != 0 && qipan[6][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 6;
				}
			}
		}else if(x == 3){
			if(qipan[7][1] != 0 && qipan[7][2] != 0 && qipan[7][3] != 0 && qipan[8][1] != 0 && qipan[8][2] != 0 && qipan[8][3] != 0 && qipan[9][1] != 0 && qipan[9][2] != 0 && qipan[9][3] != 0 ){	
				atplace = 0;
			}else{
				atplace = 7;
			}
		}else{
			if(qipan[1][7] != 0 && qipan[1][8] != 0 && qipan[1][9] != 0 && qipan[2][7] != 0 && qipan[2][8] != 0 && qipan[2][9] != 0 && qipan[3][7] != 0 && qipan[3][8] != 0 && qipan[3][9] != 0 ){	
				atplace = 0;
			}else{
			atplace = 3;
			}
		}
	}
	if(x >= 1 && x <=3 && y >= 4 && y <= 6){
		if(x+3 == y){
			if(x == 2){
				if(qipan[4][4] != 0 && qipan[4][5] != 0 && qipan[4][6] != 0 && qipan[5][4] != 0 && qipan[5][6] != 0 && qipan[5][5] != 0 && qipan[6][4] != 0 && qipan[6][5] != 0 && qipan[6][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 5;
				}
			}else if(x == 1){
				if(qipan[1][1] != 0 && qipan[1][2] != 0 && qipan[1][3] != 0 && qipan[2][1] != 0 && qipan[2][2] != 0 && qipan[2][3] != 0 && qipan[3][1] != 0 && qipan[3][2] != 0 && qipan[3][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 1;
				}
			}else{
				if(qipan[7][7] != 0 && qipan[7][8] != 0 && qipan[7][9] != 0 && qipan[8][7] != 0 && qipan[8][8] != 0 && qipan[8][9] != 0 && qipan[9][7] != 0 && qipan[9][8] != 0 && qipan[9][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 9;
				}
			}
		}else if(x - y == -2){
			if(x == 2){
				if(qipan[4][1] != 0 && qipan[4][2] != 0 && qipan[4][3] != 0 && qipan[5][1] != 0 && qipan[5][2] != 0 && qipan[5][3] != 0 && qipan[6][1] != 0 && qipan[6][2] != 0 && qipan[6][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 4;
				}
			}else{
				if(qipan[7][4] != 0 && qipan[7][5] != 0 && qipan[7][6] != 0 && qipan[8][4] != 0 && qipan[8][5] != 0 && qipan[8][6] != 0 && qipan[9][4] != 0 && qipan[9][5] != 0 && qipan[9][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 8;
				}
			}
		}else if(x - y == -4){
			if(x == 1){
				if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 2;
				}
			}else{
				if(qipan[4][7] != 0 && qipan[4][8] != 0 && qipan[4][9] != 0 && qipan[5][7] != 0 && qipan[5][8] != 0 && qipan[5][9] != 0 && qipan[6][7] != 0 && qipan[6][8] != 0 && qipan[6][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 6;
				}
			}
		}else if(x == 3){
			if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
				atplace = 0;
			}else{
				atplace = 7;
			}
		}else{
			if(qipan[1][7] != 0 && qipan[1][8] != 0 && qipan[1][9] != 0 && qipan[2][7] != 0 && qipan[2][8] != 0 && qipan[2][9] != 0 && qipan[3][7] != 0 && qipan[3][8] != 0 && qipan[3][9] != 0 ){	
				atplace = 0;
			}else{
				atplace = 3;
			}
		}
	}
	if(x >= 1 && x <=3 && y >= 7 && y <= 9){
		if(x+6 == y){
			if(x == 2){
				if(qipan[4][4] != 0 && qipan[4][5] != 0 && qipan[4][6] != 0 && qipan[5][4] != 0 && qipan[5][6] != 0 && qipan[5][5] != 0 && qipan[6][4] != 0 && qipan[6][5] != 0 && qipan[6][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 5;
				}
			}else if(x == 1){
				if(qipan[1][1] != 0 && qipan[1][2] != 0 && qipan[1][3] != 0 && qipan[2][1] != 0 && qipan[2][2] != 0 && qipan[2][3] != 0 && qipan[3][1] != 0 && qipan[3][2] != 0 && qipan[3][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 1;
				}
			}else{
				if(qipan[7][7] != 0 && qipan[7][8] != 0 && qipan[7][9] != 0 && qipan[8][7] != 0 && qipan[8][8] != 0 && qipan[8][9] != 0 && qipan[9][7] != 0 && qipan[9][8] != 0 && qipan[9][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 9;
				} 
			}
		}else if(x - y == -5){
			if(x == 2){
				if(qipan[4][1] != 0 && qipan[4][2] != 0 && qipan[4][3] != 0 && qipan[5][1] != 0 && qipan[5][2] != 0 && qipan[5][3] != 0 && qipan[6][1] != 0 && qipan[6][2] != 0 && qipan[6][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 4;
				}
			}else{
				if(qipan[7][4] != 0 && qipan[7][5] != 0 && qipan[7][6] != 0 && qipan[8][4] != 0 && qipan[8][5] != 0 && qipan[8][6] != 0 && qipan[9][4] != 0 && qipan[9][5] != 0 && qipan[9][6] != 0 ){	
					atplace = 0;
				}else{	
					atplace = 8;
				}
			}
		}else if(x - y == -7){
			if(x == 1){
				if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 2;
				}
			}else{
				if(qipan[4][7] != 0 && qipan[4][8] != 0 && qipan[4][9] != 0 && qipan[5][7] != 0 && qipan[5][8] != 0 && qipan[5][9] != 0 && qipan[6][7] != 0 && qipan[6][8] != 0 && qipan[6][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 6;
				}
			}
		}else if(x == 3){
			if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
				atplace = 0;
			}else{
				atplace = 7;
			}
		}else{
			if(qipan[1][7] != 0 && qipan[1][8] != 0 && qipan[1][9] != 0 && qipan[2][7] != 0 && qipan[2][8] != 0 && qipan[2][9] != 0 && qipan[3][7] != 0 && qipan[3][8] != 0 && qipan[3][9] != 0 ){	
				atplace = 0;
			}else{
				atplace = 3;
			}
		}
	}
	if(x >= 4 && x <=6 && y >= 1 && y <= 3){
		if(x-3 == y){
			if(x == 5){
				if(qipan[4][4] != 0 && qipan[4][5] != 0 && qipan[4][6] != 0 && qipan[5][4] != 0 && qipan[5][6] != 0 && qipan[5][5] != 0 && qipan[6][4] != 0 && qipan[6][5] != 0 && qipan[6][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 5;
				}
			}else if(x == 4){
				if(qipan[1][1] != 0 && qipan[1][2] != 0 && qipan[1][3] != 0 && qipan[2][1] != 0 && qipan[2][2] != 0 && qipan[2][3] != 0 && qipan[3][1] != 0 && qipan[3][2] != 0 && qipan[3][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 1;
				}
			}else{
				if(qipan[7][7] != 0 && qipan[7][8] != 0 && qipan[7][9] != 0 && qipan[8][7] != 0 && qipan[8][8] != 0 && qipan[8][9] != 0 && qipan[9][7] != 0 && qipan[9][8] != 0 && qipan[9][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 9;
				}
			}
		}else if(x - y == 4){
			if(x == 5){
				if(qipan[4][1] != 0 && qipan[4][2] != 0 && qipan[4][3] != 0 && qipan[5][1] != 0 && qipan[5][2] != 0 && qipan[5][3] != 0 && qipan[6][1] != 0 && qipan[6][2] != 0 && qipan[6][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 4;
				}
			}else{
				if(qipan[7][4] != 0 && qipan[7][5] != 0 && qipan[7][6] != 0 && qipan[8][4] != 0 && qipan[8][5] != 0 && qipan[8][6] != 0 && qipan[9][4] != 0 && qipan[9][5] != 0 && qipan[9][6] != 0 ){	
					atplace = 0;
				}else{	
					atplace = 8;
				}
			}
		}else if(x - y == 2){
			if(x == 4){
				if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 2;
				}
			}else{
				if(qipan[4][7] != 0 && qipan[4][8] != 0 && qipan[4][9] != 0 && qipan[5][7] != 0 && qipan[5][8] != 0 && qipan[5][9] != 0 && qipan[6][7] != 0 && qipan[6][8] != 0 && qipan[6][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 6;
				}
			}
		}else if(x == 6){
			if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
				atplace = 0;
			}else{
				atplace = 7;
			}
		}else{
			if(qipan[1][7] != 0 && qipan[1][8] != 0 && qipan[1][9] != 0 && qipan[2][7] != 0 && qipan[2][8] != 0 && qipan[2][9] != 0 && qipan[3][7] != 0 && qipan[3][8] != 0 && qipan[3][9] != 0 ){	
				atplace = 0;
			}else{
				atplace = 3;
			}
		}
	}
	if(x >= 4 && x <=6 && y >= 4 && y <= 6){
		if(x == y){
			if(x == 5){
				if(qipan[4][4] != 0 && qipan[4][5] != 0 && qipan[4][6] != 0 && qipan[5][4] != 0 && qipan[5][6] != 0 && qipan[5][5] != 0 && qipan[6][4] != 0 && qipan[6][5] != 0 && qipan[6][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 5;
				}
			}else if(x == 4){
				if(qipan[1][1] != 0 && qipan[1][2] != 0 && qipan[1][3] != 0 && qipan[2][1] != 0 && qipan[2][2] != 0 && qipan[2][3] != 0 && qipan[3][1] != 0 && qipan[3][2] != 0 && qipan[3][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 1;
				}
			}else{
				if(qipan[7][7] != 0 && qipan[7][8] != 0 && qipan[7][9] != 0 && qipan[8][7] != 0 && qipan[8][8] != 0 && qipan[8][9] != 0 && qipan[9][7] != 0 && qipan[9][8] != 0 && qipan[9][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 9;
				}
			}
		}else if(x - y == 1){
			if(x == 5){
				if(qipan[4][1] != 0 && qipan[4][2] != 0 && qipan[4][3] != 0 && qipan[5][1] != 0 && qipan[5][2] != 0 && qipan[5][3] != 0 && qipan[6][1] != 0 && qipan[6][2] != 0 && qipan[6][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 4;
				}
			}else{
				if(qipan[7][4] != 0 && qipan[7][5] != 0 && qipan[7][6] != 0 && qipan[8][4] != 0 && qipan[8][5] != 0 && qipan[8][6] != 0 && qipan[9][4] != 0 && qipan[9][5] != 0 && qipan[9][6] != 0 ){	
					atplace = 0;
				}else{	
					atplace = 8;
				}
			}
		}else if(x - y == -1){
			if(x == 4){
				if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 2;
				}
			}else{
				if(qipan[4][7] != 0 && qipan[4][8] != 0 && qipan[4][9] != 0 && qipan[5][7] != 0 && qipan[5][8] != 0 && qipan[5][9] != 0 && qipan[6][7] != 0 && qipan[6][8] != 0 && qipan[6][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 6;
				}
			}
		}else if(x == 6){
			if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
				atplace = 0;
			}else{
				atplace = 7;
			}
		}else{
			if(qipan[1][7] != 0 && qipan[1][8] != 0 && qipan[1][9] != 0 && qipan[2][7] != 0 && qipan[2][8] != 0 && qipan[2][9] != 0 && qipan[3][7] != 0 && qipan[3][8] != 0 && qipan[3][9] != 0 ){	
				atplace = 0;
			}else{
				atplace = 3;
			}
		}
	}
	if(x >= 4 && x <=6 && y >= 7 && y <= 9){
		if(x+3 == y){
			if(x == 5){
				atplace = 5;
			}else if(x == 4){
				if(qipan[1][1] != 0 && qipan[1][2] != 0 && qipan[1][3] != 0 && qipan[2][1] != 0 && qipan[2][2] != 0 && qipan[2][3] != 0 && qipan[3][1] != 0 && qipan[3][2] != 0 && qipan[3][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 1;
				}
			}else{
				if(qipan[7][7] != 0 && qipan[7][8] != 0 && qipan[7][9] != 0 && qipan[8][7] != 0 && qipan[8][8] != 0 && qipan[8][9] != 0 && qipan[9][7] != 0 && qipan[9][8] != 0 && qipan[9][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 9;
				}
			}
		}else if(x - y == -2){
			if(x == 5){
				if(qipan[4][1] != 0 && qipan[4][2] != 0 && qipan[4][3] != 0 && qipan[5][1] != 0 && qipan[5][2] != 0 && qipan[5][3] != 0 && qipan[6][1] != 0 && qipan[6][2] != 0 && qipan[6][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 4;
				}
			}else{
				if(qipan[7][4] != 0 && qipan[7][5] != 0 && qipan[7][6] != 0 && qipan[8][4] != 0 && qipan[8][5] != 0 && qipan[8][6] != 0 && qipan[9][4] != 0 && qipan[9][5] != 0 && qipan[9][6] != 0 ){	
					atplace = 0;
				}else{	
					atplace = 8;
				}
			}
		}else if(x - y == -4){
			if(x == 4){
				if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 2;
				}
			}else{
				if(qipan[4][7] != 0 && qipan[4][8] != 0 && qipan[4][9] != 0 && qipan[5][7] != 0 && qipan[5][8] != 0 && qipan[5][9] != 0 && qipan[6][7] != 0 && qipan[6][8] != 0 && qipan[6][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 6;
				}
			}
		}else if(x == 6){
			if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
				atplace = 0;
			}else{
				atplace = 7;
			}
		}else{
			if(qipan[1][7] != 0 && qipan[1][8] != 0 && qipan[1][9] != 0 && qipan[2][7] != 0 && qipan[2][8] != 0 && qipan[2][9] != 0 && qipan[3][7] != 0 && qipan[3][8] != 0 && qipan[3][9] != 0 ){	
				atplace = 0;
			}else{
				atplace = 3;
			}
		}
	}
	if(x >= 7 && x <=9 && y >= 1 && y <= 3){
		if(x-6 == y){
			if(x == 8){
				atplace = 5;
			}else if(x == 7){
				if(qipan[1][1] != 0 && qipan[1][2] != 0 && qipan[1][3] != 0 && qipan[2][1] != 0 && qipan[2][2] != 0 && qipan[2][3] != 0 && qipan[3][1] != 0 && qipan[3][2] != 0 && qipan[3][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 1;
				}
			}else{
				if(qipan[7][7] != 0 && qipan[7][8] != 0 && qipan[7][9] != 0 && qipan[8][7] != 0 && qipan[8][8] != 0 && qipan[8][9] != 0 && qipan[9][7] != 0 && qipan[9][8] != 0 && qipan[9][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 9;
				}
			}
		}else if(x - y == 7){
			if(x == 8){
				if(qipan[4][1] != 0 && qipan[4][2] != 0 && qipan[4][3] != 0 && qipan[5][1] != 0 && qipan[5][2] != 0 && qipan[5][3] != 0 && qipan[6][1] != 0 && qipan[6][2] != 0 && qipan[6][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 4;
				}
			}else{
				if(qipan[7][4] != 0 && qipan[7][5] != 0 && qipan[7][6] != 0 && qipan[8][4] != 0 && qipan[8][5] != 0 && qipan[8][6] != 0 && qipan[9][4] != 0 && qipan[9][5] != 0 && qipan[9][6] != 0 ){	
					atplace = 0;
				}else{	
					atplace = 8;
				}
			}
		}else if(x - y == 5){
			if(x == 7){
				if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 2;
				}
			}else{
				if(qipan[4][7] != 0 && qipan[4][8] != 0 && qipan[4][9] != 0 && qipan[5][7] != 0 && qipan[5][8] != 0 && qipan[5][9] != 0 && qipan[6][7] != 0 && qipan[6][8] != 0 && qipan[6][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 6;
				}
			}
		}else if(x == 9){
			if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
				atplace = 0;
			}else{
				atplace = 7;
			}
		}else{
			if(qipan[1][7] != 0 && qipan[1][8] != 0 && qipan[1][9] != 0 && qipan[2][7] != 0 && qipan[2][8] != 0 && qipan[2][9] != 0 && qipan[3][7] != 0 && qipan[3][8] != 0 && qipan[3][9] != 0 ){	
				atplace = 0;
			}else{
				atplace = 3;
			}
		}
	}
	if(x >= 7 && x <=9 && y >= 4 && y <= 6){
		if(x-3 == y){
			if(x == 8){
				atplace = 5;
			}else if(x == 7){
				if(qipan[1][1] != 0 && qipan[1][2] != 0 && qipan[1][3] != 0 && qipan[2][1] != 0 && qipan[2][2] != 0 && qipan[2][3] != 0 && qipan[3][1] != 0 && qipan[3][2] != 0 && qipan[3][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 1;
				}
			}else{
				if(qipan[7][7] != 0 && qipan[7][8] != 0 && qipan[7][9] != 0 && qipan[8][7] != 0 && qipan[8][8] != 0 && qipan[8][9] != 0 && qipan[9][7] != 0 && qipan[9][8] != 0 && qipan[9][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 9;
				}
			}
		}else if(x - y == 4){
			if(x == 8){
				if(qipan[4][1] != 0 && qipan[4][2] != 0 && qipan[4][3] != 0 && qipan[5][1] != 0 && qipan[5][2] != 0 && qipan[5][3] != 0 && qipan[6][1] != 0 && qipan[6][2] != 0 && qipan[6][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 4;
				}
			}else{
				if(qipan[7][4] != 0 && qipan[7][5] != 0 && qipan[7][6] != 0 && qipan[8][4] != 0 && qipan[8][5] != 0 && qipan[8][6] != 0 && qipan[9][4] != 0 && qipan[9][5] != 0 && qipan[9][6] != 0 ){	
					atplace = 0;
				}else{	
					atplace = 8;
				}
			}
		}else if(x - y == 2){
			if(x == 7){
				if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 2;
				}
			}else{
				if(qipan[4][7] != 0 && qipan[4][8] != 0 && qipan[4][9] != 0 && qipan[5][7] != 0 && qipan[5][8] != 0 && qipan[5][9] != 0 && qipan[6][7] != 0 && qipan[6][8] != 0 && qipan[6][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 6;
				}
			}
		}else if(x == 9){
			if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
				atplace = 0;
			}else{
				atplace = 7;
			}
		}else{
			if(qipan[1][7] != 0 && qipan[1][8] != 0 && qipan[1][9] != 0 && qipan[2][7] != 0 && qipan[2][8] != 0 && qipan[2][9] != 0 && qipan[3][7] != 0 && qipan[3][8] != 0 && qipan[3][9] != 0 ){	
				atplace = 0;
			}else{
				atplace = 3;
			}
		}
	}
	if(x >= 7 && x <=9 && y >= 7 && y <= 9){
		if(x == y){
			if(x == 8){
				atplace = 5;
			}else if(x == 7){
				if(qipan[1][1] != 0 && qipan[1][2] != 0 && qipan[1][3] != 0 && qipan[2][1] != 0 && qipan[2][2] != 0 && qipan[2][3] != 0 && qipan[3][1] != 0 && qipan[3][2] != 0 && qipan[3][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 1;
				}
			}else{
				if(qipan[7][7] != 0 && qipan[7][8] != 0 && qipan[7][9] != 0 && qipan[8][7] != 0 && qipan[8][8] != 0 && qipan[8][9] != 0 && qipan[9][7] != 0 && qipan[9][8] != 0 && qipan[9][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 9;
				}
			}
		}else if(x - y == 1){
			if(x == 8){
				if(qipan[4][1] != 0 && qipan[4][2] != 0 && qipan[4][3] != 0 && qipan[5][1] != 0 && qipan[5][2] != 0 && qipan[5][3] != 0 && qipan[6][1] != 0 && qipan[6][2] != 0 && qipan[6][3] != 0 ){	
					atplace = 0;
				}else{
					atplace = 4;
				}
			}else{
				atplace = 8;
			}
		}else if(x - y == -1){
			if(x == 7){
				if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
					atplace = 0;
				}else{
					atplace = 2;
				}
			}else{
				if(qipan[4][7] != 0 && qipan[4][8] != 0 && qipan[4][9] != 0 && qipan[5][7] != 0 && qipan[5][8] != 0 && qipan[5][9] != 0 && qipan[6][7] != 0 && qipan[6][8] != 0 && qipan[6][9] != 0 ){	
					atplace = 0;
				}else{
					atplace = 6;
				}
			}
		}else if(x == 9){
			if(qipan[1][4] != 0 && qipan[1][5] != 0 && qipan[1][6] != 0 && qipan[2][4] != 0 && qipan[2][5] != 0 && qipan[2][6] != 0 && qipan[3][4] != 0 && qipan[3][5] != 0 && qipan[3][6] != 0 ){	
				atplace = 0;
			}else{
				atplace = 7;
			}
		}else{
			if(qipan[1][7] != 0 && qipan[1][8] != 0 && qipan[1][9] != 0 && qipan[2][7] != 0 && qipan[2][8] != 0 && qipan[2][9] != 0 && qipan[3][7] != 0 && qipan[3][8] != 0 && qipan[3][9] != 0 ){	
				atplace = 0;
			}else{
				atplace = 3;
			}
		}
	}
}

int player1(int x1,int y1){
	if(atplace == 0){
		if(qipan[x1][y1] == 0){
			start1 = true;
			qipan[x1][y1] = 1;
			daying();
		}else{
			cout<<"this place has been filled,please choose another place."<<endl;
		}
	}else if(atplace == 1){
		if(x1 >= 1 && x1 <= 3 && y1 >= 1 && y1 <= 3){
			if(qipan[x1][y1] == 0){
				start1 = true;
				qipan[x1][y1] = 1;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time1 = false;
		}
	}else if(atplace == 2){
		if(x1 >= 1 && x1 <= 3 && y1 >= 4 && y1 <= 6){
			if(qipan[x1][y1] == 0){
				start1 = true;
				qipan[x1][y1] = 1;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time1 = false;
		}
	}else if(atplace == 3){
		if(x1 >= 1 && x1 <= 3 && y1 >= 7 && y1 <= 9){
			if(qipan[x1][y1] == 0){
				start1 = true;
				qipan[x1][y1] = 1;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time1 = false;
		}
	}else if(atplace == 4){
		if(x1 >= 4 && x1 <= 6 && y1 >= 1 && y1 <= 3){
			if(qipan[x1][y1] == 0){
				start1 = true;
				qipan[x1][y1] = 1;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time1 = false;
		}
	}else if(atplace == 5){
		if(x1 >= 4 && x1 <= 6 && y1 >= 4 && y1 <= 6){
			if(qipan[x1][y1] == 0){
				start1 = true;
				qipan[x1][y1] = 1;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time1 = false;
		}
	}else if(atplace == 6){
		if(x1 >= 4 && x1 <= 6 && y1 >= 7 && y1 <= 9){
			if(qipan[x1][y1] == 0){
				start1 = true;
				qipan[x1][y1] = 1;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time1 = false;
		}
	}else if(atplace == 7){
		if(x1 >= 7 && x1 <= 9 && y1 >= 1 && y1 <= 3){
			if(qipan[x1][y1] == 0){
				start1 = true;
				qipan[x1][y1] = 1;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time1 = false;
		}
	}else if(atplace == 8){
		if(x1 >= 7 && x1 <= 9 && y1 >= 4 && y1 <= 6){
			if(qipan[x1][y1] == 0){
				start1 = true;
				qipan[x1][y1] = 1;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time1 = false;
		}
	}else if(atplace == 9){
		if(x1 >= 7 && x1 <= 9 && y1 >= 7 && y1 <= 9){
			if(qipan[x1][y1] == 0){
				start1 = true;
				qipan[x1][y1] = 1;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time1 = false;
		}
	}
}

int player2(int x2,int y2){
	if(atplace == 0){	
		if(qipan[x2][y2] == 0){
			start2 = true;
			qipan[x2][y2] = 2;
			daying();
		}else{
			cout<<"this place has been filled,please choose another place."<<endl;
		}
	}else if(atplace == 1){
		if(x2 >= 1 && x2 <= 3 && y2 >= 1 && y2 <= 3){
			if(qipan[x2][y2] == 0){
				start2 = true;
				qipan[x2][y2] = 2;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time2 = false;
		}
	}else if(atplace == 2){
		if(x2 >= 1 && x2 <= 3 && y2 >= 4 && y2 <= 6){
			if(qipan[x2][y2] == 0){
				start2 = true;
				qipan[x2][y2] = 2;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time2 = false;
		}
	}else if(atplace == 3){
		if(x2 >= 1 && x2 <= 3 && y2 >= 7 && y2 <= 9){
			if(qipan[x2][y2] == 0){
				start2 = true;
				qipan[x2][y2] = 2;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time2 = false;
		}
	}else if(atplace == 4){
		if(x2 >= 4 && x2 <= 6 && y2 >= 1 && y2 <= 3){
			if(qipan[x2][y2] == 0){
				start2 = true;
				qipan[x2][y2] = 2;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time2 = false;
		}
	}else if(atplace == 5){
		if(x2 >= 4 && x2 <= 6 && y2 >= 4 && y2 <= 6){
			if(qipan[x2][y2] == 0){
				start2 = true;
				qipan[x2][y2] = 2;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time2 = false;
		}
	}else if(atplace == 6){
		if(x2 >= 4 && x2 <= 6 && y2 >= 7 && y2 <= 9){
			if(qipan[x2][y2] == 0){
				start2 = true;
				qipan[x2][y2] = 2;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time2 = false;
		}
	}else if(atplace == 7){
		if(x2 >= 7 && x2 <= 9 && y2 >= 1 && y2 <= 3){
			if(qipan[x2][y2] == 0){
				start2 = true;
				qipan[x2][y2] = 2;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time2 = false;
		}
	}else if(atplace == 8){
		if(x2 >= 7 && x2 <= 9 && y2 >= 4 && y2 <= 6){
			if(qipan[x2][y2] == 0){
				start2 = true;
				qipan[x2][y2] = 2;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time2 = false;
		}
	}else if(atplace == 9){
		if(x2 >= 7 && x2 <= 9 && y2 >= 7 && y2 <= 9){
			if(qipan[x2][y2] == 0){
				start2 = true;
				qipan[x2][y2] = 2;
				daying();
			}else{
				cout<<"this place has been filled,please choose another place."<<endl;
			}
		}else{
			cout<<"this place is not allowed,please choose another place."<<endl;
			time2 = false;
		}
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
//	qipan[1][1]=1;
//	qipan[2][2]=1;
//	qipan[3][3]=1;
//	qipan[4][1]=1;
//	qipan[5][2]=1;
//	qipan[6][3]=1;
//	qipan[7][1]=1;
//	qipan[8][2]=1;
//	qipan[9][3]=1;
	cout << "the game of qipan" << endl;
	daying();
	cout << "player 1 is '1' , player 2 is '2' "<<endl<<endl;
	cout << "If you want to change the place (3,2) , you can type the '3 2' , then the qipan will become like this : " << endl <<endl ;
	qipan[2][3] = 1;
	daying();
	cout<<endl<<endl;
	qipan[2][3] = 0;
	//开始
	
	cout<<endl<<"NOW START!"<<endl;
	daying();
	for(int iii = 1;over == false ; iii){
		bool game = true;
		start1 = false;
		start2 = false;
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
					int k=i , h=j;
					for(k;k <= i+2;k++){
						for(h;h <= j+2 ; h++){
							qipan[k][h]=1;
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
		ap(x11,y11);
		game = true ;
		for(int a = 1;a<=7;a=a+3){
			for(int b = 1;b<=7;b=b+3){
				game = true;	
				for(int i=a;i<=a+2;i++){
					for(int j=b;j<=b+2;j++){
						if(qipan[i][j] == 0 || qipan[i][j] == 2){
							game = false;
						}
					}
				}
				if(game == true){
					cout<<endl;
					daying();
					cout<<"Congratuations! player1 wins!"<<endl;
					over = true;
					return 0;
				}
			}
		}
		//横着三个胜利
		
		game = true;
		for(int a = 1;a<=7;a=a+3){
			for(int b = 1;b<=7;b=b+3){	
				game = true;
				for(int i=b;i<=b+2;i++){
					for(int j=a;j<=a+2;j++){
						if(qipan[i][j] == 0 || qipan[i][j] == 2){
							game = false;
						}
					}
				}
				if(game == true){
					cout<<endl;
					daying();
					cout<<"Congratuations! player1 wins!"<<endl;
					over = true;
					return 0;
				} 
			}
		}
		//竖着三个胜利
		
		game = true;
		for(int ab = 1;ab <= 9;ab = ab + 2){
			for(int ac = ab;ac <= ab; ac = ac + 2){
				if(qipan[ab][ac] == 0 || qipan[ab][ac] == 2){
					game = false;
				}
			}
		}
		if(game == true){
			cout<<endl;
			daying();
			cout<<"Congratuations! player1 wins!"<<endl;
			over = true;
			return 0;
		} 
		//斜的三个胜利 
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
					int k=i , h=j;
					for(k;k <= i+2;k++){
						for(h;h <= j+2 ; h++){
							qipan[k][h]=2;
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
		ap(x22,y22);
		game = true;
		for(int a = 1;a<=7;a=a+3){
			for(int b = 1;b<=7;b=b+3){	
				game = true;
				for(int i=a;i<=a+2;i++){
					for(int j=b;j<=b+2;j++){
						if(qipan[i][j] == 0 || qipan[i][j] == 1){
							game = false;
						}
					}
				}
				if(game == true){
					cout<<endl;
					daying();
					cout<<"Congratuations! player2 wins!"<<endl;
					over = true;
					return 0;
				}
			}
		}
		//横着三个胜利
		
		game = true;
		for(int b = 1;b<=7;b=b+3){
			for(int a = 1;a<=7;a=a+3){	
				game = true;
				for(int i=b;i<=b+2;i++){
					for(int j=a;j<=a+2;j++){
						if(qipan[i][j] == 0 || qipan[i][j] == 1){
							game = false;
						}
					}
				}
				if(game == true){
					cout<<endl;
					daying();
					cout<<"Congratuations! player2 wins!"<<endl;
					over = true;
					return 0;
				} 
			}
		}
		//竖着三个胜利
		
		game = true;
		for(int ab = 1;ab <= 9;ab = ab + 2){
			for(int ac = ab;ac <= ab; ac = ac + 2){
				if(qipan[ab][ac] == 0 || qipan[ab][ac] == 1){
					game = false;
				}
			}
		}
		if(game == true){
			cout<<endl;
			daying();
			cout<<"Congratuations! player2 wins!"<<endl;
			over = true;
			return 0;
		} 
		//斜的三个胜利 
		
		//player2 
	}






	return 0;
}
