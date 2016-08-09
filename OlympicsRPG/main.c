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

int eventScore();
int calcAbsoluteDifference(int, int);
double calculateRawCompositeScore(int[], int);
int calculateWeightedCompositeScore(double);

int main(int argc, const char * argv[]) {
    
    return 0;
    
}

int eventScore() {
    return scoreTiers[arc4random_uniform(2)];
}

int calcAbsoluteDifference(int a, int b) {
    return abs(a - b);
}

double calculateRawCompositeScore(int scores[], int scoreSize) {
    
    double rtn = 0;
    
    for (int i = 0; i<scoreSize; i++) {
        rtn += scores[i];
    }
    
    return rtn / 6;
}


int calculateWeightedCompositeScore(double rawCompositeScore) {
    
    int rtn = 0;
    //numericalDistanceOfEachCompositeScoreFromScoreTiers[i] = rawCompositeScore;

return rtn;
}
