int len=0;
void iKeyboard(unsigned char key){
    if(takename){
        win=1;
        int i;
        if(key == '\r' )
        {
            if(str[0]!=0)strcpy(lb[selectlevel][leaderindx].name,str);
            leaderboardsave();
            //printf("%s\n", str2);

            iText(650,275,str);
            for(i = 0; i < len; i++)
                str[i] = 0;
            len = 0;
            takename=0;
            leaderb=1;
            leadermode=selectlevel;
            win=0;
        }
        else if(key==8){
            if(len){
                str[len-1]=0;
                len--;
            }
        }
        else if((key>=48 && key <=57) || (key>=65 && key<=90) || (key>=97 && key<=122))
        {
            if(len<15){
                str[len] = key;
                len++;
            }
        }
    }
    else{
    if(key=='w' && dragrace && enter)
    {

        if(td1>=100 && td1<200 && cnt1<5)
        {
            geart1[0]=0;
            geart1[2]=0;
            geart1[1]=1;
            vdg1+=8;
        }
        else if(td1>=200 && td1<250 && cnt1<5)
        {
            geart1[0]=0;
            geart1[2]=1;
            geart1[1]=0;
            vdg1+=15;
        }
        else if(td1<100 && cnt1<5)
        {
            geart1[0]=1;
            geart1[2]=0;
            geart1[1]=0;
            vdg1+=4;
        }

        td1=0;
        cnt1++;
    }
    else if(key==' '){
        if((win && !leaderb)|| lose){
            menu=1;
            leaderb=0;
            getname=0;
            singleplayer=0;
            win=0;
            lose=0;
            enter=0;
            iPauseTimer(0);
            iPauseTimer(1);
            winmusic();
            losemusic();
            menumusic();
        }
        else
        enter++;
        if(dragrace && enter){
            iResumeTimer(2);
            start=1;
            dragracemusic();
        }
        if(drp1 || drp2 || rd){
            iPauseTimer(2);
            dragrace=0;
            menu=1;
            key=0;
            menumusic();
            dragracemusic();
            drag1=1;
            drag2=0;
            drp1=0;
            drp2=0;
            rd=0;
        }
        if(enter==1 && singleplayer==1){
        iResumeTimer(0);
        iResumeTimer(1);
        timestart=clock();
        enter++;
        sound();
        if(op1x[1]==500 && op1y[1]==400)timeelasped=0;
        }
    }
    else if(key==13){
            //enter==13
        key=1;
        if(leaderb){leaderb=0;key=0;menu=1;menumusic();}
        if((win || lose)&& key){
            key=0;
            menu=1;
            getname=0;
            win=0;
            lose=0;
            winmusic();
            losemusic();
            menumusic();
        }
        int key2;
        if(carselect && !level){
            if(menukey[1]){
                level=1;
                key2=0;
            }
        }
        if(level && !key2)key2=1;
        else if(key2 && level){
            level=0;
            key2=0;
            carselect=0;
            newmatchfunc();
            iResumeTimer(4);
            gameload=1;
            enter=0;
            iOpponentCarSelection();
            carselectmusic();
        }
        if(menu && con_exit && key){
            if(exitkey)exit(0);
            else con_exit=0;
            key=0;
        }
        else if(menu && key){
            if(menukey[0]){iResumeTimer(4);gameload=1;menu=0;menumusic();}
            else if(menukey[1])normalrace();
            else if(menukey[2]){dragracecarselect=1;drag1=1;drag2=0;menu=0;dragcarselectmusic();}
            else if(menukey[3]){leaderb=1;menu=0;}
            else if(menukey[4]){sounds=!sounds;menumusic();}
            else if(menukey[5]){help=1;menu=0;}
            else if(menukey[6]){about=1;menu=0;}
            else if(menukey[7]){con_exit=1;}
            key=0;
        }
        else if(key && about){about=0;menu=1;key=0;}
        if(pause && key){
            if(pausekey[0]){
                if(menukey[1]){
                    singleplayer=1;
                    pause=0;
                    pausemusic();
                    if(enter){
                        iResumeTimer(0);
                        iResumeTimer(1);
                        timestart=clock();
                    }
                }
                if(menukey[2]){
                    dragrace=1;
                    pause=0;
                    pausemusic();
                }
            }
            if(pausekey[1]){
                if(menukey[1]){
                    carselect=1;
                    pause=0;
                    pausemusic();
                    carselectmusic();
                }
                if(menukey[2]){
                    drag1=1;
                    drag2=0;
                    dragracecarselect=1;
                    pause=0;
                    pausemusic();
                    dragcarselectmusic();
                }
            }
            if(pausekey[2]){
                pause=0;
                pausemusic();
                menu=1;
                menumusic();
            }
            if(pausekey[3]){
                if(menukey[1])savenormalgame();
                if(menukey[2])savedraggame();
                exit(0);
            }
            key=0;
        }
        else if(dragracecarselect  && key){
            if(drag1){drag2=1;drag1=0;}
            else if(drag2){
                iResumeTimer(4);gameload=1;
                dragracemusic();
                dragracecarselect=0;
                dragcarselectmusic();
                enter=0;
                dragnewgame();
            }
            key=0;
        }
        else if(drp1 || drp2 || rd){
            iPauseTimer(2);
            dragrace=0;
            menu=1;
            key=0;
            dragracemusic();
            menumusic();
            drag1=1;
            drag2=0;
            drp1=0;
            drp2=0;
            rd=0;
        }
    }

    else if(key == 27){
            //esc==27
        if(carselect && !level){
            carselect=0;
            yellow=1;
            red=0;
            black=0;
            menu=1;
            carselectmusic();
            menumusic();
        }
        else if(level){
            level=0;
            carselect=1;
        }
        else if(dragracecarselect){
            if(drag1){
                dragracecarselect=0;
                menu=1;
                menumusic();
                dragcarselectmusic();
            }
            else if(drag2){
                drag1=1;
                drag2=0;
            }
        }
        else if(singleplayer){
            pause=!pause;
            pausemusic();
            singleplayer=!singleplayer;
            iPauseTimer(0);
            iPauseTimer(1);
            enter=0;
            timestop=clock();
            timeelasped=timeelasped+(double)(timestop-timestart)/CLOCKS_PER_SEC;
        }
        else if(dragrace && !drp1 && !drp2 && !rd){
            dragrace=!dragrace;
            pause=!pause;
            pausemusic();
            iPauseTimer(2);
            enter=0;
        }
        else if(help)
        {
            help=0;
            menu=1;
        }
        else if(pause){
            if(menukey[1]){
                singleplayer=!singleplayer;
                pause=!pause;
                pausemusic();
                if(enter){
                    iResumeTimer(0);
                    iResumeTimer(1);
                    timestart=clock();
                }
            }
            else if(menukey[2]){
                dragrace=!dragrace;
                pause=!pause;
                pausemusic();
                if(enter)iResumeTimer(2);
            }
        }
        else if(leaderb){
            leaderb=0;
            menu=1;
            menumusic();
        }
        else if(about){
            about=0;
            menu=1;
        }
    }
    }
}

