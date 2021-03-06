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
#ifndef YATBCPP_CHATMEMBER_H
#define YATBCPP_CHATMEMBER_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "chatmember_status.h"
#include "User.h"

namespace yatbcpp{
    /** See also https://core.telegram.org/bots/api#chatmember */
    class ChatMember {
    public:
        ChatMember(User user,chatmember_status status);
        
        ChatMember(const ChatMember& ChatMember);

        void setUntil_date(const std::optional<std::int32_t> &until_date);

        void setCan_be_edited(const std::optional<bool> &can_be_edited);

        void setCan_change_info(const std::optional<bool> &can_change_info);

        void setCan_post_messages(const std::optional<bool> &can_post_messages);

        void setCan_edit_messages(const std::optional<bool> &can_edit_messages);

        void setCan_delete_messages(const std::optional<bool> &can_delete_messages);

        void setCan_invite_users(const std::optional<bool> &can_invite_users);

        void setCan_restrict_members(const std::optional<bool> &can_restrict_members);

        void setCan_pin_messages(const std::optional<bool> &can_pin_messages);

        void setCan_promote_members(const std::optional<bool> &can_promote_members);

        void setCan_send_messages(const std::optional<bool> &can_send_messages);

        void setCan_send_media_messages(const std::optional<bool> &can_send_media_messages);

        void setCan_send_other_messages(const std::optional<bool> &can_send_other_messages);

        void setCan_add_web_page_previews(const std::optional<bool> &can_add_web_page_previews);

        const User &getUser() const;

        const chatmember_status &getStatus() const;

        const std::optional<std::int32_t> &getUntil_date() const;

        const std::optional<bool> &getCan_be_edited() const;

        const std::optional<bool> &getCan_change_info() const;

        const std::optional<bool> &getCan_post_messages() const;

        const std::optional<bool> &getCan_edit_messages() const;

        const std::optional<bool> &getCan_delete_messages() const;

        const std::optional<bool> &getCan_invite_users() const;

        const std::optional<bool> &getCan_restrict_members() const;

        const std::optional<bool> &getCan_pin_messages() const;

        const std::optional<bool> &getCan_promote_members() const;

        const std::optional<bool> &getCan_send_messages() const;

        const std::optional<bool> &getCan_send_media_messages() const;

        const std::optional<bool> &getCan_send_other_messages() const;

        const std::optional<bool> &getCan_add_web_page_previews() const;

    private:
        User user;
        chatmember_status status;//creator,administrator,member,restricted,left,kicked
        std::optional<std::int32_t> until_date;//2038 might be a problem one day
        std::optional<bool> can_be_edited;
        std::optional<bool> can_change_info;
        std::optional<bool> can_post_messages;
        std::optional<bool> can_edit_messages;
        std::optional<bool> can_delete_messages;
        std::optional<bool> can_invite_users;
        std::optional<bool> can_restrict_members;
        std::optional<bool> can_pin_messages;
        std::optional<bool> can_promote_members;
        std::optional<bool> can_send_messages;
        std::optional<bool> can_send_media_messages;
        std::optional<bool> can_send_other_messages;
        std::optional<bool> can_add_web_page_previews;
    };

}


#endif //YATBCPP_CHATMEMBER_H
