// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9600
// Canonical corpus name: VTableSwitchDtor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableSwitchDtor_004c9600.c

void UnknownObject::VTableSwitchDtor()
{
    // Destructor that switches vtables: writes the destructor vtable pointer (off_5ACE5C) to this+0x0, invokes the destructor body VtableDestructorNull(this), restores the original vtable pointer (off_5ACE2C), then frees the object via FreeWrapper_7bcf when the release flag a2 has bit 0 set (a2 & 1). Returns this. No static caller recorded.
    // ASSIGNMENT: Write the destructor vtable pointer off_5ACE5C into this+0x0, replacing the object's live vtable during destruction. [field:this:0x00000000, global:0x005ACE5C, source:raw]
    // CALL: Call VtableDestructorNull(this) to run the object-type destructor body. [callee:0x004C9790, source:raw]
    // ASSIGNMENT: Restore the original vtable pointer off_5ACE2C into this+0x0 after the destructor body completes. [field:this:0x00000000, global:0x005ACE2C, source:raw]
    // GUARD: Guard on (a2 & 1) != 0: only when set, call FreeWrapper_7bcf(this) to release the heap allocation on final destruction. [callee:0x00587BCF, source:raw]
    // RETURN: Return this (the object pointer). [function:0x004C9600, source:raw]

    // Conservative worker pseudocode:
    //   void* VTableSwitchDtor(void* this, char a2) {
    //     *(void**)this = off_5ACE5C;
    //     VtableDestructorNull(this);
    //     *(void**)this = off_5ACE2C;
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: The concrete object type behind this vtable switch is unknown; off_5ACE5C is described as a sound-object vtable and off_5ACE2C as a plain vtable reference in the fill, both DERIVED and unproven.
    // UNRESOLVED: VtableDestructorNull (0x004C9790) may itself free or modify sub-objects; its full effect is outside this function.
    // UNRESOLVED: No static callers are recorded, so the destruction context (normal scope exit vs manual delete) is unknown.
}
