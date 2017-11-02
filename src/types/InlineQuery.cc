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

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/InlineQuery.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

InlineQuery::InlineQuery(std::string id, User from, std::string query, std::string offset):
        id(id), from(from), query(query), offset(offset)
{

}

InlineQuery::InlineQuery(const InlineQuery& InlineQuery) :
        id(InlineQuery.id), from(InlineQuery.from), query(InlineQuery.query), offset(InlineQuery.offset)
{
    location = InlineQuery.location;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InlineQuery::setLocation(const optional<Location> &location) {
    InlineQuery::location = location;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &InlineQuery::getId() const {
    return id;
}

const User &InlineQuery::getFrom() const {
    return from;
}

const optional<Location> &InlineQuery::getLocation() const {
    return location;
}

const string &InlineQuery::getQuery() const {
    return query;
}

const string &InlineQuery::getOffset() const {
    return offset;
}


