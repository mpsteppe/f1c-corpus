// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00536130
// Canonical corpus name: BigEndianShortWriter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BigEndianShortWriter_00536130.c

void UnknownObject::WriteBigEndianShort()
{
    // Big-endian short writer: writes the two bytes of a2 (high byte first, then low byte) into a byte buffer whose pointer is stored at object offset +8, at a write offset stored at object offset +20, advancing that write offset by 2. Returns the advanced write offset. No field list, globals, guards or callees were recovered in the packet.
    // ASSIGNMENT: Write the high byte HIBYTE(a2) to the output buffer at the current write offset: target = buffer(*(a1+8)) + offset(*(a1+20)). [source:raw]
    // ASSIGNMENT: Increment the stored write offset at a1+20 by 1 (v2 = offset + 1). [source:raw]
    // ASSIGNMENT: Write the low byte of a2 to the output buffer at the new write offset: target = buffer(*(a1+8)) + v2. [source:raw]
    // CALCULATION: Increment the stored write offset at a1+20 by 1 again and keep it as the return value (result = offset + 1). [source:raw]
    // RETURN: Return the advanced write offset (a1+20 after the second increment). [source:raw, abi:lead]
    // CALL: Called by sub_535E80 (0x00535E80), consistent with the abi:lead label Big_Endian_Short_Writer. [caller:0x00535E80, function:0x00536130, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   int sub_536130(int a1, __int16 a2) {
    //     *(BYTE *)(*(DWORD *)(a1 + 8) + *(DWORD *)(a1 + 20)) = HIBYTE(a2);
    //     *(DWORD *)(a1 + 20) += 1;
    //     *(BYTE *)(*(DWORD *)(a1 + 8) + *(DWORD *)(a1 + 20)) = a2;
    //     *(DWORD *)(a1 + 20) += 1;
    //     return *(DWORD *)(a1 + 20);
    //   }
    // UNRESOLVED: Object layout unknown: buffer pointer at offset +8 and write offset at offset +20; the owner class is not identified.
    // UNRESOLVED: Caller context at 0x00535E80 is not available, so the meaning of the returned write offset is unconfirmed.
}
