#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   

#define MAX_DISKS 10

int rodA[MAX_DISKS], rodB[MAX_DISKS], rodC[MAX_DISKS];
int topA = -1, topB = -1, topC = -1;

void push(int rod[], int *top, int disk) {
    rod[++(*top)] = disk;
}

int pop(int rod[], int *top) {
    if (*top == -1) return -1;
    return rod[(*top)--];
}

void printRods(int n) {
    system("clear");  

    printf("\n\tTOWER OF HANOI VISUALIZATION\n");
    printf("\n--------------------------------------------\n");
    printf("  A\t\tB\t\tC\n");
    printf("--------------------------------------------\n");

    for (int i = n - 1; i >= 0; i--) {
        printf("  ");
        if (i <= topA) printf("%d", rodA[i]); else printf("|");
        printf("\t\t");

        if (i <= topB) printf("%d", rodB[i]); else printf("|");
        printf("\t\t");

        if (i <= topC) printf("%d", rodC[i]); else printf("|");

        printf("\n");
    }

    printf("--------------------------------------------\n");
    sleep(1);  // 1 sec delay
}

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 0)
        return;

    towerOfHanoi(n - 1, from, aux, to);

    int disk;
    if (from == 'A') disk = pop(rodA, &topA);
    else if (from == 'B') disk = pop(rodB, &topB);
    else disk = pop(rodC, &topC);

    if (to == 'A') push(rodA, &topA, disk);
    else if (to == 'B') push(rodB, &topB, disk);
    else push(rodC, &topC, disk);

    printRods(n);
    printf("\nMove disk %d from %c → %c\n", disk, from, to);
    sleep(1);

    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n;

    printf("Enter number of disks (max 10): ");
    scanf("%d", &n);

    if (n > MAX_DISKS || n < 1) {
        printf("Invalid number of disks!\n");
        return 0;
    }

    for (int i = n; i >= 1; i--)
        push(rodA, &topA, i);

    printRods(n);

    towerOfHanoi(n, 'A', 'C', 'B');

    printf("\nAll disks moved successfully!\n");
    return 0;
}