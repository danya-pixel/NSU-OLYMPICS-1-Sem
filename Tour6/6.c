#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>

int to_10_int(char *str, int size, int from) {
    int sum = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
            sum += (int) pow(from, size - i - 1) * (str[i] - '0');
        } else {
            sum += (int) pow(from, size - i - 1) * (str[i] - 'a' + 10);
        }
    }
    return sum;
}
double to_10_double(char *str, int size, int from){
    double sum = 0;
    for(int i = -1; i>=-size; i--)
    {
        int ind = -i-1;
        if (str[ind] - '0' >= 0 && str[ind] - '0' <= 9) {
            sum += pow(from, i) * (str[ind] - '0');
        } else {
            sum += pow(from, i) * (str[ind] - 'a' + 10);
        }
    }
    return sum;
}
double to_10(char *whole, int size_whole,char *fract, int size_fract, int from)
{
    return (double)to_10_int(whole,(int)strlen(whole), from) + to_10_double(fract, (int)strlen(fract), from);
}

int main() {
    freopen("input.txt", "r", stdin);
    int from = 0, to = 0;
    char whole[200], str[200];
    char fract[200];
    scanf("%d%s", &from, str);
    int i=0;
    while(str[i] != '.')
    {
        whole[i]=str[i];
        i++;
    }
    whole[i]='\0';
    for(int j=i+1;j<(int)strlen(str); j++)
    {
        fract[j-i-1] = str[j];
    }
    fract[strlen(str)-i-1]='\0';
    double ans = to_10(whole, strlen(whole), fract, strlen(fract), from);
    printf("%.5f", ans);
    return 0;
}