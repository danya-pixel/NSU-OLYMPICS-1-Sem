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

double to_10(char *whole, int size_whole, char *fract, int size_fract, int from) {
    return (double) to_10_int(whole, (int) strlen(whole), from) + to_10_double(fract, (int) strlen(fract), from);
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
        int ind = -1;
        i--;
        while (fract != 0 && acc != 0) {
            int buf = (int) (fract * to);
            if (fract * to - buf >= 0.99999) buf++;
            fract = fract * to - buf;
            ind--;
            if (buf > 9)
            {
                printf("%c", (char) (buf - 10 + 'a'));
            }
            else printf("%d", buf);
            acc--;
        }

    }


}


int main() {
    freopen("input.txt", "r", stdin);
    int from = 0, to = 0, acc = 5;
    double n = 0;
    scanf("%d%d%lf", &to, &acc, &n);
    from_10(n, to, acc);
    return 0;
}