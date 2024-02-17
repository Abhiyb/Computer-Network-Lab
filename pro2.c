#include <stdio.h>
#include <string.h>

void getval(char ipadd[]) {
    int a, b, c, d;
    sscanf(ipadd, "%d.%d.%d.%d", &a, &b, &c, &d);
    if (a >= 0 && a <= 127) {
        printf("Class A\n");
        printf("Network ID: %d\n", a);
        printf("Host ID: %d.%d.%d\n", b, c, d);
    } else if (a >= 128 && a <= 191) {
        printf("Class B\n");
        printf("Network ID: %d.%d\n", a, b);
        printf("Host ID: %d.%d\n", c, d);
    } else if (a >= 192 && a <= 223) {
        printf("Class C\n");
        printf("Network ID: %d.%d.%d\n", a, b, c);
        printf("Host ID: %d\n", d);
    } else if (a >= 224 && a <= 239) {
        printf("Class D\n");
    } else if (a >= 240 && a <= 255) {
        printf("Class E\n");
    } else {
        printf("Invalid IP address\n");
    }
}

int main() {
    char ipadd[16];
    printf("Enter an IP address: ");
    scanf("%s", ipadd);
    getval(ipadd);
    return 0;
}
