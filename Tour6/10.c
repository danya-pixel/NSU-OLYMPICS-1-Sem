#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


void strok(int ch) {
    if (ch == 1)
        printf("stroka");
    else if (ch == 2 || ch == 3 || ch == 4)
        printf("stroki");
    else
        printf("strok");
}

void edin(int ch) {
    switch (ch) {
        case 1:
            printf("odna");
            break;
        case 2:
            printf("dve");
            break;
        case 3:
            printf("tri");
            break;
        case 4:
            printf("chetyre");
            break;
        case 5:
            printf("pyat");
            break;
        case 6:
            printf("shest");
            break;
        case 7:
            printf("sem");
            break;
        case 8:
            printf("vosem");
            break;
        case 9:
            printf("devyat");
            break;
        case 10:
            printf("desyat'");
            break;
        default:
            break;
    }
}

void do_20(int ch) {
    if (ch % 10 == 1)
        printf("odin");
    else if (ch % 10 == 4)
        printf("chetyr");
    else edin(ch - 10);
    printf("nadtsat'");
}

void sotni(int ch) {
    if (ch == 1)
        printf("sto");
    else {
        edin(ch);
        if (ch > 4) printf("'");
        if (ch == 2) printf("sti");
        else if (ch == 3 || ch == 4) printf("sta");
        else printf("sot");
    }
}

void desyatki(int ch) {
    if (ch == 4) {
        printf("sorok");
        return;
    } else if (ch == 9) {
        printf("devyanosto");
        return;
    } else if (ch == 2)
    {
        printf("dva");
    }
    else
        edin(ch);
    if (ch > 3)
        printf("'desyat");
    else
        printf("dtsat'");
}

void parse(int ch, int is_mil) {
    if (ch / 100) {
        sotni(ch / 100);
        ch %= 100;
        if (ch)
            printf(" ");
    }
    if (ch > 19) {
        desyatki(ch / 10);
        ch %= 10;
        if (ch)
            printf(" ");
    }
    if (ch > 10) {
        do_20(ch);
        ch = 0;
    }
    if (ch) {
        if (is_mil) {
            if (ch == 1) {
                printf("odin");
                return;
            }
            if (ch == 2) {
                printf("dva");
                return;
            }
        }
        edin(ch);
        if (ch > 4 && ch != 10)
            printf("'");
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int ch, ch_m, ch_t;
        scanf("%d", &ch);
        ch_m = ch / 1000000;
        ch %= 1000000;
        ch_t = ch / 1000;
        ch %= 1000;
        if (ch_m) {
            parse(ch_m, 1);
            ch_m %= 100;
            if (ch_m < 20 && ch_m > 10)
                ch_m = 0;
            if (ch_m % 10 == 1)
                printf(" million");
            else if (ch_m % 10 == 2 || ch_m % 10 == 3 || ch_m % 10 == 4)
                printf(" milliona");
            else
                printf(" millionov");
            printf(" ");
        }
        if (ch_t) {
            parse(ch_t, 0);
            ch_t %= 100;
            if (ch_t < 20 && ch_t > 10)
                ch_t = 0;
            if (ch_t % 10 == 1)
                printf(" tysyacha ");
            else if (ch_t % 10 == 2 || ch_t % 10 == 3 || ch_t % 10 == 4)
                printf(" tysyachi ");
            else
                printf(" tysyach ");
        }
        if (ch) {
            parse(ch, 0);
            printf(" ");
        }
        ch %= 100;
        if (ch < 20 && ch > 10)
            ch = 0;
        strok(ch % 10);
        printf("\n");
    }
    return 0;
}