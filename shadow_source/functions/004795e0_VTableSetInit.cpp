// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004795E0
// Canonical corpus name: VTableSetInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableSetInit_004795e0.c

void UnknownObject::VTableSetInit()
{
    // UI component constructor helper: forwards this, a2 and a3 to UIConstructorWithVTableParams (0048D3A0) as the base UI constructor, then assigns the UI component vtable pointer off_5A4AD8 to this+0x0 and returns this. Called by UISliderConstructor, ObjectInit and sub_479700 to finish component setup after base construction.
    // CALL: Delegate base construction: UIConstructorWithVTableParams((int)this, a2, a3) initializes the base UI component with the given parameters. [callee:0x0048D3A0, source:raw]
    // ASSIGNMENT: Set the vtable pointer: *this = &off_5A4AD8 (this+0x0 = off_5A4AD8), selecting this component's vtable. [field:this:0x00000000, global:0x005A4AD8, source:raw]
    // RETURN: Return the initialized this pointer. [source:raw]
    // CALL: Invoked by UISliderConstructor (00479690), ObjectInit (004796C0) and sub_479700 (00479700) to install the shared UI component vtable after each caller's own base construction. [caller:0x00479690, caller:0x004796C0, caller:0x00479700, source:raw]

    // Conservative worker pseudocode:
    //   UIConstructorWithVTableParams(this, a2, a3);
    //   *this = &off_5A4AD8;
    //   return this;
    // UNRESOLVED: The exact type of the UI component object and the meaning of parameters a2, a3 (owned by the base UIConstructorWithVTableParams) are not documented in this function.
}
