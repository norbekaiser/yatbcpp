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
//
// Created by norbert on 18.08.17.
//

#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <jsoncpp/json/json.h>
#include "exceptions/essential_key_missing.h"
#include "types/telegram_type.h"
#include "types/Update.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Update::Update(int update_id) : update_id(update_id)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Update::setMessage(const optional<Message> &message) {
    Update::message = message;
}

void Update::setEdited_message(const optional<Message> &edited_message) {
    Update::edited_message = edited_message;
}

void Update::setChannel_post(const optional<Message> &channel_post) {
    Update::channel_post = channel_post;
}

void Update::setEdited_channel_post(const optional<Message> &edited_channel_post) {
    Update::edited_channel_post = edited_channel_post;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Update::getUpdate_id() const {
    return update_id;
}

const optional<Message> &Update::getMessage() const {
    return message;
}

const optional<Message> &Update::getEdited_message() const {
    return edited_message;
}

const optional<Message> &Update::getChannel_post() const {
    return channel_post;
}

const optional<Message> &Update::getEdited_channel_post() const {
    return edited_channel_post;
}
