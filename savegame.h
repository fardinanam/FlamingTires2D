void savenormalgame () {
    FILE *fp;
    fp=fopen("Data\\savegame.txt","w");
    fprintf(fp,"1\n");
    //rx ry
    fprintf(fp,"%lf\n",timeelasped);
    fprintf(fp,"%lf\t%lf\n",rx,ry);
    //mycar angle motion afterangle
    fprintf(fp,"%lf\t%lf\t%lf\t%lf\t%lf\n",carx[1],cary[1],angle,motion,afterangle);
    //velocity mycarloop
    fprintf(fp,"%lf\t%d\n",v,mycarloop);
    //carcolor
    fprintf(fp,"%d %d %d\n",yellow,red,black);
    fprintf(fp,"%lf %lf %lf\n",acceleration,speed,drift);

    //op1car angleop1 op1motion
    fprintf(fp,"%lf\t%lf\t%lf\t%lf\n",op1x[1],op1y[1],angleop1,op1motion);
    //op1velocity l
    fprintf(fp,"%lf\t%lf\t%d",op1v,l,op1carcolor);

    fclose(fp);
}
void loadnormalgame(){
    FILE *fp;
    fp=fopen("Data\\savegame.txt","r");
    int n;
    fscanf(fp,"%d",&n);
    if(n==1){
    fscanf(fp,"%lf\n",&timeelasped);
    //rx ry
    fscanf(fp,"%lf\t%lf\n",&rx,&ry);

    //mycar angle motion afterangle
    fscanf(fp,"%lf\t%lf\%lf\t%lf\t%lf\n",&carx[1],&cary[1],&angle,&motion,&afterangle);
    //velocity mycarloop
    fscanf(fp,"%lf\t%d\n",&v,&mycarloop);
    //carcolor
    fscanf(fp,"%d %d %d\n",&yellow,&red,&black);
    fscanf(fp,"%lf %lf %lf\n",&acceleration,&speed,&drift);


    //op1car angleop1 op1motion
    fscanf(fp,"%lf\t%lf\t%lf\t%lf\n",&op1x[1],&op1y[1],&angleop1,&op1motion);
    //op1velocity l
    fscanf(fp,"%lf\t%lf\t%d",&op1v,&l,&op1carcolor);

    singleplayer=1;
    opp1velocity();
//    velocity();

//    if(v>15){play1=false;play2=true;}
//    else {play1=true;play2=false;}
    menu=0;
    menumusic();
    menukey[0]=0;
    menukey[1]=1;
    continuecarselect();
    if(yellow)iDrawBMPCar("BMP//car//yellow.bmp");
    else if(red)iDrawBMPCar("BMP//car//red.bmp");
    else if(black)iDrawBMPCar("BMP//car//black.bmp");
    }
    else if(n==2){
        fscanf(fp,"%d\n",&start);

        fscanf(fp,"%lf %lf %lf %lf\n",&mycarx1,&mycary1,&refy1,&refx1);
        int i;
        for(i=0;i<4;i++){
            fscanf(fp,"%d %d\n",&geart1[i],&geart2[i]);
        }
        fscanf(fp,"%d %d %d\n",&r1,&g1,&b1);
        fscanf(fp,"%lf %lf %lf %d\n",&a1,&vdg1,&td1,&cnt1);


        fscanf(fp,"%lf %lf %lf %lf\n",&mycarx2,&mycary2,&refy2,&refx2);
        fscanf(fp,"%d %d %d\n",&r2,&g2,&b2);
        fscanf(fp,"%lf %lf %lf %d\n",&a2,&vdg2,&td2,&cnt2);
        dragrace=1;
        menu=0;
        menumusic();
        movement();
        enter=0;
        menukey[0]=0;
        menukey[2]=1;
    }
    fclose(fp);
}

void savedraggame(){
    FILE *fp;
    fp=fopen("Data\\savegame.txt","w");
    fprintf(fp,"2\n");
    //start
    fprintf(fp,"%d\n",start);

    fprintf(fp,"%lf %lf %lf %lf\n",mycarx1,mycary1,refy1,refx1);
    int i;
    for(i=0;i<4;i++){
        fprintf(fp,"%d %d\n",geart1[i],geart2[i]);
    }
    fprintf(fp,"%d %d %d\n",r1,g1,b1);
    fprintf(fp,"%lf %lf %lf %d\n",a1,vdg1,td1,cnt1);


    fprintf(fp,"%lf %lf %lf %lf\n",mycarx2,mycary2,refy2,refx2);
    fprintf(fp,"%d %d %d\n",r2,g2,b2);
    fprintf(fp,"%lf %lf %lf %d\n",a2,vdg2,td2,cnt2);

    fclose(fp);
}
