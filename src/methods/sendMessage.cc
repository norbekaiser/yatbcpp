//    Copyright (c) 2017 Norbert Rühl
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
#include "methods/sendMessage.h"

using namespace std;
using namespace yatbcpp;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sendMessage::sendMessage(Chat C, std::string text) :
        telegram_methodJSON("sendMessage"),
        chat_id(to_string(C.getId())), text(text)
{

}

sendMessage::sendMessage(int chat_id, std::string text) :
        telegram_methodJSON("sendMessage"),
        chat_id(to_string(chat_id)), text(text)
{

}

sendMessage::sendMessage(string chat_id, std::string text) :
        telegram_methodJSON("sendMessage"),
        chat_id(chat_id), text(text)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Outgoing Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Json::Value sendMessage::toJson() {
    Json::Value Outgoing;
    Outgoing["chat_id"] = getChat_id();
    Outgoing["text"] = getText();
    if(getParse_mode()){
        Outgoing["parse_mode"] = getParse_mode().value();
    }
    if(getDisable_web_page_preview()){
        Outgoing["disable_web_page_preview"] = getDisable_web_page_preview().value();
    }
    if(getDisable_notification()){
        Outgoing["disable_notification"] = getDisable_notification().value();
    }
    if(getReply_to_message_id()){
        Outgoing["reply_to_message_id"] = getReply_to_message_id().value();
    }
    //Todo add keyboard

    return Outgoing;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sendMessage::setParse_mode(const std::optional<std::string> &parse_mode) {
    sendMessage::parse_mode = parse_mode;
}

void sendMessage::setDisable_web_page_preview(const std::optional<bool> &disable_web_page_preview) {
    sendMessage::disable_web_page_preview = disable_web_page_preview;
}

void sendMessage::setDisable_notification(const std::optional<bool> &disable_notification) {
    sendMessage::disable_notification = disable_notification;
}

void sendMessage::setReply_to_message_id(const std::optional<int> &reply_to_message_id) {
    sendMessage::reply_to_message_id = reply_to_message_id;
}

/**
 * Sets an ReplyKeyboardMarkup
 * @param RKM
 */
void sendMessage::setReplyMarkup(const ReplyKeyboardMarkup RKM){
    sendMessage::reply_markup = RKM;
}

/**
 * Sets an ReplyKeyboardRemove
 * @param RKR
 */
void sendMessage::setReplyMarkup(const ReplyKeyboardRemove RKR){
    sendMessage::reply_markup = RKR;
}

/**
 * Sets an ForceReply
 * @param FR
 */
void sendMessage::setReplyMarkup(const ForceReply FR){
    sendMessage::reply_markup = FR;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &sendMessage::getChat_id() const {
    return chat_id;
}

const string &sendMessage::getText() const {
    return text;
}

const optional<string> &sendMessage::getParse_mode() const {
    return parse_mode;
}

const optional<bool> &sendMessage::getDisable_web_page_preview() const {
    return disable_web_page_preview;
}

const optional<bool> &sendMessage::getDisable_notification() const {
    return disable_notification;
}

const optional<int> &sendMessage::getReply_to_message_id() const {
    return reply_to_message_id;
}

const optional<ReplyMarkup> &sendMessage::getReply_markup() const {
    return reply_markup;
}



