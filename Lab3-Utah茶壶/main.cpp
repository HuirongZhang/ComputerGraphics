#include<graphics.h>
#include<conio.h>
#include<math.h>
#include"UtahTeapot.h"
#define PI 3.1415926

int main() {

	initgraph(800, 800); // 初始化绘图窗口 

	setbkcolor(WHITE);//设置背景色为白色

	cleardevice(); //调用清屏cleardevice用背景色刷新背景

	double x, y, z, t, u, w;
	//t是三次贝塞尔曲线控制参数
	//u,w是双三次贝塞尔曲面控制参数
	//x,y,z贝塞尔控制得到的点
	int i, j;

	double xc, yc, zc, xs, ys;//xs,ys 最终坐标

	xc = 0;
	yc = 100;
	zc = 300;//透视投影视点(投影中心)

	int degree;
	double s, c;
	//壶体
	for (degree = 0; degree <= 360; degree++)
	{
		s = sin(degree * PI / 180);
		c = cos(degree * PI / 180);

		for (i = 0; i < 100; i++)
		{
			t = 0.01*i;
			x = (point_body[0][0] * t*t*t + point_body[1][0] * 3 * t*t*(1 - t) + point_body[2][0] * 3 * t*(1 - t)*(1 - t) + point_body[3][0] * (1 - t)*(1 - t)*(1 - t)) ;
			y = (point_body[0][1] * t*t*t + point_body[1][1] * 3 * t*t*(1 - t) + point_body[2][1] * 3 * t*(1 - t)*(1 - t) + point_body[3][1] * (1 - t)*(1 - t)*(1 - t)) ;
			
			x = 80*x;
			y = 80*y;

			xs = (xc*x * s - zc*x * c) / (-x * s - zc);
			ys = (-yc*x * s - zc*y) / (-x * s - zc);
			putpixel( 400 + xs, 400-ys, RGB(192,192,192));

			x = (point_body[3][0] * t*t*t + point_body[4][0] * 3 * t*t*(1 - t) + point_body[5][0] * 3 * t*(1 - t)*(1 - t) + point_body[6][0] * (1 - t)*(1 - t)*(1 - t)) ;
			y = (point_body[3][1] * t*t*t + point_body[4][1] * 3 * t*t*(1 - t) + point_body[5][1] * 3 * t*(1 - t)*(1 - t) + point_body[6][1] * (1 - t)*(1 - t)*(1 - t)) ;
			
			x = 80*x;
			y = 80*y;

			xs = (xc*x * s - zc*x * c) / (-x * s - zc);
			ys = (-yc*x * s - zc*y) / (-x * s - zc);
			putpixel( 400 + xs, 400-ys, RGB(192,192,192));

			x = (point_body[6][0] * t*t*t + point_body[7][0] * 3 * t*t*(1 - t) + point_body[8][0] * 3 * t*(1 - t)*(1 - t) + point_body[9][0] * (1 - t)*(1 - t)*(1 - t)) ;
			y = (point_body[6][1] * t*t*t + point_body[7][1] * 3 * t*t*(1 - t) + point_body[8][1] * 3 * t*(1 - t)*(1 - t) + point_body[9][1] * (1 - t)*(1 - t)*(1 - t)) ;
			
			x = 80*x;
			y = 80*y;

			xs = (xc*x * s - zc*x * c) / (-x * s - zc);
			ys = (-yc*x * s - zc*y) / (-x * s - zc);
			putpixel( 400 + xs, 400-ys, RGB(192,192,192));
		}
	}


	//壶盖
	for (degree = 0; degree <= 360; degree++)
	{
		s = sin(degree * PI / 180);
		c = cos(degree * PI / 180);


		for (i = 0; i < 100; i++)
		{
			t = 0.01*i;
			x = (point_lid[0][0] * t*t*t + point_lid[1][0] * 3 * t*t*(1 - t) + point_lid[2][0] * 3 * t*(1 - t)*(1 - t) + point_lid[3][0] * (1 - t)*(1 - t)*(1 - t)) ;
			y = (point_lid[0][1] * t*t*t + point_lid[1][1] * 3 * t*t*(1 - t) + point_lid[2][1] * 3 * t*(1 - t)*(1 - t) + point_lid[3][1] * (1 - t)*(1 - t)*(1 - t)) ;

			x = 80*x;
			y = 80*y;

			xs = (xc*x * s - zc*x * c) / (-x * s - zc);
			ys = (-yc*x * s - zc*y) / (-x * s - zc);
			putpixel( 400 + xs, 400-ys, RGB(192,192,192));

			x = (point_lid[3][0] * t*t*t + point_lid[4][0] * 3 * t*t*(1 - t) + point_lid[5][0] * 3 * t*(1 - t)*(1 - t) + point_lid[6][0] * (1 - t)*(1 - t)*(1 - t)) ;
			y = (point_lid[3][1] * t*t*t + point_lid[4][1] * 3 * t*t*(1 - t) + point_lid[5][1] * 3 * t*(1 - t)*(1 - t) + point_lid[6][1] * (1 - t)*(1 - t)*(1 - t)) ;

			x = 80*x;
			y = 80*y;

			xs = (xc*x * s - zc*x * c) / (-x * s - zc);
			ys = (-yc*x * s - zc*y) / (-x * s - zc);
			putpixel( 400 + xs, 400-ys, RGB(192,192,192));
		}
	}


	//壶嘴


	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			u = 0.01*i;
			w = 0.01*j;
			double a, b, c, d, e, f, g, h;
			a = -u*u*u + 3 * u*u - 3 * u + 1;
			b = 3 * u*u*u - 6 * u*u + 3 * u;
			c = -3 * u*u*u + 3 * u*u;
			d = u*u*u;

			e = -w*w*w + 3 * w*w - 3 * w + 1;
			f = 3 * w*w*w - 6 * w*w + 3 * w;
			g = -3 * w*w*w + 3 * w*w;
			h = w*w*w;

			x = ((a*point_mouth[0][0] + b*point_mouth[1][0] + c*point_mouth[2][0] + d*point_mouth[3][0])*e + (a*point_mouth[0][0] + b*point_mouth[1][0] + c*point_mouth[2][0] + d*point_mouth[3][0])*f + (a*point_mouth[7][0] + b*point_mouth[8][0] + c*point_mouth[9][0] + d*point_mouth[10][0])*g + (a*point_mouth[7][0] + b*point_mouth[8][0] + c*point_mouth[9][0] + d*point_mouth[10][0])*h) ;
			y = ((a*point_mouth[0][1] + b*point_mouth[1][1] + c*point_mouth[2][1] + d*point_mouth[3][1])*e + (a*point_mouth[0][1] + b*point_mouth[1][1] + c*point_mouth[2][1] + d*point_mouth[3][1])*f + (a*point_mouth[7][1] + b*point_mouth[8][1] + c*point_mouth[9][1] + d*point_mouth[10][1])*g + (a*point_mouth[7][1] + b*point_mouth[8][1] + c*point_mouth[9][1] + d*point_mouth[10][1])*h) ;
			z = ((a*point_mouth[0][2] + b*point_mouth[1][2] + c*point_mouth[2][2] + d*point_mouth[3][2])*f + (a*point_mouth[7][2] + b*point_mouth[8][2] + c*point_mouth[9][2] + d*point_mouth[10][2])*g) ;

			x = 80*x;
			y = 80*y;
			z = 80*z;

			xs = (xc*z - zc*x) / (z - zc);
			ys = (-yc*z - zc*y) / (z - zc);
			putpixel( 400 + xs, 400-ys, RGB(192,192,192));

			x = ((a*point_mouth[3][0] + b*point_mouth[4][0] + c*point_mouth[5][0] + d*point_mouth[6][0])*e + (a*point_mouth[3][0] + b*point_mouth[4][0] + c*point_mouth[5][0] + d*point_mouth[6][0])*f + (a*point_mouth[10][0] + b*point_mouth[11][0] + c*point_mouth[12][0] + d*point_mouth[13][0])*g + (a*point_mouth[10][0] + b*point_mouth[11][0] + c*point_mouth[12][0] + d*point_mouth[13][0])*h) ;
			y = ((a*point_mouth[3][1] + b*point_mouth[4][1] + c*point_mouth[5][1] + d*point_mouth[6][1])*e + (a*point_mouth[3][1] + b*point_mouth[4][1] + c*point_mouth[5][1] + d*point_mouth[6][1])*f + (a*point_mouth[10][1] + b*point_mouth[11][1] + c*point_mouth[12][1] + d*point_mouth[13][1])*g + (a*point_mouth[10][1] + b*point_mouth[11][1] + c*point_mouth[12][1] + d*point_mouth[13][1])*h) ;
			z = ((a*point_mouth[3][2] + b*point_mouth[4][2] + c*point_mouth[5][2] + d*point_mouth[6][2])*f + (a*point_mouth[10][2] + b*point_mouth[11][2] + c*point_mouth[12][2] + d*point_mouth[13][2])*g) ;

			x = 80*x;
			y = 80*y;
			z = 80*z;

			xs = (xc*z - zc*x) / (z - zc);
			ys = (-yc*z - zc*y) / (z - zc);
			putpixel( 400 + xs, 400-ys, RGB(192,192,192));
		}
	}


	//把手

	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			u = 0.01*i;
			w = 0.01*j;
			double a, b, c, d, e, f, g, h;
			a = -u*u*u + 3 * u*u - 3 * u + 1;
			b = 3 * u*u*u - 6 * u*u + 3 * u;
			c = -3 * u*u*u + 3 * u*u;
			d = u*u*u;

			e = -w*w*w + 3 * w*w - 3 * w + 1;
			f = 3 * w*w*w - 6 * w*w + 3 * w;
			g = -3 * w*w*w + 3 * w*w;
			h = w*w*w;

			x = ((a*point_hand[0][0] + b*point_hand[1][0] + c*point_hand[2][0] + d*point_hand[3][0])*e + (a*point_hand[0][0] + b*point_hand[1][0] + c*point_hand[2][0] + d*point_hand[3][0])*f + (a*point_hand[7][0] + b*point_hand[8][0] + c*point_hand[9][0] + d*point_hand[10][0])*g + (a*point_hand[7][0] + b*point_hand[8][0] + c*point_hand[9][0] + d*point_hand[10][0])*h) ;
			y = ((a*point_hand[0][1] + b*point_hand[1][1] + c*point_hand[2][1] + d*point_hand[3][1])*e + (a*point_hand[0][1] + b*point_hand[1][1] + c*point_hand[2][1] + d*point_hand[3][1])*f + (a*point_hand[7][1] + b*point_hand[8][1] + c*point_hand[9][1] + d*point_hand[10][1])*g + (a*point_hand[7][1] + b*point_hand[8][1] + c*point_hand[9][1] + d*point_hand[10][1])*h) ;
			z = ((a*point_hand[0][2] + b*point_hand[1][2] + c*point_hand[2][2] + d*point_hand[3][2])*f + (a*point_hand[7][2] + b*point_hand[8][2] + c*point_hand[9][2] + d*point_hand[10][2])*g) ;

			x = 80*x;
			y = 80*y;
			z = 80*z;

			xs = -(xc*z - zc*x) / (z - zc);
			ys = (-yc*z - zc*y) / (z - zc);
			putpixel( 400 + xs, 400-ys, RGB(192,192,192));

			x = ((a*point_hand[3][0] + b*point_hand[4][0] + c*point_hand[5][0] + d*point_hand[6][0])*e + (a*point_hand[3][0] + b*point_hand[4][0] + c*point_hand[5][0] + d*point_hand[6][0])*f + (a*point_hand[10][0] + b*point_hand[11][0] + c*point_hand[12][0] + d*point_hand[13][0])*g + (a*point_hand[10][0] + b*point_hand[11][0] + c*point_hand[12][0] + d*point_hand[13][0])*h) ;
			y = ((a*point_hand[3][1] + b*point_hand[4][1] + c*point_hand[5][1] + d*point_hand[6][1])*e + (a*point_hand[3][1] + b*point_hand[4][1] + c*point_hand[5][1] + d*point_hand[6][1])*f + (a*point_hand[10][1] + b*point_hand[11][1] + c*point_hand[12][1] + d*point_hand[13][1])*g + (a*point_hand[10][1] + b*point_hand[11][1] + c*point_hand[12][1] + d*point_hand[13][1])*h) ;
			z = ((a*point_hand[3][2] + b*point_hand[4][2] + c*point_hand[5][2] + d*point_hand[6][2])*f + (a*point_hand[10][2] + b*point_hand[11][2] + c*point_hand[12][2] + d*point_hand[13][2])*g) ;

			x = 80*x;
			y = 80*y;
			z = 80*z;

			xs = -(xc*z - zc*x) / (z - zc);
			ys = (-yc*z - zc*y) / (z - zc);
			putpixel(400 + xs, 400-ys, RGB(192,192,192));
		}
	}
	
	_getch();
	return 0;
}