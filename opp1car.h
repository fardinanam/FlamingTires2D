void iGetBMP(char *file_name){
    AUX_RGBImageRec *TextureImage;
    TextureImage = auxDIBImageLoad(file_name);
    int i,j,k;
    int realwidth = TextureImage->sizeX;
    int realheight = TextureImage->sizeY;
    realwidth>100?width=100:width=realwidth;
    realheight>200?height=200:height=realheight;
    for(i=0;i<height;i++)
        for(j=0;j<width;j++)
            for(k=2;k>=0;k--)
                img[i][j][k]=TextureImage->data[3*i*realwidth+3*j+k];


    free(TextureImage->data);
    free(TextureImage);
}

void iOpponentCarSelection(){
    select:
        int r;
        r=rand()%12;
        r=r%4;
        if(r==1 && yellow)goto select;
        if(r==2 && red)goto select;
        if(r==3 && black)goto select;

    op1carcolor=r%4;
    if(r==0)iGetBMP("BMP//car//white.bmp");
    else if(r==1)iGetBMP("BMP//car//yellow.bmp");
    else if(r==2)iGetBMP("BMP//car//red.bmp");
    else if(r==3)iGetBMP("BMP//car//black.bmp");


    op1speed=speedarray[r];
    op1acceleration=accelerationarray[r];
    op1drift=driftarray[r];

}
void continuecarselect(){
    int r=op1carcolor%4;
    if(r==0)iGetBMP("BMP//car//white.bmp");
    else if(r==1)iGetBMP("BMP//car//yellow.bmp");
    else if(r==2)iGetBMP("BMP//car//red.bmp");
    else if(r==3)iGetBMP("BMP//car//black.bmp");

    op1speed=speedarray[r];
    op1acceleration=accelerationarray[r];
    op1drift=driftarray[r];
}

void iDrawOpponent1(){
    iSetColor(255,255,25);
    op1x[3]=op1x[2]+200*cos(angleop1*pi);
    op1y[3]=op1y[2]+200*sin(angleop1*pi);
    op1x[4]=op1x[0]+200*cos(angleop1*pi);
    op1y[4]=op1y[0]+200*sin(angleop1*pi);
    //iFilledPolygon(op1x,op1y,5);
    iRotate(op1x[0],op1y[0],angleop1-90);
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            if(img[j][i][0]!=0){
                iSetColor(img[j][i][0],img[j][i][1],img[j][i][2]);
                iPoint(i+op1x[0],j+op1y[0],2);
            }
        }
    }
    iUnRotate();
}



