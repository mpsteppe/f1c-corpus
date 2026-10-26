// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058DFC1
// Canonical corpus name: sub_58DFC1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58DFC1_0058dfc1.c

void UnknownObject::CriticalSectionArrayInit()
{
    // Startup-only routine that initializes four Win32 critical section objects via InitializeCriticalSection: lpCriticalSection, off_5E6CB4, off_5E6CA4 and off_5E6C84. Straight-line function with no guards, preparing synchronization primitives used by the allocation/thread-management paths.
    // CALL: InitializeCriticalSection (import at 0x0059E16C) on the first critical-section object at lpCriticalSection (0x005E6CC4). [global:0x0059E16C, global:0x005E6CC4, source:raw]
    // CALL: InitializeCriticalSection on the critical section at off_5E6CB4 (0x005E6CB4). [global:0x0059E16C, global:0x005E6CB4, source:raw]
    // CALL: InitializeCriticalSection on the critical section at off_5E6CA4 (0x005E6CA4). [global:0x0059E16C, global:0x005E6CA4, source:raw]
    // CALL: InitializeCriticalSection on the critical section at off_5E6C84 (0x005E6C84). [global:0x0059E16C, global:0x005E6C84, source:raw]
    // RETURN: Void return; nothing is produced. [source:raw]

    // Conservative worker pseudocode:
    //   void InitCriticalSectionArray() {
    //     InitializeCriticalSection(&g_cs0); // lpCriticalSection @0x005E6CC4
    //     InitializeCriticalSection(&g_cs1); // off_5E6CB4  @0x005E6CB4
    //     InitializeCriticalSection(&g_cs2); // off_5E6CA4  @0x005E6CA4
    //     InitializeCriticalSection(&g_cs3); // off_5E6C84  @0x005E6C84
    //   }
    // UNRESOLVED: The four initialized critical sections appear to guard allocation/TLS paths, but which threads use each lock is not visible from this packet.
    // UNRESOLVED: No evidence here of which owner object holds these globals or why four distinct sections are needed.
}
