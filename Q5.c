#include <stdio.h>

int findLength(char message[]) {
    int i = 0;
    while (message[i] != '\0') {
        i++;
    }
    return i;
}


void reverseString(char message[]) {
    int i = 0, j;
    char temp;
    j = findLength(message) - 1;
    while (i < j) {
        temp = message[i];
        message[i] = message[j];
        message[j] = temp;
        i++;
        j--;
    }
}


char toggleBits(char ch) {
    ch = ch ^ (1 << 1); 
    ch = ch ^ (1 << 4); 
    return ch;
}


void encodeMessage(char message[]) {
    int i;
    reverseString(message);
    for (i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]);
    }
    printf("\nEncoded Message: %s\n", message);
}


void decodeMessage(char message[]) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]); 
    }
    reverseString(message); 
    printf("\nDecoded Message: %s\n", message);
}

int main() {
    char message[200];
    int choice;

    while (1) {
        printf("\nTCS Secure Message System \n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 1) {
            printf("Enter your message: ");
            int i = 0;
            char ch;
            while (1) {
                ch = getchar();
                if (ch == '\n') break;
                message[i++] = ch;
            }
            message[i] = '\0';
            encodeMessage(message);
        }
        else if (choice == 2) {
            printf("Enter encoded message: ");
            int i = 0;
            char ch;
            while (1) {
                ch = getchar();
                if (ch == '\n') break;
                message[i++] = ch;
            }
            message[i] = '\0';
            decodeMessage(message);
        }
        else if (choice == 3) {
            printf("Exiting system\n");
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
