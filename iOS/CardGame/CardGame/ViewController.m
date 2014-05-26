//
//  ViewController.m
//  CardGame
//
//  Created by Avneet Singh on 5/25/14.
//  Copyright (c) 2014 Pivot.IO. All rights reserved.
//

#import "ViewController.h"
#import "PlayingCard.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)cardButtonDragged:(UIButton *)sender {
    // add drag listener to the sender
	[sender addTarget:self action:@selector(wasDragged:withEvent:)
     forControlEvents:UIControlEventTouchDragInside];
    
}

- (IBAction)cardButtonTouced:(UIButton *)sender {
    
    PlayingCard* playingCard = [[PlayingCard alloc] init];
    
    if ([sender.currentTitle length]) { // Back of the card
        [sender setBackgroundImage:[UIImage imageNamed:@"cardBack"] forState:UIControlStateNormal];
        [sender setImage:nil forState:UIControlStateNormal];
        [sender setTitle:@"" forState:UIControlStateNormal];
    } else { // Front of the card
        [sender setBackgroundImage:[UIImage imageNamed:@"cardFront"]forState:UIControlStateNormal];
        [sender setImage:[UIImage imageNamed:@"10Club"]forState:UIControlStateNormal];
        [sender setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [sender setTitle:playingCard.contents forState:UIControlStateNormal];
    }
}

- (void)wasDragged:(UIButton *)button withEvent:(UIEvent *)event
{
	// get the touch
	UITouch *touch = [[event touchesForView:button] anyObject];
    
	// get delta
	CGPoint previousLocation = [touch previousLocationInView:button];
	CGPoint location = [touch locationInView:button];
	CGFloat delta_x = location.x - previousLocation.x;
	CGFloat delta_y = location.y - previousLocation.y;
    
	// move button
	button.center = CGPointMake(button.center.x + delta_x,
                                button.center.y + delta_y);
}

@end
