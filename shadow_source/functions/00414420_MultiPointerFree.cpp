// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414420
// Canonical corpus name: MultiPointerFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiPointerFree_00414420.c

void UnknownObject::MultiPointerFree()
{
    // Resource teardown for a pointer-array struct, structurally related to MultiFieldPointerFree (00414380). Resets the text-format struct via TextFormatStructInitializer_4fe0, then runs two two-iteration countdown loops that free four pointer slots spaced at a 5-dword stride below the anchors this+23 and this+13, each slot freed only when non-null through FreeWrapper_7bcf. Finally frees the main pointer field at this+0 when non-null and returns its prior value. Invoked by GlobalListTripleCleanupWithTimerRemoval (00414210).
    // CALL: Reset the text-format struct by calling TextFormatStructInitializer_4fe0 before any pointer-field teardown. [callee:0x00414FE0, source:raw]
    // LOOP: Two-iteration countdown loop from anchor this+23: each iteration loads the slot 5 dwords below the current anchor, frees it via FreeWrapper_7bcf when non-null, and steps the anchor down by 5. [source:raw]
    // LOOP: Two-iteration countdown loop from anchor this+13: frees the two 5-dword-strided pointer slots below it when non-null. [source:raw]
    // GUARD: Guard on the main pointer field at this+0: it is freed only when non-null. [field:this:0x00000000, source:raw]
    // CALL: Free the main pointer field at this+0 via FreeWrapper_7bcf when the guard passes. [callee:0x00587BCF, source:raw]
    // RETURN: Return the original main pointer value (null when the final free was skipped). [source:raw]
    // CALL: Shared teardown helper invoked by GlobalListTripleCleanupWithTimerRemoval (00414210). [caller:0x00414210, source:raw]

    // Conservative worker pseudocode:
    //   LPVOID MultiPointerFree(LPVOID* this) {
    //     TextFormatStructInitializer_4fe0();
    //     for (v2 = this + 23, v3 = 2; v3; --v3, v2 -= 5)
    //       if (*(v2 - 5)) FreeWrapper_7bcf(*(v2 - 5));
    //     for (v5 = this + 13, v6 = 2; v6; --v6, v5 -= 5)
    //       if (*(v5 - 5)) FreeWrapper_7bcf(*(v5 - 5));
    //     result = *this;
    //     if (*this) return FreeWrapper_7bcf(*this);
    //     return result;
    //   }
    // UNRESOLVED: Identity of the five pointer fields (which owned resources they reference) is not established; the loop slot offsets are dword-slot displacements, not verified byte field offsets.
    // UNRESOLVED: TextFormatStructInitializer_4fe0 is called with no visible arguments in the raw source; whether it acts on this or on a global is unresolved.
    // UNRESOLVED: The prelabel marks this as structurally related to MultiFieldPointerFree (00414380), but that twin shows four loops while this function has only two, so the field sets differ.
}
