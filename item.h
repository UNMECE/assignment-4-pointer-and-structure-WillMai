// item.h
#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _Item {
    double price;
    char *sku;
    char *name;
    char *category;
};

typedef struct _Item Item;

#endif
