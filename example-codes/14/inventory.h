#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 64

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
    float total_value;
} product_t;

// Returns the number of products loaded, or -1 on failure
int load_products(const char* filename, product_t* products, int max_count);
void save_report(const char* filename, const product_t* products, int count);

#endif /* INVENTORY_H */
