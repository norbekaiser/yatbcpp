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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <jsoncpp/json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/Chat.h"

namespace yatbcpp{

    /**
    * Returns A Chat based on a Json Object
    * @param Data   a Json Object Containing the necessary and Optional Fields
    * @return Parsed Chat
    */
    template <> Chat fromJson(Json::Value Data) {
        if(!Data.isMember("id")){
            throw essential_key_missing("Chat::id is missing");
        }
        if(!Data.isMember("type")){
            throw essential_key_missing("Chat::type is missing");
        }

        int id = Data["id"].asInt();
        std::string s_chatType = Data["type"].asString();
        chat_type chatType;
        if(s_chatType[0]=='P'){
            chatType = chat_type::Private;
        }
        else if(s_chatType[0]=='G'){
            chatType = chat_type::Group;
        }
        else if(s_chatType[0]=='S'){
            chatType = chat_type::Supergroup;
        }
        else if(s_chatType[0]=='C'){
            chatType = chat_type::Channel;
        }

        Chat ret(id,chatType);
        //additional information//add fast option so additional data is ignored sometimes?
        if(Data.isMember("title")){
            ret.setTitle(Data["title"].asString());
        }
        if(Data.isMember("username")){
            ret.setUsername(Data["username"].asString());
        }
        if(Data.isMember("first_name")){
            ret.setFirst_name(Data["first_name"].asString());
        }
        if(Data.isMember("last_name")){
            ret.setLast_name(Data["last_name"].asString());
        }
        if(Data.isMember("all_members_are_administrators")){
            ret.setAll_members_are_administrators(Data["all_members_are_administrators"].asBool());
        }
        if(Data.isMember("description")){
            ret.setDescription(Data["description"].asString());
        }
        if(Data.isMember("invite_link")){
            ret.setInvite_link(Data["description"].asString());
        }
        return ret;
    }
}
