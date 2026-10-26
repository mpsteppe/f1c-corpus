// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596030
// Canonical corpus name: sub_596030
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596030_00596030.c

void UnknownObject::LocaleAwareWideCharToMultiByte()
{
    // Thread-safe wrapper around the actual wide-to-multi-byte conversion sub_596089. Atomically increments the heap-lock counter dword_8D5A5C; if the locale-thread refcount dword_8D5A58 is non-zero, decrements the counter and enters critical section 19 for the conversion; otherwise stays outside the critical section. Calls sub_596089(lpMultiByteStr, WideCharStr) and returns its result, releasing the critical section or decrementing the counter on exit accordingly. Per-frame path (on_frame_path).
    // CALL: InterlockedIncrement(&dword_8D5A5C): atomically raise the heap-lock counter before conversion. [global:0x0059E238, global:0x008D5A5C, function:0x00596030, source:raw]
    // ASSIGNMENT: v2 = 0; clear the critical-section-entered flag. [function:0x00596030, source:raw]
    // GUARD: If dword_8D5A58 (locale-thread refcount) is non-zero, take the locked path: InterlockedDecrement the counter, enter critical section 19 via CriticalSectionLazyInitEnter(19), and set v2 = 1. [global:0x008D5A58, global:0x0059E234, global:0x008D5A5C, callee:0x0058DFEA, function:0x00596030, source:raw]
    // CALL: WideCharStra = sub_596089(lpMultiByteStr, WideCharStr); perform the actual wide-to-multi-byte conversion. [callee:0x00596089, function:0x00596030, source:raw]
    // GUARD: On exit: if v2 is set, release critical section 19 via CritSectLeave(19); otherwise InterlockedDecrement the heap-lock counter. [callee:0x0058E04B, global:0x0059E234, global:0x008D5A5C, function:0x00596030, source:raw]
    // RETURN: Return the result of sub_596089 (the converted byte count / status). [callee:0x00596089, function:0x00596030, source:raw]

    // Conservative worker pseudocode:
    //   InterlockedIncrement(&heapLockCounter);
    //   entered = 0;
    //   if (localeThreadRefcount != 0) {
    //     InterlockedDecrement(&heapLockCounter);
    //     CriticalSectionLazyInitEnter(19);
    //     entered = 1;
    //   }
    //   result = sub_596089(lpMultiByteStr, WideCharStr);
    //   if (entered) CritSectLeave(19); else InterlockedDecrement(&heapLockCounter);
    //   return result;
    // UNRESOLVED: Semantics of dword_8D5A58 (locale-thread refcount, DERIVED name) and dword_8D5A5C (heap-lock counter, DERIVED name) are not confirmed.
    // UNRESOLVED: Critical section slot 19 purpose not established; the guard pairs it with the locale refcount.
    // UNRESOLVED: Meaning of the return value of sub_596089 (00496089) not grounded.
}
