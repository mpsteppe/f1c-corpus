// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554510
// Canonical corpus name: EnumToIDMappingWithVTableNotify
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EnumToIDMappingWithVTableNotify_00554510.c

void UnknownObject::EnumToIDMappingWithVTableNotify()
{
    // Maps an enum a2 (0, 1, 2) to a state value (1, 3, 2) and dispatches it to the global object at 0x008B89A0 through its vtable entry at offset 252. Skips when a2 is -1 or equals the stored previous value this[15], otherwise records a2 into this[15] after dispatch.
    // GUARD: Skip when a2 is -1 or when a2 already equals the stored previous value this[15] (offset 0x3C). [field:this:0x0000003C, function:0x00554510, source:raw]
    // CALL: When a2 is 0, dispatch on the global object at 0x008B89A0 through vtable+252 with (*this, 14, 1). [global:0x008B89A0, field:this:0x00000000, source:raw]
    // CALL: When a2 is 1, dispatch on the global object at 0x008B89A0 through vtable+252 with (*this, 14, 3). [global:0x008B89A0, field:this:0x00000000, source:raw]
    // CALL: When a2 is 2, dispatch on the global object at 0x008B89A0 through vtable+252 with (*this, 14, 2). [global:0x008B89A0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Record the new value a2 into this[15] (offset 0x3C) after a successful dispatch. [field:this:0x0000003C, source:raw]

    // Conservative worker pseudocode:
    //   void sub_554510(int *this, int a2) {
    //     if (a2 == -1 || a2 == this[15]) return;
    //     int v = (a2 == 1) ? 3 : (a2 == 2) ? 2 : 1;
    //     ((void (__stdcall *)(int, int, int, int))vtable252_of(*(int*)0x8B89A0))(*0x8B89A0, *this, 14, v);
    //     this[15] = a2;
    //   }
    // UNRESOLVED: The meaning of state parameter 14 and of the 1/3/2 value mapping is owned by the vtable+252 handler on the global object, not by this function.
    // UNRESOLVED: this[15] (offset 0x3C) is compared and updated here but consumed elsewhere.
}
