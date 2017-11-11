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
#include <string>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/chatmember_status.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A chatmember_status based on a STL string
     * @param Data   a String Containing the nescesary data
     * @return Parsed chatmember_status
     */
    template<> chatmember_status fromString(string Data) {
        if(Data.compare("creator")==0){
            return chatmember_status::creator;
        }
        else if(Data.compare("administrator")==0){
            return chatmember_status::administrator;
        }
        else if(Data.compare("member")==0){
            return chatmember_status::member;
        }
        else if(Data.compare("restricted")==0){
            return chatmember_status::restricted;
        }
        else if(Data.compare("left")==0){
            return chatmember_status::left;
        }
        else if(Data.compare("kicked")==0){
            return chatmember_status::kicked;
        }
        else{
            throw essential_key_missing("chatmember_status parsable key is not known how to be parsed to");
        }
    }
    
}
