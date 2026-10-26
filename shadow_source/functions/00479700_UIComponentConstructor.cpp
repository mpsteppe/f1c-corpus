// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479700
// Canonical corpus name: sub_479700
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_479700_00479700.c

void UnknownObject::UIComponentConstructor()
{
    // UI component constructor: delegates to the base UI initializer VTableSetInit(this, 0, 1065353216 = 1.0f), overrides the vtable pointer at this+0x0 with the UI-component vtable global off_5A4D00, and returns the initialized this pointer.
    // CALL: Base UI component initialization: VTableSetInit(this, 0, 1065353216) runs before the vtable is installed, using a zero parameter and float 1.0 (1065353216). [callee:0x004795E0, source:raw]
    // ASSIGNMENT: Install the vtable pointer: *this = &off_5A4D00, writing the UI-component vtable global into this+0x0 and overriding whatever VTableSetInit installed. [field:this:0x00000000, global:0x005A4D00, source:raw]
    // RETURN: Return the constructed this pointer. [function:0x00479700, source:raw]

    // Conservative worker pseudocode:
    //   UIComponentConstructor(this) {
    //     VTableSetInit(this, 0, 1065353216);
    //     *this = &off_5A4D00;
    //     return this;
    //   }
    // UNRESOLVED: The meaning of the two parameters forwarded to VTableSetInit (0 and float 1.0) is owned by the base initializer and not documented by this packet.
    // UNRESOLVED: The concrete type of the UI component that owns the off_5A4D00 vtable is not evidenced.
}
