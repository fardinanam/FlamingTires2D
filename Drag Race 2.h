
double mycarx2=425,mycary2=20,refx1=240,refy1=0;

double a1=0,vdg1=0,td1=0;
int start=0,cnt1=0;
int r1=255,g1=255,b1=0;

void movement()
{
    if(start)
        td1+=1;

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
//    if(!a1)
//    {
////        v+=a1*t;
//        if(refy1>-64000)
//            refy1=-v*t;
//    }
//    else
//    {
//        refy1=-(v*t+.5*a1*t*t);
//    }
//    if(v<50 && start){
//        v=;
//    }
    if(refy1>=-63700)
        refy1=refy1-vdg1;
}
void iDrawDragRoad()
{
    iClear();
    iSetColor(51,102,0);
    iFilledRectangle(0,0,1920,1080);
    iSetColor(128,128,128);//left track color
    iFilledRectangle(refx1,refy1,480,64000);//first track
    iFilledRectangle(refx1+960,0,480,64000);//second track
    iSetColor(255,255,0); //lane color
    iFilledRectangle(refx1,refy1,10,64000);//lanes start
    iFilledRectangle(refx1+960,refy1,10,64000);
    iFilledRectangle(refx1+480-10,refy1,10,64000);
    iFilledRectangle(refx1+960+480-10,refy1,10,64000);//lanes end
    iSetColor(r,g,b);
    iFilledCircle(475+355,540,25,1000);
    iSetColor(255,255,255);
    iFilledRectangle(930,380,60,320);
    iSetColor(253,0,0);
    iFilledRectangle(930,380,30,-refy1/200);
//    sprintf()
    iSetColor(255,255,255);
    iLine(960,0,960,1080);


    iSetColor(255,255,255);//divider color
    for(int i=0;i<=63950;i+=200)//dividers
    {
        iFilledRectangle(refx1+235,refy1+i,10,100);
        iFilledRectangle(refx1+960+235,0+i,10,100);
    }
    if(start==0)
        {
            iSetColor(255,255,255);
            iText(340,540,"PRESS SPACE TO START",GLUT_BITMAP_HELVETICA_18);
        }
    if(yellow)iDrawBMPCar("BMP//car//yellow.bmp");
    else if(red)iDrawBMPCar("BMP//car//red.bmp");
    else if(black)iDrawBMPCar("BMP//car//black.bmp");

    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            if(mycarimg[j][i][0]!=0){
                iSetColor(mycarimg[j][i][0],mycarimg[j][i][1],mycarimg[j][i][2]);
                iPoint(i+mycarx2,j+mycary2,1);
            }
        }
    }
}

//void iKeyboard(unsigned char key)
//{
//    if(key==' ')
//    {
//        start=1;
//        v=15;
//    }
//}

//void iSpecialKeyboard(unsigned char key)
//{
//    if(key==GLUT_KEY_UP)
//    {
//
//
//    }
//    if(key==GLUT_KEY_RIGHT)
//    {
////        if(mycarx2<1080){
////
mycarx2+=10;
////        }
//    }
//    if(key==GLUT_KEY_LEFT)
//    {
////        if(mycarx2>400){
////            mycarx2-=10;
////        }
//    }
//    if(key==GLUT_KEY_DOWN)
//    {
////        if(a1)
////            a1-=.1;
////        if(refy1)
////        {
////            //mycary2-=5;
////            //refy1+=10;
////        }
//
//    }
//
//}
//
