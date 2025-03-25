#include <stdio.h>

#define BAGSIZE 50

typedef struct b {
    int item[BAGSIZE];
} Bag;

void init(Bag *b);

int size(Bag *b);

int insert(Bag *b, int elm);

int check(Bag *b, int elem);

int delete(Bag *b, int elem);

void printall(Bag *b);