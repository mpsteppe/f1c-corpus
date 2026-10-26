// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A54D
// Canonical corpus name: sub_59A54D
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59A54D_0059a54d.c

void UnknownObject::CriticalSectionInitAndEnter()
{
    // Thread-safe one-time initialization and entry of the global critical section CriticalSection (0x008D45F8), driven by the atomic state variable Target (0x008D4610: 0 = uninitialized, 1 = initializing, 2 = ready). The winning thread uses InterlockedExchange to claim initialization, calls InitializeCriticalSection, registers a teardown callback loc_59A5CB through BooleanToIntConversion (the callback path uses DeleteCriticalSection), sets Target = 2 and enters the section. Losing threads spin with Sleep(1) while Target == 1, then enter once ready. Returns this in all paths.
    // GUARD: if (Target == 2): section already ready, jump directly to the enter path. [global:0x008D4610, source:raw]
    // GUARD: if (Target == 0): section never initialized; this is the first-time initialization path. [global:0x008D4610, source:raw]
    // CALL: v2 = InterlockedExchange(&Target, 1): atomically claim the initializing state; a return of 0 means this thread won the race. [global:0x008D4610, global:0x0059E0B4, source:raw]
    // GUARD: if (v2 == 0): this thread won the race and performs the initialization. [source:raw]
    // CALL: InitializeCriticalSection(&CriticalSection): create the global critical section object. [global:0x008D45F8, global:0x0059E16C, source:raw]
    // CALL: BooleanToIntConversion((int)&loc_59A5CB): register loc_59A5CB as the teardown/cleanup callback; the callback path referenced here uses DeleteCriticalSection. [callee:0x00587B3E, global:0x0059A5CB, global:0x0059E160, source:raw]
    // ASSIGNMENT: Target = 2: mark the section as ready so other threads can stop spinning. [global:0x008D4610, source:raw]
    // ASSIGNMENT: if (v2 == 2): another thread already completed initialization after the exchange; adopt the ready state by setting Target = 2. [global:0x008D4610, source:raw]
    // LOOP: while (Target == 1) Sleep(1u): spin-wait while another thread is still initializing. [global:0x008D4610, global:0x0059E0DC, source:raw]
    // GUARD: if (Target == 2): after the spin, section is ready; fall through to the enter path. [global:0x008D4610, source:raw]
    // CALL: EnterCriticalSection(&CriticalSection): acquire the section before returning. [global:0x008D45F8, global:0x0059E174, source:raw]
    // RETURN: Return this on the normal enter path. [source:raw]
    // RETURN: Return this when the section did not reach the ready state (spin exit path). [source:raw]

    // Conservative worker pseudocode:
    //   void *CriticalSectionInitAndEnter(void *this) {
    //     if (Target == 2) { EnterCriticalSection(&CriticalSection); return this; }
    //     if (Target == 0) {
    //       LONG v2 = InterlockedExchange(&Target, 1);
    //       if (v2 == 0) {
    //         InitializeCriticalSection(&CriticalSection);
    //         BooleanToIntConversion((int)&loc_59A5CB);
    //         Target = 2;
    //         EnterCriticalSection(&CriticalSection);
    //         return this;
    //       }
    //       if (v2 == 2) Target = 2;
    //     }
    //     while (Target == 1) Sleep(1u);
    //     if (Target == 2) { EnterCriticalSection(&CriticalSection); return this; }
    //     return this;
    //   }
    // UNRESOLVED: loc_59A5CB is a code address (a thunk/stub) passed to BooleanToIntConversion as a cleanup callback; its body is outside this function and its exact relationship to DeleteCriticalSection is inferred from the packet's global list.
    // UNRESOLVED: The imported kernel32 entries (InterlockedExchange, Sleep, DeleteCriticalSection, InitializeCriticalSection, EnterCriticalSection) appear as read globals here because they are reached through the import address table; the interpreter rendering them as direct calls is a decompiler artifact.
    // UNRESOLVED: The object identity behind the returned this pointer is not resolvable from this packet; the critical section state is global, not per-object.
}
