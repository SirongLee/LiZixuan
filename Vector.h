#ifndef INCLUDE_LESLEE_VECTOR__
#define INCLUDE_LESLEE_VECTOR__

typedef struct{
    int size;
    int capacity;
    void *base;
    int type_size;
}vector;

void init (vector* v,  int type_size);

void get_value (vector* v , int pos , void* to);

void push_back (vector* v,  void * from);

int size ( vector * v);

int capacity ( vector * v);

void destory (vector* v);

void pop_back (vector* v);

int insert (vector* v , int pos ,  void* val);

int erase (vector* v , int pos);

#endif
