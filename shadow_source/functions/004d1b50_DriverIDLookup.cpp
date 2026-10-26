// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1B50
// Canonical corpus name: sub_4D1B50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D1B50_004d1b50.c

void UnknownObject::DriverIDLookup()
{
    // Resolves a driver ID for a caller-supplied index a2. Reads a byte-slot table at this[+296]; a 255 marker or an occupied vehicle slot (dword_5EF9A0 stride 4656 entry != -1) short-circuits with either the default player value or the table value. Otherwise scans the active-vehicle pointer array dword_7C54F0[0 .. dword_5C329C) for an object whose +16480 field equals a2 + 2 and returns that object's +16440 field; any miss returns the default player value *(dword_7C54F0[0] + 16).
    // ASSIGNMENT: Load the driver-slot byte for index a2 from the table at this[a2 + 296]. [source:raw]
    // GUARD: If the table byte is 255 (empty marker), return the default player value *(dword_7C54F0[0] + 16). [source:raw, global:0x007C54F0]
    // GUARD: If dword_5EF9A0[4656 * result] != -1, the target vehicle slot is occupied, so return the table byte result directly as the driver ID. [source:raw, global:0x005EF9A0]
    // LOOP: Scan active-vehicle pointers dword_7C54F0[v3] for v3 in [0, dword_5C329C), testing whether the object's +16480 field equals a2 + 2. [source:raw, global:0x007C54F0, global:0x005C329C]
    // GUARD: If dword_5C329C <= 0, or the scan runs past the count without a match, return the default player value *(dword_7C54F0[0] + 16). [source:raw, global:0x005C329C, global:0x007C54F0]
    // RETURN: When a matching active vehicle is found, return its +16440 field as the resolved driver ID; the default fallback is the player object's +16 field. [source:raw, global:0x007C54F0]
    // CALL: Invoked from AI driver state transition (0x00419120), AI corner-speed comparison (0x00419500), race-finish handling (0x004A0BA0), camera FOV update (0x004C7F30) and eight further AI/entry call sites to map a grid/entry index to a driver ID. [caller:0x00419120, caller:0x00419500, caller:0x0049BD40, caller:0x0049BE50, caller:0x0049BFF0, caller:0x0049C0B0, caller:0x004A0BA0, caller:0x004C7F30, caller:0x004DA840, caller:0x004DAD50, caller:0x004DAD80, caller:0x004DAE00, source:raw]

    // Conservative worker pseudocode:
    //   int DriverIDLookup(unsigned __int8 *this, int a2) {
    //     int result = this[a2 + 296];
    //     if (result == 255) return *(dword_7C54F0[0] + 16);
    //     if (dword_5EF9A0[4656 * result] != -1) return result;
    //     for (int v3 = 0; v3 < dword_5C329C; ++v3)
    //       if (*(dword_7C54F0[v3] + 16480) == a2 + 2)
    //         return *(dword_7C54F0[v3] + 16440);
    //     return *(dword_7C54F0[0] + 16);
    //   }
    // UNRESOLVED: Meaning of the byte table at this[+296] and what a2 indexes (grid position, entrant number, or similar) is caller-dependent.
    // UNRESOLVED: Role of the +16480 match field and the returned +16440 field on the active-vehicle objects is unknown (likely entry/grid identity versus driver ID).
    // UNRESOLVED: Default value *(dword_7C54F0[0] + 16) is assumed to be the player's driver ID but its exact field semantics are unverified.
}
