#include <stdio.h>

int main() {
    int a, b, size;
    size = 15;
    for (a = size/2; a <= size; a = a+2) {
        for (b = 1; b < size-a; b = b+2) {
            printf(" ")
        }
        for (b = 1; b <= a; b++) {
            printf("*");
        }
        for (b = 1; b <= size-a; b++) {
            printf(" ");
        }
        for (b = 1; b <= a-1; b++) {
            printf("*");
        }
        printf("\n");
    }
    for (a = size; a >= 0; a--) {
        for (b = a; b < size; b++) {
            printf(" ");
        }
        for (b = 1; b <= ((a*2)-1); b++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}


// 1-tatchof wax dak table [max] kyn f stack a o la f stack b
// Fi halt kan f stack B tanchof wax ila first element ola last  ila kan first tan pushih ila kan lkhar tan rrb o tan pushih A
// Ila fi halat ma kan la first la last
// Tan pushih l stack a o tan habtoo ltahat o tan ndir wahd variable ( ex: int k ,ila kan k==0 kay ya3ni rah ma kayn walo ltaht f stack A ma msortiach ,ila kan l3akss rah ba9ay tam chy haja )
// Kolma habat chy element ltaht tan k++
// Wax fhamti ola ndir audio
// Db nwaslo liha
// Mhm ila kan k ==0 rah tan pushiwh o tan habtoh ltahat o tan k++
// Ila kan k !=0 rah tan nchofo first element f stack b khaso yakon kabar man last stack A
// Bax dima yab9a lik dak max howa lkhar f stack A o daghya tawsl lih
// Ila ma taha9ach had condition tan  nkhaliwh f stack b o tan habtoh ltahat
// Hadchi kaml ila kan max f stack b
// Ila kan f satck A
// Hada kay ya3ni bli pushinah o hatinah ltahat
// Tan tal3oh lfo9 fsatck a
// Rra
// O k--
// Sfy hadchi li kyan
// F lkhar kass yakon k==0 ila makan tadir rra tat wali k ==0