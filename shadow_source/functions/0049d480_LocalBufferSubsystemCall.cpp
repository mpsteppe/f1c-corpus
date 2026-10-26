// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049D480
// Canonical corpus name: LocalBufferSubsystemCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LocalBufferSubsystemCall_0049d480.c

void UnknownObject::LocalBufferSubsystemCall()
{
    // Thiscall that prepares a 16-byte stack buffer, initializes it with sub_49C670(buffer, 15), then forwards it to sub_553070(buffer, 4, 21, *(*(this+0x10) + 0x54)) and returns the result. The final argument dereferences a pointer read from this+0x10 and adds 84; the packet also exposes the flattened nominal target this+0x64. Called only from SteeringWheelAnimation (0049D070).
    // CALL: Initializes the 16-byte stack buffer v3 by calling sub_49C670(v3, 15) [callee:0x0049C670, source:raw]
    // CALL: Calls sub_553070(v3, 4, 21, value) with the value read from the object reached as *(this+0x10) + 0x54; the pointer at this+0x10 is dereferenced and 84 is added, which the packet flattens to the nominal target this+0x64 [callee:0x00553070, field:this:0x00000010, field:this:0x00000064, source:raw]
    // RETURN: Returns the result of sub_553070 to the caller [source:raw]

    // Conservative worker pseudocode:
    //   int LocalBufferSubsystemCall(this) {
    //     byte v3[16];
    //     sub_49C670(v3, 15);
    //     return sub_553070(v3, 4, 21, *((this[4]) + 84));
    //   }
    // UNRESOLVED: The read-only global unk_7CE234 (0x007CE234) is flagged by packet facts but appears nowhere in the raw decompiled source
    // UNRESOLVED: field:this:0x00000064 is a packet-flattened nominal target of the read at *(this+0x10)+0x54; the meaning of the +0x54 subfield of the pointed-to object is unknown
    // UNRESOLVED: The meaning of the constant arguments 15, 4 and 21 passed to sub_49C670 / sub_553070 is not evidenced by this packet
    // UNRESOLVED: The role of the 16-byte buffer shared between the two callee calls is not evidenced
}
