/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <UIKit/UIKit.h>

#import <ReactABI24_0_0/ABI24_0_0RCTBridgeModule.h>
#import <ReactABI24_0_0/ABI24_0_0RCTInvalidating.h>

typedef NS_ENUM(NSInteger, ABI24_0_0RCTAlertViewStyle) {
  ABI24_0_0RCTAlertViewStyleDefault = 0,
  ABI24_0_0RCTAlertViewStyleSecureTextInput,
  ABI24_0_0RCTAlertViewStylePlainTextInput,
  ABI24_0_0RCTAlertViewStyleLoginAndPasswordInput
};


@interface ABI24_0_0RCTAlertManager : NSObject <ABI24_0_0RCTBridgeModule, ABI24_0_0RCTInvalidating>

@end
