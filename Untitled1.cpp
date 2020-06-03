#include "iGraphics.h"
#include "gl.h"
#include<windows.h>
#include<iostream>
using namespace std;
#include<commdlg.h>
#include<time.h>

double pi=acos(-1)/180;


int swidth,sheight;
//for leaderboard
typedef struct{
    char name[15];
    double time;
} leaderboard;

leaderboard lb[3][10];

//for time calculating
clock_t timestart;
clock_t timestop;
double timeelasped=0;
char showtime[10];//in game screen
char ttime[30];//in win screen

//for key overflowing
int key=1;
int hint=0;
int help=0;
int helpkey=0;

//for mouse overflowing
int mouse=0;
char mo[20];//mouse co-ordinate

//game mode
int singleplayer=0,dragrace=0;
int newmatch=0,menu=0,carselect=0,leaderb=0,leadermode=0,loading=1,gameload=0,about=0;
int dragracecarselect=0;
int menukey[8]={1,0,0,0,0,0,0,0};
int pausekey[4]={1,0,0,0};
int settingkey[2]={1,0};
int win=0,lose=0,llose=0,enter=0,pause=0;//enter actually denote space :( :(
int con_exit=0,exitkey=0;
long hints;


int img[200][100][3],height,width;//for opponent car
int mycarimg[200][100][3];//for my car
char *file_name;//for opponent car

double rx,ry;//Road

//my cars variable
double carx[5]={650,700,750,0,0},cary[5]={400,400,400,0,0};
double angle=90,motion=90;//Car
double v,acc=0,iv;
int mycarloop=0;//for tracking
double vx,vy;//system velocity==car velocity
double afterangle=0;//camera

//opponenet cars variable
double op1x[5]={rx+450,rx+500,rx+550,0,0},op1y[5]={ry+400,ry+400,ry+400,0,0};
double op1v,angleop1=90,op1motion=90,l=0;
double op1vx,op1vy,t=0;

//speedometer
double smangle=225;//speedometer
char speedm[10]="0.00 MPH";

//sound
bool play1=false,play2=false;//car start & speed sound
int sounds=1;

//leaderboard update
int takename=0,leaderindx;
int getname=0;

//game saving
int savegame=0;

// cars characteristic
int yellow=1,red=0,black=0;//My Car
int op1carcolor=0;//Opponent car
double speed,acceleration,drift;
double op1speed,op1acceleration,op1drift;
double speedarray[4]={22,21,22,23};
double accelerationarray[4]={1,1,0.9,0.8};
double driftarray[4]={.7,.65,.6,.8};//handle

//level
int level=0,selectlevel=0;
int lvlsp[3]={1,2.5,3};
int lvlacc[3]={0.3,0.4,0.5};

//loading screen variable
int loadingx=0,loadingy;

//leaderboard save
void leaderboardsave();
void sound();

int laodingimg[12][900][1600][3];
int menuimg[900][1600][3];
int leaderboardimg[900][1600][3];
int pauseimg[900][1600][3];
int aboutimg[900][1600][3];

void printimg(int img[900][1600][3]){
    for(int i=0;i<1600;i++){
        for(int j=0;j<900;j++){
                iSetColor(img[j][i][0],img[j][i][1],img[j][i][2]);
                iPoint(i,j,1);
        }
    }
}

#include"mainmenu.h"
#include"opp1car.h"
#include"mycar.h"
#include"Drag Race.h"
#include"sound.h"
#include"firsttrack.h"
#include"savegame.h"


void iDraw(){
    iClear();
    if(loading)iDrawLoading();
    else if(menu)
    iDrawMain();
    else if(pause)
    iDrawPause();
    else if(singleplayer){
        iRotate(carx[1],cary[1],90-angle);
        iDrawGallery();
        iDrawRoad();
        if(mycarloop==3)iDrawEndLine();
        iDrawCar();
        iDrawOpponent1();
        iUnRotate();
        iRotate(carx[1],cary[1],afterangle);
        for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            if(mycarimg[j][i][0]!=0){
            iSetColor(mycarimg[j][i][0],mycarimg[j][i][1],mycarimg[j][i][2]);
            iPoint(i+carx[1]-50,j+cary[1],2.5);
            }
        }
        }
        iUnRotate();
        if(enter){
            iDrawSpedometer();
            timestop=clock();
            timeelasped=timeelasped+(double)(timestop-timestart)/CLOCKS_PER_SEC;
            sprintf(showtime,"%.2lf s",timeelasped);
            timestart=clock();
            iSetColor(255,255,255);
            iText(1450,800,showtime,GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }
    else if(dragrace){
        iDrawDragRoad();
    }
    else if(leaderb)iDrawLeaderboard();
    else if(carselect){
        iCarSelect();
        if(level)iLevel();
    }
    else if(dragracecarselect)iDragCarSelection();
    else if(win==1)iWin();
    else if(lose==1)iLose();
    else if(about)iDrawAbout();
    if(takename)iDrawTakeName();
    if(con_exit)iExit();
    if(!menu && !loading){
        if(singleplayer || (dragrace && (!drp1 || !drp2)))iShowBMP2(20,820,"BMP\\pausekey.bmp",0);
        else iShowBMP2(20,830,"BMP\\esc.bmp",0);
    }
    if(help)
    {
        if(helpkey==0)
            iShowBMP(0,0,"BMP\\helpscreen1.bmp");
        else if(helpkey==1)
            iShowBMP(0,0,"BMP\\helpscreen2.bmp");
        else if(helpkey==2)
            iShowBMP(0,0,"BMP\\helpscreen3.bmp");
    }
    if(gameload)iDrawGameLoad();
}

