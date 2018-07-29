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
#include "types/PhotoSize.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A PhotoSize based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed PhotoSize
     */
    template<> PhotoSize fromJson(Json::Value Data) {
        if (!Data.isMember("file_id")) {
            throw essential_key_missing("PhotoSize::file_id is missing");
        }
        if (!Data.isMember("width")) {
            throw essential_key_missing("PhotoSize::width is missing");
        }
        if (!Data.isMember("height")) {
            throw essential_key_missing("PhotoSize::height is missing");
        }

        std::string file_id = Data["file_id"].asString();
        std::int32_t width = Data["width"].asInt();
        std::int32_t height = Data["height"].asInt();

        PhotoSize ret(file_id, width, height);

        if (Data.isMember("file_size")) {
            ret.setFile_size(Data["file_size"].asInt());
        }
        return ret;
    }
}
