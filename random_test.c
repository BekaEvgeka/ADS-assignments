#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
main(){
    srand(time(NULL));

    int t = rand() % 5;
    printf("%d", t);
}