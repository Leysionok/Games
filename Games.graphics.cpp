#include <graphics.h>
#include <conio.h>
      #include <dos.h>
      #include <alloc.h>
void main()
{int x;
int d = DETECT, m;
initgraph (&d,&m,"C:\\BORLANDC\\BGI");
 int driver=DETECT,mode,size,i;
	   void *buf;
	   initgraph(&driver,&mode,"");

setfillstyle (SOLID_FILL,GREEN);
bar(0,300,700,500);
settextstyle(GOTHIC_FONT,HORIZ_DIR,7);
outtextxy ( 550, 40, "X2" );
setfillstyle (SOLID_FILL, RED);
bar(100,20,200,40);
bar(80,40,260,60);
bar(76,181,200,300);
bar(60,200,240,220);
bar(40,220,260,240);
bar(200,240,220,260);
bar(500,30,510,25);
	  bar(520,30,530,25);
	  bar(490,30,540,45);
	  bar(495,45,535,50);
	  bar(502,50,530,55);
	  bar(508,55,524,60);
	  bar(515,60,520,65);
setfillstyle (SOLID_FILL,BROWN);
bar(80,60,140,80);
bar(100,80,140,140);
bar(60,80,100,160);
setfillstyle (SOLID_FILL,YELLOW);
bar(140,60,180,140);
bar(80,80,100,120);
bar(100,140,180,180);
bar(140,100,120,120);
bar(180,100,200,140);
bar(201,60,220,120);
bar(221,100,260,140);
bar(260,120,280,140);
bar(180,160,240,180);
setfillstyle(SOLID_FILL,DARKGRAY);
bar(180,60,200,100);
bar(180,140,260,160);
bar(200,120,220,140);
setfillstyle(SOLID_FILL,BLUE);
bar(115,181,133,240);
bar(160,200,178,240);
bar(133,220,178,240);
bar(95,240,200,300);
bar(75,280,133,320);
bar(160,280,220,320);
setfillstyle(SOLID_FILL,YELLOW);
bar(40,240,75,300);
bar(75,260,94,280);
bar(221,240,260,300);
bar(200,260,220,280);
setfillstyle (SOLID_FILL,BROWN);
bar(55,321,115,360);
bar(35,340,55,360);
bar(180,321,240,360);
bar(240,340,260,360);
setcolor ( MAGENTA );
circle ( 320, 240, 0);
setfillstyle(SOLID_FILL, YELLOW);
floodfill ( 320, 240, MAGENTA );
setcolor (GREEN );
setbkcolor (BLACK);
	  setcolor(BLACK);
	  setfillstyle(1,YELLOW);
	  fillellipse(700,220,20,20);
	  buf=malloc(size);
	  getimage(680,200,720,240,buf);
	  for(i=1;i<=440;i++)
	  {
	      setfillstyle(1,YELLOW);
	  fillellipse(721-i,240,20,20);
	    delay(4);
	  }
	   for(i=1;i<=15;i++)
	  {
	      setfillstyle(1,RED);
	  fillellipse(281,240,20+i,20+i);
	    delay(4);
	  }
	  setfillstyle(1,BLACK);
	  bar(540,35,560,45);
	  setcolor(WHITE);
	  outtextxy ( 550, 40, "X1" );
	   setfillstyle(1,BLACK);
	  bar(262,200,320,280);
	  bar(240,180,280,220);
	  setfillstyle(1,RED);
	  bar(240,220,260,239);
	  setfillstyle(1,YELLOW);
	  bar(240,240,260,270);
	  setfillstyle(1,102		);
	  bar(500,120,540,130);
	  bar(490,130,550,140);
	  bar(480,140,560,150);
	  bar(470,150,570,160);
	  bar(460,160,580,170);
	  bar(450,170,590,190);
	  bar(440,190,600,220);
	  bar(450,220,590,230);
	  setfillstyle(1,YELLOW);
	  bar(480,170,490,210);
	  bar(480,200,510,210);
	  bar(500,190,510,210);
	  bar(530,190,540,210);
	  bar(530,200,560,210);
	  bar(550,170,560,210);
	  bar(490,220,550,270);
	  bar(480,230,490,270);
	  bar(550,230,560,270);
	  setfillstyle(1,DARKGRAY);
	  bar(470,160,490,170);
	  bar(490,170,500,200);
	  bar(490,180,540,190);
	  bar(540,170,550,200);
	  bar(550,160,570,170);
	  bar(460,240,480,250);
	  bar(450,250,500,270);
	  bar(460,260,510,280);
	  bar(530,260,580,280);
	  bar(540,250,590,270);
	  bar(560,240,580,250);
	  size=imagesize(440,120,600,280);
	  buf=malloc(size);
	  getimage(440,120,600,280,buf);
	  setfillstyle(1,BLACK);
	  bar(440,120,600,280);
	   for(i=1;i<=240;i++)
	  {
	       putimage(500-i,140,buf,COPY_PUT);
	       bar(650-i,120,650,280);
	  }
	  free(buf);
	   setfillstyle(1,BLACK);
	  bar(540,35,570,45);
	  setcolor(WHITE);
	  outtextxy ( 550, 40, "X0" );
	  setfillstyle(1,BLACK);
	  bar(0,0,650,600);
	  setcolor(WHITE);
	  outtextxy(300,250,"GAME OVER"); getch();}
