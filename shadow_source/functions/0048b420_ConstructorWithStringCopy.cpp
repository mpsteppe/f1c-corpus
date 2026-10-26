// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048B420
// Canonical corpus name: ConstructorWithStringCopy
// Owner: EditBoxWidget [DERIVED]
// Raw source: functions/ConstructorWithStringCopy_0048b420.c

void EditBoxWidget::ConstructorWithStringCopy()
{
    // Edit-box widget constructor. Calls the base widget initializer, assigns the edit-box vtable off_5ABED0, selects a string buffer (external a2 or an inline fallback at this+0xE6), runs sub_48B4F0, optionally applies a length bound via BoundedFieldSetter, zeroes a counter at this+0x2FC, copies the initial text a3 into two buffers when it fits the bound, and stores the option flags a5/a7 and bound value a6.
    // CALL: Call ShortComputation_5e30(this) to initialize base widget state. [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Assign the edit-box vtable off_5ABED0 to this+0x0. [field:this:0x00000000, global:0x005ABED0, source:raw]
    // CALCULATION: Select the string buffer: v8 = a2; when a2 is null fall back to the inline buffer at this + 0xE6 (this + 230). [source:raw]
    // ASSIGNMENT: Store the selected buffer pointer into this+0x2F0 (this + 752). [field:this:0x000002F0, source:raw]
    // CALL: Call sub_48B4F0(this) for further edit-box internal setup. [callee:0x0048B4F0, source:raw]
    // GUARD: When a4 > 0, call BoundedFieldSetter(a4) to apply the length bound. [callee:0x0048B8F0, source:raw]
    // ASSIGNMENT: Zero the counter/state field at this+0x2FC (this + 764). [field:this:0x000002FC, source:raw]
    // GUARD: When a3 is non-null and strlen(a3) < a4, copy a3 into the selected buffer and also into a second buffer at this + 0x1E7 (this + 487). [field:this:0x000002F0, source:raw]
    // ASSIGNMENT: Store a7 into this+0xE5 (this + 229), a5 into this+0xE2 (this + 226), and a6 into this+0x2E8 (this + 744). [field:this:0x000000E5, field:this:0x000000E2, field:this:0x000002E8, source:raw]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   int ConstructorWithStringCopy(int this, int a2, const char *a3, int a4, char a5, int a6, char a7) {
    //     ShortComputation_5e30(this);
    //     *(this) = &off_5ABED0;
    //     int v8 = a2 ? a2 : this + 230;
    //     *(this + 752) = v8;
    //     sub_48B4F0(this);
    //     if (a4 > 0) BoundedFieldSetter(a4);
    //     *(this + 764) = 0;
    //     if (a3 && strlen(a3) < a4) { strcpy(*(this + 752), a3); strcpy(this + 487, a3); }
    //     *(this + 229) = a7; *(this + 226) = a5; *(this + 744) = a6;
    //     return this;
    //   }
    // UNRESOLVED: Semantics of the byte option flags at this+0xE2 (a5) and this+0xE5 (a7); likely widget behavior flags but meanings unconfirmed.
    // UNRESOLVED: Division of roles between a4 and a6: a4 bounds the string copy and selects BoundedFieldSetter; a6 is stored at this+0x2E8 as the bound value.
    // UNRESOLVED: Purpose of duplicating the text into the second buffer at this + 0x1E7.
    // UNRESOLVED: Internals of sub_48B4F0 are not visible from this function.
}
