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
int minX = 30;
int minY = 30;

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
int markColor[30][15];	//��ʾ��Ӧλ�õ���ɫ

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

// ���ָ��λ��ָ������ķ���
// ����x: ��������Ͻǵ�x����
// ����y: ��������Ͻ�����Ϸ�����ڵ�����, ������Ϸ���򶥲��ľ���
void clearBlock(int x, int y, block_dir_t dir) {
	setcolor(BLACK);
	int id = BlockIndex * 4 + dir;
	y += START_Y;

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[id][i][j]) {
				//�����÷���ĵ�i�еĵ�J��
				outtextxy(x + j * UNIT_SIZE, y + i * UNIT_SIZE, _T("��"));
			}
		}
	}
}

// �����Ͻ�������, ������һ������
void drawBlock(int x, int y) {
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

// ���Ʒ���: ��ָ��λ�û���ָ�������ָ������
void drawBlock(int x, int y, int blockIndex,block_dir_t dir) {
	settextcolor(color[BlockIndex]);
	settextstyle(23, 0, _T("����"));

	int id = blockIndex * 4 + dir;

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[id][i][j]) {
				//"��"
				outtextxy(x + j * UNIT_SIZE, y + i * UNIT_SIZE, _T("��"));
			}
		}
	}
}

void nextBlock(void) {
	int x = 391;
	int y = 71;

	clearBlock(x, y);			// ���Ҳ����ʾ�����ԭ���ķ���

	// ���ѡ��һ�ַ���
	srand(time(NULL));		//ʹ��ʱ�亯���ķ���ֵ, ����Ϊ�������
	NextIndex = rand() % BLOCK_COUNT;

	drawBlock(x, y);

}

// �����ָ��λ�ÿ�����ָ�������ƶ�, �ͷ���1,����ͷ���0
int moveAble(int x0, int y0, move_dir_t moveDir, block_dir_t blockDir) {
	// ���㵱ǰ��������Ͻ���30*15����Ϸ���е�λ��(�ڶ�����, �ڶ�����)
	int x = (y0 - minY) / UNIT_SIZE;
	int y = (x0 - minX) / UNIT_SIZE;
	int id = BlockIndex * 4 + blockDir;
	int ret = 1;

	if (moveDir == MOVE_DOWN) {
		for (int i = 0; i < BLOCK_HEIGHT; i++) {
			for (int j = 0; j < BLOCK_WIDTH; j++) {
				if (block[id][i][j] && ((x + i + 1) >= 30 || visit[x + i + 1][y + j])) {	//(x + i >= 0 && x + i < 30 && y + j >= 0 && y + j < 15 && 
					ret = 0;
				}
			}
		}
	}
	else if (moveDir == MOVE_LEFT) {
		for (int i = 0; i < BLOCK_HEIGHT; i++) {
			for (int j = 0; j < BLOCK_WIDTH; j++) {
				if (block[id][i][j] && ((y + j) == 0 || visit[x + i][y + j - 1])) {
					ret = 0;
				}
			}
		}
	}
	else if (moveDir == MOVE_RIGHT) {
		for (int i = 0; i < BLOCK_HEIGHT; i++) {
			for (int j = 0; j < BLOCK_WIDTH; j++) {
				if (block[id][i][j] && ((y + j + 1) >= 15 || visit[x + i][y + j + 1])) {
					ret = 0;
				}
			}
		}
	}

	return ret;
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

void wait(int interval) {		//500
	int count = interval / 10;
	for (int i = 0; i < count; i++) {
		Sleep(10);
		if (_kbhit()) {
			return;
		}
	}
}

// �жϵ�ǰ�����Ƿ����ת��ָ������
// ע��, ��ʱ��û��ת���÷���! ! !
int rotatable(int x, int y, block_dir_t dir) {
	int id = BlockIndex * 4 + dir;
	int xIndex = (y - minY) / UNIT_SIZE;
	int yIndex = (x - minX) / UNIT_SIZE;

	if (!moveAble(x, y, MOVE_DOWN, dir)) {
		return 0;
	}

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[id][i][j] && (yIndex + j < 0 || yIndex + j >= 15 || visit[xIndex + i][yIndex + j])) {
				return 0;
			}
		}
	}

	return 1;
}

