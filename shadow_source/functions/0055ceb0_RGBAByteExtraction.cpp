// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055CEB0
// Canonical corpus name: RGBAByteExtraction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RGBAByteExtraction_0055ceb0.c

void UnknownObject::RGBAByteExtraction()
{
    // Trivial __stdcall wrapper that unpacks three low bytes from a packed dword a2 and forwards them, together with a1, to RGBColorSpaceCompactionTo16Bit. Used from the 2D surface blit/fill path. Decomposes a2 into BYTE2, BYTE1 and BYTE0 and returns the compaction result.
    // CALCULATION: Extract byte components of a2: BYTE2(a2), BYTE1(a2) and (unsigned __int8)a2. [source:raw]
    // CALL: Call RGBColorSpaceCompactionTo16Bit(a1, BYTE2(a2), BYTE1(a2), (unsigned __int8)a2). [source:raw, callee:0x0055CEE0]
    // RETURN: Return the value produced by RGBColorSpaceCompactionTo16Bit. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_55CEB0(int a1, int a2) {
    //     return RGBColorSpaceCompactionTo16Bit(a1, BYTE2(a2), BYTE1(a2), (unsigned __int8)a2);
    //   }
    // UNRESOLVED: Meaning of the four packed bytes in a2 (alpha/red/green/blue ordering) is not established from this packet.
    // UNRESOLVED: Role of a1 (color handle, format, or packed value) is caller-dependent and unknown here.
}
