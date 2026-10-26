// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00511B5C
// Canonical corpus name: ConditionalDispatchWithGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDispatchWithGuard_00511b5c.c

void UnknownObject::ConditionalDispatchWithGuard()
{
    // Conditionally recalculates the audio buffer size when the flag byte at this+0x5C has bit 0x40 clear, then always dispatches to packet field encoding and returns its result. Guarded dispatch helper; called from sub_50210E.
    // GUARD: If (byte at this+0x5C & 0x40) == 0, the audio buffer recalculation branch runs; when bit 0x40 is set the branch is skipped. [field:this:0x0000005C, source:raw]
    // CALL: When bit 0x40 is clear, call AudioBufferSizeCalc(a1) to recalculate the audio buffer size. [callee:0x0051868C, source:raw]
    // CALL: Always dispatch to PacketFieldEncoding(a1, a2) to encode packet fields into an output buffer. [callee:0x005124DE, source:raw]
    // RETURN: Return the result of PacketFieldEncoding(a1, a2). [source:raw]

    // Conservative worker pseudocode:
    //   int ConditionalDispatchWithGuard(int a1, int a2) {
    //     if ((*(BYTE *)(a1 + 92) & 0x40) == 0)
    //       AudioBufferSizeCalc(a1);
    //     return PacketFieldEncoding(a1, a2);
    //   }
    // UNRESOLVED: Purpose of the flag byte at this+0x5C bit 0x40 and the owner class of 'this' are not evidenced; the reading that bit 0x40 set means the buffer is already sized is DERIVED from the control flow only.
    // UNRESOLVED: Semantics of PacketFieldEncoding (0x005124DE) and AudioBufferSizeCalc (0x0051868C) rest on corpus names; their runtime behavior is not verified in this packet.
}
