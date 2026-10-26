// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9360
// Canonical corpus name: ObjectVTableSwitchDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectVTableSwitchDestructor_004c9360.c

void UnknownObject::ObjectVTableSwitchDestructor()
{
    // Deleting-style destructor with vtable switching: writes the destructor-phase vtable off_5ACE4C into this[0], calls the destructor body sub_4C94D0(this), restores the base vtable off_5ACE2C, then, when a2 & 1 is set (deleting-destructor flag), releases the object's own heap block via FreeWrapper_7bcf. Returns the this pointer unchanged.
    // ASSIGNMENT: Write the destructor-phase vtable off_5ACE4C into this[0] so virtual calls during destruction dispatch to the destructor variant. [global:0x005ACE4C, field:this:0x00000000, source:raw]
    // CALL: Invoke the destructor body sub_4C94D0(this). [callee:0x004C94D0, source:raw]
    // ASSIGNMENT: Restore the base vtable off_5ACE2C into this[0]. [global:0x005ACE2C, field:this:0x00000000, source:raw]
    // GUARD: When a2 & 1 is nonzero (deleting-destructor flag), the object's own heap block is freed; otherwise only the destructor body runs. [function:0x004C9360, source:raw]
    // CALL: FreeWrapper_7bcf(this) releases the object's heap allocation on final release. [callee:0x00587BCF, source:raw]
    // RETURN: Return the this pointer unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *ObjectVTableSwitchDestructor(_DWORD *this, char a2) {
    //       *this = &off_5ACE4C;      // destructor-phase vtable
    //       sub_4C94D0(this);         // destructor body
    //       *this = &off_5ACE2C;      // restore base vtable
    //       if (a2 & 1)
    //           FreeWrapper_7bcf(this); // final release frees self
    //       return this;
    //   }
    // UNRESOLVED: The concrete object type owning off_5ACE2C/off_5ACE4C is unknown; the two vtables and the destructor body sub_4C94D0 are unresolved.
    // UNRESOLVED: The semantic of a2 beyond bit 0 (deleting-destructor flag) is not confirmed by the raw source.
    // UNRESOLVED: No static callers exist for this function in the packet.
}
