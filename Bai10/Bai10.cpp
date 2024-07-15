#include <stdio.h>
#include <ctype.h>
#include <string.h>

void to_uppercase(char* str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void capitalize_words(char* str) {
    int in_word = 0;
    while (*str) {
        if (isspace((unsigned char)*str)) {
            in_word = 0;
        }
        else {
            if (!in_word) {
                *str = toupper((unsigned char)*str);
                in_word = 1;
            }
        }
        str++;
    }
}

int main() {
    char st[100];

    printf("Nhap vao chuoi: ");
    fgets(st, sizeof(st), stdin);

    size_t len = strlen(st);
    if (len > 0 && st[len - 1] == '\n') {
        st[len - 1] = '\0';
    }

    char* ptr = st;
    printf("Gia tri tung ky tu cua chuoi:\n");
    while (*ptr) {
        printf("%c ", *ptr);
        ptr++;
    }
    printf("\n");

    to_uppercase(st);
    printf("Chuoi ve dang chu hoa: %s\n", st);

    capitalize_words(st);
    printf("Chuoi ve dang chu hoa o dau moi tu: %s\n", st);

    return 0;
}
