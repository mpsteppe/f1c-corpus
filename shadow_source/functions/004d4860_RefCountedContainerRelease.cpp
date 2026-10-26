// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D4860
// Canonical corpus name: sub_4D4860
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D4860_004d4860.c

void UnknownObject::RefCountedContainerRelease()
{
    // Decrements the reference count of a COM-like container. When the count reaches zero, invokes the destructor callback off_5D43C8 on the contained inner object, frees the secondary resource via FreeWrapper_7bcf, and clears both stored pointers. Sets the vtable pointer at this+0x0 to off_5ACF08 on entry.
    // ASSIGNMENT: Set vtable pointer at this+0x0 to off_5ACF08. [abi:lead, field:this:0x00000000, global:0x005ACF08, source:raw]
    // GUARD: Destructor callback off_5D43C8 is non-null before any release work. [global:0x005D43C8]
    // GUARD: Inner object pointer at this+0x4 is non-null. [field:this:0x00000004]
    // CALCULATION: Decrement reference count stored at this+0x8. [field:this:0x00000008]
    // GUARD: Release when the reference count was exactly 1 before the decrement, or the decremented value is negative. [guard:0, field:this:0x00000008]
    // CALL: Invoke destructor callback off_5D43C8 on the inner object at this+0x4. [global:0x005D43C8, field:this:0x00000004]
    // GUARD: Secondary resource pointer at this+0xC is non-null. [field:this:0x0000000C]
    // CALL: Free the secondary resource at this+0xC via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x0000000C]
    // ASSIGNMENT: Clear secondary resource pointer this+0xC to 0. [field:this:0x0000000C]
    // ASSIGNMENT: Clear inner object pointer this+0x4 to 0. [field:this:0x00000004]
    // RETURN: Return the last function-pointer / result value. [function:0x004D4860, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4D4860(void *this) {
    //     *(_DWORD*)this = (int)&off_5ACF08;
    //     if (off_5D43C8) {
    //       if (*((_DWORD*)this + 1)) {
    //         int was_one = *((_DWORD*)this + 2) == 1;
    //         int rc = *((_DWORD*)this + 2) - 1;
    //         *((_DWORD*)this + 2) = rc;
    //         if (rc < 0 || was_one) {
    //           off_5D43C8(*((_DWORD*)this + 1));
    //           if (*((_DWORD*)this + 3)) {
    //             FreeWrapper_7bcf(*((_DWORD*)this + 3));
    //             *((_DWORD*)this + 3) = 0;
    //           }
    //           *((_DWORD*)this + 1) = 0;
    //         }
    //       }
    //     }
    //   }
    // UNRESOLVED: Exact target of the indirect destructor callback off_5D43C8 is not resolved; the packet lists callee candidates 0x004D4780 / 0x004D4790 that are only reachable through it.
    // UNRESOLVED: Global off_5D43C4 is read in the surrounding object but not referenced in this function body.
    // UNRESOLVED: Element type and ownership semantics of the inner object and the secondary resource depend on the container's constructor, not visible here.
}
