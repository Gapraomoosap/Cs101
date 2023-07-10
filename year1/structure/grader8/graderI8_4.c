#include <stdio.h>
#include <string.h>

int main() {
    int n, max_len = 0;
    char strings[100][100];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
        int len = strlen(strings[i]);
        if (len > max_len) {
            max_len = len;
        }
    }
    
    char result[100];
    int index = 0;
    for (int i = 0; i < max_len; i++) {
        for (int j = 0; j < n; j++) {
            if (strings[j][i] != '\0') {
                result[index] = strings[j][i];
                index++;
            }
        }
    }
    result[index] = '\0';
    
    // Print the result
    printf("%s\n", result);
    
    return 0;
}
