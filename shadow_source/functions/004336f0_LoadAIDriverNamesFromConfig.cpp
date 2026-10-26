// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004336F0
// Canonical corpus name: LoadAIDriverNamesFromConfig
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LoadAIDriverNamesFromConfig_004336f0.c

void UnknownObject::LoadAIDriverNamesFromConfig()
{
    // Loads AI driver names and settings for a range of vehicles from the auto-load config. Computes a vehicle index range from the a2 argument and the VehicleCount global dword_5C329C: a2 inside [0, count) selects only slot a2, otherwise all slots are processed. Iterates the vehicle pointer array dword_7C54F0; vehicles that already have AI settings (dword at +13000 non-zero) just get the resolved AI settings path copied into +18324. The first vehicle lacking settings breaks out and is loaded: the auto-load config path byte_7CE498 is set up via sub_432DF0, the file existence is checked, the vehicle is looked up by name (field this:0x10), and either its name is removed from the linked list or, after a default string copy, the driver name (field this:0x0, or byte_5EA438 default) is copied into the vehicle struct and validated via ValidateVehicleConfigurationFile.
    // CALCULATION: Compute the vehicle index range: if a2 is outside [0, dword_5C329C), start at 0 and process all vehicles up to the count; otherwise process only slot a2 (end index a2 + 1). [source:raw, global:0x005C329C]
    // CALL: Call AISettingsFileResolver(v16, 128) to resolve the default AI settings file path into buffer v16. [source:raw, callee:0x00433890]
    // LOOP: Iterate vehicle indices in [start, end); each iteration dereferences the vehicle pointer array dword_7C54F0[index] into v7. [source:raw, global:0x007C54F0]
    // GUARD: If the vehicle's dword at +13000 is non-zero it already has AI settings: copy the resolved settings path into +18324 (sub_587DD0, max 255) and zero the byte at +18579, then advance to the next vehicle. [source:raw, callee:0x00587DD0]
    // GUARD: The first vehicle whose +13000 dword is zero breaks out of the skip loop and is loaded below. [source:raw]
    // CALL: Call sub_432DF0(this, &byte_7CE498) to set up the auto-load config file path from the byte_7CE498 global. [source:raw, callee:0x00432DF0, global:0x007CE498]
    // CALCULATION: File path fallback: use *this (field this:0x0) or the byte_5EA438 default path when null, then call FileAttributesExistenceCheck on it. [source:raw, callee:0x00568540, field:this:0x00000000, global:0x005EA438]
    // CALL: Call LookUpVehicleConfigEntry(v17, 128) to look up the current vehicle by its name string (field this:0x10). [source:raw, callee:0x004339E0, field:this:0x00000010]
    // STATE_TRANSITION: When the lookup does not find an entry: copy the resolved entry v17 with StringCopyWithBufferRealloc, then let sub_568B00 decide between the validation path and the linked-list removal path. [source:raw, callee:0x00566650, callee:0x00568B00]
    // CALL: On the removal path: call LinkedListRemovalByName on the vehicle name (field this:0x10), then StringCopyWithBufferRealloc(&byte_5EA438) to prepare the default string before validation. [source:raw, callee:0x00433D60, field:this:0x00000010, global:0x005EA438]
    // ASSIGNMENT: LABEL_16: copy the vehicle name *v9 (field this:0x10, or byte_5EA438 when null) with StringCopyWithBufferRealloc; copy the driver name *this (field this:0x0, or byte_5EA438 when null) into vehicle +18324 via sub_587DD0 (max 255) and zero the byte at +18579. [source:raw, callee:0x00566650, callee:0x00587DD0, field:this:0x00000010, field:this:0x00000000, global:0x005EA438]
    // CALL: Call ValidateVehicleConfigurationFile(*this, 0) to validate the driver's configuration file. [source:raw, callee:0x00433ED0, field:this:0x00000000]
    // LOOP: Resume the iteration from the saved index v15; return the end index when the range is exhausted. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4336F0(const char **this, int slot) {
    //     int start = 0, end = dword_5C329C;
    //     if (slot >= 0 && slot < dword_5C329C) { start = slot; end = slot + 1; }
    //     char settingsPath[128];
    //     AISettingsFileResolver(settingsPath, 128);
    //     int i = start;
    //     while (i < end) {
    //       char *veh = dword_7C54F0[i];
    //       if (*(int*)(veh + 13000) == 0) break;
    //       sub_587DD0(veh + 18324, settingsPath, 255);
    //       *(char*)(veh + 18579) = 0;
    //       i++;
    //     }
    //     if (i < end) {
    //       sub_432DF0(this, &byte_7CE498);
    //       const char *cfgPath = *this ? *this : &byte_5EA438;
    //       FileAttributesExistenceCheck(cfgPath);
    //       char name[128];
    //       if (!LookUpVehicleConfigEntry(name, 128)) {
    //         StringCopyWithBufferRealloc(name);
    //         if (!sub_568B00()) LinkedListRemovalByName(this[4]);
    //       }
    //       StringCopyWithBufferRealloc(&byte_5EA438);
    //       const char *vehName = this[4] ? this[4] : &byte_5EA438;
    //       StringCopyWithBufferRealloc(vehName);
    //       const char *driverName = *this ? *this : &byte_5EA438;
    //       sub_587DD0(veh + 18324, driverName, 255);
    //       *(char*)(veh + 18579) = 0;
    //       ValidateVehicleConfigurationFile(driverName, 0);
    //     }
    //     return end;
    //   }
    // UNRESOLVED: Meaning of the vehicle offsets +13000 (AI-settings-present flag), +18324 (string field) and +18579 (cleared byte) is only inferable from usage here; offsets carry no evidence refs of their own.
    // UNRESOLVED: Semantics of sub_568B00's return and whether the removal path or the validation path is taken depend on config parse state not visible in this packet.
    // UNRESOLVED: dword_7C54F0 is treated as an array of vehicle struct pointers but its exact element count relation to dword_5C329C is not proven here.
}
