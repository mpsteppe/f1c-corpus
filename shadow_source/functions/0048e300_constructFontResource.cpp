// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E300
// Canonical corpus name: ShortComputation_e300
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_e300_0048e300.c

void UnknownObject::constructFontResource()
{
    // Constructor/initializer for a UI widget object: calls base ConstructorWithByteParams with zero byte args, zeroes fields at 0xFC (this[63]) and 0xE4 (this[57]), sets field at 0x100 (this[64]) to -1, installs vtable off_5AC490 at offset 0x0, and resets the string buffer via StringCopyWithBufferRealloc(0). Returns the object pointer. Existing analysis labels this a font resource constructor.
    // CALL: Call ConstructorWithByteParams(this, 0, 0) for base widget initialization. [callee:0x00487220]
    // ASSIGNMENT: Set this[63] (offset 0xFC) to 0. [field:this:0x000000FC]
    // ASSIGNMENT: Set this[64] (offset 0x100) to -1 (packet literal 18446744073709551615). [field:this:0x00000100]
    // ASSIGNMENT: Install vtable pointer: *this (offset 0x0) = &off_5AC490. [field:this:0x00000000, global:0x005AC490]
    // ASSIGNMENT: Set this[57] (offset 0xE4) to 0. [field:this:0x000000E4]
    // CALL: Call StringCopyWithBufferRealloc(0) to reset/clear the string buffer. [callee:0x00566650]
    // RETURN: Return the object pointer. [function:0x0048E300]

    // Conservative worker pseudocode:
    //   _DWORD *constructFontResource(_DWORD *this) {
    //     ConstructorWithByteParams(this, 0, 0);
    //     this[63] = 0; this[64] = -1;
    //     *this = &off_5AC490;
    //     this[57] = 0;
    //     StringCopyWithBufferRealloc(0);
    //     return this;
    //   }
    // UNRESOLVED: Owning class is unconfirmed; font-resource label is DERIVED from existing analysis.
    // UNRESOLVED: Semantics of fields at 0xE4 (this[57]), 0xFC (this[63]) and 0x100 (this[64]) are unknown.
    // UNRESOLVED: Identity of vtable off_5AC490 and its derived vtable name are not established.
}