void mark(int x, int y, int blocklndex, block_dir_t dir) {
	int id = blocklndex * 4 + dir;
	int x2 = (y - minY) / UNIT_SIZE;
	int y2 = (x - minX) / UNIT_SIZE;
	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[id][i][j]) {
				visit[x2 + i][y2 + j] = 1;
				markColor[x2 + i][y2 + j] = color[blocklndex];
			}
		}
	}
}

void move(void) {
	int x = START_X;
	int y = START_Y;
	int k = 0;
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
		
		//�����ǰ����
		clearBlock(x, k, blockDir);
		
		if (_kbhit()) {
			int key = _getch();

			if (key == KEY_UP) {
				block_dir_t nextDir = (block_dir_t)((blockDir + 1) % 4);
				if (rotatable(x, y + k, nextDir)) {
					blockDir = nextDir;
				}
			}
			else if (key == KEY_DOWN) {
				curSpeed = 50;
			}
			else if (key == KEY_LEFT) {
				if (moveAble(x, y + k + 20, MOVE_LEFT, blockDir)) {
					x -= UNIT_SIZE;
				}
			}
			else if (key == KEY_RIGHT) {
				if (moveAble(x, y + k + 20, MOVE_RIGHT, blockDir)) {
					x += UNIT_SIZE;		//x = x + 20;
				}
			}
		}

		k += 20;
		// ���Ƶ�ǰ����
		drawBlock(x, y + k, BlockIndex, blockDir);

		wait(curSpeed);
			
		// ����� "�̻�" ����
		if (!moveAble(x, y + k, MOVE_DOWN, blockDir)) {
			mark(x, y+k, BlockIndex, blockDir);
			break;
		}
	}
}

void newBlock() {
	// ȷ������ʹ�õķ�������
	BlockIndex = NextIndex;

	// ���ƸմӶ����½��ķ���
	drawBlock(START_X, START_Y);

	//���³��ֵķ�����ͣһ��,���û�ʶ��
	Sleep(100);	//0.1��
	//�����Ͻ�����, ������һ������
	nextBlock();

	//���齵��
	move();
}

//������x��, ����������ж�����
void down(int x) {
	for (int i = x; i >= 0; i--) {
		// ������i��, ��j�еķ�������
		for (int j = 0; j < 15; j++) {
			if (visit[i - 1][j]) {
				visit[i][j] = 1;
				markColor[i][j] = markColor[i - 1][j];
				setcolor(markColor[i][j]);
				outtextxy(minX + j * UNIT_SIZE, minY + i * UNIT_SIZE, _T("��"));
			}
			else {
				visit[i][j] = 0;
				setcolor(BLACK);
				outtextxy(minX + j * UNIT_SIZE, minY + i * UNIT_SIZE, _T("��"));
			}
		}
	}

	//�����ϵ�һ��(���Ǻ���Ϊ0����һ��)
	setcolor(BLACK);
	for (int j = 0; j < 15; j++) {
		visit[0][j] = 0;
		outtextxy(minX + j * UNIT_SIZE, minY, _T("��"));
	}
}

void check(void) {
	int i, j;

	for (i = 29; i >= 0; i--) {
		// ����i����û����
		for (j = 0; j < 15 && visit[i][j]; j++);
			// ִ�е��˴�ʱ, ���������:
			// 1. ��i��û����, ����ʾ�п�λ ��ʱj<15
			// 2. ��i���Ѿ�����, j>=15
		if (j >= 15) {
			// ��ʱ, ��i���Ѿ�����, ����Ҫ������i��
			down(i);	//������i��, ����������ж�����
			i++;	//��Ϊ������ѭ������i--, ����������i++,ʹ���´�ѭ��ʱ,�ٰ���һ�м��һ��
		}
	}
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

		// ��������, �����·������ٶ�
		check();
	}

	system("pause");
	closegraph();
	return 0;
}