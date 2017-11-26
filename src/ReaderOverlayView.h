//------------------------------------------------------------------------
//  Copyright 2009-2011 (c) Jeff Brown <spadix@users.sourceforge.net>
//
//  This file is part of the ZBar iPhone App.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
//  http://zbar.sourceforge.net/iphone
//------------------------------------------------------------------------

typedef enum {
    OVERLAY_MODE_DONE,
    OVERLAY_MODE_CANCEL
} ReaderOverlayMode;

@class GradientView, ShapeView;

@protocol ReaderOverlayDelegate
- (void) readerOverlayDidDismiss;
- (void) readerOverlayDidRequestHelp;
@end


@interface ReaderOverlayView : UIView
{
    NSObject<ReaderOverlayDelegate> *delegate;
    UIToolbar *toolbar;
    UIBarButtonItem *doneBtn, *cancelBtn, *space;
    UIButton *infoBtn;
    UIView *tipView;
    GradientView *topMask, *bottomMask;
    ShapeView *cropGuide[4];
    NSTimeInterval tipShowDelay, tipHideDelay;
    BOOL enableLandscapeCrop, enableTip, tipVisible;
    UIBezierPath *guidePath;
}

- (id) init;
- (void) willAppear;
- (void) willDisappear;
- (void) setMode: (ReaderOverlayMode) mode;

@property (nonatomic, assign) NSObject<ReaderOverlayDelegate> *delegate;

@property (nonatomic) BOOL enableLandscapeCrop;

// delay in seconds before the popup tip is shown.  set to 0 to disable.
@property (nonatomic) NSTimeInterval tipShowDelay;

// delay in seconds before the popup tip is automatically hidden.
// set to 0 to disable and leave tip visible until dismissed.
@property (nonatomic) NSTimeInterval tipHideDelay;

@end
