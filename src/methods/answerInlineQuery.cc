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
#include <jsoncpp/json/json.h>
#include <iostream>
#include "methods/answerInlineQuery.h"

using namespace yatbcpp;
using namespace std;

answerInlineQuery::answerInlineQuery(string inline_query_id,vector<shared_ptr<InlineQueryResult>> results) :
        telegram_simplemethodJSON("answerInlineQuery"),
        inline_query_id(move(inline_query_id)), results(move(results))
{

}
answerInlineQuery::answerInlineQuery(string inline_query_id) :
        telegram_simplemethodJSON("answerInlineQuery"),
        inline_query_id(move(inline_query_id))
{

}

Json::Value answerInlineQuery::toJson(){
    Json::Value Outgoing;
    Outgoing["inline_query_id"] = getInline_query_id();
    for(int i=0;i<results.size();i++){
        std::cout << "DEBUG:: RESULT" << std::endl;
        Outgoing["results"][i] = results[i]->toJson();
    }
    if(cache_time){
        Outgoing["cache_time"] = cache_time.value();
    }
    if(is_personal){
        Outgoing["is_personal"] = is_personal.value();
    }
    if(next_offset){
        Outgoing["next_offset"] = next_offset.value();
    }
    if(switch_pm_text){
            Outgoing["switch_pm_text"] = switch_pm_text.value();
    }
    if(switch_pm_parameter){
            Outgoing["switch_pm_parameter"] = switch_pm_parameter.value();
    }
    return Outgoing;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Adds an Inline Query Result to the Results, however only 50 can be handled?
 * todo maybe separate or add page support?, todo maybe add pass by reference instead of by ptr?
 * current state is a smart ptr
 * @param IQR
 */
void answerInlineQuery::addInlineQueryResult(shared_ptr<InlineQueryResult>IQR) {
    this->results.push_back(move(IQR));
}

void answerInlineQuery::setCache_time(const optional<std::int32_t> &cache_time) {
    answerInlineQuery::cache_time = cache_time;
}

void answerInlineQuery::setIs_personal(const optional<bool> &is_personal) {
    answerInlineQuery::is_personal = is_personal;
}

void answerInlineQuery::setNext_offset(const optional<string> &next_offset) {
    answerInlineQuery::next_offset = next_offset;
}

void answerInlineQuery::setSwitch_pm_text(const optional<string> &switch_pm_text) {
    answerInlineQuery::switch_pm_text = switch_pm_text;
}

void answerInlineQuery::setSwitch_pm_parameter(const optional<string> &switch_pm_parameter) {
    answerInlineQuery::switch_pm_parameter = switch_pm_parameter;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &answerInlineQuery::getInline_query_id() const {
    return inline_query_id;
}

//tood return of vector?, add?

const optional<std::int32_t> &answerInlineQuery::getCache_time() const {
    return cache_time;
}

const optional<bool> &answerInlineQuery::getIs_personal() const {
    return is_personal;
}

const optional<string> &answerInlineQuery::getNext_offset() const {
    return next_offset;
}

const optional<string> &answerInlineQuery::getSwitch_pm_text() const {
    return switch_pm_text;
}

const optional<string> &answerInlineQuery::getSwitch_pm_parameter() const {
    return switch_pm_parameter;
}



