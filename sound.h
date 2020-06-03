void sound(){
    if(sounds){
        if(play1 && !pause)PlaySound("music//carstart.wav",NULL,SND_ASYNC);
        else if(play2 && !pause)PlaySound("music//cars.wav",NULL,SND_ASYNC | SND_LOOP);
        else PlaySound(NULL,NULL,SND_ASYNC);
    }
}

void pausemusic(){
    if(sounds){
        if(pause) PlaySound("music//pause.wav",NULL,SND_ASYNC | SND_LOOP);
        if(!pause) PlaySound(NULL,NULL,SND_ASYNC);
    }
}

void carselectmusic(){
    if(sounds){
        if(carselect)PlaySound("music//carselect.wav",NULL,SND_ASYNC | SND_LOOP);
        else PlaySound(NULL,NULL,SND_ASYNC);
    }
}

void dragcarselectmusic(){
    if(sounds){
        if(dragracecarselect)PlaySound("music//carselect.wav",NULL,SND_ASYNC | SND_LOOP);
        else PlaySound(NULL,NULL,SND_ASYNC);
    }
}

void menumusic(){
    if(sounds){
        if(menu) PlaySound("music//menu.wav",NULL,SND_ASYNC | SND_LOOP);
        else PlaySound(NULL,NULL,SND_ASYNC);
    }
    else PlaySound(NULL,NULL,SND_ASYNC);
}

void dragracemusic(){
    if(sounds){
        if(dragrace)PlaySound("music//dragrace.wav",NULL,SND_ASYNC | SND_LOOP);
        else PlaySound(NULL,NULL,SND_ASYNC);
    }
}
void winmusic(){
    if(sounds){
        if(win)PlaySound("music//win.wav",NULL,SND_ASYNC | SND_LOOP);
        else PlaySound(NULL,NULL,SND_ASYNC);
    }
}
void losemusic(){
    if(sounds){
        if(lose)PlaySound("music//lose.wav",NULL,SND_ASYNC | SND_LOOP);
        else PlaySound(NULL,NULL,SND_ASYNC);
    }
}
