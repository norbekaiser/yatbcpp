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
#include <jsoncpp/json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/InlineQuery.h"
namespace yatbcpp {

    /**
     * Returns An InlineQuery based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed InlineQuery
     */
    template<>
    InlineQuery fromJson(Json::Value Data) {
        if(!Data.isMember("id")) {
            throw essential_key_missing("Audio::id is missing");
        }
        if(!Data.isMember("from")) {
            throw essential_key_missing("Audio::from is missing");
        }
        if(!Data.isMember("from")) {
            throw essential_key_missing("Audio::from is missing");
        }

        std::string id = Data["id"].asString();
        User from = fromJson<User>(Data["from"]);
        std::string query = Data["query"].asString();
        std::string offset = Data["offset"].asString();

        InlineQuery ret(id, from, query,offset);

        if(Data.isMember("location")){
            ret.setLocation(fromJson<Location>(Data["location"]));
        }


        return ret;
   }
}
