/* Copyright (C) 2019 Mr Goldberg
   This file is part of the Goldberg Emulator

   The Goldberg Emulator is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 3 of the License, or (at your option) any later version.

   The Goldberg Emulator is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the Goldberg Emulator; if not, see
   <http://www.gnu.org/licenses/>.  */

#include "settings.h"

#ifndef SETTINGS_PARSER_INCLUDE
#define SETTINGS_PARSER_INCLUDE

//returns game appid
uint32 create_localstorage_settings(Settings **settings_client_out, Settings **settings_server_out, Local_Storage **local_storage_out);
void save_global_settings(class Local_Storage *local_storage, const char *name, const char *language);

bool settings_disable_lan_only();

enum class SettingsItf {
   CLIENT,
   GAMESERVER_STATS,
   GAMESERVER,
   MATCHMAKING_SERVERS,
   MATCHMAKING,
   USER,
   FRIENDS,
   UTILS,
   USER_STATS,
   APPS,
   NETWORKING,
   REMOTE_STORAGE,
   SCREENSHOTS,
   HTTP,
   UNIFIED_MESSAGES,
   CONTROLLER,
   UGC,
   APPLIST,
   MUSIC,
   MUSIC_REMOTE,
   HTML_SURFACE,
   INVENTORY,
   VIDEO,
   MASTERSERVER_UPDATER,
};

const std::map<SettingsItf, std::string>& settings_old_interfaces();

#endif
