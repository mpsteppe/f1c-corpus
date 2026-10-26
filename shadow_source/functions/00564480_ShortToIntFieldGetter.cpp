// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564480
// Canonical corpus name: ShortToIntFieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortToIntFieldGetter_00564480.c

void UnknownObject::ShortToIntFieldGetter()
{
    // Plain getter: returns the 16-bit value stored at byte offset 0x6 of `this` (this[3] as __int16 index), widened to int. No side effects. Called from StringComparisonWithConstantDispatch.
    // RETURN: Return this[3], the 16-bit field at byte offset 0x6, promoted to int. [source:raw, field:this:0x00000006]

    // Conservative worker pseudocode:
    //   int sub_564480(__int16 *this) {
    //     return this[3];
    //   }
    // UNRESOLVED: Semantics of the 16-bit field at offset 0x6 and the object type behind `this` are unknown.
    // UNRESOLVED: Only read; no writer or state transition is visible in this function.
}
