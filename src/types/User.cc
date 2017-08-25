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
#include "types/User.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

User::User(int id, bool is_bot, string first_name) : id(id), is_bot(is_bot), first_name(first_name)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A User based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Parsed User
 */
User User::fromJson(Json::Value Data) {
    //Checking for essential fields, method somehow? check <"first_name">
    if(!Data.isMember("id")){
        throw essential_key_missing("User::id is missing");
    }
    if(!Data.isMember("is_bot")){
        throw essential_key_missing("User::is_bot is missing");
    }
    if(!Data.isMember("first_name")){
        throw essential_key_missing("User::first_name is missing");
    }
    //Extracting the essential information
    int id = Data["id"].asInt();
    bool is_bot = Data["is_bot"].asBool();
    string first_name = Data["first_name"].asString();
    //Creating the for return created object
    User ret(id,is_bot,first_name);
    //Adding Optional/Additional Information
    if( Data.isMember("last_name")  ){
        ret.setLast_name(Data["last_name"].asString());
    }
    if( Data.isMember("username")   ){
        ret.setUsername(Data["username"].asString());
    }
    if( Data.isMember("language_code")  ){
        ret.setLanguage_code(Data["language_code"].asString());
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void User::setLast_name(const optional<string> &last_name) {
    User::last_name = last_name;
}

void User::setUsername(const optional<string> &username) {
    User::username = username;
}

void User::setLanguage_code(const optional<string> &language_code) {
    User::language_code = language_code;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int User::getId() const {
    return id;
}

const string &User::getFirst_name() const {
    return first_name;
}

const optional<string> &User::getLast_name() const {
    return last_name;
}

const optional<string> &User::getUsername() const {
    return username;
}

const optional<string> &User::getLanguage_code() const {
    return language_code;
}



