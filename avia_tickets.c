#include <stdio.h>
#include <string.h>

typedef struct Airline {
    char from[50];
    char to[50];
    char data[11];
    float price_ticket;
} Avia;

void sortReyslarByDate(Avia reys[], int n) {
    Avia temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int dayA, monthA, yearA;
            int dayB, monthB, yearB;

            sscanf(reys[i].from, "%d-%d-%d", &dayA, &monthA, &yearA);
            sscanf(reys[j].from, "%d-%d-%d", &dayB, &monthB, &yearB);

            int dateA = dayA + monthA * 100 + yearA * 10000;
            int dateB = dayB + monthB * 100 + yearB * 10000;

            if (dateA > dateB) {
                temp = reys[i];
                reys[i] = reys[j];
                reys[j] = temp;
            }
        }
    }
}

int main() {
    Avia reys[10] = {
        {"Toshkent", "London", "15-04-2025", 450.00},
        {"Moskva", "Tokio", "10-06-2025", 550.00},
        {"Parij", "New York", "25-03-2025", 650.00},
        {"Istanbul", "Berlin", "18-05-2025", 300.00},
        {"London", "Dubai", "05-06-2025", 500.00},
        {"New York", "Los Angeles", "30-04-2025", 400.00},
        {"Berlin", "Moskva", "10-07-2025", 350.00},
        {"Dubai", "Toshkent", "15-05-2025", 500.00},
        {"Los Angeles", "Parij", "20-08-2025", 700.00},
        {"Tokio", "Istanbul", "28-09-2025", 600.00}
    };

    sortReyslarByDate(reys, 10);

    printf("Reyslar uchish sanasi bo'yicha o'sib borish tartibida:\n\n");

    for (int i = 0; i < 10; i++) {
        printf("Uchish shahri: %s\n", reys[i].from);
        printf("Qo’nish shahri: %s\n", reys[i].to);
        printf("Uchish sanasi: %s\n", reys[i].data);
        printf("Bilet narxi: %.2f $\n\n", reys[i].price_ticket);
    }

    return 0;
}
