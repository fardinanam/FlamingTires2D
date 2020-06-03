void iDrawMain()
{
    //INSTRUCTION
    iShowBMP(0,0,"BMP//menu1.bmp");
    //printimg(menuimg);
    int i;
    iSetColor(255,255,255);
    if(hint)
    {
        iText(650,250,"USE NAVIGATION KEY",GLUT_BITMAP_HELVETICA_18);
    }

    //iSetColor(102,51,0);
    //iFilledRectangle(610,435,300,250);
    int y=635;
    for(i=0;i<8;i++){
        if(menukey[i])break;
        else y-=50;
    }
    if(menukey[4]){
        if(sounds){
        iSetColor(0,255,0);
        iText(920,450," ON",GLUT_BITMAP_HELVETICA_18);
        }
        else{
            iSetColor(255,0,0);
            iText(920,450,"OFF",GLUT_BITMAP_HELVETICA_18);
        }
    }
    //if(menukey[0])y=635;if(menukey[1])y=585;if(menukey[2])y=535;if(menukey[3])y=485;if(menukey[4])y=435;if(menukey[5])y=385;
    iSetColor(255,255,255);
    iRectangle(610,y,300,50);
    iSetColor(0,0,0155);
    iRectangle(611,y+1,300,50);
    iSetColor(0,0,125);
    for(int i=0;i<3;i++){
        if(i==0)iSetColor(0,0,0);
        else if(i==1)iSetColor(0,0102,0102);
        else if(i==2)iSetColor(0,0102,0255);
    iText(649+i*2,650+i,"       CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(649+i*2,600+i,"   NORMAL RACE",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(649+i*2,550+i,"      DRAG RACE",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(649+i*2,500+i,"   LEADERBOARD",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(649+i*2,450+i,"            SOUND",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(649+i*2,400+i,"             HELP",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(649+i*2,350+i,"           ABOUT",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(649+i*2,300+i,"             QUIT",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    iShowBMP2(400,700,"BMP//gamename.bmp",0);
    if(menukey[0])
        iShowBMP2(0,100,"BMP//instcont.bmp",0);
    else if(menukey[1])
        iShowBMP2(0,100,"BMP//instnormal.bmp",0);
    else if(menukey[2])
        iShowBMP2(0,100,"BMP//instdrag.bmp",0);
    else if(menukey[3])
        iShowBMP2(0,100,"BMP//instlead.bmp",0);
    else if(menukey[4])
        iShowBMP2(0,100,"BMP//instlsnd.bmp",0);

}

void iDrawPause(){
    iShowBMP(0,0,"BMP//pause.bmp");
    //printimg(pauseimg);
    iSetColor(255,255,255);
//    iText(740,650,"  Resume Game",GLUT_BITMAP_HELVETICA_18);
//    iText(740,600,"    New Game",GLUT_BITMAP_HELVETICA_18);
//    iText(740,550,"    Main Menu",GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,255);
    iText(741,651," Resume Game",GLUT_BITMAP_HELVETICA_18);
    iText(741,601,"    New Game",GLUT_BITMAP_HELVETICA_18);
    iText(741,551,"    Main Menu",GLUT_BITMAP_HELVETICA_18);
    iText(741,501,"   Save & Exit",GLUT_BITMAP_HELVETICA_18);
    int y;
    if(pausekey[0])y=635;if(pausekey[1])y=585;if(pausekey[2])y=535;if(pausekey[3])y=485;
    iSetColor(255,255,255);
    iRectangle(700,y,210,50);
}

void iExit(){
    iSetColor(0,0,0);
    iFilledRectangle(0,335,1600,150);
    iSetColor(0,102,204);
    iText(650,450,"Do you want to quit?",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(153,0,0);
    iText(675,370," YES",GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,153,0);
    iText(775,370,"  NO",GLUT_BITMAP_HELVETICA_18);
    iSetColor(255,255,255);
    iSetColor(0,102,204);
    if(exitkey)iRectangle(650,350,100,50);

    else iRectangle(750,350,100,50);
}
char str[15];
int blink;
void iDrawTakeName(){
    iSetColor(150, 150, 150);
	iRectangle(830, 255, 250, 50);
	iSetColor(255,255,255);
	iText(630,275,"Enter Your Name",GLUT_BITMAP_HELVETICA_18);
	iText(855,275,str,GLUT_BITMAP_HELVETICA_18);
//	blink>50?blink=0:blink=255;
//	iSetColor(blink,blink,blink);
//	iText(855,265,"---------------------");
}

void iDrawLeaderboard(){
//    iSetColor(115,226,84);
//    iFilledRectangle(0,0,1600,900);
    //iShowBMP(0,0,"BMP\\leaderboard.bmp");
    printimg(leaderboardimg);
    iSetColor(255,255,255);
    if(leadermode==0)iText(740,650,"EASY",GLUT_BITMAP_TIMES_ROMAN_24);
    else if(leadermode==1)iText(725,650,"MEDIUM",GLUT_BITMAP_TIMES_ROMAN_24);
    else iText(740,650,"HARD",GLUT_BITMAP_TIMES_ROMAN_24);

    int i,y=600;
    char ch[10];
    for(i=0;i<10;i++){
        sprintf(ch,"%d",i+1);
        iText(575,y,ch,GLUT_BITMAP_HELVETICA_12);
        iText(600,y,lb[leadermode][i].name,GLUT_BITMAP_HELVETICA_12);
        sprintf(ch,"%lf",lb[leadermode][i].time);
        iText(900,y,ch,GLUT_BITMAP_HELVETICA_12);
        y-=40;
    }
}


void iDrawLoading(){
    int t=0;
    if(loadingx>1070)t=(loadingx-1070)/10;
    if(t>0){
        if(t==1)iShowBMP(0,0,"BMP\\G Loading\\1.bmp");
    else if(t<5)iShowBMP(0,0,"BMP\\G Loading\\2.bmp");
    else if(t<9)iShowBMP(0,0,"BMP\\G Loading\\3.bmp");
    else if(t<13)iShowBMP(0,0,"BMP\\G Loading\\4.bmp");
    else if(t<17)iShowBMP(0,0,"BMP\\G Loading\\5.bmp");
    else if(t<21)iShowBMP(0,0,"BMP\\G Loading\\6.bmp");
    else if(t<25)iShowBMP(0,0,"BMP\\G Loading\\7.bmp");
    else if(t<29)iShowBMP(0,0,"BMP\\G Loading\\8.bmp");
    else if(t<33)iShowBMP(0,0,"BMP\\G Loading\\9.bmp");
    else if(t<37)iShowBMP(0,0,"BMP\\G Loading\\10.bmp");
    else if(t<41)iShowBMP(0,0,"BMP\\G Loading\\11.bmp");
    else iShowBMP(0,0,"BMP\\G Loading\\12.bmp");
    }

    //iShowBMP(0,400,"BMP\\Load\\1.bmp");
    iSetColor(255,0,0);
    //iFilledRectangle(0,25,1600,15);
//    iRectangle(0,25,1600,15);
//    iSetColor(0,0,255);
    int i;
//    for(i=26;i<40;i++){
//        iLine(0,i,loadingx+rand()%50,i);
//    }
    iSetColor(101,101,101);
    iText(1295,45,"LOADING",GLUT_BITMAP_TIMES_ROMAN_24);
    for(i=0;i<loadingy/10;i++){
        iFilledCircle(1430+15*i,50,5);
    }

}
void iDrawGameLoad(){
    int t=0;
    if(loadingx>550)t=(loadingx-550)/10;
    if(t>0){
        if(t==1)iShowBMP2(400,225,"BMP\\GameLoad\\load00.bmp",0);
    else if(t<5)iShowBMP2(400,225,"BMP\\GameLoad\\load01.bmp",0);
    else if(t<9)iShowBMP2(400,225,"BMP\\GameLoad\\load02.bmp",0);
    else if(t<13)iShowBMP2(400,225,"BMP\\GameLoad\\load03.bmp",0);
    else if(t<17)iShowBMP2(400,225,"BMP\\GameLoad\\load04.bmp",0);
    else if(t<21)iShowBMP2(400,225,"BMP\\GameLoad\\load05.bmp",0);
    else if(t<25)iShowBMP2(400,225,"BMP\\GameLoad\\load06.bmp",0);
    else if(t<29)iShowBMP2(400,225,"BMP\\GameLoad\\load07.bmp",0);
    else if(t<33)iShowBMP2(400,225,"BMP\\GameLoad\\load08.bmp",0);
    else if(t<37)iShowBMP2(400,225,"BMP\\GameLoad\\load09.bmp",0);
    else if(t<41)iShowBMP2(400,225,"BMP\\GameLoad\\load10.bmp",0);
    else if(t<45)iShowBMP2(400,225,"BMP\\GameLoad\\load11.bmp",0);
    else if(t<49)iShowBMP2(400,225,"BMP\\GameLoad\\load12.bmp",0);
    else if(t<53)iShowBMP2(400,225,"BMP\\GameLoad\\load13.bmp",0);
    else if(t<57)iShowBMP2(400,225,"BMP\\GameLoad\\load14.bmp",0);
    else if(t<61)iShowBMP2(400,225,"BMP\\GameLoad\\load15.bmp",0);
    else if(t<65)iShowBMP2(400,225,"BMP\\GameLoad\\load16.bmp",0);
    }
}

iDrawAbout(){
    iShowBMP(0,0,"BMP\\about bg.bmp");
}
