//Copyright 2019 Topaz

#import <Foundation/Foundation.h>

@interface TokenResponse : NSObject
@property (nonatomic) NSString *token;
@property (nonatomic) int duration;

-(instancetype)initWithToken:(NSString *)token andDuration:(int)duration;
@end
