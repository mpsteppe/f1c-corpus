// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004761E0
// Canonical corpus name: MultiPhaseDestructorWithVTableSwitching
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiPhaseDestructorWithVTableSwitching_004761e0.c

void UnknownObject::MultiPhaseDestructorWithVTableSwitching()
{
    // Multi-phase destructor for a UI filter object: transitions the vtable pointer through three vtables (off_5A4478, off_5A4450, off_5A443C), freeing an owned child pointer at each phase when it is non-null (this[16] at 0x40, this[12] at 0x30, this[1] at 0x4), then frees the this object when the scalar-deleting flag (a2 & 1) is set and returns this.
    // ASSIGNMENT: Set vtable *this to &off_5A4478 (phase 1 vtable) [field:this:0x00000000, global:0x005A4478, source:raw]
    // GUARD: If this[16] (offset 0x40) child pointer is non-null [field:this:0x00000040, source:raw]
    // CALL: FreeWrapper_7bcf (0x00587BCF) frees this[16] (offset 0x40) [callee:0x00587BCF, field:this:0x00000040, source:raw]
    // ASSIGNMENT: Set vtable *this to &off_5A4450 (phase 2 vtable) [field:this:0x00000000, global:0x005A4450, source:raw]
    // GUARD: If this[12] (offset 0x30) child pointer is non-null [field:this:0x00000030, source:raw]
    // CALL: FreeWrapper_7bcf (0x00587BCF) frees this[12] (offset 0x30) [callee:0x00587BCF, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Set vtable *this to &off_5A443C (phase 3 vtable) [field:this:0x00000000, global:0x005A443C, source:raw]
    // GUARD: If this[1] (offset 0x4) owned pointer is non-null [field:this:0x00000004, source:raw]
    // CALL: FreeWrapper_7bcf (0x00587BCF) frees this[1] (offset 0x4) [callee:0x00587BCF, field:this:0x00000004, source:raw]
    // GUARD: If the destructor flag (a2 & 1) is set (scalar deleting destructor path) [source:raw]
    // CALL: FreeWrapper_7bcf (0x00587BCF) frees the this object when the flag is set [callee:0x00587BCF, source:raw]
    // RETURN: Return the this pointer [source:raw]

    // Conservative worker pseudocode:
    //   this->vtable = &off_5A4478;
    //   if (this[16]) FreeWrapper_7bcf(this[16]);
    //   this->vtable = &off_5A4450;
    //   if (this[12]) FreeWrapper_7bcf(this[12]);
    //   this->vtable = &off_5A443C;
    //   if (this[1]) FreeWrapper_7bcf(this[1]);
    //   if (a2 & 1) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: Class identity and role of the three vtables (off_5A4478, off_5A4450, off_5A443C) not established.
    // UNRESOLVED: Semantics of the owned child pointers this[16], this[12], this[1] not grounded.
}
