#include <iostream>
using namespace std;

//kmp
void getNext(const char *pat, int next[])
{
    const int m = strlen(pat);

    int i, j = -1;
    next[0] = -1;
    for(i = 1; i < m; ++i){
        while(j > -1 && pat[i] != pat[j+1]) j = next[j];

        if(pat[i] == pat[j+1]) j++;
        next[i] = j;
    }
}

int kmp(const char *text, const char *pat)
{
    int n = strlen(text);
    int m = strlen(pat);
    if(m == 0) return 0;

    int *next = (int*) malloc(sizeof(int) * m);
    int i, j = -1;
    for(i = 0; i < n; ++i){
        while(j > -1 && text[i] != pat[j+1]) j = next[j];

        if(text[i] == pat[j+1]) j++;
        if(j == m-1){
            free(next);
            return i - m + 1;
        }
    }

    free(next);
    return -1;
}

//O(m*n)
char* strStr(char *haystack, char *needle) {
    int h = strlen(haystack);
    int n = strlen(needle);

    int i, j;
    for(i = 0; i <= h-n; ++i){
        for(j = 0; j < n; ++j){
            if(haystack[i+j] != needle[j])
                break;
        }
        if(j == n) return haystack + i;
    }

    return NULL;
}

int main()
{
    char h[] = "hello world";
    char n[] = "so";
    cout<<kmp(h, n)<<endl;
    return 0;
}
