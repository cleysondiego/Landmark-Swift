//Copyright 2020 Topaz

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@protocol VoiceAuthenticationDelegate
@required

/*!
    @method onFinish:
    @abstract Chamada quando o fluxo é finalizado
    @param actionCode Ação associada ao statusCode
    @param statusCode Status retornado pelo Analytics com a resposta de comparação da voz do usuário.
*/
- (void) onFinish:(int)actionCode andStatusCode:(int)statusCode;

@end

typedef NS_ENUM(NSInteger, VoiceAuthenticationStatusCode) {
    VoiceAuthenticationStatusCodeMaxAudioTimeReached = -45,
    VoiceAuthenticationStatusCodeStartFailure = -46,
    VoiceAuthenticationStatusCodeSendFailure = -47,
    VoiceAuthenticationStatusCodeStopFailure = -48,
    VoiceAuthenticationStatusCodeReleaseFailure = -49,
    VoiceAuthenticationStatusCodeRecordFailure = -50
};

typedef NS_ENUM(NSInteger, VoiceAuthenticationAction) {
    VoiceAuthenticationSendVoiceAction = 1,
    VoiceAuthenticationSendBaseVoiceAction = 2,
    VoiceAuthenticationStartRecordAction = 3,
    VoiceAuthenticationStopRecordAction = 4,
    VoiceAuthenticationReleaseAction = 5,
    VoiceAuthenticationPrepareAction = 6
};

@interface VoiceAuthentication : NSObject <AVAudioRecorderDelegate, VoiceAuthenticationDelegate>

/*!
    @method initWithDelegate:
    @param voiceAuthenticationDelegate Objeto que implementa as funções para receber os retornos de Voz
    @abstract Inicializa a classe de Voz
*/
- (instancetype)initWithDelegate: (id) voiceAuthenticationDelegate;
- (BOOL) prepare;
- (void) startRecord;
- (void) stopRecord;
- (void) sendRecord;
- (void) sendRecordAsBaseVoice;
- (void) releaseRecord;
- (NSData *) getAudioBuffer;
- (void)addParameter:(NSString *) key value:(NSString *) value;

@end
