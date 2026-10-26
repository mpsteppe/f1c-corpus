// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00433090
// Canonical corpus name: PhysicsObjectDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsObjectDestructor_00433090.c

void UnknownObject::PhysicsObjectDestructor()
{
    // Teardown for a physics-config style object. First calls SessionConfigDefaultInit on the whole object to reset its configuration fields, then frees up to three heap-allocated pointer fields (offsets 0x14, 0x8, 0x0) via FreeWrapper_7bcf, each guarded by a non-null check, and returns the last FreeWrapper result (or the saved value of field 0x8 when that field was null).
    // CALL: Invoke SessionConfigDefaultInit(this) to reinitialize/reset the object's configuration fields before any pointers are freed. [callee:0x00432CC0, source:raw]
    // GUARD: Guard: only free the pointer at offset 0x14 (this + 20) when it is non-null. [field:this:0x00000014, source:raw]
    // CALL: Free the heap pointer at offset 0x14 via FreeWrapper_7bcf(*(this + 20)). [callee:0x00587BCF, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Load result = *(this + 8), the second heap-allocated pointer field, before its null check. [field:this:0x00000008, source:raw]
    // GUARD: Guard: only free the pointer at offset 0x8 when result (the loaded value) is non-null. [field:this:0x00000008, source:raw]
    // CALL: Free the heap pointer at offset 0x8 via FreeWrapper_7bcf(*(this + 8)) and keep its return value as result. [callee:0x00587BCF, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Load v3 = *(this), the first heap-allocated pointer field at offset 0x0. [field:this:0x00000000, source:raw]
    // GUARD: Guard: only free the pointer at offset 0x0 when v3 is non-null. [field:this:0x00000000, source:raw]
    // RETURN: Return the FreeWrapper_7bcf result for the offset 0x0 pointer when it was freed, otherwise the earlier result (from offset 0x8 or its null fallback). [source:raw]
    // CALL: Called by AutoLoadEntryListLoader (0x00432E70), which tears this object down as part of loading the auto-load entry list. [caller:0x00432E70, source:raw]

    // Conservative worker pseudocode:
    //   int PhysicsObjectDestructor(int this) {
    //     SessionConfigDefaultInit((int *)this);
    //     if (*(int *)(this + 20))
    //       FreeWrapper_7bcf(*(void **)(this + 20));
    //     int result = *(int *)(this + 8);
    //     if (result)
    //       result = FreeWrapper_7bcf(*(void **)(this + 8));
    //     void *v3 = *(void **)this;
    //     if (v3)
    //       return FreeWrapper_7bcf(v3);
    //     return result;
    //   }
    // UNRESOLVED: The concrete object type is unknown; the destructor-shaped call to SessionConfigDefaultInit before freeing suggests a physics/session config record, but only the three pointer-field offsets are evidenced.
    // UNRESOLVED: Exact types of the freed allocations at offsets 0x0, 0x8 and 0x14 are unknown.
    // UNRESOLVED: Whether SessionConfigDefaultInit is a plain field reset or performs additional allocation is outside this function's evidence.
}
