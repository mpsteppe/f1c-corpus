// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046FE80
// Canonical corpus name: SessionFlagPointerSelector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionFlagPointerSelector_0046fe80.c

void UnknownObject::SessionFlagPointerSelector()
{
    // UI component constructor: runs the base component init (UIComponentInit5), zeroes field 0xEC, sets field 0xF0 to -1, installs the vtable off_5A01A0 at offset 0x0, then selects one of six session-state pointers by index a2 (1-6) into field 0xE8, or null for out-of-range. Returns the initialized object.
    // CALL: UIComponentInit5(this): base UI component initialization before the object-specific fields are set. [callee:0x0048FE60]
    // ASSIGNMENT: this[59] (offset 0xEC) = 0: clears the flag field. [field:this:0x000000EC]
    // ASSIGNMENT: this[60] (offset 0xF0) = -1: initializes the field to all-bits-set (-1). [field:this:0x000000F0]
    // ASSIGNMENT: *this (offset 0x0) = &off_5A01A0: installs the object vtable pointer. [field:this:0x00000000, global:0x005A01A0]
    // GUARD: Switch on a2 dispatching through jump table jpt_46FEAA to select the session-state pointer. [source:raw, global:0x0046FF20]
    // ASSIGNMENT: case 1: this[58] (offset 0xE8) = &unk_7CEB64. [field:this:0x000000E8, global:0x007CEB64]
    // ASSIGNMENT: case 2: this[58] (offset 0xE8) = &unk_7CEB7C. [field:this:0x000000E8, global:0x007CEB7C]
    // ASSIGNMENT: case 3: this[58] (offset 0xE8) = &unk_7CEB94. [field:this:0x000000E8, global:0x007CEB94]
    // ASSIGNMENT: case 4: this[58] (offset 0xE8) = &unk_7CEBAC. [field:this:0x000000E8, global:0x007CEBAC]
    // ASSIGNMENT: case 5: this[58] (offset 0xE8) = &byte_7CEBC4. [field:this:0x000000E8, global:0x007CEBC4]
    // ASSIGNMENT: case 6: this[58] (offset 0xE8) = &unk_7CEBDC. [field:this:0x000000E8, global:0x007CEBDC]
    // ASSIGNMENT: default: this[58] (offset 0xE8) = 0 for out-of-range a2. [field:this:0x000000E8]
    // RETURN: Return the initialized object pointer. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* SessionFlagPointerSelector(_DWORD* this, int a2) {
    //     UIComponentInit5(this);
    //     this[59] = 0; this[60] = -1;
    //     *this = &off_5A01A0;
    //     switch (a2) {
    //       case 1: this[58] = &unk_7CEB64; break;
    //       case 2: this[58] = &unk_7CEB7C; break;
    //       case 3: this[58] = &unk_7CEB94; break;
    //       case 4: this[58] = &unk_7CEBAC; break;
    //       case 5: this[58] = &byte_7CEBC4; break;
    //       case 6: this[58] = &unk_7CEBDC; break;
    //       default: this[58] = 0; break;
    //     }
    //     return this;
    //   }
    // UNRESOLVED: The six target globals unk_7CEB64 .. unk_7CEBDC are opaque session-state locations; their layout and role (flag byte vs struct) are not evidenced.
    // UNRESOLVED: Offsets 0xE8/0xEC/0xF0 map from this[58]/[59]/[60]; only the this-relative layout is known, not the enclosing class.
}
