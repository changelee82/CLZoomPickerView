//
//  CLZoomPickerView.h
//  CLZoomPickerView
//
//  Created by 李辉 on 15/12/13.
//  Copyright © 2015年 李辉. All rights reserved.
//  https://github.com/changelee82/CLZoomPickerView
//


#import <UIKit/UIKit.h>

@protocol CLZoomPickerViewDelegate;
@protocol CLZoomPickerViewDataSource;



@interface CLZoomPickerView : UIView

/** 代理 */
@property (nonatomic, weak) id<CLZoomPickerViewDelegate> delegate;

/** 数据源 */
@property (nonatomic, weak) id<CLZoomPickerViewDataSource> dataSource;


/** 当前行上方显示行数，默认2 */
@property (nonatomic, assign) NSUInteger topRowCount;

/** 当前行下方显示行数，默认2 */
@property (nonatomic, assign) NSUInteger bottomRowCount;

/** 当前选中行的序号，通过此属性选择行，将没有动画效果 */
@property (nonatomic, assign) NSUInteger selectedRow;

/** 行高，默认20 */
@property (nonatomic, assign) CGFloat rowHeight;

/** 当前选中行的字体 */
@property (nonatomic, strong) UIFont *selectedRowFont;

/** 字体颜色，默认黑色 */
@property (nonatomic, strong) UIColor *textColor;

/** 未选中行的字体缩放比例，范围：[0, 1]，默认0.5 */
@property (nonatomic, assign) CGFloat unselectedRowScale;

/** 行数量 */
@property (nonatomic, readonly, assign) NSUInteger rowCount;

/** CLZoomPickerView实际占用的高度 */
@property (nonatomic, readonly, assign) CGFloat fitHeight;


/** 重新加载数据源 */
- (void)reloadData;

/** 通过行序号，选择指定行 */
- (void)selectRow:(NSInteger)row animated:(BOOL)animated;

@end



/** CLZoomPickerView 代理协议 */
@protocol CLZoomPickerViewDelegate <NSObject>

@optional

/** 返回在指定行需要显示的字符串 */
- (NSString *)pickerView:(CLZoomPickerView *)pickerView titleForRow:(NSUInteger)indexPath;

/** 当前项改变后调用此方法 */
- (void)pickerView:(CLZoomPickerView *)pickerView changedIndex:(NSUInteger)indexPath;

@end



/** CLZoomPickerView 数据源协议 */
@protocol CLZoomPickerViewDataSource <NSObject>

/** 返回数据行数 */
- (NSInteger)pickerView:(CLZoomPickerView *)pickerView;

@end



