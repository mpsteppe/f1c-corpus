// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048B7E0
// Canonical corpus name: UtilityFunction_b7e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_b7e0_0048b7e0.c

void UnknownObject::TextEditBufferInit()
{
    // Initializes a text edit buffer: stores the caller-provided buffer pointer into this[188] (byte offset 0x2F0) and the size into this[190] (byte offset 0x2F8), then calls the virtual slot at vtable+168 (byte offset 0xA8, dword index 42) with argument 1. Performs no work when the buffer pointer is null or the size is not positive. Returns 0. Called during text field setup by UITextFieldInitialization (00470300).
    // GUARD: Guard on (a2 != 0) && (a3 > 0); when either fails the body is skipped and the function returns 0. [source:raw]
    // ASSIGNMENT: Store the buffer size: this[190] = a3. [source:raw, field:this:0x000002F8]
    // ASSIGNMENT: Store the buffer pointer: this[188] = a2. [source:raw, field:this:0x000002F0]
    // CALCULATION: Read the vtable pointer: v3 = *this. [source:raw, field:this:0x00000000]
    // CALL: Call the __stdcall virtual slot at v3 + 168 (vtable byte offset 0xA8) with argument 1, which notifies the text-edit object that its buffer was set. [source:raw, field:obj:0x000000A8]
    // CALL: Invoked by UITextFieldInitialization (00470300) during text field setup. [caller:0x00470300]
    // RETURN: Return 0 in both the guarded and unguarded paths. [function:0x0048B7E0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_48B7E0(int *this, int buffer, int size) {
    //     if (buffer && size > 0) {
    //       this[190] = size;
    //       this[188] = buffer;
    //       (*(int (__stdcall **)(int))(*this + 168))(1);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the virtual slot at vtable+168 (dword index 42) are not documented in this packet.
    // UNRESOLVED: Identity and layout of the owning text-edit object are unknown; the same offsets may differ on other object types.
}
