//
//  PlayingCard.h
//  PlayingCards
//
//  Created by Avneet Singh on 5/25/14.
//  Copyright (c) 2014 Pivot.IO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Card.h"

@interface PlayingCard : Card

@property (strong, nonatomic) NSString *suit;
@property (nonatomic) NSInteger rank;

+ (NSArray *) validSuits;
+ (NSInteger) maxRank;

@end
