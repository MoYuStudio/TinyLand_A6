
/*
   === MoYuStudio 2022 ===   
*/

#include <stdio.h>
#include <graphics.h> // EasyX 图形
#include <conio.h> // _getch()
#include <mmsystem.h> // 多媒体设备接口

double window_size[] = { 1280, 720 };
char window_title[] = "TinyLand";

void block()
{
	IMAGE block_img(128, 128);
}

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

	IMAGE img;
	setbkmode(TRANSPARENT);
	loadimage(&img, TEXT("./1.png"),128,128);
	putimage(0, 0, &img, SRCCOPY);

	button(250, 250, 150, 50);

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