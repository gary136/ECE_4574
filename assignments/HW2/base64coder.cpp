//#include "Base64Coder.h"

//Base64Coder::Base64Coder(RESTTalker* restTalker) : pRESTTalker(restTalker)
//{
//    connect(pRESTTalker, &RESTTalker::replyReceived, this, &Base64Coder::onReplyReceived);
//}

//QString Base64Coder::encode(const QString& input)
//{
//    QString fixedInput = input;
//    fixedInput.replace(" ", "%20");

//    QString urlstring = "https://networkcalc.com/api/encoder/" + fixedInput + "?encoding=base64";

//    QEventLoop loop;
//    connect(pRESTTalker, &RESTTalker::replyReceived, &loop, &QEventLoop::quit);
//    pRESTTalker->tryREST(urlstring);
//    loop.exec();

//    result = parseResponse(pRESTTalker->getResponse());
//    return result;
//}

//void Base64Coder::onReplyReceived()
//{
//    emit replyProcessed(result);
//}

//QString Base64Coder::parseResponse(const QString& response)
//{
//    return response; // Modify this line to parse the response
//}
