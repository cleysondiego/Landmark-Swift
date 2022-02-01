//Copyright 2018 Topaz

@import UIKit;

//! Project version number for Heartbeat.
FOUNDATION_EXPORT double HeartbeatVersionNumber;

//! Project version string for Heartbeat.
FOUNDATION_EXPORT const unsigned char HeartbeatVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <Heartbeat/PublicHeader.h>

// ****** define face para CI ******
// #define FACE 1
// *********************************

#ifdef FACE
#import <HeartbeatFace/HeartbeatStarter.h>
#import <HeartbeatFace/Event.h>
#import <HeartbeatFace/Token.h>
#import <HeartbeatFace/FaceAuthorization.h>
#import <HeartbeatFace/VoiceAuthentication.h>
#import <HeartbeatFace/QRCodeAuthentication.h>
#import <HeartbeatFace/OFDOCR.h>
#import <HeartbeatFace/OCRFile.h>
#else
#import <Heartbeat/HeartbeatStarter.h>
#import <Heartbeat/Event.h>
#import <Heartbeat/Token.h>
#import <Heartbeat/VoiceAuthentication.h>
#import <Heartbeat/QRCodeAuthentication.h>
#endif

