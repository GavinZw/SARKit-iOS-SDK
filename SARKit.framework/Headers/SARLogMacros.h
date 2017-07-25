//
//  SARLogMacros.h
//  MySky
//
//  Created by Gavin on 2017/6/28.
//
//
#if __has_include(<SARKit/SARKit.h>)
#import <SARKit/SARManage.h>
#else
#import "SARManage.h"
#endif

/**
 * This is the single macro that all other macros below compile into.
 * This big multiline macro makes all the other macros easier to read.
 **/
#define AR_LOG_MACRO(frmt, ...) \
[SARManage verboseLogFormat : (frmt), ## __VA_ARGS__]

/**
 * Define version of the macro that only execute if the log level is above the threshold.
 * The compiled versions essentially look like this:
 **/
#define AR_LOG_MAYBE(frmt, ...) \
do { AR_LOG_MACRO(frmt, ##__VA_ARGS__); } while(0)

/**
 * Ready to use log macros with no context or tag.
 **/
#define AR_LOG( frmt, ...) \
AR_LOG_MAYBE(frmt, ##__VA_ARGS__)

/**
 * Ready to use log macros with no context or tag.
 **/
#define AR_ERROR_LOG( frmt, ...) \
AR_LOG_MAYBE(frmt, ##__VA_ARGS__)

