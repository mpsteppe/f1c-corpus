// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485DF0
// Canonical corpus name: GlobalManagerShutdownSequence
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalManagerShutdownSequence_00485df0.c

void UnknownObject::GlobalManagerShutdownSequence()
{
    // Shutdown sequence for a globally held dispatch/manager object: calls sub_4963D0 with dword_7CD8C0, dispatches through the object's vtable first entry with argument 1 when non-null, nulls the global, and returns the result of sub_4B0770(1). Called by sub_485B90 (00485B90).
    // CALL: Call sub_4963D0 with dword_7CD8C0 as the argument (pre-release/pre-shutdown hook). [callee:0x004963D0, global:0x007CD8C0, source:raw]
    // GUARD: If dword_7CD8C0 is non-null, dispatch through its vtable first entry with (this=dword_7CD8C0, argument=1) — proposed release/shutdown method. [global:0x007CD8C0, source:raw]
    // ASSIGNMENT: Null the global dword_7CD8C0 after the interface call. [global:0x007CD8C0, source:raw]
    // CALL: Return the result of sub_4B0770(1) (proposed final cleanup with a constant argument). [callee:0x004B0770, source:raw]

    // Conservative worker pseudocode:
    //   int sub_485DF0() {
    //     sub_4963D0(dword_7CD8C0);
    //     if (dword_7CD8C0)
    //       (*(void (__thiscall **)(int, int))dword_7CD8C0)(dword_7CD8C0, 1);
    //     dword_7CD8C0 = 0;
    //     return sub_4B0770(1);
    //   }
    // UNRESOLVED: Vtable slot 0 identity and the meaning of the constant 1 passed to it are unknown.
    // UNRESOLVED: byte_7CE498 is flagged as a read global by packet facts but appears nowhere in the raw decompiled source; its role cannot be verified here.
}
