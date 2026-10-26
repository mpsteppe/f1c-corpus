// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048EBD0
// Canonical corpus name: UIDimensionCapture
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIDimensionCapture_0048ebd0.c

void UnknownObject::UIDimensionCapture()
{
    // UI element dimension capture: queries eight child widgets through two indexed accessor families (sub_487060 and sub_4870E0) and stores the sixteen resulting dimension values into this[68]..this[83]; applies fallback defaults from this[1..4] when four of the computed dimensions are negative; resets this[93], issues a virtual layout call through vtable slot 16 passing this+0x104, resolves three widget dimensions through ConditionalDelegation_6460 into this[57..59], then calls UIWindowTextSetup and StringCopyWithBufferRealloc(byte_5EA438), clears this[90] and returns 0.
    // CALL: Store eight dimension values: this[68..75] = sub_487060(this, index) for index 0..7 (fields at +0x110 through +0x12C). [callee:0x00487060, field:this:0x00000110, field:this:0x00000114, field:this:0x00000118, field:this:0x0000011C, field:this:0x00000120, field:this:0x00000124, field:this:0x00000128, field:this:0x0000012C, source:raw]
    // CALL: Store eight dimension values: this[76..83] = sub_4870E0(this, index) for index 0..7 (fields at +0x130 through +0x14C). [callee:0x004870E0, field:this:0x00000130, field:this:0x00000134, field:this:0x00000138, field:this:0x0000013C, field:this:0x00000140, field:this:0x00000144, field:this:0x00000148, field:this:0x0000014C, source:raw]
    // GUARD: If this[80] (+0x140) is negative, replace it with the default this[1] (+0x4). [guard:2, field:this:0x00000140, field:this:0x00000004]
    // GUARD: If this[72] (+0x120) is negative, replace it with the default this[3] (+0xC). [guard:0, field:this:0x00000120, field:this:0x0000000C]
    // GUARD: If this[81] (+0x144) is negative, replace it with the default this[2] (+0x8). [guard:3, field:this:0x00000144, field:this:0x00000008]
    // GUARD: If this[73] (+0x124) is negative, replace it with the default this[4] (+0x10). [guard:1, field:this:0x00000124, field:this:0x00000010]
    // ASSIGNMENT: Reset this[93] (+0x174) to 0 before the virtual layout call. [field:this:0x00000174, source:raw]
    // CALL: Indirect virtual call through the vtable read from this+0x0 at byte offset 64, passing this and this[65] (+0x104) as the argument; this is the layout computation step. [field:this:0x00000000, field:this:0x00000104, source:raw]
    // CALL: ConditionalDelegation_6460(this, 6); when the returned object is non-null, dereference it at +32 and, if that pointer is non-null, copy the dword at +12 into this[57] (+0xE4). The accessor traverses the child object graph rooted at obj+0x40. [callee:0x00486460, field:obj:0x00000040, field:this:0x000000E4]
    // CALL: ConditionalDelegation_6460(this, 7); when the returned object is non-null, dereference it at +32 and, if that pointer is non-null, copy the dword at +12 into this[58] (+0xE8). [callee:0x00486460, field:obj:0x00000040, field:this:0x000000E8]
    // CALL: ConditionalDelegation_6460(this, 5); when the returned object is non-null, dereference it at +32 and, if that pointer is non-null, copy the dword at +12 into this[59] (+0xEC). [callee:0x00486460, field:obj:0x00000040, field:this:0x000000EC]
    // CALL: Call UIWindowTextSetup(this) to finalize the window text fields. [callee:0x0048F9F0]
    // CALL: Call StringCopyWithBufferRealloc(byte_5EA438) against the global text buffer. [callee:0x00566650, global:0x005EA438]
    // ASSIGNMENT: Clear this[90] (+0x168) to 0. [field:this:0x00000168, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_48EBD0(int* this) {
    //     for (int i = 0; i < 8; ++i) { this[68 + i] = sub_487060(this, i); this[76 + i] = sub_4870E0(this, i); }
    //     if (this[80] < 0) this[80] = this[1];
    //     if (this[72] < 0) this[72] = this[3];
    //     if (this[81] < 0) this[81] = this[2];
    //     if (this[73] < 0) this[73] = this[4];
    //     this[93] = 0;
    //     (this->vtable[16])(this, this[65]);
    //     setDimFromDelegate(this, 6, 57);
    //     setDimFromDelegate(this, 7, 58);
    //     setDimFromDelegate(this, 5, 59);
    //     UIWindowTextSetup(this);
    //     StringCopyWithBufferRealloc(byte_5EA438);
    //     this[90] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Difference in meaning between the two accessor families sub_487060 and sub_4870E0 (only index and result fields are visible here).
    // UNRESOLVED: Purpose and semantic effect of the virtual call at vtable byte offset 64 on this + this[65].
    // UNRESOLVED: Meaning of the +32 dereference and +12 dword read chain inside the ConditionalDelegation_6460 results.
    // UNRESOLVED: What byte_5EA438 holds and which UI text it carries.
    // UNRESOLVED: Semantics of the default fallback values at this[1..4].
    // UNRESOLVED: Which widget or layout the captured dimension array this[68..83] feeds into.
}
