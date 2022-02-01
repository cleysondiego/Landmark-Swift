//Copyright 2018 Topaz

#import <Foundation/Foundation.h>

@interface Event : NSObject

- (void)addParameter:(NSString *) key value:(NSString *) value;
- (void)sendEvent;

@end
