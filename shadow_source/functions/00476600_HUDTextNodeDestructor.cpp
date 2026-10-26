// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00476600
// Canonical corpus name: ShortComputation_6600
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_6600_00476600.c

void UnknownObject::HUDTextNodeDestructor()
{
    // Destructor for a UI text node class. Walks the base-class chain by writing three successive vtable pointers to this+0x0 (off_5A448C, off_5A4450, off_5A443C), freeing a child object after each step (offsets 0x3C, 0x30, 0x4) when non-null. Finally frees the object itself when the low bit of the deleting-destructor flag a2 is set, and returns this.
    // ASSIGNMENT: Write the first vtable pointer &off_5A448C to this+0x0 (most-derived intermediate node class). [field:this:0x00000000, global:0x005A448C, source:raw]
    // GUARD: Guard: child at offset 0x3C (this[15]) is freed only when non-null. [field:this:0x0000003C, source:raw]
    // CALL: FreeWrapper_7bcf releases the child object at offset 0x3C. [callee:0x00587BCF, field:this:0x0000003C, source:raw]
    // ASSIGNMENT: Write the second vtable pointer &off_5A4450 to this+0x0 (HUD text node class). [field:this:0x00000000, global:0x005A4450, source:raw]
    // GUARD: Guard: child at offset 0x30 (this[12]) is freed only when non-null. [field:this:0x00000030, source:raw]
    // CALL: FreeWrapper_7bcf releases the child object at offset 0x30. [callee:0x00587BCF, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Write the third vtable pointer &off_5A443C to this+0x0 (control base class). [field:this:0x00000000, global:0x005A443C, source:raw]
    // GUARD: Guard: child at offset 0x4 (this[1]) is freed only when non-null. [field:this:0x00000004, source:raw]
    // CALL: FreeWrapper_7bcf releases the child object at offset 0x4. [callee:0x00587BCF, field:this:0x00000004, source:raw]
    // GUARD: Guard: the object itself is freed only when the low bit of a2 is set (deleting-destructor flag). [source:raw]
    // CALL: FreeWrapper_7bcf releases this (the object itself) when a2 & 1 is non-zero. [callee:0x00587BCF, source:raw]
    // RETURN: Return this (the LPVOID* receiver), matching the scalar-deleting destructor pattern. [function:0x00476600, source:raw]

    // Conservative worker pseudocode:
    //   LPVOID* HUDTextNodeDestructor(LPVOID* this, char flags) {
    //     this[0] = &off_5A448C; if (this[0x3C/4]) FreeWrapper_7bcf(this[0x3C/4]);
    //     this[0] = &off_5A4450; if (this[0x30/4]) FreeWrapper_7bcf(this[0x30/4]);
    //     this[0] = &off_5A443C; if (this[0x4/4])  FreeWrapper_7bcf(this[0x4/4]);
    //     if (flags & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: The exact class hierarchy order is inferred from the vtable pointer order and is not independently confirmed from this packet
    // UNRESOLVED: Whether FreeWrapper_7bcf is a heap free or a virtual operator delete is unresolved from this packet
}
