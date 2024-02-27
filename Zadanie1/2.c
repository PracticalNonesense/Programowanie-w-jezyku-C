#include <stdio.h>

int main()
{   
    float grades[2][5] = {{5,6,2,4,3},{6,1,4,3,3}};
    
    // Obliczenie średniej ocen z matematyki
    float sumam = 0;
    for (int i = 0; i < 5; i++) {
        sumam += grades[0][i];
    }
    float sredniam = sumam / 5;

    // Obliczenie średniej ocen z fizyki
    float sumaf = 0;
    for (int i = 0; i < 5; i++) {
        sumaf += grades[1][i];
    }
    float sredniaf = sumaf / 5;

    printf("Średnia ocen z matematyki: %.2f\n", sredniam);
    printf("Średnia ocen z fizyki: %.2f", sredniaf);

    return 0;
}
