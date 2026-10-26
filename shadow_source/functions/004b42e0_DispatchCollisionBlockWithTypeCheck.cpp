// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B42E0
// Canonical corpus name: FAILWRONGDESCRIPTION_42e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FAILWRONGDESCRIPTION_42e0_004b42e0.c

void UnknownObject::DispatchCollisionBlockWithTypeCheck()
{
    // Dispatches a collision data block through the conditional-dispatch system: first a header dispatch with code 4, then, when the header tag bits identify the block type and a subfield is clear, a transformed float value (scaled and rounded to a byte) is dispatched with code 1, and finally the data payload is dispatched with a length read from the header. Always returns 1.
    // CALL: Dispatch the header dword at a3 with dispatch code 4 via ConditionalDispatch_6bd0. [callee:0x00566BD0]
    // GUARD: Guard: transformed-byte dispatch runs only when (*(_DWORD*)v3 & 0xE0000000) == 0x20000000 and (*(_DWORD*)v3 & 0xFC0000) == 0. [source:raw]
    // CALCULATION: Compute (float field at v3+4 - a2) divided by 0.0001670000056037679 plus 0.5; scale constants referenced by read globals dbl_59E880 and dbl_5ACD28. [source:raw, global:0x0059E880, global:0x005ACD28]
    // CALL: Convert the computed float to a byte via CRTFtol and store into the low byte of a3. [callee:0x00587BDC]
    // CALL: Dispatch the transformed byte value with dispatch code 1 via ConditionalDispatch_6bd0. [callee:0x00566BD0]
    // CALL: Dispatch the data payload at v3+8 with a length taken from header bits (*(_DWORD*)v3 >> 8) & 0x3FF via ConditionalDispatch_6bd0. [callee:0x00566BD0]
    // RETURN: Return 1 (success) regardless of whether the transformed-byte branch was taken. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4B42E0(int a1, float a2, int a3) {
    //     int v3 = a3;
    //     ConditionalDispatch_6bd0(a3, 4);
    //     if ((*(_DWORD*)v3 & 0xE0000000) == 0x20000000 && (*(_DWORD*)v3 & 0xFC0000) == 0) {
    //       LOBYTE(a3) = CRTFtol((*(float*)(v3 + 4) - a2) / 0.0001670000056037679 + 0.5);
    //       ConditionalDispatch_6bd0(&a3, 1);
    //     }
    //     ConditionalDispatch_6bd0(v3 + 8, (*(_DWORD*)v3 >> 8) & 0x3FF);
    //     return 1;
    //   }
    // UNRESOLVED: Exact association of dbl_59E880 and dbl_5ACD28 with the inlined constant 0.0001670000056037679 is not determinable from this packet.
    // UNRESOLVED: Meaning of the header tag bits (0x20000000 in bits [31:29]) and the length field bits [17:8] depends on the collision block format, not recoverable here.
}
