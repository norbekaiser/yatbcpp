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
// Created by norbert on 26.08.17.
//

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <jsoncpp/json/json.h>
#include "exceptions/essential_key_missing.h"
#include "types/ReplyKeyboardMarkup.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ReplyKeyboardMarkup::ReplyKeyboardMarkup(std::vector<std::vector<KeyboardButton>> keyboard): keyboard(keyboard)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A KeyboardButton based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return KeyboardButton
 */
ReplyKeyboardMarkup ReplyKeyboardMarkup::fromJson(Json::Value Data) {
    std::vector<std::vector<KeyboardButton>> keyboardbuttons;
    for(int i=0;i<Data["photos"].size();i++){
        std::vector<KeyboardButton> keyboardbutton;
        for(int j=0;j<Data["photos"][i].size();j++){
            keyboardbutton.push_back(KeyboardButton::fromJson(Data["keyboard"][i]));
        }
        keyboardbuttons.push_back(keyboardbutton);
    }



    ReplyKeyboardMarkup ret(keyboardbuttons);

    if(Data.isMember("resize_keyboard")){
        ret.setResize_keyboard(Data["resize_keyboard"].asBool());
    }
    if(Data.isMember("one_time_keyboard")){
        ret.setOne_time_keyboard(Data["one_time_keyboard"].asBool());
    }
    if(Data.isMember("selective")){
        ret.setSelective(Data["selective"].asBool());
    }


    return ret;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ReplyKeyboardMarkup::setResize_keyboard(const optional<bool> &resize_keyboard) {
    ReplyKeyboardMarkup::resize_keyboard = resize_keyboard;
}

void ReplyKeyboardMarkup::setOne_time_keyboard(const optional<bool> &one_time_keyboard) {
    ReplyKeyboardMarkup::one_time_keyboard = one_time_keyboard;
}

void ReplyKeyboardMarkup::setSelective(const optional<bool> &selective) {
    ReplyKeyboardMarkup::selective = selective;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const vector<vector<KeyboardButton>> &ReplyKeyboardMarkup::getKeyboard() const {
    return keyboard;
}

const optional<bool> &ReplyKeyboardMarkup::getResize_keyboard() const {
    return resize_keyboard;
}

const optional<bool> &ReplyKeyboardMarkup::getOne_time_keyboard() const {
    return one_time_keyboard;
}

const optional<bool> &ReplyKeyboardMarkup::getSelective() const {
    return selective;
}
