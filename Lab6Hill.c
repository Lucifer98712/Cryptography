#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int encryption(){
    int x, y, i, j, k, n;
    printf("Enter the size of key matrix: ");
    scanf("%d", &n);
    printf("Enter the key matrix:\n");
    int a[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the message to encrypt: ");
    char s[100];
    scanf("%s", s);
    int temp = (n - strlen(s) % n) % n;
    for (i = 0; i < temp; i++) {
        strcat(s, "x");
    }
    k = 0;
    char ans[1000] = "";
    while (k < strlen(s)) {
        for (i = 0; i < n; i++) {
            int sum = 0;
            int temp = k;
            for (j = 0; j < n; j++) {
                sum += (a[i][j] % 26 * (s[temp++] - 'a') % 26) % 26;
                sum = sum % 26;
            }
            ans[strlen(ans)] = sum + 'a';
        }
        k += n;
    }
    ans[strlen(ans)] = '\0';
    printf("%s\n", ans);

    return 0;
}

int main(){
   encryption();
}

