/* dice_game.c */
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    int balance = 1000;
    int bet, guess, dice, game_end;
    char answer[16];

    // Welcome Message and Exception Handling of unwanted input
    printf("Welcome to the one and only DICE GAME\nShall I explain the rules of this game? Answer with yes or no!\n");
    scanf("%15s", answer);
    if (strcmp(answer, "yes") == 0)
    {
        printf("\nThe rules are simple:\n\nYou can choose between a number from 1-6 and if the dice rolls your chosen number you win triple by the amount of your bet.\nIf you loose the bet the money will be gone.\nType 0 to leave the game.\nHave fun playing!\n\n");
    }
    else if (strcmp(answer, "no") == 0)
    {
        printf("Good Luck and have fun!\n");
    }
    else
    {
        printf("That's an inappropriate answer!\n");
        return 0;
    }

    // Initiation of the game loop
    while (balance > 0)
    {

        printf("Please insert the amount of money you want to bet: \n");
        scanf("%4d", &bet);
        printf("You inserted: %d EUR\n", bet);
        // flushes the input
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
        // flushes the input

        // makes sure that bet is larger than 0 or negative numbers and that the user won't bet more that they have in there account
        if (bet <= 0 || bet > balance)
        {
            printf("Invalid bet amount.\n");
            continue;
        }

        // asks for a number between 1-6 and sets borders to what the user is able to succesfully type in
        while (1)
        {
            printf("Guess a number (1-6): ");
            fgets(answer, sizeof(answer), stdin);

            if (sscanf(answer, "%d", &guess) != 1)
            {
                printf("Invalid input - please enter a number!\n");
                continue;
            }

            if (guess < 1 || guess > 6)
            {
                printf("Number must be between 1 and 6!\n");
                continue;
            }

            break;
        }

        // Some visualisation
        printf("Rolling the dice\n.\n");
        sleep(1);
        printf("..\n");
        sleep(1);
        printf("...\n");
        sleep(1);

        // Determines the number "randomly"
        dice = rand() % 6 + 1;

        // examines if the user guess is correct or incorrect
        if (guess == dice)
        {
            printf("Hooray you won!\n");
            balance += (3 * bet);
            printf("Your current balance: %d\n", balance);
            printf("Now triple your bet again champ!\n");
        }
        else
        {
            printf("Oh no a miss!....The wanted number was %d\n", dice);
            balance -= bet;
            printf("Your current balance: %d\n", balance);
            printf("Next round you'll hit!\n\n");
        }

        printf("Press 0 to stop playing or 1 to continue!\n");
        // there needs to be a pointer to game_end to ensure that the correct value is chosen and not a random memory address
        scanf("%d", &game_end);

        if (game_end == 0)
        {
            printf("Goodbye!");
            break;
        }
        else if (game_end == 1)
        {
            continue;
            // int d;
            // while ((d = getchar()) != '\n' && c != EOF)
            // {
            // }
        }
    }
}