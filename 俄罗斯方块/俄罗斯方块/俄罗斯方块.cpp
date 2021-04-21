#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int score = 0;	//����
int rank = 0;		//�ȼ�

#define BLOCK_COUNT		5
#define BLOCK_WIDTH		5
#define BLOCK_HEIGHT	5
#define UNIT_SIZE				20

#define START_X				130
#define START_Y				30

#define KEY_UP					72
#define KEY_RIGHT			77
#define KEY_DOWN			80
#define KEY_LEFT				75
#define KEY_SPACE			32

int speed = 500;

typedef enum block_dir_t {
	BLOCK_UP,
	BLOCK_RIGHT,
	BLOCK_DOWN,
	BLOCK_LEFT
};

typedef enum move_dir_t {
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT
};

int NextIndex = -1;	//��һ�����������
int BlockIndex = -1;	//��ǰ��Ϸ�����������

int color[BLOCK_COUNT] = {
	LIGHTGREEN,LIGHTCYAN,LIGHTMAGENTA,BROWN,YELLOW
};

int visit[30][15];		//��������

int block[BLOCK_COUNT * 4][BLOCK_HEIGHT][BLOCK_WIDTH] = {
	// "|" �η���
	{	//����
		0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,0,0,0
	},

	{	//����
		0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},

	{	//����
		0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,0,0,0
	},

	{	//����
		0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},

	// "L" �ͷ���
	{
		0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0
	},

	{ 
		0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,1,0,
		0,1,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,1,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,0,0,1,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	// "��" �η���
	{ 
		0,0,0,0,0,
		0,1,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,1,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,1,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	{
		0,0,0,0,0,
		0,1,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	// "T" �η���
	{ 
		0,0,0,0,0,
		0,1,1,1,0,
		0,0,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	},

	{ 
		0,0,0,0,0,
		0,0,0,1,0,
		0,0,1,1,0,
		0,0,0,1,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,0,1,0,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,1,0,0,0,
		0,1,1,0,0,
		0,1,0,0,0,
		0,0,0,0,0 
	},

	// "Z" �η���
	{
		0,0,0,0,0,
		0,1,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,0,1,0,0,
		0,1,1,0,0,
		0,1,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,1,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,0,1,0,0,
		0,1,1,0,0,
		0,1,0,0,0,
		0,0,0,0,0 
	}
};

void welcome(void) {
	initgraph(550, 660);
	HWND window = GetHWnd();		//��ȡ����
	SetWindowText(window, _T("����˹����    ����"));		//���ô��ڱ���

	//�����ı���	������ʽ
	settextstyle(40, 0, _T("΢���ź�"));
	setcolor(WHITE);
	outtextxy(205, 200, _T("����˹����! "));
	settextstyle(20, 0, _T("����"));
	outtextxy(175, 300, _T("���, �Ӷ���˹���鿪ʼ! "));
	Sleep(3000);	//˯�� (��ͣ) 3000����, 3����
}

//��ʼ����Ϸ����
void initGameScene(void) {
	char str[16];

	//�����Ļ
	cleardevice();
	//initgraph(550, 660);
	//HWND	window = GetHWnd();
	//SetWindowText(window, _T("����˹����    ����"));

	setlinecolor(WHITE);
	rectangle(27, 27, 336, 635);
	rectangle(29, 29, 334, 633);
	rectangle(370, 50, 515, 195);

	settextstyle(24, 0, _T("����"));
	settextcolor(LIGHTGRAY);
	outtextxy(405, 215, _T("��һ��: "));

	settextcolor(RED);
	outtextxy(405, 280, _T("����: "));
	sprintf_s(str, "%d", score);
	outtextxy(415, 310, str);

	outtextxy(405, 375, _T("�ȼ�: "));
	sprintf_s(str, "%d", rank);
	outtextxy(425, 405, str);

	//����˵��	��	��	��	  ��
	settextcolor(LIGHTBLUE);
	outtextxy(390, 475, _T("����˵��: "));
	outtextxy(390, 500, _T("��: ��ת"));
	outtextxy(390, 525, _T("��: �½�"));
	outtextxy(390, 550, _T("��: ����"));
	outtextxy(390, 575, _T("��: ����"));
	outtextxy(390, 600, _T("�ո�: ��ͣ"));
}

void clearBlock(int x, int y) {
	settextcolor(BLACK);
	settextstyle(23, 0, _T("����"));

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			//"��"
			outtextxy(x + j * UNIT_SIZE, y + i * UNIT_SIZE, _T("��"));
		}
	}
}

void clearBlock(int x, int y, block_dir_t dir) {
	settextcolor(BLACK);
	settextstyle(23, 0, _T("����"));

	if (dir == BLOCK_UP || dir == BLOCK_RIGHT || dir == BLOCK_DOWN || dir == BLOCK_LEFT) {
		for (int i = 0; i < BLOCK_HEIGHT; i++) {
			for (int j = 0; j < BLOCK_WIDTH; j++) {
				//"��"
				outtextxy(x + j * UNIT_SIZE, y + i * UNIT_SIZE, _T("��"));
			}
		}
	}
}

// �����Ͻ�������, ������һ������
void drawBlock(int x, int y,int next) {
	settextcolor(color[NextIndex]);
	settextstyle(23, 0, _T("����"));

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[NextIndex * 4][i][j]) {
				//"��"
				outtextxy(x + j * UNIT_SIZE, y + i * UNIT_SIZE, _T("��"));
			}
		}
	}
}

