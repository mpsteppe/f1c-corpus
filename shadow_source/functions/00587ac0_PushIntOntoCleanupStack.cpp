// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587AC0
// Canonical corpus name: sub_587AC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587AC0_00587ac0.c

void UnknownObject::PushIntOntoCleanupStack()
{
    // Thread-safe push of an integer a1 onto a custom DWORD stack described by globals dword_8D5A54 (base) and dword_8D5A50 (top/next-free). Enters a critical section, grows the stack via sub_58B5D4 when the current fill exceeds the capacity, writes a1 at the top, advances the top by 4, leaves the critical section and returns a1 on success (0 when reallocation fails).
    // CALL: Enter the critical section via sub_589D6B to make the stack update atomic. [source:raw, callee:0x00589D6B]
    // CALL: Query the current fill position via sub_58BB68(dword_8D5A54) to test whether reallocation is needed. [source:raw, callee:0x0058BB68, global:0x008D5A54]
    // GUARD: Guard comparing fill (v1) against (dword_8D5A50 - dword_8D5A54) + 4; when fill is below the threshold the stack has room and reallocation is skipped. [source:raw, global:0x008D5A50, global:0x008D5A54]
    // CALL: Re-query the fill via sub_58BB68 and request a reallocation via sub_58B5D4 of the base block, sized fill + 16. [source:raw, callee:0x0058BB68, callee:0x0058B5D4, global:0x008D5A54]
    // GUARD: Guard on the reallocation result v4 being non-null; a null result means the push failed and v5 is set to 0. [source:raw]
    // ASSIGNMENT: Rebind dword_8D5A54 to the new block v4 and recompute the top pointer dword_8D5A50 from the preserved element count (v6 >> 2). [source:raw, global:0x008D5A54, global:0x008D5A50]
    // ASSIGNMENT: Store a1 at the current top pointer and advance dword_8D5A50 by 4. [source:raw, global:0x008D5A50]
    // CALL: Leave the critical section via CriticalSectionLeave. [source:raw, callee:0x00589D74]
    // RETURN: Return the pushed value a1 on success, or 0 when the reallocation failed. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_587AC0(int a1) {
    //     sub_589D6B();
    //     unsigned int fill = sub_58BB68(dword_8D5A54);
    //     char *top = (char *)dword_8D5A50;
    //     int v5;
    //     if (fill >= dword_8D5A50 - (int)dword_8D5A54 + 4) {
    //       unsigned int more = sub_58BB68(dword_8D5A54);
    //       char *block = (char *)sub_58B5D4((LPVOID)dword_8D5A54, more + 16);
    //       if (block) {
    //         int used = dword_8D5A50 - (int)dword_8D5A54;
    //         dword_8D5A54 = (int)block;
    //         top = &block[4 * (used >> 2)];
    //         dword_8D5A50 = (int)top;
    //       } else {
    //         v5 = 0;
    //         CriticalSectionLeave();
    //         return v5;
    //       }
    //     }
    //     *(_DWORD *)top = a1;
    //     dword_8D5A50 += 4;
    //     v5 = a1;
    //     CriticalSectionLeave();
    //     return v5;
    //   }
    // UNRESOLVED: Caller context: pushed values are consumed by an unknown pop path; BooleanToIntConversion (0x00587B3E) is the single known caller.
    // UNRESOLVED: The storage is described as a cleanup stack only because the callers' semantics are not yet mapped.
}
