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
#include "exceptions/telegram_api_error.h"
#include "types/UserProfilePhotos.h"

using namespace std;

namespace yatbcpp {
/**
 * Returns A File based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return File Voice
 */
    template<> UserProfilePhotos fromJson(Json::Value Data) {
        if (!Data.isMember("total_count")) {
            throw essential_key_missing("UserProfilePhotos::total_count is missing");
        }

        if (!Data.isMember("photos")) {
            throw essential_key_missing("UserProfilePhotos::photos is missing");
        }

        int total_count = Data["total_count"].asInt();
        std::vector<std::vector<PhotoSize>> photos;
        //ok make sure that each photo maximal has 4 photosizes each
        for (int i = 0; i < Data["photos"].size(); i++) {
            std::vector<PhotoSize> photo;
            for (int j = 0; j < Data["photos"][i].size(); j++) {
                photo.push_back(fromJson<PhotoSize>(Data["photos"][i]));
            }
            if (photo.size() > 4) {
                throw telegram_api_error(0,"More than 4 photo sizes for a photo have been found, please check telegram api for changes");
                //Trow something like api error?
            }
            photos.push_back(photo);
        }

        UserProfilePhotos ret(total_count, photos);


        return ret;
    }
}
