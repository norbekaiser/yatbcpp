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
#include "methods/sendLocation.h"

using namespace std;
using namespace yatbcpp;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sendLocation::sendLocation(Chat C,Location location) :
        telegram_methodJSON("sendLocation"),
        chat_id(to_string(C.getId())), latitude(location.getLatitude()), longitude(location.getLongitude())
{
    
}

sendLocation::sendLocation(int64_t chat_id,Location location) :
        telegram_methodJSON("sendLocation"),
        chat_id(to_string(chat_id)), latitude(location.getLatitude()), longitude(location.getLongitude())
{
    
}

sendLocation::sendLocation(string chat_id,Location location) :
        telegram_methodJSON("sendLocation"),
        chat_id(move(chat_id)), latitude(location.getLatitude()), longitude(location.getLongitude())
{
    
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Outgoing Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Json::Value sendLocation::toJson() {
    Json::Value Outgoing;
    Outgoing["chat_id"] = getChat_id();
    Outgoing["latitude"] = getLatitude();
    Outgoing["longitude"] = getLongitude();

    if(getLivePeriod()){
        Outgoing["live_period"] = getLivePeriod().value();
    }
    if(getDisable_notification()){
        Outgoing["disable_notification"] = getDisable_notification().value();
    }
    if(getReply_to_message_id()){
        Outgoing["reply_to_message_id"] = getReply_to_message_id().value();
    }

    return Outgoing;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void sendLocation::setLive_period(const optional<unsigned int> &live_period) {
    sendLocation::live_period = live_period;
}

void sendLocation::setDisable_notification(const optional<bool> &disable_notification) {
    sendLocation::disable_notification = disable_notification;
}

void sendLocation::setReply_to_message_id(const optional<int32_t> &reply_to_message_id) {
    sendLocation::reply_to_message_id = reply_to_message_id;
}


/**
 * Sets an ReplyKeyboardMarkup
 * @param RKM
 */
void sendLocation::setReplyMarkup(const ReplyKeyboardMarkup RKM){
    sendLocation::reply_markup = RKM;
}

/**
 * Sets an ReplyKeyboardRemove
 * @param RKR
 */
void sendLocation::setReplyMarkup(const ReplyKeyboardRemove RKR){
    sendLocation::reply_markup = RKR;
}

/**
 * Sets an ForceReply
 * @param FR
 */
void sendLocation::setReplyMarkup(const ForceReply FR){
    sendLocation::reply_markup = FR;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &sendLocation::getChat_id() const {
    return chat_id;
}

const float &sendLocation::getLatitude() const {
    return latitude;
}

const float &sendLocation::getLongitude() const {
    return longitude;
}

const optional<unsigned int> &sendLocation::getLivePeriod() const {
    return live_period;
}

const optional<bool> &sendLocation::getDisable_notification() const {
    return disable_notification;
}

const optional<int32_t> &sendLocation::getReply_to_message_id() const {
    return reply_to_message_id;
}

const optional<ReplyMarkup> &sendLocation::getReply_markup() const {
    return reply_markup;
}
