// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478BC0
// Canonical corpus name: FunctionCallWrapper_8bc0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_8bc0_00478bc0.c

void UnknownObject::ConstructorWithVTable_5A4970()
{
    // Constructor-like function: calls sub-constructor Constructor_e070 (0x0048E070) on this, then initializes fields at this+0xF0 (0), this+0xF4 (18446744073709551615, source-level -1 / all-unlimited marker), and this+0xF8 (0), installs the vtable pointer off_5A4970 (0x005A4970) at this+0x0, and returns this.
    // CALL: Call sub-constructor Constructor_e070 (0x0048E070) on this before field initialization; ABI states the function forwards to another function with no additional work. [callee:0x0048E070, function:0x00478BC0, source:raw, abi:lead]
    // ASSIGNMENT: Initialize this+0xF0 (this[60]) to 0. [field:this:0x000000F0]
    // ASSIGNMENT: Initialize this+0xF4 (this[61]) to 18446744073709551615, the packet's unsigned spelling of source-level -1, asserted by existing analysis as a max/limit (all/unlimited) marker. [field:this:0x000000F4]
    // ASSIGNMENT: Initialize this+0xF8 (this[62]) to 0. [field:this:0x000000F8]
    // ASSIGNMENT: Install vtable: assign the vtable pointer off_5A4970 (0x005A4970) to *this (this+0x0). [field:this:0x00000000, global:0x005A4970]
    // RETURN: Return this, the constructed object pointer. [function:0x00478BC0, source:raw]

    // Conservative worker pseudocode:
    //   // Constructor for an object whose vtable is off_5A4970.
    //   void* ConstructorWithVTable_5A4970(void* this) {
    //     Constructor_e070(this);
    //     ((unsigned int*)this)[60] = 0;
    //     ((unsigned int*)this)[61] = 18446744073709551615; // packet spelling of -1 (this[61] = -1 in raw source)
    //     ((unsigned int*)this)[62] = 0;
    //     *((void**)this) = &off_5A4970;
    //     return this;
    //   }
    // UNRESOLVED: Semantic purpose of fields this+0xF0, this+0xF4, this+0xF8 is not independently proven; existing analysis proposes counter/limit/counter roles, which is DERIVED prose.
    // UNRESOLVED: The object type owning this constructor is unknown (owner retained as UnknownObject/UNKNOWN).
    // UNRESOLVED: off_5A4970 is read as a vtable pointer from existing analysis; that role is inferred from the install-at-this+0x0 pattern, not independently proven.
}
