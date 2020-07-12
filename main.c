// from Listing 8.2 2 Dimensional Array for scoring the point totals of
// 5 players in 4 different games; page 174

#include <stdio.h>

#define PLAYERS 5
#define GAMES 4

//if defining an array for this pgm without skipping [0] subscript
// this would look like:
// int scores[5][4];
// ...for 5 players and 4 games.. 5 copies of array with 4 spots (columns vs rows)
//              [5] is columns x [4] is rows
//
//     p1  p2  p3  p4  p5
//  g1  x   x   x   x   x
//  g2  x   x   x   x   x
//  g3  x   x   x   x   x
//  g4  x   x   x   x   x
//
// So, you have to do inner and outer loops correctly or you'll miss data and/or
// get unexpected results

int scores[6][5];

float score_avg[6], best_avg;
int point_total, best_player;
int counter1, counter2;
int a,b;

int main()
{

    //outer loop is for each of the games
    for(counter2=1; counter2<=GAMES; counter2++)
    {
        printf("\nGetting scoring totals for Game #%d.\n",counter2);
        //inner loop is for each player in the specific game.
        for(counter1 = 1; counter1 <= PLAYERS; counter1++)
        {
            //printf("what did player #%d score in the game? ",counter1);
            printf("what did player #%d score in game %d? ",counter1,counter2);
            scanf("%d",&scores[counter1][counter2]);
        }

    }
    //*******   me checking/printing array
      printf("\nPrinting out the array:\n");
      for(a=1; a<=5; a++)
        {
        printf("\nScores for player #%d are:\n",a);
        for(b=1; b<=4; b++)
            {
            printf("\t %d",scores[a][b]);
            }
        }

    //loop through the array to calculate scoring average per player
    for(counter1=1; counter1<= PLAYERS; counter1++)
    {
        point_total=0;
        for(counter2=1; counter2<= GAMES; counter2++)
        {
            point_total += scores[counter1][counter2];
        }
        score_avg[counter1]= (float)point_total/GAMES;
    }

    //Now loop through and store sho has the best scoring average

    best_avg=0;
    for(counter1=1; counter1<=PLAYERS; counter1++)
    {
        if(score_avg[counter1] > best_avg)
        {
            best_avg = score_avg[counter1];
            best_player = counter1;
        }
    }
    printf("\nPlayer #%d had the best scoring average,\n", best_player);
    printf("at %.2f points per game.\n", score_avg[best_player]);


    return 0;
}
