// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A870
// Canonical corpus name: sub_58A870
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58A870_0058a870.c

void UnknownObject::MSVCU64ShiftRight()
{
    // Compiler-helper for 64-bit logical shift right on the 32-bit build: receives the 64-bit value in the edx:eax register pair and the shift count in cl, returns 0 when the count is >= 64 (0x40), otherwise returns a1 >> a2. Invoked by TextureDecodeRGB16 (0050A6E5) where the decompiler expressed a 64-bit right shift.
    // GUARD: Guard on a2 >= 64 (0x40); x86 32-bit shift helpers must clamp counts outside [0,63]. [source:raw]
    // RETURN: Return 0 when the shift count is 64 or greater. [source:raw]
    // CALCULATION: Compute the 64-bit logical right shift of a1 by a2. [source:raw]
    // RETURN: Return the shifted value a1 >> a2. [source:raw]
    // CALL: Invoked by TextureDecodeRGB16 (0050A6E5) to perform the 64-bit unsigned shift the 32-bit target cannot issue inline. [caller:0x0050A6E5, source:raw]

    // Conservative worker pseudocode:
    //   unsigned __int64 __ull_rshift(unsigned __int64 value, unsigned char count) {
    //     if (count >= 64)
    //       return 0;
    //     return value >> count;
    //   }
    // UNRESOLVED: This is a compiler-generated helper (matching the MSVC 32-bit __ull_rshift calling convention), not a hand-written source function; it has no natural source-level owner.
    // UNRESOLVED: The source expression in TextureDecodeRGB16 that produced this 64-bit shift is not visible from this packet.
}
