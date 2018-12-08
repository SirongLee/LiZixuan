#include "Vector.h"
#include <stdlib.h>
#include <string.h>

void init (vector* v, int type_size){
    v -> size = 0;
    v -> type_size = type_size;
    v -> base = 0;
    v -> capacity = 0;
}

void get_value (vector* v , int pos , void* to){
    char * base = (char*)v -> base;
    memcpy (to , base + pos * v -> type_size , v -> type_size);
}

void add_memory (vector* v , int size){
    void* new_base = malloc (v -> type_size * size);
    memcpy (new_base , v -> base , v -> size * v -> type_size);
    if (!v -> base)
        free (v -> base);
    v -> base = new_base;
    v -> capacity = size;
}

void push_back (vector* v,  void * from){
    if (v -> capacity == 0){
        add_memory (v , 1);
        char *tmp = (char*) v -> base;
        memcpy (tmp , from , v -> type_size);
        v -> size++;
    }
    else {
        if (v -> capacity == v -> size){
            add_memory (v , v -> capacity * 2);
            char *tmp = (char*) v -> base;
            memcpy (tmp + (v -> size * v -> type_size) , from , v -> type_size);
        }   
        else {
            char *tmp = (char*) v -> base;
            memcpy (tmp + (v -> size * v -> type_size) , from , v -> type_size);
        }
        v -> size++;
    }
}

int size ( vector * v){
    return v -> size;
}

int capacity ( vector * v){
    return v -> capacity;
}

void destory(vector* v){
    free (v -> base);
    v -> base = 0;
    v -> capacity = 0;
    v -> size = 0;
    v -> type_size = 0;
}

void pop_back (vector* v){
    // if (v -> type_size == 0){
    //     // return ;
    // }
    if (v -> type_size == 1){
        free(v -> base);
        v -> base = NULL;
        v -> type_size = 0;
        v -> capacity = 0;
    }
    else if(v -> type_size - 1 == v -> capacity/2){
        void *new_base = malloc (v -> type_size);
        memcpy(new_base , v -> base , v -> type_size - 1);
        free(v -> base);
        v -> base = new_base;
        v -> size--;
    }
    v -> size--;
}

int insert (vector* v , int pos ,  void* val){
    if (pos == v -> size + 1){
        push_back (v , val);
        return 1;
    }
    if (pos < 0 || pos > v -> size){
        return 0;
    }
    if (v -> size ==  v -> capacity){
        add_memory (v , v -> capacity * 2);
    }
    char * tmp = (char*)malloc ((v -> size - pos + 1) * v -> type_size);
    char * t = (char*)v -> base;
    memcpy (tmp , t + (pos - 1) * v -> type_size , v -> type_size * (v -> size - pos + 1));
    memcpy (t + (pos - 1) * v -> type_size , val , v -> type_size);
    memcpy (t + pos * v -> type_size , tmp , v -> type_size * (v -> size - pos + 1));
    free (tmp);
    v -> size++;
    return 1;
}

int erase (vector* v , int pos){
    if (v -> size == 0 || pos > v -> size || pos < 0){
        return 0;
    }
    char * tmp = (char*)malloc ((v -> size - pos) * v -> type_size);
    char * t = (char*)v -> base;
    memcpy (tmp , t + pos * v -> type_size , (v -> size - pos) * v -> type_size);
    memcpy (t + (pos - 1) * v -> type_size , tmp , (v -> size - pos) * v -> type_size);
    free (tmp);
    v -> size--;
    return 1;
}
