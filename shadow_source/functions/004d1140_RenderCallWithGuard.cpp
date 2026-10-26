// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1140
// Canonical corpus name: RenderCallWithGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderCallWithGuard_004d1140.c

void UnknownObject::RenderCallWithGuard()
{
    // If the grid position index at this+0x48A4 is negative (< 0, unallocated), call sub_4C6F10(a1) to allocate/find a free grid position. Then read indexed struct data from the setup scene via IndexedStructDataRead(dword_5EA2C0, this+0x48A4, this+0x48A8, a2, a3) and return its result. Called from render, physics, camera and AI update paths.
    // GUARD: If the grid position index at this+0x48A4 is negative (< 0), the slot is unallocated and sub_4C6F10(a1) is invoked to allocate/find a free grid position. [guard:0, field:this:0x000048A4, callee:0x004C6F10, source:raw]
    // CALL: sub_4C6F10(a1) recalculates/allocates the grid position for the struct when the guard passes (index < 0). [callee:0x004C6F10, guard:0, source:raw]
    // CALL: IndexedStructDataRead(dword_5EA2C0 (setup scene), this+0x48A4 (grid position index), this+0x48A8 (team column index), a2, a3) reads the indexed struct data from the setup scene. [callee:0x00403FC0, global:0x005EA2C0, field:this:0x000048A4, field:this:0x000048A8, source:raw]
    // RETURN: Return the result of IndexedStructDataRead. [callee:0x00403FC0, source:raw]

    // Conservative worker pseudocode:
    //   int RenderCallWithGuard(int* a1, int* a2, int* a3) {
    //     if (a1[4649] < 0)          /* this+0x48A4 grid position index * /
    //       sub_4C6F10(a1);
    //     return IndexedStructDataRead(dword_5EA2C0, a1[4649], a1[4650], a2, a3);
    //   }
    // UNRESOLVED: sub_4C6F10's exact algorithm (allocation vs lookup) is not visible here; only its role as grid-position recalculation is evidenced.
    // UNRESOLVED: The base object this/a1 is not identified; the global dword_5EA2C0 is only DERIVED as the setup scene pointer.
    // UNRESOLVED: The roles of the a2/a3 output parameters of IndexedStructDataRead are not documented in this function's evidence.
}
