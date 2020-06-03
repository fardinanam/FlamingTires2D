
void iDrawRoad(){

    //ROAD
    iSetColor(255,255,255);
    iFilledCircle(rx+800,ry+2000,450);
    iFilledCircle(rx+3200,ry+2000,450);
    iFilledCircle(rx+3200,ry,450);

    iSetColor(104,104,104);
    iFilledRectangle(rx+400,ry+0,400,2000);
    iFilledRectangle(rx+800,ry+2000,2400,400);
    iFilledRectangle(rx+3200,ry+0,400,2000);
    iFilledRectangle(rx,ry-400,3200,400);


    iFilledCircle(rx+800,ry+2000,400);
    iFilledCircle(rx+3200,ry+2000,400);
    iFilledCircle(rx+3200,ry,400);

    iSetColor(255,255,255);
    iFilledCircle(rx+1050,ry+1750,250);
    iFilledCircle(rx+2950,ry+1750,250);
    iFilledCircle(rx+2950,ry+250,250);

    iFilledRectangle(rx+350,ry,50,2000);
    iFilledRectangle(rx+800,ry,50,1750);
    iFilledRectangle(rx+800,ry+2400,2400,50);
    iFilledRectangle(rx+1050,ry+1950,1900,50);
    iFilledRectangle(rx+3600,ry,50,2000);
    iFilledRectangle(rx+3150,ry+250,50,1500);
    iFilledRectangle(rx,ry,2950,50);
    iFilledRectangle(rx,ry-450,3200,50);

    iSetColor(0,77,13);
    iFilledCircle(rx+1050,ry+1750,200);
    iFilledRectangle(rx+850,ry+1500,500,250);
    iFilledRectangle(rx+1050,ry+1750,500,200);

    iFilledCircle(rx+2950,ry+1750,200);
    iFilledRectangle(rx+2700,ry+1500,250,450);
    iFilledRectangle(rx+2950,ry+1500,200,250);

    iFilledCircle(rx+2950,ry+250,200);
    iFilledRectangle(rx+2700,ry+50,250,450);
    iFilledRectangle(rx+2950,ry+250,200,250);
     int i;
    //STRIP
//    iSetColor(0255,71,71);
//
//    for(i=0;i<=1950;){
//        iFilledRectangle(rx+350,ry+i,50,25);
//        iFilledRectangle(rx+3150,ry+i,50,25);
//        iFilledRectangle(rx+800,ry+i,50,25);
//        iFilledRectangle(rx+3600,ry+i,50,25);
//        i+=50;
//    }


     //Lane Divider
    iSetColor(255,255,0);

    for(i=00;i<1700;){
        iFilledRectangle(rx+600,ry+i,10,100);
        i+=112;
    }
    for(i=0;i<2000;){
        iFilledRectangle(rx+895+i,ry+2200,100,10);
        i+=112;
    }
    for(i=0;i<1500;){
        iFilledRectangle(rx+3400,ry+100+i,10,100);
        i+=112;
    }
    for(i=1;i<2088;){
        iFilledRectangle(rx+600+i,ry-200,100,10);
        i+=112;
    }

    iSetColor(0,77,13);
    if(mycarloop==0)iFilledRectangle(rx,ry-450,1800,500);
    if(mycarloop==3)iFilledRectangle(rx+350,ry+50,800,1200);

}

void iDrawEndLine(){
    int i;
    iSetColor(255,255,255);
    for(i=0;i<400;){
        iFilledRectangle(rx+800,ry-400+i,50,50);
        i+=100;
    }
    for(i=0;i<350;){
        iFilledRectangle(rx+850,ry+i-350,50,50);
        i+=100;
    }
    for(i=0;i<400;i++){
        iFilledRectangle(rx+900,ry-400+i,50,50);
        i+=100;
    }
    for(i=0;i<350;i++){
        iFilledRectangle(rx+950,ry-350+i,50,50);
        i+=100;
    }

}



