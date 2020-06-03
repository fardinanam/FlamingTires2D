
int drag1=0,drag2=0;
int dr1=1,dr2=1;
double mycarx1=390,mycary1=20,refx1=200,refy1=0;
int geart1[4]={0},geart2[4]={0};


double a1=0,vdg1=0,td1=0;
int start=0,cnt1=0;
int r1=255,g1=255,b1=0;

double mycarx2=1115,mycary2=mycary1,refx2=920,refy2=0;

double a2=0,vdg2=0,td2=0;
int cnt2=0;
int r2=255,g2=255,b2=0;

int drp1=0,drp2=0;
int aftergame=0;
int rd=0;

void dragnewgame(){
    mycarx1=390,mycary1=20,refx1=200,refy1=0;
    int i;
    for(i=0;i<4;i++){
    geart1[i]=0;geart2[i]=0;
    }
    a1=0,vdg1=15,td1=0;
    start=0,cnt1=0;
    r1=255,g1=255,b1=0;

    mycarx2=1115,mycary2=mycary1,refx2=920,refy2=0;
    a2=0,vdg2=15,td2=0;
    cnt2=0;
    r2=255,g2=255,b2=0;
}

void movement()
{
    if(start){
        if(cnt1<5)td1+=1;
        else if(td1>=250);
        else td1=257;
        if(cnt2<5)td2+=1;
        else if(td2>=250);
        else td2=257;
    }

    if(td1>=100 && td1<200 && cnt1<5)
    {
        r1=0;
        g1=0;
        b1=255;
    }
    else if(td1>=200 && td1<250 && cnt1<5)
    {
        r1=0;
        g1=255;
        b1=0;
    }
    else if(td1>=250 && cnt1<5)
    {
        r1=255;
        g1=0;
        b1=0;
        vdg1=0;
        cnt1=6;
    }
    else if(cnt1<5)
    {
        r1=255;
        g1=255;
        b1=0;
    }
    if(cnt1==5)
    {
        r1=0;
        g1=0;
        b1=0;
    }

    if(refy1>=-63700)refy1=refy1-vdg1;
    else{
        drp1=1;
        iPauseTimer(2);

    }
    if(refy2>=-63700)refy2=refy2-vdg2;
    else{
        drp2=1;
        iPauseTimer(2);

    }

    if(td2>=100 && td2<200 && cnt2<5)
    {
        r2=0;
        g2=0;
        b2=255;
    }
    else if(td2>=200 && td2<250 && cnt2<5)
    {
        r2=0;
        g2=255;
        b2=0;
    }
    else if(td2>=250 && cnt2<5)
    {
        r2=255;
        g2=0;
        b2=0;
        vdg2=0;
        cnt2=6;
    }
    else if(cnt2<5)
    {
        r2=255;
        g2=255;
        b2=0;
    }
    if(cnt2==5)
    {
        r2=0;
        g2=0;
        b2=0;
    }


    //else td2--;

}
void iDrawDragRoad()
{
    iClear();
    iSetColor(96,96,96);//track color
    iFilledRectangle(refx1,refy1,480,64800);//first track
    iFilledRectangle(refx2,refy2,480,64800);//second track
    iSetColor(32,32,32); //lane color
    iFilledRectangle(refx1-15,refy1,30,64800);//lanes start
    iFilledRectangle(refx2-15,refy2,30,64800);
    iFilledRectangle(refx1+480-25,refy1,30,64800);
    iFilledRectangle(refx2+480-25,refy2,30,64800);//lanes end


    iSetColor(255,255,255);
    iFilledRectangle(770,290,60,320);//tracking
    iSetColor(253,0,0);
    iFilledRectangle(770,290,30,-refy1/200);
    iSetColor(0,253,0);
    iFilledRectangle(800,290,30,-refy2/200);


//    sprintf()
//    iSetColor(255,255,255);
//    iLine(800,0,800,900);//splitting line

    iSetColor(192,192,192);//divider color
    for(int i=0;i<=64750;i+=200)//dividers
    {
        if(refy1+i>-100 && refy1+i<1000)
        iFilledRectangle(refx1+235,refy1+i,10,100);
        if(refy2+i>-100 && refy2+i<1000)
        iFilledRectangle(refx2+235,refy2+i,10,100);
    }

    if(geart1[0] && td1<50)
    {
        iSetColor(255,255,0);
        iText(360,550," EARLY SHIFT",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    else if(geart1[1] && td1<50)
    {
        iSetColor(0,0,255);
        iText(360,550," GOOD SHIFT",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    else if(geart1[2] && td1<50)
    {
        iSetColor(0,255,0);
        iText(360,550,"PERFECT SHIFT",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(geart2[0] && td2<50)
    {
        iSetColor(255,255,0);
        iText(1080,550," EARLY SHIFT",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    else if(geart2[1] && td2<50)
    {
        iSetColor(0,0,255);
        iText(1080,550," GOOD SHIFT",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    else if(geart2[2] && td2<50)
    {
        iSetColor(0,255,0);
        iText(1080,550,"PERFECT SHIFT",GLUT_BITMAP_TIMES_ROMAN_24);
    }


    for(int i=450;i<=63950;i+=450)
    {
        for(int j=0;j<76;j+=2)
        {
            iSetColor(96+j,96+j,96+j);
            if(refy1+10+i >=-100 && refy1+10+i<1400)
                iCircle(refx1+30,refy1+10+i,76-j,100);
            if(refy2+10+i >=-76 && refy2+10+i<976)
                iCircle(refx2+425,refy2+10+i,76-j,100);
        }
        iSetColor(64,64,64);
        if(refy1+10+i >=-100 && refy1+10+i<1400)
            iFilledRectangle(refx1-15,refy1+i,60,20);
        if(refy2+10+i >=-76 && refy2+10+i<976)
              iFilledRectangle(refx2+425,refy2+i,60,20);
    }

    if(r1==255 && g1==0 && b1==0)
    {
        iSetColor(255,0,0);
        iText(360,550,"   OVER RED",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(r2==255 && g2==0 && b2==0)
    {
        iSetColor(255,0,0);
        iText(1080,550,"  OVER RED",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    iSetColor(255,255,255);
    iRectangle(240,800,400,10);
    iRectangle(960,800,400,10);
    iSetColor(0,0,255);
    if(td1<100)iFilledRectangle(394,801,2,8);
    if(td2<100)iFilledRectangle(1113,801,2,8);
    iSetColor(0,255,0);
    if(td1>100)iFilledRectangle(549,801,2,8);
    if(td2>100)iFilledRectangle(1269,801,2,8);
    iSetColor(255,0,0);
    if(td1>200)iFilledRectangle(626.5,801,2,8);
    if(td2>200)iFilledRectangle(1346.5,801,2,8);

    iSetColor(r1,g1,b1);//Indicator of left player
    iFilledRectangle(241,801,td1*1.55,8);
    iSetColor(r2,g2,b2);//Indicator of right player
    iFilledRectangle(961,801,td2*1.55,8);
//    for(int i=450;i<=63950;i+=450)
//    {
//
//        for(int j=0;j<76;j++)
//        {
//            iSetColor(96+j,96+j,96+j);
//
//        }
//        iSetColor(64,64,64);
//
//    }
    iSetColor(0,51,102);
    iFilledRectangle(0,0,185,900);//water
    iFilledRectangle(1400,0,200,900);//right water



    if(!enter)
        {
            iSetColor(255,0,2);
            iText(685,250,"PRESS SPACE TO START",GLUT_BITMAP_HELVETICA_18);
            iSetColor(0,0,204);
            iText(300,600,"PLAYER1: Press 'w' to gear up",GLUT_BITMAP_HELVETICA_18);
            iText(1025,600,"PLAYER2: Press '^' to gear up",GLUT_BITMAP_HELVETICA_18);
        }
    if(dr1==1)iDrawBMPCar("BMP//car//yellow.bmp");
    else if(dr1==2)iDrawBMPCar("BMP//car//red.bmp");
    else if(dr1==3)iDrawBMPCar("BMP//car//black.bmp");

    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            if(mycarimg[j][i][0]!=0){
                iSetColor(mycarimg[j][i][0],mycarimg[j][i][1],mycarimg[j][i][2]);
                iPoint(i+mycarx1,j+mycary1,1);
            }
        }
    }

    if(dr2==1)iDrawBMPCar("BMP//car//yellow.bmp");
    else if(dr2==2)iDrawBMPCar("BMP//car//red.bmp");
    else if(dr2==3)iDrawBMPCar("BMP//car//black.bmp");

    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            if(mycarimg[j][i][0]!=0){
                iSetColor(mycarimg[j][i][0],mycarimg[j][i][1],mycarimg[j][i][2]);
                iPoint(i+mycarx2,j+mycary2,1);
            }
        }
    }
    iSetColor(255,255,255);
    if(drp1){
        iText(720,650,"Player1 Won",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(665,250,"PRESS SPACE TO CONTINUE",GLUT_BITMAP_HELVETICA_18);
    }
    else if(drp2){
        iText(720,650,"Player2 Won",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(665,250,"PRESS SPACE TO CONTINUE",GLUT_BITMAP_HELVETICA_18);
    }

//    if(drp1 && drp2)
//        iText(720,650," RACE DRAWN",GLUT_BITMAP_TIMES_ROMAN_24);
    if(r1==255 && !g1 && r2==255 && !g2){
        rd=1;
        iText(720,650," RACE DRAWN",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(665,250,"PRESS SPACE TO CONTINUE",GLUT_BITMAP_HELVETICA_18);
    }

}

void iDragCarSelection(){
    iSetColor(0,51,102);
    iFilledRectangle(0,0,1600,900);
    int i;

    double x1[6],y1[6];
    iSetColor(204,204,0);
    for(i=0;i<1600;i+=24){
        x1[0]=i;x1[1]=i+20;x1[2]=i+10;x1[3]=i-10;
        y1[0]=750;y1[1]=750;y1[2]=725;y1[3]=725;//top line
        iFilledPolygon(x1,y1,4);
        y1[0]=875;y1[1]=875;y1[2]=850;y1[3]=850;//middle line
        iFilledPolygon(x1,y1,4);
        y1[0]=50;y1[1]=50;y1[2]=25;y1[3]=25;//bottom line
        iFilledPolygon(x1,y1,4);
    }
    iSetColor(0,76,153);
        x1[0]=600;x1[1]=1000;x1[2]=900;x1[3]=700;
        y1[0]=725;y1[1]=725;y1[2]=625;y1[3]=625;
        iFilledPolygon(x1,y1,4);//enter to select
        //first player
        x1[0]=600;x1[1]=625;x1[2]=650;x1[3]=625;x1[4]=600;x1[5]=650;
        y1[0]=550;y1[1]=550;y1[2]=450;y1[3]=350;y1[4]=350;y1[5]=450;
        iFilledPolygon(x1,y1,6);//right
        x1[0]=200;x1[1]=175;x1[2]=150;x1[3]=175;x1[4]=200;x1[5]=175;
        y1[0]=550;y1[1]=550;y1[2]=450;y1[3]=350;y1[4]=350;y1[5]=450;
        iFilledPolygon(x1,y1,6);//left
        iFilledRectangle(250,225,300,50);//middle block
        //second player
        y1[0]=550;y1[1]=550;y1[2]=450;y1[3]=350;y1[4]=350;y1[5]=450;
        x1[0]=1000;x1[1]=975;x1[2]=950;x1[3]=975;x1[4]=1000;x1[5]=975;
        iFilledPolygon(x1,y1,6);//left
        x1[0]=1400;x1[1]=1425;x1[2]=1450;x1[3]=1425;x1[4]=1400;x1[5]=1450;
        iFilledPolygon(x1,y1,6);//right
        iFilledRectangle(1050,225,300,50);
    iSetColor(255,255,255);
    iText(685,665,"SELECT YOUR CARS",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(255,240,"PRESS ENTER TO SELECT",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1055,240,"PRESS ENTER TO SELECT",GLUT_BITMAP_TIMES_ROMAN_24);


    if(dr1==1)iShowBMP2(335,310,"BMP//car//yellow.bmp",0);
    else if(dr1==2)iShowBMP2(335,310,"BMP//car//red.bmp",0);
    else if(dr1==3)iShowBMP2(335,310,"BMP//car//black.bmp",0);


    if(dr2==1)iShowBMP2(1145,310,"BMP//car//yellow.bmp",0);
    else if(dr2==2)iShowBMP2(1145,310,"BMP//car//red.bmp",0);
    else if(dr2==3)iShowBMP2(1145,310,"BMP//car//black.bmp",0);

    if(drag1){
        iSetColor(255,255,255);
        iText(335,590,"First Player",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(drag2){
        iSetColor(255,255,255);
        iText(1125,590,"Second Player",GLUT_BITMAP_TIMES_ROMAN_24);
    }

}
