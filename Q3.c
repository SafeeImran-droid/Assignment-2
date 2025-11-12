#include <stdio.h>

#define ROWS 3
#define COLS 3

void update(int grid[ROWS][COLS]);
void query(int grid[ROWS][COLS]);
void run(int grid[ROWS][COLS]);

int main() {
    int grid[ROWS][COLS] = {0}; 
    int choice;

    do {
        printf("\nIESCO Grid Monitoring\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            update(grid);
        else if (choice == 2)
            query(grid);
        else if (choice == 3)
            run(grid);
        else if (choice == 4)
            printf("Exiting system...\n");
        else
            printf("Invalid choice.\n");

    } while (choice != 4);

    return 0;
}

void update(int grid[ROWS][COLS]) {
    int r, c, flag, setClear;

    printf("Enter row (0-%d): ", ROWS - 1);
    scanf("%d", &r);
    printf("Enter column (0-%d): ", COLS - 1);
    scanf("%d", &c);

    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
        printf("Invalid coordinates.\n");
        return;
    }

    printf("Select flag to modify:\n");
    printf("0 - Power Status\n");
    printf("1 - Overload Warning\n");
    printf("2 - Maintenance Required\n");
    scanf("%d", &flag);

    if (flag < 0 || flag > 2) {
        printf("Invalid flag.\n");
        return;
    }

    printf("Enter 1 to SET or 0 to CLEAR this flag: ");
    scanf("%d", &setClear);

    if (setClear == 1)
        grid[r][c] |= (1 << flag);   // setting the bit
    else
        grid[r][c] &= ~(1 << flag);  // clearing the bit

    printf("Sector updated successfully.\n");
}

void query(int grid[ROWS][COLS]) {
    int r, c;

    printf("Enter row: ");
    scanf("%d", &r);
    printf("Enter column: ");
    scanf("%d", &c);

    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
        printf("Invalid coordinates.\n");
        return;
    }

    int value = grid[r][c];
    printf("\nSector (%d, %d) Status:\n", r, c);
    printf("Power: %s\n", (value & 1) ? "ON" : "OFF");
    printf("Overload: %s\n", (value & 2) ? "YES" : "NO");
    printf("Maintenance Required: %s\n", (value & 4) ? "YES" : "NO");
}

void run(int grid[ROWS][COLS]) {
    int over_l_c = 0;
    int maint_c = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] & 2)
                over_l_c++;
            if (grid[i][j] & 4)
                maint_c++;
        }
    }

    printf("\nSystem Diagnostic Report:\n");
    printf("Overloaded Sectors: %d\n", over_l_c);
    printf("Sectors Requiring Maintenance: %d\n", maint_c);
}
