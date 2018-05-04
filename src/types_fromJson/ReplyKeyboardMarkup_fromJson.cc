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
#include "types/ReplyKeyboardMarkup.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A KeyboardButton based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return KeyboardButton
     */
    template<> ReplyKeyboardMarkup fromJson(Json::Value Data) {
        std::vector<std::vector<KeyboardButton>> keyboardbuttons;
        for (int i = 0; i < Data["photos"].size(); i++) {
            std::vector<KeyboardButton> keyboardbutton;
            for (int j = 0; j < Data["photos"][i].size(); j++) {
                keyboardbutton.push_back(fromJson<KeyboardButton>(Data["keyboard"][i]));
            }
            keyboardbuttons.push_back(keyboardbutton);
        }


        ReplyKeyboardMarkup ret(keyboardbuttons);

        if (Data.isMember("resize_keyboard")) {
            ret.setResize_keyboard(Data["resize_keyboard"].asBool());
        }
        if (Data.isMember("one_time_keyboard")) {
            ret.setOne_time_keyboard(Data["one_time_keyboard"].asBool());
        }
        if (Data.isMember("selective")) {
            ret.setSelective(Data["selective"].asBool());
        }


        return ret;
    }
}

