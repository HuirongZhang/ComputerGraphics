#include<graphics.h>
#include<conio.h>
#include<ctime>
#define random(a,b) (rand()%(b-a+1)+a)
int main() {
	srand((unsigned)time(NULL));
	initgraph(600, 600); // ³õÊ¼»¯»æÍ¼´°¿Ú
	float x=1, y=1, x1, y1;
	for (int i = 0; i < 1000000; ++i) {
		if (random(1, 100) > 15) {
			x1 = 0.85*x + 0.04*y; y1 = -0.04*x + 0.85*y + 1.6;
			putpixel(200 + 50 * x1, 80 + 50 * y1, GREEN);
			x = x1; y = y1;
		}
		else if (random(1, 100) > 8) {
			x1 = -0.15*x + 0.28*y;	y1 = 0.26*x + 0.24*y + 0.44;
			putpixel(200 + 50 * x1, 80 + 50 * y1, GREEN);
			x = x1; y = y1;
		}
		else if (random(1, 100) >1) {
			x1 = 0.2*x + -0.26*y;	y1 = 0.23*x + 0.22*y + 1.6;
			putpixel(200 + 50 * x1, 80 + 50 * y1, GREEN);
			x = x1; y = y1;
		}
		else {
			x1 = 0; y1 = 0.16*y;
			putpixel(200 + 50 * x1, 80 + 50 * y1, GREEN);
			y = y1;
		}
	}
	_getch();
	return 0;
}