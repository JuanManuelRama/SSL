#include "histograma.h"


int* contar(){
    int* longitudes = calloc(MAX_LEN+1, sizeof *longitudes);
    int wl=0;
    goto Out;

    Out:
        switch (getchar()){
            case '\n':
            case ' ':
            case '\t':
                goto Out;
            case EOF:
                goto End;
            default:
                ++wl;
                goto In;
            
        }
    In:
        switch(getchar()){
            case '\n':
            case ' ':
            case '\t':
            if(wl>MAX_LEN)
                ++longitudes[MAX_LEN];
            else 
                longitudes[wl]++;
            wl=0;
            goto Out;
            default:
                ++wl;
                goto In;
        }

    End:
        return longitudes;
}

