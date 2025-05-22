#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    struct Book b;

    printf("Enter book title: ");
    fgets(b.title, sizeof(b.title), stdin);
    strtok(b.title, "\n");

    printf("Enter author name: ");
    fgets(b.author, sizeof(b.author), stdin);
    strtok(b.author, "\n");

    printf("Enter book price: ");
    scanf("%f", &b.price);

    FILE *fptr = fopen("book2.dat", "wb");
    if (!fptr) return 1;
    fwrite(&b, sizeof(struct Book), 1, fptr);
    fclose(fptr);

    struct Book rb;
    fptr = fopen("book2.dat", "rb");
    fread(&rb, sizeof(struct Book), 1, fptr);
    fclose(fptr);

    printf("\nTitle: %s\nAuthor: %s\nPrice: %.2f\n", rb.title, rb.author, rb.price);
    return 0;
}
