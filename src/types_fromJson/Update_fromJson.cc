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
#include "types/Update.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns An Update based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed Update
     */
    template<> Update fromJson(Json::Value Data) {
        //Checking for essential fields
        if (!Data.isMember("update_id")) {
            throw essential_key_missing("Update::update_id is missing");
        }
        //Extracting the essential information
        std::int32_t update_id = Data["update_id"].asInt();
        //Creating the for return created object
        Update ret(update_id);
        //Adding Optional/Additional Information
        if (Data.isMember("message")) {
            Message M = fromJson<Message>(Data["message"]);
            ret.setMessage(M);
        }
        if (Data.isMember("edited_message")) {
            Message M = fromJson<Message>(Data["edited_message"]);
            ret.setEdited_message(M);
        }
        if (Data.isMember("channel_post")) {
            Message M = fromJson<Message>(Data["channel_post"]);
            ret.setChannel_post(M);
        }
        if (Data.isMember("edited_channel_post")) {
            Message M = fromJson<Message>(Data["edited_channel_post"]);
            ret.setEdited_channel_post(M);
        }
        if (Data.isMember("inline_query")) {
            InlineQuery I= fromJson<InlineQuery>(Data["inline_query"]);
            ret.setInlineQuery(I);
        }


        return ret;
    }
}
