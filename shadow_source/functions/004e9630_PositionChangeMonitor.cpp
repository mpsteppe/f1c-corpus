// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E9630
// Canonical corpus name: PositionChangeMonitor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PositionChangeMonitor_004e9630.c

void UnknownObject::PositionChangeMonitor()
{
    // Conditionally registers the current 3D position (this+0x34D4, this+0x34D8, this+0x34DC) with a tracking service via sub_403640, saves the previous position triplet into the history slots (this+0x3AA0, this+0x3AA4, this+0x3AA8), and returns the tracking handle stored at this+0x3A9C. The update runs only when no status flags are set or the current handle is zero.
    // GUARD: If no status flags are set (the decompiled v4/c0 and v5/c3 are both zero) or the tracking handle at this[3751] (this+0x3A9C) is zero, proceed to update the position history. [field:this:0x00003A9C, source:raw]
    // CALL: Call sub_403640(dword_5EA2C0, (float*)this + 3381, this[3751]) to register the current position triplet (this+0x34D4, 0x34D8, 0x34DC) with the tracking service; the returned pointer becomes the new handle. [callee:0x00403640, global:0x005EA2C0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, field:this:0x00003A9C, source:raw]
    // ASSIGNMENT: Read the current position X component (this+0x34D4) into a local before the handle slot is overwritten. [field:this:0x000034D4, source:raw]
    // ASSIGNMENT: Read the current position Y component (this+0x34D8) into a local. [field:this:0x000034D8, source:raw]
    // ASSIGNMENT: Read the current position Z component (this+0x34DC) into a local. [field:this:0x000034DC, source:raw]
    // ASSIGNMENT: Store the new tracking handle returned by sub_403640 into this[3751] (this+0x3A9C). [field:this:0x00003A9C, source:raw]
    // ASSIGNMENT: Copy the saved previous position X into this[3752] (this+0x3AA0). [field:this:0x00003AA0, source:raw]
    // ASSIGNMENT: Copy the saved previous position Y into this[3753] (this+0x3AA4). [field:this:0x00003AA4, source:raw]
    // ASSIGNMENT: Copy the saved previous position Z into this[3754] (this+0x3AA8). [field:this:0x00003AA8, source:raw]
    // RETURN: Return this[3751] (the tracking handle at this+0x3A9C). [field:this:0x00003A9C, source:raw]

    // Conservative worker pseudocode:
    //   int update(this) {
    //     if (!status_flags_set || !this[3751]) {
    //       v2 = this + 3381;
    //       v7 = v2[0];
    //       v8 = v2[1];
    //       this[3751] = sub_403640(dword_5EA2C0, (float*)this + 3381, this[3751]);
    //       v9 = v2[2];
    //       this[3752] = v7;
    //       this[3753] = v8;
    //       this[3754] = v9;
    //     }
    //     return this[3751];
    //   }
    // UNRESOLVED: flt_59E9E0 (global 0x0059E9E0) appears in the packet globals but is not referenced by the raw source text; role unknown.
    // UNRESOLVED: The guard reads decompiler condition-code flags v4 (c0) and v5 (c3); the original flag source is not recoverable from the packet.
    // UNRESOLVED: The exact registration semantics of sub_403640 and the meaning of the returned handle are outside this packet.
    // UNRESOLVED: The position triplet (this+0x34D4 .. 0x34DC) and history slots (this+0x3AA0 .. 0x3AA8) are described from the existing analysis, not from the raw source.
}
