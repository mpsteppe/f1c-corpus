// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00418CF0
// Canonical corpus name: ShortComputation_8cf0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_8cf0_00418cf0.c

void UnknownObject::MultiFieldPointerFreeShallow()
{
    // Shallow resource teardown structurally parallel to MultiFieldPointerFree (00414380). Resets the text-format struct via TextFormatStructInitializer_4fe0, runs two two-iteration countdown loops freeing four 5-dword-strided pointer slots below the anchors this+23 and this+13, each freed when non-null through FreeWrapper_7bcf, then frees the main pointer at this+0. When flag bit a2 bit 0 is set, the object itself is freed after its fields. Returns this. Invoked by SceneListBuilderFromGlobalArray (00415C40).
    // CALL: Reset the text-format struct by calling TextFormatStructInitializer_4fe0 on this before pointer-field teardown. [callee:0x00414FE0, source:raw]
    // LOOP: Two-iteration countdown loop from anchor this+23: each iteration loads the slot 5 dwords below the current anchor, frees it via FreeWrapper_7bcf when non-null, and steps the anchor down by 5. [source:raw]
    // LOOP: Two-iteration countdown loop from anchor this+13: frees the two 5-dword-strided pointer slots below it when non-null. [source:raw]
    // GUARD: Guard on the main pointer field at this+0: it is freed only when non-null. [field:this:0x00000000, source:raw]
    // CALL: Free the main pointer field at this+0 via FreeWrapper_7bcf when the guard passes. [callee:0x00587BCF, source:raw]
    // GUARD: Guard on a2 bit 0: when set, the object pointer itself is freed after its fields. [source:raw]
    // CALL: Free the this object itself via FreeWrapper_7bcf when a2 bit 0 is set. [callee:0x00587BCF, source:raw]
    // RETURN: Return this, so callers can chain or observe the (possibly freed) pointer. [source:raw]
    // CALL: Invoked by SceneListBuilderFromGlobalArray (00415C40) as the teardown for the scene-list objects it builds. [caller:0x00415C40, source:raw]

    // Conservative worker pseudocode:
    //   TextFormatStructInitializer_4fe0((int)this);
    //   p = this + 23; n = 2;
    //   do { q = *(p - 5); p -= 5; if (q) FreeWrapper_7bcf(q); } while (--n);
    //   p = this + 13; n = 2;
    //   do { q = *(p - 5); p -= 5; if (q) FreeWrapper_7bcf(q); } while (--n);
    //   if (*this) FreeWrapper_7bcf(*this);
    //   if (a2 & 1) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: Identity of the five pointer fields (which owned resources they reference) is not established; the loop slot offsets are dword-slot displacements, not verified byte field offsets.
    // UNRESOLVED: Interpretation of a2 bit 0 as a delete/self-free flag is DERIVED from the raw source's conditional FreeWrapper_7bcf(this) and is not confirmed.
    // UNRESOLVED: Why this variant covers only the two lower pointer groups while 00414380 covers four is unresolved.
}
