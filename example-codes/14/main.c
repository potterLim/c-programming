/*
 * Example code for: 14-File I/O
 * Purpose         : Loads product list, computes total values, and writes an inventory report
 */

#include <stdio.h>
#include "inventory.h"

int main(void)
{
    product_t products[MAX_PRODUCTS];

    // Load products from file
    int count = load_products("products.txt", products, MAX_PRODUCTS);
    if (count < 0) {
        printf("Failed to load product list.\n");
        return 1;
    }

    // Compute total value for each product
    for (int i = 0; i < count; ++i) {
        products[i].total_value = products[i].price * products[i].quantity;
    }

    // Save formatted report
    save_report("report.txt", products, count);
    printf("Inventory report saved to report.txt\n");

    return 0;
}
