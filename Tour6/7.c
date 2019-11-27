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

double to_10_double(char *str, int size, int from) {
    double sum = 0;
    for (int i = -1; i >= -size; i--) {
        int ind = -i - 1;
        if (str[ind] - '0' >= 0 && str[ind] - '0' <= 9) {
            sum += pow(from, i) * (str[ind] - '0');
        } else {
            sum += pow(from, i) * (str[ind] - 'a' + 10);
        }
    }
    return sum;
}

void from_10(double val, int to, int acc) {
    char str[200];
    int whole = (int) val;
    double fract = val - whole;
    int i = 299;
    while (whole > 0) {
        str[i] = (char) (whole % to);
        whole = whole / to;
        i--;
    }
    if (i == 299) printf("0");
    else {
        for (int j = i + 1; j < 300; ++j) {
            if (str[j] > 9) printf("%c", (char) (str[j] - 10 + 'a'));
            else printf("%d", str[j]);
        }
    }

    if (fract != 0) {
        printf(".");
        char answer[100];
        int ind = -1, j=0;
        double last_fract = -1;
        while (fract > 0 && acc != 0) {
            int buf = (int) (fract * to);
            if (fract * to - buf >= 0.99999) buf++;
            fract = fract * to - buf;
            last_fract = fract;
            ind--;
            if (buf > 9) answer[j]=(char)(buf - 10 + 'a');
            else answer[j]=(char)(buf+'0');
            acc--;
            j++;
        }
        int new_j=j;
        for(j-=1;j>=0;j--)
        {
            if(answer[j] == '0')new_j=j;
            else break;
        }
        for(int z=0;z<new_j;z++)
        {
            printf("%c", answer[z]);
        }
    }


}

_Bool validate(char *str, int size, int system) {
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (cnt > 1) return (_Bool)0;
        if (str[i] == '.'){
            cnt++;
            continue;}
        if ((str[i] >= 'a' && str[i] - 'a' + 10 >= system) || (str[i] <= '9' && str[i] - '0' >= system))
            return (_Bool) 0;
    }
    return (_Bool) 1;
}


int main() {
    freopen("input.txt", "r", stdin);
    int from = 0, to = 0, acc = 5;
    char whole[200], str[200];
    char fract[200];
    scanf("%d%d%d%s", &from, &to, &acc, str);
    if (!validate(str, (int) strlen(str), from)) {
        printf("NO");
        return 0;
    }
    int i = 0;
    while (str[i] != '.') {
        whole[i] = str[i];
        i++;
        if (i == (int) strlen(str))break;
    }
    whole[i]='\0';
    double ans = (double) to_10_int(whole, (int)strlen(whole), from);
    if (i != (int) strlen(str)) {
        whole[i] = '\0';
        for (int j = i + 1; j < (int) strlen(str); j++) {
            fract[j - i - 1] = str[j];
        }
        fract[strlen(str) - i - 1] = '\0';
        ans += to_10_double(fract, (int) strlen(fract), from);
    }
    from_10(ans, to, acc);
    return 0;
}