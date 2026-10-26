// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567740
// Canonical corpus name: FPUControlWordMaskExtract
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FPUControlWordMaskExtract_00567740.c

void UnknownObject::FPUControlWordMaskExtract()
{
    // Returns a 16-bit stack value v1 masked with 0x300, extracting bits 8 and 9. The decompiled source reads v1 before any assignment, so its origin is not evidenced; callers are physics/tire initialization code.
    // CALCULATION: Bitwise AND of 16-bit stack local v1 with 0x300, keeping bits 8 and 9 [source:raw, function:0x00567740]
    // RETURN: Return the masked value [source:raw, function:0x00567740]

    // Conservative worker pseudocode:
    //   return v1 & 0x300;
    // UNRESOLVED: v1 is read uninitialized in the decompiled source; likely an FPU control-word read by the caller, but no packet evidence grounds that.
    // UNRESOLVED: Semantics of the extracted bits are not established.
}
