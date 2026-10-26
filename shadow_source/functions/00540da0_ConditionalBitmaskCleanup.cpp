// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00540DA0
// Canonical corpus name: ConditionalBitmaskCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalBitmaskCleanup_00540da0.c

void UnknownObject::ConditionalBitmaskCleanup()
{
    // Conditionally releases two sub-resources of an object based on bits of a bitmask argument. When a1 is non-null and bit 4 of a2 is set, calls ArithmeticComparison_0f90 on the object pointer at a1[7] (offset 0x1C) and clears a1[8] (offset 0x20) to 0. When bit 8 of a2 is set, calls GuardedVirtualDecrement on a1[9] (offset 0x24) and clears a1[10] (offset 0x28) to 0. Returns the last release result. Used by callers sub_557670 and sub_558310.
    // GUARD: If a1 is null, the function is a no-op. [source:raw]
    // GUARD: If bit 4 of the bitmask a2 is set, call ArithmeticComparison_0f90 on the object pointer at a1[7] (offset 0x1C), then clear field a1[8] (offset 0x20) to 0. [callee:0x00540F90, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // GUARD: If bit 8 of the bitmask a2 is set, call GuardedVirtualDecrement on the object pointer at a1[9] (offset 0x24), then clear field a1[10] (offset 0x28) to 0. [callee:0x005410F0, field:this:0x00000024, field:this:0x00000028, source:raw]
    // RETURN: Return the result of the last release call executed. [source:raw]

    // Conservative worker pseudocode:
    //   int ReleaseByBitmask(void* a1, char flags) {
    //     int result = 0;
    //     if (a1) {
    //       if (flags & 4) { result = ReleaseBufferLock(((int*)a1)[7]); ((int*)a1)[8] = 0; }
    //       if (flags & 8) { result = ReleaseSurfaceLock(((int*)a1)[9]); ((int*)a1)[10] = 0; }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The exact object type holding the four pointer/result fields is unknown; the two release routines differ and their reference-count semantics are unconfirmed.
    // UNRESOLVED: The meaning of bits other than 4 and 8 in the bitmask is not exercised here.
}
