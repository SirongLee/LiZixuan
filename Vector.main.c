#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

typedef int ADT;

int main (){
    vector v;
    init (&v , sizeof (ADT));
    for (int i = 0;i < 10;i++){
        ADT a =i * 1.0;
        push_back (&v , &a);
    }
    ADT a = 10.0;
    insert (&v , 2 , (void*)&a);

    erase (&v , 2);

    for (int i = 0;i < v.size;i++){
        ADT a = 0;
        get_value (&v, i , &a);
        printf ("%d " , a);
    }
    printf ("\n");
    destory (&v);
    return 0;
}
