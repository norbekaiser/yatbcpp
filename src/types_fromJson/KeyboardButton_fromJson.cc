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
#include "types/KeyboardButton.h"

using namespace std;

namespace yatbcpp {

    /**
     * Returns A KeyboardButton based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return KeyboardButton
     */
    template<> KeyboardButton fromJson(Json::Value Data) {
        if (!Data.isMember("text")) {
            throw essential_key_missing("KeyboardButton::text is missing");
        }

        string text = Data["text"].asString();

        KeyboardButton ret(text);

        if (Data.isMember("request_contact")) {
            ret.setRequest_contact(Data["request_contact"].asBool());
        }
        if (Data.isMember("request_location")) {
            ret.setRequest_location(Data["request_location"].asBool());
        }

        return ret;
    }

}
