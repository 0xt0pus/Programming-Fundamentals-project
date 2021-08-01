//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<fstream>



#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

int xo=335;
int yo=39;
int xp=475;
int yp=755;
int a400=400;
int xoo=473;
int yoo=756;
int flag=2;
int level=1;
int temp_score;
//variables for drawline function or food 


int x[8]={58,58,58,58,58,58,58,58};
int y[8]={63,153,243,333,513,603,693,783};

int xt[8]={157,157,157,157,157,157,157,157};
int yt[8]={63,163,253,343,513,603,683,783};

int hh[8]={250,250,257,257,257,257,257,257};
int hy[8]={63,163,263,343,503,583,683,783};

int xx[8]={332,332,332,350,350,337,337,337};
int yy[8]={63,163,263,365,480,583,683,783}; 

int aa[8]={510,510,510,475,475,475,475,475};
int bb[8]={63,163,263,370,480,583,683,783};	

int x6[8]={590,590,570,570,570,570,570,570};
int y6[8]={63,163,263,343,503,583,683,783};

int x7[8]={670,670,670,670,670,670,670,670};
int y7[8]={63,163,253,343,513,603,683,783};

int x8[8]={765,765,765,765,765,765,765,765};
int y8[8]={63,153,243,333,513,603,693,783};

	

int xq[8]={58,58,58,58,58,58,58,58};
int yq[8]={63,153,243,333,513,603,693,783};

int xtq[8]={157,157,157,157,157,157,157,157};
int ytq[8]={63,163,253,343,513,603,683,783};

int hhq[8]={250,250,257,257,257,257,257,257};
int hyq[8]={63,163,263,343,503,583,683,783};

int xxq[8]={332,332,332,350,350,337,337,337};
int yyq[8]={63,163,263,365,480,583,683,783}; 

int aaq[8]={510,510,510,475,475,475,475,475};
int bbq[8]={63,163,263,370,480,583,683,783};	

int x6q[8]={590,590,570,570,570,570,570,570};
int y6q[8]={63,163,263,343,503,583,683,783};

int x7q[8]={670,670,670,670,670,670,670,670};
int y7q[8]={63,163,253,343,513,603,683,783};

int x8q[8]={765,765,765,765,765,765,765,765};
int y8q[8]={63,153,243,333,513,603,693,783};




int xqa[8]={58,58,58,58,58,58,58,58};
int yqa[8]={63,153,243,333,513,603,693,783};

int xtqa[8]={157,157,157,157,157,157,157,157};
int ytqa[8]={63,163,253,343,513,603,683,783};

int hhqa[8]={250,250,257,257,257,257,257,257};
int hyqa[8]={63,163,263,343,503,583,683,783};

int xxqa[8]={332,332,332,350,350,337,337,337};
int yyqa[8]={63,163,263,365,480,583,683,783}; 

int aaqa[8]={510,510,510,475,475,475,475,475};
int bbqa[8]={63,163,263,370,480,583,683,783};	

int x6qa[8]={590,590,570,570,570,570,570,570};
int y6qa[8]={63,163,263,343,503,583,683,783};

int x7qa[8]={670,670,670,670,670,670,670,670};
int y7qa[8]={63,163,253,343,513,603,683,783};

int x8qa[8]={765,765,765,765,765,765,765,765};
int y8qa[8]={63,153,243,333,513,603,693,783};


int xqaa[8]={58,58,58,58,58,58,58,58};
int yqaa[8]={63,153,243,333,513,603,693,783};

int xtqaa[8]={157,157,157,157,157,157,157,157};
int ytqaa[8]={63,163,253,343,513,603,683,783};

int hhqaa[8]={250,250,257,257,257,257,257,257};
int hyqaa[8]={63,163,263,343,503,583,683,783};

int xxqaa[8]={332,332,332,350,350,337,337,337};
int yyqaa[8]={63,163,263,365,480,583,683,783}; 

int aaqaa[8]={510,510,510,475,475,475,475,475};
int bbqaa[8]={63,163,263,370,480,583,683,783};	

int x6qaa[8]={590,590,570,570,570,570,570,570};
int y6qaa[8]={63,163,263,343,503,583,683,783};

int x7qaa[8]={670,670,670,670,670,670,670,670};
int y7qaa[8]={63,163,253,343,513,603,683,783};

int x8qaa[8]={765,765,765,765,765,765,765,765};
int y8qaa[8]={63,153,243,333,513,603,693,783};
	
int score=0;
int lives=3;
int highscore=0;




int array2[10];







// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}




string int_to_string(int num)
{

		string res="";
		int sign=(num<0)?-1:1;
		num=abs(num);

		while(num>0)
		{
			res+=char(num%10+48);
			num/=10;
		}
		if(sign<0) res+='-';
		for(int i=0;i<res.length()/2;i++)
		{
			swap(res[i],res[res.length()-i-1]);
		}
		return res;
}

/*
 * Main Canvas drawing function.
 * */
//Board *b;


