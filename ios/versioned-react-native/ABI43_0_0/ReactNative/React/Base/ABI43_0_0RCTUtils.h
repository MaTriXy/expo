/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <tgmath.h>

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <ABI43_0_0React/ABI43_0_0RCTAssert.h>
#import <ABI43_0_0React/ABI43_0_0RCTDefines.h>

NS_ASSUME_NONNULL_BEGIN

// JSON serialization/deserialization
ABI43_0_0RCT_EXTERN NSString *__nullable ABI43_0_0RCTJSONStringify(id __nullable jsonObject, NSError **error);
ABI43_0_0RCT_EXTERN id __nullable ABI43_0_0RCTJSONParse(NSString *__nullable jsonString, NSError **error);
ABI43_0_0RCT_EXTERN id __nullable ABI43_0_0RCTJSONParseMutable(NSString *__nullable jsonString, NSError **error);

// Sanitize a JSON object by stripping invalid types and/or NaN values
ABI43_0_0RCT_EXTERN id ABI43_0_0RCTJSONClean(id object);

// Get MD5 hash of a string
ABI43_0_0RCT_EXTERN NSString *ABI43_0_0RCTMD5Hash(NSString *string);

// Check if we are currently on the main queue (not to be confused with
// the main thread, which is not necessarily the same thing)
// https://twitter.com/olebegemann/status/738656134731599872
ABI43_0_0RCT_EXTERN BOOL ABI43_0_0RCTIsMainQueue(void);

// Execute the specified block on the main queue. Unlike dispatch_async()
// this will execute immediately if we're already on the main queue.
ABI43_0_0RCT_EXTERN void ABI43_0_0RCTExecuteOnMainQueue(dispatch_block_t block);

// Legacy function to execute the specified block on the main queue synchronously.
// Please do not use this unless you know what you're doing.
ABI43_0_0RCT_EXTERN void ABI43_0_0RCTUnsafeExecuteOnMainQueueSync(dispatch_block_t block);

// Get screen metrics in a thread-safe way
ABI43_0_0RCT_EXTERN CGFloat ABI43_0_0RCTScreenScale(void);
ABI43_0_0RCT_EXTERN CGFloat ABI43_0_0RCTFontSizeMultiplier(void);
ABI43_0_0RCT_EXTERN CGSize ABI43_0_0RCTScreenSize(void);
ABI43_0_0RCT_EXTERN CGSize ABI43_0_0RCTViewportSize(void);

// Round float coordinates to nearest whole screen pixel (not point)
ABI43_0_0RCT_EXTERN CGFloat ABI43_0_0RCTRoundPixelValue(CGFloat value);
ABI43_0_0RCT_EXTERN CGFloat ABI43_0_0RCTCeilPixelValue(CGFloat value);
ABI43_0_0RCT_EXTERN CGFloat ABI43_0_0RCTFloorPixelValue(CGFloat value);

// Convert a size in points to pixels, rounded up to the nearest integral size
ABI43_0_0RCT_EXTERN CGSize ABI43_0_0RCTSizeInPixels(CGSize pointSize, CGFloat scale);

// Method swizzling
ABI43_0_0RCT_EXTERN void ABI43_0_0RCTSwapClassMethods(Class cls, SEL original, SEL replacement);
ABI43_0_0RCT_EXTERN void ABI43_0_0RCTSwapInstanceMethods(Class cls, SEL original, SEL replacement);
ABI43_0_0RCT_EXTERN void ABI43_0_0RCTSwapInstanceMethodWithBlock(Class cls, SEL original, id replacementBlock, SEL replacementSelector);

// Module subclass support
ABI43_0_0RCT_EXTERN BOOL ABI43_0_0RCTClassOverridesClassMethod(Class cls, SEL selector);
ABI43_0_0RCT_EXTERN BOOL ABI43_0_0RCTClassOverridesInstanceMethod(Class cls, SEL selector);

// Creates a standardized error object to return in callbacks
ABI43_0_0RCT_EXTERN NSDictionary<NSString *, id>
    *ABI43_0_0RCTMakeError(NSString *message, id __nullable toStringify, NSDictionary<NSString *, id> *__nullable extraData);
ABI43_0_0RCT_EXTERN NSDictionary<NSString *, id> *
ABI43_0_0RCTMakeAndLogError(NSString *message, id __nullable toStringify, NSDictionary<NSString *, id> *__nullable extraData);
ABI43_0_0RCT_EXTERN NSDictionary<NSString *, id> *ABI43_0_0RCTJSErrorFromNSError(NSError *error);
ABI43_0_0RCT_EXTERN NSDictionary<NSString *, id>
    *ABI43_0_0RCTJSErrorFromCodeMessageAndNSError(NSString *code, NSString *message, NSError *__nullable error);

// The default error code to use as the `code` property for callback error objects
ABI43_0_0RCT_EXTERN NSString *const ABI43_0_0RCTErrorUnspecified;

// Returns YES if ABI43_0_0React is running in a test environment
ABI43_0_0RCT_EXTERN BOOL ABI43_0_0RCTRunningInTestEnvironment(void);

// Returns YES if ABI43_0_0React is running in an iOS App Extension
ABI43_0_0RCT_EXTERN BOOL ABI43_0_0RCTRunningInAppExtension(void);

// Returns the shared UIApplication instance, or nil if running in an App Extension
ABI43_0_0RCT_EXTERN UIApplication *__nullable ABI43_0_0RCTSharedApplication(void);

// Returns the current main window, useful if you need to access the root view
// or view controller
ABI43_0_0RCT_EXTERN UIWindow *__nullable ABI43_0_0RCTKeyWindow(void);