void drawBlock(int x, int y, int blockIndex,block_dir_t dir) {

}

void nextBlock(void) {
	int x = 391;
	int y = 71;

	clearBlock(x, y);			// ���Ҳ����ʾ�����ԭ���ķ���
	
	// ���ѡ��һ�ַ���
	srand(time(NULL));		//ʹ��ʱ�亯���ķ���ֵ, ����Ϊ�������
	NextIndex = rand() % BLOCK_COUNT;
	drawBlock(x, y, NextIndex);

}

// �����ָ��λ�ÿ�����ָ�������ƶ�, �ͷ���1,����ͷ���0
int moveAble(int x, int y, move_dir_t moveDir, block_dir_t blockDir) {

	if (moveDir == MOVE_DOWN) {
		//for(int i=0;i<)
	}
	else if (moveDir == MOVE_LEFT) {

	}
	else if (moveDir == MOVE_RIGHT) {

	}

	return 1;
}

//�����Ϸ�Ƿ����
void failCheck() {
	if (!moveAble(START_X, START_Y, MOVE_DOWN, BLOCK_UP)) {
		setcolor(WHITE);
		settextstyle(45, 0, _T("����"));
		outtextxy(75, 300, _T("GAME OVER"));
		Sleep(1000);
		system("pause");
		closegraph();
		exit(0);
	}
}

void wait(int interval) {

}

void move() {
	int x = START_X;
	int y = START_Y;
	block_dir_t blockDir = BLOCK_UP;
	int curSpeed = speed;

	//�����Ϸ�Ƿ����
	failCheck();

	//�������½���
	while (1) {
		if (_kbhit()) {
			int key = _getch();
			if (key == KEY_SPACE) {
				_getch();
			}
		}
	}
		
	//�����ǰ����
	clearBlock(x, y, blockDir);

	if (_kbhit()) {
		int key = _getch();
		if (key == KEY_UP) {

		}
		else if (key == KEY_DOWN) {
			/*for (int i = 0; i < BLOCK_HEIGHT; i++) {
				for (int j = 0; j < BLOCK_WIDTH; j++) {
					visit[i - 1][j] = block[BlockIndex * 4][i][j];
				}
			}
		}
		else if (key == KEY_LEFT) {
			for (int i = 0; i < BLOCK_HEIGHT; i++) {
				for (int j = 0; j < BLOCK_WIDTH; j++) {
					visit[i][j - 1] = block[BlockIndex * 4][i][j];
				}
			}
		}
		else if (key == KEY_RIGHT) {
			for (int i = 0; i < BLOCK_HEIGHT; i++) {
				for (int j = 0; j < BLOCK_WIDTH; j++) {
					visit[i][j + 1] = block[BlockIndex * 4][i][j];
				}
			}*/
		}

	// ���Ƶ�ǰ����
	//drawBlock()
	wait(curSpeed);

	// ����� "�̻�" ����
	//to do.
	}
}

void newBlock() {
	// ȷ������ʹ�õķ�������
	BlockIndex = NextIndex;

	// ���ƸմӶ����½��ķ���
	drawBlock(START_X, START_Y,BlockIndex);

	//���³��ֵķ�����ͣһ��,���û�ʶ��
	Sleep(100);	//0.1��
	//�����Ͻ�����, ������һ������
	nextBlock();

	//���齵��
	move();
}

int main(void) {
	welcome();
	initGameScene();

	//���Ϸ���ʾ��һ���·���
	nextBlock();
	Sleep(500);

	//��ʼ����������
	memset(visit, 0, sizeof(visit));

	while (1) {
		newBlock();
	}

	system("pause");
	closegraph();
	return 0;
}