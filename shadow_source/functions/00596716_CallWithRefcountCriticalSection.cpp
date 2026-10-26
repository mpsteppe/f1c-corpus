// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596716
// Canonical corpus name: sub_596716
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596716_00596716.c

void UnknownObject::CallWithRefcountCriticalSection()
{
    // Reference-counted wrapper that forwards three arguments to sub_596773. It increments a shared active-call counter, and when the dword_8D5A58 flag is set it rebalances that counter and acquires critical section 19 before the inner call, releasing it afterwards. The caller-side critical section is taken on the flag path and mirrored by an InterlockedDecrement on the non-flag path.
    // CALL: InterlockedIncrement(&dword_8D5A5C) bumps the shared active-call reference counter on entry. [global:0x008D5A5C, global:0x0059E238]
    // GUARD: If dword_8D5A58 is non-zero, take the critical-section path instead of the plain counter path. [global:0x008D5A58]
    // CALL: On the flag path, InterlockedDecrement(&dword_8D5A5C) balances the entry increment, then CriticalSectionLazyInitEnter(19) acquires critical section 19. [global:0x008D5A5C, global:0x0059E234, callee:0x0058DFEA]
    // STATE_TRANSITION: v3 = 1 records that critical section 19 was acquired and must be released. [source:raw]
    // CALL: v5 = sub_596773(lpWideCharStr, lpMultiByteStr, a3) performs the real work, forwarding all three arguments unchanged. [callee:0x00596773, source:raw]
    // GUARD: If v3 is set, release the critical section on the exit path. [source:raw]
    // CALL: CritSectLeave(19) releases critical section 19 when it was acquired. [callee:0x0058E04B]
    // CALL: On the non-flag path, InterlockedDecrement(&dword_8D5A5C) balances the entry increment instead of using a critical section. [global:0x008D5A5C, global:0x0059E234]
    // RETURN: Return v5, the result of sub_596773. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_596716(LPWSTR wide, LPCCH mb, int a3) {
    //     InterlockedIncrement(&dword_8D5A5C);
    //     int locked = 0;
    //     if (dword_8D5A58) {
    //       InterlockedDecrement(&dword_8D5A5C);
    //       CriticalSectionLazyInitEnter(19);
    //       locked = 1;
    //     }
    //     int result = sub_596773(wide, mb, a3);
    //     if (locked)
    //       CritSectLeave(19);
    //     else
    //       InterlockedDecrement(&dword_8D5A5C);
    //     return result;
    //   }
    // UNRESOLVED: Purpose of the dword_8D5A58 guard flag and the dword_8D5A5C reference counter is unknown; the exact thread-safety contract is outside this function.
    // UNRESOLVED: Semantics of the real work in sub_596773 are outside this wrapper.
    // UNRESOLVED: The prelabel cluster twin sub_596030 (00596030) is DERIVED and unverified here.
}
