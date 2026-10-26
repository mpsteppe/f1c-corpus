// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00579FB0
// Canonical corpus name: sub_579FB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_579FB0_00579fb0.c

void UnknownObject::GlobalObjectsInitWithRefcountGuard()
{
    // CRT-style guarded one-time initializer: sets up an SEH handler on global table unk_8D3BF1, uses a reference-count guard global dword_5E9EF4 so the global object constructor chain runs only on the first entry, and returns the caller's saved value. The first-time branch constructs a sequence of global objects with vtable/SEH init routines and cross-links them into each other's vtable slots.
    // CALL: Set up the SEH handler table on global unk_8D3BF1 for the guarded region. [global:0x008D3BF1]
    // ASSIGNMENT: Save the incoming value into the frame slot at a1-20 and initialize the local scope marker slot at a1-16 to 0. [source:raw]
    // CALL: Register the scope-exit/cleanup callback sub_59A54D on the frame slot a1-16 before the guarded body. [source:raw]
    // GUARD: Reference-count guard on dword_5E9EF4: when it is negative, set it to 1 and select the first-time path; otherwise increment it and select the repeat path. [source:raw]
    // CALL: Register the scope-exit/cleanup callback sub_59A5E9 on the frame slot a1-16 after the guarded body. [source:raw]
    // GUARD: When the first-time path was selected, run the one-time global object constructor chain. [source:raw]
    // CALL: Construct a sequence of global objects using the SEH/vtable init routines and the locale-aware constructor helper, tracking each constructed slot, and link derived objects into their parent object's vtable at the computed slots. [source:raw]
    // RETURN: Return the saved incoming value read back from the frame slot at a1-20. [source:raw]

    // Conservative worker pseudocode:
    //   int GlobalObjectsInitWithRefcountGuard(int saved) {
    //     SEHHandlerInit(&unk_8D3BF1);
    //     frame.saved = saved; frame.marker = 0;
    //     sub_59A54D(&frame.marker);
    //     int first;
    //     if (dword_5E9EF4 < 0) { dword_5E9EF4 = 1; first = 1; }
    //     else { ++dword_5E9EF4; first = 0; }
    //     sub_59A5E9(&frame.marker);
    //     if (first) { /* construct and cross-link global objects unk_8D4370,
    //                    unk_8D4248, dword_8D4330, unk_8D42A0, unk_8D42D8,
    //                    dword_8D43C8, dword_8D4210, dword_8D423C * / }
    //     return frame.saved;
    //   }
    // UNRESOLVED: Identity and owning class of the constructed global objects (unk_8D4370, unk_8D4248, dword_8D4330, unk_8D42A0, unk_8D42D8, dword_8D43C8, dword_8D4210, dword_8D423C) are not evidenced by the packet.
    // UNRESOLVED: The vtable tables off_5E6748, unk_5E6768 and unk_5E6788 referenced by the constructor helpers are not separately evidenced here.
    // UNRESOLVED: Whether this is a CRT iostream/locale static-init block or an application global initializer is unresolved.
    // UNRESOLVED: The callbacks sub_59A54D and sub_59A5E9 are only visible as named calls in the raw source; their behavior is not established.
}
