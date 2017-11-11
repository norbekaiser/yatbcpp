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
#include "types/chat_type.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A chat_type based on a STL string
     * @param Data   a String Containing the nescesary data
     * @return Parsed chat_type
     */
    template<> chat_type fromString(string Data) {
        if(Data.compare("private")==0){
            return chat_type::Private;
        }
        else if(Data.compare("group")==0){
            return chat_type::Group;
        }
        else if(Data.compare("supergroup")==0){
            return chat_type::Supergroup;
        }
        else if(Data.compare("channel")==0){
            return chat_type::Channel;
        }
        else{
            throw essential_key_missing("chat_type parsable key is not known how to be parsed to");
        }
    }
    
}
