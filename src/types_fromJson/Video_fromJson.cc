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
#include <jsoncpp/json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/Video.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A Video based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed Video
     */
    template<> Video fromJson(Json::Value Data) {
        if (!Data.isMember("file_id")) {
            throw essential_key_missing("Video::file_id is missing");
        }
        if (!Data.isMember("width")) {
            throw essential_key_missing("Video::width is missing");
        }
        if (!Data.isMember("height")) {
            throw essential_key_missing("Video::height is missing");
        }
        if (!Data.isMember("duration")) {
            throw essential_key_missing("Video::duration is missing");
        }

        std::string file_id = Data["file_id"].asString();
        int width = Data["width"].asInt();
        int height = Data["height"].asInt();
        int duration = Data["duration"].asInt();

        Video ret(file_id, width, height, duration);

        if (Data.isMember("thumb")) {
            ret.setThumb(fromJson<PhotoSize>(Data["thumb"]));
        }
        if (Data.isMember("mime_type")) {
            ret.setMime_type(Data["mime_type"].asString());
        }
        if (Data.isMember("file_size")) {
            ret.setFile_size(Data["file_size"].asInt());
        }
        return ret;
    }
}
