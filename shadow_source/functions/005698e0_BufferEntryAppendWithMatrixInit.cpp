// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005698E0
// Canonical corpus name: BufferEntryAppendWithMatrixInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferEntryAppendWithMatrixInit_005698e0.c

void UnknownObject::BufferEntryAppendWithMatrixInit()
{
    // Appends a 132-byte entry to the buffer described by this: the entry base is this[142] + 132 * this[141] and the element count this[141] is post-incremented. Writes metadata a5 at +120, a3 at +124 and the byte flag a4 at +128, then calls sub_56C3A0(entry+24, entry+48) to initialize a matrix block within the entry. Returns the new entry base pointer. Called by VehiclePhysicsJointSystemLoader.
    // ASSIGNMENT: v5 = this[142] + 132 * this[141]++ computes the next entry base in the stride-132 buffer and post-increments the element count at this[141] [field:this:0x00000234, field:this:0x00000238, source:raw]
    // ASSIGNMENT: *(v5 + 120) = a5 stores the first metadata dword in the entry [source:raw]
    // ASSIGNMENT: *(v5 + 124) = a3 stores the second metadata dword in the entry [source:raw]
    // ASSIGNMENT: *(v5 + 128) = a4 stores the byte flag in the entry [source:raw]
    // CALL: sub_56C3A0(v5 + 24, v5 + 48) initializes a matrix block spanning entry offsets 24 and 48 [callee:0x0056C3A0, source:raw]
    // RETURN: Returns v5, the base pointer of the appended entry [source:raw]
    // CALL: Invoked by VehiclePhysicsJointSystemLoader (0056d930) as the constraint-group entry appender [caller:0x0056D930]

    // Conservative worker pseudocode:
    //   v5 = this[142] + 132 * this[141]++;
    //   *(v5 + 120) = a5;
    //   *(v5 + 124) = a3;
    //   *(v5 + 128) = a4;
    //   sub_56C3A0(v5 + 24, v5 + 48);
    //   return v5;
    // UNRESOLVED: a2 is not referenced anywhere in the decompiled body; its intended role (likely a base/index argument) is unknown
    // UNRESOLVED: The exact semantics of the 3x3 matrix block initialized by sub_56C3A0 at entry offsets 24 and 48 are not documented in this packet
    // UNRESOLVED: The meaning of the metadata dwords at entry offsets 120/124 and the byte flag at offset 128 is inferred as constraint-group parameters; the packet only shows their assignment
}
