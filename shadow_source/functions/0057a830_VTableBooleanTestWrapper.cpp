// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A830
// Canonical corpus name: VTableBooleanTestWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableBooleanTestWrapper_0057a830.c

void UnknownObject::VTableBooleanTestWrapper()
{
    // COM-style boolean-inversion test. Reads the interface object obj from *this (this+0x0), loads the vtable base from *obj (obj+0x0), calls the __thiscall method at vtable slot +156 (0x9C) on obj with a2 and a3 forwarded, and returns TRUE exactly when that predicate method returns 0.
    // CALCULATION: Read the interface object pointer obj from *this (this+0x0) and the vtable base from *obj (obj+0x0) [source:raw, field:this:0x00000000, field:obj:0x00000000]
    // CALL: Dispatch the __thiscall virtual method at vtable slot +156 (0x9C) on obj, forwarding a2 and a3 as arguments [source:raw, field:*(obj+0x0):0x0000009C]
    // RETURN: Return the inverted result: TRUE when the dispatched predicate returns 0, FALSE otherwise [source:raw]
    // CALL: Invoked by ShortComputation_23b0 (0x004623B0) as a single-slot virtual predicate test [caller:0x004623B0, abi:lead]

    // Conservative worker pseudocode:
    //   BOOL VTableBooleanTestWrapper(void *this, int a2, int a3) {
    //     void *obj = *(void **)this;
    //     return ((unsigned __int8 (__thiscall *)(void *, int, int))(*(int *)obj + 156))(obj, a2, a3) == 0;
    //   }
    // UNRESOLVED: The interface contract behind the COM-style handle and the identity of the method at vtable slot +156 (0x9C, index 39) are unknown
    // UNRESOLVED: The meaning of a2 and a3 for the predicate is unknown
}
