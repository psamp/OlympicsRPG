//
//  main.c
//  OlympicsRPG
//
//  Created by Princess Sampson on 8/9/16.
//  Copyright © 2016 Princess Sampson. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int scoreTiers[] = {33, 66, 99};
int events = 6;

void newGame();
void endGame();
int generateRandomEventScore();
int calcAbsoluteDifference(int, int);
double calculateAverageScore(int);
int calculateWeightedAverageScore(double);
int indexOfSmallestArrayValue(int[], int arrSize);

void swimming();
void gymnasticsBar();
void archery();
void skating();
void track();
void fencing();

int main(int argc, const char * argv[]) {
    
    newGame();
    
    return 0;
}

void newGame() {
    
    int score = 0;
    int eventCounter = 0;
    
    char eventsList[] = "\nSwim (1\nGymnastics (bar) (2\nArchery (3\nSkating(4\nTrack (5\nFencing (6\n";
    
    while(eventCounter < 6) {
        
        int option = 0;
        printf("%s", eventsList);
        fpurge(stdin);
        scanf("%d", &option);
        
        switch (option) {
            case 1: {
                
                swimming();
                score += generateRandomEventScore();
                printf("YOUR RAW SCORE IS: %d\n", score);
                
                eventCounter++;
                break;
            }
            case 2: {
                gymnasticsBar();
                score += generateRandomEventScore();
                printf("YOUR RAW SCORE IS: %d\n", score);
                
                eventCounter++;
                break;
            }
            case 3: {
                archery();
                score += generateRandomEventScore();
                printf("YOUR RAW SCORE IS: %d\n", score);
                
                eventCounter++;
                break;
            }
            case 4: {
                skating();
                score += generateRandomEventScore();
                printf("YOUR RAW SCORE IS: %d\n", score);
                
                eventCounter++;
                break;
            }
            case 5: {
                track();
                score += generateRandomEventScore();
                printf("YOUR RAW SCORE IS: %d\n", score);
                
                eventCounter++;
                break;
            }
            case 6: {
                
                fencing();
                score += generateRandomEventScore();
                printf("YOUR RAW SCORE IS: %d\n", score);
                
                eventCounter++;
                break;
            }
                
            default: {
                printf("Invalid event number. Please choose from our list!\n");
                break;
            }
        }
        
    }
    
    endGame(calculateWeightedAverageScore(calculateAverageScore(score)));
    
}

void endGame(int weighedScore) {
    
    int continueGame = 1;
    
    for (int i = 0; i < 3; i++) {
        char *medals[3] = {"BRONZE","SILVER","GOLD"};
        
        if(weighedScore == scoreTiers[i]) {
            printf("WITH YOUR AVERAGED AND WEIGHTED ALL-AROUND SCORE OF %d YOU HAVE EARNED A %s MEDAL!\n", weighedScore, medals[i]);
        }
    }
    
    printf("It's been four years. Would you like to compete again?\nYes (0\nNo (1\n");
    scanf("%d", &continueGame);
    
    if (continueGame == 0) {
        newGame();
    }
}

void swimming() {
    printf("You pull your goggles down over your eyes and try to tune out the roaring crowd noise, the clicks of the phototgraphers' cameras. _This is it_, you think. The horn blares out, and you're in the water, kicking faster than you ever have.\n");
    
    
}

void gymnasticsBar() {
    printf("You rub chalk on your hands until your palms are coated in it, clap them together to shake off the excess. It's time. You run, launch yourself off the ground. Heart beating and adrenaline racing, you know the photographers have frozen in time the almost invisble cloud of chalkdust that puffs up when your hands hit the bar. \n");
    
}
void archery() {
    printf("You feel the weight of the quiver on your back, and the weight of every arrow inside: Their desperate hope to fly steady and true. The horn sounds. You notch your arrow, draw the string back to your ear. On your next exhale, you let it go and the tail leaves a cut on your cheek.\n");
    
}
void skating() {
    printf("You're cold. Frozen air rolls in waves off the rink, and your fingers are stiff as they tie the laces of your skates. You watch the others, their turns on a dime and their landings impeccable. When it's your turn, you glide out to the center of the ice. Before your song begins, you take a deep breath. It fogs the air.\n");
}

void track() {
    printf("You're crouched in a line beside the others, your number pinned to your chest. You should probably be standing still, but you can't help shifting from foot to foot--not out of nervousness, but restlessness. The photographers are turning dials on their cameras, turning up their Olympics-level shutterspeeds even higher for some of the fastest in the world. The horn goes off, and everything in your peripherals becomes a blur.\n");
    
}
void fencing() {
    printf("You're wearing the mask for protection, but it also means the millions watching can't see your every expression. Good. Someone hands you your rapier, and you grip it tightly as you tread to the edge of the ring. It's dim in here, dark, and the crowd more quiet. \n\"En guard,\" the ref yells, and you lift your weapon and launch yourself forward. \n");
    
    
}

int generateRandomEventScore() {
    return scoreTiers[arc4random_uniform(3)];
}

int calcAbsoluteDifference(int a, int b) {
    return abs(a - b);
}

int indexOfSmallestArrayValue(int arr[], int arrSize){
    int index = 0;
    
    for (int i = 0; i < arrSize; i++) {
        
        if (arr[i] < arr[index]) {
            index = i;
        }
    }
    
    return index;
}

double calculateAverageScore(int score) {
    
    return score / events;
}


int calculateWeightedAverageScore(double rawAverageScore) {
    
    int differencesBetweenAverageScoreAndScoreTiers[3];
    
    for (int i = 0; i < 3; i++) {
        differencesBetweenAverageScoreAndScoreTiers[i] = calcAbsoluteDifference(rawAverageScore,scoreTiers[i]);
    }
    
    int weightedAverageScore = scoreTiers[indexOfSmallestArrayValue(differencesBetweenAverageScoreAndScoreTiers, 3)];
    
    return weightedAverageScore;
}