void carcharcteristic(){
    int r;
    if(yellow)r=1;
    else if(red)r=2;
    else if(black)r=3;
    speed=speedarray[r];
    acceleration=accelerationarray[r];
    drift=driftarray[r];
}
void newmatchfunc(){
    win=0;
    lose=0;
    rx=0;
    ry=0;
    afterangle=0;
    op1x[0]=rx+450;
    op1x[1]=rx+500;
    op1x[2]=rx+550;
    op1y[0]=ry+400;
    op1y[1]=ry+400;
    op1y[2]=ry+400;
    v=0;
    smangle=180;
    angle=90;
    motion=90;
    carx[0]=650;
    carx[1]=700;
    carx[2]=750;
    cary[0]=400;
    cary[1]=400;
    cary[2]=400;
    angleop1=90;
    op1v=0;
    op1motion=90;
    enter=0;
    llose=0;
    l=0;
    mycarloop=0;
    carcharcteristic();
    timestart=clock();
    timestop=clock();
}

void normalrace(){
    carselect=1;
    menu=0;
    menumusic();
    carselectmusic();
}

/*
    keyboard codes are in keyboard.h
*/

#include"keyboard.h"


/*
    mouse codes are in keyboard.h
*/

#include"mouse.h"
void leaderboardsave(){
    int j;
    for(j=0;j<3;j++){
    FILE *fp;
    if(j==0){
        if((fp=fopen("Data\\easy.txt","w"))==NULL)
        {
            printf("Error");
            exit(1);
        }
    }
    if(j==1){
        if((fp=fopen("Data\\medium.txt","w"))==NULL)
        {
            printf("Error");
            exit(1);
        }
    }
    if(j==2){
        if((fp=fopen("Data\\hard.txt","w"))==NULL)
        {
            printf("Error");
            exit(1);
        }
    }
    int i;
    for(i=0;i<10;i++){
        fprintf(fp,"%s %lf\n",lb[j][i].name,lb[j][i].time);
        //printf("%s %lf\n",lb[j][i].name,lb[j][i].time);
    }
    fclose(fp);
    }
}


Fileopen(){

    int j;
    for(j=0;j<3;j++){
    FILE *fp;
    if(j==0){
        if((fp=fopen("Data\\easy.txt","r"))==NULL)
        {
            printf("Error");
            exit(1);
        }
    }
    if(j==1){
        if((fp=fopen("Data\\medium.txt","r"))==NULL)
        {
            printf("Error");
            exit(1);
        }
    }
    if(j==2){
        if((fp=fopen("Data\\hard.txt","r"))==NULL)
        {
            printf("Error");
            exit(1);
        }
    }
    int i;
    for(i=0;i<10;i++){
        fscanf(fp,"%s %lf",&lb[j][i].name,&lb[j][i].time);
        //printf("%s %lf\n",lb[j][i].name,lb[j][i].time);
    }
    fclose(fp);
    }
}
void loadingfunc(){
    loadingx+=20;
    loadingy+=1;
    if(loadingy>30)loadingy=1;
    if(loadingx>1590){
        menu=1;
        loading=0;
        loadingx=0;
        loadingy=0;
        menumusic();
        iPauseTimer(3);
    }
}

void loadinggame(){
    loadingx+=20;
    loadingy+=1;
    if(loadingy>30)loadingy=1;
    if(loadingx>1590){
        if(menukey[0])loadnormalgame();
        else if(menukey[1])singleplayer=1;
        else if(menukey[2])dragrace=1;
        gameload=0;
        loadingx=0;
        loadingy=0;
        enter=0;
        iPauseTimer(4);
    }
}


void loadimg(int img[900][1600][3],char *filename){
    AUX_RGBImageRec *TextureImage;
    TextureImage = auxDIBImageLoad(filename);
    int i,j,k;
    int realwidth = TextureImage->sizeX;
    int realheight = TextureImage->sizeY;
    realwidth>1600?width=1600:width=realwidth;
    realheight>900?height=900:height=realheight;
    for(i=0;i<height;i++)
        for(j=0;j<width;j++)
            for(k=2;k>=0;k--)
                img[i][j][k]=TextureImage->data[3*i*realwidth+3*j+k];


    free(TextureImage->data);
    free(TextureImage);
}

int main(){

    iSetTimer(75,velocity);
    iSetTimer(75,opp1velocity);
    iSetTimer(10,movement);
    iSetTimer(5,loadingfunc);
    iSetTimer(15,loadinggame);
    iPauseTimer(0);
    iPauseTimer(1);
    iPauseTimer(2);
    iPauseTimer(4);

    loadimg(menuimg,"BMP//menu1.bmp");
    loadimg(pauseimg,"BMP//pause.bmp");
    loadimg(leaderboardimg,"BMP\\leaderboard.bmp");
    loadimg(aboutimg,"BMP\\about bg.bmp");

    Fileopen();


//
//    int i,j;
//    for(j=0;j<3;j++){
//        for(i=0;i<10;i++){
//            printf("%lf\n",leaderboardscore[j][i]);
//        }
////        for(i=0;i<10;i++){
////            printf("%s\n",leaderboardname[j][i][0]);
////        }
//    }

    iInitialize(1600,900,"Flaming Tires 2D");

}
