// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005029E5
// Canonical corpus name: BMPHeaderValidation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BMPHeaderValidation_005029e5.c

void UnknownObject::BMPHeaderValidation()
{
    // __thiscall BMP header gate: if the buffer length a3 is at least 14 bytes, the first 16-bit value a2 equals 19778 (0x4D42, "BM"), and the declared file size at a2+2 does not exceed the buffer length a3, the function hands the remaining payload at a2+14 (length a3-14) to DDSTextureFormatValidationDecoding. Otherwise it returns the error value -2147467259.
    // GUARD: Guard: proceed only when a3 >= 14, the 16-bit signature at a2 equals 19778 (0x4D42, BMP magic "BM"), and the 32-bit size field at a2+2 is <= a3. [source:raw]
    // CALCULATION: Compute the payload pointer and remaining length: a2 + 14 bytes after the header, and a3 - 14 bytes remaining. [source:raw]
    // CALL: On valid header, call DDSTextureFormatValidationDecoding(this, a2 + 14, a3 - 14) and return its result. [callee:0x00500FCA, source:raw]
    // RETURN: On failed validation, return -2147467259. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5029E5(int *this, int header, unsigned int len) {
    //     if (len >= 0xE && *(WORD*)header == 19778 && *(DWORD*)(header + 2) <= len)
    //       return DDSTextureFormatValidationDecoding(this, header + 14, len - 14);
    //     return -2147467259;
    //   }
    // UNRESOLVED: The role of this (an object pointer of UnknownObject type) and how its format state is mutated by the decode callee is unknown here.
    // UNRESOLVED: The remaining payload is assumed to be a DDS or embedded texture format decoded by sub_500FCA; not proven from this packet.
    // UNRESOLVED: Literal 19778 is the BMP signature value; the connection to BMP/DDS negotiation is inferred from the caller DirectXSurfaceFormatNegotiation.
}
