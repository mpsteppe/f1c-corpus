// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048EAA0
// Canonical corpus name: LargeConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LargeConstructor_0048eaa0.c

void UnknownObject::ConstructLargeObject()
{
    // Large __thiscall constructor: delegates to the base-class initializer ShortComputation_5e30 (0x00485E30), zero-initializes a wide block of dword/byte fields, installs the vtable off_5A4550 at this+0x0, then sets a small set of range/default fields (1, 4, 0.5f, -1, 10, byte 1) before returning this. Matches a widget-style object whose base init and vtable imply a derived class.
    // CALL: Invoke the base-class initializer ShortComputation_5e30 (0x00485E30) on this. [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Zero-initialize the dword block this+0xE0..0xFC (a1+224..252). [field:this:0x000000E0, field:this:0x000000E4, field:this:0x000000E8, field:this:0x000000EC, field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, field:this:0x000000FC, source:raw]
    // ASSIGNMENT: Zero-initialize the dword block this+0x10C..0x16C. [field:this:0x0000010C, field:this:0x00000110, field:this:0x00000114, field:this:0x00000118, field:this:0x0000011C, field:this:0x00000120, field:this:0x00000124, field:this:0x00000128, field:this:0x0000012C, field:this:0x00000130, field:this:0x00000134, field:this:0x00000138, field:this:0x0000013C, field:this:0x00000140, field:this:0x00000144, field:this:0x00000148, field:this:0x0000014C, field:this:0x00000150, field:this:0x00000154, field:this:0x00000158, field:this:0x0000015C, field:this:0x00000160, field:this:0x00000164, field:this:0x00000168, field:this:0x0000016C, source:raw]
    // ASSIGNMENT: Zero-initialize the dword this+0x174 and the bytes this+0x17D/0x17E/0x17F. [field:this:0x00000174, field:this:0x0000017D, field:this:0x0000017E, field:this:0x0000017F, source:raw]
    // ASSIGNMENT: Install the vtable pointer off_5A4550 (0x005A4550) at this+0x0. [field:this:0x00000000, global:0x005A4550, source:raw]
    // ASSIGNMENT: Set this+0x100 to 1 and this+0x104 to 4 (numeric range minimum/maximum). [field:this:0x00000100, field:this:0x00000104, source:raw]
    // ASSIGNMENT: Set this+0x108 to 1056964608 (float 0.5), the initial/default value of the range. [field:this:0x00000108, source:raw]
    // ASSIGNMENT: Set this+0x170 to -1 (preserved literal 18446744073709551615 as unsigned), an invalid/unset id marker. [field:this:0x00000170, source:raw]
    // ASSIGNMENT: Set this+0x178 to 10 (step count) and the byte this+0x17C to 1 (enabled/active flag). [field:this:0x00000178, field:this:0x0000017C, source:raw]
    // RETURN: Return this, following the constructor convention. [source:raw]
    // CALL: Called by ShortComputation_66f0 (0x004766F0), sub_477410 (0x00477410), SeasonDatabaseObjectFactory (0x0047F440) and sub_493FC0 (0x00493FC0) to construct instances. [caller:0x004766F0, caller:0x00477410, caller:0x0047F440, caller:0x00493FC0, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall ConstructLargeObject(int this) {
    //     ShortComputation_5e30((DWORD*)this);
    //     for (int off = 0xE0; off <= 0x16C; off += 4)
    //       if (off != 0x100 && off != 0x104 && off != 0x108 && off != 0x170)
    //         *(DWORD*)(this + off) = 0;
    //     *(DWORD*)(this + 0x174) = 0;
    //     *(BYTE*)(this + 0x17D) = 0;
    //     *(BYTE*)(this + 0x17E) = 0;
    //     *(BYTE*)(this + 0x17F) = 0;
    //     *(DWORD*)this = &off_5A4550;           // vtable
    //     *(DWORD*)(this + 0x100) = 1;           // range minimum
    //     *(DWORD*)(this + 0x104) = 4;           // range maximum
    //     *(DWORD*)(this + 0x108) = 1056964608;  // 0.5f default
    //     *(DWORD*)(this + 0x170) = -1;
    //     *(DWORD*)(this + 0x178) = 10;
    //     *(BYTE*)(this + 0x17C) = 1;
    //     return this;
    //   }
    // UNRESOLVED: Semantics of the range-like fields 0x100/0x104/0x108 and 0x178 are inferred (existing analysis proposes a UI slider range 1..4 at 0.5 with 10 steps) but not statically confirmed.
    // UNRESOLVED: Object type and class implied by the vtable off_5A4550 and the base init ShortComputation_5e30 are not established here.
}
