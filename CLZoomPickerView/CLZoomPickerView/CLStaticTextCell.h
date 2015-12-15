//
//  CLStaticTextCell.h
//  CLZoomPickerView
//
//  Created by 李辉 on 15/12/14.
//  Copyright © 2015年 李辉. All rights reserved.
//

#import <UIKit/UIKit.h>


/** 垂直对齐方向 */
typedef NS_ENUM(NSInteger, VerticalAlignment) {
    VerticalAlignmentTop,
    VerticalAlignmentMiddle,
    VerticalAlignmentBottom
};


/**
 *  静态文字视图
 *  只提供了简单的文字显示功能
 *  添加了垂直对齐方向属性
 */
@interface CLStaticTextCell : UITableViewCell


/** 文字 */
@property (nonatomic, copy) NSString *text;

/** 文字字体 */
@property (nonatomic, strong) UIFont *font;

/** 文字颜色 */
@property (nonatomic, strong) UIColor *textColor;

/** 水平对齐方向，默认为 NSTextAlignmentCenter */
@property (nonatomic, assign) NSTextAlignment alignment;

/** 垂直对齐方向，默认为 VerticalAlignmentMiddle */
@property (nonatomic, assign) VerticalAlignment verticalAlignment;



@end