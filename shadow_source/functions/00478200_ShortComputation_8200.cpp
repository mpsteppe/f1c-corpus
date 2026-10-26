// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478200
// Canonical corpus name: ShortComputation_8200
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_8200_00478200.c

void UnknownObject::ShortComputation_8200()
{
    // Indirect factory-style store: calls a virtual method (vtable offset 28) on the object referenced by global dword_7CD8C0 passing literal argument 22; if the returned pointer is non-null it is stored into this[56] (offset 0xE0), then returns 0.
    // CALL: Call the virtual method at vtable offset 28 on the object pointed to by dword_7CD8C0, passing integer argument 22; result kept in v2. [global:0x007CD8C0, source:raw]
    // GUARD: Conditional: only proceed when the returned pointer v2 is non-null. [source:raw, function:0x00478200]
    // ASSIGNMENT: Store the returned pointer v2 into this[56] (offset 0xE0) when the guard passes. [field:this:0x000000E0, source:raw]
    // RETURN: Return integer constant 0 regardless of which branch was taken. [source:raw, function:0x00478200]

    // Conservative worker pseudocode:
    //   int ShortComputation_8200(_DWORD *this) {
    //     int v2 = (*(int (__thiscall **)(int,int))(*(_DWORD*)dword_7CD8C0 + 28))(dword_7CD8C0, 22);
    //     if (v2)
    //       this[56] = v2;
    //     return 0;
    //   }
    // UNRESOLVED: Virtual call target (vtable offset 28 on the object behind dword_7CD8C0) is not resolved; neither the source object type nor the produced object stored at this->0xE0 is identified.
    // UNRESOLVED: Semantic meaning of literal argument 22 and of field this->0xE0 is not established by packet evidence.
}
