// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004780B0
// Canonical corpus name: PhysicsVehicleObjectReferenceStore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsVehicleObjectReferenceStore_004780b0.c

void UnknownObject::PhysicsVehicleObjectReferenceStore()
{
    // Indirect factory-style store: calls a virtual method (vtable offset 28) on the object referenced by global dword_7CD8C0 passing literal argument 21; if the returned pointer is non-null it is stored into this[56] (offset 0xE0), then returns 0.
    // CALL: Call the virtual method at vtable offset 28 on the object pointed to by dword_7CD8C0, passing integer argument 21; result kept in v2. [global:0x007CD8C0, source:raw]
    // GUARD: Conditional: only proceed when the returned pointer v2 is non-null. [source:raw, function:0x004780B0]
    // ASSIGNMENT: Store the returned pointer v2 into this[56] (offset 0xE0) when the guard passes. [field:this:0x000000E0, source:raw]
    // RETURN: Return integer constant 0 regardless of which branch was taken. [source:raw, function:0x004780B0]

    // Conservative worker pseudocode:
    //   int PhysicsVehicleObjectReferenceStore(_DWORD *this) {
    //     int v2 = (*(int (__thiscall **)(int,int))(*(_DWORD*)dword_7CD8C0 + 28))(dword_7CD8C0, 21);
    //     if (v2)
    //       this[56] = v2;
    //     return 0;
    //   }
    // UNRESOLVED: Virtual call target (vtable offset 28 on the object behind dword_7CD8C0) is not resolved; neither the source object type nor the produced object stored at this->0xE0 is identified.
    // UNRESOLVED: Semantic meaning of literal argument 21 and of field this->0xE0 is not established by packet evidence.
}
