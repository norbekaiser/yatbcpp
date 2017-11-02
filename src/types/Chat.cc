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
#include "types/Chat.h"


using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Chat::Chat(int id, chat_type type):
        id(id), type (type)
{

}

Chat::Chat(const Chat& chat):
        id(id), type (type)
{
    title = chat.title;
    username = chat.username;
    first_name = chat.first_name;
    last_name = chat.last_name;
    all_members_are_administrators = chat.all_members_are_administrators;
    description = chat.description;
    invite_link = chat.invite_link;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Chat::setTitle(const optional<string> &title) {
    Chat::title = title;
}

void Chat::setUsername(const optional<string> &username) {
    Chat::username = username;
}

void Chat::setFirst_name(const optional<string> &first_name) {
    Chat::first_name = first_name;
}

void Chat::setLast_name(const optional<string> &last_name) {
    Chat::last_name = last_name;
}

void Chat::setAll_members_are_administrators(const optional<bool> &all_members_are_administrators) {
    Chat::all_members_are_administrators = all_members_are_administrators;
}

void Chat::setDescription(const optional<string> &description) {
    Chat::description = description;
}

void Chat::setInvite_link(const optional<string> &invite_link) {
    Chat::invite_link = invite_link;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Chat::getId() const {
    return id;
}

chat_type Chat::getType() const {
    return type;
}

const optional<string> &Chat::getTitle() const {
    return title;
}

const optional<string> &Chat::getUsername() const {
    return username;
}

const optional<string> &Chat::getFirst_name() const {
    return first_name;
}

const optional<string> &Chat::getLast_name() const {
    return last_name;
}

const optional<bool> &Chat::getAll_members_are_administrators() const {
    return all_members_are_administrators;
}

const optional<string> &Chat::getDescription() const {
    return description;
}

const optional<string> &Chat::getInvite_link() const {
    return invite_link;
}
