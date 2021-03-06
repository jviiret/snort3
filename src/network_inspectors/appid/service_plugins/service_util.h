//--------------------------------------------------------------------------
// Copyright (C) 2014-2016 Cisco and/or its affiliates. All rights reserved.
// Copyright (C) 2005-2013 Sourcefire, Inc.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License Version 2 as published
// by the Free Software Foundation.  You may not use, modify or distribute
// this program under any other version of the GNU General Public License.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//--------------------------------------------------------------------------

// service_util.h author Sourcefire Inc.

#ifndef SERVICE_UTIL_H
#define SERVICE_UTIL_H

#include <mutex>

#include "main/snort_config.h"
#include "target_based/snort_protocols.h"

inline const uint8_t* service_strstr(const uint8_t* haystack, unsigned haystack_len,
    const uint8_t* needle, unsigned needle_len)
{
    const uint8_t* h_end = haystack + haystack_len;

    for (const uint8_t* p = haystack; h_end-p >= (int)needle_len; p++)
    {
        if (memcmp(p, needle, needle_len) == 0)
        {
            return p;
        }
    }
    return nullptr;
}

inline int16_t add_appid_protocol_reference(const char* protocol)
{
    static std::mutex apr_mutex;

    apr_mutex.lock();
    int16_t id = snort_conf->proto_ref->add(protocol);
    apr_mutex.unlock();
    return id;
}

#endif