//Gallary
void iDrawGallery(){


    //
     iSetColor(0,77,13);
//    iFilledRectangle(rx-650,ry-1450,5300,4900);
//    iSetColor(42,128,0);
//    iFilledRectangle(rx-450,ry-1250,4900,4500);
//    iSetColor(0,77,13);
    iFilledRectangle(rx-250,ry-1050,4500,4100);
    iSetColor(42,128,0);
    iFilledRectangle(rx-50,ry-850,4100,3700);
    iSetColor(0,77,13);
    iFilledRectangle(rx+150,ry-650,3700,3300);


    iSetColor(0,77,13);
    iFilledRectangle(rx+850,ry+50,2300,1900);
    iSetColor(42,128,0);
    iFilledRectangle(rx+1050,ry+250,1900,1500);
    iSetColor(0,77,13);
    iFilledRectangle(rx+1250,ry+450,1500,1100);
//    iSetColor(42,128,0);
//    iFilledRectangle(rx+1450,ry+650,1100,700);
//    iSetColor(0,77,13);
//    iFilledRectangle(rx+1650,ry+850,700,300);
//    int l;
//    for(l=0;l<2800;l+=600){
//        int i,j,k;
//        for(int i=0;i<100;i++){
//            for(int j=0;j<100;j++){
//                if(img[j][i][0]!=0){
//                    iSetColor(treeimg[j][i][0],treeimg[j][i][1],treeimg[j][i][2]);
//                    if(treeimg[j][i][0]<185 && treeimg[j][i][1] <185 && treeimg[j][i][2]<185)
//                    iPoint(i+rx+10,j+ry+l,1);
//                }
//            }
//        }
//
//    }

}

//win || lose

