// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005921C5
// Canonical corpus name: LazyInitSingletonWithFlagGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LazyInitSingletonWithFlagGuard_005921c5.c

void UnknownObject::LazyInitSingletonWithFlagGuard()
{
    // Thread-safe lazy initialization of a CRT singleton via double-checked locking on global flag dword_8D4078. Fast-path returns when the flag is already set; otherwise enters critical section 11, re-checks the flag, runs the real initializer sub_5921F3, bumps the flag, and leaves the section.
    // GUARD: Outer fast-path guard: if dword_8D4078 is non-zero the singleton is already initialized and the function returns without touching the lock. [global:0x008D4078, source:raw]
    // CALL: Enter critical section 11 via CriticalSectionLazyInitEnter(11) with lazy first-time setup. [callee:0x0058DFEA, source:raw]
    // GUARD: Inner double-check after acquiring the lock: only initialize if dword_8D4078 is still zero. [global:0x008D4078, source:raw]
    // CALL: Run the actual singleton initializer sub_5921F3(). [callee:0x005921F3, source:raw]
    // ASSIGNMENT: Mark the singleton initialized by incrementing dword_8D4078. [global:0x008D4078, source:raw]
    // CALL: Release critical section 11 via CritSectLeave(11). [callee:0x0058E04B, source:raw]

    // Conservative worker pseudocode:
    //   void sub_5921C5() {
    //     if (dword_8D4078) return;
    //     CriticalSectionLazyInitEnter(11);
    //     if (!dword_8D4078) {
    //       sub_5921F3();
    //       ++dword_8D4078;
    //     }
    //     CritSectLeave(11);
    //   }
    // UNRESOLVED: What the 11th critical section protects and what sub_5921F3 actually initializes are outside this function's evidence.
    // UNRESOLVED: Why dword_8D4078 is a counter (++dword) rather than a boolean set to a constant is not answered by the packet.
}
