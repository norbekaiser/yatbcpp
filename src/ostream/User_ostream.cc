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
// Created by norbert on 19.08.17.
//
#include <string>
#include <ostream>
#include <types/User.h>

namespace yatbcpp{
    std::ostream& operator<< (std::ostream& o,const yatbcpp::User& U){
        using namespace std;
//         o << " User::id "            << U.id;
//         o << " User::first_name "    << U.first_name;
//        o << " User::last_name "     << U.last_name;
//        o << " User::username "      << U.username;
//        o << " User::language_code " << U.language_code;
        o << to_string(U.getId());
        if(U.IsBot()){
            o << " [BOT]";
        }
        else{
            o << " [User]";
        }
        o << " ( ";
        o << U.getFirst_name();
        o << " " << U.getUsername().value_or("[NoUsername]");
        o << " " << U.getLast_name().value_or("[NoLastname]");
        o << " " << U.getLanguage_code().value_or("");
        o << " )";
        return o;
    }
}
