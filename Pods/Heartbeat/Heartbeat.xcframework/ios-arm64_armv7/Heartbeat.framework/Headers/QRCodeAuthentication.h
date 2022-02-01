//Copyright 2020 Topaz

/*!
 @file QRCodeAuthentication.h
 @abstract Interfaces da classe QRCodeAuthentication
 @copyright 2020 Topaz
 */

#import <Foundation/Foundation.h>

/*!
 @enum QRCodeAuthenticationStatus
 @abstract Códigos de retorno passados para classe delegada ao finalizar uma etapa do processo de autenticação
 */
typedef enum : NSInteger {
    QRCodeAuthenticationStatusSendFailure = -47,
    QRCodeAuthenticationStatusStartFailure = -46
} QRCodeAuthenticationStatus;

/*!
 @enum QRCodeAuthenticationAction
 @abstract Código usado para identificar qual ação está relacionada ao código <i>QRCodeAuthenticationStatus</i>
 */
typedef enum : NSInteger {
    QRCodeAuthenticationActionStart = 0,
    QRCodeAuthenticationActionSend = 1
} QRCodeAuthenticationAction;

/*!
 @protocol
 @abstract Protocolo usado para notificar a classe delegada sobre a finalização das etapas de autenticação do QRCode
 */
@protocol QRCodeAuthenticationDelegate

@required
/*!
 @method onFinish
 @abstract Chamada quando o fluxo é finalizado
 @param actionCode Código QRCodeAuthenticationAction da operação em andamento
 @param statusCode Status retornado pelo Analytics com a resposta de comparação da voz do usuário.
 @discussion A classe delegante notifica este método quando concluiu a autenticação do QRCode, o statusCode indicará um código do Analytics QRCode API, um código do tipo QRCodeAuthenticationStatus ou erro 500 em falhas não específicas.
*/
- (void)onFinish:(QRCodeAuthenticationAction)actionCode andStatusCode:(QRCodeAuthenticationStatus)statusCode;

@end

/*!
 @class QRCodeAuthentication
 @abstract Classe concreta para autenticação de QRCode gerado pela API do Analytics QRCode
 @discussion Esta classe lida apenas com a mensagem criptograda pelo Analytics e transportada para o aplicativo através da leitura do QRCode. Com ela você consegue extrair a descrição da transação antes de enviá-la para o Analytics, então o chamador é responsável pela leitura do QRCode.
 */
@interface QRCodeAuthentication : NSObject

/*!
 @method setQrCodeData
 @abstract Inicializa a mensagem base64 que será enviada para o Analytics QRCode API.
 @param qrcodeData string em base64 contendo mensagem criptografada
 */
- (void)setQrCodeData:(NSString *)qrcodeData;

/*!
 @method initWithDelegate
 @param delegate Objeto da classe delegada para receber notificações sobre as etapas da autenticação via QRCode
 @abstract Construtor para inicializar a classe com um objeto que implementa o protocolo <i>QRCodeAuthenticationDelegate</i>
 @discussion Se houver um problema na inicialização do objeto, o objeto da classe delegada é notificado no método onFinish indicando o ActionCode QRCodeAuthenticationActionStart e um StatusCode QRCodeAuthenticationStatusStartFailure
 */
- (instancetype)initWithDelegate:(id<QRCodeAuthenticationDelegate>)delegate;

/*!
 @method addParameter
 @param key  chave id para o novo objeto
 @param value objeto para inclusao
 @abstract Adiciona parâmetros requeridos pelo Analytics QRCode API
 */
- (void)addParameter:(NSString *)key value:(NSString *)value;

/*!
 @method getMessage
 @abstract Obtem uma cópia da mensagem desencriptada contida no QRCode
 @discussion Este método sempre retorna uma string. Uma string vazia pode indicar que:
 <ul>
  <li> houve um erro na inicialização do objeto QRCodeAuthentication, mais detalhes na documentação do construtor;</li>
  <li> não foi passado um QRCode para a instância do QRCodeAuthentication usando o método setQrCodeData();</li>
  <li> a instância do QRCodeAuthentication não pode decifrar o conteúdo do QRCode passado</li>
 </ul>
 */
- (NSString *)getMessage;

/*!
 @method send
 @abstract Envia informações contidas no QRCode para Analytics QRCode API
 @discussion Este método notifica o objeto da classe delegada <i>QRCodeAuthenticationDelegate</i> no método onFinish:
 */
- (void)send;

@end
