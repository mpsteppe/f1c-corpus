// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057B7D0
// Canonical corpus name: ObjectCopyInitWithVTableSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectCopyInitWithVTableSetup_0057b7d0.c

void UnknownObject::CopyInitObjectWithVTable()
{
    // Copy-init with vtable setup: invokes ObjectCopyConstructFromSource (0x00587090) to copy-construct the object from the source argument a2, then installs the static vtable pointer off_5B8A64 at this+0x0, zeroes the dword at this+0x1C (dword index 7), and returns the this pointer. Called by sub_5813E0.
    // CALL: Copy-construct this object from the source argument a2 by calling ObjectCopyConstructFromSource (0x00587090). [callee:0x00587090, source:raw]
    // ASSIGNMENT: Install the static vtable pointer off_5B8A64 as the object's vtable at this+0x0. [field:this:0x00000000, global:0x005B8A64]
    // ASSIGNMENT: Zero the dword field at this+0x1C (dword index 7). [field:this:0x0000001C]
    // CALL: Invoked by the caller sub_5813E0 as part of object construction. [caller:0x005813E0, source:raw]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* CopyInitObjectWithVTable(_DWORD* this, int a2) {
    //     ObjectCopyConstructFromSource(this, a2);
    //     *this = &off_5B8A64;
    //     this[7] = 0;
    //     return this;
    //   }
    // UNRESOLVED: The contents of the static vtable off_5B8A64 and therefore the object's runtime type are not evidenced by the packet.
    // UNRESOLVED: The contract of the copy-construct helper ObjectCopyConstructFromSource (0x00587090) and the meaning of argument a2 are outside this packet.
    // UNRESOLVED: Why the field at this+0x1C is reset to 0 after the copy is not established.
    // UNRESOLVED: The identity and owning class of the constructed object are unresolved; the packet prelabel flags this as a structural twin of ObjectInitWithVTableFieldSet at DERIVED trust.
}
