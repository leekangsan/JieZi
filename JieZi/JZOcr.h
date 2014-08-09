//
//  JZOcr.h
//  JieZi
//
//  Created by 崔峥 on 14-8-5.
//  Copyright (c) 2014年 cuizzz. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
//#import <TesseractOCR/TesseractOCR.h>
#import "Tesseract.h"

@protocol JZOcrDelegate <NSObject>

@optional

- (void)OcrDidGetContentWithString:(NSString *)value;
- (void)OcrDidConfirmWithString:(NSString *)value;
- (void)OcrProgressImageRecognitionForTesseract:(Tesseract*)tesseract;

@required

- (void)OcrDidGetReconizedContextWithString:(NSString *)value;
@end

//@interface JZOcr : NSObject <AVCaptureMetadataOutputObjectsDelegate, UIAlertViewDelegate, TesseractDelegate>
@interface JZOcr : NSObject <AVCaptureMetadataOutputObjectsDelegate, UIAlertViewDelegate>

@property (strong,nonatomic)AVCaptureDevice *device;
@property (strong,nonatomic)AVCaptureDeviceInput *input;
@property (strong,nonatomic)AVCaptureStillImageOutput *output;
@property (strong,nonatomic)AVCaptureSession *session;
@property (strong,nonatomic)AVCaptureVideoPreviewLayer *preview;
@property (strong,nonatomic)UIImageView *view;
@property (strong,nonatomic)UIView *borderView;
@property (strong,nonatomic)NSString *qrvalue;
@property (strong,nonatomic)id<JZOcrDelegate> delegate;
@property (nonatomic, strong) Tesseract *tesseract;
@property (nonatomic, assign) CGFloat lastScale;
@property (nonatomic, assign) CGFloat currentScale;
@property (nonatomic, assign) CGPoint startLocation;
@property (nonatomic, strong) UIImage *currentImage;
@property (nonatomic, strong) UIImage *currentRawImage;

- (id)initWithView:(UIView *)view;
- (void)startRunning;
- (void)captureimage;
- (void)showCurrentRawImageInViewBackground;
- (void)removeCurrentRawImageInViewBackground;

@end
