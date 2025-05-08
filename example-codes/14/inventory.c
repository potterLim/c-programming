#include <stdio.h>
#include "inventory.h"

// Load products from a file
int load_products(const char* filename, product_t* products, int max_count)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1; // File open failed
    }

    int count = 0;
    while (count < max_count && fscanf(fp, "%s %f %d", products[count].name, &products[count].price, &products[count].quantity) == 3)
    {
        ++count;
    }

    fclose(fp);
    return count;
}

// Save a formatted inventory report to a file
void save_report(const char* filename, const product_t* products, int count)
{
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Failed to open output file\n");
        return;
    }

    fprintf(fp, "Product Name       Price   Qty    Total Value\n");
    fprintf(fp, "---------------------------------------------\n");

    for (int i = 0; i < count; ++i) {
        fprintf(fp, "%-18s %6.2f %5d %12.2f\n", products[i].name, products[i].price, products[i].quantity, products[i].total_value);
    }

    fclose(fp);
}
