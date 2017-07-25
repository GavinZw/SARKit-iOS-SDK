//
//  MySkyARUnity.m
//  Gavin
//
//  Created by Gavin on 2017/6/29.
//
//
#import "MySkyARUnity.h"

void UnitySendMessage(const char *obj, const char *method, const char *msg);

extern "C" {
  static char *MySkyARCopyString(const char *string) {
    if (string != NULL) {
      char *res = strdup(string);
      return res;
    }
    
    return NULL;
  }
  
  static NSString *MySkyARCreateNSString(const char *string) {
    return string ? [NSString stringWithUTF8String:string] : [NSString stringWithUTF8String:""];
  }
  
  static NSURL *MySkyARCreateNSURL(const char *string) {
    return [NSURL URLWithString:MySkyARCreateNSString(string)];
  }
}

static MySkyARUnity *everyplayUnity = [MySkyARUnity sharedInstance];
static const char *arUnityGameObjectName = NULL;
static const char *arUnityGameObjectMethodName = NULL;

@implementation MySkyARUnity

+ (void)initialize {
  if (everyplayUnity == nil) {
    everyplayUnity = [[MySkyARUnity alloc] init];
  }
}

+ (MySkyARUnity *)sharedInstance {
  return everyplayUnity;
}

+ (NSString *)jsonFromDictionary:(NSDictionary *)dictionary {
  NSError *error = nil;
  NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dictionary options:0 error:&error];
  if (error == nil) {
    return [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
  } else {
    AR_LOG(@"Failed generating JSON: %@", error);
  }
  return nil;
}

+ (NSDictionary *)dictionaryFromJson:(NSString *)json {
  if (json != nil) {
    NSError *error = nil;
    NSData *jsonData = [json dataUsingEncoding:NSUTF8StringEncoding];
    
    id jsonParsedObj = [NSJSONSerialization JSONObjectWithData:jsonData options:0 error:&error];
    
    if (error == nil) {
      if ([jsonParsedObj isKindOfClass:[NSDictionary class]]) {
        return (NSDictionary *) jsonParsedObj;
      }
    } else {
      AR_LOG(@"Failed parsing JSON: %@", error);
    }
  }
  
  return nil;
}

- (id)init {
  if (everyplayUnity != nil) {
    return everyplayUnity;
  }
  
  self = [super init];
  
  if (self) {
    everyplayUnity = self;
    displayLinkPaused = NO;
    
#if UNITY_VERSION >= 430
    UnityRegisterAppDelegateListener(self);
#endif
    [SARManage initWithDelegate:self];
    
    if (arUnityGameObjectName != NULL) {
      free((char *)arUnityGameObjectName);
      arUnityGameObjectName = NULL;
    }
    
    if (arUnityGameObjectMethodName != NULL) {
      free((char *)arUnityGameObjectMethodName);
      arUnityGameObjectMethodName = NULL;
    }
    
    const char *gameObjectName = [[SARManage sharedAR].GameObjectName UTF8String];
    arUnityGameObjectName = strdup(gameObjectName);
    
    const char *gameObjectMethodName = [[SARManage sharedAR].GameObjectMethodName UTF8String];
    arUnityGameObjectMethodName = strdup(gameObjectMethodName);
    
  }
  return self;
}

#pragma makr - SAREngineDelegate

- (void)arSceneShown{  
#if TARGET_OS_IPHONE && TARGET_OS_IOS
  currentOrientation = UnityGetGLViewController().interfaceOrientation;
#endif
//  UnityPause(false);
  [[UnityAppController sharedInstance] startUnityApp];
}

- (void)arSceneHidden{
//   UnityPause(true);
  #if TARGET_OS_IPHONE && TARGET_OS_IOS
  /* Force orientation check, orientation could have changed while Unity was paused */
  UIInterfaceOrientation newOrientation = UnityGetGLViewController().interfaceOrientation;
  
  #endif
  [[UnityAppController sharedInstance] stopUnityApp];
  
}

- (UIView *)arGLSceneView{
  return UnityGetGLView();
}

- (void)arEngineSendOnMethod:(NSString *)method data:(id)data{
  if (arUnityGameObjectName != NULL && arUnityGameObjectMethodName != NULL) {
    NSString *message = [MySkyARUnity jsonFromDictionary:data];
    UnitySendMessage(arUnityGameObjectName, arUnityGameObjectMethodName, [message UTF8String]);
  }
}

@end


extern "C" {
  void Sky_Unity_CallBack_log(const char *log){
    
  }
  
  void Sky_Unity_CallBack(char *message){
    if (message != NULL) {
      NSString *strValue = MySkyARCreateNSString(message);
      NSDictionary *dictionary = [MySkyARUnity dictionaryFromJson:strValue];
      [[SARManage sharedAR] arEngineReceiveMessage:dictionary effective:(dictionary != nil)];
    }
  }
}
