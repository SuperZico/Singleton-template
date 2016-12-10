//
//  Single.h
//  test
//
//  Created by 周超 on 2016/12/10.
//  Copyright © 2016年 周超. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Single : NSObject
#define SingleH(name) +(instancetype)shared##name;

#define SingleM(name) static id P=nil;\
+(void)load{\
    P=[[self alloc]init];\
}\
\
+(instancetype)shared##name{\
    return P;\
}\
\
+(instancetype)alloc{\
    \
    if (P) {\
        NSException * excp=[NSException exceptionWithName:@"这是一个单例" reason:@"单例不允许创建多个实例，请用+(instancetype)shared类名 方法获取单例" userInfo:nil];\
        [excp raise];\
       \
}\
   \
    return [super alloc];\
}\

@end