void GameDisplay()/**/
{
	if (flag==0)
{

	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
   
	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display score;
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	DrawString( 20, 834, "score", colors[MISTY_ROSE]);
	DrawString( 100 , 834, int_to_string(score), colors[MISTY_ROSE]);
	DrawString( 670, 834, "Lives", colors[MISTY_ROSE]);
	DrawString( 750 , 834, int_to_string(lives), colors[MISTY_ROSE]);
	DrawString( 450 , 834, int_to_string(level), colors[MISTY_ROSE]);
	DrawString( 400, 834, "level", colors[MISTY_ROSE]);
	DrawString( 165, 834, "H.S =", colors[MISTY_ROSE]);
	DrawString( 230 , 834, int_to_string(highscore), colors[MISTY_ROSE]);
	
	if(lives==0)
	{

	DrawString( 330, 470, "Game over", colors[MISTY_ROSE]);
	DrawString( 330, 420, "You have zero lives remaining", colors[MISTY_ROSE]);
	DrawString( 330, 370, "Try again :)", colors[MISTY_ROSE]);
	DrawString( 330, 300, "Tap on 4 to Continue", colors[MISTY_ROSE]);

	xo=xo*76543;
	yo=yo*6543;
	yo=yo*765;
	yp=yp*43245;
	yoo=yoo*17675;
	a400=a400*654;
	xx[3]=xx[3]*656;
	xx[4]=xx[4]*676;
	aa[3]=aa[3]*456;
	aa[4]=aa[4]*676;

	}













int array[10]={128,106,104,103,78,30,24,23,20,16};

ofstream outputfile;
outputfile.open("highscores.txt");

if(highscore>array[0])
{
	array[0]=highscore;
	
}
else if(highscore>array[1])
{
	array[1]=highscore;
	
}
else if(highscore>array[2])
{
	array[2]=highscore;

}
else if(highscore>array[3])
{
	array[3]=highscore;

}
else if(highscore>array[4])
{
	array[4]=highscore;
	}

else if(highscore>array[5])
{
	array[5]=highscore;

}
else if(highscore>array[6])
{
	array[6]=highscore;

}

else if(highscore>array[7])
{
	array[7]=highscore;

}
else if(highscore>array[8])
{
	array[8]=highscore;

}
else if(highscore>array[9])
{
	array[9]=highscore;

}

	outputfile<<array[0]<<endl;
	outputfile<<array[1]<<endl;
	outputfile<<array[2]<<endl;
	outputfile<<array[3]<<endl;
	outputfile<<array[4]<<endl;
	outputfile<<array[5]<<endl;
	outputfile<<array[6]<<endl;
	outputfile<<array[7]<<endl;
	outputfile<<array[8]<<endl;
	outputfile<<array[9]<<endl;

outputfile.close();


ifstream inputfile;
inputfile.open("highscores.txt");
inputfile>>array2[0];
inputfile>>array2[1];
inputfile>>array2[2];
inputfile>>array2[3];
inputfile>>array2[4];
inputfile>>array2[5];
inputfile>>array2[6];
inputfile>>array2[7];
inputfile>>array2[8];
inputfile>>array2[9];
inputfile.close();

	DrawSquare( a400, a400 ,35,colors[BROWN]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	

if(level==1)
{	
DrawCircle(x[0],y[0],10,colors[RED]);//first colomn extreme left  y0;
	if(xp-x[0]<20 && xp-x[0]>-20 && yp-y[0]<20 && yp-y[0]>-20)
	{
		x[0]=x[0]*1000;
		score++;
	}
DrawCircle(x[1],y[1],10,colors[RED]);//first colomn extreme left y1;
	if(xp-x[1]<30 && xp-x[1]>-30 && yp-y[1]<30 && yp-y[1]>-30)
	{
		x[1]=x[1]*1000;
		score++;
	}
DrawCircle(x[2],y[2],10,colors[RED]);//first colomn extreme left  y2;
	if(xp-x[2]<30 && xp-x[2]>-30 && yp-y[2]<30 && yp-y[2]>-30)
	{
		x[2]=x[2]*1000;
		score++;
	}
DrawCircle(x[3],y[3],10,colors[RED]);//first colomn extreme left y3;
	if(xp-x[3]<30 && xp-x[3]>-30 && yp-y[3]<30 && yp-y[3]>-30)
	{
		x[3]=x[3]*1000;
		score++;
	}
	
DrawCircle(x[4],y[4],10,colors[RED]);//first colomn extreme left y4;
	if(xp-x[4]<30 && xp-x[4]>-30 && yp-y[4]<30 && yp-y[4]>-30)
	{
		x[4]=x[4]*1000;
		score++;
	}	
DrawCircle(x[5],y[5],10,colors[RED]);//first colomn extreme left y5;
	if(xp-x[5]<30 && xp-x[5]>-30 && yp-y[5]<30 && yp-y[5]>-30)
	{
		x[5]=x[5]*1000;
		score++;
	}
DrawCircle(x[6],y[6],10,colors[RED]);//first colomn extreme left y6;
	if(xp-x[6]<30 && xp-x[6]>-30 && yp-y[6]<30 && yp-y[6]>-30)
	{
		x[6]=x[6]*1000;
		score++;
	}	
	
DrawCircle(x[7],y[7],10,colors[RED]);//first colomn extreme left y7;
	if(xp-x[7]<40 && xp-x[7]>-40 && yp-y[7]<40 && yp-y[7]>-40)
	{
		x[7]=x[7]*1000;
		score++;
	}	

//now let us draw the second left bubbles
DrawCircle(xt[0],yt[0],10,colors[RED]);//second colomn extreme left y10;
	if(xp-xt[0]<10 && xp-xt[0]>-10 && yp-yt[0]<30 && yp-yt[0]>-30)
	{
		xt[0]=xt[0]*1000;
		score++;
	}

DrawCircle(xt[1],yt[1],10,colors[RED]);//second colomn extreme left y11;
	if(xp-xt[1]<30 && xp-xt[1]>-30 && yp-yt[1]<30 && yp-yt[1]>-30)
	{
		xt[1]=xt[1]*1000;
		score++;
	}

DrawCircle(xt[2],yt[2],10,colors[RED]);//second colomn extreme leftt y12;
	if(xp-xt[2]<30 && xp-xt[2]>-30 && yp-yt[2]<30 && yp-yt[2]>-30)
	{
		xt[2]=xt[2]*1000;
		score++;
	}

DrawCircle(xt[3],yt[3],10,colors[RED]);//second colomn extreme left y13;
	if(xp-xt[3]<30 && xp-xt[3]>-30 && yp-yt[3]<30 && yp-yt[3]>-30)
	{
		xt[3]=xt[3]*1000;
		score++;
	}

DrawCircle(xt[4],yt[4],10,colors[RED]);//second colomn extreme left y14;
	if(xp-xt[4]<30 && xp-xt[4]>-30 && yp-yt[4]<30 && yp-yt[4]>-30)
	{
		xt[4]=xt[4]*1000;
		score++;
	}

DrawCircle(xt[5],yt[5],10,colors[RED]);//second colomn extreme left y15;
	if(xp-xt[5]<30 && xp-xt[5]>-30 && yp-yt[5]<30 && yp-yt[5]>-30)
	{
		xt[5]=xt[5]*1000;
		score++;
	}
	
DrawCircle(xt[6],yt[6],10,colors[RED]);//second colomn extreme left y16;
	if(xp-xt[6]<50 && xp-xt[6]>-50 && yp-yt[6]<50 && yp-yt[6]>-40)
	{
		xt[6]=xt[6]*1000;
		score++;
	}
	
DrawCircle(xt[7],yt[7],10,colors[RED]);//second colomn extreme left y17;
	if(xp-xt[7]<40 && xp-xt[7]>-40 && yp-yt[7]<40 && yp-yt[7]>-40)
	{
		xt[7]=xt[7]*1000;
		score++;
	}
	

//Third row from left side

DrawCircle(hh[0],hy[0],10,colors[RED]);//third colomn extreme left y20;
	if(xp-hh[0]<10 && xp-hh[0]>-10 && yp-hy[0]<30 && yp-hy[0]>-30)
	{
		hh[0]=hh[0]*1000;
		score++;
	}

DrawCircle(hh[1],hy[1],10,colors[RED]);//third colomn extreme left y21;
	if(xp-hh[1]<10 && xp-hh[1]>-10 && yp-hy[1]<30 && yp-hy[1]>-30)
	{
		hh[1]=hh[1]*1000;
		score++;
	}

DrawCircle(hh[2],hy[2],10,colors[RED]);//third colomn extreme left y22;
	if(xp-hh[2]<30 && xp-hh[2]>-30 && yp-hy[2]<30 && yp-hy[2]>-30)
	{
		hh[2]=hh[2]*1000;
		score++;
	}	

DrawCircle(hh[3],hy[3],10,colors[RED]);//third colomn extreme left y23;
	if(xp-hh[3]<30 && xp-hh[3]>-30 && yp-hy[3]<30 && yp-hy[3]>-30)
	{
		hh[3]=hh[3]*1000;
		score++;
	}	

DrawCircle(hh[4],hy[4],10,colors[RED]);//third colomn extreme left y24;
	if(xp-hh[4]<30 && xp-hh[4]>-30 && yp-hy[4]<30 && yp-hy[4]>-30)
	{
		hh[4]=hh[4]*1000;
		score++;
	}

DrawCircle(hh[5],hy[5],10,colors[RED]);//third colomn extreme left y25;
	if(xp-hh[5]<40 && xp-hh[5]>-40 && yp-hy[5]<40 && yp-hy[5]>-40)
	{
		hh[5]=hh[5]*1000;
		score++;
	}

DrawCircle(hh[6],hy[6],10,colors[RED]);//third colomn extreme left y26;
	if(xp-hh[6]<50 && xp-hh[6]>-50 && yp-hy[6]<50 && yp-hy[6]>-50)
	{
		hh[6]=hh[6]*1000;
		score++;
	}						

DrawCircle(hh[7],hy[7],10,colors[RED]);//Third colomn extreme left y27;
	if(xp-hh[7]<40 && xp-hh[7]>-40 && yp-hy[7]<40 && yp-hy[7]>-40)
	{
		hh[7]=hh[7]*1000;
		score++;
	}	




DrawCircle(xx[0],yy[0],10,colors[RED]);//Fourth colomn extreme left y30;
	if(xp-xx[0]<10 && xp-xx[0]>-10 && yp-yy[0]<40 && yp-yy[0]>-40)
	{
		xx[0]=xx[0]*1000;
		score++;
	}	

DrawCircle(xx[1],yy[1],10,colors[RED]);//Fourth colomn extreme left y31;
	if(xp-xx[1]<10 && xp-xx[1]>-10 && yp-yy[1]<40 && yp-yy[1]>-40)
	{
		xx[1]=xx[1]*1000;
		score++;
	}

DrawCircle(xx[2],yy[2],10,colors[RED]);//fourth colomn extreme left y32;
	if(xp-xx[2]<10 && xp-xx[2]>-10 && yp-yy[2]<40 && yp-yy[2]>-40)
	{
		xx[2]=xx[2]*1000;
		score++;
	}

DrawCircle(xx[3],yy[3],10,colors[RED]);//fourth colomn extreme left y33;
	if(xp-xx[3]<40 && xp-xx[3]>-40 && yp-yy[3]<40 && yp-yy[3]>-40)
	{
		xx[3]=xx[3]*1000;
		score++;
	}		

DrawCircle(xx[4],yy[4],10,colors[RED]);//fourth colomn extreme left y34;
	if(xp-xx[4]<50 && xp-xx[4]>-50 && yp-yy[4]<50 && yp-yy[4]>-50)
	{
		xx[4]=xx[4]*1000;
		score++;
	}

DrawCircle(xx[5],yy[5],10,colors[RED]);//fourth colomn extreme left y35;
	if(xp-xx[5]<40 && xp-xx[5]>-40 && yp-yy[5]<40 && yp-yy[5]>-40)
	{
		xx[5]=xx[5]*1000;
		score++;
	}

DrawCircle(xx[6],yy[6],10,colors[RED]);//fourth colomn extreme left y36;
	if(xp-xx[6]<40 && xp-xx[6]>-40 && yp-yy[6]<40 && yp-yy[6]>-40)
	{
		xx[6]=xx[6]*1000;
		score++;
	}	

DrawCircle(xx[7],yy[7],10,colors[RED]);//fourth colomn extreme left y37;
	if(xp-xx[7]<40 && xp-xx[7]>-40 && yp-yy[7]<40 && yp-yy[7]>-40)
	{
		xx[7]=xx[7]*1000;
		score++;
	}	//




DrawCircle(aa[0],bb[0],10,colors[RED]);//fifth colomn extreme left y40;
	if(xp-aa[0]<30 && xp-aa[0]>-30 && yp-bb[0]<50 && yp-bb[0]>-50)
	{
		aa[0]=aa[0]*1000;
		score++;
	}

DrawCircle(aa[1],bb[1],10,colors[RED]);//fifth colomn extreme left y41;
	if(xp-aa[1]<10 && xp-aa[1]>-10 && yp-bb[1]<40 && yp-bb[1]>-40)
	{
		aa[1]=aa[1]*1000;
		score++;
	}

DrawCircle(aa[2],bb[2],10,colors[RED]);//fifth colomn extreme left y42;
	if(xp-aa[2]<10 && xp-aa[2]>-10 && yp-bb[2]<40 && yp-bb[2]>-40)
	{
		aa[2]=aa[2]*1000;
		score++;
	}

DrawCircle(aa[3],bb[3],10,colors[RED]);//fifth colomn extreme left y43;
	if(xp-aa[3]<40 && xp-aa[3]>-40 && yp-bb[3]<40 && yp-bb[3]>-40)
	{
		aa[3]=aa[3]*1000;
		score++;
	}

DrawCircle(aa[4],bb[4],10,colors[RED]);//fifth colomn extreme left y44;
	if(xp-aa[4]<50 && xp-aa[4]>-50 && yp-bb[4]<50 && yp-bb[4]>-50)
	{
		aa[4]=aa[4]*1000;
		score++;
	}

DrawCircle(aa[5],bb[5],10,colors[RED]);//fifth colomn extreme left y45;
	if(xp-aa[5]<40 && xp-aa[5]>-40 && yp-bb[5]<40 && yp-bb[5]>-40)
	{
		aa[5]=aa[5]*1000;
		score++;
	}

DrawCircle(aa[6],bb[6],10,colors[RED]);//fifth colomn extreme left y46;
	if(xp-aa[6]<40 && xp-aa[6]>-40 && yp-bb[6]<40 && yp-bb[6]>-40)
	{
		aa[6]=aa[6]*1000;
		score++;
	}

DrawCircle(aa[7],bb[7],10,colors[RED]);//fifth colomn extreme left y47;
	if(xp-aa[7]<40 && xp-aa[7]>-40 && yp-bb[7]<40 && yp-bb[7]>-40)
	{
		aa[7]=aa[7]*1000;
		score++;
	}





DrawCircle(x6[0],y6[0],10,colors[RED]);//sixth colomn extreme left y50;
	if(xp-x6[0]<10 && xp-x6[0]>-10 && yp-y6[0]<30 && yp-y6[0]>-30)
	{
		x6[0]=x6[0]*1000;
		score++;
	}

DrawCircle(x6[1],y6[1],10,colors[RED]);//sixth colomn extreme left y51;
	if(xp-x6[1]<10 && xp-x6[1]>-10 && yp-y6[1]<30 && yp-y6[1]>-30)
	{
		x6[1]=x6[1]*1000;
		score++;
	}


DrawCircle(x6[2],y6[2],10,colors[RED]);//sixth colomn extreme left y52;
	if(xp-x6[2]<40 && xp-x6[2]>-40 && yp-y6[2]<20 && yp-y6[2]>-20)
	{
		x6[2]=x6[2]*1000;
		score++;
	}
DrawCircle(x6[3],y6[3],10,colors[RED]);//second colomn extreme left y53;
	if(xp-x6[3]<40 && xp-x6[3]>-40 && yp-y6[3]<20 && yp-y6[3]>-20)
	{
		x6[3]=x6[3]*1000;
		score++;
	}
DrawCircle(x6[4],y6[4],10,colors[RED]);//second colomn extreme left y54;
	if(xp-x6[4]<40 && xp-x6[4]>-40 && yp-y6[4]<30 && yp-y6[4]>-30)
	{
		x6[4]=x6[4]*1000;
		score++;
	}
DrawCircle(x6[5],y6[5],10,colors[RED]);//second colomn extreme left y55;
	if(xp-x6[5]<40 && xp-x6[5]>-40 && yp-y6[5]<40 && yp-y6[5]>-40)//should never change y co ordiunates
	{
		x6[5]=x6[5]*1000;
		score++;
	}

DrawCircle(x6[6],y6[6],10,colors[RED]);//second colomn extreme left y56;
	if(xp-x6[6]<40 && xp-x6[6]>-40 && yp-y6[6]<40 && yp-y6[6]>-40)
	{
		x6[6]=x6[6]*1000;
		score++;
	}

DrawCircle(x6[7],y6[7],10,colors[RED]);//second colomn extreme left y57;
	if(xp-x6[7]<40 && xp-x6[7]>-40 && yp-y6[7]<40 && yp-y6[7]>-40)
	{
		x6[7]=x6[7]*1000;
		score++;
	}		







//


	DrawCircle(x7[0],y7[0],10,colors[RED]);//second colomn extreme left y60;
	if(xp-x7[0]<10 && xp-x7[0]>-10 && yp-y7[0]<30 && yp-y7[0]>-30)
	{
		x7[0]=x7[0]*1000;
		score++;
	}

DrawCircle(x7[1],y7[1],10,colors[RED]);//second colomn extreme left y61;
	if(xp-x7[1]<40 && xp-x7[1]>-40 && yp-y7[1]<30 && yp-y7[1]>-30)
	{
		x7[1]=x7[1]*1000;
		score++;
	}


DrawCircle(x7[2],y7[2],10,colors[RED]);//second colomn extreme left y62;
	if(xp-x7[2]<40 && xp-x7[2]>-40 && yp-y7[2]<10 && yp-y7[2]>-10)
	{
		x7[2]=x7[2]*1000;
		score++;
	}
DrawCircle(x7[3],y7[3],10,colors[RED]);//second colomn extreme left y63;
	if(xp-x7[3]<40 && xp-x7[3]>-40 && yp-y7[3]<10 && yp-y7[3]>-10)
	{
		x7[3]=x7[3]*1000;
		score++;
	}
DrawCircle(x7[4],y7[4],10,colors[RED]);//second colomn extreme left y64;
	if(xp-x7[4]<40 && xp-x7[4]>-40 && yp-y7[4]<10 && yp-y7[4]>-10)
	{
		x7[4]=x7[4]*1000;
		score++;
	}
DrawCircle(x7[5],y7[5],10,colors[RED]);//second colomn extreme left y65;
	if(xp-x7[5]<40 && xp-x7[5]>-40 && yp-y7[5]<10 && yp-y7[5]>-10)
	{
		x7[5]=x7[5]*1000;
		score++;
	}

DrawCircle(x7[6],y7[6],10,colors[RED]);//second colomn extreme left y66;
	if(xp-x7[6]<40 && xp-x7[6]>-40 && yp-y7[6]<40 && yp-y7[6]>-40)
	{
		x7[6]=x7[6]*1000;
		score++;
	}

DrawCircle(x7[7],y7[7],10,colors[RED]);//second colomn extreme left y67;
	if(xp-x7[7]<40 && xp-x7[7]>-40 && yp-y7[7]<40 && yp-y7[7]>-40)
	{
		x7[7]=x7[7]*1000;
		score++;
	}		







DrawCircle(x8[0],y8[0],10,colors[RED]);//second colomn extreme left y70;
	if(xp-x8[0]<40 && xp-x8[0]>-40 && yp-y8[0]<30 && yp-y8[0]>-30)
	{
		x8[0]=x8[0]*1000;
		score++;
	}

DrawCircle(x8[1],y8[1],10,colors[RED]);//second colomn extreme left y71;
	if(xp-x8[1]<40 && xp-x8[1]>-40 && yp-y8[1]<20 && yp-y8[1]>-20)
	{
		x8[1]=x8[1]*1000;
		score++;
	}


DrawCircle(x8[2],y8[2],10,colors[RED]);//second colomn extreme left y72;
	if(xp-x8[2]<40 && xp-x8[2]>-40 && yp-y8[2]<10 && yp-y8[2]>-10)
	{
		x8[2]=x8[2]*1000;
		score++;
	}
DrawCircle(x8[3],y8[3],10,colors[RED]);//second colomn extreme left y73;
	if(xp-x8[3]<40 && xp-x8[3]>-40 && yp-y8[3]<10 && yp-y8[3]>-10)
	{
		x8[3]=x8[3]*1000;
		score++;
	}
DrawCircle(x8[4],y8[4],10,colors[RED]);//second colomn extreme left y74;
	if(xp-x8[4]<40 && xp-x8[4]>-40 && yp-y8[4]<10 && yp-y8[4]>-10)
	{
		x8[4]=x8[4]*1000;
		score++;
	}
DrawCircle(x8[5],y8[5],10,colors[RED]);//second colomn extreme left y75;
	if(xp-x8[5]<40 && xp-x8[5]>-40 && yp-y8[5]<10 && yp-y8[5]>-10)
	{
		x8[5]=x8[5]*1000;
		score++;
	}

DrawCircle(x8[6],y8[6],10,colors[RED]);//second colomn extreme left y76;
	if(xp-x8[6]<40 && xp-x8[6]>-40 && yp-y8[6]<10 && yp-y8[6]>-10)
	{
		x8[6]=x8[6]*1000;
		score++;
	}

DrawCircle(x8[7],y8[7],10,colors[RED]);//second colomn extreme left y77;
	if(xp-x8[7]<40 && xp-x8[7]>-40 && yp-y8[7]<40 && yp-y8[7]>-40)
	{
		x8[7]=x8[7]*1000;
		score++;
	}		
}


else if(level==2) //it is for 2nd level.
{	
DrawCircle(xq[0],yq[0],10,colors[RED]);//first colomn extreme left  y0;
	if(xp-xq[0]<20 && xp-xq[0]>-20 && yp-yq[0]<20 && yp-yq[0]>-20)
	{
		xq[0]=xq[0]*1000;
		score++;
	}
DrawCircle(xq[1],yq[1],10,colors[RED]);//first colomn extreme left y1;
	if(xp-xq[1]<30 && xp-xq[1]>-30 && yp-yq[1]<30 && yp-yq[1]>-30)
	{
		xq[1]=xq[1]*1000;
		score++;
	}
DrawCircle(xq[2],yq[2],10,colors[RED]);//first colomn extreme left  y2;
	if(xp-xq[2]<30 && xp-xq[2]>-30 && yp-yq[2]<30 && yp-yq[2]>-30)
	{
		xq[2]=xq[2]*1000;
		score++;
	}
DrawCircle(xq[3],yq[3],10,colors[RED]);//first colomn extreme left y3;
	if(xp-xq[3]<30 && xp-xq[3]>-30 && yp-yq[3]<30 && yp-yq[3]>-30)
	{
		xq[3]=xq[3]*1000;
		score++;
	}
	
DrawCircle(xq[4],yq[4],10,colors[RED]);//first colomn extreme left y4;
	if(xp-xq[4]<30 && xp-xq[4]>-30 && yp-yq[4]<30 && yp-yq[4]>-30)
	{
		xq[4]=xq[4]*1000;
		score++;
	}	
DrawCircle(xq[5],yq[5],10,colors[RED]);//first colomn extreme left y5;
	if(xp-xq[5]<30 && xp-xq[5]>-30 && yp-yq[5]<30 && yp-yq[5]>-30)
	{
		xq[5]=xq[5]*1000;
		score++;
	}
DrawCircle(xq[6],yq[6],10,colors[RED]);//first colomn extreme left y6;
	if(xp-xq[6]<30 && xp-xq[6]>-30 && yp-yq[6]<30 && yp-yq[6]>-30)
	{
		xq[6]=xq[6]*1000;
		score++;
	}	
	
DrawCircle(xq[7],yq[7],10,colors[RED]);//first colomn extreme left y7;
	if(xp-xq[7]<40 && xp-xq[7]>-40 && yp-yq[7]<40 && yp-yq[7]>-40)
	{
		xq[7]=xq[7]*1000;
		score++;
	}



//now let us draw the second left bubbles
DrawCircle(xtq[0],ytq[0],10,colors[RED]);//second colomn extreme left y10;
	if(xp-xtq[0]<10 && xp-xtq[0]>-10 && yp-ytq[0]<30 && yp-ytq[0]>-30)
	{
		xtq[0]=xtq[0]*1000;
		score++;
	}

DrawCircle(xtq[1],ytq[1],10,colors[RED]);//second colomn extreme left y11;
	if(xp-xtq[1]<30 && xp-xtq[1]>-30 && yp-ytq[1]<30 && yp-ytq[1]>-30)
	{
		xtq[1]=xtq[1]*1000;
		score++;
	}

DrawCircle(xtq[2],ytq[2],10,colors[RED]);//second colomn extreme leftt y12;
	if(xp-xtq[2]<30 && xp-xtq[2]>-30 && yp-ytq[2]<30 && yp-ytq[2]>-30)
	{
		xtq[2]=xtq[2]*1000;
		score++;
	}

DrawCircle(xtq[3],ytq[3],10,colors[RED]);//second colomn extreme left y13;
	if(xp-xtq[3]<30 && xp-xtq[3]>-30 && yp-ytq[3]<30 && yp-ytq[3]>-30)
	{
		xtq[3]=xtq[3]*1000;
		score++;
	}

DrawCircle(xtq[4],ytq[4],10,colors[RED]);//second colomn extreme left y14;
	if(xp-xtq[4]<30 && xp-xtq[4]>-30 && yp-ytq[4]<30 && yp-ytq[4]>-30)
	{
		xtq[4]=xtq[4]*1000;
		score++;
	}

DrawCircle(xtq[5],ytq[5],10,colors[RED]);//second colomn extreme left y15;
	if(xp-xtq[5]<30 && xp-xtq[5]>-30 && yp-ytq[5]<30 && yp-ytq[5]>-30)
	{
		xtq[5]=xtq[5]*1000;
		score++;
	}
	
DrawCircle(xtq[6],ytq[6],10,colors[RED]);//second colomn extreme left y16;
	if(xp-xtq[6]<50 && xp-xtq[6]>-50 && yp-ytq[6]<50 && yp-ytq[6]>-40)
	{
		xtq[6]=xtq[6]*1000;
		score++;
	}
	
DrawCircle(xtq[7],ytq[7],10,colors[RED]);//second colomn extreme left y17;
	if(xp-xtq[7]<40 && xp-xtq[7]>-40 && yp-ytq[7]<40 && yp-ytq[7]>-40)
	{
		xtq[7]=xtq[7]*1000;
		score++;
	}
	

//Third row from left side

DrawCircle(hhq[0],hyq[0],10,colors[RED]);//third colomn extreme left y20;
	if(xp-hhq[0]<10 && xp-hhq[0]>-10 && yp-hyq[0]<30 && yp-hyq[0]>-30)
	{
		hhq[0]=hhq[0]*1000;
		score++;
	}

DrawCircle(hhq[1],hyq[1],10,colors[RED]);//third colomn extreme left y21;
	if(xp-hhq[1]<10 && xp-hhq[1]>-10 && yp-hyq[1]<30 && yp-hyq[1]>-30)
	{
		hhq[1]=hhq[1]*1000;
		score++;
	}

DrawCircle(hhq[2],hyq[2],10,colors[RED]);//third colomn extreme left y22;
	if(xp-hhq[2]<30 && xp-hhq[2]>-30 && yp-hyq[2]<30 && yp-hyq[2]>-30)
	{
		hhq[2]=hhq[2]*1000;
		score++;
	}	

DrawCircle(hhq[3],hyq[3],10,colors[RED]);//third colomn extreme left y23;
	if(xp-hhq[3]<30 && xp-hhq[3]>-30 && yp-hyq[3]<30 && yp-hyq[3]>-30)
	{
		hhq[3]=hhq[3]*1000;
		score++;
	}	

DrawCircle(hhq[4],hyq[4],10,colors[RED]);//third colomn extreme left y24;
	if(xp-hhq[4]<30 && xp-hhq[4]>-30 && yp-hyq[4]<30 && yp-hyq[4]>-30)
	{
		hhq[4]=hhq[4]*1000;
		score++;
	}

DrawCircle(hhq[5],hyq[5],10,colors[RED]);//third colomn extreme left y25;
	if(xp-hhq[5]<40 && xp-hhq[5]>-40 && yp-hyq[5]<40 && yp-hyq[5]>-40)
	{
		hhq[5]=hhq[5]*1000;
		score++;
	}

DrawCircle(hhq[6],hyq[6],10,colors[RED]);//third colomn extreme left y26;
	if(xp-hhq[6]<50 && xp-hhq[6]>-50 && yp-hyq[6]<50 && yp-hyq[6]>-50)
	{
		hhq[6]=hhq[6]*1000;
		score++;
	}						

DrawCircle(hhq[7],hyq[7],10,colors[RED]);//Third colomn extreme left y27;
	if(xp-hhq[7]<40 && xp-hhq[7]>-40 && yp-hyq[7]<40 && yp-hyq[7]>-40)
	{
		hhq[7]=hhq[7]*1000;
		score++;
	}	




DrawCircle(xxq[0],yyq[0],10,colors[RED]);//Fourth colomn extreme left y30;
	if(xp-xxq[0]<10 && xp-xxq[0]>-10 && yp-yyq[0]<40 && yp-yyq[0]>-40)
	{
		xxq[0]=xxq[0]*1000;
		score++;
	}	

DrawCircle(xxq[1],yyq[1],10,colors[RED]);//Fourth colomn extreme left y31;
	if(xp-xxq[1]<10 && xp-xxq[1]>-10 && yp-yyq[1]<40 && yp-yyq[1]>-40)
	{
		xxq[1]=xxq[1]*1000;
		score++;
	}

DrawCircle(xxq[2],yyq[2],10,colors[RED]);//fourth colomn extreme left y32;
	if(xp-xxq[2]<10 && xp-xxq[2]>-10 && yp-yyq[2]<40 && yp-yyq[2]>-40)
	{
		xxq[2]=xxq[2]*1000;
		score++;
	}

DrawCircle(xxq[3],yyq[3],10,colors[RED]);//fourth colomn extreme left y33;
	if(xp-xxq[3]<40 && xp-xxq[3]>-40 && yp-yyq[3]<40 && yp-yyq[3]>-40)
	{
		xxq[3]=xxq[3]*1000;
		score++;
	}		

DrawCircle(xxq[4],yyq[4],10,colors[RED]);//fourth colomn extreme left y34;
	if(xp-xxq[4]<50 && xp-xxq[4]>-50 && yp-yyq[4]<50 && yp-yyq[4]>-50)
	{
		xxq[4]=xxq[4]*1000;
		score++;
	}

DrawCircle(xxq[5],yyq[5],10,colors[RED]);//fourth colomn extreme left y35;
	if(xp-xxq[5]<40 && xp-xxq[5]>-40 && yp-yyq[5]<40 && yp-yyq[5]>-40)
	{
		xxq[5]=xxq[5]*1000;
		score++;
	}

DrawCircle(xxq[6],yyq[6],10,colors[RED]);//fourth colomn extreme left y36;
	if(xp-xxq[6]<40 && xp-xxq[6]>-40 && yp-yyq[6]<40 && yp-yyq[6]>-40)
	{
		xxq[6]=xxq[6]*1000;
		score++;
	}	

DrawCircle(xxq[7],yyq[7],10,colors[RED]);//fourth colomn extreme left y37;
	if(xp-xxq[7]<40 && xp-xxq[7]>-40 && yp-yyq[7]<40 && yp-yyq[7]>-40)
	{
		xxq[7]=xxq[7]*1000;
		score++;
	}	//




DrawCircle(aaq[0],bbq[0],10,colors[RED]);//fifth colomn extreme left y40;
	if(xp-aaq[0]<30 && xp-aaq[0]>-30 && yp-bbq[0]<50 && yp-bbq[0]>-50)
	{
		aaq[0]=aaq[0]*1000;
		score++;
	}

DrawCircle(aaq[1],bbq[1],10,colors[RED]);//fifth colomn extreme left y41;
	if(xp-aaq[1]<10 && xp-aaq[1]>-10 && yp-bbq[1]<40 && yp-bbq[1]>-40)
	{
		aaq[1]=aaq[1]*1000;
		score++;
	}

DrawCircle(aaq[2],bbq[2],10,colors[RED]);//fifth colomn extreme left y42;
	if(xp-aaq[2]<10 && xp-aaq[2]>-10 && yp-bbq[2]<40 && yp-bbq[2]>-40)
	{
		aaq[2]=aaq[2]*1000;
		score++;
	}

DrawCircle(aaq[3],bbq[3],10,colors[RED]);//fifth colomn extreme left y43;
	if(xp-aaq[3]<40 && xp-aaq[3]>-40 && yp-bbq[3]<40 && yp-bbq[3]>-40)
	{
		aaq[3]=aaq[3]*1000;
		score++;
	}

DrawCircle(aaq[4],bbq[4],10,colors[RED]);//fifth colomn extreme left y44;
	if(xp-aaq[4]<50 && xp-aaq[4]>-50 && yp-bbq[4]<50 && yp-bbq[4]>-50)
	{
		aaq[4]=aaq[4]*1000;
		score++;
	}

DrawCircle(aaq[5],bbq[5],10,colors[RED]);//fifth colomn extreme left y45;
	if(xp-aaq[5]<40 && xp-aaq[5]>-40 && yp-bbq[5]<40 && yp-bbq[5]>-40)
	{
		aaq[5]=aaq[5]*1000;
		score++;
	}

DrawCircle(aaq[6],bbq[6],10,colors[RED]);//fifth colomn extreme left y46;
	if(xp-aaq[6]<40 && xp-aaq[6]>-40 && yp-bbq[6]<40 && yp-bbq[6]>-40)
	{
		aaq[6]=aaq[6]*1000;
		score++;
	}

DrawCircle(aaq[7],bbq[7],10,colors[RED]);//fifth colomn extreme left y47;
	if(xp-aaq[7]<40 && xp-aaq[7]>-40 && yp-bbq[7]<40 && yp-bbq[7]>-40)
	{
		aaq[7]=aaq[7]*1000;
		score++;
	}



DrawCircle(x6q[0],y6q[0],10,colors[RED]);//sixth colomn extreme left y50;
	if(xp-x6q[0]<10 && xp-x6q[0]>-10 && yp-y6q[0]<30 && yp-y6q[0]>-30)
	{
		x6q[0]=x6q[0]*1000;
		score++;
	}

DrawCircle(x6q[1],y6q[1],10,colors[RED]);//sixth colomn extreme left y51;
	if(xp-x6q[1]<10 && xp-x6q[1]>-10 && yp-y6q[1]<30 && yp-y6q[1]>-30)
	{
		x6q[1]=x6q[1]*1000;
		score++;
	}


DrawCircle(x6q[2],y6q[2],10,colors[RED]);//sixth colomn extreme left y52;
	if(xp-x6q[2]<40 && xp-x6q[2]>-40 && yp-y6q[2]<20 && yp-y6q[2]>-20)
	{
		x6q[2]=x6q[2]*1000;
		score++;
	}
DrawCircle(x6q[3],y6q[3],10,colors[RED]);//second colomn extreme left y53;
	if(xp-x6q[3]<40 && xp-x6q[3]>-40 && yp-y6q[3]<20 && yp-y6q[3]>-20)
	{
		x6q[3]=x6q[3]*1000;
		score++;
	}
DrawCircle(x6q[4],y6q[4],10,colors[RED]);//second colomn extreme left y54;
	if(xp-x6q[4]<40 && xp-x6q[4]>-40 && yp-y6q[4]<30 && yp-y6q[4]>-30)
	{
		x6q[4]=x6q[4]*1000;
		score++;
	}
DrawCircle(x6q[5],y6q[5],10,colors[RED]);//second colomn extreme left y55;
	if(xp-x6q[5]<40 && xp-x6q[5]>-40 && yp-y6q[5]<40 && yp-y6q[5]>-40)//should never change y co ordiunates
	{
		x6q[5]=x6q[5]*1000;
		score++;
	}

DrawCircle(x6q[6],y6q[6],10,colors[RED]);//second colomn extreme left y56;
	if(xp-x6q[6]<40 && xp-x6q[6]>-40 && yp-y6q[6]<40 && yp-y6q[6]>-40)
	{
		x6q[6]=x6q[6]*1000;
		score++;
	}

DrawCircle(x6q[7],y6q[7],10,colors[RED]);//second colomn extreme left y57;
	if(xp-x6q[7]<40 && xp-x6q[7]>-40 && yp-y6q[7]<40 && yp-y6q[7]>-40)
	{
		x6q[7]=x6q[7]*1000;
		score++;
	}		


	DrawCircle(x7q[0],y7q[0],10,colors[RED]);//second colomn extreme left y60;
	if(xp-x7q[0]<10 && xp-x7q[0]>-10 && yp-y7q[0]<30 && yp-y7q[0]>-30)
	{
		x7q[0]=x7q[0]*1000;
		score++;
	}

DrawCircle(x7q[1],y7q[1],10,colors[RED]);//second colomn extreme left y61;
	if(xp-x7q[1]<40 && xp-x7q[1]>-40 && yp-y7q[1]<30 && yp-y7q[1]>-30)
	{
		x7q[1]=x7q[1]*1000;
		score++;
	}


DrawCircle(x7q[2],y7q[2],10,colors[RED]);//second colomn extreme left y62;
	if(xp-x7q[2]<40 && xp-x7q[2]>-40 && yp-y7q[2]<10 && yp-y7q[2]>-10)
	{
		x7q[2]=x7q[2]*1000;
		score++;
	}
DrawCircle(x7q[3],y7q[3],10,colors[RED]);//second colomn extreme left y63;
	if(xp-x7q[3]<40 && xp-x7q[3]>-40 && yp-y7q[3]<10 && yp-y7q[3]>-10)
	{
		x7q[3]=x7q[3]*1000;
		score++;
	}
DrawCircle(x7q[4],y7q[4],10,colors[RED]);//second colomn extreme left y64;
	if(xp-x7q[4]<40 && xp-x7q[4]>-40 && yp-y7q[4]<10 && yp-y7q[4]>-10)
	{
		x7q[4]=x7q[4]*1000;
		score++;
	}
DrawCircle(x7q[5],y7q[5],10,colors[RED]);//second colomn extreme left y65;
	if(xp-x7q[5]<40 && xp-x7q[5]>-40 && yp-y7q[5]<10 && yp-y7q[5]>-10)
	{
		x7q[5]=x7q[5]*1000;
		score++;
	}

DrawCircle(x7q[6],y7q[6],10,colors[RED]);//second colomn extreme left y66;
	if(xp-x7q[6]<40 && xp-x7q[6]>-40 && yp-y7q[6]<40 && yp-y7q[6]>-40)
	{
		x7q[6]=x7q[6]*1000;
		score++;
	}

DrawCircle(x7q[7],y7q[7],10,colors[RED]);//second colomn extreme left y67;
	if(xp-x7q[7]<40 && xp-x7q[7]>-40 && yp-y7q[7]<40 && yp-y7q[7]>-40)
	{
		x7q[7]=x7q[7]*1000;
		score++;
	}		



DrawCircle(x8q[0],y8q[0],10,colors[RED]);//second colomn extreme left y70;
	if(xp-x8q[0]<40 && xp-x8q[0]>-40 && yp-y8q[0]<30 && yp-y8q[0]>-30)
	{
		x8q[0]=x8q[0]*1000;
		score++;
	}

DrawCircle(x8q[1],y8q[1],10,colors[RED]);//second colomn extreme left y71;
	if(xp-x8q[1]<40 && xp-x8q[1]>-40 && yp-y8q[1]<20 && yp-y8q[1]>-20)
	{
		x8q[1]=x8q[1]*1000;
		score++;
	}


DrawCircle(x8q[2],y8q[2],10,colors[RED]);//second colomn extreme left y72;
	if(xp-x8q[2]<40 && xp-x8q[2]>-40 && yp-y8q[2]<10 && yp-y8q[2]>-10)
	{
		x8q[2]=x8q[2]*1000;
		score++;
	}
DrawCircle(x8q[3],y8q[3],10,colors[RED]);//second colomn extreme left y73;
	if(xp-x8q[3]<40 && xp-x8q[3]>-40 && yp-y8q[3]<10 && yp-y8q[3]>-10)
	{
		x8q[3]=x8q[3]*1000;
		score++;
	}
DrawCircle(x8q[4],y8q[4],10,colors[RED]);//second colomn extreme left y74;
	if(xp-x8q[4]<40 && xp-x8q[4]>-40 && yp-y8q[4]<10 && yp-y8q[4]>-10)
	{
		x8q[4]=x8q[4]*1000;
		score++;
	}
DrawCircle(x8q[5],y8q[5],10,colors[RED]);//second colomn extreme left y75;
	if(xp-x8q[5]<40 && xp-x8q[5]>-40 && yp-y8q[5]<10 && yp-y8q[5]>-10)
	{
		x8q[5]=x8q[5]*1000;
		score++;
	}

DrawCircle(x8q[6],y8q[6],10,colors[RED]);//second colomn extreme left y76;
	if(xp-x8q[6]<40 && xp-x8q[6]>-40 && yp-y8q[6]<10 && yp-y8q[6]>-10)
	{
		x8q[6]=x8q[6]*1000;
		score++;
	}

DrawCircle(x8q[7],y8q[7],10,colors[RED]);//second colomn extreme left y77;
	if(xp-x8q[7]<40 && xp-x8q[7]>-40 && yp-y8q[7]<40 && yp-y8q[7]>-40)
	{
		x8q[7]=x8q[7]*1000;
		score++;
	}		
}


else if(level==3)
{
	
DrawCircle(xqa[0],yqa[0],10,colors[RED]);//first colomn extreme left  y0;
	if(xp-xqa[0]<20 && xp-xqa[0]>-20 && yp-yq[0]<20 && yp-yq[0]>-20)
	{
		xqa[0]=xqa[0]*1000;
		score++;
	}
DrawCircle(xqa[1],yqa[1],10,colors[RED]);//first colomn extreme left y1;
	if(xp-xqa[1]<30 && xp-xqa[1]>-30 && yp-yq[1]<30 && yp-yq[1]>-30)
	{
		xqa[1]=xqa[1]*1000;
		score++;
	}
DrawCircle(xqa[2],yqa[2],10,colors[RED]);//first colomn extreme left  y2;
	if(xp-xqa[2]<30 && xp-xqa[2]>-30 && yp-yq[2]<30 && yp-yq[2]>-30)
	{
		xqa[2]=xqa[2]*1000;
		score++;
	}
DrawCircle(xqa[3],yqa[3],10,colors[RED]);//first colomn extreme left y3;
	if(xp-xqa[3]<30 && xp-xqa[3]>-30 && yp-yq[3]<30 && yp-yq[3]>-30)
	{
		xqa[3]=xqa[3]*1000;
		score++;
	}
	
DrawCircle(xqa[4],yqa[4],10,colors[RED]);//first colomn extreme left y4;
	if(xp-xqa[4]<30 && xp-xqa[4]>-30 && yp-yq[4]<30 && yp-yq[4]>-30)
	{
		xqa[4]=xqa[4]*1000;
		score++;
	}	
DrawCircle(xqa[5],yqa[5],10,colors[RED]);//first colomn extreme left y5;
	if(xp-xqa[5]<30 && xp-xqa[5]>-30 && yp-yq[5]<30 && yp-yq[5]>-30)
	{
		xqa[5]=xqa[5]*1000;
		score++;
	}
DrawCircle(xqa[6],yqa[6],10,colors[RED]);//first colomn extreme left y6;
	if(xp-xqa[6]<30 && xp-xqa[6]>-30 && yp-yq[6]<30 && yp-yq[6]>-30)
	{
		xqa[6]=xqa[6]*1000;
		score++;
	}	
	
DrawCircle(xqa[7],yqa[7],10,colors[RED]);//first colomn extreme left y7;
	if(xp-xqa[7]<40 && xp-xqa[7]>-40 && yp-yq[7]<40 && yp-yq[7]>-40)
	{
		xqa[7]=xqa[7]*1000;
		score++;
	}



//now let us draw the second left bubbles
DrawCircle(xtqa[0],ytqa[0],10,colors[RED]);//second colomn extreme left y10;
	if(xp-xtqa[0]<10 && xp-xtqa[0]>-10 && yp-ytq[0]<30 && yp-ytq[0]>-30)
	{
		xtqa[0]=xtqa[0]*1000;
		score++;
	}

DrawCircle(xtqa[1],ytqa[1],10,colors[RED]);//second colomn extreme left y11;
	if(xp-xtqa[1]<30 && xp-xtqa[1]>-30 && yp-ytq[1]<30 && yp-ytq[1]>-30)
	{
		xtqa[1]=xtqa[1]*1000;
		score++;
	}

DrawCircle(xtqa[2],ytqa[2],10,colors[RED]);//second colomn extreme leftt y12;
	if(xp-xtqa[2]<30 && xp-xtqa[2]>-30 && yp-ytq[2]<30 && yp-ytq[2]>-30)
	{
		xtqa[2]=xtqa[2]*1000;
		score++;
	}

DrawCircle(xtqa[3],ytqa[3],10,colors[RED]);//second colomn extreme left y13;
	if(xp-xtqa[3]<30 && xp-xtqa[3]>-30 && yp-ytq[3]<30 && yp-ytq[3]>-30)
	{
		xtqa[3]=xtqa[3]*1000;
		score++;
	}

DrawCircle(xtqa[4],ytqa[4],10,colors[RED]);//second colomn extreme left y14;
	if(xp-xtqa[4]<30 && xp-xtqa[4]>-30 && yp-ytq[4]<30 && yp-ytq[4]>-30)
	{
		xtqa[4]=xtqa[4]*1000;
		score++;
	}

DrawCircle(xtqa[5],ytqa[5],10,colors[RED]);//second colomn extreme left y15;
	if(xp-xtqa[5]<30 && xp-xtqa[5]>-30 && yp-ytq[5]<30 && yp-ytq[5]>-30)
	{
		xtqa[5]=xtqa[5]*1000;
		score++;
	}
	
DrawCircle(xtqa[6],ytqa[6],10,colors[RED]);//second colomn extreme left y16;
	if(xp-xtqa[6]<50 && xp-xtqa[6]>-50 && yp-ytq[6]<50 && yp-ytq[6]>-40)
	{
		xtqa[6]=xtqa[6]*1000;
		score++;
	}
	
DrawCircle(xtqa[7],ytqa[7],10,colors[RED]);//second colomn extreme left y17;
	if(xp-xtqa[7]<40 && xp-xtqa[7]>-40 && yp-ytq[7]<40 && yp-ytq[7]>-40)
	{
		xtqa[7]=xtqa[7]*1000;
		score++;
	}
	

//Third row from left side

DrawCircle(hhqa[0],hyqa[0],10,colors[RED]);//third colomn extreme left y20;
	if(xp-hhqa[0]<10 && xp-hhqa[0]>-10 && yp-hyq[0]<30 && yp-hyq[0]>-30)
	{
		hhqa[0]=hhqa[0]*1000;
		score++;
	}

DrawCircle(hhqa[1],hyqa[1],10,colors[RED]);//third colomn extreme left y21;
	if(xp-hhqa[1]<10 && xp-hhqa[1]>-10 && yp-hyq[1]<30 && yp-hyq[1]>-30)
	{
		hhqa[1]=hhqa[1]*1000;
		score++;
	}

DrawCircle(hhqa[2],hyqa[2],10,colors[RED]);//third colomn extreme left y22;
	if(xp-hhqa[2]<30 && xp-hhqa[2]>-30 && yp-hyq[2]<30 && yp-hyq[2]>-30)
	{
		hhqa[2]=hhqa[2]*1000;
		score++;
	}	

DrawCircle(hhqa[3],hyqa[3],10,colors[RED]);//third colomn extreme left y23;
	if(xp-hhqa[3]<30 && xp-hhqa[3]>-30 && yp-hyq[3]<30 && yp-hyq[3]>-30)
	{
		hhqa[3]=hhqa[3]*1000;
		score++;
	}	

DrawCircle(hhqa[4],hyqa[4],10,colors[RED]);//third colomn extreme left y24;
	if(xp-hhqa[4]<30 && xp-hhqa[4]>-30 && yp-hyq[4]<30 && yp-hyq[4]>-30)
	{
		hhqa[4]=hhqa[4]*1000;
		score++;
	}

DrawCircle(hhqa[5],hyqa[5],10,colors[RED]);//third colomn extreme left y25;
	if(xp-hhqa[5]<40 && xp-hhqa[5]>-40 && yp-hyq[5]<40 && yp-hyq[5]>-40)
	{
		hhqa[5]=hhqa[5]*1000;
		score++;
	}

DrawCircle(hhqa[6],hyqa[6],10,colors[RED]);//third colomn extreme left y26;
	if(xp-hhqa[6]<50 && xp-hhqa[6]>-50 && yp-hyq[6]<50 && yp-hyq[6]>-50)
	{
		hhqa[6]=hhqa[6]*1000;
		score++;
	}						

DrawCircle(hhqa[7],hyqa[7],10,colors[RED]);//Third colomn extreme left y27;
	if(xp-hhqa[7]<40 && xp-hhqa[7]>-40 && yp-hyq[7]<40 && yp-hyq[7]>-40)
	{
		hhqa[7]=hhqa[7]*1000;
		score++;
	}	




DrawCircle(xxqa[0],yyqa[0],10,colors[RED]);//Fourth colomn extreme left y30;
	if(xp-xxqa[0]<10 && xp-xxqa[0]>-10 && yp-yyq[0]<40 && yp-yyq[0]>-40)
	{
		xxqa[0]=xxqa[0]*1000;
		score++;
	}	

DrawCircle(xxqa[1],yyqa[1],10,colors[RED]);//Fourth colomn extreme left y31;
	if(xp-xxqa[1]<10 && xp-xxqa[1]>-10 && yp-yyq[1]<40 && yp-yyq[1]>-40)
	{
		xxqa[1]=xxqa[1]*1000;
		score++;
	}

DrawCircle(xxqa[2],yyqa[2],10,colors[RED]);//fourth colomn extreme left y32;
	if(xp-xxqa[2]<10 && xp-xxqa[2]>-10 && yp-yyq[2]<40 && yp-yyq[2]>-40)
	{
		xxqa[2]=xxqa[2]*1000;
		score++;
	}

DrawCircle(xxqa[3],yyqa[3],10,colors[RED]);//fourth colomn extreme left y33;
	if(xp-xxqa[3]<40 && xp-xxqa[3]>-40 && yp-yyq[3]<40 && yp-yyq[3]>-40)
	{
		xxqa[3]=xxqa[3]*1000;
		score++;
	}		

DrawCircle(xxqa[4],yyqa[4],10,colors[RED]);//fourth colomn extreme left y34;
	if(xp-xxqa[4]<50 && xp-xxqa[4]>-50 && yp-yyq[4]<50 && yp-yyq[4]>-50)
	{
		xxqa[4]=xxqa[4]*1000;
		score++;
	}

DrawCircle(xxqa[5],yyqa[5],10,colors[RED]);//fourth colomn extreme left y35;
	if(xp-xxqa[5]<40 && xp-xxqa[5]>-40 && yp-yyq[5]<40 && yp-yyq[5]>-40)
	{
		xxqa[5]=xxqa[5]*1000;
		score++;
	}

DrawCircle(xxqa[6],yyqa[6],10,colors[RED]);//fourth colomn extreme left y36;
	if(xp-xxqa[6]<40 && xp-xxqa[6]>-40 && yp-yyq[6]<40 && yp-yyq[6]>-40)
	{
		xxqa[6]=xxqa[6]*1000;
		score++;
	}	

DrawCircle(xxqa[7],yyqa[7],10,colors[RED]);//fourth colomn extreme left y37;
	if(xp-xxqa[7]<40 && xp-xxqa[7]>-40 && yp-yyq[7]<40 && yp-yyq[7]>-40)
	{
		xxqa[7]=xxqa[7]*1000;
		score++;
	}	//




DrawCircle(aaqa[0],bbqa[0],10,colors[RED]);//fifth colomn extreme left y40;
	if(xp-aaqa[0]<30 && xp-aaqa[0]>-30 && yp-bbq[0]<50 && yp-bbq[0]>-50)
	{
		aaqa[0]=aaqa[0]*1000;
		score++;
	}

DrawCircle(aaqa[1],bbqa[1],10,colors[RED]);//fifth colomn extreme left y41;
	if(xp-aaqa[1]<10 && xp-aaqa[1]>-10 && yp-bbq[1]<40 && yp-bbq[1]>-40)
	{
		aaqa[1]=aaqa[1]*1000;
		score++;
	}

DrawCircle(aaqa[2],bbqa[2],10,colors[RED]);//fifth colomn extreme left y42;
	if(xp-aaqa[2]<10 && xp-aaqa[2]>-10 && yp-bbq[2]<40 && yp-bbq[2]>-40)
	{
		aaqa[2]=aaqa[2]*1000;
		score++;
	}

DrawCircle(aaqa[3],bbqa[3],10,colors[RED]);//fifth colomn extreme left y43;
	if(xp-aaqa[3]<40 && xp-aaqa[3]>-40 && yp-bbq[3]<40 && yp-bbq[3]>-40)
	{
		aaqa[3]=aaqa[3]*1000;
		score++;
	}

DrawCircle(aaqa[4],bbqa[4],10,colors[RED]);//fifth colomn extreme left y44;
	if(xp-aaqa[4]<50 && xp-aaqa[4]>-50 && yp-bbq[4]<50 && yp-bbq[4]>-50)
	{
		aaqa[4]=aaqa[4]*1000;
		score++;
	}

DrawCircle(aaqa[5],bbqa[5],10,colors[RED]);//fifth colomn extreme left y45;
	if(xp-aaqa[5]<40 && xp-aaqa[5]>-40 && yp-bbq[5]<40 && yp-bbq[5]>-40)
	{
		aaqa[5]=aaqa[5]*1000;
		score++;
	}

DrawCircle(aaqa[6],bbqa[6],10,colors[RED]);//fifth colomn extreme left y46;
	if(xp-aaqa[6]<40 && xp-aaqa[6]>-40 && yp-bbq[6]<40 && yp-bbq[6]>-40)
	{
		aaqa[6]=aaqa[6]*1000;
		score++;
	}

DrawCircle(aaqa[7],bbqa[7],10,colors[RED]);//fifth colomn extreme left y47;
	if(xp-aaqa[7]<40 && xp-aaqa[7]>-40 && yp-bbq[7]<40 && yp-bbq[7]>-40)
	{
		aaqa[7]=aaqa[7]*1000;
		score++;
	}

DrawCircle(x6qa[0],y6qa[0],10,colors[RED]);//sixth colomn extreme left y50;
	if(xp-x6qa[0]<10 && xp-x6qa[0]>-10 && yp-y6q[0]<30 && yp-y6q[0]>-30)
	{
		x6qa[0]=x6qa[0]*1000;
		score++;
	}

DrawCircle(x6qa[1],y6qa[1],10,colors[RED]);//sixth colomn extreme left y51;
	if(xp-x6qa[1]<10 && xp-x6qa[1]>-10 && yp-y6q[1]<30 && yp-y6q[1]>-30)
	{
		x6qa[1]=x6qa[1]*1000;
		score++;
	}


DrawCircle(x6qa[2],y6qa[2],10,colors[RED]);//sixth colomn extreme left y52;
	if(xp-x6qa[2]<40 && xp-x6qa[2]>-40 && yp-y6q[2]<20 && yp-y6q[2]>-20)
	{
		x6qa[2]=x6qa[2]*1000;
		score++;
	}
DrawCircle(x6qa[3],y6qa[3],10,colors[RED]);//second colomn extreme left y53;
	if(xp-x6qa[3]<40 && xp-x6qa[3]>-40 && yp-y6q[3]<20 && yp-y6q[3]>-20)
	{
		x6qa[3]=x6qa[3]*1000;
		score++;
	}
DrawCircle(x6qa[4],y6qa[4],10,colors[RED]);//second colomn extreme left y54;
	if(xp-x6qa[4]<40 && xp-x6qa[4]>-40 && yp-y6q[4]<30 && yp-y6q[4]>-30)
	{
		x6qa[4]=x6qa[4]*1000;
		score++;
	}
DrawCircle(x6qa[5],y6qa[5],10,colors[RED]);//second colomn extreme left y55;
	if(xp-x6qa[5]<40 && xp-x6qa[5]>-40 && yp-y6q[5]<40 && yp-y6q[5]>-40)//should never change y co ordiunates
	{
		x6qa[5]=x6qa[5]*1000;
		score++;
	}

DrawCircle(x6qa[6],y6qa[6],10,colors[RED]);//second colomn extreme left y56;
	if(xp-x6qa[6]<40 && xp-x6qa[6]>-40 && yp-y6q[6]<40 && yp-y6q[6]>-40)
	{
		x6qa[6]=x6qa[6]*1000;
		score++;
	}

DrawCircle(x6qa[7],y6qa[7],10,colors[RED]);//second colomn extreme left y57;
	if(xp-x6qa[7]<40 && xp-x6qa[7]>-40 && yp-y6q[7]<40 && yp-y6q[7]>-40)
	{
		x6qa[7]=x6qa[7]*1000;
		score++;
	}		

	DrawCircle(x7qa[0],y7qa[0],10,colors[RED]);//second colomn extreme left y60;
	if(xp-x7qa[0]<10 && xp-x7qa[0]>-10 && yp-y7q[0]<30 && yp-y7q[0]>-30)
	{
		x7qa[0]=x7qa[0]*1000;
		score++;
	}

DrawCircle(x7qa[1],y7qa[1],10,colors[RED]);//second colomn extreme left y61;
	if(xp-x7qa[1]<40 && xp-x7qa[1]>-40 && yp-y7q[1]<30 && yp-y7q[1]>-30)
	{
		x7qa[1]=x7qa[1]*1000;
		score++;
	}


DrawCircle(x7qa[2],y7qa[2],10,colors[RED]);//second colomn extreme left y62;
	if(xp-x7qa[2]<40 && xp-x7qa[2]>-40 && yp-y7q[2]<10 && yp-y7q[2]>-10)
	{
		x7qa[2]=x7qa[2]*1000;
		score++;
	}
DrawCircle(x7qa[3],y7qa[3],10,colors[RED]);//second colomn extreme left y63;
	if(xp-x7qa[3]<40 && xp-x7qa[3]>-40 && yp-y7q[3]<10 && yp-y7q[3]>-10)
	{
		x7qa[3]=x7qa[3]*1000;
		score++;
	}
DrawCircle(x7qa[4],y7qa[4],10,colors[RED]);//second colomn extreme left y64;
	if(xp-x7qa[4]<40 && xp-x7qa[4]>-40 && yp-y7q[4]<10 && yp-y7q[4]>-10)
	{
		x7qa[4]=x7qa[4]*1000;
		score++;
	}
DrawCircle(x7qa[5],y7qa[5],10,colors[RED]);//second colomn extreme left y65;
	if(xp-x7qa[5]<40 && xp-x7qa[5]>-40 && yp-y7q[5]<10 && yp-y7q[5]>-10)
	{
		x7qa[5]=x7qa[5]*1000;
		score++;
	}

DrawCircle(x7qa[6],y7qa[6],10,colors[RED]);//second colomn extreme left y66;
	if(xp-x7qa[6]<40 && xp-x7qa[6]>-40 && yp-y7q[6]<40 && yp-y7q[6]>-40)
	{
		x7qa[6]=x7qa[6]*1000;
		score++;
	}

DrawCircle(x7qa[7],y7qa[7],10,colors[RED]);//second colomn extreme left y67;
	if(xp-x7qa[7]<40 && xp-x7qa[7]>-40 && yp-y7q[7]<40 && yp-y7q[7]>-40)
	{
		x7qa[7]=x7qa[7]*1000;
		score++;
	}		

DrawCircle(x8qa[0],y8qa[0],10,colors[RED]);//second colomn extreme left y70;
	if(xp-x8qa[0]<40 && xp-x8qa[0]>-40 && yp-y8q[0]<30 && yp-y8q[0]>-30)
	{
		x8qa[0]=x8qa[0]*1000;
		score++;
	}

DrawCircle(x8qa[1],y8qa[1],10,colors[RED]);//second colomn extreme left y71;
	if(xp-x8qa[1]<40 && xp-x8qa[1]>-40 && yp-y8q[1]<20 && yp-y8q[1]>-20)
	{
		x8qa[1]=x8qa[1]*1000;
		score++;
	}


DrawCircle(x8qa[2],y8qa[2],10,colors[RED]);//second colomn extreme left y72;
	if(xp-x8qa[2]<40 && xp-x8qa[2]>-40 && yp-y8q[2]<10 && yp-y8q[2]>-10)
	{
		x8qa[2]=x8qa[2]*1000;
		score++;
	}
DrawCircle(x8qa[3],y8qa[3],10,colors[RED]);//second colomn extreme left y73;
	if(xp-x8qa[3]<40 && xp-x8qa[3]>-40 && yp-y8q[3]<10 && yp-y8q[3]>-10)
	{
		x8qa[3]=x8qa[3]*1000;
		score++;
	}
DrawCircle(x8qa[4],y8qa[4],10,colors[RED]);//second colomn extreme left y74;
	if(xp-x8qa[4]<40 && xp-x8qa[4]>-40 && yp-y8q[4]<10 && yp-y8q[4]>-10)
	{
		x8qa[4]=x8qa[4]*1000;
		score++;
	}
DrawCircle(x8qa[5],y8qa[5],10,colors[RED]);//second colomn extreme left y75;
	if(xp-x8qa[5]<40 && xp-x8qa[5]>-40 && yp-y8q[5]<10 && yp-y8q[5]>-10)
	{
		x8qa[5]=x8qa[5]*1000;
		score++;
	}

DrawCircle(x8qa[6],y8qa[6],10,colors[RED]);//second colomn extreme left y76;
	if(xp-x8qa[6]<40 && xp-x8qa[6]>-40 && yp-y8q[6]<10 && yp-y8q[6]>-10)
	{
		x8qa[6]=x8qa[6]*1000;
		score++;
	}

DrawCircle(x8qa[7],y8qa[7],10,colors[RED]);//second colomn extreme left y77;
	if(xp-x8qa[7]<40 && xp-x8qa[7]>-40 && yp-y8q[7]<40 && yp-y8q[7]>-40)
	{
		x8qa[7]=x8qa[7]*1000;
		score++;
	}		

}

else if(level==4)
{
	
DrawCircle(xqaa[0],yqaa[0],10,colors[RED]);//first colomn extreme left  y0;
	if(xp-xqaa[0]<20 && xp-xqaa[0]>-20 && yp-yq[0]<20 && yp-yq[0]>-20)
	{
		xqaa[0]=xqaa[0]*1000;
		score++;
	}
DrawCircle(xqaa[1],yqaa[1],10,colors[RED]);//first colomn extreme left y1;
	if(xp-xqaa[1]<30 && xp-xqaa[1]>-30 && yp-yq[1]<30 && yp-yq[1]>-30)
	{
		xqaa[1]=xqaa[1]*1000;
		score++;
	}
DrawCircle(xqaa[2],yqaa[2],10,colors[RED]);//first colomn extreme left  y2;
	if(xp-xqaa[2]<30 && xp-xqaa[2]>-30 && yp-yq[2]<30 && yp-yq[2]>-30)
	{
		xqaa[2]=xqaa[2]*1000;
		score++;
	}
DrawCircle(xqaa[3],yqaa[3],10,colors[RED]);//first colomn extreme left y3;
	if(xp-xqaa[3]<30 && xp-xqaa[3]>-30 && yp-yq[3]<30 && yp-yq[3]>-30)
	{
		xqaa[3]=xqaa[3]*1000;
		score++;
	}
	
DrawCircle(xqaa[4],yqaa[4],10,colors[RED]);//first colomn extreme left y4;
	if(xp-xqaa[4]<30 && xp-xqaa[4]>-30 && yp-yq[4]<30 && yp-yq[4]>-30)
	{
		xqaa[4]=xqaa[4]*1000;
		score++;
	}	
DrawCircle(xqaa[5],yqaa[5],10,colors[RED]);//first colomn extreme left y5;
	if(xp-xqaa[5]<30 && xp-xqaa[5]>-30 && yp-yq[5]<30 && yp-yq[5]>-30)
	{
		xqaa[5]=xqaa[5]*1000;
		score++;
	}
DrawCircle(xqaa[6],yqaa[6],10,colors[RED]);//first colomn extreme left y6;
	if(xp-xqaa[6]<30 && xp-xqaa[6]>-30 && yp-yq[6]<30 && yp-yq[6]>-30)
	{
		xqaa[6]=xqaa[6]*1000;
		score++;
	}	
	
DrawCircle(xqaa[7],yqaa[7],10,colors[RED]);//first colomn extreme left y7;
	if(xp-xqaa[7]<40 && xp-xqaa[7]>-40 && yp-yq[7]<40 && yp-yq[7]>-40)
	{
		xqaa[7]=xqaa[7]*1000;
		score++;
	}

//now let us draw the second left bubbles
DrawCircle(xtqaa[0],ytq[0],10,colors[RED]);//second colomn extreme left y10;
	if(xp-xtqaa[0]<10 && xp-xtqaa[0]>-10 && yp-ytq[0]<30 && yp-ytq[0]>-30)
	{
		xtqaa[0]=xtqaa[0]*1000;
		score++;
	}

DrawCircle(xtqaa[1],ytqaa[1],10,colors[RED]);//second colomn extreme left y11;
	if(xp-xtqaa[1]<30 && xp-xtqaa[1]>-30 && yp-ytq[1]<30 && yp-ytq[1]>-30)
	{
		xtqaa[1]=xtqaa[1]*1000;
		score++;
	}

DrawCircle(xtqaa[2],ytqaa[2],10,colors[RED]);//second colomn extreme leftt y12;
	if(xp-xtqaa[2]<30 && xp-xtqaa[2]>-30 && yp-ytq[2]<30 && yp-ytq[2]>-30)
	{
		xtqaa[2]=xtqaa[2]*1000;
		score++;
	}

DrawCircle(xtqaa[3],ytqaa[3],10,colors[RED]);//second colomn extreme left y13;
	if(xp-xtqaa[3]<30 && xp-xtqaa[3]>-30 && yp-ytq[3]<30 && yp-ytq[3]>-30)
	{
		xtqaa[3]=xtqaa[3]*1000;
		score++;
	}

DrawCircle(xtqaa[4],ytqaa[4],10,colors[RED]);//second colomn extreme left y14;
	if(xp-xtqaa[4]<30 && xp-xtqaa[4]>-30 && yp-ytq[4]<30 && yp-ytq[4]>-30)
	{
		xtqaa[4]=xtqaa[4]*1000;
		score++;
	}

DrawCircle(xtqaa[5],ytqaa[5],10,colors[RED]);//second colomn extreme left y15;
	if(xp-xtqaa[5]<30 && xp-xtqaa[5]>-30 && yp-ytq[5]<30 && yp-ytq[5]>-30)
	{
		xtqaa[5]=xtqaa[5]*1000;
		score++;
	}
	
DrawCircle(xtqaa[6],ytqaa[6],10,colors[RED]);//second colomn extreme left y16;
	if(xp-xtqaa[6]<50 && xp-xtqaa[6]>-50 && yp-ytq[6]<50 && yp-ytq[6]>-40)
	{
		xtqaa[6]=xtqaa[6]*1000;
		score++;
	}
	
DrawCircle(xtqaa[7],ytqaa[7],10,colors[RED]);//second colomn extreme left y17;
	if(xp-xtqaa[7]<40 && xp-xtqaa[7]>-40 && yp-ytq[7]<40 && yp-ytq[7]>-40)
	{
		xtqaa[7]=xtqaa[7]*1000;
		score++;
	}
	
//Third row from left side

DrawCircle(hhqaa[0],hyqaa[0],10,colors[RED]);//third colomn extreme left y20;
	if(xp-hhqaa[0]<10 && xp-hhqaa[0]>-10 && yp-hyq[0]<30 && yp-hyq[0]>-30)
	{
		hhqaa[0]=hhqaa[0]*1000;
		score++;
	}

DrawCircle(hhqaa[1],hyqaa[1],10,colors[RED]);//third colomn extreme left y21;
	if(xp-hhqaa[1]<10 && xp-hhqaa[1]>-10 && yp-hyq[1]<30 && yp-hyq[1]>-30)
	{
		hhqaa[1]=hhqaa[1]*1000;
		score++;
	}

DrawCircle(hhqaa[2],hyqaa[2],10,colors[RED]);//third colomn extreme left y22;
	if(xp-hhqaa[2]<30 && xp-hhqaa[2]>-30 && yp-hyq[2]<30 && yp-hyq[2]>-30)
	{
		hhqaa[2]=hhqaa[2]*1000;
		score++;
	}	

DrawCircle(hhqaa[3],hyqaa[3],10,colors[RED]);//third colomn extreme left y23;
	if(xp-hhqaa[3]<30 && xp-hhqaa[3]>-30 && yp-hyq[3]<30 && yp-hyq[3]>-30)
	{
		hhqaa[3]=hhqaa[3]*1000;
		score++;
	}	

DrawCircle(hhqaa[4],hyqaa[4],10,colors[RED]);//third colomn extreme left y24;
	if(xp-hhqaa[4]<30 && xp-hhqaa[4]>-30 && yp-hyq[4]<30 && yp-hyq[4]>-30)
	{
		hhqaa[4]=hhqaa[4]*1000;
		score++;
	}

DrawCircle(hhqaa[5],hyqaa[5],10,colors[RED]);//third colomn extreme left y25;
	if(xp-hhqaa[5]<40 && xp-hhqaa[5]>-40 && yp-hyq[5]<40 && yp-hyq[5]>-40)
	{
		hhqaa[5]=hhqaa[5]*1000;
		score++;
	}

DrawCircle(hhqaa[6],hyqaa[6],10,colors[RED]);//third colomn extreme left y26;
	if(xp-hhqaa[6]<50 && xp-hhqaa[6]>-50 && yp-hyq[6]<50 && yp-hyq[6]>-50)
	{
		hhqaa[6]=hhqaa[6]*1000;
		score++;
	}						

DrawCircle(hhqaa[7],hyqaa[7],10,colors[RED]);//Third colomn extreme left y27;
	if(xp-hhqaa[7]<40 && xp-hhqaa[7]>-40 && yp-hyq[7]<40 && yp-hyq[7]>-40)
	{
		hhqaa[7]=hhqaa[7]*1000;
		score++;
	}	

DrawCircle(xxqaa[0],yyqaa[0],10,colors[RED]);//Fourth colomn extreme left y30;
	if(xp-xxqaa[0]<10 && xp-xxqaa[0]>-10 && yp-yyq[0]<40 && yp-yyq[0]>-40)
	{
		xxqaa[0]=xxqaa[0]*1000;
		score++;
	}	

DrawCircle(xxqaa[1],yyqaa[1],10,colors[RED]);//Fourth colomn extreme left y31;
	if(xp-xxqaa[1]<10 && xp-xxqaa[1]>-10 && yp-yyq[1]<40 && yp-yyq[1]>-40)
	{
		xxqaa[1]=xxqaa[1]*1000;
		score++;
	}

DrawCircle(xxqaa[2],yyqaa[2],10,colors[RED]);//fourth colomn extreme left y32;
	if(xp-xxqaa[2]<10 && xp-xxqaa[2]>-10 && yp-yyq[2]<40 && yp-yyq[2]>-40)
	{
		xxqaa[2]=xxqaa[2]*1000;
		score++;
	}

DrawCircle(xxqaa[3],yyqaa[3],10,colors[RED]);//fourth colomn extreme left y33;
	if(xp-xxqaa[3]<40 && xp-xxqaa[3]>-40 && yp-yyq[3]<40 && yp-yyq[3]>-40)
	{
		xxqaa[3]=xxqaa[3]*1000;
		score++;
	}		

DrawCircle(xxqaa[4],yyqaa[4],10,colors[RED]);//fourth colomn extreme left y34;
	if(xp-xxqaa[4]<50 && xp-xxqaa[4]>-50 && yp-yyq[4]<50 && yp-yyq[4]>-50)
	{
		xxqaa[4]=xxqaa[4]*1000;
		score++;
	}

DrawCircle(xxqaa[5],yyqaa[5],10,colors[RED]);//fourth colomn extreme left y35;
	if(xp-xxqaa[5]<40 && xp-xxqaa[5]>-40 && yp-yyq[5]<40 && yp-yyq[5]>-40)
	{
		xxqaa[5]=xxqaa[5]*1000;
		score++;
	}

DrawCircle(xxqaa[6],yyqaa[6],10,colors[RED]);//fourth colomn extreme left y36;
	if(xp-xxqaa[6]<40 && xp-xxqaa[6]>-40 && yp-yyq[6]<40 && yp-yyq[6]>-40)
	{
		xxqaa[6]=xxqaa[6]*1000;
		score++;
	}	

DrawCircle(xxqaa[7],yyqaa[7],10,colors[RED]);//fourth colomn extreme left y37;
	if(xp-xxqaa[7]<40 && xp-xxqaa[7]>-40 && yp-yyq[7]<40 && yp-yyq[7]>-40)
	{
		xxqaa[7]=xxqaa[7]*1000;
		score++;
	}	//

DrawCircle(aaqaa[0],bbqaa[0],10,colors[RED]);//fifth colomn extreme left y40;
	if(xp-aaqaa[0]<30 && xp-aaqaa[0]>-30 && yp-bbq[0]<50 && yp-bbq[0]>-50)
	{
		aaqaa[0]=aaqaa[0]*1000;
		score++;
	}

DrawCircle(aaqaa[1],bbqaa[1],10,colors[RED]);//fifth colomn extreme left y41;
	if(xp-aaqaa[1]<10 && xp-aaqaa[1]>-10 && yp-bbq[1]<40 && yp-bbq[1]>-40)
	{
		aaqaa[1]=aaqaa[1]*1000;
		score++;
	}

DrawCircle(aaqaa[2],bbqaa[2],10,colors[RED]);//fifth colomn extreme left y42;
	if(xp-aaqaa[2]<10 && xp-aaqaa[2]>-10 && yp-bbq[2]<40 && yp-bbq[2]>-40)
	{
		aaqaa[2]=aaqaa[2]*1000;
		score++;
	}

DrawCircle(aaqaa[3],bbqaa[3],10,colors[RED]);//fifth colomn extreme left y43;
	if(xp-aaqaa[3]<40 && xp-aaqaa[3]>-40 && yp-bbq[3]<40 && yp-bbq[3]>-40)
	{
		aaqaa[3]=aaqaa[3]*1000;
		score++;
	}

DrawCircle(aaqaa[4],bbqaa[4],10,colors[RED]);//fifth colomn extreme left y44;
	if(xp-aaqaa[4]<50 && xp-aaqaa[4]>-50 && yp-bbq[4]<50 && yp-bbq[4]>-50)
	{
		aaqaa[4]=aaqaa[4]*1000;
		score++;
	}

DrawCircle(aaqaa[5],bbqaa[5],10,colors[RED]);//fifth colomn extreme left y45;
	if(xp-aaqaa[5]<40 && xp-aaqaa[5]>-40 && yp-bbq[5]<40 && yp-bbq[5]>-40)
	{
		aaqaa[5]=aaqaa[5]*1000;
		score++;
	}

DrawCircle(aaqaa[6],bbqaa[6],10,colors[RED]);//fifth colomn extreme left y46;
	if(xp-aaqaa[6]<40 && xp-aaqaa[6]>-40 && yp-bbq[6]<40 && yp-bbq[6]>-40)
	{
		aaqaa[6]=aaqaa[6]*1000;
		score++;
	}

DrawCircle(aaqaa[7],bbqaa[7],10,colors[RED]);//fifth colomn extreme left y47;
	if(xp-aaqaa[7]<40 && xp-aaqaa[7]>-40 && yp-bbq[7]<40 && yp-bbq[7]>-40)
	{
		aaqaa[7]=aaqaa[7]*1000;
		score++;
	}

DrawCircle(x6qaa[0],y6qaa[0],10,colors[RED]);//sixth colomn extreme left y50;
	if(xp-x6qaa[0]<10 && xp-x6qaa[0]>-10 && yp-y6q[0]<30 && yp-y6q[0]>-30)
	{
		x6qaa[0]=x6qaa[0]*1000;
		score++;
	}

DrawCircle(x6qaa[1],y6qaa[1],10,colors[RED]);//sixth colomn extreme left y51;
	if(xp-x6qaa[1]<10 && xp-x6qaa[1]>-10 && yp-y6q[1]<30 && yp-y6q[1]>-30)
	{
		x6qaa[1]=x6qaa[1]*1000;
		score++;
	}


DrawCircle(x6qaa[2],y6qaa[2],10,colors[RED]);//sixth colomn extreme left y52;
	if(xp-x6qaa[2]<40 && xp-x6qaa[2]>-40 && yp-y6q[2]<20 && yp-y6q[2]>-20)
	{
		x6qaa[2]=x6qaa[2]*1000;
		score++;
	}
DrawCircle(x6qaa[3],y6qaa[3],10,colors[RED]);//second colomn extreme left y53;
	if(xp-x6qaa[3]<40 && xp-x6qaa[3]>-40 && yp-y6q[3]<20 && yp-y6q[3]>-20)
	{
		x6qaa[3]=x6qaa[3]*1000;
		score++;
	}
DrawCircle(x6qaa[4],y6qaa[4],10,colors[RED]);//second colomn extreme left y54;
	if(xp-x6qaa[4]<40 && xp-x6qaa[4]>-40 && yp-y6q[4]<30 && yp-y6q[4]>-30)
	{
		x6qaa[4]=x6qaa[4]*1000;
		score++;
	}
DrawCircle(x6qaa[5],y6qaa[5],10,colors[RED]);//second colomn extreme left y55;
	if(xp-x6qaa[5]<40 && xp-x6qaa[5]>-40 && yp-y6q[5]<40 && yp-y6q[5]>-40)//should never change y co ordiunates
	{
		x6qaa[5]=x6qaa[5]*1000;
		score++;
	}

DrawCircle(x6qaa[6],y6qaa[6],10,colors[RED]);//second colomn extreme left y56;
	if(xp-x6qaa[6]<40 && xp-x6qaa[6]>-40 && yp-y6q[6]<40 && yp-y6q[6]>-40)
	{
		x6qaa[6]=x6qaa[6]*1000;
		score++;
	}

DrawCircle(x6qaa[7],y6qaa[7],10,colors[RED]);//second colomn extreme left y57;
	if(xp-x6qaa[7]<40 && xp-x6qaa[7]>-40 && yp-y6q[7]<40 && yp-y6q[7]>-40)
	{
		x6qaa[7]=x6qaa[7]*1000;
		score++;
	}		

//


	DrawCircle(x7qaa[0],y7qaa[0],10,colors[RED]);//second colomn extreme left y60;
	if(xp-x7qaa[0]<10 && xp-x7qaa[0]>-10 && yp-y7q[0]<30 && yp-y7q[0]>-30)
	{
		x7qaa[0]=x7qaa[0]*1000;
		score++;
	}

DrawCircle(x7qaa[1],y7qaa[1],10,colors[RED]);//second colomn extreme left y61;
	if(xp-x7qaa[1]<40 && xp-x7qaa[1]>-40 && yp-y7q[1]<30 && yp-y7q[1]>-30)
	{
		x7qaa[1]=x7qaa[1]*1000;
		score++;
	}


DrawCircle(x7qaa[2],y7qaa[2],10,colors[RED]);//second colomn extreme left y62;
	if(xp-x7qaa[2]<40 && xp-x7qaa[2]>-40 && yp-y7q[2]<10 && yp-y7q[2]>-10)
	{
		x7qaa[2]=x7qaa[2]*1000;
		score++;
	}
DrawCircle(x7qaa[3],y7qaa[3],10,colors[RED]);//second colomn extreme left y63;
	if(xp-x7qaa[3]<40 && xp-x7qaa[3]>-40 && yp-y7q[3]<10 && yp-y7q[3]>-10)
	{
		x7qaa[3]=x7qaa[3]*1000;
		score++;
	}
DrawCircle(x7qaa[4],y7qaa[4],10,colors[RED]);//second colomn extreme left y64;
	if(xp-x7qaa[4]<40 && xp-x7qaa[4]>-40 && yp-y7q[4]<10 && yp-y7q[4]>-10)
	{
		x7qaa[4]=x7qaa[4]*1000;
		score++;
	}
DrawCircle(x7qaa[5],y7qaa[5],10,colors[RED]);//second colomn extreme left y65;
	if(xp-x7qaa[5]<40 && xp-x7qaa[5]>-40 && yp-y7q[5]<10 && yp-y7q[5]>-10)
	{
		x7qaa[5]=x7qaa[5]*1000;
		score++;
	}

DrawCircle(x7qaa[6],y7qaa[6],10,colors[RED]);//second colomn extreme left y66;
	if(xp-x7qaa[6]<40 && xp-x7qaa[6]>-40 && yp-y7q[6]<40 && yp-y7q[6]>-40)
	{
		x7qaa[6]=x7qaa[6]*1000;
		score++;
	}

DrawCircle(x7qaa[7],y7qaa[7],10,colors[RED]);//second colomn extreme left y67;
	if(xp-x7qaa[7]<40 && xp-x7qaa[7]>-40 && yp-y7q[7]<40 && yp-y7q[7]>-40)
	{
		x7qaa[7]=x7qaa[7]*1000;
		score++;
	}		







DrawCircle(x8qaa[0],y8qaa[0],10,colors[RED]);//second colomn extreme left y70;
	if(xp-x8qaa[0]<40 && xp-x8qaa[0]>-40 && yp-y8q[0]<30 && yp-y8q[0]>-30)
	{
		x8qaa[0]=x8qaa[0]*1000;
		score++;
	}

DrawCircle(x8qaa[1],y8qaa[1],10,colors[RED]);//second colomn extreme left y71;
	if(xp-x8qaa[1]<40 && xp-x8qaa[1]>-40 && yp-y8q[1]<20 && yp-y8q[1]>-20)
	{
		x8qaa[1]=x8qaa[1]*1000;
		score++;
	}


DrawCircle(x8qaa[2],y8qaa[2],10,colors[RED]);//second colomn extreme left y72;
	if(xp-x8qaa[2]<40 && xp-x8qaa[2]>-40 && yp-y8q[2]<10 && yp-y8q[2]>-10)
	{
		x8qaa[2]=x8qaa[2]*1000;
		score++;
	}
DrawCircle(x8qaa[3],y8qaa[3],10,colors[RED]);//second colomn extreme left y73;
	if(xp-x8qaa[3]<40 && xp-x8qaa[3]>-40 && yp-y8q[3]<10 && yp-y8q[3]>-10)
	{
		x8qaa[3]=x8qaa[3]*1000;
		score++;
	}
DrawCircle(x8qaa[4],y8qaa[4],10,colors[RED]);//second colomn extreme left y74;
	if(xp-x8qaa[4]<40 && xp-x8qaa[4]>-40 && yp-y8q[4]<10 && yp-y8q[4]>-10)
	{
		x8qaa[4]=x8qaa[4]*1000;
		score++;
	}
DrawCircle(x8qaa[5],y8qaa[5],10,colors[RED]);//second colomn extreme left y75;
	if(xp-x8qaa[5]<40 && xp-x8qaa[5]>-40 && yp-y8q[5]<10 && yp-y8q[5]>-10)
	{
		x8qaa[5]=x8qaa[5]*1000;
		score++;
	}

DrawCircle(x8qaa[6],y8qaa[6],10,colors[RED]);//second colomn extreme left y76;
	if(xp-x8qaa[6]<40 && xp-x8qaa[6]>-40 && yp-y8q[6]<10 && yp-y8q[6]>-10)
	{
		x8qaa[6]=x8qaa[6]*1000;
		score++;
	}

DrawCircle(x8qaa[7],y8qaa[7],10,colors[RED]);//second colomn extreme left y77;
	if(xp-x8qaa[7]<40 && xp-x8qaa[7]>-40 && yp-y8q[7]<40 && yp-y8q[7]>-40)
	{
		x8qaa[7]=x8qaa[7]*1000;
		score++;
	}		

}
//Player car
	float x = xp; 
	float y = yp; 
	float width = 12;
	float height = 10;
	float* color = colors[BLUE_VIOLET]; 
	float radius = 3.0;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect

	float xaa = xo; 
	float yaa = yo; 
	float* colora = colors[RED]; 

	
	//opponent car
	DrawRoundRect(xaa,yaa,width,height,colora,radius); // bottom left tyre
	DrawRoundRect(xaa+width*3,yaa,width,height,colora,radius); // bottom right tyre
	DrawRoundRect(xaa+width*3,yaa+height*4,width,height,colora,radius); // top right tyre
	DrawRoundRect(xaa,yaa+height*4,width,height,colora,radius); // top left tyre
	DrawRoundRect(xaa, yaa+height*2, width, height, colora, radius/2); // body left rect
	DrawRoundRect(xaa+width, yaa+height, width*2, height*3, colora, radius/2); // body center rect
	DrawRoundRect(xaa+width*3, yaa+height*2, width, height, colora, radius/2); // body right rect

if(level==4)
{

float xaaa = xoo; 
float yaaa = yoo; 
float* coloraa = colors[RED]; 

	
	//opponent car
	DrawRoundRect(xaaa,yaaa,width,height,coloraa,radius); // bottom left tyre
	DrawRoundRect(xaaa+width*3,yaaa,width,height,coloraa,radius); // bottom right tyre
	DrawRoundRect(xaaa+width*3,yaaa+height*4,width,height,coloraa,radius); // top right tyre
	DrawRoundRect(xaaa,yaaa+height*4,width,height,coloraa,radius); // top left tyre
	DrawRoundRect(xaaa, yaaa+height*2, width, height, coloraa, radius/2); // body left rect
	DrawRoundRect(xaaa+width, yaaa+height, width*2, height*3, coloraa, radius/2); // body center rect
	DrawRoundRect(xaaa+width*3, yaaa+height*2, width, height, coloraa, radius/2); // body right rect

}

	// Drawing Arena
	int gap_turn = 120;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2;//340 // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left


int sxa = 120;
int sya = 110;
int swidtha=240;

DrawRectangle(sxa-sheight*2 /*100*/, sya+sheight+swidtha+gap_turn, sheight*2, swidtha, scolor); // left up
DrawRectangle(sxa + swidtha + gap_turn, sya, swidtha, sheight, scolor); // bottom right
DrawRectangle(sxa-sheight*2, sya+sheight, sheight*2, swidtha, scolor); // left down
DrawRectangle(sxa, sya+610, swidtha, sheight, scolor); // top right
DrawRectangle(sxa + swidtha + gap_turn, sya+610, swidtha, sheight, scolor); // top left
DrawRectangle(sxa+swidtha*2+gap_turn, sya+sheight+swidtha+gap_turn, sheight*2, swidtha, scolor); // right up
DrawRectangle(sxa+swidtha*2+gap_turn, sya+sheight, sheight*2, swidtha, scolor); // right down
DrawRectangle(sxa, sya, swidtha, sheight, scolor); // bottom left


	int sxb = 220;
	int syb = 210;
	int swidthb =140;//140 // half width
	
	DrawRectangle(sxb-sheight*2, syb+sheight+swidthb+gap_turn, sheight*2, swidthb, scolor); // left up
	DrawRectangle(sxb + swidthb + gap_turn, syb, swidthb, sheight, scolor); // bottom right
	DrawRectangle(sxb-sheight*2, syb+sheight, sheight*2, swidthb, scolor); // left down
	DrawRectangle(sxb, syb+410, swidthb, sheight, scolor); // top right
	DrawRectangle(sxb + swidthb + gap_turn, syb+410, swidthb, sheight, scolor); // top left
	DrawRectangle(sxb+swidthb*2+gap_turn, syb+sheight+swidthb+gap_turn, sheight*2, swidthb, scolor); // right up
	DrawRectangle(sxb+swidthb*2+gap_turn, syb+sheight, sheight*2, swidthb, scolor); // right down
	DrawRectangle(sxb, syb, swidthb, sheight, scolor); // bottom left


	int sxc = 320;
	int syc = 310;
	int swidthc = 40;
	
	DrawRectangle((sxc-sheight*2), (syc+sheight+swidthc+gap_turn), sheight*2, swidthc, scolor); // left up
	DrawRectangle(sxc + swidthc + gap_turn, syc, swidthc, sheight, scolor); // bottom right
	DrawRectangle((sxc-sheight*2), syc+sheight, sheight*2, swidthc, scolor); // left down
	DrawRectangle(sxc, syc+210, swidthc, sheight, scolor); // top right
	DrawRectangle(sxc + swidthc + gap_turn, syc+210, swidthc, sheight, scolor); // top left
	DrawRectangle(sxc+swidthc*2+gap_turn, syc+sheight+swidthc+gap_turn, sheight*2, swidthc, scolor); // right up
	DrawRectangle(sxc+swidthc*2+gap_turn, syc+sheight, sheight*2, swidthc, scolor); // right down
	DrawRectangle(sxc, syc, swidthc, sheight, scolor); // bottom left





	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
	glutPostRedisplay();
}
if(flag==1)
{
	DrawString( 300, 770,"Press", colors[LINEN]);
	DrawString( 350, 730," 1) Start a new game ",colors[DARK_GOLDEN_ROD]);
	DrawString( 350, 690," 2) See high-scores",colors[DARK_GOLDEN_ROD]);
	DrawString( 350, 650," 3) Help",colors[DARK_GOLDEN_ROD]);
	DrawString( 350, 610," 4) Exit",colors[DARK_GOLDEN_ROD]);
	DrawString( 350, 570," 5) Continue",colors[DARK_GOLDEN_ROD]);

	glutSwapBuffers();
	glutPostRedisplay();
}
if(flag==2)
{

	
	DrawString( 50, 760," Press ",colors[LIGHT_PINK]);
	DrawString( 50, 730," > 1 to Start a new game ",colors[DARK_GOLDEN_ROD]);
	DrawString( 50, 700," > 2 to See highscores ",colors[DARK_GOLDEN_ROD]);
	DrawString( 50, 670," > 3 for Help",colors[DARK_GOLDEN_ROD]);
	DrawString( 50, 640," > 4 to exit",colors[DARK_GOLDEN_ROD]);



	glutSwapBuffers();

	glutPostRedisplay();
}
if(flag==4)//help menu
{
	DrawString( 50, 400,"Welcome to Help menu", colors[YELLOW]);
	DrawString( 50, 350,"You will be given three lives.one life will lost if you collide with the opponent car",colors[YELLOW]);
	DrawString( 50, 300,"You will get reward when you pick circular awards", colors[YELLOW]);
	DrawString( 50, 250,"Press p any time during game to pause game", colors[YELLOW]);
	DrawString( 50, 220,"Tap on space botton to play with double spped", colors[YELLOW]);
	DrawString( 50, 170,"For farther help visit dodge.com", colors[YELLOW]);

	glutSwapBuffers();
	glutPostRedisplay();
}
if(flag==7)
{

DrawString(300 , 584, "highscores", colors[MISTY_ROSE]);
DrawString(300 , 534, int_to_string(array2[0]), colors[GREEN]);
DrawString(300 , 494, int_to_string(array2[1]), colors[GREEN]);
DrawString(300 , 454, int_to_string(array2[2]), colors[GREEN]);
DrawString(300 , 414, int_to_string(array2[3]), colors[GREEN]);
DrawString(300 , 374, int_to_string(array2[4]), colors[GREEN]);
DrawString(300 , 344, int_to_string(array2[5]), colors[GREEN]);
DrawString(300 , 304, int_to_string(array2[6]), colors[GREEN]);
DrawString(300 , 264, int_to_string(array2[7]), colors[GREEN]);
DrawString(300 , 224, int_to_string(array2[8]), colors[GREEN]);
DrawString(300 , 184, int_to_string(array2[9]), colors[GREEN]);



glutSwapBuffers();
glutPostRedisplay();
}




















if(score==64)
	{
		level=2;
		score=score+100;
	}
if(score==228)
	{
		level=3;
		score=score+100;
	}
if(score==392)
	{
		level++;
		score=score+100;
	}

	//you won 


	if(score==456)
		{
		xo=xo*76543;
		yo=yo*6543;
		yo=yo*765;
		yp=yp*43245;
				DrawString( 400, 834, "You won", colors[MISTY_ROSE]);
		}
}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */


void NonPrintableKeys(int key, int x, int y) 
{

if(xp>350 && xp<480)//can only user press only if the car at gap
{


	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) 
	{
		xp=xp-100;
		// what to do when left key is pressed...

	} else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) 
	{
		xp=xp+100;
	} else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) 
	{
		yp=yp+100;
	}

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{
		yp=yp-100;
	}
}
if(yp>350 && yp<480)
{


	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) 
	{
		xp=xp-100;
		// what to do when left key is pressed...

	} else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) 
	{
		xp=xp+100;
	} else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) 
	{
		yp=yp+110;
	}

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{
		yp=yp-100;
	}
}


	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/






	glutPostRedisplay();



}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) 
{
	
	if(key=='1')
	{
		flag=0;
	}
	
	if(key=='3')
	{
		flag=4;
	}
	if(key=='4')
	{
		exit(1);
	}
	if(key=='p')
	{
		flag=1;
	}

	if(key=='5')
	{
		flag=0;
	}

	if(key=='2')
	{
		flag=7;
	}

	if (key==32)
	{
		if (yp>18 && yp<54 && xp>28)// neche last wale 
	{	if(flag==0)
		{
		xp=xp-4;
		}
	}
	if(xp>=28 && xp<50 && yp<762)//left uper
	{	if(flag==0)
		{
	yp=yp+4;
}
	}

	if(yp>738 && yp<780 && xp<758)//top 
	{
		if(flag==0)
		{
		xp=xp+4;
	}
	}
	if(xp>750 && xp<770 && yp>22)//right
	{	if(flag==0)
		{
		yp=yp-4;
		}

	}
//int xp=440;
//int yp=39;
  	 
//2nd orbit
  	 if (xp>140 && xp<700 && yp>130 && yp<160)//2nd orbit ki bottom wala
  	 {	if(flag==0)
  	 	{
  	 	xp=xp-4;
  	 }
  	 }
  	 if (xp>110 && xp<157 && yp<660 && yp>110)// 2nd orbit ki left side wala
  	 {	if(flag==0)
  	 	{
  	 	yp=yp+4;
  	 }
  	 }
  	 if(yp>640 && yp<670 && xp<670 && xp>110) // 2nd orbit ki top wala
  	 {	if(flag==0)
  	 	{
  	 	xp=xp+4;
  	 }
  	 }
  	 if(xp>643 && xp<680 && yp>130 && yp<720)// 2nd orbit ki right side wla
  	 {	if(flag==0)
  	 	{
  	 	yp=yp-4;

  	 }
  	 }


  	 //3RD ORBITT WALA
  	 if(xp<620 && yp<260 && yp>220 && xp>242)
  	 {	if(flag==0)
  	 	{
  	 	xp=xp-4;
  	 	}
  	 }

  	if (xp>225 && xp<255 && yp>220 && yp<558)
  	{	if(flag==0)
  		{
  		yp=yp+4;
  		}
  	}
  	if(yp<580 && yp>535 && xp>230 && xp<557)
  	{	if(flag==0)
  		{
  		xp=xp+4;
  		}
  	}
  	if(xp>540 && xp<570 && yp<610 && yp>215)
  	{	if(flag==0)
  		{
  		yp=yp-4;
  		}
  	
  	}



  	//4rd orbit


	if(xp<500 && xp>332 && yp>320 && yp<370)
	{	if(flag==0)
		{
		xp=xp-4;
		}
	}
	if(yp>320 && yp<450 && xp>329 && xp<365)
	{	if(flag==0)
		{
		yp=yp+4;
		}
	}

	if(xp>328 && xp<480 && yp<456 && yp>420)
	{	if(flag==0)
		{
	xp=xp+4;
	}
	}

	if(xp>425 && xp<510 && yp>321 && yp<455)
	{	if(flag==0)
		{
	yp=yp-4;
		}
	}

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
/*if(yp==39 && xp<755)//bottom move
{
	xp=xp+1;

}*/
//movement of opponent car


	if(level==3)
	{
		if(yo>20 && yo<48 && xo<755 )//again  bottom move // neche bilkul last wale line ma move hoti ha
		{
			if(flag==0)
			{
			xo=xo+4;
		}
		}


		if(xo>=755 && xo<=775 && yo<763) //righ upper  move // right side  per upper jati ha 
		{	if(flag==0)
			{
			yo=yo+4;
			}
		}
		if(yo>=755 && yo<=780 && xo>35)//upper move toward right  // top upper right side pe move krti ha gariii(:
		{	if(flag==0)

			{
			xo=xo-4;
			}
		}

		if(xo>=20 && xo<=40 && yo>39)//left  down move
		{	if(flag==0)
			{
			yo=yo-4;
			}
		}


		if (xo>130 && xo<700 && yo>130 && yo<160)//2nd orbit ki bottom wala
	  	 {	if(flag==0)
	  	 	{
	  	 	xo=xo+4;
	  	 	}
	  	 }

	  	 if(xo>643 && xo<680 && yo>130 && yo<720)// 2nd orbit ki right side wla
	  	 {	if(flag==0)
	  	 	{
	  	 	yo=yo+4;
	  	 }
	  	}

	  	 if(yo>640 && yo<670 && xo<670 && xo>110) // 2nd orbit ki top wala
	  	 {	
	  	 	if(flag==0)
	  	 	{
	  	 	xo=xo-4;
	  	 	}
	  	 }
	  	 
		if (xo>109 && xo<157 && yo<665 && yo>110)// 2nd orbit ki left side wala
	  	 {	if(flag==0)
	  	 	{
	  	 	yo=yo-4;
	  	 }}

	//3RD ORBITT WALA opponent ki garii ka
	  	 if(xo<620 && yo<260 && yo>220 && xo>230)
	  	 {	if(flag==0)
	  	 	{
	  	 	xo=xo+4;
	  	 }
	  	 }

		if(xo>540 && xo<570 && yo<610 && yo>215)
	  	{	if(flag==0)
	  		{
	  		yo=yo+4;
	  		}
	  	
	  	}

	  	if(yo<580 && yo>528 && xo>230 && xo<565)
	  	{	if(flag==0)
	  		{
	  		xo=xo-4;
	  		}
	  	}
	  	
	  	if (xo>225 && xo<255 && yo>220 && yo<558)
	  	{	if(flag==0)
	  		{
	  		yo=yo-4;
	  		}
	  	}


	  	//opponent car in 4rth orbit
	  	if(xo<500 && xo>332 && yo>315 && yo<370)
		{	if(flag==0)
			{
			xo=xo+4;
			}
		}

		if(xo>420 && xo<505 && yo>321 && yo<455)
		{	if(flag==0)
			{
		yo=yo+4;
			}
		}
		if(xo>328 && xo<480 && yo<456 && yo>420)
		{
			if(flag==0)
			{
		xo=xo-4;
			}
		}
		if(yo>320 && yo<459 && xo>329 && xo<365)
		{
			if(flag==0)
			{
			yo=yo-4;
			}
		}

	}	


	else if(level==1)
	{
		if(yo>20 && yo<48 && xo<755 )//again  bottom move // neche bilkul last wale line ma move hoti ha
		{
			if(flag==0)
				{
					xo=xo+2;
				}	
		}


		if(xo>=755 && xo<=775 && yo<763) //righ upper  move // right side  per upper jati ha 
		{	
			if (flag==0)
			{yo=yo+2;
			}
		}
		if(yo>=755 && yo<=780 && xo>35)//upper move toward right  // top upper right side pe move krti ha gariii(:
		{	if(flag==0)
			{
			xo=xo-2;
			}
		}

		if(xo>=20 && xo<=40 && yo>39)//left  down move
		{	if(flag==0)
			{
			yo=yo-2;
			}
		}


		if (xo>130 && xo<700 && yo>130 && yo<160)//2nd orbit ki bottom wala
	  	 {	if(flag==0)
	  	 	{
	  	 	xo=xo+2;
	  	 	}
	  	 }

	  	 if(xo>643 && xo<680 && yo>130 && yo<720)// 2nd orbit ki right side wla
	  	 {	if(flag==0)
	  	 	{
	  	 	yo=yo+2;
	  	 	}
	  	 }

	  	 if(yo>640 && yo<670 && xo<670 && xo>110) // 2nd orbit ki top wala
	  	 {
	  	 	if(flag==0)
	  	 	{
	  	 	xo=xo-2;
	  	 	}
	  	 }
	  	 
		if (xo>109 && xo<157 && yo<665 && yo>110)// 2nd orbit ki left side wala
	  	 {	if(flag==0)
	  	 	{
	  	 	yo=yo-2;
	  	 	}
	  	 }

	//3RD ORBITT WALA opponent ki garii ka
	  	 if(xo<620 && yo<260 && yo>220 && xo>230)
	  	 {	if(flag==0)
	  	 	{
	  	 	xo=xo+2;
	  	 }
	  	 }

		if(xo>540 && xo<570 && yo<610 && yo>215)
	  	{	if(flag==0)
	  		{
	  		yo=yo+2;
	  		}
	  	
	  	}

	  	if(yo<580 && yo>528 && xo>230 && xo<565)
	  	{	if(flag==0)
	  		{
	  		xo=xo-2;
	  		}
	  	}
	  	
	  	if (xo>225 && xo<255 && yo>220 && yo<558)
	  	{	if(flag==0)
	  		{
	  		yo=yo-2;
	  		}
	  	}


	  	//opponent car in 4rth orbit
	  	if(xo<500 && xo>332 && yo>315 && yo<370)
		{	if(flag==0)
			{
			xo=xo+2;
			}
		}

		if(xo>425 && xo<510 && yo>321 && yo<455)
		{
			if(flag==0)
			{
		yo=yo+2;
			}
		}
		if(xo>328 && xo<480 && yo<456 && yo>420)
		{
			if(flag==0)
			{
		xo=xo-2;
			}
		}
		if(yo>320 && yo<459 && xo>329 && xo<365)
		{
			if(flag==0)
			{
			yo=yo-2;
			}
		}
	}
	else if(level==2)
	{
		if(yo>20 && yo<48 && xo<755 )//again  bottom move // neche bilkul last wale line ma move hoti ha
		{
			if(flag==0)
			{
			xo=xo+2;
		}
		}


		if(xo>=755 && xo<=775 && yo<763) //righ upper  move // right side  per upper jati ha 
		{	if(flag==0)
			{
			yo=yo+2;
			}
		}
		if(yo>=755 && yo<=780 && xo>35)//upper move toward right  // top upper right side pe move krti ha gariii(:
		{	if(flag==0)

			{
			xo=xo-2;
			}
		}

		if(xo>=20 && xo<=40 && yo>39)//left  down move
		{	if(flag==0)
			{
			yo=yo-2;
			}
		}


		if (xo>130 && xo<700 && yo>130 && yo<160)//2nd orbit ki bottom wala
	  	 {	if(flag==0)
	  	 	{
	  	 	xo=xo+2;
	  	 	}
	  	 }

	  	 if(xo>643 && xo<680 && yo>130 && yo<720)// 2nd orbit ki right side wla
	  	 {	if(flag==0)
	  	 	{
	  	 	yo=yo+2;
	  	 }
	  	}

	  	 if(yo>640 && yo<670 && xo<670 && xo>110) // 2nd orbit ki top wala
	  	 {	
	  	 	if(flag==0)
	  	 	{
	  	 	xo=xo-2;
	  	 	}
	  	 }
	  	 
		if (xo>109 && xo<157 && yo<665 && yo>110)// 2nd orbit ki left side wala
	  	 {	if(flag==0)
	  	 	{
	  	 	yo=yo-2;
	  	 }}

	//3RD ORBITT WALA opponent ki garii ka
	  	 if(xo<620 && yo<260 && yo>220 && xo>230)
	  	 {	if(flag==0)
	  	 	{
	  	 	xo=xo+2;
	  	 }
	  	 }

		if(xo>540 && xo<570 && yo<610 && yo>215)
	  	{	if(flag==0)
	  		{
	  		yo=yo+2;
	  		}
	  	
	  	}

	  	if(yo<580 && yo>528 && xo>230 && xo<565)
	  	{	if(flag==0)
	  		{
	  		xo=xo-2;
	  		}
	  	}
	  	
	  	if (xo>225 && xo<255 && yo>220 && yo<558)
	  	{	if(flag==0)
	  		{
	  		yo=yo-2;
	  		}
	  	}


	  	//opponent car in 4rth orbit
	  	if(xo<500 && xo>332 && yo>315 && yo<370)
		{	if(flag==0)
			{
			xo=xo+2;
			}
		}

		if(xo>420 && xo<505 && yo>321 && yo<455)
		{	if(flag==0)
			{
		yo=yo+2;
			}
		}
		if(xo>328 && xo<480 && yo<456 && yo>420)
		{
			if(flag==0)
			{
		xo=xo-2;
			}
		}
		if(yo>320 && yo<459 && xo>329 && xo<365)
		{
			if(flag==0)
			{
			yo=yo-2;
			}
		}
	}
	else if(level==4)
	{
			if(yo>20 && yo<48 && xo<755 )//again  bottom move // neche bilkul last wale line ma move hoti ha
		{
			if(flag==0)
			{
			xo=xo+2;
		}
		}


		if(xo>=755 && xo<=775 && yo<763) //righ upper  move // right side  per upper jati ha 
		{	if(flag==0)
			{
			yo=yo+2;
			}
		}
		if(yo>=755 && yo<=780 && xo>35)//upper move toward right  // top upper right side pe move krti ha gariii(:
		{	if(flag==0)

			{
			xo=xo-2;
			}
		}

		if(xo>=20 && xo<=40 && yo>39)//left  down move
		{	if(flag==0)
			{
			yo=yo-2;
			}
		}


		if (xo>130 && xo<700 && yo>130 && yo<160)//2nd orbit ki bottom wala
	  	 {	if(flag==0)
	  	 	{
	  	 	xo=xo+2;
	  	 	}
	  	 }

	  	 if(xo>643 && xo<680 && yo>130 && yo<720)// 2nd orbit ki right side wla
	  	 {	if(flag==0)
	  	 	{
	  	 	yo=yo+2;
	  	 }
	  	}

	  	 if(yo>640 && yo<670 && xo<670 && xo>110) // 2nd orbit ki top wala
	  	 {	
	  	 	if(flag==0)
	  	 	{
	  	 	xo=xo-2;
	  	 	}
	  	 }
	  	 
		if (xo>109 && xo<157 && yo<665 && yo>110)// 2nd orbit ki left side wala
	  	 {	if(flag==0)
	  	 	{
	  	 	yo=yo-2;
	  	 }}

	//3RD ORBITT WALA opponent ki garii ka
	  	 if(xo<620 && yo<260 && yo>220 && xo>230)
	  	 {	if(flag==0)
	  	 	{
	  	 	xo=xo+2;
	  	 }
	  	 }

		if(xo>540 && xo<570 && yo<610 && yo>215)
	  	{	if(flag==0)
	  		{
	  		yo=yo+2;
	  		}
	  	
	  	}

	  	if(yo<580 && yo>528 && xo>230 && xo<565)
	  	{	if(flag==0)
	  		{
	  		xo=xo-2;
	  		}
	  	}
	  	
	  	if (xo>225 && xo<255 && yo>220 && yo<558)
	  	{	if(flag==0)
	  		{
	  		yo=yo-2;
	  		}
	  	}


	  	//opponent car in 4rth orbit
	  	if(xo<500 && xo>332 && yo>315 && yo<370)
		{	if(flag==0)
			{
			xo=xo+2;
			}
		}

		if(xo>420 && xo<505 && yo>321 && yo<455)
		{	if(flag==0)
			{
		yo=yo+2;
			}
		}
		if(xo>328 && xo<480 && yo<456 && yo>420)
		{
			if(flag==0)
			{
		xo=xo-2;
			}
		}
		if(yo>320 && yo<459 && xo>329 && xo<365)
		{
			if(flag==0)
			{
			yo=yo-2;
			}
		}



//this if for the second car of computer
		if(yoo>20 && yoo<48 && xoo<755 )//again  bottom move // neche bilkul last wale line ma move hoti ha
		{	if(flag==0)
			{
			xoo=xoo+2;
			}
		}


		if(xoo>=755 && xoo<=775 && yoo<763) //righ upper  move // right side  per upper jati ha 
		{	if(flag==0)
			{
			yoo=yoo+2;
			}
		}
		if(yoo>=755 && yoo<=780 && xoo>35)//upper move toward right  // top upper right side pe move krti ha gariii(:
		{	if(flag==0)
			{
			xoo=xoo-2;
			}
		}

		if(xoo>=20 && xoo<=40 && yoo>39)//left  down move
		{	if(flag==0)
			{
			yoo=yoo-2;
			}
		}


		if (xoo>130 && xoo<700 && yoo>130 && yoo<160)//2nd orbit ki bottom wala
	  	 {	if(flag==0)
	  	 	{
	  	 	xoo=xoo+2;
	  	 	}
	  	 }

	  	 if(xoo>643 && xoo<680 && yoo>130 && yoo<720)// 2nd orbit ki right side wla
	  	 {	if(flag==0)
	  	 	{
	  	 	yoo=yoo+2;
	  	 	}
	  	 }

	  	 if(yoo>640 && yoo<670 && xoo<670 && xoo>110) // 2nd orbit ki top wala
	  	 {	if(flag==0)
	  	 	{
	  	 	xoo=xoo-2;
	  	 	}
	  	 }
	  	 
		if (xoo>109 && xoo<157 && yoo<665 && yoo>110)// 2nd orbit ki left side wala
	  	 {	if(flag==0)
	  	 	{
	  	 	yoo=yoo-2;
	  	 }}

	//3RD ORBITT WALA opponent ki garii ka
	  	 if(xoo<620 && yoo<260 && yoo>220 && xoo>230)
	  	 {	if(flag==0)
	  	 	{
	  	 	xoo=xoo+2;}
	  	 }

		if(xoo>540 && xoo<570 && yoo<610 && yoo>215)
	  	{	if(flag==0)
	  		{
	  		yoo=yoo+2;
	  		}
	  	
	  	}

	  	if(yoo<580 && yoo>528 && xoo>230 && xoo<565)
	  	{	if(flag==0)
	  		{
	  		xoo=xoo-2;
	  		}
	  	}
	  	
	  	if (xoo>225 && xoo<255 && yoo>220 && yoo<558)
	  	{	if(flag==0)
	  		{
	  		yoo=yoo-2;
	  		}
	  	}


	  	//opponent car in 4rth orbit
	  	if(xoo<500 && xoo>332 && yoo>315 && yoo<370)
		{	if(flag==0)
			{
			xoo=xoo+2;
			}
		}

		if(xoo>425 && xoo<510 && yoo>321 && yoo<455)
		{	if(flag==0)
			{
		yoo=yoo+2;
			}
		}
		if(xoo>328 && xoo<480 && yoo<456 && yoo>420)
		{	if(flag==0)
			{
		xoo=xoo-2;
			}
		}
		if(yoo>320 && yoo<459 && xoo>329 && xoo<365)
		{	if(flag==0)
			{
			yoo=yoo-2;
			}
		}
	}




	//ye player ki garri ko first orbit ma move krti ha
	if (yp>18 && yp<54 && xp>28)// neche last wale 
	{	if(flag==0)
		{
		xp=xp-2;
		}
	}
	if(xp>=28 && xp<50 && yp<762)//left uper
	{	if(flag==0)
		{
	yp=yp+2;
}
	}

	if(yp>738 && yp<780 && xp<758)//top 
	{
		if(flag==0)
		{
		xp=xp+2;
	}
	}
	if(xp>740 && xp<770 && yp>22)//right
	{	if(flag==0)
		{
		yp=yp-2;
		}

	}
//int xp=440;
//int yp=39;
  	 
//2nd orbit
  	 if (xp>140 && xp<700 && yp>130 && yp<160)//2nd orbit ki bottom wala
  	 {	if(flag==0)
  	 	{
  	 	xp=xp-2;
  	 }
  	 }
  	 if (xp>110 && xp<157 && yp<660 && yp>110)// 2nd orbit ki left side wala
  	 {	if(flag==0)
  	 	{
  	 	yp=yp+2;
  	 }
  	 }
  	 if(yp>640 && yp<670 && xp<670 && xp>110) // 2nd orbit ki top wala
  	 {	if(flag==0)
  	 	{
  	 	xp=xp+2;
  	 }
  	 }
  	 if(xp>643 && xp<680 && yp>130 && yp<720)// 2nd orbit ki right side wla
  	 {	if(flag==0)
  	 	{
  	 	yp=yp-2;

  	 }
  	 }


  	 //3RD ORBITT WALA
  	 if(xp<620 && yp<260 && yp>220 && xp>242)
  	 {	if(flag==0)
  	 	{
  	 	xp=xp-2;
  	 	}
  	 }

  	if (xp>225 && xp<255 && yp>220 && yp<558)
  	{	if(flag==0)
  		{
  		yp=yp+2;
  		}
  	}
  	if(yp<580 && yp>535 && xp>230 && xp<557)
  	{	if(flag==0)
  		{
  		xp=xp+2;
  		}
  	}
  	if(xp>540 && xp<570 && yp<610 && yp>215)
  	{	if(flag==0)
  		{
  		yp=yp-2;
  		}
  	
  	}



  	//4rd orbit


	if(xp<500 && xp>332 && yp>320 && yp<370)
	{	if(flag==0)
		{
		xp=xp-2;
		}
	}
	if(yp>320 && yp<450 && xp>329 && xp<365)
	{	if(flag==0)
		{
		yp=yp+2;
		}
	}

	if(xp>328 && xp<480 && yp<456 && yp>420)
	{	if(flag==0)
		{
	xp=xp+2;
	}
	}

	if(xp>425 && xp<510 && yp>321 && yp<455)
	{	if(flag==0)
		{
	yp=yp-2;
		}
	}


	if(xp<0)//it will not let the car to move outside in right gap box
	{	
		xp=30;
		
	}
	if(yp<0)//it will not let the car to move outside in bottom gap box
	{
		yp=38;
	}
	if(xp>775)//it will not let the car to move outside in left gap box
	{
		xp=xp-20;
	}

	if(yp>769)//it will not let the car to move outside in top gap box
	{
		yp=yp-20;
	}



//for computers car
if(xo<0)//it will not let the car to move outside in right gap box
{
	xo=30;
}
if(yo<0)//it will not let the car to move outside in bottom gap box
{
	yo=38;
}
if(xo>775)//it will not let the car to move outside in left gap box
{
	xo=xo-20;
}

if(yo>769)//it will not let the car to move outside in top gap box
{
	yo=yo-20;
}


//it will work only if two cars collide
if(level==1)
{
	if(xp-xo<20 && xp-xo>-20 && yp-yo<20 && yp-yo>-20)
	{
	lives--;
	score=0;
temp_score=score;


 xo=335;
 yo=39;
 xp=475;
yp=755;

	if(x[0]>1000)
	{
	x[0]=x[0]/1000;
	}
	if(x[1]>1000)
	{
	x[1]=x[1]/1000;
	}
	if(x[2]>1000)
	{
	x[2]=x[2]/1000;
	}
	if(x[3]>1000)
	{
	x[3]=x[3]/1000;
	}
	if(x[4]>1000)
	{
	x[4]=x[4]/1000;
	}
	if(x[5]>1000)
	{
	x[5]=x[5]/1000;
	}
	if(x[6]>1000)
	{
	x[6]=x[6]/1000;
	}
	if(x[7]>1000)
	{
	x[7]=x[7]/1000;
	}
	
	//second column
	if(xt[0]>1000)
	{
	xt[0]=xt[0]/1000;
	}

	if(xt[1]>1000)
	{
	xt[1]=xt[1]/1000;
	}

	if(xt[2]>1000)
	{
	xt[2]=xt[2]/1000;
	}

	if(xt[3]>1000)
	{
	xt[3]=xt[3]/1000;
	}

	if(xt[4]>1000)
	{
	xt[4]=xt[4]/1000;
	}

	if(xt[5]>1000)
	{
	xt[5]=xt[5]/1000;
	}

	if(xt[5]>1000)
	{
	xt[5]=xt[5]/1000;
	}

	if(xt[6]>1000)
	{
	xt[6]=xt[6]/1000;
	}

	if(xt[7]>1000)
	{
	xt[7]=xt[7]/1000;
	}
	//third colomn
	if(hh[0]>1000)
	{
	hh[0]=hh[0]/1000;
	}

	if(hh[1]>1000)
	{
	hh[1]=hh[1]/1000;
	}

	if(hh[2]>1000)
	{
	hh[2]=hh[2]/1000;
	}

	if(hh[3]>1000)
	{
	hh[3]=hh[3]/1000;
	}

	if(hh[4]>1000)
	{
	hh[4]=hh[4]/1000;
	}

	if(hh[5]>1000)
	{
	hh[5]=hh[5]/1000;
	}

	if(hh[6]>1000)
	{
	hh[6]=hh[6]/1000;
	}

	if(hh[7]>1000)
	{
	hh[7]=hh[7]/1000;
	}

	//fourth colomn
	if(xx[0]>1000)
	{
	xx[0]=xx[0]/1000;
	}

	if(xx[1]>1000)
	{
	xx[1]=xx[1]/1000;
	}
	if(xx[2]>1000)
	{
	xx[2]=xx[2]/1000;
	}

	if(xx[3]>1000)
	{
	xx[3]=xx[3]/1000;
	}

	if(xx[4]>1000)
	{
	xx[4]=xx[4]/1000;
	}

	if(xx[5]>1000)
	{
	xx[5]=xx[5]/1000;
	}

	if(xx[6]>1000)
	{
	xx[6]=xx[6]/1000;
	}

	if(xx[7]>1000)
	{
	xx[7]=xx[7]/1000;
	}
	  


//fifth
	

	if(aa[0]>1000)
	{
		aa[0]=aa[0]/1000;
	}
	
	if(aa[1]>1000)
	{
		aa[1]=aa[1]/1000;
	}

	if(aa[2]>1000)
	{
		aa[2]=aa[2]/1000;
	}


	if(aa[3]>1000)
	{
		aa[3]=aa[3]/1000;
	}

	if(aa[4]>1000)
	{
		aa[4]=aa[4]/1000;
	}

	if(aa[5]>1000)
	{
		aa[5]=aa[5]/1000;
	}

	if(aa[6]>1000)
	{
		aa[6]=aa[6]/1000;
	}

	if(aa[7]>1000)
	{
		aa[7]=aa[7]/1000;
	}

//sixth

	if(x6[0]>1000)
	{
	x6[0]=x6[0]/1000;
	}
	
	if(x6[1]>1000)
	{
	x6[1]=x6[1]/1000;
	}

	if(x6[2]>1000)
	{
	x6[2]=x6[2]/1000;
	}

	if(x6[3]>1000)
	{
	x6[3]=x6[3]/1000;
	}

	if(x6[4]>1000)
	{
	x6[4]=x6[4]/1000;
	}

	if(x6[5]>1000)
	{
	x6[5]=x6[5]/1000;
	}

	if(x6[6]>1000)
	{
	x6[6]=x6[6]/1000;
	}

	if(x6[7]>1000)
	{
	x6[7]=x6[7]/1000;
	}



	//sixth
	if(x7[0]>1000)
	{
	x7[0]=x7[0]/1000;
	}


	if(x7[1]>1000)
	{
	x7[1]=x7[1]/1000;
	}


	if(x7[2]>1000)
	{
	x7[2]=x7[2]/1000;
	}


	if(x7[3]>1000)
	{
	x7[3]=x7[3]/1000;
	}


	if(x7[4]>1000)
	{
	x7[4]=x7[4]/1000;
	}


	if(x7[5]>1000)
	{
	x7[5]=x7[5]/1000;
	}

	if(x7[6]>1000)
	{
	x7[6]=x7[6]/1000;
	}

	if(x7[7]>1000)
	{
	x7[7]=x7[7]/1000;
	}

	//last
	if(x8[0]>1000)
	{
	x8[0]=x8[0]/1000;
	}
	
	if(x8[1]>1000)
	{
	x8[1]=x8[1]/1000;
	}
	
	if(x8[2]>1000)
	{
	x8[2]=x8[2]/1000;
	}
	
	if(x8[3]>1000)
	{
	x8[3]=x8[3]/1000;
	}
	
	if(x8[4]>1000)
	{
	x8[4]=x8[4]/1000;
	}
	
	if(x8[5]>1000)
	{
	x8[5]=x8[5]/1000;
	}
	
	if(x8[6]>1000)
	{
	x8[6]=x8[6]/1000;
	}
	
	if(x8[7]>1000)
	{
	x8[7]=x8[7]/1000;
	}
	


}
}
else if(level==2)//for level two to recover the lost foods
{
	if(xp-xo<20 && xp-xo>-20 && yp-yo<20 && yp-yo>-20)
	{
	lives--;
	score=164;
	level=2;



 xo=335;
 yo=39;
 xp=475;
yp=755;

	if(xq[0]>1000)
	{
	xq[0]=xq[0]/1000;
	}
	if(xq[1]>1000)
	{
	xq[1]=xq[1]/1000;
	}
	if(xq[2]>1000)
	{
	xq[2]=xq[2]/1000;
	}
	if(xq[3]>1000)
	{
	xq[3]=xq[3]/1000;
	}
	if(xq[4]>1000)
	{
	xq[4]=xq[4]/1000;
	}
	if(xq[5]>1000)
	{
	xq[5]=xq[5]/1000;
	}
	if(xq[6]>1000)
	{
	xq[6]=xq[6]/1000;
	}
	if(xq[7]>1000)
	{
	xq[7]=xq[7]/1000;
	}
	
	//second column
	if(xtq[0]>1000)
	{
	xtq[0]=xtq[0]/1000;
	}

	if(xtq[1]>1000)
	{
	xtq[1]=xtq[1]/1000;
	}

	if(xtq[2]>1000)
	{
	xtq[2]=xtq[2]/1000;
	}

	if(xtq[3]>1000)
	{
	xtq[3]=xtq[3]/1000;
	}

	if(xtq[4]>1000)
	{
	xtq[4]=xtq[4]/1000;
	}

	if(xtq[5]>1000)
	{
	xtq[5]=xtq[5]/1000;
	}

	if(xtq[5]>1000)
	{
	xtq[5]=xtq[5]/1000;
	}

	if(xtq[6]>1000)
	{
	xtq[6]=xtq[6]/1000;
	}

	if(xtq[7]>1000)
	{
	xtq[7]=xt[7]/1000;
	}
	//third colomn
	if(hhq[0]>1000)
	{
	hhq[0]=hhq[0]/1000;
	}

	if(hhq[1]>1000)
	{
	hhq[1]=hhq[1]/1000;
	}

	if(hhq[2]>1000)
	{
	hhq[2]=hhq[2]/1000;
	}

	if(hhq[3]>1000)
	{
	hhq[3]=hhq[3]/1000;
	}

	if(hhq[4]>1000)
	{
	hhq[4]=hhq[4]/1000;
	}

	if(hhq[5]>1000)
	{
	hhq[5]=hhq[5]/1000;
	}

	if(hhq[6]>1000)
	{
	hhq[6]=hhq[6]/1000;
	}

	if(hhq[7]>1000)
	{
	hhq[7]=hhq[7]/1000;
	}

	//fourth colomn
	if(xxq[0]>1000)
	{
	xxq[0]=xxq[0]/1000;
	}

	if(xxq[1]>1000)
	{
	xxq[1]=xxq[1]/1000;
	}
	if(xxq[2]>1000)
	{
	xxq[2]=xxq[2]/1000;
	}

	if(xxq[3]>1000)
	{
	xxq[3]=xxq[3]/1000;
	}

	if(xxq[4]>1000)
	{
	xxq[4]=xxq[4]/1000;
	}

	if(xxq[5]>1000)
	{
	xxq[5]=xxq[5]/1000;
	}

	if(xxq[6]>1000)
	{
	xxq[6]=xxq[6]/1000;
	}

	if(xxq[7]>1000)
	{
	xxq[7]=xxq[7]/1000;
	}
	  


//fifth
	

	if(aaq[0]>1000)
	{
		aaq[0]=aaq[0]/1000;
	}
	
	if(aaq[1]>1000)
	{
		aaq[1]=aaq[1]/1000;
	}

	if(aaq[2]>1000)
	{
		aaq[2]=aaq[2]/1000;
	}


	if(aaq[3]>1000)
	{
		aaq[3]=aaq[3]/1000;
	}

	if(aaq[4]>1000)
	{
		aaq[4]=aaq[4]/1000;
	}

	if(aaq[5]>1000)
	{
		aaq[5]=aaq[5]/1000;
	}

	if(aaq[6]>1000)
	{
		aaq[6]=aaq[6]/1000;
	}

	if(aaq[7]>1000)
	{
		aaq[7]=aaq[7]/1000;
	}

//sixth

	if(x6q[0]>1000)
	{
	x6q[0]=x6q[0]/1000;
	}
	
	if(x6q[1]>1000)
	{
	x6q[1]=x6q[1]/1000;
	}

	if(x6q[2]>1000)
	{
	x6q[2]=x6q[2]/1000;
	}

	if(x6q[3]>1000)
	{
	x6q[3]=x6q[3]/1000;
	}

	if(x6q[4]>1000)
	{
	x6q[4]=x6q[4]/1000;
	}

	if(x6q[5]>1000)
	{
	x6q[5]=x6q[5]/1000;
	}

	if(x6q[6]>1000)
	{
	x6q[6]=x6q[6]/1000;
	}

	if(x6q[7]>1000)
	{
	x6q[7]=x6q[7]/1000;
	}



	//sixth
	if(x7q[0]>1000)
	{
	x7q[0]=x7q[0]/1000;
	}


	if(x7q[1]>1000)
	{
	x7q[1]=x7q[1]/1000;
	}


	if(x7q[2]>1000)
	{
	x7q[2]=x7q[2]/1000;
	}


	if(x7q[3]>1000)
	{
	x7q[3]=x7q[3]/1000;
	}


	if(x7q[4]>1000)
	{
	x7q[4]=x7q[4]/1000;
	}


	if(x7q[5]>1000)
	{
	x7q[5]=x7q[5]/1000;
	}

	if(x7q[6]>1000)
	{
	x7q[6]=x7q[6]/1000;
	}

	if(x7q[7]>1000)
	{
	x7q[7]=x7q[7]/1000;
	}

	//last
	if(x8q[0]>1000)
	{
	x8q[0]=x8q[0]/1000;
	}
	
	if(x8q[1]>1000)
	{
	x8q[1]=x8q[1]/1000;
	}
	
	if(x8q[2]>1000)
	{
	x8q[2]=x8q[2]/1000;
	}
	
	if(x8q[3]>1000)
	{
	x8q[3]=x8q[3]/1000;
	}
	
	if(x8q[4]>1000)
	{
	x8q[4]=x8q[4]/1000;
	}
	
	if(x8q[5]>1000)
	{
	x8q[5]=x8q[5]/1000;
	}
	
	if(x8q[6]>1000)
	{
	x8q[6]=x8q[6]/1000;
	}
	
	if(x8q[7]>1000)
	{
	x8q[7]=x8q[7]/1000;
	}
	



}
}


else if(level==3)//for level three to recover the lost foods
{
	if(xp-xo<20 && xp-xo>-20 && yp-yo<20 && yp-yo>-20)
	{
	lives--;
	score=328;
	level=3;




 xo=335; 
 yo=39;
 xp=475;
yp=755;

	if(xqa[0]>1000)
	{
	xqa[0]=xqa[0]/1000;
	}
	if(xqa[1]>1000)
	{
	xqa[1]=xqa[1]/1000;
	}
	if(xqa[2]>1000)
	{
	xqa[2]=xqa[2]/1000;
	}
	if(xqa[3]>1000)
	{
	xqa[3]=xqa[3]/1000;
	}
	if(xqa[4]>1000)
	{
	xqa[4]=xqa[4]/1000;
	}
	if(xqa[5]>1000)
	{
	xqa[5]=xqa[5]/1000;
	}
	if(xqa[6]>1000)
	{
	xqa[6]=xqa[6]/1000;
	}
	if(xqa[7]>1000)
	{
	xqa[7]=xqa[7]/1000;
	}
	
	//second column
	if(xtqa[0]>1000)
	{
	xtqa[0]=xtqa[0]/1000;
	}

	if(xtqa[1]>1000)
	{
	xtqa[1]=xtqa[1]/1000;
	}

	if(xtqa[2]>1000)
	{
	xtqa[2]=xtqa[2]/1000;
	}

	if(xtqa[3]>1000)
	{
	xtqa[3]=xtqa[3]/1000;
	}

	if(xtqa[4]>1000)
	{
	xtqa[4]=xtqa[4]/1000;
	}

	if(xtqa[5]>1000)
	{
	xtqa[5]=xtqa[5]/1000;
	}

	if(xtqa[5]>1000)
	{
	xtqa[5]=xtqa[5]/1000;
	}

	if(xtqa[6]>1000)
	{
	xtqa[6]=xtqa[6]/1000;
	}

	if(xtqa[7]>1000)
	{
	xtqa[7]=xt[7]/1000;
	}
	//third colomn
	if(hhqa[0]>1000)
	{
	hhqa[0]=hhqa[0]/1000;
	}

	if(hhqa[1]>1000)
	{
	hhqa[1]=hhqa[1]/1000;
	}

	if(hhqa[2]>1000)
	{
	hhqa[2]=hhqa[2]/1000;
	}

	if(hhqa[3]>1000)
	{
	hhqa[3]=hhqa[3]/1000;
	}

	if(hhqa[4]>1000)
	{
	hhqa[4]=hhqa[4]/1000;
	}

	if(hhqa[5]>1000)
	{
	hhqa[5]=hhqa[5]/1000;
	}

	if(hhqa[6]>1000)
	{
	hhqa[6]=hhqa[6]/1000;
	}

	if(hhqa[7]>1000)
	{
	hhqa[7]=hhqa[7]/1000;
	}

	//fourth colomn
	if(xxqa[0]>1000)
	{
	xxqa[0]=xxqa[0]/1000;
	}

	if(xxqa[1]>1000)
	{
	xxqa[1]=xxqa[1]/1000;
	}
	if(xxqa[2]>1000)
	{
	xxqa[2]=xxqa[2]/1000;
	}

	if(xxqa[3]>1000)
	{
	xxqa[3]=xxqa[3]/1000;
	}

	if(xxqa[4]>1000)
	{
	xxqa[4]=xxqa[4]/1000;
	}

	if(xxqa[5]>1000)
	{
	xxqa[5]=xxqa[5]/1000;
	}

	if(xxqa[6]>1000)
	{
	xxqa[6]=xxqa[6]/1000;
	}

	if(xxqa[7]>1000)
	{
	xxqa[7]=xxqa[7]/1000;
	}
	  


//fifth
	

	if(aaqa[0]>1000)
	{
		aaqa[0]=aaqa[0]/1000;
	}
	
	if(aaqa[1]>1000)
	{
		aaqa[1]=aaqa[1]/1000;
	}

	if(aaqa[2]>1000)
	{
		aaqa[2]=aaqa[2]/1000;
	}


	if(aaqa[3]>1000)
	{
		aaqa[3]=aaqa[3]/1000;
	}

	if(aaqa[4]>1000)
	{
		aaqa[4]=aaqa[4]/1000;
	}

	if(aaqa[5]>1000)
	{
		aaqa[5]=aaqa[5]/1000;
	}

	if(aaqa[6]>1000)
	{
		aaqa[6]=aaqa[6]/1000;
	}

	if(aaqa[7]>1000)
	{
		aaqa[7]=aaqa[7]/1000;
	}

//sixth

	if(x6qa[0]>1000)
	{
	x6qa[0]=x6qa[0]/1000;
	}
	
	if(x6qa[1]>1000)
	{
	x6qa[1]=x6qa[1]/1000;
	}

	if(x6qa[2]>1000)
	{
	x6qa[2]=x6qa[2]/1000;
	}

	if(x6qa[3]>1000)
	{
	x6qa[3]=x6qa[3]/1000;
	}

	if(x6qa[4]>1000)
	{
	x6qa[4]=x6qa[4]/1000;
	}

	if(x6qa[5]>1000)
	{
	x6qa[5]=x6qa[5]/1000;
	}

	if(x6qa[6]>1000)
	{
	x6qa[6]=x6qa[6]/1000;
	}

	if(x6qa[7]>1000)
	{
	x6qa[7]=x6qa[7]/1000;
	}



	//sixth
	if(x7qa[0]>1000)
	{
	x7qa[0]=x7qa[0]/1000;
	}


	if(x7qa[1]>1000)
	{
	x7qa[1]=x7qa[1]/1000;
	}


	if(x7qa[2]>1000)
	{
	x7qa[2]=x7qa[2]/1000;
	}


	if(x7qa[3]>1000)
	{
	x7qa[3]=x7qa[3]/1000;
	}


	if(x7qa[4]>1000)
	{
	x7qa[4]=x7qa[4]/1000;
	}


	if(x7qa[5]>1000)
	{
	x7qa[5]=x7qa[5]/1000;
	}

	if(x7qa[6]>1000)
	{
	x7qa[6]=x7qa[6]/1000;
	}

	if(x7qa[7]>1000)
	{
	x7qa[7]=x7qa[7]/1000;
	}

	//last
	if(x8qa[0]>1000)
	{
	x8qa[0]=x8qa[0]/1000;
	}
	
	if(x8qa[1]>1000)
	{
	x8qa[1]=x8qa[1]/1000;
	}
	
	if(x8qa[2]>1000)
	{
	x8qa[2]=x8qa[2]/1000;
	}
	
	if(x8qa[3]>1000)
	{
	x8qa[3]=x8qa[3]/1000;
	}
	
	if(x8qa[4]>1000)
	{
	x8qa[4]=x8qa[4]/1000;
	}
	
	if(x8qa[5]>1000)
	{
	x8qa[5]=x8qa[5]/1000;
	}
	
	if(x8qa[6]>1000)
	{
	x8qa[6]=x8qa[6]/1000;
	}
	
	if(x8qa[7]>1000)
	{
	x8qa[7]=x8qa[7]/1000;
	}
	

}
}
else if(level==4)//for level four to recover the lost foods
{
	if(xp-xo<20 && xp-xo>-20 && yp-yo<20 && yp-yo>-20)
	{
	lives--;
	score=492;
	level=4;



	
 xo=335;
 yo=39;
 xp=475;
yp=755;

	if(xqaa[0]>1000)
	{
	xqaa[0]=xqaa[0]/1000;
	}
	if(xqaa[1]>1000)
	{
	xqaa[1]=xqaa[1]/1000;
	}
	if(xqaa[2]>1000)
	{
	xqaa[2]=xqaa[2]/1000;
	}
	if(xqaa[3]>1000)
	{
	xqaa[3]=xqaa[3]/1000;
	}
	if(xqaa[4]>1000)
	{
	xqaa[4]=xqaa[4]/1000;
	}
	if(xqaa[5]>1000)
	{
	xqaa[5]=xqaa[5]/1000;
	}
	if(xqaa[6]>1000)
	{
	xqaa[6]=xqaa[6]/1000;
	}
	if(xqaa[7]>1000)
	{
	xqaa[7]=xqaa[7]/1000;
	}
	
	//second column
	if(xtqaa[0]>1000)
	{
	xtqaa[0]=xtqaa[0]/1000;
	}

	if(xtqaa[1]>1000)
	{
	xtqaa[1]=xtqaa[1]/1000;
	}

	if(xtqaa[2]>1000)
	{
	xtqaa[2]=xtqaa[2]/1000;
	}

	if(xtqaa[3]>1000)
	{
	xtqaa[3]=xtqaa[3]/1000;
	}

	if(xtqaa[4]>1000)
	{
	xtqaa[4]=xtqaa[4]/1000;
	}

	if(xtqaa[5]>1000)
	{
	xtqaa[5]=xtqaa[5]/1000;
	}

	if(xtqaa[5]>1000)
	{
	xtqaa[5]=xtqaa[5]/1000;
	}

	if(xtqaa[6]>1000)
	{
	xtqaa[6]=xtqaa[6]/1000;
	}

	if(xtqaa[7]>1000)
	{
	xtqaa[7]=xt[7]/1000;
	}
	//third colomn
	if(hhqaa[0]>1000)
	{
	hhqaa[0]=hhqaa[0]/1000;
	}

	if(hhqaa[1]>1000)
	{
	hhqaa[1]=hhqaa[1]/1000;
	}

	if(hhqaa[2]>1000)
	{
	hhqaa[2]=hhqaa[2]/1000;
	}

	if(hhqaa[3]>1000)
	{
	hhqaa[3]=hhqaa[3]/1000;
	}

	if(hhqaa[4]>1000)
	{
	hhqaa[4]=hhqaa[4]/1000;
	}

	if(hhqaa[5]>1000)
	{
	hhqaa[5]=hhqaa[5]/1000;
	}

	if(hhqaa[6]>1000)
	{
	hhqaa[6]=hhqaa[6]/1000;
	}

	if(hhqaa[7]>1000)
	{
	hhqaa[7]=hhqaa[7]/1000;
	}

	//fourth colomn
	if(xxqaa[0]>1000)
	{
	xxqaa[0]=xxqaa[0]/1000;
	}

	if(xxqaa[1]>1000)
	{
	xxqaa[1]=xxqaa[1]/1000;
	}
	if(xxqaa[2]>1000)
	{
	xxqaa[2]=xxqaa[2]/1000;
	}

	if(xxqaa[3]>1000)
	{
	xxqaa[3]=xxqaa[3]/1000;
	}

	if(xxqaa[4]>1000)
	{
	xxqaa[4]=xxqaa[4]/1000;
	}

	if(xxqaa[5]>1000)
	{
	xxqaa[5]=xxqaa[5]/1000;
	}

	if(xxqaa[6]>1000)
	{
	xxqaa[6]=xxqaa[6]/1000;
	}

	if(xxqaa[7]>1000)
	{
	xxqaa[7]=xxqaa[7]/1000;
	}
	  


//fifth
	

	if(aaqaa[0]>1000)
	{
		aaqaa[0]=aaqaa[0]/1000;
	}
	
	if(aaqaa[1]>1000)
	{
		aaqaa[1]=aaqaa[1]/1000;
	}

	if(aaqaa[2]>1000)
	{
		aaqaa[2]=aaqaa[2]/1000;
	}


	if(aaqaa[3]>1000)
	{
		aaqaa[3]=aaqaa[3]/1000;
	}

	if(aaqaa[4]>1000)
	{
		aaqaa[4]=aaqaa[4]/1000;
	}

	if(aaqaa[5]>1000)
	{
		aaqaa[5]=aaqaa[5]/1000;
	}

	if(aaqaa[6]>1000)
	{
		aaqaa[6]=aaqaa[6]/1000;
	}

	if(aaqaa[7]>1000)
	{
		aaqaa[7]=aaqaa[7]/1000;
	}

//sixth

	if(x6qaa[0]>1000)
	{
	x6qaa[0]=x6qaa[0]/1000;
	}
	
	if(x6qaa[1]>1000)
	{
	x6qaa[1]=x6qaa[1]/1000;
	}

	if(x6qaa[2]>1000)
	{
	x6qaa[2]=x6qaa[2]/1000;
	}

	if(x6qaa[3]>1000)
	{
	x6qaa[3]=x6qaa[3]/1000;
	}

	if(x6qaa[4]>1000)
	{
	x6qaa[4]=x6qaa[4]/1000;
	}

	if(x6qaa[5]>1000)
	{
	x6qaa[5]=x6qaa[5]/1000;
	}

	if(x6qaa[6]>1000)
	{
	x6qaa[6]=x6qaa[6]/1000;
	}

	if(x6qaa[7]>1000)
	{
	x6qaa[7]=x6qaa[7]/1000;
	}



	//sixth
	if(x7qaa[0]>1000)
	{
	x7qaa[0]=x7qaa[0]/1000;
	}


	if(x7qaa[1]>1000)
	{
	x7qaa[1]=x7qaa[1]/1000;
	}


	if(x7qaa[2]>1000)
	{
	x7qaa[2]=x7qaa[2]/1000;
	}


	if(x7qaa[3]>1000)
	{
	x7qaa[3]=x7qaa[3]/1000;
	}


	if(x7qaa[4]>1000)
	{
	x7qaa[4]=x7qaa[4]/1000;
	}


	if(x7qaa[5]>1000)
	{
	x7qaa[5]=x7qaa[5]/1000;
	}

	if(x7qaa[6]>1000)
	{
	x7qaa[6]=x7qaa[6]/1000;
	}

	if(x7qaa[7]>1000)
	{
	x7qaa[7]=x7qaa[7]/1000;
	}

	//last
	if(x8qaa[0]>1000)
	{
	x8qaa[0]=x8qaa[0]/1000;
	}
	
	if(x8qaa[1]>1000)
	{
	x8qaa[1]=x8qaa[1]/1000;
	}
	
	if(x8qaa[2]>1000)
	{
	x8qaa[2]=x8qaa[2]/1000;
	}
	
	if(x8qaa[3]>1000)
	{
	x8qaa[3]=x8qaa[3]/1000;
	}
	
	if(x8qaa[4]>1000)
	{
	x8qaa[4]=x8qaa[4]/1000;
	}
	
	if(x8qaa[5]>1000)
	{
	x8qaa[5]=x8qaa[5]/1000;
	}
	
	if(x8qaa[6]>1000)
	{
	x8qaa[6]=x8qaa[6]/1000;
	}
	
	if(x8qaa[7]>1000)
	{
	x8qaa[7]=x8qaa[7]/1000;
	}
	





}


//it works for the second computer car


if(xp-xoo<20 && xp-xoo>-20 && yp-yoo<20 && yp-yoo>-20)
	{
	lives--;
	score=492;
	level=4;




 xo=335;
 yo=39;
 xp=475;
yp=755;

	if(xqaa[0]>1000)
	{
	xqaa[0]=xqaa[0]/1000;
	}
	if(xqaa[1]>1000)
	{
	xqaa[1]=xqaa[1]/1000;
	}
	if(xqaa[2]>1000)
	{
	xqaa[2]=xqaa[2]/1000;
	}
	if(xqaa[3]>1000)
	{
	xqaa[3]=xqaa[3]/1000;
	}
	if(xqaa[4]>1000)
	{
	xqaa[4]=xqaa[4]/1000;
	}
	if(xqaa[5]>1000)
	{
	xqaa[5]=xqaa[5]/1000;
	}
	if(xqaa[6]>1000)
	{
	xqaa[6]=xqaa[6]/1000;
	}
	if(xqaa[7]>1000)
	{
	xqaa[7]=xqaa[7]/1000;
	}
	
	//second column
	if(xtqaa[0]>1000)
	{
	xtqaa[0]=xtqaa[0]/1000;
	}

	if(xtqaa[1]>1000)
	{
	xtqaa[1]=xtqaa[1]/1000;
	}

	if(xtqaa[2]>1000)
	{
	xtqaa[2]=xtqaa[2]/1000;
	}

	if(xtqaa[3]>1000)
	{
	xtqaa[3]=xtqaa[3]/1000;
	}

	if(xtqaa[4]>1000)
	{
	xtqaa[4]=xtqaa[4]/1000;
	}

	if(xtqaa[5]>1000)
	{
	xtqaa[5]=xtqaa[5]/1000;
	}

	if(xtqaa[5]>1000)
	{
	xtqaa[5]=xtqaa[5]/1000;
	}

	if(xtqaa[6]>1000)
	{
	xtqaa[6]=xtqaa[6]/1000;
	}

	if(xtqaa[7]>1000)
	{
	xtqaa[7]=xt[7]/1000;
	}
	//third colomn
	if(hhqaa[0]>1000)
	{
	hhqaa[0]=hhqaa[0]/1000;
	}

	if(hhqaa[1]>1000)
	{
	hhqaa[1]=hhqaa[1]/1000;
	}

	if(hhqaa[2]>1000)
	{
	hhqaa[2]=hhqaa[2]/1000;
	}

	if(hhqaa[3]>1000)
	{
	hhqaa[3]=hhqaa[3]/1000;
	}

	if(hhqaa[4]>1000)
	{
	hhqaa[4]=hhqaa[4]/1000;
	}

	if(hhqaa[5]>1000)
	{
	hhqaa[5]=hhqaa[5]/1000;
	}

	if(hhqaa[6]>1000)
	{
	hhqaa[6]=hhqaa[6]/1000;
	}

	if(hhqaa[7]>1000)
	{
	hhqaa[7]=hhqaa[7]/1000;
	}

	//fourth colomn
	if(xxqaa[0]>1000)
	{
	xxqaa[0]=xxqaa[0]/1000;
	}

	if(xxqaa[1]>1000)
	{
	xxqaa[1]=xxqaa[1]/1000;
	}
	if(xxqaa[2]>1000)
	{
	xxqaa[2]=xxqaa[2]/1000;
	}

	if(xxqaa[3]>1000)
	{
	xxqaa[3]=xxqaa[3]/1000;
	}

	if(xxqaa[4]>1000)
	{
	xxqaa[4]=xxqaa[4]/1000;
	}

	if(xxqaa[5]>1000)
	{
	xxqaa[5]=xxqaa[5]/1000;
	}

	if(xxqaa[6]>1000)
	{
	xxqaa[6]=xxqaa[6]/1000;
	}

	if(xxqaa[7]>1000)
	{
	xxqaa[7]=xxqaa[7]/1000;
	}
	  


//fifth
	

	if(aaqaa[0]>1000)
	{
		aaqaa[0]=aaqaa[0]/1000;
	}
	
	if(aaqaa[1]>1000)
	{
		aaqaa[1]=aaqaa[1]/1000;
	}

	if(aaqaa[2]>1000)
	{
		aaqaa[2]=aaqaa[2]/1000;
	}


	if(aaqaa[3]>1000)
	{
		aaqaa[3]=aaqaa[3]/1000;
	}

	if(aaqaa[4]>1000)
	{
		aaqaa[4]=aaqaa[4]/1000;
	}

	if(aaqaa[5]>1000)
	{
		aaqaa[5]=aaqaa[5]/1000;
	}

	if(aaqaa[6]>1000)
	{
		aaqaa[6]=aaqaa[6]/1000;
	}

	if(aaqaa[7]>1000)
	{
		aaqaa[7]=aaqaa[7]/1000;
	}

//sixth

	if(x6qaa[0]>1000)
	{
	x6qaa[0]=x6qaa[0]/1000;
	}
	
	if(x6qaa[1]>1000)
	{
	x6qaa[1]=x6qaa[1]/1000;
	}

	if(x6qaa[2]>1000)
	{
	x6qaa[2]=x6qaa[2]/1000;
	}

	if(x6qaa[3]>1000)
	{
	x6qaa[3]=x6qaa[3]/1000;
	}

	if(x6qaa[4]>1000)
	{
	x6qaa[4]=x6qaa[4]/1000;
	}

	if(x6qaa[5]>1000)
	{
	x6qaa[5]=x6qaa[5]/1000;
	}

	if(x6qaa[6]>1000)
	{
	x6qaa[6]=x6qaa[6]/1000;
	}

	if(x6qaa[7]>1000)
	{
	x6qaa[7]=x6qaa[7]/1000;
	}



	//sixth
	if(x7qaa[0]>1000)
	{
	x7qaa[0]=x7qaa[0]/1000;
	}


	if(x7qaa[1]>1000)
	{
	x7qaa[1]=x7qaa[1]/1000;
	}


	if(x7qaa[2]>1000)
	{
	x7qaa[2]=x7qaa[2]/1000;
	}


	if(x7qaa[3]>1000)
	{
	x7qaa[3]=x7qaa[3]/1000;
	}


	if(x7qaa[4]>1000)
	{
	x7qaa[4]=x7qaa[4]/1000;
	}


	if(x7qaa[5]>1000)
	{
	x7qaa[5]=x7qaa[5]/1000;
	}

	if(x7qaa[6]>1000)
	{
	x7qaa[6]=x7qaa[6]/1000;
	}

	if(x7qaa[7]>1000)
	{
	x7qaa[7]=x7qaa[7]/1000;
	}

	//last
	if(x8qaa[0]>1000)
	{
	x8qaa[0]=x8qaa[0]/1000;
	}
	
	if(x8qaa[1]>1000)
	{
	x8qaa[1]=x8qaa[1]/1000;
	}
	
	if(x8qaa[2]>1000)
	{
	x8qaa[2]=x8qaa[2]/1000;
	}
	
	if(x8qaa[3]>1000)
	{
	x8qaa[3]=x8qaa[3]/1000;
	}
	
	if(x8qaa[4]>1000)
	{
	x8qaa[4]=x8qaa[4]/1000;
	}
	
	if(x8qaa[5]>1000)
	{
	x8qaa[5]=x8qaa[5]/1000;
	}
	
	if(x8qaa[6]>1000)
	{
	x8qaa[6]=x8qaa[6]/1000;
	}
	
	if(x8qaa[7]>1000)
	{
	x8qaa[7]=x8qaa[7]/1000;
	}
	





}
}


//for cars to chase the player car

if(level==1)
{



	//lower gap
	if(xo>350 && xo<470 && yp>110 && yp<410 &&  yp-yo<300 && yo>0 &&yo<110 && yp-yo>100 && score>5)
	{
		yo=yo+100;
	}

	if(xo>350 && xo<470 && yp>410 && yp<620 && yo>110 && yo<210 && yp-yo<250 && yp-yo>100 && score>5)
	{
		yo=yo+100;
	}  

	if(xo>350 && xo<470 && yo>210 && yo<310 && yp<210  && yo-yp<300 && yo-yp>100)
	{
		yo=yo-100;
	} 

	if(xo>350 && xo<470 && yo<210 && yo>110 && yp<110 && yo-yp>90 && yo-yp<200)
	{
		yo=yo-100;
	} 

	//upper gab

	if(yo>720 && yp>450 && yp<720 && xo>350 && xo<470 )
	{
		yo=yo-100;
	}
	if(yo>620 && yo<720 && yp>720 && yp<800 && xo>350 && xo<470)
	{
		yo=yo+100;
	}
	if(yo<720 && yo>620 && yp>110 && yp<420 && xo>350 && xo<470)
	{
		yo=yo-100;
	}

	if(yo>430 && yo<620 && yp>430 && yp<720 && xo>350 && xo<470)
	{
	yo=yo+100;
	}
}

else if(level==2)
{



	//lower gap
	if(xo>350 && xo<470 && yp>110 && yp<410 &&  yp-yo<300 && yp-yo>100 && score>5)
	{
		yo=yo+100;
	}

	if(xo>350 && xo<470 && yp>310 && yp<620 && yo>110 && yo<210 && yp-yo<250 && yp-yo>100 && score>5)
	{
		yo=yo+100;
	}  

	if(xo>350 && xo<470 && yo>210 && yo<310 && yp<210  && yo-yp<300 && yo-yp>100)
	{
		yo=yo-100;
	} 

	if(xo>350 && xo<470 && yo<210 && yo>110 && yp<110 && yo-yp>90 && yo-yp<200)
	{
		yo=yo-100;
	} 

	//upper gab

	if(yo>720 && yp>450 && yp<720 && xo>350 && xo<470 )
	{
		yo=yo-100;
	}
	if(yo>620 && yo<720 && yp>720 && yp<800 && xo>350 && xo<470)
	{
		yo=yo+100;
	}
	if(yo<720 && yo>620 && yp>110 && yp<420 && xo>350 && xo<470)
	{
		yo=yo-100;
	}

	if(yo>430 && yo<620 && yp>430 && yp<720 && xo>350 && xo<470)
	{
	yo=yo+100;
	}
	//right gab
	if(yo>350 && yo<480 && xo>720 && xp>400 && xp<720)
	{
		xo=xo-100;
	}
	if(yo>350 && yo<480 && xo>620 && xo<720 && xp>100 && xp<400)
	{
		xo=xo-100;
	}
	if(xo>520 && xo<620 && yo>350 && yo<480 && xp<580)

	{
		xo=xo+100;
	}
	if(xo>620 && xo<720 && yo>350 && yo<480 && xp<800)

	{
		xo=xo+100;
	}

	//left gap

	if(xo>0 && xo<100 && yo>350 && yo<480 && xp<400 && xp>100)

	{
		xo=xo+100;
	}
	if(xo>100 && xo<200 && yo>350 && yo<480 && xp>400 && xp<720)
	{
		xo=xo+100;
	}

	if(xo>100 && xo<200 && yo>350 && yo<480 && xp>0 && xp<100)
	{
	xo=xo-100;
	}
	if(xo>200 && xo<300 && yo<480 && yo>350 && xp>100 && xp<300)
	{
		xo=xp-100;
	}
}

else if(level==3)
{


	//lower gap
	if(xo>350 && xo<470 && yp>110 && yp<410 &&  yp-yo<300 && yp-yo>100 && score>5)
	{
		yo=yo+100;
	}

	if(xo>350 && xo<470 && yp>310 && yp<620 && yo>110 && yo<210 && yp-yo<250 && yp-yo>100 && score>5)
	{
		yo=yo+100;
	}  

	if(xo>350 && xo<470 && yo>210 && yo<310 && yp<210  && yo-yp<300 && yo-yp>100)
	{
		yo=yo-100;
	} 

	if(xo>350 && xo<470 && yo<210 && yo>110 && yp<110 && yo-yp>90 && yo-yp<200)
	{
		yo=yo-100;
	} 

	//upper gab

	if(yo>720 && yp>450 && yp<720 && xo>350 && xo<470 )
	{
		yo=yo-100;
	}
	if(yo>620 && yo<720 && yp>720 && yp<800 && xo>350 && xo<470)
	{
		yo=yo+100;
	}
	if(yo<720 && yo>620 && yp>110 && yp<420 && xo>350 && xo<470)
	{
		yo=yo-100;
	}

	if(yo>430 && yo<620 && yp>430 && yp<720 && xo>350 && xo<470)
	{
	yo=yo+100;
	}
	//right gab
	if(yo>350 && yo<480 && xo>720 && xp>400 && xp<720)
	{
		xo=xo-100;
	}
	if(yo>350 && yo<480 && xo>620 && xo<720 && xp>100 && xp<400)
	{
		xo=xo-100;
	}
	if(xo>520 && xo<620 && yo>350 && yo<480 && xp<580)

	{
		xo=xo+100;
	}
	if(xo>620 && xo<720 && yo>350 && yo<480 && xp<800)

	{
		xo=xo+100;
	}

	//left gap

	if(xo>0 && xo<100 && yo>350 && yo<480 && xp<400 && xp>100)

	{
		xo=xo+100;
	}
	if(xo>100 && xo<200 && yo>350 && yo<480 && xp>400 && xp<720)
	{
		xo=xo+100;
	}

	if(xo>100 && xo<200 && yo>350 && yo<480 && xp>0 && xp<100)
	{
	xo=xo-100;
	}
	if(xo>200 && xo<300 && yo<480 && yo>350 && xp>100 && xp<300)
	{
		xo=xp-100;
	}
}
else if(level==4)
{



	//lower gap
	if(xo>350 && xo<470 && yp>110 && yp<410 &&  yp-yo<300 && yp-yo>100 && score>5)
	{
		yo=yo+100;
	}

	if(xo>350 && xo<470 && yp>310 && yp<620 && yo>110 && yo<210 && yp-yo<250 && yp-yo>100 && score>5)
	{
		yo=yo+100;
	}  

	if(xo>350 && xo<470 && yo>210 && yo<310 && yp<210  && yo-yp<300 && yo-yp>100)
	{
		yo=yo-100;
	} 

	if(xo>350 && xo<470 && yo<210 && yo>110 && yp<110 && yo-yp>90 && yo-yp<200)
	{
		yo=yo-100;
	} 

	//upper gab

	if(yo>720 && yp>450 && yp<720 && xo>350 && xo<470 )
	{
		yo=yo-100;
	}
	if(yo>620 && yo<720 && yp>720 && yp<800 && xo>350 && xo<470)
	{
		yo=yo+100;
	}
	if(yo<720 && yo>620 && yp>110 && yp<420 && xo>350 && xo<470)
	{
		yo=yo-100;
	}

	if(yo>430 && yo<620 && yp>430 && yp<720 && xo>350 && xo<470)
	{
	yo=yo+100;
	}
	//right gab
	if(yo>350 && yo<480 && xo>720 && xp>400 && xp<720)
	{
		xo=xo-100;
	}
	if(yo>350 && yo<480 && xo>620 && xo<720 && xp>100 && xp<400)
	{
		xo=xo-100;
	}
	if(xo>520 && xo<620 && yo>350 && yo<480 && xp<580)

	{
		xo=xo+100;
	}
	if(xo>620 && xo<720 && yo>350 && yo<480 && xp<800)

	{
		xo=xo+100;
	}

	//left gap

	if(xo>0 && xo<100 && yo>350 && yo<480 && xp<400 && xp>100)

	{
		xo=xo+100;
	}
	if(xo>100 && xo<200 && yo>350 && yo<480 && xp>400 && xp<720)
	{
		xo=xo+100;
	}

	if(xo>100 && xo<200 && yo>350 && yo<480 && xp>0 && xp<100)
	{
	xo=xo-100;
	}
	if(xo>200 && xo<300 && yo<480 && yo>350 && xp>100 && xp<300)
	{
		xo=xp-100;
	}




	//the computer 2 car
	if(xoo>350 && xoo<470 && yp>110 && yp<410 &&  yp-yoo<300 && yp-yoo>100 && score>5)
	{
		yoo=yoo+100;
	}

	if(xoo>350 && xoo<470 && yp>310 && yp<620 && yoo>110 && yoo<210 && yp-yoo<250 && yp-yoo>100 && score>5)
	{
		yoo=yoo+100;
	}  

	if(xoo>350 && xoo<470 && yoo>210 && yoo<310 && yp<210  && yoo-yp<300 && yoo-yp>100)
	{
		yoo=yoo-100;
	} 

	if(xoo>350 && xoo<470 && yoo<210 && yoo>110 && yp<110 && yoo-yp>90 && yoo-yp<200)
	{
		yoo=yoo-100;
	} 

	//upper gab

	if(yoo>720 && yp>450 && yp<720 && xoo>350 && xoo<470 )
	{
		yoo=yoo-100;
	}
	if(yoo>620 && yoo<720 && yp>720 && yp<800 && xoo>350 && xoo<470)
	{
		yoo=yoo+100;
	}
	if(yoo<720 && yoo>620 && yp>110 && yp<420 && xoo>350 && xoo<470)
	{
		yoo=yoo-100;
	}

	if(yoo>430 && yoo<620 && yp>430 && yp<720 && xoo>350 && xoo<470)
	{
	yoo=yoo+100;
	}
	//right gab
	if(yoo>350 && yoo<480 && xoo>720 && xp>400 && xp<720)
	{
		xoo=xoo-100;
	}
	if(yoo>350 && yoo<480 && xoo>620 && xoo<720 && xp>100 && xp<400)
	{
		xoo=xoo-100;
	}
	if(xoo>520 && xoo<620 && yoo>350 && yoo<480 && xp<580)

	{
		xoo=xoo+100;
	}
	if(xoo>620 && xoo<720 && yoo>350 && yoo<480 && xp<800)

	{
		xoo=xoo+100;
	}

	//left gap

	if(xoo>0 && xoo<100 && yoo>350 && yoo<480 && xp<400 && xp>100)

	{
		xoo=xoo+100;
	}
	if(xoo>100 && xoo<200 && yoo>350 && yoo<480 && xp>400 && xp<720)
	{
		xoo=xoo+100;
	}

	if(xoo>100 && xoo<200 && yoo>350 && yoo<480 && xp>0 && xp<100)
	{
	xoo=xoo-100;
	}
	if(xoo>200 && xoo<300 && yoo<480 && yoo>350 && xp>100 && xp<300)
	{
		xoo=xp-100;
	}
}
/*
if(xo>350 && xo<470 && yo>720 && yo<820 &&  yo-yp<350 && yo-yp>-350)
{
	yo=yo-100;
}

if(xo>350 && xo<470 && yo>620 && yo<720 && yo-yp<150 && yo-yp>-150)
{
	yo=yo-100;
}

if(xo>350 && xo<470 && yo>620 && yo<720 && yo-yp<250 && yo-yp>-250 && xo-xp<300 && xo-xp>-300)
{
	yo=yo+100;
}
*/










//upper
//highscore
if(score>highscore)
{
	highscore=score;
}
//level will increase if car eat all the rewards
	
//last orbit 
/*
  	if(xp<500 && yp<370 && yp>335 && xp>337 )
  	{
  		xp=xp-1;
  	}if(score==64)
	{
		level++;
		score=score+100;
	}

  	
  	if(xp>300 && xp<370 && yp>310 && yp<470)
  	{
  		yp=yp+1;
  	}

  	if(yp<420 && yp>370 && xp>300 && xp<470)
  	{
  		xp=xp+1;
  	}

  	if(xp>370 && xp<510 && yp<430 && yp>330)
  	{
  		yp=yp-1;
  	}
	// implement your functionality here
	// once again we tell the library to call our Timer function after next 1000/FPS*/
	glutTimerFunc(1.0, Timer, 0);
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {

	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) 
{

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */

int main(int argc, char*argv[]) 
{


	//b = newBoard(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 870; // i have set my window size to be 800 x 600

	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow(""); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels..	
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);
	//Timer(1000);
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	//GameDisplay();


	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
	


}
#endif /* AsteroidS_CPP_ */
