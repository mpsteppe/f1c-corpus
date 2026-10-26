// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046EC10
// Canonical corpus name: ObjectNameMatchingActivation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectNameMatchingActivation_0046ec10.c

void UnknownObject::ObjectNameMatchingActivation()
{
    // Name-gated object activation. Compares the input string a2 against the first element of the global string reference array off_5C666C. On a match it reads the object vtable pointer at this+0x0, sets the activation flag byte at this+0x174 to 1, invokes the vtable callback at offset 0x2C with arguments (this, 1), and returns 1. On no match it resets the flag byte at this+0x174 to 0 and returns 0 without invoking the callback.
    // GUARD: Entry guard: name-match test strcmp(off_5C666C[0], a2) == 0. On match the activation branch runs; on mismatch the deactivation branch runs. [global:0x005C666C, source:raw]
    // ASSIGNMENT: Read the object vtable pointer from this+0x0 into v3 for the subsequent dispatch. [field:this:0x00000000, source:raw]
    // STATE_TRANSITION: Set the activation flag byte at this+0x174 to 1 (activated) on a successful name match. [field:this:0x00000174, source:raw]
    // CALL: Invoke the __thiscall vtable callback at offset 0x2C with arguments (this, 1); the callback is only reached on a successful name match. [field:obj:0x0000002C, source:raw]
    // RETURN: Return 1 to signal the object was activated. [source:raw]
    // ASSIGNMENT: Set the activation flag byte at this+0x174 to 0 (deactivated) when the name does not match. [field:this:0x00000174, source:raw]
    // RETURN: Return 0 to signal the object was not activated. [source:raw]

    // Conservative worker pseudocode:
    //   char ObjectNameMatchingActivation(_BYTE *this, const char *a2) {
    //     if (strcmp(off_5C666C[0], a2) == 0) {
    //       int v3 = *(_DWORD *)this;
    //       this[0x174] = 1;
    //       (*(void (__thiscall **)(_BYTE *, int))(v3 + 0x2C))(this, 1);
    //       return 1;
    //     } else {
    //       this[0x174] = 0;
    //       return 0;
    //     }
    //   }
    // UNRESOLVED: The identity and content of the global string array element off_5C666C[0] is not resolvable from this packet.
    // UNRESOLVED: The virtual method at vtable offset 0x2C and the meaning of its parameter 1 are unknown without the object's vtable layout.
}
