#include <graphics.h> 
#include <conio.h>
#include <stdlib.h>
#include <stdio.h> 
#include <string> 

using namespace std; 

#define MAX_STAR 100 
#define SCREEN_WIDTH 640 
#define SCREEN_HEIGHT 480 
#define MAX_STEP 5 
#define MAX_RADIUS 3 
#define BOTTOM_MARGIN 100 

//����״̬ 
enum STATUS{
	STOP=0, 
	UP, 
	DOWN, 
	LEFT, 
	RIGHT, 
	RANDOM, 
	ALL_STATUS 
};

struct STAR{
	int x;				//���ǵ� x ���� 
	int y;				//���ǵ� y ���� 
	enum STATUS stat;	//״̬ 
	unsigned radius;	//���ǵİ뾶 
	int step;			//ÿ����Ծ�ļ�� 
	int color;			//���ǵ���ɫ 
};

struct STAR star[MAX_STAR];

bool isQuit() {
	for (int i = 0; i < MAX_STAR; i++) {
		if (star[i].x > 0 && star[i].x < SCREEN_WIDTH && star[i].y>0 &&
			star[i].y < SCREEN_HEIGHT) {
			return false;
		}
	}

	return true;
}

void MoveStar(int i) {

	if (star[i].stat == STOP) return; 

	//����ԭ�������� 
	setfillcolor(BLACK); 
	solidcircle(star[i].x, star[i].y, star[i].radius); 

	if(star[i].stat == DOWN){ 
		star[i].y =star[i].y + star[i].step; 
		//if (star[i].y > SCREEN_HEIGHT) star[i].y = 0;
	}else if(star[i].stat == UP){ 
		star[i].y -= star[i].step; 
		//if(star[i].y<0) star[i].y = SCREEN_HEIGHT; 
	}else if(star[i].stat == LEFT){ 
		star[i].x -= star[i].step; 
		//if(star[i].x<0) star[i].x = SCREEN_WIDTH; 
	}else if(star[i].stat == RIGHT){ 
		star[i].x += star[i].step; 
		//if(star[i].x>SCREEN_WIDTH) star[i].x = 0; 
	}

	setfillcolor(star[i].color); 
	solidcircle(star[i].x, star[i].y, star[i].radius); 

}

/************************************ 
* ���ܣ���ʼ������
* * ��������� 
* i - ������ȫ�������е��±� 
* ����ֵ���� 
************************************/

void initStar(int i) {
	int rgb = 0; 
	if (i<0 || i>MAX_STAR) {
		fprintf(stderr, "��˾�����㴫��ֵ i[%d]���ܲ��ˣ�", i); //log �� ־ 
		return; 
	}

	//rand() �õ��������Χ 0 - 32767 RAND_MAX 
	star[i].x = rand()% SCREEN_WIDTH; // x ��Χ 0 -639 
	star[i].y = rand()% (SCREEN_HEIGHT - BOTTOM_MARGIN);// y ��Χ 0 - 379 

	star[i].stat = UP;	//(enum STATUS)(rand() % ALL_STATUS);  ����״̬���
	star[i].radius = 1 + rand() % MAX_RADIUS; //�뾶���� 1 - 3 
	star[i].step = rand() % MAX_STEP + 1; //���� 1 - 5 
	rgb = 255 * star[i].step / MAX_STEP; // 0 - 255 
	star[i].color = RGB(rgb, rgb, rgb);
}

int main(){

	bool quit = false;

	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT); 
	for (int i = 0; i < MAX_STAR; i++) {
		initStar(i);
	}

	for (int i = 0; i < MAX_STAR; i++) {
		setfillcolor(star[i].color);
		solidcircle(star[i].x, star[i].y, star[i].radius);
	}

	IMAGE tortoise; //����ͼƬ 
	loadimage(&tortoise, _T("tortoise.jpg"), 30, 30, false);
	putimage(SCREEN_WIDTH * 4 / 10 - 30, SCREEN_HEIGHT - 30, &tortoise);
	putimage(SCREEN_WIDTH * 6 / 10, SCREEN_HEIGHT - 30, &tortoise);

	while (quit == false) {
		for (int i = 0; i < MAX_STAR; i++) {
			MoveStar(i); 
		}
		if (isQuit()) { 
			quit = true; 
		}
		
		Sleep(50);
	}

	system("pause"); 
	closegraph(); 
	return 0; 
}