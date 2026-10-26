// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598AF5
// Canonical corpus name: ObjectConstructorWithVTableSetupAndSEH
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithVTableSetupAndSEH_00598af5.c

void UnknownObject::ObjectConstructorWithVTableSetupAndSEH()
{
    // __userpurge constructor of an istream-derived object. Registers an SEH handler via SEHHandlerInit, then conditionally (when a1[4], offset 0x10, is non-zero) installs the primary vtable (unk_5B9BC0) and the std::ios vftable on the new object and raises a construction-state flag. Always sets the istream vftable slot and calls ObjectInitWithVTableFlagSet with arguments read from offsets 0x8 and 0xC. Returns the constructed object pointer.
    // CALL: Call SEHHandlerInit() to set up the SEH handler registration for this constructor. [callee:0x0058A5D8, source:raw]
    // GUARD: Test a1[4] (offset 0x10) == 0; result v5 controls the conditional vtable-init block. [guard:0, field:this:0x00000010]
    // ASSIGNMENT: Write v4 into *(a1 - 5) and 0 into *(a1 - 4); the second write is re-set to 1 inside the conditional block, acting as a construction-state flag. [function:0x00598AF5, source:raw]
    // ASSIGNMENT: When a1[4] != 0: install the primary vtable pointer unk_5B9BC0 into *v4. [global:0x005B9BC0, guard:0]
    // ASSIGNMENT: When a1[4] != 0: clear v4[11], install the std::ios vftable into v4[2], set *(a1 - 4) to 1, and clear *(a1 - 1). [global:0x005B9BB4, guard:0]
    // ASSIGNMENT: Clear v4[1] unconditionally after the conditional block. [function:0x00598AF5, source:raw]
    // CALCULATION: Read v9 from a1[3] (offset 0xC) and v8 from a1[2] (offset 0x8) to forward as constructor arguments. [field:this:0x00000008, field:this:0x0000000C]
    // ASSIGNMENT: Install the std::istream vftable at the vtable-relative slot v4 + *( *v4 + 4 ). [global:0x005B9BA4]
    // CALL: Call ObjectInitWithVTableFlagSet(v8, v9) to initialize the object sub-component with the vtable flag. [callee:0x005993EB, field:this:0x00000008, field:this:0x0000000C]
    // RETURN: Return v6, the constructed object pointer. [function:0x00598AF5]

    // Conservative worker pseudocode:
    //   _DWORD *ObjectConstructorWithVTableSetupAndSEH(_DWORD *a1, int a2, int a3, int a4) {
    //     SEHHandlerInit();
    //     bool flag = (a1[4] == 0);
    //     _DWORD *obj = (ecx);
    //     *(a1 - 5) = obj;
    //     *(a1 - 4) = 0;
    //     if (!flag) {
    //       *obj = &unk_5B9BC0;
    //       obj[11] = 0;
    //       obj[2] = &std::ios::vftable;
    //       *(a1 - 4) = 1;
    //       *(a1 - 1) = 0;
    //     }
    //     obj[1] = 0;
    //     *(obj + *( *obj + 4 )) = &std::istream::vftable;
    //     ObjectInitWithVTableFlagSet(a1[2], a1[3]);
    //     return obj;
    //   }
    // UNRESOLVED: global 0x0059D286 (loc_59D286) is referenced as an SEH exception-handling type descriptor but does not appear in the decompiled body text.
    // UNRESOLVED: The relationship between a1 (ebp-based) and the ecx-derived v4 is not fully resolved; several writes target a1-relative slots (a1-5, a1-4, a1-1) whose owning fields have no packet-level evidence.
    // UNRESOLVED: The condition is inverted in the fill prose vs the raw source (guard fires when a1[4] != 0); raw source wording is followed here.
}
