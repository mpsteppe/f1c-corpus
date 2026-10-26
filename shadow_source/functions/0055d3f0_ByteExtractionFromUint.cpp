// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D3F0
// Canonical corpus name: ByteExtractionFromUint
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteExtractionFromUint_0055d3f0.c

void UnknownObject::ByteExtractionFromUint()
{
    // Forwarding wrapper: decomposes the packed value a3 into its three low bytes (BYTE2, BYTE1, BYTE0) and forwards each as a separate integer argument to sub_55D320 along with this and a2, returning that callee's result unchanged. No arithmetic or storage of its own.
    // CALL: Forward to sub_55D320((int)this, a2, BYTE2(a3), BYTE1(a3), (unsigned __int8)a3): the byte at bit 16-23, the byte at bit 8-15, and the low byte of a3 become three separate arguments. Wrapper sub_55D3F0 (ABI lead Byte_Extraction_from_uint) called from sub_55A500 (0x0055A500). [abi:lead, callee:0x0055D320, caller:0x0055A500, function:0x0055D3F0, source:raw]
    // RETURN: Return the integer result of sub_55D320 unchanged. [callee:0x0055D320, source:raw]

    // Conservative worker pseudocode:
    //   int sub_55D3F0(void *this, int a2, int a3) {
    //     return sub_55D320((int)this, a2, BYTE2(a3), BYTE1(a3), (unsigned __int8)a3);
    //   }
    // UNRESOLVED: Meaning of the three extracted byte values and of arguments a2/a3 for callee sub_55D320 is unknown.
    // UNRESOLVED: Owner of this object and the reason the bytes are unpacked here rather than in the callee are not established.
}
