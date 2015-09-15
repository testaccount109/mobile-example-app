// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#import <UIKit/UIKit.h>
#import "iCarousel.h"
#include "TourExplorerViewIncludes.h"
#include "Tours.h"
#include "TourWebViewIncludes.h"

@class ImageStore;

@interface TourExplorerView : iCarousel<UIGestureRecognizerDelegate>
{
    ExampleApp::Tours::View::TourExplorer::TourExplorerViewInterop* m_pInterop;
    
    float m_width;
    float m_height;
    
    float m_screenWidth;
    float m_screenHeight;
    float m_pixelScale;
    
    float m_yPosActive;
    float m_yPosInactive;
    
    float m_stateChangeAnimationTimeSeconds;
    
    UIView* m_pCarouselContainer;
    UIView* m_pTourItemLabelContainer;
    UIView* m_pTourItemLabelGradientContainer;
    UILabel* m_pTourItemLabel;
}

@property (nonatomic, retain) UIButton* pExitButton;

- (id) initWithParams:(float)width :(float)height :(float)pixelScale :(ImageStore*)pImageStore;

- (ExampleApp::Tours::View::TourExplorer::TourExplorerViewInterop*) getInterop;

- (BOOL)consumesTouch:(UITouch *)touch;

- (void) configureViewForTour:(const ExampleApp::Tours::SdkModel::TourModel&) tour :(int)initialCard;

- (void) interruptCurrentTour:(const ExampleApp::Tours::SdkModel::TourModel&) tour;

- (void) setFullyOnScreen;

- (void) setFullyOffScreen;

- (void) setOnScreenStateToIntermediateValue:(float)openState;

- (void) animateToY:(float)y;


@end
