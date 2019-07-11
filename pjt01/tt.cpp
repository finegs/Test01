#if 1

#include<cstdio>
#include<conio.h>
#include<windows.h>
 
void draw_v_slide(int x, int y, int length, char *s);

void draw_h_slide(int x, int y, int length, char *s);

void draw_c_slide(int x, int y, int h_slide_length, int v_slide_length);

void draw_rectangle(int c, int r, int x, int y);

void draw_line(int x, int y, int h_slide_length, int v_slide_length);

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);

void gotoxy(int x, int y);

 

int main(void )
{
	char *slide="■", key=1;

    int x=1, y=1; //화면에출력될x, y의위치

    int h_slide_length=60, v_slide_length=19; //가로, 세로슬라이드길이

 

    do{

        draw_v_slide(1, y, v_slide_length, slide);

        draw_h_slide(x, v_slide_length+3, h_slide_length, slide);

        draw_c_slide(7, 1, h_slide_length, v_slide_length);

        draw_line(x,y, h_slide_length, v_slide_length);

        key=_getch();

        move_arrow_key(key, &x, &y, h_slide_length, v_slide_length);

    }while(key!=27); //ESC이전까지

    return 0;

}

 

void draw_v_slide(int x, int y, int length, char *s)

{

    int y_s=1; //y좌표시작

    gotoxy(x,y_s);

    draw_rectangle(1, length, x ,y_s);

    gotoxy(x+2, y+1);

    printf("%s", s);

    gotoxy(x, length+3);

    printf("%2d", y);

}

 

void draw_h_slide(int x, int y, int length, char *s)

{

    int real_length=length/2;

    int x_s=7; //x좌표시작

    gotoxy(x_s,y);

    draw_rectangle(real_length+1, 1, x_s, y);

    gotoxy(x_s+x+3, y+1);

    printf("%s", s);

    gotoxy(5, y+2);

    printf("%2d", x);

}

 

void draw_c_slide(int x, int y, int h_slide_length, int v_slide_length)

{

    int i, j;

    unsigned char a=0xa6, b[7]; //─│┌┐┘└
 

    h_slide_length/=2;

    for(i=1;i<7;i++)

        b[i]=0xa0+i;
 

    gotoxy(x, y);

    printf("%c%c", a, b[3]);

    for(i=x;i<h_slide_length+8;i++)

        printf("%c%c", a, b[1]);

    printf("%c%c", a, b[4]);

    printf("\n");

 

    for(i=y;i<v_slide_length+2;i++)

    {

        gotoxy(x,y+i);

        printf("%c%c", a, b[2]);

        for(j=x;j<h_slide_length+8;j++)

            printf(" ");

        printf("%c%c", a, b[2]);

        printf("\n");

    }

 

    gotoxy(x,v_slide_length+2);

    printf("%c%c", a, b[6]);

    for(i=x;i<h_slide_length+8;i++)

        printf("%c%c", a, b[1]);

    printf("%c%c", a, b[5]);

    printf("\n");

}

 

void draw_rectangle(int c, int r, int x, int y)
{

    int i, j;

    unsigned char a=0xa6, b[7]; //─│┌┐┘└
 

    for(i=1;i<7;i++)

        b[i]=0xa0+i;

 

    gotoxy(x,y);

    printf("%c%c", a, b[3]);

    for(i=0;i<c;i++)

        printf("%c%c", a, b[1]);

    printf("%c%c", a, b[4]);

    printf("\n");

 

    for(i=0;i<r;i++)

    {

        gotoxy(x,y+i+1);

        printf("%c%c", a, b[2]);

        for(j=0;j<c;j++)

            printf(" ");

        printf("%c%c", a, b[2]);

        printf("\n");

    }

 

    gotoxy(x,y+r+1);

    printf("%c%c", a, b[6]);

    for(i=0;i<c;i++)

        printf("%c%c", a, b[1]);

    printf("%c%c", a, b[5]);

    printf("\n");

}

 

