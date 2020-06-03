void iDrawBMPCar(char *filename){
    AUX_RGBImageRec *TextureImage;
    TextureImage = auxDIBImageLoad(filename);
    int i,j,k;
    int realwidth = TextureImage->sizeX;
    int realheight = TextureImage->sizeY;
    realwidth>600?width=600:width=realwidth;
    realheight>600?height=600:height=realheight;
    for(i=0;i<height;i++)
        for(j=0;j<width;j++)
            for(k=2;k>=0;k--)
                mycarimg[i][j][k]=TextureImage->data[3*i*realwidth+3*j+k];

    free(TextureImage->data);
    free(TextureImage);
}

void iCarSelect(){
    //iShowBMP(0,0,"dims.bmp");
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
        x1[0]=1200;x1[1]=1225;x1[2]=1250;x1[3]=1225;x1[4]=1200;x1[5]=1250;
        y1[0]=550;y1[1]=550;y1[2]=450;y1[3]=350;y1[4]=350;y1[5]=450;
        iFilledPolygon(x1,y1,6);//right
        x1[0]=400;x1[1]=375;x1[2]=350;x1[3]=375;x1[4]=400;x1[5]=375;
        y1[0]=550;y1[1]=550;y1[2]=450;y1[3]=350;y1[4]=350;y1[5]=450;
        iFilledPolygon(x1,y1,6);//left
        iFilledRectangle(650,225,300,50);
    iSetColor(255,255,255);
    iText(690,665,"SELECT YOUR CAR",GLUT_BITMAP_TIMES_ROMAN_24);
//    iText(655,655," SELECT and RACE",GLUT_BITMAP_HELVETICA_18);
    iText(675,245," PRESS ENTER TO SELECT",GLUT_BITMAP_HELVETICA_18);
    if(yellow)iShowBMP2(575,300,"BMP//car//yellow.bmp",0);
    else if(red)iShowBMP2(575,300,"BMP//car//red.bmp",0);
    else if(black)iShowBMP2(575,300,"BMP//car//black.bmp",0);
    //getting my cars details
    if(yellow)iDrawBMPCar("BMP//car//yellow.bmp");
    else if(red)iDrawBMPCar("BMP//car//red.bmp");
    else if(black)iDrawBMPCar("BMP//car//black.bmp");

    iText(775,490,"SPEED",GLUT_BITMAP_HELVETICA_18);
    iText(775,420,"HANDLING",GLUT_BITMAP_HELVETICA_18);
    iText(775,350,"ACCELERATION",GLUT_BITMAP_HELVETICA_18);
    iRectangle(950,345,200,20);
    iRectangle(950,415,200,20);
    iRectangle(950,485,200,20);
    int r;
    if(yellow)r=1;
    else if(red)r=2;
    else if(black)r=3;
    iSetColor(0,76,153);
    iFilledRectangle(951,346,accelerationarray[r]*190,18);
    iFilledRectangle(951,416,(1-driftarray[r])*380,18);
    iFilledRectangle(951,486,speedarray[r]*8,18);
}

void iLevel(){
    iSetColor(32,32,32);
    iFilledRectangle(0,280,1600,250);
    iSetColor(0,102,204);
    iText(700,450,"  SELECT LEVEL",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0,153,76);
    iText(550,355,"    EASY",GLUT_BITMAP_HELVETICA_18);
    if(selectlevel==0)iText(610,290,"If you are a beginner then this level is for you",GLUT_BITMAP_HELVETICA_18);
    iSetColor(204,204,0);
    iText(750,355,"   MEDIUM",GLUT_BITMAP_HELVETICA_18);
    if(selectlevel==1)iText(610,290,"                  Time to show your skills",GLUT_BITMAP_HELVETICA_18);
    iSetColor(204,0,0);
    iText(950,355,"    HARD",GLUT_BITMAP_HELVETICA_18);
    if(selectlevel==2)iText(610,290,"              Ready for the real challenge?",GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,102,204);
    iRectangle(500+200*selectlevel,335,200,50);



}
void iDrawCar(){
    iSetColor(0,51,102);
    if(enter<2)iText(485,650,"PRESS SPACE TO START",GLUT_BITMAP_HELVETICA_18);
    carx[3]=carx[2]+200*cos(angle*pi);
    cary[3]=cary[2]+200*sin(angle*pi);
    carx[4]=carx[0]+200*cos(angle*pi);
    cary[4]=cary[0]+200*sin(angle*pi);
    iSetColor(255,255,255);
    //iFilledPolygon(carx,cary,5);
}

void iDrawSpedometer(){
    iSetColor(255,255,255);
//    iFilledRectangle(100,650,150,150);
    iShowBMP2(83.5,650,"BMP//speedometer.bmp",0);
    iSetColor(255,255,255);
    iLine(175,675,175+90*cos(pi*smangle),725+90*sin(pi*smangle));
    iLine(176,675,175+90*cos(pi*smangle),725+90*sin(pi*smangle));
    iLine(174,675,175+90*cos(pi*smangle),725+90*sin(pi*smangle));
    iText(150,700,speedm);
    iText(151,700,speedm);
}

