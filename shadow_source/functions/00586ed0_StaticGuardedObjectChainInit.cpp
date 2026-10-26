// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586ED0
// Canonical corpus name: ThunkToFUN00598815_6ed0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN00598815_6ed0_00586ed0.c

void UnknownObject::StaticGuardedObjectChainInit()
{
    // MSVC-generated SEH-guarded dynamic initializer. Registers a per-frame SEH handler seeded with the read-only global 0x008D3E31, applies a shared re-entrancy guard on dword_5E9EF4 (construction runs only on the first entry), and on that first call builds a fixed chain of global objects (unk_8D4370, unk_8D4248, dword_8D4330, unk_8D42A0, unk_8D42D8, dword_8D43C8, dword_8D4210, dword_8D423C) via vtable/SEH/locale constructors, cross-wiring each with the address of unk_8D42A0 and OR-ing flag value 2 into one entry. Returns the original ecx value saved at frame slot a1-20.
    // CALL: Register the per-frame SEH handler via SEHHandlerInit, seeding it with the read-only global 0x008D3E31. [global:0x008D3E31, source:raw]
    // ASSIGNMENT: Save the incoming ecx value v1 at frame slot a1-20 and initialize the SEH frame slot a1-16 to 0. [source:raw]
    // CALL: Invoke sub_59A54D(a1-16) to set up the SEH registration frame. [source:raw]
    // GUARD: Re-entrancy guard on the shared counter dword_5E9EF4: when it is negative it is reset to 1 and the first-call flag v2 is set; otherwise it is incremented and v2 is cleared. [source:raw]
    // CALL: Invoke sub_59A5E9(a1-16) to finalize the SEH frame after the guard. [source:raw]
    // GUARD: Only when v2 (first call) run the global object construction chain. [source:raw]
    // CALL: Construct unk_8D4370 through ObjectConstructorWithSEHVTableInitChain(&off_5E6748). [source:raw]
    // CALL: Construct unk_8D4248 through ObjectConstructorWithSEHVTableInitChain(&unk_5E6768). [source:raw]
    // CALL: Construct dword_8D4330 through ObjectConstructorWithVTableSetupAndSEH(&unk_8D4370, 1, 1). [source:raw]
    // CALL: Construct unk_8D42A0 through LocaleObjectConstructorWithVtableInit(&unk_8D4248, 1, 1, 1). [source:raw]
    // ASSIGNMENT: Wire dword_8D4330: store the address of unk_8D42A0 into slot dword_8D4330 + *(dword_8D4330 + 4) + 44. [source:raw]
    // CALL: Construct unk_8D42D8 through ObjectConstructorWithSEHVTableInitChain(&unk_5E6788). [source:raw]
    // CALL: Construct dword_8D43C8 through LocaleObjectConstructorWithVtableInit(&unk_8D42D8, 1, 1, 1). [source:raw]
    // ASSIGNMENT: Wire dword_8D43C8: store the address of unk_8D42A0 into dword_8D43C8 + *(dword_8D43C8 + 4) + 44 and OR flag value 2 into dword_8D43C8 + *(dword_8D43C8 + 4) + 12. [source:raw]
    // CALL: Construct dword_8D4210 through LocaleObjectConstructorWithVtableInit(&unk_8D42D8, 1, 1, 1). [source:raw]
    // ASSIGNMENT: Wire dword_8D423C: store the address of unk_8D42A0 into dword_8D423C + *(dword_8D4210 + 4). [source:raw]
    // RETURN: Return the saved incoming value at frame slot a1-20 (the original ecx v1). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_586ED0(int a1) {
    //     int v1 = <incoming ecx>;
    //     SEHHandlerInit(&unk_8D3E31);
    //     *(int *)(a1 - 20) = v1;
    //     *(int *)(a1 - 16) = 0;
    //     sub_59A54D(a1 - 16);
    //     char first = 0;
    //     if (dword_5E9EF4 < 0) { dword_5E9EF4 = 1; first = 1; }
    //     else { ++dword_5E9EF4; }
    //     sub_59A5E9(a1 - 16);
    //     if (first) {
    //       ObjectConstructorWithSEHVTableInitChain(&off_5E6748);       // unk_8D4370
    //       ObjectConstructorWithSEHVTableInitChain(&unk_5E6768);       // unk_8D4248
    //       ObjectConstructorWithVTableSetupAndSEH(&unk_8D4370, 1, 1);  // dword_8D4330
    //       LocaleObjectConstructorWithVtableInit(&unk_8D4248, 1, 1, 1); // unk_8D42A0
    //       *(int *)((char *)&dword_8D4330 + *(int *)(dword_8D4330 + 4) + 44) = (int)&unk_8D42A0;
    //       ObjectConstructorWithSEHVTableInitChain(&unk_5E6788);       // unk_8D42D8
    //       LocaleObjectConstructorWithVtableInit(&unk_8D42D8, 1, 1, 1); // dword_8D43C8
    //       *(int *)((char *)&dword_8D43C8 + *(int *)(dword_8D43C8 + 4) + 44) = (int)&unk_8D42A0;
    //       *(int *)((char *)&dword_8D43C8 + *(int *)(dword_8D43C8 + 4) + 12) |= 2;
    //       LocaleObjectConstructorWithVtableInit(&unk_8D42D8, 1, 1, 1); // dword_8D4210
    //       *(int *)((char *)&dword_8D423C + *(int *)(dword_8D4210 + 4)) = (int)&unk_8D42A0;
    //     }
    //     return *(int *)(a1 - 20);
    //   }
    // UNRESOLVED: Semantics of the constructed global object chain and why each entry is cross-wired with the address of unk_8D42A0 are not grounded by this packet; constructor helpers are external.
    // UNRESOLVED: Purpose of the shared counter dword_5E9EF4 beyond guarding first-time construction is unknown; the routine is one of several near-identical copies sharing that counter.
    // UNRESOLVED: sub_59A54D / sub_59A5E9 SEH frame helper roles are inferred only from call position.
}
