// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00490160
// Canonical corpus name: BooleanFlagSetterVirtualCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BooleanFlagSetterVirtualCall_00490160.c

void UnknownObject::BooleanFlagSetterVirtualCall()
{
    // Boolean flag setter with a virtual dispatch: stores 0 when the input flag is non-zero and 1 when it is zero into the state field this[56], then always dispatches the vtable method at vtable offset 44 (0x2C) with argument 1 and returns its result.
    // GUARD: Branch on input flag a2: non-zero versus zero path. [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: When a2 is non-zero, clear the boolean state field this[56] (offset 0xE0) to 0. [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: When a2 is zero, set the boolean state field this[56] (offset 0xE0) to 1. [field:this:0x000000E0, source:raw]
    // CALL: Dispatch through the vtable: read the function pointer at vtable offset 44 (0x2C) from the vtable pointer at this+0x00 and invoke it as a __thiscall with argument 1. [field:this:0x00000000, field:obj:0x0000002C, source:raw]
    // RETURN: Return the result of the vtable dispatch. [source:raw]

    // Conservative worker pseudocode:
    //   int setBooleanFlag(_DWORD* this, char flag) {
    //     this[56] = flag ? 0 : 1;
    //     return ((int (__thiscall**)(_DWORD*, int))*this + 44)(this, 1);
    //   }
    // UNRESOLVED: Virtual target identity is unknown; the slot at vtable offset 44 (0x2C) has no statically resolvable callee.
    // UNRESOLVED: The semantic link between the boolean state flag and the dispatched method (UI toggle/hover state) is not confirmed.
    // UNRESOLVED: Owner object identity is unknown; the object exposes both a state field and a vtable, but its class is not identified.
}
