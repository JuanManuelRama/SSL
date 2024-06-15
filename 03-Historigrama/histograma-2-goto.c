#include <stdio.h>
int main(){
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
            printf("%d ", length);
            length=0;
            goto Out;
            default:
                ++length;
                goto In;
        }

    End:
        return 0;
}

