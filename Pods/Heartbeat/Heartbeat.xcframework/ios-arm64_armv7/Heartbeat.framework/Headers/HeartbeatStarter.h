//Copyright 2018 Topaz

@import Foundation;

@interface Heartbeat : NSObject

+ (void)start:(NSString *)clientId;
+ (void)start:(NSString *)clientId onSuccess:(void (^)(int statusCode))onSuccess onFailure:(void (^)(int statusCode))onFailure;
+ (NSString *)getCipheredId:(NSString *)sessionId;
+ (NSString *)getInfo:(int)item;
+ (void) setDefaultUrl:(NSString *)defaultUrl;

@end
