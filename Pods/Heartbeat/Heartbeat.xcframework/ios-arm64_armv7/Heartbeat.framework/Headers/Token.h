//Copyright 2019 Topaz
#import "TokenResponse.h"
@import Foundation;

@interface Token : NSObject

- (void)addParameter:(NSString *) key
          value:(NSString *) value;

- (void)requestAuthorization:(NSString *)authorizationInfo
                     success:(void (^)(void))success
                     failure:(void (^)(int))failure;

- (void)requestAuthorization:(void(^)(void))success
                     failure:(void(^)(int))failure;

- (void)authorize:(NSString *)authorizationCode
          success:(void (^)(void))success
          failure:(void (^)(int))failure;

- (void)getToken:(void(^)(TokenResponse *))success
         failure:(void (^)(int))failure;

- (void)dismiss:(void(^)(void))success
        failure:(void (^)(int))failure;

- (void)checkToken:(void(^)(void))success
           failure:(void (^)(int))failure;

@end

