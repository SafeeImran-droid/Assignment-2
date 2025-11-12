#include <stdio.h>

#define MAX 100

void addBook(int id[], char name[][50], float price[], int qty[], int *count);
void sellBook(int id[], char name[][50], float price[], int qty[], int count);
void lowStock(int id[], char name[][50], float price[], int qty[], int count);

void readLine(char str[], int size);

int main() {
    int id[MAX];
    char name[MAX][50];
    float price[MAX];
    int qty[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n1. Add Book\n");
        printf("2. Sell Book\n");
        printf("3. Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        while (getchar() != '\n'); // clear enter key

        if (choice == 1)
            addBook(id, name, price, qty, &count);
        else if (choice == 2)
            sellBook(id, name, price, qty, count);
        else if (choice == 3)
            lowStock(id, name, price, qty, count);
        else if (choice == 4)
            printf("Goodbye!\n");
        else
            printf("Invalid choice.\n");

    } while (choice != 4);

    return 0;
}

void addBook(int id[], char name[][50], float price[], int qty[], int *count) {
    if (*count >= MAX) {
        printf("No more space.\n");
        return;
    }

    int code, same = 0;
    printf("Enter ISBN: ");
    scanf("%d", &code);

    for (int i = 0; i < *count; i++) {
        if (id[i] == code) {
            same = 1;
            break;
        }
    }

    if (same) {
        printf("This book already exists.\n");
        return;
    }

    id[*count] = code;

    while (getchar() != '\n'); // clear input
    printf("Enter Title: ");
    readLine(name[*count], 50);

    printf("Enter Price: ");
    scanf("%f", &price[*count]);
    printf("Enter Quantity: ");
    scanf("%d", &qty[*count]);

    (*count)++;
    printf("Book added.\n");
}

void sellBook(int id[], char name[][50], float price[], int qty[], int count) {
    if (count == 0) {
        printf("No books yet.\n");
        return;
    }

    int code, num;
    printf("Enter ISBN: ");
    scanf("%d", &code);

    for (int i = 0; i < count; i++) {
        if (id[i] == code) {
            printf("Enter number sold: ");
            scanf("%d", &num);

            if (num > qty[i])
                printf("Not enough in stock. Only %d left.\n", qty[i]);
            else {
                qty[i] -= num;
                printf("Sale done. Now %d left.\n", qty[i]);
            }
            return;
        }
    }

    printf("Book not found.\n");
}

void lowStock(int id[], char name[][50], float price[], int qty[], int count) {
    int found = 0;
    printf("\nBooks with less than 5 in stock:\n");

    for (int i = 0; i < count; i++) {
        if (qty[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Qty: %d\n",
                   id[i], name[i], price[i], qty[i]);
            found = 1;
        }
    }

    if (!found)
        printf("All books have enough stock.\n");
}

void readLine(char str[], int size) {
    int i = 0;
    char c;
    while (i < size - 1) {
        c = getchar();
        if (c == '\n' || c == EOF)
            break;
        str[i] = c;
        i++;
    }
    str[i] = '\0';
}
