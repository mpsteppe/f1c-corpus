// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046FF40
// Canonical corpus name: sub_46FF40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_46FF40_0046ff40.c

void UnknownObject::UIComponentDestructorWithFree()
{
    // UI object destructor (thiscall): installs the base UI vtable off_5A01A0, frees the child object stored at +0xEC when non-null, runs vtable sub-initialization VTableSubInit, and optionally frees the object itself when a2 bit 0 is set. Returns this.
    // ASSIGNMENT: Install the base UI vtable: *this = off_5A01A0. [field:this:0x00000000, global:0x005A01A0, source:raw]
    // GUARD: Guard on the child pointer at +0xEC being non-null before releasing it. [field:this:0x000000EC, source:raw]
    // CALL: Release the child object at +0xEC via FreeWrapper_7bcf when it is non-null. [callee:0x00587BCF, field:this:0x000000EC, source:raw]
    // CALL: Run vtable sub-initialization VTableSubInit on the object during cleanup. [callee:0x0048FEB0, source:raw]
    // GUARD: Guard on a2 bit 0 (a2 & 1); when set, the object itself is freed. [source:raw]
    // CALL: Free the object itself via FreeWrapper_7bcf when a2 bit 0 is set (final release). [callee:0x00587BCF, source:raw]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   void *UIComponentDestructorWithFree(void *this, char a2) {
    //     *(void **)this = &off_5A01A0;
    //     if (*(void **)(this + 0xEC))
    //       FreeWrapper_7bcf(*(void **)(this + 0xEC));
    //     VTableSubInit(this);
    //     if (a2 & 1)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Owner class of the destructor is unknown; +0xEC child is a generic heap object.
    // UNRESOLVED: Semantics of VTableSubInit and the pre-destruction state of off_5A01A0 are not established here.
}
