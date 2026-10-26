// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00583700
// Canonical corpus name: sub_583700
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_583700_00583700.c

void UnknownObject::InputStateUpdateWithDataCopy()
{
    // Input/event state updater with optional attached payload copy. Guarded on the object's type ID matching a2 and on the time delta a3 - *(double*)(this+4) staying below 2.0. On success stores the new value a3 across this+0x10/0x14, sets the update flag byte at this+0xC to 1, writes the blended result v6*0.5+a4 as a double at this+0x18, then either zeroes the payload size at this+0x120 (a6 out of [1,254]) or stores a6 and copies a6 bytes from a5 into this+0x20; returns 1, else 0.
    // GUARD: If a2 does not equal *(DWORD*)this (the object's type/identifier field), return 0 without updating. [field:this:0x00000000, source:raw]
    // CALCULATION: Compute the time delta v6 = a3 - *(double*)(this+4) against the stored previous value. [field:this:0x00000004, source:raw]
    // GUARD: If v6 >= 2.0 the update is stale/out of range; return 0. [source:raw]
    // ASSIGNMENT: Store the incoming value a3 into this+0x10 (low dword) and this+0x14 (high dword) as a packed double. [field:this:0x00000010, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Set the byte at this+0xC to 1 to flag a successful state update. [field:this:0x0000000C, source:raw]
    // CALCULATION: Write the blended/lerped result v6 * 0.5 + a4 as a double at this+0x18. [field:this:0x00000018, source:raw]
    // GUARD: If a6 <= 0 or a6 >= 255, the payload size at this+0x120 is set to 0 (no attached data). [field:this:0x00000120, source:raw]
    // ASSIGNMENT: Otherwise store a6 into this+0x120 and copy a6 bytes from the a5 buffer into this+0x20 via qmemcpy. [field:this:0x00000120, source:raw]
    // RETURN: Return 1 on a successful state update; 0 on both guard failures. [function:0x00583700, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 != *(DWORD*)this) return 0;
    //   v6 = a3 - *(double*)(this + 4);
    //   if (v6 >= 2.0) return 0;
    //   *(DWORD*)(this + 0x10) = LODWORD(a3);
    //   *(DWORD*)(this + 0x14) = HIDWORD(a3);
    //   this[12] = 1;
    //   *(double*)(this + 0x18) = v6 * 0.5 + a4;
    //   if (a6 <= 0 || a6 >= 255)
    //       *(DWORD*)(this + 0x120) = 0;
    //   else {
    //       *(DWORD*)(this + 0x120) = a6;
    //       qmemcpy(this + 0x20, a5, a6);
    //   }
    //   return 1;
    // UNRESOLVED: The read-only globals flt_59E800 and dbl_59E880 are flagged by packet facts but absent from the raw source text; the skeleton fill labels them AmplitudeLimit/HalfStep (DERIVED), possibly the sources of the inlined 0.5/2.0 literals, unverifiable from this packet.
    // UNRESOLVED: The exact meaning of a3/a4 (value plus blend offset) and of the payload buffer at this+0x20 is not stated; the caller sub_584230's context is outside this packet.
    // UNRESOLVED: Owner is unknown; the object holding the type ID, timestamp and payload is not identified.
}