void upkey(){
    if(singleplayer && enter){
        if(v<25){
            if(v<5)v+=.25;
            else if(v>speed)v+=0.0015;
            else v+=acceleration;
        }
    }
    else if(menu){
        int i;
        for(i=0;i<8;i++){
            if(menukey[i]==1){
                menukey[(i+7)%8]=1;
                menukey[i]=0;
                break;
            }
        }
    }
    else if(pause){
        int i;
        for(i=0;i<4;i++){
            if(pausekey[i]==1){
                pausekey[(i+3)%4]=1;
                pausekey[i]=0;
                break;
            }
        }
    }
    else if(dragrace && enter){

        if(refy2>-5700)
        {
            //mycary+=5;
            //refy-=10;
        }
        if(td2>=100 && td2<200 && cnt2<5)
        {
            geart2[0]=0;
            geart2[2]=0;
            geart2[1]=1;
            vdg2+=8;
        }
        else if(td2>=200 && td2<250 && cnt2<5)
        {
            geart2[0]=0;
            geart2[2]=1;
            geart2[1]=0;
            vdg2+=15;
        }
        else if(td2<100 && cnt2<5)
        {
            geart2[0]=1;
            geart2[2]=0;
            geart2[1]=0;
            vdg2+=4;
        }


        td2=0;
        cnt2++;
    }

}

