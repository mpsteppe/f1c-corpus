// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F070
// Canonical corpus name: CollisionDataFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionDataFill_0044f070.c

void UnknownObject::CollisionDataFill()
{
    // Block fill (fastcall): builds a 4-byte pattern in which the low three byte lanes all equal the byte argument a3, then writes that pattern across 0x40 dwords (256 bytes) at offset 636 of the object via memset32, and returns the pattern.
    // CALCULATION: Construct the 4-byte fill pattern v3 from byte a3: LOBYTE(a2) = a3 and BYTE1(a2) = a3 seed the low word, v3 = a2 << 16 seeds the third byte lane, and LOWORD(v3) = a2 restores the low word, so the value occupies the three low byte lanes of the pattern (value | value<<8 | value<<16). [source:raw]
    // CALL: memset32(a1 + 636, v3, 0x40): write the 4-byte pattern to 64 dwords (256 bytes) starting at offset 636 of the object. [function:0x0044F070, source:raw]
    // RETURN: Return the fill pattern v3 as a 16-bit result. [source:raw]
    // CALL: Invoked by HWInput_Post (0x00455E70) to re-initialize the object's 256-byte block at offset 636 with a uniform byte value. [caller:0x00455E70, source:raw]

    // Conservative worker pseudocode:
    //   __int16 sub_44F070(int obj, int a2, char value) {
    //     int pattern = value | (value << 8) | (value << 16);
    //     memset32((void *)(obj + 636), pattern, 0x40);
    //     return pattern;
    //   }
    // UNRESOLVED: Identity of the 256-byte block at offset 636 and why it must be uniformly filled.
    // UNRESOLVED: a2 is only used as a scratch register to build the pattern; its intended semantic role is unknown.
    // UNRESOLVED: Relationship to the neighbouring CollisionNodePropertySetter, which also addresses offset 636 of a caller object.
}
