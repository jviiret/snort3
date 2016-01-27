//--------------------------------------------------------------------------
// Copyright (C) 2015-2016 Cisco and/or its affiliates. All rights reserved.
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

// host_module.h author Steve Chew <stechew@cisco.com>

#ifndef HOST_MODULE_H
#define HOST_MODULE_H

//  Loads host configuration data.

//  FIXIT-M - Temporarily create new HostTracker module to test new
//            HostTracker object.  May eventually replace old Hosts
//            module with this one.

#include "framework/module.h"
#include "host_tracker/host_tracker.h"
#include <assert.h>

#define host_tracker_help \
    "configure hosts"

class HostTrackerModule : public Module
{
public:
    HostTrackerModule() : Module("host_tracker", host_tracker_help, host_tracker_params, true)
    {
        host = nullptr;
    }

    ~HostTrackerModule()
    {
        assert(!host);
    }

    bool set(const char*, Value&, SnortConfig*) override;
    bool begin(const char*, int, SnortConfig*) override;
    bool end(const char*, int, SnortConfig*) override;

private:
    static const Parameter host_tracker_params[];
    static const Parameter service_params[];

    HostApplicationEntry app;
    HostTracker* host;
};

#endif

