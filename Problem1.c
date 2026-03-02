
#include <stdio.h>
 
void findCombinations(int score) {
    printf("Possible combinations of scoring section for %d:\n", score);

    for (int touchdown2pt = 0; touchdown2pt * 8 <= score; touchdown2pt++) {
        for (int touchdown1pt = 0; touchdown1pt * 7 <= score; touchdown1pt++) {
            for (int touchdown0pt = 0; touchdown0pt * 6 <= score; touchdown0pt++) {
                for (int fieldgoal = 0; fieldgoal * 3 <= score; fieldgoal++) {
                    for (int safety = 0; safety * 2 <= score; safety++) {

                        if ((touchdown2pt * 8 + touchdown1pt * 7 + touchdown0pt * 6 + fieldgoal * 3 + safety * 2) == score) {
                            printf("%d TouchDown + 2pt, %d TouchDown + FieldGoal, %d TouchDown, %d 3pt FieldGoal, %d Safety\n",
                                touchdown2pt, touchdown1pt, touchdown0pt, fieldgoal, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while(1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");

        if (scanf("%d", &score) != 1) {

        }

        if (score <= 1) {
            break;
        }

        findCombinations(score);
        printf("\n");
    }

    return 0;
}