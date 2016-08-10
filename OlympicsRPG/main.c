//
//  main.c
//  OlympicsRPG
//
//  Created by Princess Sampson on 8/9/16.
//  Copyright © 2016 Princess Sampson. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int scoreTiers[] = {33, 66, 99};

int generateRandomEventScore();
int calcAbsoluteDifference(int, int);
double calculateAverageScore(int[], int);
int calculateWeightedAverageScore(double);
int indexOfSmallestArrayValue(int[], int arrSize);

int main(int argc, const char * argv[]) {
    
    int rawScores[6];
    
    for (int i = 0; i <= 6; i++) {
        rawScores[i] = generateRandomEventScore();
    }
    
    double rawCompScore = calculateAverageScore(rawScores, 6);
    
    printf("raw score: %f\n", rawCompScore);
    
    printf("calculate weighted comp score: %d\n", calculateWeightedAverageScore(rawCompScore));
    
    return 0;
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

double calculateAverageScore(int scores[], int scoresSize) {
    
    double rtn = 0;
    
    for (int i = 0; i<scoresSize; i++) {
        rtn += scores[i];
    }
    
    return rtn / 6;
}


int calculateWeightedAverageScore(double rawCompositeScore) {
    
    int differencesBetweenAverageScoreAndScoreTiers[3];
    
    for (int i = 0; i < 3; i++) {
        differencesBetweenAverageScoreAndScoreTiers[i] = calcAbsoluteDifference(rawCompositeScore,scoreTiers[i]);
    }
    
    int weightedCompositeScore = scoreTiers[indexOfSmallestArrayValue(differencesBetweenAverageScoreAndScoreTiers, 3)];
    
    
    return weightedCompositeScore;
}
