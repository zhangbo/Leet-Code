#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int result = rand() % 10 + 1;
    int correct = 0;
    int guess;
    int counter = 0;
    int reward = 1000;

    printf("Guess: ");
    do {
        scanf("%d", &guess);
        counter++;
        if (guess == result)
        {
            char* tips = (char*)malloc(30 * sizeof(char));
            const char* res = counter != 1 ? "Correct, %d tries\n" : "%d coins reward.";
            int tmp = counter != 1 ? counter : reward;
            sprintf(tips, res, tmp);
            printf("%s\n", tips);
            free(tips);
            correct = 1;
        }

        if (guess < result)
            printf("Lower.");

        if (guess > result)
            printf("Higher.");

    } while (correct == 0);

    return 0;
}
