// main.c
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
    item_list[index].price = price;

    item_list[index].sku = malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);

    item_list[index].category = malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);

    item_list[index].name = malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        free(item_list[i].sku);
        free(item_list[i].category);
        free(item_list[i].name);
    }
    free(item_list);
}

double average_price(Item *item_list, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += item_list[i].price;
    }
    return total / size;
}

void print_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %f\n", item_list[i].price);
        printf("###############\n");
    }
}

int main(int argc, char *argv[]) {
    int size = 5;

    // Dynamically allocate space for 5 items
    Item *item_list = malloc(size * sizeof(Item));

    // Add 5 items to the list
    add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
    add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
    add_item(item_list, 4.20, "20384", "snacks", "chips", 2);
    add_item(item_list, 2.50, "10923", "produce", "apple", 3);
    add_item(item_list, 7.10, "30294", "meat", "chicken breast", 4);

    // Print all items
    print_items(item_list, size);

    // Calculate average price
    printf("average price of items = %f\n", average_price(item_list, size));

    // Command-line argument usage for SKU search
    if (argc > 1) {
        char *search_sku = argv[1];
        int found = 0;
        for (int i = 0; i < size; i++) {
            if (strcmp(item_list[i].sku, search_sku) == 0) {
                printf("\nItem found:\n");
                printf("item name = %s\n", item_list[i].name);
                printf("item sku = %s\n", item_list[i].sku);
                printf("item category = %s\n", item_list[i].category);
                printf("item price = %f\n", item_list[i].price);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Item not found\n");
        }
    }

    // Free allocated memory
    free_items(item_list, size);

    return 0;
}
