// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414380
// Canonical corpus name: MultiFieldPointerFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldPointerFree_00414380.c

void UnknownObject::MultiFieldPointerFree()
{
    // Resource teardown for a pointer-array struct. First resets the text-format struct via TextFormatStructInitializer_4d70, then runs four two-iteration countdown loops that free eight pointer slots spaced at a 5-dword stride below the anchors this+43, this+33, this+23 and this+13, each slot freed only when non-null through FreeWrapper_7bcf. Finally frees the main pointer field at this+0 when non-null. Invoked by GlobalListTripleCleanupWithTimerRemoval (00414210) and DrawableResourceCleanup (004150C0).
    // CALL: Reset the text-format struct by calling TextFormatStructInitializer_4d70 before any pointer-field teardown. [callee:0x00414D70, source:raw]
    // LOOP: Two-iteration countdown loop from anchor this+43: each iteration loads the slot 5 dwords below the current anchor, frees it via FreeWrapper_7bcf when non-null, and steps the anchor down by 5. [source:raw]
    // LOOP: Two-iteration countdown loop from anchor this+33: frees the two 5-dword-strided pointer slots below it when non-null. [source:raw]
    // LOOP: Two-iteration countdown loop from anchor this+23: frees the two 5-dword-strided pointer slots below it when non-null. [source:raw]
    // LOOP: Two-iteration countdown loop from anchor this+13: frees the two 5-dword-strided pointer slots below it when non-null. [source:raw]
    // GUARD: Guard on the main pointer field at this+0: it is freed only when non-null. [field:this:0x00000000, source:raw]
    // CALL: Free the main pointer field at this+0 via FreeWrapper_7bcf when the guard passes. [callee:0x00587BCF, source:raw]
    // RETURN: Return the original main pointer value (null when the final free was skipped). [source:raw]
    // CALL: Invoked as a shared teardown helper by GlobalListTripleCleanupWithTimerRemoval (00414210) and DrawableResourceCleanup (004150C0). [caller:0x00414210, caller:0x004150C0, source:raw]

    // Conservative worker pseudocode:
    //   TextFormatStructInitializer_4d70();
    //   free two 5-dword-strided slots below this+43;
    //   free two 5-dword-strided slots below this+33;
    //   free two 5-dword-strided slots below this+23;
    //   free two 5-dword-strided slots below this+13;
    //   if (*this) FreeWrapper_7bcf(*this);
    //   return result;
    // UNRESOLVED: Identity of the nine pointer fields (which owned resources they reference) is not established; the loop slot offsets are dword-slot displacements, not verified byte field offsets.
    // UNRESOLVED: TextFormatStructInitializer_4d70 is called with no visible arguments in the raw source; whether it acts on this or on a global is unresolved.
}
