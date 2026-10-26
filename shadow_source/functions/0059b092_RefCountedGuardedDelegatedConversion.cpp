// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B092
// Canonical corpus name: sub_59B092
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59B092_0059b092.c

void UnknownObject::RefCountedGuardedDelegatedConversion()
{
    // Reference-counted wrapper around sub_59B0F5. Increments the interlocked counter dword_8D5A5C; when the global flag dword_8D5A58 is set it instead decrements that counter, lazily enters critical section 19 and marks that the lock was taken. After the delegated conversion call it either leaves critical section 19 (when the lock was taken) or decrements the interlocked counter again. Returns the result of sub_59B0F5. Structural twin of sub_596030 (cluster_copy prelabel).
    // CALCULATION: InterlockedIncrement(&dword_8D5A5C): bump the interlocked counter at 0x008D5A5C via the imported increment routine at 0x0059E238. [global:0x0059E238, global:0x008D5A5C, source:raw]
    // ASSIGNMENT: v5 = 0: default to not holding the critical section. [source:raw]
    // GUARD: if (dword_8D5A58): branch into the lock-taking path when the global flag at 0x008D5A58 is set. [global:0x008D5A58, source:raw]
    // CALL: InterlockedDecrement(&dword_8D5A5C): undo the earlier increment via the imported decrement routine at 0x0059E234. [global:0x0059E234, global:0x008D5A5C, source:raw]
    // CALL: CriticalSectionLazyInitEnter(19): lazily initialize and enter critical section number 19. [callee:0x0058DFEA, source:raw]
    // ASSIGNMENT: v5 = 1: record that the critical section was taken. [source:raw]
    // CALL: v7 = sub_59B0F5(lpWideCharStr, a2, a3, lpMultiByteStr, a5): delegate the actual wide/multibyte conversion work and keep its result. [callee:0x0059B0F5, source:raw]
    // GUARD: if (v5) then CritSectLeave(19) else InterlockedDecrement(&dword_8D5A5C): release the lock when it was taken, otherwise balance the interlocked counter. [callee:0x0058E04B, global:0x0059E234, global:0x008D5A5C, source:raw]
    // RETURN: return v7: propagate the result produced by sub_59B0F5. [function:0x0059B092, source:raw]

    // Conservative worker pseudocode:
    //   int sub_59B092(LPWSTR wide, LPCCH a2, int a3, LPCCH mb, int a5) {
    //     InterlockedIncrement(&dword_8D5A5C);
    //     int locked = 0;
    //     if (dword_8D5A58) {
    //       InterlockedDecrement(&dword_8D5A5C);
    //       CriticalSectionLazyInitEnter(19);
    //       locked = 1;
    //     }
    //     int result = sub_59B0F5(wide, a2, a3, mb, a5);
    //     if (locked) CritSectLeave(19);
    //     else InterlockedDecrement(&dword_8D5A5C);
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the global flag dword_8D5A58 and the counter dword_8D5A5C is unknown; the critical-section index 19 has no documented owner.
    // UNRESOLVED: Argument roles of a2/a3/a5 for the delegated call sub_59B0F5 are not established from this function alone.
}
