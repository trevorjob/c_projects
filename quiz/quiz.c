#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 5

int listOptions(char *options[][5], int userAnswer, int k, int i);
void printScore(int score, char *name);

int main(void)
{
        // variable declarations  
        int i,k;
        char name[20];
        int userAnswer;
        int score = 0;

        // 2D array containg all questions asked in the quiz
        char *questions[] = {"What year was the United Nations established ?",
                                "What artist has the most streams on Spotify ?",
                                "Which planet in the Milky Way is the hottest?",
                                "What is the 4th letter of the Greek alphabet?",
                                "What country has won the most World Cups?",
                                "What software company is headquartered in Redmond, Washington?",
                                "What is acrophobia a fear of?",
                                "In what country was Elon Musk born?",
                                "What phone company produced the 3310?",
                                "What is the only continent with land in all four hemispheres?"
                                };

        // 3D array containing all the answer options 
        char *options[][N] = {{"1985", "1920", "2003", "1945", "2015"},
                                {"Drake", "Bad bunny", "The Weeknd", "Ed Sheeran", "Taylor Swift"},
                                {"Mecury", "Saturn", "Jupitar", "Mars", "Venus"},
                                {"Beta", "Delta", "Charlie", "Echo", "Alpha"},
                                {"Morocco", "New Zeland", "Portugal", "Brazil", "Fance"},
                                {"Twitter", "Microsoft", "IBM", "Tinder", "Facebook"},
                                {"Flying", "Acrobatics", "Falling", "Swimming", "Dying"},
                                {"South Africa", "Singapore", "Germany", "France", "Korea"},
                                {"Infinix", "Blackberry", "Nokia", "Iphone", "Samsung"},
                                {"Europe", "Asia", "South America", "Africa", "Antarctica"}};

        // string array containing all the answers 
        // char *answers[] = {"1945", "The Weeknd", "Venus", "Delta", "Brazil", "Microsoft", "Flying", "South Africa", "Nokia", "Africa"};
        char *answers[] = {
                                options[0][3],
                                options[1][2],
                                options[2][4],
                                options[3][1],
                                options[4][3],
                                options[5][1],
                                options[6][0], 
                                options[7][0],
                                options[8][2],
                                options[9][3]};


        /* get player name */
        printf("what is your name : ");
        fgets(name, 20, stdin);
        
        /* transform name to uppercase */
        for ( i = 0; name[i]; i++)
        {
        name[i] = toupper(name[i]);
        }

        // quiz information and guidlines
        printf("there are a total %d questions in this quiz\n",sizeof(questions)/sizeof(questions[0]));
        printf("each question has 5 possible answer options\n");
        printf("if you get an answer right on your first try you will be awarded 10 points\n");
        printf("if you get it wrong you would be asked again for a different answer if you get that correctly you will be awarded 5 points\n");
        printf("and at the end of the quiz you score will be provided to you\n");

        // confirm from player if he/she wants to start the quiz
        printf("well %s",name);
        printf("would you like to start the quiz...? \n(0)no\n(1)yes ");

        // if i == 0 cancel quiz
        scanf("%d", &i);
        printf("\n");
        if(!i)exit(1);
        // if i == 1 start quiz

        /*
           the sizeof function gets the size (in bytes) of the entire questions array
           and does the same for the first element in the questions array
           it then divides them thus providing the number of elements contained in the array
           e.g sizeof(questions) = 40 bytes
           sizeof(questions[0]) = 4 bytes
           therefore sizeof(questions)/sizeof(questions[0]) == 10
           meaning there are 10 elements in the questions array 
        */
        /*  loop through the questions array and print out all questions  */
        for (i = 0; i < sizeof(questions)/sizeof(questions[0]); i++)
        {
                // print question
                printf("%s: \n", questions[i]);
                // print options and get player answer
                userAnswer = listOptions(options, userAnswer, k, i);

                // check player answer to see if it is correct 
                if (options[i][userAnswer] == answers[i])
                {
                        // increase score count by 10
                        score += 10;
                        printf("correct\n");   
                } else {
                        printf("wrong\ntry again\n");
                        // get new answer and check player answer to see if it is correct 
                        userAnswer = listOptions(options, userAnswer, k, i);
                        if (options[i][userAnswer] == answers[i]) score += 5;
                }
                printf("\n");
        }
        // print player score and closing message
        printScore(score, name);
        return (0);
}

/* listOptions function takes the options array, the useranswer variable and the 2 counting integers 
   and prints out all the options in the options array
   returns - useranswer variable */
int listOptions(char *options[][5], int userAnswer, int k, int i)
{
        for (k = 0; k < N; k++)
        {
                printf("(%d)%s ", k, options[i][k]);  
        }
        // get useranswer
        scanf("%d", &userAnswer);
        return userAnswer;
}

/* printscore function takes 2 parameters the score variable and the the current player name saved in the name variable
   it compares the scores in 3 different instances and prints a message according to the result */
void printScore(int score, char *name)
{
        if (score >= 80)
        {
                printf("WOW! %syou scored %d%c\nyou did excellent", name, score, 37);
        }
        else if (score >= 40 && score <= 79)
        {
                printf("well %syou scored %d%c\nwelldone", name, score, 37);
        }
        else if (score >= 0 && score <= 39)
        {
                printf("OMO! %se be like say you no know wating de happen for this world oo\nany how sha your score is %d%c\nyou nor try at all",name, score, 37);
        }
        
}