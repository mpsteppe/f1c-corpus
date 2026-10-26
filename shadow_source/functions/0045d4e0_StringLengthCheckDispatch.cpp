// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045D4E0
// Canonical corpus name: StringLengthCheckDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringLengthCheckDispatch_0045d4e0.c

void UnknownObject::StringLengthCheckDispatch()
{
    // Dispatches on two byte flags of the this object. When this[0] is zero the function returns without doing anything. When this[0] is non-zero and this[1] is non-zero, it forwards the off_5E4DFC pointer to an inactivity-timeout handler and then returns the network-packet receive result for that pointer; when this[1] is zero it skips the timeout handler and returns the network-packet receive result directly.
    // GUARD: Guard on this[0] (offset 0x0): when zero, the function returns early without dispatching. [field:this:0x00000000, source:raw]
    // GUARD: Guard on this[1] (offset 0x1): when non-zero, select the timeout-check path; otherwise select the direct receive path. [field:this:0x00000001, source:raw]
    // CALL: On the this[1] non-zero path, save the off_5E4DFC pointer and call TickCountComparisonHandleInactivityTimeout with it before receiving packets. [source:raw]
    // CALL: Call NetworkPacketReceive with the off_5E4DFC pointer on both non-zero branches; its result is returned. [source:raw]
    // RETURN: Return the NetworkPacketReceive result on the dispatch paths, or the uninitialized local result on the this[0] == 0 path. [source:raw]
    // CALL: Invoked by SessionScoringUpdate (0x004643C0). [caller:0x004643C0]

    // Conservative worker pseudocode:
    //   if (this[0]) {
    //     if (this[1]) {
    //       v1 = off_5E4DFC;
    //       TickCountComparisonHandleInactivityTimeout(off_5E4DFC);
    //       return NetworkPacketReceive(v1);
    //     } else {
    //       return NetworkPacketReceive(off_5E4DFC);
    //     }
    //   }
    //   return result; /* uninitialized when this[0] == 0 * /
    // UNRESOLVED: The raw source references the global off_5E4DFC and the callees TickCountComparisonHandleInactivityTimeout and NetworkPacketReceive, but the packet exposes no global/callee evidence entries for them; their addresses are not asserted here.
    // UNRESOLVED: The `result` returned on the this[0] == 0 path is uninitialized in the decompiled output (decompiler artifact).
    // UNRESOLVED: The object layout beyond the two byte flags at offsets 0x0 and 0x1 is not established.
}
