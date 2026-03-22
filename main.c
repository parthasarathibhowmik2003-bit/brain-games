#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, userAnswer, correctAnswer, op;
    char operatorSymbol;
    time_t start, end;

    // Seed the random number generator
    srand(time(0));

    printf("--- Welcome to the C Speed Math Challenge! ---\n");
    
    // Generate random numbers (1 to 20)
    num1 = rand() % 20 + 1;
    num2 = rand() % 20 + 1;
    op = rand() % 4; // 0 to 3 for +, -, *, /

    // Assign operator and calculate answer
    switch(op) {
        case 0: operatorSymbol = '+'; correctAnswer = num1 + num2; break;
        case 1: operatorSymbol = '-'; correctAnswer = num1 - num2; break;
        case 2: operatorSymbol = '*'; correctAnswer = num1 * num2; break;
        case 3: 
            operatorSymbol = '/'; 
            // Ensure division results in an integer for simplicity
            num1 = num1 * num2; 
            correctAnswer = num1 / num2; 
            break;
    }

    printf("Solve this: %d %c %d = ?\n", num1, operatorSymbol, num2);
    
    // Start timing
    time(&start);
    
    printf("Your answer: ");
    scanf("%d", &userAnswer);
    
    // End timing
    time(&end);

    double timeTaken = difftime(end, start);

    // Check result
    if (userAnswer == correctAnswer) {
        printf("\nCorrect! 🎉\n");
        printf("Time taken: %.2f seconds.\n", timeTaken);
        
        if (timeTaken < 3) printf("Verdict: You're a human calculator!\n");
        else printf("Verdict: Not bad, but try to be faster next time.\n");
    } else {
        printf("\nWrong! The correct answer was %d.\n", correctAnswer);
    }

    return 0;
}