void downkey(){
    if(menu){
        int j;
        for(j=0;j<8;j++){
            if(menukey[j]==1){
                menukey[(j+1)%8]=1;
                menukey[j]=0;
                break;
            }
        }
    }
    else if(pause){
        int j;
        for(j=0;j<4;j++){
            if(pausekey[j]==1){
                pausekey[(j+1)%4]=1;
                pausekey[j]=0;
                break;
            }
        }
    }
    else if(singleplayer && enter){
        sound();
        if(v>15){
            v-=1.2;
        }
        else if(v>-5){
            v-=1.1;
        }
        else if(v>-15){
            v--;
        }
    }
}

void rightkey(){
    if(singleplayer && enter){
        afterangle-=2;
        if(angle<-270)angle+=360;
        carx[0]=carx[1]-50*cos(pi*(90-angle));
        cary[0]=cary[1]+50*sin(pi*(90-angle));
        carx[2]=carx[1]+50*cos(pi*(90-angle));
        cary[2]=cary[1]-50*sin(pi*(90-angle));
        if(v>=15)v-=drift+.1;
    }
    else if(carselect && !level){
        if(yellow){
            yellow=0;
            red=1;
        }
        else if(red){
            black=1;
            red=0;
        }
        else if(black){
            black=0;
            yellow=1;
        }
    }
    else if(level){
        if(selectlevel==0)selectlevel=1;
        else if(selectlevel==1)selectlevel=2;
        else if(selectlevel==2)selectlevel=0;
    }
    else if(dragracecarselect){
        if(drag1)dr1=(dr1+3)%3+1;
        if(drag2)dr2=(dr2+3)%3+1;
    }
    else if(con_exit)exitkey=!exitkey;

    else if(leaderb){
        leadermode=(leadermode+1)%3;
    }
    else if(help)
    {
        helpkey=(helpkey+1)%3;
    }
}

void leftkey(){
    if(leaderb){
        leadermode=(leadermode+2)%3;
    }
    else if(help)
    {
        helpkey=(helpkey+2)%3;
    }

    else if(con_exit)exitkey=!exitkey;
    else if(singleplayer && enter){
        afterangle+=2;
        if(angle>=180)angle-=360;
        carx[0]=carx[1]-50*cos(pi*(90-angle));
        cary[0]=cary[1]+50*sin(pi*(90-angle));
        carx[2]=carx[1]+50*cos(pi*(90-angle));
        cary[2]=cary[1]-50*sin(pi*(90-angle));
        if(v>=15)v-=drift+.5;
    }
    else if(carselect && !level){
        if(yellow){
            yellow=0;
            black=1;
        }
        else if(red){
            yellow=1;
            red=0;
        }
        else if(black){
            black=0;
            red=1;
        }
    }
    else if(level){
        if(selectlevel==0)selectlevel=2;
        else if(selectlevel==1)selectlevel=0;
        else if(selectlevel==2)selectlevel=1;
    }
    else if(dragracecarselect){
        if(drag1)dr1=(dr1+1)%3+1;
        if(drag2)dr2=(dr2+1)%3+1;
    }
}

void iSpecialKeyboard(unsigned char key){
    if(singleplayer){
    if(key == GLUT_KEY_UP || GLUT_UP){
        upkey();
    }
    }
    else{
        if(key == GLUT_KEY_UP){
        upkey();
    }
    }
    if(key == GLUT_KEY_DOWN ){
        downkey();
    }
    if(key == GLUT_KEY_RIGHT){
        rightkey();
    }
    if(key == GLUT_KEY_LEFT){
        leftkey();
    }
    if(hint)hint=0;
}
