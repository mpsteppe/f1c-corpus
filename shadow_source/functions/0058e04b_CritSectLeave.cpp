// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058E04B
// Canonical corpus name: CritSectLeave
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CritSectLeave_0058e04b.c

void UnknownObject::CritSectLeave()
{
    // Indexed critical-section release helper: given an index a1, selects the critical section stored at offset a1 within the global table rooted at dword_5E6C80 and calls LeaveCriticalSection on it. Mirrors the enter/init helpers in the same address range that treat dword_5E6C80 as an array of CRITICAL_SECTION objects.
    // CALCULATION: Compute the critical-section address as (&dword_5E6C80 + a1), i.e. a1 steps through the global critical-section table rooted at dword_5E6C80 (read-only here). [global:0x005E6C80, source:raw]
    // CALL: Release the selected critical section via LeaveCriticalSection (read at 0x0059E170), dereferencing the computed table entry. [global:0x0059E170, source:raw]
    // CALL: Called as the release half of critical-section pairs across the engine, e.g. CriticalSectionLeave (0x00589D74), AddressRangeCriticalSectionLeave (0x0058C203), CriticalSectionLeave_c232 (0x0058C232), CriticalSectionLazyInitEnter (0x0058DFEA), LazyInitSingletonWithFlagGuard (0x005921C5) and CriticalSectionGuardedCall (0x0059247A). [caller:0x00589D74, caller:0x0058C203, caller:0x0058C232, caller:0x0058DFEA, caller:0x005921C5, caller:0x0059247A]

    // Conservative worker pseudocode:
    //   void __cdecl sub_58E04B(int index) {
    //     LeaveCriticalSection(*(&dword_5E6C80 + index));
    //   }
    // UNRESOLVED: Element count and stride of the dword_5E6C80 table, and whether a1 is validated before indexing.
    // UNRESOLVED: The enter counterparts and table initialization live in sibling functions outside this packet.
}
