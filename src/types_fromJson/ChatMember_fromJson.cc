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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <jsoncpp/json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/ChatMember.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A ChatMember based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed ChatMember
     */
    template<> ChatMember fromJson(Json::Value Data) {
        if (!Data.isMember("user")) {
            throw essential_key_missing("ChatMember::user is missing");
        }
        if (!Data.isMember("status")) {
            throw essential_key_missing("ChatMember::status is missing");
        }

        //    yatbcpp<User>::fromJson()
        User user = yatbcpp::fromJson<User>(Data["user"]);
        //string status = Data["status"].asString();
        chatmember_status status = yatbcpp::fromString<chatmember_status>(Data["status"].asString());
        
        ChatMember ret(user, status);

        if (Data.isMember("until_date")) {
            ret.setUntil_date(Data["until_date"].asInt());
        }
        if (Data.isMember("can_be_edited")) {
            ret.setCan_be_edited(Data["can_be_edited"].asBool());
        }
        if (Data.isMember("can_change_info")) {
            ret.setCan_change_info(Data["can_change_info"].asBool());
        }
        if (Data.isMember("can_post_messages")) {
            ret.setCan_post_messages(Data["can_post_messages"].asBool());
        }
        if (Data.isMember("can_edit_messages")) {
            ret.setCan_edit_messages(Data["can_edit_messages"].asBool());
        }
        if (Data.isMember("can_delete_messages")) {
            ret.setCan_delete_messages(Data["can_delete_messages"].asBool());
        }
        if (Data.isMember("can_invite_users")) {
            ret.setCan_invite_users(Data["can_invite_users"].asBool());
        }
        if (Data.isMember("can_restrict_members")) {
            ret.setCan_restrict_members(Data["can_restrict_members"].asBool());
        }
        if (Data.isMember("can_pin_messages")) {
            ret.setCan_pin_messages(Data["can_pin_messages"].asBool());
        }
        if (Data.isMember("can_promote_members")) {
            ret.setCan_promote_members(Data["can_promote_members"].asBool());
        }
        if (Data.isMember("can_send_messages")) {
            ret.setCan_send_messages(Data["can_send_messages"].asBool());
        }
        if (Data.isMember("can_send_media_messages")) {
            ret.setCan_send_media_messages(Data["can_send_media_messages"].asBool());
        }
        if (Data.isMember("can_send_other_messages")) {
            ret.setCan_send_other_messages(Data["can_send_other_messages"].asBool());
        }
        if (Data.isMember("can_add_web_page_previews")) {
            ret.setCan_add_web_page_previews(Data["can_add_web_page_previews"].asBool());
        }
        return ret;
    }
}
