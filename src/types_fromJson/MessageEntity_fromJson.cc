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
#include "types/MessageEntity.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A MessageEntity based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed MessageEntity
     */
    template<> MessageEntity fromJson(Json::Value Data) {
        if (!Data.isMember("type")) {
            throw essential_key_missing("MessageEntity::type is missing");
        }
        if (!Data.isMember("offset")) {
            throw essential_key_missing("MessageEntity::offset is missing");
        }
        if (!Data.isMember("length")) {
            throw essential_key_missing("MessageEntity::length is missing");
        }

        std::string type = Data["type"].asString();
        std::int32_t offset = Data["offset"].asInt();
        std::int32_t length = Data["length"].asInt();

        MessageEntity ret(type, offset, length);

        if (Data.isMember("url")) {
            ret.setUrl(Data["url"].asString());
        }
        if (Data.isMember("user")) {
            ret.setUser(yatbcpp::fromJson<User>(Data["user"]));
        }
        return ret;
    }
}
