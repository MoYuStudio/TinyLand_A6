
/*
   === MoYuStudio 2022 ===   
*/

#include <stdio.h>
#include <graphics.h> // EasyX 图形库
#include <conio.h> // _getch()
#include <mmsystem.h> // 多媒体设备接口

using namespace std;

int window_size[] = { 1280, 720 };
char window_title[] = "TinyLand";

int block_width = 64;
int map_size = 3;
int block_map[3][3] = {
						{0,0,0},
						{0,0,0},
						{0,0,0}
					};

void block(int x, int y)
{
	IMAGE block_img, block_alpha;
	setbkmode(TRANSPARENT);
	loadimage(&block_img, TEXT("./1.png"), block_width, block_width);
	loadimage(&block_alpha, TEXT("./1alpha.png"), block_width, block_width);

	//SetWorkingImage(&block_alpha);

	putimage(400, 465, &block_img, SRCPAINT);
	putimage(400, 465, &block_alpha, SRCAND);

	//putimage(x, y, &block_img, SRCPAINT);
};

void block_map_rander()
{
	for (int x = 0; x <= map_size; x = x+1)
		for (int y = 0; y <= map_size; y = y + 1)
		{
			// self.rect.x = self.pos['z']*(self.width/2)-self.pos['x']*(self.width/2)+self.offset[0]
			// self.rect.y = self.pos['x']*(self.width/4)+self.pos['z']*(self.width/4)+self.offset[1]+(-self.width/2)*int(self.pos['y'])
			int rect_x = y * (block_width / 2) - x * (block_width / 2)+200;
			int rect_y = x * (block_width / 4) + y * (block_width / 4)+100;
			setbkmode(TRANSPARENT);
			block(rect_x, rect_y);
		};
};

void button(int x, int y, int w, int h)
{
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(255, 0, 0));
	fillroundrect(x, y, x + w, y + h, 10, 10);

	settextstyle(15, 0, TEXT("Courier"));
	outtextxy(x+10, y+10, TEXT("button"));
}

int main()
{
	initgraph(window_size[0], window_size[1]);
	HWND window_hnd = GetHWnd();
	SetWindowText(window_hnd, window_title);
	
	setbkcolor(RGB(0,0,0));
	cleardevice();

	setbkmode(TRANSPARENT);
	settextstyle(50, 0, TEXT("Courier"));
	settextcolor(RGB(255, 255, 255));
	outtextxy(0,0,TEXT("TinyLand C Test"));

	block_map_rander();

	button(300, 300, 150, 50);

	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE))
	{
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			if (msg.x >= 50 && msg.x <= 50 + 150 && msg.y >= 50 && msg.y <= 50 + 50)
			{
				printf("click!");
			}
			break;
		default:
			break;
		}
	}

	_getch();
	closegraph();
	return 0;
}
