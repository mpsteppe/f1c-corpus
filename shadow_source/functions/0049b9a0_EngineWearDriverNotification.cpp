// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049B9A0
// Canonical corpus name: sub_49B9A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49B9A0_0049b9a0.c

void UnknownObject::EngineWearDriverNotification()
{
    // Detects first-time engine-wear conditions for the vehicle matching the current player. Compares the current player vehicle's per-driver value at offset 18580 with that of the current vehicle; when they match, the wear parameter exceeds a threshold, and wear mode is active, notifies the driver once via sub_41B190. Stores the resulting present flag per driver and returns it.
    // CALCULATION: read comparison value at vehicle offset 18580 from VehiclePtrArray slot indexed by current player index [global:0x007C54F0, global:0x007C54DC]
    // CALCULATION: build condition: value equals current-vehicle value AND dbl_7C9174 greater than dbl_7C9204 AND wear mode dword_7CEA5C nonzero [global:0x007C54E4, global:0x007C9174, global:0x007C9204, global:0x007CEA5C]
    // CALCULATION: compute vehicle pointer as vehicle array base plus 18624 times the vehicle index [global:0x005EC6D8]
    // GUARD: if driver present flag byte_5EC354 indexed by driver id at vehicle offset 18580 is unset and condition holds, proceed to notify [global:0x005EC354]
    // CALL: notify driver via sub_41B190 with the vehicle pointer [callee:0x0041B190]
    // ASSIGNMENT: store condition result into driver present flag byte_5EC354 [global:0x005EC354]
    // RETURN: return condition result [function:0x0049B9A0]

    // Conservative worker pseudocode:
    //   idx = playerIndex; v0 = vehPtrArr[idx]->offset18580;
    //   v1 = (v0 == vehPtrArr[vehIndex]->offset18580) && wearParam > wearThreshold && wearMode;
    //   veh = vehArrayBase + 18624 * v0;
    //   if (!presentFlag[veh->offset18580] && v1) sub_41B190(veh);
    //   presentFlag[veh->offset18580] = v1;
    //   return v1;
    // UNRESOLVED: exact meaning of the compared value at vehicle offset 18580 (driver id versus team id) is not established from this packet
    // UNRESOLVED: dword_5EB978 is listed in packet globals but absent from the raw source text; its role here is unknown
}
