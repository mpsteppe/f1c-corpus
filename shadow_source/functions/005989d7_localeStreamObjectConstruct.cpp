// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005989D7
// Canonical corpus name: LocaleObjectConstructorWithVtableInit
// Owner: LocaleStreamObject [DERIVED]
// Raw source: functions/LocaleObjectConstructorWithVtableInit_005989d7.c

void LocaleStreamObject::localeStreamObjectConstruct()
{
    // Inlined MSVC locale/stream object construction. Registers an SEH handler, conditionally installs a streambuf vtable and the std::ios vtable plus a construction-completed flag, writes the std::ostream vtable into the sub-object slot derived from the installed vtable, and conditionally initializes a sub-object via ObjectInitWithVTableFlagSet. Returns the constructed object pointer.
    // CALL: SEH handler registration for the constructor frame. [callee:0x0058A5D8]
    // GUARD: Read the flag at this+0x14 (a1+20); if zero, the stream sub-object initialization block is skipped. [guard:1, field:this:0x00000014]
    // ASSIGNMENT: Store the constructed object pointer into the stack slot at a1-20 and clear the construction-completed flag at a1-16. [field:this:0x00000014]
    // ASSIGNMENT: In the non-zero branch: set *v5 to the streambuf vtable (unk_5B9BB8), zero v5[10], set v5[1] to the std::ios vtable, set the construction-completed flag at a1-16 to 1, and zero the slot at a1-4. [global:0x005B9BB8, global:0x005B9BB4]
    // ASSIGNMENT: Write the std::ostream vtable into the sub-object slot located by the embedded offset read from the installed vtable (v5 + *(*(v5)+4)). [global:0x005B9BAC]
    // GUARD: Read the flag at this+0x10 (a1+16); if zero, the sub-object initialization call is skipped. [guard:0, field:this:0x00000010]
    // CALL: In the non-zero branch: call ObjectInitWithVTableFlagSet with this+0x8 and this+0xC as arguments. [callee:0x005993EB, field:this:0x00000008, field:this:0x0000000C]
    // RETURN: Return the constructed object pointer (v7). [function:0x005989D7]

    // Conservative worker pseudocode:
    //   SEHHandlerInit();
    //   store v5 at (a1-20); flag(a1-16) = 0;
    //   if (this+0x14 != 0) { *v5 = &unk_5B9BB8; v5[10] = 0; v5[1] = &std::ios::vftable; flag(a1-16) = 1; (a1-4) = 0; }
    //   write &std::ostream::vftable at v5 + *(*(v5)+4);
    //   if (this+0x10 != 0) ObjectInitWithVTableFlagSet(this+0x8, this+0xC);
    //   return v7;
    // UNRESOLVED: The exception-handling type descriptor loc_59D23E participates in the SEH frame but is not referenced by name in the visible constructor body.
    // UNRESOLVED: The a1-relative stack slots (a1-20, a1-16, a1-4) belong to the inlined caller frame; the exact object layout they describe is not recoverable from this function alone.
}
