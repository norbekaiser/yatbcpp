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
// Created by norbert on 23.08.17.
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
#include "types/Venue.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Venue::Venue(Location location, std::string title, std::string address) : location(location), title(title), address(address)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A Location based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Location Voice
 */
Venue Venue::fromJson(Json::Value Data) {
    if(!Data.isMember("location")){
        throw essential_key_missing("Venue::location is missing");
    }
    if(!Data.isMember("title")){
        throw essential_key_missing("Venue::title is missing");
    }
    if(!Data.isMember("address")){
            throw essential_key_missing("Venue::address is missing");
    }

    Location location = Location::fromJson(Data["location"]);
    string title = Data["title"].asString();
    string address = Data["address"].asString();

    Venue ret(location,title,address);

    if(Data.isMember("foursquare_id")){
        ret.setFoursquare_id(Data["foursquare_id"].asString());
    }

    return ret;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Venue::setFoursquare_id(const optional<string> &foursquare_id) {
    Venue::foursquare_id = foursquare_id;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const Location &Venue::getLocation() const {
    return location;
}

const string &Venue::getTitle() const {
    return title;
}

const string &Venue::getAddress() const {
    return address;
}

const optional<string> &Venue::getFoursquare_id() const {
    return foursquare_id;
}