void velocity(){
    if(abs(motion-angle)<1)motion=angle;
    else if(motion>angle)motion-=2;
    else if(motion<angle)motion+=2;

    if(afterangle>0){
        afterangle--;
        angle++;
        if(afterangle>10){
            afterangle-=2;
            angle+=2;
        }
    }
    else if(afterangle<0){
        afterangle++;
        angle--;
        if(afterangle<-10){
            afterangle+=2;
            angle-=2;
        }
        //printf("%lf\n",afterangle+angle);
    }

    vx=v*cos(motion*pi);
    vy=v*sin(motion*pi);
    rx=rx-vx;
    ry=ry-vy;
    if(smangle<225-10.8*v)smangle+=1;
    if(smangle>225-10.8*v)smangle-=7;
    if(smangle>225)smangle=225;
    sprintf(speedm,"%0.2lf KMH",8*v);
    if(v<=12 && menu==0 && win==0 && lose==0 ){
        if(play1==false){
            play1=true;
            sound();
        }
        play2=false;
    }
    if(v>12){
        play1=false;
        if(play2==false){
            play2=true;
            sound();
        }
    }
    //printf("%lf %lf\n",carx[1]-rx,cary[1]-ry);
    if((carx[1]-rx>950 && carx[1]-rx<2895) && (cary[1]-ry>195 && cary[1]-ry<1705)){
        v=-0.5;
    }
    else if((carx[1]-rx>3905 || carx[1]-rx<95) || (cary[1]-ry>2705 || cary[1]-ry<-705)){
        v=-0.5;
    }
    else if((carx[1]-rx>805 && carx[1]-rx<3095) && (cary[1]-ry>105 && cary[1]-ry<1905)){
        v-=0.125;
    }
    else if((carx[1]-rx>3605 || carx[1]-rx<295) || (cary[1]-ry>2405 || cary[1]-ry<-405)){
        v-=0.125;
    }

    if(mycarloop==0){
        if(ry>50)v=0;
        if(ry<-1400)mycarloop=1;
    }
    else if(mycarloop==1){
        if(rx<-2325)mycarloop=2;
    }
    else if(mycarloop==2){
        if(ry>250)mycarloop=3;
    }
    else if(mycarloop==3){
    }
    int i,j;
    double area[4],sum1,sum2;
    int lcol[4]={0,0,0,0};
    for(i=0;i<5;i++){
        if(i==1)continue;
        area[0]=0.5*abs((op1x[4]*op1y[3]+op1x[3]*cary[i]+carx[i]*op1y[4]-op1y[4]*op1x[3]-op1y[3]*carx[i]-cary[i]*op1x[4]));
        area[1]=0.5*abs((op1x[4]*op1y[0]+op1x[0]*cary[i]+carx[i]*op1y[4]-op1y[4]*op1x[0]-op1y[0]*carx[i]-cary[i]*op1x[4]));
        area[2]=0.5*abs((op1x[2]*op1y[0]+op1x[0]*cary[i]+carx[i]*op1y[2]-op1y[2]*op1x[0]-op1y[0]*carx[i]-cary[i]*op1x[2]));
        area[3]=0.5*abs((op1x[2]*op1y[3]+op1x[3]*cary[i]+carx[i]*op1y[2]-op1y[2]*op1x[3]-op1y[3]*carx[i]-cary[i]*op1x[2]));
        sum1=area[0]+area[1]+area[2]+area[3];
        int j;
        for(j=0;j<5;j++){
        if(j==1)continue;
        area[0]=0.5*abs((carx[4]*cary[3]+carx[3]*op1y[j]+op1x[j]*cary[4]-cary[4]*carx[3]-cary[3]*op1x[j]-op1y[j]*carx[4]));
        area[1]=0.5*abs((carx[4]*cary[0]+carx[0]*op1y[j]+op1x[j]*cary[4]-cary[4]*carx[0]-cary[0]*op1x[j]-op1y[j]*carx[4]));
        area[2]=0.5*abs((carx[2]*cary[0]+carx[0]*op1y[j]+op1x[j]*cary[2]-cary[2]*carx[0]-cary[0]*op1x[j]-op1y[j]*carx[2]));
        area[3]=0.5*abs((carx[2]*cary[3]+carx[3]*op1y[j]+op1x[j]*cary[2]-cary[2]*carx[3]-cary[3]*op1x[j]-op1y[j]*carx[2]));
        sum2=area[0]+area[1]+area[2]+area[3];
        //printf("%lf \t %lf\n",sum1,sum2);
        if(sum1<=20000 || sum2<=20000){
            double temp;
            temp=vx;
            vx=op1vx;
            op1vx=temp;
            temp=vy;
            vy=op1vy;
            op1vy=temp;

            rx=rx-vx;
            ry=ry-vy;

            temp=0.5*(angle+angleop1);
            if(angle>angleop1){
                motion=temp-10;
                op1motion=temp+10;
            }
            else{
                motion=temp+10;
                op1motion=temp-10;
            }
//            temp=motion;
//            motion=op1motion;
//            op1motion=motion;
            if(sum2<=20000){
                if(v<op1v){
                    temp=v;
                    v=op1v;
                    if(op1v>10)op1v=temp-5;
                    else op1v=temp;
                }
            }
            if(v>10)v-=2;
            if(op1v>10)op1v-=2;
        }
    }
    }
}



