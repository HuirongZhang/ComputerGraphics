#include<graphics.h>
#include<conio.h>
#include"data.h"

void bezier_to_point(int c,int v[][8]);
long  DeCasteljau(double t, long *p);


void bezier_to_point(int c, int v[][8]) {
	//de Casteljau算法,先考虑实现,再考虑优化
	for (int i = 0; i <c; i++) {
		long px[4] = { v[i][0], v[i][2],v[i][4],v[i][6] };
		long py[4] = { -v[i][1], -v[i][3],-v[i][5],-v[i][7] };
		for (double t = 0.0; t <=1.0; t += 0.001) {
			int x = (int)DeCasteljau(t, px)+100;
			int y = (int)DeCasteljau(t, py)+700;
			putpixel(x, y, BLACK);
		}
	}
}

long  DeCasteljau(double t,long *p){
	double P[4][4];

	for (int i = 0; i < 4; i++) {
		P[0][i] = p[i];
	}

	for (int j = 1; j < 4; j++) {
		for (int k = 0; k < 4 - j; k++) {
			P[j][k] = (1 - t)*P[j - 1][k] + t*P[j - 1][k + 1];
		}
	}

	return (long)P[3][0];

}

int main(int argc, char * argv[]) {
	
/*#ifdef DEBUG
	ifstream cin("T.txt");
#endif // DEBUG
	int T[16][8];
	for (int i = 0; i < 16; i++) {
		for(int j=0;j<8;j++){
			cin >> T[i][j];
	}
	
#ifdef DEBUG
	cin.close();
#endif // DEBUG*/

	
	initgraph(800, 800); // 初始化绘图窗口

	setbkcolor(WHITE);//设置背景色为白色

	cleardevice(); //调用清屏cleardevice用背景色刷新背景

	//bezier_to_point(sizeof(coordnate_T) / sizeof(coordnate_T[0]), coordnate_T);

	//bezier_to_point(sizeof(coordnate_F) / sizeof(coordnate_F[0]), coordnate_F);

	bezier_to_point(sizeof(coordnate_5) / sizeof(coordnate_5[0]), coordnate_5);


	_getch();
	return 0;
}
