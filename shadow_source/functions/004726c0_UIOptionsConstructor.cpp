// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004726C0
// Canonical corpus name: UIOptionsConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIOptionsConstructor_004726c0.c

void UnknownObject::UIOptionsConstructor()
{
    // Constructor for a UI options component. Calls the base initializer ShortComputation_6d60(this, 1), installs the vtable pointer off_5A2040 at the object base, binds the data source interface dword_7CFF84 at byte offset 0x31C, then configures the options state: option count 3 at 0x324, initial/current value 1 at 0x328, boundary fields 1 at 0x32C and 0x330, component identifier 259 at 0x334, and default selection sentinel -1 (unsigned 18446744073709551615) at 0x338.
    // CALL: Call the base initialization helper ShortComputation_6d60 with this and the argument 1. [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Install the virtual method table pointer off_5A2040 at the object base (byte offset 0x0). [field:this:0x00000000, global:0x005A2040, source:raw]
    // ASSIGNMENT: Bind the data source interface address dword_7CFF84 at byte offset 0x31C. [field:this:0x0000031C, global:0x007CFF84, source:raw]
    // ASSIGNMENT: Configure the options state: option count 3 at byte offset 0x324, initial/current value 1 at 0x328, and boundary/enabled fields 1 at 0x32C and 0x330. [field:this:0x00000324, field:this:0x00000328, field:this:0x0000032C, field:this:0x00000330, source:raw]
    // ASSIGNMENT: Store the component identifier 259 at byte offset 0x334 and the default selection sentinel -1 (unsigned 18446744073709551615) at byte offset 0x338. [field:this:0x00000334, field:this:0x00000338, source:raw]
    // RETURN: Return this, the constructed options component. [function:0x004726C0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* UIOptionsConstructor(_DWORD* this) {
    //     ShortComputation_6d60(this, 1);
    //     *this = &off_5A2040;
    //     this[199] = &dword_7CFF84;
    //     this[201] = 3;
    //     this[202] = 1;
    //     this[203] = 1;
    //     this[204] = 1;
    //     this[205] = 259;
    //     this[206] = -1;
    //     return this;
    //   }
    // UNRESOLVED: The role of ShortComputation_6d60 (base-class initialization helper) is not established from this packet.
    // UNRESOLVED: The interface pointed to by dword_7CFF84 (bound at 0x31C) is not identified from raw source; the existing analysis labels it ScreenModeSetting but that is not confirmed here.
    // UNRESOLVED: The owning class behind the UI options component is unknown.
}
