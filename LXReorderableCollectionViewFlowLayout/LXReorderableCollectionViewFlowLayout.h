//
//  LXReorderableCollectionViewFlowLayout.h
//
//  Created by Stan Chang Khin Boon on 1/10/12.
//  Copyright (c) 2012 d--buzz. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LXReorderableCollectionViewFlowLayout : UICollectionViewFlowLayout <UIGestureRecognizerDelegate>

@property (strong, nonatomic) UIView *currentView;
@property (strong, nonatomic) NSIndexPath *selectedItemIndexPath;

@property (assign, nonatomic) CGFloat scrollingSpeed;
@property (assign, nonatomic) UIEdgeInsets scrollingTriggerEdgeInsets;
@property (weak, nonatomic, readonly) UILongPressGestureRecognizer *longPressGestureRecognizer;
@property (weak, nonatomic, readonly) UIPanGestureRecognizer *panGestureRecognizer;

- (void)setUpGestureRecognizersOnCollectionView __attribute__((deprecated("Calls to setUpGestureRecognizersOnCollectionView method are not longer needed as setup are done automatically through KVO.")));

- (void)shouldMiniminizeCurrentView:(BOOL)shouldMinimize;

@end

@protocol LXReorderableCollectionViewDatasource <NSObject>

- (void)collectionView:(UICollectionView *)collectionView itemAtIndexPath:(NSIndexPath *)fromIndexPath willMoveToIndexPath:(NSIndexPath *)toIndexPath;

@optional

- (BOOL)collectionView:(UICollectionView *)collectionView canMoveItemAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)collectionView:(UICollectionView *)collectionView itemAtIndexPath:(NSIndexPath *)fromIndexPath canMoveToIndexPath:(NSIndexPath *)toIndexPath;

@end

@protocol LXReorderableCollectionViewDelegate <NSObject>
@optional

- (void)collectionView:(UICollectionView *)collectionView isDraggingItemAtIndexPath:(NSIndexPath *)indexPath atPosition:(CGPoint)center;
- (void)collectionView:(UICollectionView *)collectionView willBeginDraggingItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView didBeginDraggingItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView willEndDraggingItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView didEndDraggingItemAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)collectionView:(UICollectionView *)collectionView shouldDeleteItemAtIndexPath:(NSIndexPath *)indexPath;



@end