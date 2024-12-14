# include "iGraphics.h"
# include "gl.h"
#include<windows.h>
#include<stdlib.h>
#pragma comment(lib, "Winmm.lib")

bool music=true;

int busket_x,busket_y;
int dx, dy;
int pic_x,pic_y,hen_x,hen_y=500,hen_x1,hen_y1=400;
int eg=0,egg_x,egg_y=500,eg1=0,egg_x1,egg_y1=400;
int s=0;
char scr[1];
int l=3;
char liv[1];
char tim[1],tim1[1];
int i=10,j=2,k=59;
int gold=0,blue=0;
int game=1;


void egg();
void score();
void live();
void t();

void score()
{

    sprintf(scr,"Score:%d",s);
    iText(25,650,scr);

}
void live()
{
    sprintf(liv,"Live:%d",l);
    iText(700,650,liv);
    if(l==0)
        exit(0);
}
void t()
{



    sprintf(tim,"Time:%02d",j);
    iText(200,650,tim);
    sprintf(tim1,":%02d",k);
    iText(255,650,tim1);
    Sleep(100);
    i--;
    if(i==0)
    {
        k--;
        i=10;
    }
    if(k==-1)
    {
        k=59;
        j--;
    }
    if(j==0&&k==0)
        exit(0);

}

void iDraw()
{
    //place your drawing codes here

    if(game==1){

    iClear();
    iShowBMP(0,0,"farm back1 bmp.bmp");


    iSetColor(255, 100, 255);
    iLine(0,500,800,500);

    iSetColor(255, 255, 100);
    iLine(0,400,800,400);

    if(eg==0 || eg==1 || eg==2)
    {
        iSetColor(255,255,255);
        iFilledEllipse(egg_x,egg_y,12,20);
    }
    else if(eg==3 || eg==4)
    {
        iSetColor(0,0,255);
        iFilledEllipse(egg_x,egg_y,12,20);
    }
    else if (eg==5)
    {
        iSetColor(220,210,0);
        iFilledEllipse(egg_x,egg_y,12,20);
    }
    else if(eg==6 || eg==7)
    {
        iSetColor(0,200,40);
        iFilledCircle(egg_x,egg_y,8);
    }
    //cicken2
     if(eg1==0 || eg1==1 || eg1==2)
    {
        iSetColor(255,255,255);
        iFilledEllipse(egg_x1,egg_y1,12,20);
    }
    else if(eg1==3 || eg1==4)
    {
        iSetColor(0,0,255);
        iFilledEllipse(egg_x1,egg_y1,12,20);
    }
    else if (eg1==5)
    {
        iSetColor(220,210,0);
        iFilledEllipse(egg_x1,egg_y1,12,20);
    }
    else if(eg1==6 || eg1==7)
    {
        iSetColor(0,200,40);
        iFilledCircle(egg_x1,egg_y1,8);
    }



    iShowBMP(pic_x,pic_y,"basket.bmp");
    iShowBMP(hen_x,hen_y,"chicken.bmp");
iShowBMP(hen_x1,hen_y1,"chicken2.bmp");




    iSetColor(0,0,0);
    score();
    live();
    t();

    }
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

    pic_x=mx-25;

    if(pic_x<0)
        pic_x=0;
    if(pic_x>640)
        pic_x=640;

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'p')
    {
        iPauseTimer(0);
    }
    if(key == 'r')
    {
        iResumeTimer(0);
    }
    if(key=='q')
        exit(0);

}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_RIGHT)
    {
        if(pic_x<640)
            pic_x=pic_x+10;
        if(pic_x>=640)
            pic_x=640;

    }
    if(key == GLUT_KEY_LEFT)
    {
        if(pic_x>0)
            pic_x=pic_x-10;
        if(pic_x<0)
            pic_x=0;
    }
}
void egg()
{
    int a=1,b=1;

    if(egg_y>0 && egg_y<600)
    {
        egg_y-=15;
        if(rand()%2)
            egg_x+=4;
        else
            egg_x-=4;

    }

    if(eg==0 || eg==1 || eg==2)
        a=1;
    else if(eg==3 || eg==4)
        a=5;
    else if(eg==5)
        a=10;
    else if(eg==6 || eg==7)
        a=-10;

    if (egg_y<=0)
    {
        egg_y=500;
        egg_x=rand()%700;
        if(egg_x<100)
            egg_x=egg_x+225;
        hen_x=egg_x-80;
        l--;
        if(eg==6 || eg==7)
            l++;
        eg=rand()%8;

    }




    if(egg_x>=pic_x-5 && egg_x<=pic_x+160 &&egg_y<=pic_y+60)
    {
        s+=a;
        egg_y=500;
        egg_x=rand()%700;
        if(egg_x<100)
            egg_x=egg_x+225;
        hen_x=egg_x-80;
        eg=rand()%8;
    }

    //chicken2
     if(egg_y1>0 && egg_y1<600)
    {
        egg_y1-=15;
        if(rand()%2)
            egg_x1+=4;
        else
            egg_x1-=4;

    }

    if(eg1==0 || eg1==1 || eg1==2)
        b=1;
    else if(eg1==3 || eg1==4)
        b=5;
    else if(eg1==5)
        b=10;
    else if(eg1==6 || eg1==7)
        b=-10;

    if (egg_y1<=0)
    {
        egg_y1=400;
        egg_x1=rand()%700;
        if(egg_x1<100)
            egg_x1=egg_x1+225;
        hen_x1=egg_x1-80;
        l--;
        if(eg1==6 || eg1==7)
            l++;
        eg1=rand()%8;

    }




    if(egg_x1>=pic_x-5 && egg_x1<=pic_x+160 &&egg_y1<=pic_y+60)
    {
        s+=b;
        egg_y1=400;
        egg_x1=rand()%700;
        if(egg_x1<100)
            egg_x1=egg_x1+225;
        hen_x1=egg_x1-80;
        eg1=rand()%8;
    }




}



int main()
{

//     PlaySound("Music\\sound.wav",NULL,SND_FILENAME|SND_ASYNC);





    pic_x=345;
    pic_y=10;


    egg_x=rand()%345;
    if(egg_x<100)
        egg_x=egg_x+225;
    hen_x=egg_x-80;
    iSetTimer(25,egg);




    iInitialize(800, 700, "1905108 Catch The Egg");

    return 0;
}

