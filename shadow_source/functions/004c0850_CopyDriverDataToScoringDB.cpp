// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C0850
// Canonical corpus name: sub_4C0850
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C0850_004c0850.c

void UnknownObject::CopyDriverDataToScoringDB()
{
    // Restores a vehicle's runtime state into the season scoring database from a loaded career-data record. Guarded by an active flag byte at this+0x1B0; when set, it indexes a season-scoring entry as dword_7D2E48 + 18624 * this[105], looks up the vehicle by name with VehicleLookupByName, loads nationality/driver info with NationalityDriverInfoLoader, copies the driver name and vehicle file name strings (with byte_5EA438 defaults for null pointers) into the entry, then sets the grid position via ConditionalFieldSetter and transitions session state. Returns the adjusted grid position value.
    // GUARD: Guard on the active flag byte at this+0x1B0: when zero, skip all restore work and return it (returns 0). [field:this:0x000001B0, abi:lead]
    // CALCULATION: v4 = dword_7D2E48 + 18624 * this[105]: index the season-scoring database entry using the vehicle index stored at this+0x1A4. [global:0x007D2E48, field:this:0x000001A4]
    // ASSIGNMENT: v3 = this+0x8 vehicle file name pointer; fall back to byte_5EA438 when null. [field:this:0x00000008, global:0x005EA438]
    // CALL: VehicleLookupByName(v3): look up the vehicle by file name. [callee:0x004C3F80]
    // CALL: NationalityDriverInfoLoader(dword_8AC38C): load nationality/driver info using the loaded lookup parameter. [callee:0x004C78F0, global:0x008AC38C]
    // ASSIGNMENT: v5 = this+0x0 driver name pointer; fall back to byte_5EA438 when null. [field:this:0x00000000, global:0x005EA438]
    // CALL: strcpy(v4 + 17952, v5): copy the driver name into the season-scoring entry. [global:0x007D2E48]
    // CALL: strcpy(v4 + 18196, v6): copy the vehicle file name into the season-scoring entry. [global:0x007D2E48]
    // CALL: ConditionalFieldSetter(v4 + 16436, this[106] + 1): set the grid position field of the entry from the value at this+0x1A8. [callee:0x004BC2F0, field:this:0x000001A8]
    // STATE_TRANSITION: SessionStateTransition(this[107], 0): transition the session state using the parameter at this+0x1AC. [callee:0x004EF5A0, field:this:0x000001AC]
    // ASSIGNMENT: v2 = this[106] + 1; write v2 back to the entry at v4 + 16472. [field:this:0x000001A8]
    // RETURN: Return v2: the adjusted grid position value, or 0 when the active flag was clear. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4C0850(CareerRecord* this) {
    //     if (!*(char*)((char*)this + 432)) return 0;
    //     char* vehFile = *(char**)this + 8;
    //     if (!vehFile) vehFile = byte_5EA438;
    //     ScoringEntry* entry = (ScoringEntry*)(dword_7D2E48 + 18624 * this[105]);
    //     VehicleLookupByName(vehFile);
    //     NationalityDriverInfoLoader(dword_8AC38C);
    //     const char* name = *(const char**)this;
    //     if (!name) name = byte_5EA438;
    //     strcpy((char*)entry + 17952, name);
    //     strcpy((char*)entry + 18196, vehFile);
    //     ConditionalFieldSetter((int)entry + 16436, this[106] + 1);
    //     SessionStateTransition(this[107], 0);
    //     int pos = this[106] + 1;
    //     *(int*)((char*)entry + 16472) = pos;
    //     return pos;
    //   }
    // UNRESOLVED: global unk_8AC388 (0x8AC388) is marked read but not referenced directly in the raw source; it is adjacent to dword_8AC38C and may be consumed by a callee.
    // UNRESOLVED: Exact semantics of the SessionStateTransition second argument (0) are not proven.
    // UNRESOLVED: Whether dword_7D2E48 is the base or a pointer to the season-scoring database is unverified.
}
