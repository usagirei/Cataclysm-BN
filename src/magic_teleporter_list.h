#pragma once

#include <map>
#include <optional>
#include <set>
#include <string>

#include "coordinates.h"
#include "point.h"

class Character;
class JsonIn;
class JsonOut;

class teleporter_list
{
    private:
        // OMT locations of all known teleporters
        std::map<tripoint_abs_omt, std::string> known_teleporters;
        // ui for selection of desired teleport location.
        // returns overmap tripoint, or nullopt if canceled
        std::optional<tripoint_abs_omt> choose_teleport_location();
        // returns true if a teleport is successful
        // does not do any loading or unloading
        bool place_avatar_overmap( Character &you, const tripoint_abs_omt &omt_pt ) const;
    public:
        bool knows_translocator( const tripoint_abs_omt &omt_pos ) const;
        // adds teleporter to known_teleporters and does any other activation necessary
        bool activate_teleporter( const tripoint_abs_omt &omt_pt, const tripoint &local_pt );
        void deactivate_teleporter( const tripoint_abs_omt &omt_pt, const tripoint &local_pt );

        // calls the necessary functions to select translocator location
        // and teleports the target(s) there
        void translocate( const std::set<tripoint> &targets );

        void serialize( JsonOut &json ) const;
        void deserialize( JsonIn &jsin );
};