void draw_line(int x, int y, int h_slide_length, int v_slide_length)
{

    int i, j;

 

    gotoxy(x+10,1);

    printf("%c%c", 0xa6, 0xa8); //┬

    gotoxy(x+10,v_slide_length+2);

    printf("%c%c", 0xa6, 0xaa); //┴

    gotoxy(7, y+1);

    printf("%c%c", 0xa6, 0xa7); //├

    gotoxy(h_slide_length+11,y+1);

    printf("%c%c", 0xa6, 0xa9); //┤

 

    for(i=2;i<v_slide_length+2;i++)

    {

        gotoxy(x+10,i);

        printf("%c%c", 0xa6, 0xa2); //│

        if(i==y+1)

        {

            gotoxy(9,i);

            for(j=0;j<h_slide_length/2+1;j++)

            {

                printf("%c%c", 0xa6, 0xa1); //─

            }

        }

    }

 

    gotoxy(x+10,y+1);

    printf("%c%c", 0xa6, 0xab); //┼

}

 

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)

{

    switch(key)

    {

    case 72:

        (*y1)--; //위쪽(상) 방향의화살표키입력

        if(*y1<1) *y1=1; //y좌표의최솟값

        break;

    case 75:

        (*x1)-=2; //왼쪽(좌) 방향의화살표키입력

        if(*x1<1) *x1=1; //x좌표의최솟값

        break;

    case 77:

        (*x1)+=2; //오른쪽(우) 방향의화살표키입력

        if(*x1>x_b-1) *x1=x_b-1; //x좌표의최댓값

        break;

    case 80:

        (*y1)++; //아래쪽(하) 방향의화살표키입력

        if(*y1>y_b) *y1=y_b; //y좌표의최댓값

        break;

    default:

        return ;

    }

}

 

void gotoxy(int x, int y)

{

    COORD Pos = { (short)x-1, (short)y-1 };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

#endif

#if 0
#include <Turboc.h>

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <windows.h>
 

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define BX 5
#define BY 1
#define BW 10
#define BH 20

#define TRUE 1
#define FALSE 0

 

void DrawScreen();
void DrawBoard();
bool ProcessKey();
void PrintBrick(bool Show);
int GetAround(int x,int y,int b,int r);
bool MoveDown();
void TestFull();

struct Point {
     int x,y;
};

Point Shape[][4][4]={
     { {0,0,1,0,2,0,-1,0}, {0,0,0,1,0,-1,0,-2}, {0,0,1,0,2,0,-1,0}, {0,0,0,1,0,-1,0,-2} },
     { {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1} },
     { {0,0,-1,0,0,-1,1,-1}, {0,0,0,1,-1,0,-1,-1}, {0,0,-1,0,0,-1,1,-1}, {0,0,0,1,-1,0,-1,-1} },
     { {0,0,-1,-1,0,-1,1,0}, {0,0,-1,0,-1,1,0,-1}, {0,0,-1,-1,0,-1,1,0}, {0,0,-1,0,-1,1,0,-1} },
     { {0,0,-1,0,1,0,-1,-1}, {0,0,0,-1,0,1,-1,1}, {0,0,-1,0,1,0,1,1}, {0,0,0,-1,0,1,1,-1} },
     { {0,0,1,0,-1,0,1,-1}, {0,0,0,1,0,-1,-1,-1}, {0,0,1,0,-1,0,-1,1}, {0,0,0,-1,0,1,1,1} },
     { {0,0,-1,0,1,0,0,1}, {0,0,0,-1,0,1,1,0}, {0,0,-1,0,1,0,0,-1}, {0,0,-1,0,0,-1,0,1} },
};

 

enum { EMPTY, BRICK, WALL };

const char *arTile[]={". ","■","□"};

int board[BW+2][BH+2];

int nx,ny;

int brick,rot;

void clrscr() {
	system("cls");
}

 
int main(int argc, char* argv[])
{

     int nFrame, nStay;
     int x,y;

     setcursortype(NOCURSOR);

	 srand(time(0));

     clrscr();

     for (x=0;x<BW+2;x++) {
          for (y=0;y<BH+2;y++) {
              board[x][y] = (y==0 || y==BH+1 || x==0 || x==BW+1) ? WALL:EMPTY;
          }
     }

     DrawScreen();

     nFrame=20;
 

     for (;1;) {

          brick=rand()%sizeof(Shape)/sizeof(Shape[0]);

          nx=BW/2;

          ny=3;

          rot=0;

          PrintBrick(TRUE);

          if (GetAround(nx,ny,brick,rot) != EMPTY) break;

          nStay=nFrame;

          for (;2;) {

              if (--nStay == 0) {

                   nStay=nFrame;

                   if (MoveDown()) break;

              }

              if (ProcessKey()) break;

              delay(1000/20);

          }

     }

     clrscr();

     gotoxy(30,12);puts("G A M E  O V E R");

     setcursortype(NORMALCURSOR);

}

 

void DrawScreen()



     int x,y;

 

     for (x=0;x<BW+2;x++) {

          for (y=0;y<BH+2;y++) {

              gotoxy(BX+x*2,BY+y);

              puts(arTile[board[x][y]]);

          }

     }

 

     gotoxy(50,3);puts("Tetris Ver 1.0");

     gotoxy(50,5);puts("좌우:이동, 위:회전, 아래:내림");

     gotoxy(50,6);puts("공백:전부 내림");

}

 

