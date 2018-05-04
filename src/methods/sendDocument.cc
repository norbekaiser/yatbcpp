//    Copyright (c) 2017,2018 Norbert Rühl
//    
//    This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
//    
//    Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
//    
//        1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
//    
//        2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
//    
//        3. This notice may not be removed or altered from any source distribution.

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "methods/sendDocument.h"

using namespace std;
using namespace yatbcpp;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sendDocument::sendDocument(Chat C, std::string Document) :
        telegram_methodJSON("sendDocument"), telegram_methodMultipart("sendDocument"),
        chat_id(to_string(C.getId())), document(Document)
{

}

sendDocument::sendDocument(int chat_id, std::string Document) :
        telegram_methodJSON("sendDocument"), telegram_methodMultipart("sendDocument"),
        chat_id(to_string(chat_id)), document(Document)
{

}

sendDocument::sendDocument(string chat_id, std::string Document) :
        telegram_methodJSON("sendDocument"), telegram_methodMultipart("sendDocument"),
        chat_id(chat_id), document(Document)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Outgoing Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Json::Value sendDocument::toJson() {
    Json::Value Outgoing;
    Outgoing["chat_id"] = getChat_id();
    Outgoing["document"] = getDocument();

    if(getCaption()){
        Outgoing["caption"] = getCaption().value();
    }
    if(getDisable_notification()){
        Outgoing["disable_notification"] = getDisable_notification().value();
    }
    if(getReply_to_message_id()){
        Outgoing["reply_to_message_id"] = getReply_to_message_id().value();
    }

    return Outgoing;

}

void sendDocument::add_to_post(struct curl_httppost **start, struct curl_httppost **end) {
    curl_formadd(start,end,
                 CURLFORM_COPYNAME,"chat_id",
                 CURLFORM_COPYCONTENTS,chat_id.c_str(),
                 CURLFORM_END);
    curl_formadd(start,end,
                 CURLFORM_COPYNAME,"document",
                 CURLFORM_FILE,document.c_str(),
                 CURLFORM_END);
    if(caption){
        curl_formadd(start,end,
                     CURLFORM_COPYNAME,"caption",
                     CURLFORM_COPYCONTENTS,caption.value().c_str(),
                     CURLFORM_END);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sendDocument::setCaption(const optional<string> &caption) {
    sendDocument::caption = caption;
}


void sendDocument::setDisable_notification(const std::optional<bool> &disable_notification) {
    sendDocument::disable_notification = disable_notification;
}

void sendDocument::setReply_to_message_id(const std::optional<int> &reply_to_message_id) {
    sendDocument::reply_to_message_id = reply_to_message_id;
}

/**
 * Sets an ReplyKeyboardMarkup
 * @param RKM
 */
void sendDocument::setReplyMarkup(const ReplyKeyboardMarkup RKM){
    sendDocument::reply_markup = RKM;
}

/**
 * Sets an ReplyKeyboardRemove
 * @param RKR
 */
void sendDocument::setReplyMarkup(const ReplyKeyboardRemove RKR){
    sendDocument::reply_markup = RKR;
}

/**
 * Sets an ForceReply
 * @param FR
 */
void sendDocument::setReplyMarkup(const ForceReply FR){
    sendDocument::reply_markup = FR;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &sendDocument::getChat_id() const {
    return chat_id;
}

const string &sendDocument::getDocument() const {
    return document;
}

const optional<string> &sendDocument::getCaption() const {
    return caption;
}

const optional<bool> &sendDocument::getDisable_notification() const {
    return disable_notification;
}

const optional<int> &sendDocument::getReply_to_message_id() const {
    return reply_to_message_id;
}

const optional<ReplyMarkup> &sendDocument::getReply_markup() const {
    return reply_markup;
}
