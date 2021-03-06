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
#include "types/ChatPhoto.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A ChatPhoto based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed ChatPhoto
     */
    template<> ChatPhoto fromJson(Json::Value Data) {
        if (!Data.isMember("small_file_id")) {
            throw essential_key_missing("ChatPhoto::small_file_id is missing");
        }
        if (!Data.isMember("big_file_id")) {
            throw essential_key_missing("ChatPhoto::big_file_id is missing");
        }

        std::string small_file_id = Data["file_id"].asString();
        std::string big_file_id = Data["file_id"].asString();

        ChatPhoto ret(small_file_id, big_file_id);

        return ret;
    }
}
