
void iMouseMenu(double mx,double my){
//    if(mx>520 && mx<780){
//        if(my>685 && my<735){
//            normalrace();
//        }
//    }
//    if(mx>520 && mx<780){
//        if(my>635 && my<685){
//            mouse=1;
//        }
//    }
//    if(mx>520 && mx<780){
//        if(my>585 && my<635){
//            setting=1;
//            menu=0;
//            mouse=1;
//        }
//    }

}

//void iMouseSetting(double mx,double my){
//    if(mx>520 && mx<780){
//        if(my>535 && my<585){
//            setting=0;
//            menu=1;
//            mouse=1;
//        }
//    }
//}

//void iMousePause(double mx,double my){
//    if(mx>520 && mx<780){
//        if(my>685 && my<735){
//            iResumeTimer(0);
//            iResumeTimer(1);
//            singleplayer=1;
//            pause=0;
//        }
//    }
//    if(mx>520 && mx<780){
//        if(my>635 && my<685){
//            carselect=1;
//            pause=0;
//        }
//    }
//    if(mx>520 && mx<780){
//        if(my>585 && my<635){
//            menu=1;
//            menumusic();
//            pause=0;
//        }
//    }
//}

void iMouse(int button,int state,int mx,int my){

    if(button ==GLUT_LEFT_BUTTON && state==GLUT_UP){
//        sprintf(mo,"%d %d",mx,my);
//        if(menu)iMouseMenu(mx,my);
//        else if(setting)iMouseSetting(mx,my);
//        else if(pause)iMousePause(mx,my);
        hint=1;
    }
}

void iMouseMove(int mx,int my){
}
