#include "histograma.h"
extern const int MAX_LEN;
int* contar(){
    int* longitudes = calloc(MAX_LEN+1, sizeof *longitudes);
    int length=0;
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
                ++length;
                goto In;
            
        }
    In:
        switch(getchar()){
            case '\n':
            case ' ':
            case '\t':
            longitudes[length]++;
            length=0;
            goto Out;
            default:
                ++length;
                goto In;
        }

    End:
        return longitudes;
}

