// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00547370
// Canonical corpus name: ArithmeticComparison_7370
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_7370_00547370.c

void UnknownObject::CopyCStringTo()
{
    // Byte-string copy from this to a2. Guards on a non-null destination, then computes the source-to-destination byte displacement v3 = a2 - this and forward-copies bytes one at a time (result[v3] = *result) until a zero terminator byte is read, copying the terminator as well. Returns the source pointer advanced past the copied terminator. The prelabel getter template is contradicted by the raw source: this is a copy routine, not a field getter.
    // GUARD: The copy body only runs when the destination a2 is non-null; a null destination returns this immediately [source:raw]
    // CALCULATION: Compute the constant byte displacement v3 = a2 - this so each source byte at result is written to result[v3] (the mirrored destination position) [source:raw]
    // LOOP: Forward byte loop: read v4 = *result, write result[v3] = v4, advance result, and repeat until the copied byte v4 is zero (the terminator is copied too, so the loop stops on the first zero byte) [field:this:0x00000000, source:raw]
    // RETURN: Return the source pointer result, which points one byte past the copied terminator [function:0x00547370, source:raw]
    // CALL: Invoked by AnimationPlaybackSequence (0044ACB0), sub_4CEF30 (004CEF30) and VehicleGraphicsSceneLoader (004DFCE0), which supply the destination buffer [caller:0x0044ACB0, caller:0x004CEF30, caller:0x004DFCE0, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == 0)
    //       return this;
    //   v3 = a2 - this;
    //   do {
    //       v4 = *result;
    //       result[v3] = v4;
    //       ++result;
    //   } while (v4 != 0);
    //   return result;
    // UNRESOLVED: The prelabel template classified this as a getter returning field this+0, which the raw source contradicts; this+0 is actually the source string buffer consumed by the copy
    // UNRESOLVED: There is no length bound on the copy, so a source buffer without a terminator byte within reachable memory would overrun; the intended buffer sizes are not documented in the packet
}