// Returns the presented view controller, useful if you need
// e.g. to present a modal view controller or alert over it
ABI43_0_0RCT_EXTERN UIViewController *__nullable ABI43_0_0RCTPresentedViewController(void);

// Does this device support force touch (aka 3D Touch)?
ABI43_0_0RCT_EXTERN BOOL ABI43_0_0RCTForceTouchAvailable(void);

// Create an NSError in the ABI43_0_0RCTErrorDomain
ABI43_0_0RCT_EXTERN NSError *ABI43_0_0RCTErrorWithMessage(NSString *message);

// Creates an NSError from given an NSException
ABI43_0_0RCT_EXTERN NSError *ABI43_0_0RCTErrorWithNSException(NSException *exception);

// Convert nil values to NSNull, and vice-versa
#define ABI43_0_0RCTNullIfNil(value) ((value) ?: (id)kCFNull)
#define ABI43_0_0RCTNilIfNull(value)                           \
  ({                                                  \
    __typeof__(value) t = (value);                    \
    (id) t == (id)kCFNull ? (__typeof(value))nil : t; \
  })

// Convert NaN or infinite values to zero, as these aren't JSON-safe
ABI43_0_0RCT_EXTERN double ABI43_0_0RCTZeroIfNaN(double value);

// Returns `0` and log special warning if value is NaN or INF.
ABI43_0_0RCT_EXTERN double ABI43_0_0RCTSanitizeNaNValue(double value, NSString *property);

// Convert data to a Base64-encoded data URL
ABI43_0_0RCT_EXTERN NSURL *ABI43_0_0RCTDataURL(NSString *mimeType, NSData *data);

// Gzip functionality - compression level in range 0 - 1 (-1 for default)
ABI43_0_0RCT_EXTERN NSData *__nullable ABI43_0_0RCTGzipData(NSData *__nullable data, float level);

// Returns the relative path within the main bundle for an absolute URL
// (or nil, if the URL does not specify a path within the main bundle)
ABI43_0_0RCT_EXTERN NSString *__nullable ABI43_0_0RCTBundlePathForURL(NSURL *__nullable URL);

// Returns the Path of Library directory
ABI43_0_0RCT_EXTERN NSString *__nullable ABI43_0_0RCTLibraryPath(void);

// Returns the relative path within the library for an absolute URL
// (or nil, if the URL does not specify a path within the Library directory)
ABI43_0_0RCT_EXTERN NSString *__nullable ABI43_0_0RCTLibraryPathForURL(NSURL *__nullable URL);

// Determines if a given image URL refers to a image in bundle
ABI43_0_0RCT_EXTERN BOOL ABI43_0_0RCTIsBundleAssetURL(NSURL *__nullable imageURL);

// Determines if a given image URL refers to a image in library
ABI43_0_0RCT_EXTERN BOOL ABI43_0_0RCTIsLibraryAssetURL(NSURL *__nullable imageURL);

// Determines if a given image URL refers to a local image
ABI43_0_0RCT_EXTERN BOOL ABI43_0_0RCTIsLocalAssetURL(NSURL *__nullable imageURL);

// Returns an UIImage for a local image asset. Returns nil if the URL
// does not correspond to a local asset.
ABI43_0_0RCT_EXTERN UIImage *__nullable ABI43_0_0RCTImageFromLocalAssetURL(NSURL *imageURL);

// Only used in case when ABI43_0_0RCTImageFromLocalAssetURL fails to get an image
// This method basically checks for the image in the bundle location, instead
// of the CodePush location
ABI43_0_0RCT_EXTERN UIImage *__nullable ABI43_0_0RCTImageFromLocalBundleAssetURL(NSURL *imageURL);

// Creates a new, unique temporary file path with the specified extension
ABI43_0_0RCT_EXTERN NSString *__nullable ABI43_0_0RCTTempFilePath(NSString *__nullable extension, NSError **error);

// Get RGBA components of CGColor
ABI43_0_0RCT_EXTERN void ABI43_0_0RCTGetRGBAColorComponents(CGColorRef color, CGFloat rgba[_Nonnull 4]);

// Converts a CGColor to a hex string
ABI43_0_0RCT_EXTERN NSString *ABI43_0_0RCTColorToHexString(CGColorRef color);

// Get standard localized string (if it exists)
ABI43_0_0RCT_EXTERN NSString *ABI43_0_0RCTUIKitLocalizedString(NSString *string);

// Get a human readable type string from an NSObject. For example NSString becomes string
ABI43_0_0RCT_EXTERN NSString *ABI43_0_0RCTHumanReadableType(NSObject *obj);

// URL manipulation
ABI43_0_0RCT_EXTERN NSString *__nullable ABI43_0_0RCTGetURLQueryParam(NSURL *__nullable URL, NSString *param);
ABI43_0_0RCT_EXTERN NSURL *__nullable
ABI43_0_0RCTURLByReplacingQueryParam(NSURL *__nullable URL, NSString *param, NSString *__nullable value);

// Given a string, drop common ABI43_0_0RN prefixes (ABI43_0_0RCT, RK, etc.)
ABI43_0_0RCT_EXTERN NSString *ABI43_0_0RCTDropABI43_0_0ReactPrefixes(NSString *s);

ABI43_0_0RCT_EXTERN BOOL ABI43_0_0RCTUIManagerTypeForTagIsFabric(NSNumber *ABI43_0_0ReactTag);

ABI43_0_0RCT_EXTERN BOOL ABI43_0_0RCTValidateTypeOfViewCommandArgument(
    NSObject *obj,
    id expectedClass,
    NSString const *expectedType,
    NSString const *componentName,
    NSString const *commandName,
    NSString const *argPos);

NS_ASSUME_NONNULL_END
