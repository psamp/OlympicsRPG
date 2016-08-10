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
int sports = 6;

void newGame();
int generateRandomEventScore();
int calcAbsoluteDifference(int, int);
double calculateAverageScore(int);
int calculateWeightedAverageScore(double);
int indexOfSmallestArrayValue(int[], int arrSize);

int main(int argc, const char * argv[]) {
    
    newGame();
}

void newGame() {
    
    int score = 0;
    int finalWeighedScore = 0;
    
    bool running = true;
    int option = -1;
    
    while (running) {
        printf("\nSwim (1\nGymnastics (bar) (2\nArchery (3)\nSkating( 4\nTrack (5\nFencing (6\n");
        scanf("%d", &option);
        
        switch (option) {
            case 1: {
                
                printf("You pull your goggles down over your eyes and try to tune out the roaring crowd noise, the clicks of the phototgraphers's camera. _This is it_, you think. The horn blares out, and you're in the water, kicking faster htan you ever have.\n");
                
                score += generateRandomEventScore();
                
                printf("YOUR SCORE IS: %d\n", score);
                
                break;
            }
            case 2: {
                
                printf("You rub chalk on your hands until your palms are coated in it, clap them together to shake off the excess. It's time. You run, launch yourself off the ground. Heart beating and adrenaline racing, you know the photographers have frozen in time the almost invisble cloud of chalkdust that puffs up when your hands hit the bar. \n");
                
                score += generateRandomEventScore();
                
                printf("YOUR SCORE IS: %d\n", score);
                
                break;
            }
            default:
                break;
        }
        
        running = false;
        
    }

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
    
    return score / sports;
}


int calculateWeightedAverageScore(double rawAverageScore) {
    
    int differencesBetweenAverageScoreAndScoreTiers[3];
    
    for (int i = 0; i < 3; i++) {
        differencesBetweenAverageScoreAndScoreTiers[i] = calcAbsoluteDifference(rawAverageScore,scoreTiers[i]);
    }
    
    int weightedAverageScore = scoreTiers[indexOfSmallestArrayValue(differencesBetweenAverageScoreAndScoreTiers, 3)];
    
    
    return weightedAverageScore;
}