void DrawBoard()

{

     int x,y;

 

     for (x=1;x<BW+1;x++) {

          for (y=1;y<BH+1;y++) {

              gotoxy(BX+x*2,BY+y);

              puts(arTile[board[x][y]]);

          }
     }
}

 

bool ProcessKey()
{
     int ch,trot;
 

     if (kbhit()) {

          ch=getch();

          if (ch == 0xE0 || ch == 0) {

              ch=getch();

              switch (ch) {

              case LEFT:

                   if (GetAround(nx-1,ny,brick,rot) == EMPTY) {

                        PrintBrick(FALSE);

                        nx--;

                        PrintBrick(TRUE);

                   }

                   break;

              case RIGHT:
                   if (GetAround(nx+1,ny,brick,rot) == EMPTY) {

                        PrintBrick(FALSE);

                        nx++;

                        PrintBrick(TRUE);

                   }

                   break;

              case UP:

                   trot=(rot == 3 ? 0:rot+1);

                   if (GetAround(nx,ny,brick,trot) == EMPTY) {

                        PrintBrick(FALSE);

                        rot=trot;

                        PrintBrick(TRUE);

                   }

                   break;

              case DOWN:

                   if (MoveDown()) {
                        return TRUE;
                   }
                   break;
              }
          } else {
              switch (ch) {

              case ' ':

                   while(MoveDown()==FALSE) {;}

                   return TRUE;
              }
          }
     }
     return FALSE;
}

void gotoxy(int x, int y) {
	COORD Pos = {(short)x-1, (short)y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
 

void PrintBrick(bool Show)
{
     int i;
     for (i=0;i<4;i++) {
          gotoxy(BX+(Shape[brick][rot][i].x+nx)*2,BY+Shape[brick][rot][i].y+ny);
          puts(arTile[Show ? BRICK:EMPTY]);
     }
}

 

int GetAround(int x,int y,int b,int r)
{
     int i,k=EMPTY;

     for (i=0;i<4;i++) {

          k=max(k,board[x+Shape[b][r][i].x][y+Shape[b][r][i].y]);

     }

     return k;

}

 

bool MoveDown()
{
     if (GetAround(nx,ny+1,brick,rot) != EMPTY) {
          TestFull();
          return TRUE;
     }

     PrintBrick(FALSE);

     ny++;

     PrintBrick(TRUE);

     return FALSE;

}
 

void TestFull()
{
     int i,x,y,ty;

     for (i=0;i<4;i++) {
          board[nx+Shape[brick][rot][i].x][ny+Shape[brick][rot][i].y]=BRICK;
     }


     for (y=1;y<BH+1;y++) {
          for (x=1;x<BW+1;x++) {
              if (board[x][y] != BRICK) break;
          }

          if (x == BW+1) {
              for (ty=y;ty>1;ty--) {
                   for (x=1;x<BW+1;x++) {
                        board[x][ty]=board[x][ty-1];
                   }
              }
              DrawBoard();
              delay(200);
          }
     }
}

#endif

