#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void AllPossibleStrings(char *s) {
    int n = strlen(s);
    int total = (1 << n);
    char **ans = (char **)malloc(total * sizeof(char *));
    int count = 0;

    for (int num = 0; num < total; num++) {
        char sub[n + 1];
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (num & (1 << i)) {
                sub[index++] = s[i];
            }
        }
        sub[index] = '\0';
        if (index > 0) {
            ans[count] = (char *)malloc((index + 1) * sizeof(char));
            strcpy(ans[count], sub);
            count++;
        }
    }

    qsort(ans, count, sizeof(char *), compare);

    printf("All possible subsequences are:\n");
    for (int i = 0; i < count; i++) {
        printf("%s ", ans[i]);
        free(ans[i]);
    }
    printf("\n");
    free(ans);
}

int main() {
    char s[] = "abc";
    AllPossibleStrings(s);
    return 0;
}
