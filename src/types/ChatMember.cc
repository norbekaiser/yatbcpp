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
#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/User.h"
#include "types/ChatMember.h"


using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ChatMember::ChatMember(User user, chatmember_status status):
        user(user), status(status)
{

}

ChatMember::ChatMember(const ChatMember& ChatMember):
        user(ChatMember.user), status(ChatMember.status)

{
        until_date = ChatMember.until_date;
        can_be_edited = ChatMember.can_be_edited;
        can_change_info = ChatMember.can_change_info;
        can_post_messages = ChatMember.can_post_messages;
        can_edit_messages = ChatMember.can_edit_messages;
        can_delete_messages = ChatMember.can_delete_messages;
        can_invite_users = ChatMember.can_invite_users;
        can_restrict_members = ChatMember.can_restrict_members;
        can_pin_messages = ChatMember.can_pin_messages;
        can_promote_members = ChatMember.can_promote_members;
        can_send_messages = ChatMember.can_send_messages;
        can_send_media_messages = ChatMember.can_send_media_messages;
        can_send_other_messages = ChatMember.can_send_other_messages;
        can_add_web_page_previews = ChatMember.can_add_web_page_previews;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ChatMember::setUntil_date(const optional<int32_t> &until_date) {
    ChatMember::until_date = until_date;
}

void ChatMember::setCan_be_edited(const optional<bool> &can_be_edited) {
    ChatMember::can_be_edited = can_be_edited;
}

void ChatMember::setCan_change_info(const optional<bool> &can_change_info) {
    ChatMember::can_change_info = can_change_info;
}

void ChatMember::setCan_post_messages(const optional<bool> &can_post_messages) {
    ChatMember::can_post_messages = can_post_messages;
}

void ChatMember::setCan_edit_messages(const optional<bool> &can_edit_messages) {
    ChatMember::can_edit_messages = can_edit_messages;
}

void ChatMember::setCan_delete_messages(const optional<bool> &can_delete_messages) {
    ChatMember::can_delete_messages = can_delete_messages;
}

void ChatMember::setCan_invite_users(const optional<bool> &can_invite_users) {
    ChatMember::can_invite_users = can_invite_users;
}

void ChatMember::setCan_restrict_members(const optional<bool> &can_restrict_members) {
    ChatMember::can_restrict_members = can_restrict_members;
}

void ChatMember::setCan_pin_messages(const optional<bool> &can_pin_messages) {
    ChatMember::can_pin_messages = can_pin_messages;
}

void ChatMember::setCan_promote_members(const optional<bool> &can_promote_members) {
    ChatMember::can_promote_members = can_promote_members;
}

void ChatMember::setCan_send_messages(const optional<bool> &can_send_messages) {
    ChatMember::can_send_messages = can_send_messages;
}

void ChatMember::setCan_send_media_messages(const optional<bool> &can_send_media_messages) {
    ChatMember::can_send_media_messages = can_send_media_messages;
}

void ChatMember::setCan_send_other_messages(const optional<bool> &can_send_other_messages) {
    ChatMember::can_send_other_messages = can_send_other_messages;
}

void ChatMember::setCan_add_web_page_previews(const optional<bool> &can_add_web_page_previews) {
    ChatMember::can_add_web_page_previews = can_add_web_page_previews;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const User &ChatMember::getUser() const {
    return user;
}

const chatmember_status &ChatMember::getStatus() const {
    return status;
}

const optional<int32_t> &ChatMember::getUntil_date() const {
    return until_date;
}

const optional<bool> &ChatMember::getCan_be_edited() const {
    return can_be_edited;
}

const optional<bool> &ChatMember::getCan_change_info() const {
    return can_change_info;
}

const optional<bool> &ChatMember::getCan_post_messages() const {
    return can_post_messages;
}

const optional<bool> &ChatMember::getCan_edit_messages() const {
    return can_edit_messages;
}

const optional<bool> &ChatMember::getCan_delete_messages() const {
    return can_delete_messages;
}

const optional<bool> &ChatMember::getCan_invite_users() const {
    return can_invite_users;
}

const optional<bool> &ChatMember::getCan_restrict_members() const {
    return can_restrict_members;
}

const optional<bool> &ChatMember::getCan_pin_messages() const {
    return can_pin_messages;
}

const optional<bool> &ChatMember::getCan_promote_members() const {
    return can_promote_members;
}

const optional<bool> &ChatMember::getCan_send_messages() const {
    return can_send_messages;
}

const optional<bool> &ChatMember::getCan_send_media_messages() const {
    return can_send_media_messages;
}

const optional<bool> &ChatMember::getCan_send_other_messages() const {
    return can_send_other_messages;
}

const optional<bool> &ChatMember::getCan_add_web_page_previews() const {
    return can_add_web_page_previews;
}

