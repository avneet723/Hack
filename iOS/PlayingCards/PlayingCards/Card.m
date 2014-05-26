//
//  Card.m
//  PlayingCards
//
//  Created by Avneet Singh on 5/25/14.
//  Copyright (c) 2014 Pivot.IO. All rights reserved.
//

#import "Card.h"

@implementation Card

- (int)match:(NSArray *) otherCards
{
    int score = 0;
    
    for (Card* card in otherCards) {
        if ([card.contents isEqualToString:self.contents]) {
            score += 1;
        }
    }
    
    return score;
}

@end
