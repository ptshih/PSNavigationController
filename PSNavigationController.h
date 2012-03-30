//
//  PSNavigationController.h
//  OSnap
//
//  Created by Peter Shih on 12/19/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 This class does NOT manage a shared navigation bar.
 It is the responsibility of the view controller to present a navigation bar.
 PSViewController has an optional PSNavigationBar property that will add one.
 
 iOS5 only, uses view containment
 */

typedef enum {
    PSNavigationControllerDirectionLeft = 1,
    PSNavigationControllerDirectionRight = 2,
    PSNavigationControllerDirectionUp = 3,
    PSNavigationControllerDirectionDown = 4
} PSNavigationControllerDirection;

@protocol PSNavigationControllerDelegate;

@class PSViewController;

@interface PSNavigationController : UIViewController <UIGestureRecognizerDelegate> {
}

@property (nonatomic, retain) UIView *overlayView;
@property (nonatomic, assign) id <PSNavigationControllerDelegate> delegate;
@property (nonatomic, assign) UIViewController *disappearingViewController;
@property (nonatomic, assign) UIViewController *topViewController;
@property (nonatomic, assign) UIViewController *rootViewController;
@property (nonatomic, retain) NSMutableArray *viewControllers;

/**
 Convenience initializer
 */
- (id)initWithRootViewController:(UIViewController *)rootViewController;

/**
 Push and Pop
 */
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (void)pushViewController:(UIViewController *)viewController direction:(PSNavigationControllerDirection)direction animated:(BOOL)animated;
- (UIViewController *)popViewControllerAnimated:(BOOL)animated;
- (UIViewController *)popViewControllerWithDirection:(PSNavigationControllerDirection)direction animated:(BOOL)animated;

- (NSArray *)popToViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (NSArray *)popToRootViewControllerAnimated:(BOOL)animated;

@end

@protocol PSNavigationControllerDelegate <NSObject>

@optional
- (void)psNavigationController:(PSNavigationController *)psNavigationController willShowViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (void)psNavigationController:(PSNavigationController *)psNavigationController didShowViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (void)psNavigationController:(PSNavigationController *)psNavigationController willHideViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (void)psNavigationController:(PSNavigationController *)psNavigationController didHideViewController:(UIViewController *)viewController animated:(BOOL)animated;

@end
