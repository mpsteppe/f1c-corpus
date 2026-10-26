// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C0D0
// Canonical corpus name: StringShiftByOffset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringShiftByOffset_0058c0d0.c

void UnknownObject::StringShiftByOffset()
{
    // When the shift offset is non-zero, computes the length of the source byte string with Strlen and block-moves the whole string including its NUL terminator (length + 1 bytes) from a1 to a1+a2, effectively shifting the string right by a2 bytes to open space for an insertion. No-op when a2 is zero. Called by sub_58BE2E (0058BE2E) and UtilityFunction_bf45 (0058BF45).
    // GUARD: If a2 == 0 the function is a no-op; the body runs only for a non-zero shift offset [function:0x0058C0D0, source:raw]
    // CALL: v2 = Strlen(a1): length of the string being shifted [callee:0x0058E1B0, source:raw]
    // CALCULATION: v2 + 1: byte count including the NUL terminator, passed as the length argument [source:raw]
    // CALL: sub_58B130(a1 + a2, a1, v2 + 1): block copy of the string onto itself at offset a2, shifting it right [callee:0x0058B130, source:raw]
    // CALL: Invoked by sub_58BE2E (0058BE2E) and UtilityFunction_bf45 (0058BF45) [caller:0x0058BE2E, caller:0x0058BF45]

    // Conservative worker pseudocode:
    //   if (a2 != 0) {
    //     v2 = Strlen(a1);
    //     sub_58B130(&a1[a2], a1, v2 + 1);
    //   }
    // UNRESOLVED: sub_58B130 (0x0058B130) is the actual block-move implementation; only its call contract (dest, src, count) is visible here, not its internal behavior
}
