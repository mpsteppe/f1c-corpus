// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FD80
// Canonical corpus name: DestructorWithConditionalFree_fd80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithConditionalFree_fd80_0048fd80.c

void UnknownObject::DestructorWithConditionalFree()
{
    // Destructor for a UI control object. Restores the vtable pointer, conditionally frees a child resource pointer when it is non-null, then frees the object itself when the low bit of the destruction flag is set.
    // ASSIGNMENT: Set *this = &off_5A443C (restore vtable pointer before cleanup). [field:this:0x00000000, global:0x005A443C]
    // GUARD: If this[1] (offset 0x4) is non-null, enter the child-resource free path. [field:this:0x00000004]
    // CALL: FreeWrapper_7bcf(this[1]) frees the child resource pointed to at offset 0x4. [callee:0x00587BCF, field:this:0x00000004]
    // GUARD: If (a2 & 1) is set, the object itself is freed. [function:0x0048FD80]
    // CALL: FreeWrapper_7bcf(this) frees the object itself. [callee:0x00587BCF, function:0x0048FD80]
    // RETURN: Return this. [function:0x0048FD80]

    // Conservative worker pseudocode:
    //   this->vtable = &off_5A443C;
    //   if (this->child) FreeWrapper_7bcf(this->child);
    //   if (a2 & 1) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: The exact class owning this destructor is not established; off_5A443C is only labeled VTable_ControlBase (DERIVED).
    // UNRESOLVED: Whether the low bit of a2 has call-site meaning (e.g. delete-vs-destroy flag) is unknown.
}
