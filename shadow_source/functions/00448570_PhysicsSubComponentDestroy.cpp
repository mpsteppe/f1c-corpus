// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00448570
// Canonical corpus name: PhysicsSubComponentDestroy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsSubComponentDestroy_00448570.c

void UnknownObject::PhysicsSubComponentDestroy()
{
    // Destroys and frees up to five physics sub-component pointers: a four-iteration loop over dword pointers starting at this+0x4C (offsets 0x4C, 0x50, 0x54, 0x58), then a single pointer at this+0x5C. Each non-null pointer is recursively destroyed via PhysicsSubComponentDestroy (self-call at 0x00448570), freed with FreeWrapper_7bcf, and set to 0. Returns the last free result (uninitialised when no pointer was non-null).
    // LOOP: Repeat four times over dword pointer slots starting at this+0x4C (offsets 0x4C, 0x50, 0x54, 0x58), advancing by one dword each iteration. [field:this:0x0000004C, source:raw]
    // GUARD: Guard on the current slot pointer being non-null before destroy/free; null pointers are skipped. [source:raw]
    // CALL: Recursively destroy the current sub-component via PhysicsSubComponentDestroy. [callee:0x00448570]
    // CALL: Free the current slot pointer via FreeWrapper_7bcf and store its result. [callee:0x00587BCF]
    // ASSIGNMENT: Clear the current slot pointer to 0 after freeing it. [source:raw]
    // GUARD: Guard on the tail pointer at this+0x5C being non-null before destroy/free. [field:this:0x0000005C, source:raw]
    // CALL: Recursively destroy the tail sub-component via PhysicsSubComponentDestroy. [callee:0x00448570]
    // CALL: Free the tail pointer at this+0x5C via FreeWrapper_7bcf and store its result. [callee:0x00587BCF]
    // ASSIGNMENT: Clear the tail pointer field this+0x5C to 0 after freeing it. [field:this:0x0000005C, source:raw]
    // RETURN: Return the result value from the last FreeWrapper_7bcf call (uninitialised if no pointer was non-null). [source:raw]

    // Conservative worker pseudocode:
    //   int PhysicsSubComponentDestroy(LPVOID** this) {
    //     int result;
    //     LPVOID** p = this + 19;
    //     int n = 4;
    //     do {
    //       if (*p) {
    //         PhysicsSubComponentDestroy();
    //         result = FreeWrapper_7bcf(*p);
    //         *p = 0;
    //       }
    //       ++p; --n;
    //     } while (n);
    //     if (this[23]) {
    //       PhysicsSubComponentDestroy();
    //       result = FreeWrapper_7bcf(this[23]);
    //       this[23] = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The recursive destroy call at 0x00448570 has no arguments shown in the decompiled source; its parameter contract is unknown.
    // UNRESOLVED: The physics sub-component structure and its owner class are unknown.
    // UNRESOLVED: Caller PhysicsBufferFree (0x00449340) is known but the surrounding buffer layout is not established here.
}
