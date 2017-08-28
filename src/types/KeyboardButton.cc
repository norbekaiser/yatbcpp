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
#include "types/telegram_type.h"
#include "types/KeyboardButton.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

KeyboardButton::KeyboardButton(std::string text) : text(text)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void KeyboardButton::setRequest_contact(const optional<bool> &request_contact) {
    KeyboardButton::request_contact = request_contact;
}

void KeyboardButton::setRequest_location(const optional<bool> &request_location) {
    KeyboardButton::request_location = request_location;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &KeyboardButton::getText() const {
    return text;
}

const optional<bool> &KeyboardButton::getRequest_contact() const {
    return request_contact;
}

const optional<bool> &KeyboardButton::getRequest_location() const {
    return request_location;
}
