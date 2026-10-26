// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8C00
// Canonical corpus name: ArithmeticComparison_8c00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_8c00_004f8c00.c

void UnknownObject::ArithmeticComparison_8c00()
{
    // Maps a status result from the VFXGetTracking function-pointer global into one of several fixed integer codes: returns 4 when the routine is not installed, 0 for status 1, 7 for status 2 or 3, and 6 for any other status.
    // GUARD: If the VFXGetTracking function pointer is null, return 4 immediately. [global:0x008AFC8C, source:raw]
    // CALL: Call VFXGetTracking(a1, a2, a3) through the global function pointer and store its result in v3. [global:0x008AFC8C, source:raw]
    // GUARD: If v3 equals 1, return 0. [source:raw]
    // GUARD: If v3 equals 2 or 3, return 7. [source:raw]
    // RETURN: Default path returns 6 for any other v3 value. [source:raw]

    // Conservative worker pseudocode:
    //   if (VFXGetTracking == NULL)
    //     return 4;
    //   status = VFXGetTracking(a1, a2, a3);
    //   if (status == 1)
    //     return 0;
    //   if (status == 2 || status == 3)
    //     return 7;
    //   return 6;
    // UNRESOLVED: Meaning of the input arguments a1, a2, a3 to VFXGetTracking.
    // UNRESOLVED: Semantic meaning of the fixed result codes 4, 0, 7 and 6.
    // UNRESOLVED: Purpose of the caller sub_4F8B00 for this status mapping.
}
