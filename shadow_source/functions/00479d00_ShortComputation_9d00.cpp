// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479D00
// Canonical corpus name: ShortComputation_9d00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_9d00_00479d00.c

void UnknownObject::ShortComputation_9d00()
{
    // Double guarded dispatch: calls the virtual method at vtable offset 28 on the object referenced by global dword_7CD8C0 twice, first with literal argument 14 then with literal argument 15; each returned pointer, when non-null, is passed to ObjectNameComparison(ptr, this); then returns 0.
    // CALL: Call the virtual method at vtable offset 28 on the object pointed to by dword_7CD8C0, passing integer argument 14; result kept in v2. [global:0x007CD8C0, source:raw]
    // GUARD: Conditional: only proceed when the returned pointer v2 is non-null. [source:raw, function:0x00479D00]
    // CALL: Call ObjectNameComparison(v2, (int)this) when the first guard passes. [callee:0x00477280, source:raw]
    // CALL: Call the virtual method at vtable offset 28 on the object pointed to by dword_7CD8C0 again, this time with integer argument 15; result kept in v3. [global:0x007CD8C0, source:raw]
    // GUARD: Conditional: only proceed when the returned pointer v3 is non-null. [source:raw, function:0x00479D00]
    // CALL: Call ObjectNameComparison(v3, (int)this) when the second guard passes. [callee:0x00477280, source:raw]
    // RETURN: Return integer constant 0 regardless of which branches were taken. [source:raw, function:0x00479D00]

    // Conservative worker pseudocode:
    //   int ShortComputation_9d00(void *this) {
    //     _DWORD *v2 = (_DWORD *)(*(int (__thiscall **)(int,int))(*(_DWORD*)dword_7CD8C0 + 28))(dword_7CD8C0, 14);
    //     if (v2)
    //       ObjectNameComparison(v2, (int)this);
    //     _DWORD *v3 = (_DWORD *)(*(int (__thiscall **)(int,int))(*(_DWORD*)dword_7CD8C0 + 28))(dword_7CD8C0, 15);
    //     if (v3)
    //       ObjectNameComparison(v3, (int)this);
    //     return 0;
    //   }
    // UNRESOLVED: Virtual call target (vtable offset 28 on the object behind dword_7CD8C0) is not resolved; the meaning of literal arguments 14 and 15 (candidates: object/command selectors) is not established.
    // UNRESOLVED: ObjectNameComparison (0x00477280) internals and why two distinct produced objects are each compared against this are outside this packet.
    // UNRESOLVED: Object type identity and owner are unknown; packet has no owner evidence.
}
