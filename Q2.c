#include <stdio.h>

#define MAX 100


void customerInfo(char name[], long long *cnic);
void showInventory(int code[], int stock[], int price[], int n);
void addToCart(int code[], int stock[], int price[], int n, int cartCode[], int cartQty[], int *cartCount);
void updateInventory(int code[], int stock[], int cartCode[], int cartQty[], int cartCount, int n);
float totalBill(int cartCode[], int cartQty[], int cartCount, int code[], int price[], int n);
void showInvoice(char name[], long long cnic, float bill, int discount);

int main() {
    int code[4] = {1, 2, 3, 4};
    int stock[4] = {50, 10, 20, 8};
    int price[4] = {100, 200, 300, 150};

    int cartCode[MAX];
    int cartQty[MAX];
    int cartCount = 0;

    char name[50];
    long long cnic = 0;
    int choice;
    float bill = 0;
    int discount = 0;

    do {
        printf("\n1. Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Update Inventory\n");
        printf("5. Display Total Bill\n");
        printf("6. Show Invoice\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            customerInfo(name, &cnic);
        else if (choice == 2)
            showInventory(code, stock, price, 4);
        else if (choice == 3)
            addToCart(code, stock, price, 4, cartCode, cartQty, &cartCount);
        else if (choice == 4)
            updateInventory(code, stock, cartCode, cartQty, cartCount, 4);
        else if (choice == 5)
            bill = totalBill(cartCode, cartQty, cartCount, code, price, 4);
        else if (choice == 6)
            showInvoice(name, cnic, bill, discount);
        else if (choice == 7)
            printf("Goodbye!\n");
        else
            printf("Invalid choice.\n");

    } while (choice != 7);

    return 0;
}


void customerInfo(char name[], long long *cnic) {
    printf("Enter customer name: ");
    scanf("%s", name);
    printf("Enter CNIC: ");
    scanf("%lld", cnic);
    printf("Customer info saved.\n");
}

// Show all products
void showInventory(int code[], int stock[], int price[], int n) {
    printf("\nProduct Code | Stock | Price\n");
    for (int i = 0; i < n; i++) {
        printf("     %03d      |  %d   |  %d\n", code[i], stock[i], price[i]);
    }
}


void addToCart(int code[], int stock[], int price[], int n, int cartCode[], int cartQty[], int *cartCount) {
    int c, q, found = 0;
    printf("Enter product code: ");
    scanf("%d", &c);

    for (int i = 0; i < n; i++) {
        if (code[i] == c) {
            found = 1;
            printf("Enter quantity: ");
            scanf("%d", &q);
            if (q > stock[i]) {
                printf("Not enough stock. Available: %d\n", stock[i]);
                return;
            }
            cartCode[*cartCount] = c;
            cartQty[*cartCount] = q;
            (*cartCount)++;
            printf("Item added to cart.\n");
        }
    }

    if (!found)
        printf("Invalid code.\n");
}


void updateInventory(int code[], int stock[], int cartCode[], int cartQty[], int cartCount, int n) {
    for (int i = 0; i < cartCount; i++) {
        for (int j = 0; j < n; j++) {
            if (cartCode[i] == code[j]) {
                stock[j] -= cartQty[i];
                if (stock[j] < 0)
                    stock[j] = 0;
            }
        }
    }
    printf("Inventory updated.\n");
}


float totalBill(int cartCode[], int cartQty[], int cartCount, int code[], int price[], int n) {
    float sum = 0;
    for (int i = 0; i < cartCount; i++) {
        for (int j = 0; j < n; j++) {
            if (cartCode[i] == code[j]) {
                sum += cartQty[i] * price[j];
            }
        }
    }

    printf("Total bill: %.2f\n", sum);

    char promo[20];
    printf("Do you have a promo code? (yes/no): ");
    scanf("%s", promo);

    if (promo[0] == 'y' || promo[0] == 'Y') {
        char codeWord[20];
        printf("Enter promo code: ");
        scanf("%s", codeWord);

        if (codeWord[0] == 'E' && codeWord[1] == 'i' && codeWord[2] == 'd') {
            printf("Promo code applied! 25%% discount.\n");
            sum = sum * 0.75;
        } else {
            printf("Invalid promo code.\n");
        }
    }

    printf("Final bill: %.2f\n", sum);
    return sum;
}

// Show invoice
void showInvoice(char name[], long long cnic, float bill, int discount) {
    printf("\n INVOICE \n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %lld\n", cnic);
    printf("Final Bill: %.2f\n", bill);
    printf("---------------------\n");
}