void iWin(){
    iShowBMP(0,0,"BMP\\win.bmp");
//    iSetColor(125,52,152);
    //iFilledRectangle(0,0,1600,900);
    iSetColor(0,255,255);
    //iText(700,550,"CONGRATULATION");
//    iText(750,750,"YOU WON",GLUT_BITMAP_TIMES_ROMAN_24);
//    iText(751,751,"YOU WON",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(752,752,"YOU WON",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0,255,255);
    if(!takename)iText(660,150,"PRESS SPACE TO CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,255,255);
    iText(675,200,ttime,GLUT_BITMAP_TIMES_ROMAN_24);
    if(getname){
        iSetColor(0,255,255);
        //iText(700,650,"NEW HIGH SCORE!!",GLUT_BITMAP_TIMES_ROMAN_24);
        if(leaderindx==0)iText(700,600," NEW BEST TIMING!!",GLUT_BITMAP_TIMES_ROMAN_24);
//        else if(leaderindx<3)iText(700,600,"YOU ARE IN TOP 3!!",GLUT_BITMAP_TIMES_ROMAN_24);
//        else if(leaderindx<5)iText(700,600,"YOU ARE IN TOP 5!!",GLUT_BITMAP_TIMES_ROMAN_24);
        if(leaderindx!=0){
            char ch[25];
            sprintf(ch,"YOU ARE %d%s ON THE LEADERBOARD",leaderindx+1,((leaderindx == 0)? "st":(leaderindx==1)? "nd":(leaderindx==2)? "rd" : "th"));
            iText(645,400,ch,GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }
}

void iLose(){
    iShowBMP(0,0,"BMP\\lost.bmp");
    iSetColor(255,255,255);

    iText(630,150,"PRESS SPACE TO CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,255,255);
    iText(655,200,ttime,GLUT_BITMAP_TIMES_ROMAN_24);
}



//Opponent Velocity
void opp1velocity(){
    if(abs(op1motion-angleop1)<1)op1motion=angleop1;
    else if(op1motion>angleop1)op1motion-=2.2;
    else if(op1motion<angleop1)op1motion+=2.2;
    if(op1v<5)op1v+=.25;
    else if(op1v<op1speed+lvlsp[selectlevel])op1v+=op1acceleration+lvlacc[selectlevel];
    else if(op1v<25)op1v+=.0025;
    op1vx=op1v*cos(op1motion*pi)-v*cos(motion*pi);//relative in x axis
    op1vy=op1v*sin(op1motion*pi)-v*sin(motion*pi);//relative in y axis
    op1x[1]=op1x[1]+op1vx;
    op1y[1]=op1y[1]+op1vy;
    //printf("%0.2lf %0.2lf\t%0.2lf %0.2lf\t%0.2lf %0.2lf\n",op1x[1],op1y[1],rx,ry,rx+500-op1x[1],ry+2020-op1y[1]);

    op1x[0]=op1x[1]-50*cos(pi*(90-angleop1));
    op1y[0]=op1y[1]+50*sin(pi*(90-angleop1));
    op1x[2]=op1x[1]+50*cos(pi*(90-angleop1));
    op1y[2]=op1y[1]-50*sin(pi*(90-angleop1));
    double angx,angy;
    double testangle;
    //for 1st line
    if(l==0){
        angx=rx+500;
        angy=ry+2300;
        testangle=abs(atan((angy-op1y[1])/(angx-op1x[1]))/pi);
        if(op1y[1]-ry>1700){
            l++;
        }
    }
    //for 2nd line
    if(l==1){
        angx=rx+3000;
        angy=ry+2300;
        if(mycarloop==1 && cary[1]-ry>2200)angy=ry+2100;
        testangle=atan((angy-op1y[1])/(angx-op1x[1]))/pi;

        if(op1x[1]-rx>2900){
            l++;
        }
    }
    //for 3rd line
    if(l==2){
        angx=rx+3500;
        angy=ry+10;
        if(mycarloop==2 && carx[1]-rx>3400)angx=rx+3300;
        testangle=atan((angy-op1y[1])/(angx-op1x[1]))/pi;
        //printf("%lf\t",testangle);
        if(testangle>0)testangle-=180;
        //printf("%lf\n",testangle);
        //printf("%lf %lf\n",angleop1,testangle);
        if(op1y[1]-ry<300){
            l++;
        }
    }
    //for last line
    if(l==3){
        angx=rx+1000;
        angy=ry-300;
        if(mycarloop==3 && cary[1]-ry<-200)angy=ry-100;
        testangle=atan((angy-op1y[1])/(angx-op1x[1]))/pi;
        testangle=testangle-180;
        //printf("%lf %lf %lf %lf\n",angy-op1y[1],angx-op1x[1],angleop1,testangle);
    }

    if(angleop1-testangle>5){angleop1-=4.8;op1v-=op1drift;}
    else if(testangle-angleop1>5){angleop1+=4.8;op1v-=op1drift;}
    else if(abs(angleop1-testangle)<1)angleop1=testangle;
    else if(angleop1>testangle){angleop1-=1;op1v-=op1drift;}
    else {angleop1+=1;op1v-=op1drift;}

    //Checking Winning or Losing
    if(l==3 || mycarloop==3){
        if(carx[1]<=rx+1000){
            iPauseTimer(0);
            iPauseTimer(1);
            play2=false;
            play1=false;
            sound();
            enter=0;
            if(mycarloop==3){
                singleplayer=0;
                //leaderboard part
                timeelasped=timeelasped+(double)(timestop-timestart)/CLOCKS_PER_SEC;
                sprintf(ttime,"     YOUR TIME IS %0.2lfs",timeelasped);
                if(llose){lose=1;losemusic();}
                else{
                win=1;
                winmusic();
                double t=timeelasped;
                int i,j=0;
                leaderboard temp,save;
                save.time=timeelasped;
                strcpy(save.name,"PLAYER");
                for(i=0;i<10;i++){
                    if(lb[selectlevel][i].time==0.00 || lb[selectlevel][i].time>t){
                        if(!j)leaderindx=i;
                        j=1;
                        temp=lb[selectlevel][i];
                        lb[selectlevel][i]=save;
                        save=temp;
                    }
                }
                if(j){getname=1;takename=1;}
                else {getname=0;takename=0;}

//                for(i=0;i<10;i++){
//                    printf("%s\t%lf\n",lb[selectlevel][i].name,lb[selectlevel][i].time);
//                }
                }
            }
            else {lose=1;losemusic();}
        }
        if(op1x[1]<=rx+1000){
            llose=1;
            if(op1v>0)op1v--;
            if(op1v<2)op1v=0;
        }
    }
}


