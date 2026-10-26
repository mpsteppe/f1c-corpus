// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057AE30
// Canonical corpus name: sub_57AE30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57AE30_0057ae30.c

void UnknownObject::StaticGuardedObjectChainInitC()
{
    // MSVC-generated SEH-guarded one-time global object initializer (canonical sub_57AE30). Registers a per-frame SEH handler seeded with the read-only global unk_8D3C19, applies a shared first-entry guard on dword_5E9EF4 (construction runs only on the first call; later calls increment the counter and skip the body), and on the first call builds a fixed chain of global objects (unk_8D4370, unk_8D4248, dword_8D4330, unk_8D42A0, unk_8D42D8, dword_8D43C8, dword_8D4210, dword_8D423C) through SEH/vtable/locale constructor helpers, cross-wiring entries with the address of unk_8D42A0 and OR-ing flag value 2 into one slot. Returns the original ecx value saved at frame slot a1-20.
    // CALL: Register the per-frame SEH handler via SEHHandlerInit, seeding it with the read-only global unk_8D3C19. [global:0x008D3C19, source:raw]
    // ASSIGNMENT: Save the incoming ecx value v1 at frame slot a1-20 and initialize the SEH scope marker slot a1-16 to 0. [source:raw, function:0x0057AE30]
    // CALL: Invoke sub_59A54D(a1-16) to set up the SEH registration scope before the guarded body. [source:raw]
    // GUARD: First-entry guard on the shared counter dword_5E9EF4: when it is negative it is reset to 1 and the first-call flag v2 is set; otherwise it is incremented and v2 is cleared. [source:raw]
    // CALL: Invoke sub_59A5E9(a1-16) to finalize the SEH scope after the guard. [source:raw]
    // GUARD: Only when v2 (first call) run the global object construction chain; each step records its object index 0 through 6 at frame slot a1-4 for unwind tracking. [source:raw]
    // CALL: Construct unk_8D4370 through ObjectConstructorWithSEHVTableInitChain(&off_5E6748), slot index 0. [source:raw]
    // CALL: Construct unk_8D4248 through ObjectConstructorWithSEHVTableInitChain(&unk_5E6768), slot index 1. [source:raw]
    // CALL: Construct dword_8D4330 through ObjectConstructorWithVTableSetupAndSEH(&unk_8D4370, 1, 1), slot index 2. [source:raw]
    // CALL: Construct unk_8D42A0 through LocaleObjectConstructorWithVtableInit(&unk_8D4248, 1, 1, 1), slot index 3. [source:raw]
    // ASSIGNMENT: Wire dword_8D4330: store the address of unk_8D42A0 into slot dword_8D4330 + *(dword_8D4330 + 4) + 44. [source:raw]
    // CALL: Construct unk_8D42D8 through ObjectConstructorWithSEHVTableInitChain(&unk_5E6788), slot index 4. [source:raw]
    // CALL: Construct dword_8D43C8 through LocaleObjectConstructorWithVtableInit(&unk_8D42D8, 1, 1, 1), slot index 5. [source:raw]
    // ASSIGNMENT: Wire dword_8D43C8: store the address of unk_8D42A0 into slot dword_8D43C8 + *(dword_8D43C8 + 4) + 44 and OR flag value 2 into slot dword_8D43C8 + *(dword_8D43C8 + 4) + 12. [source:raw]
    // CALL: Construct dword_8D4210 through LocaleObjectConstructorWithVtableInit(&unk_8D42D8, 1, 1, 1), slot index 6. [source:raw]
    // ASSIGNMENT: Wire dword_8D423C: store the address of unk_8D42A0 into slot dword_8D423C + *(dword_8D4210 + 4). [source:raw]
    // RETURN: Return the saved incoming value at frame slot a1-20 (the original ecx v1). [source:raw, function:0x0057AE30]

    // Conservative worker pseudocode:
    //   int StaticGuardedObjectChainInitC(int a1) {
    //     int v1 = <incoming ecx>;
    //     SEHHandlerInit(&unk_8D3C19);
    //     *(int *)(a1 - 20) = v1;
    //     *(int *)(a1 - 16) = 0;
    //     sub_59A54D(a1 - 16);
    //     char first = 0;
    //     if (dword_5E9EF4 < 0) { dword_5E9EF4 = 1; first = 1; }
    //     else { ++dword_5E9EF4; }
    //     sub_59A5E9(a1 - 16);
    //     if (first) {
    //       ObjectConstructorWithSEHVTableInitChain(&off_5E6748);        // unk_8D4370
    //       ObjectConstructorWithSEHVTableInitChain(&unk_5E6768);        // unk_8D4248
    //       ObjectConstructorWithVTableSetupAndSEH(&unk_8D4370, 1, 1);   // dword_8D4330
    //       LocaleObjectConstructorWithVtableInit(&unk_8D4248, 1, 1, 1); // unk_8D42A0
    //       *(int *)((char *)&dword_8D4330 + *(int *)(dword_8D4330 + 4) + 44) = (int)&unk_8D42A0;
    //       ObjectConstructorWithSEHVTableInitChain(&unk_5E6788);        // unk_8D42D8
    //       LocaleObjectConstructorWithVtableInit(&unk_8D42D8, 1, 1, 1); // dword_8D43C8
    //       *(int *)((char *)&dword_8D43C8 + *(int *)(dword_8D43C8 + 4) + 44) = (int)&unk_8D42A0;
    //       *(int *)((char *)&dword_8D43C8 + *(int *)(dword_8D43C8 + 4) + 12) |= 2;
    //       LocaleObjectConstructorWithVtableInit(&unk_8D42D8, 1, 1, 1); // dword_8D4210
    //       *(int *)((char *)&dword_8D423C + *(int *)(dword_8D4210 + 4)) = (int)&unk_8D42A0;
    //     }
    //     return *(int *)(a1 - 20);
    //   }
    // UNRESOLVED: Identity and owning class of the constructed global objects (unk_8D4370, unk_8D4248, dword_8D4330, unk_8D42A0, unk_8D42D8, dword_8D43C8, dword_8D4210, dword_8D423C) are not evidenced by the packet.
    // UNRESOLVED: Whether this is a CRT iostream/locale static-init block (locale helper names) or an application global initializer is unresolved.
    // UNRESOLVED: The vtable tables off_5E6748, unk_5E6768 and unk_5E6788 passed to the constructor helpers are not separately evidenced here.
    // UNRESOLVED: sub_59A54D and sub_59A5E9 are visible only as named calls in the raw source; their SEH frame-helper behavior is inferred from call position and no callee address is evidenced.
    // UNRESOLVED: Purpose of the shared counter dword_5E9EF4 beyond guarding first-time construction is unknown.
}
