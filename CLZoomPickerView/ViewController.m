//
//  ViewController.m
//  CLZoomPickerView
//
//  Created by 李辉 on 15/12/13.
//  Copyright © 2015年 李辉. All rights reserved.
//

#import "ViewController.h"
#import "CLZoomPickerView.h"


@interface ViewController ()  <CLZoomPickerViewDelegate, CLZoomPickerViewDataSource>

@property (weak, nonatomic) IBOutlet CLZoomPickerView *pickerView;

@property (weak, nonatomic) IBOutlet UILabel *displayTextLabel;
@property (weak, nonatomic) IBOutlet UILabel *viewHeightLabel;

@property (nonatomic, strong) NSArray *timeArray;

- (IBAction)buttonAClick:(UIButton *)sender;
- (IBAction)buttonBClick:(UIButton *)sender;
- (IBAction)buttonCClick:(UIButton *)sender;


@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    _timeArray = [NSArray arrayWithObjects:@"20min",@"30min",@"40min",@"50min",@"60min",@"70min",@"80min",@"90min",nil];
    
    self.pickerView.dataSource = self;
    self.pickerView.delegate = self;
    
    self.pickerView.topRowCount = 2;
    self.pickerView.bottomRowCount = 2;
    
    self.pickerView.selectedRow = 1;
    self.pickerView.rowHeight = 40;
    self.pickerView.selectedRowFont = [UIFont fontWithName:@"DIN Condensed" size:35];
    self.pickerView.textColor = [UIColor redColor];
    self.pickerView.unselectedRowScale = 0.5;
    
    
    self.viewHeightLabel.text = [NSString stringWithFormat:@"高度：%.2f", self.pickerView.fitHeight];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - CLZoomPickerView 代理

// CLZoomPickerView 代理，当前项改变后调用此方法
- (void)pickerView:(CLZoomPickerView *)pickerView changedIndex:(NSUInteger)indexPath
{
    self.displayTextLabel.text = _timeArray[indexPath];
}


// CLZoomPickerView 代理，返回数据行数
- (NSInteger)pickerView:(CLZoomPickerView *)pickerView
{
    return _timeArray.count;
}

// CLZoomPickerView 代理，返回指定行显示的字符串
- (NSString *)pickerView:(CLZoomPickerView *)pickerView titleForRow:(NSUInteger)indexPath
{
    return _timeArray[indexPath];
}

#pragma mark - 方法

- (IBAction)buttonAClick:(UIButton *)sender {
    NSUInteger row = self.pickerView.selectedRow;
    if (row == 0)
        return;
    
    self.pickerView.selectedRow = row - 1;
}

- (IBAction)buttonBClick:(UIButton *)sender {
    NSUInteger row = self.pickerView.selectedRow;
    [self.pickerView selectRow:(row + 1) animated:YES];
}

- (IBAction)buttonCClick:(UIButton *)sender {
    [self.pickerView selectRow:(self.pickerView.rowCount/2-1) animated:YES];
}

@end
