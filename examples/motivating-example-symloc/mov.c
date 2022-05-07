#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <wchar.h>
#include <unistd.h>

static char* bad(int a)
{
    if (a == 0x1234ABCD){
        int size = 1024;
        char * data1 = (char *) malloc(size * sizeof(char));
        char * start = data1;
        char * end = data1 + size;
        for (int i = 0; i < 1023; i++){
            if (start > end){
                abort();
            }
            start++;
        }
        return NULL;
    }
    if (a == 0x1234DCBA) {
        wchar_t * data1 = NULL;
        data1 = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (data1 == NULL) { abort(); }
        wmemset(data1, L'A', 100-1);
        data1[100-1] = L'\0';
        free(data1);
        wprintf(L"%s\n", data1);
        return NULL;
    } else {
        char *data2 = NULL;
        data2 = (char*) malloc(100 * sizeof(char));
        if (data2 == NULL) { abort();}
        memset(data2, 'A', 100-1);
        data2[100-1] = '\0';
        free(data2);
        return data2;
    }
}

int main()
{
    int a ;
    read(0, &a, sizeof(int));
    char* ret = bad(a);
    if (ret != NULL)
        printf("%s\n", ret);
    return 0;
}

