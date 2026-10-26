// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045B500
// Canonical corpus name: RotatingIndexSearchWithThreshold
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RotatingIndexSearchWithThreshold_0045b500.c

void UnknownObject::RotatingIndexSearchWithThreshold()
{
    // Searches an 8-entry circular buffer for an available slot. Starts from the rotating cursor this[199] (dword at this+0x31C) and scans up to eight candidates, returning the first index whose float field at dword offset 36 of the entry (23-dword stride) is <= the 0.0 threshold (flt_59E440). If the rotating scan finds nothing, falls back to scanning entries from this+60 (this+0xF0) with the same 23-dword stride and tracks a candidate index by comparing each entry value against the running result; returns -1 when the caller's threshold a2 exceeds the chosen entry's int field at dword offset 37, otherwise returns the chosen index. On the frame path; invoked by RegisterTextLineEntry (0045B9C0).
    // ASSIGNMENT: Load the rotating cursor v2 = this[199], the dword at this+0x31C [field:this:0x0000031C, source:raw]
    // LOOP: Rotating scan: for i = 0..7 inspect entry (v2 % 8), then advance v2 by one; the entry stride is 23 dwords [source:raw]
    // GUARD: If the float at this[23*(v2%8) + 36] (the entry's availability field) is <= 0.0, i.e. <= flt_59E440, accept that entry immediately [global:0x0059E440, source:raw]
    // RETURN: Return the accepted index v2 % 8 without further scanning [source:raw]
    // LOOP: Fallback scan: initialize result to 0 and v5 to 1, then walk v6 from this+60 (this+0xF0) in 23-dword steps while v5 < 8; when *v6 compares below result, set result = v5 [field:this:0x000000F0, source:raw]
    // GUARD: Threshold gate: if a2 > this[23*result + 37] (the chosen entry's int threshold field), reject the candidate [source:raw]
    // RETURN: Return -1 when the candidate fails the a2 threshold, otherwise return result [source:raw]
    // CALL: Invoked by RegisterTextLineEntry (0045B9C0) as its free-slot lookup; on the frame path [caller:0x0045B9C0, source:raw]

    // Conservative worker pseudocode:
    //   int RotatingIndexSearchWithThreshold(int* this, int a2) {
    //     int cursor = this[199];
    //     for (int i = 0; i < 8; ++i) {
    //       int idx = cursor % 8;
    //       if (*(float*)&this[23*idx + 36] <= 0.0f) return idx;
    //       ++cursor;
    //     }
    //     int result = 0;
    //     for (int v5 = 1; v5 < 8; ++v5) {
    //       if (this[23*v5 + 60] < result) result = v5;
    //     }
    //     if (a2 > this[23*result + 37]) return -1;
    //     return result;
    //   }
    // UNRESOLVED: The fallback scan compares each entry value against the running result index rather than against a stored best value; whether this is a decompiler artifact or the original logic is unresolved
    // UNRESOLVED: Roles of the float field at dword offset 36 (availability/lifetime) and the int field at dword offset 37 (threshold) are inferred from usage and caller context, not proven
    // UNRESOLVED: The exact record layout behind the 23-dword stride is not defined by this packet
}
