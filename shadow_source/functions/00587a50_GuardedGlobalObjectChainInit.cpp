// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587A50
// Canonical corpus name: ThunkToFUN00598815_7a50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN00598815_7a50_00587a50.c

void UnknownObject::GuardedGlobalObjectChainInit()
{
    // Compiler-generated module init thunk that installs an SEH handler, runs a reference-counted once-guard on the module counter dword_5E9EF4, and on the first entry constructs a chain of seven linked global objects (vtable/SEH-chain objects plus locale-style objects bound to each other) into static buffers in the module data region, wiring them together at vtable-derived offsets. Subsequent entries only bump the guard counter and return. The exact identity and type of the constructed globals is not grounded.
    // CALL: Install the SEH handler for the module exception record unk_8D3E3D via SEHHandlerInit. [global:0x008D3E3D, source:raw]
    // ASSIGNMENT: Save the incoming register value v1 into the local frame slot at a1-20. [source:raw]
    // ASSIGNMENT: Zero the frame slot at a1-16 that carries the construction state. [source:raw]
    // CALL: Call the compiler guard/SEH helper sub_59A54D with the frame pointer a1-16. [source:raw]
    // GUARD: Reference-counted once-guard on dword_5E9EF4: if it is negative this is the first entry, so it is set to 1 and v2 is set to 1 (run initializer); otherwise it is incremented and v2 stays 0 (skip initializer). [source:raw]
    // CALL: Call the matching compiler guard/SEH helper sub_59A5E9 with the frame pointer a1-16. [source:raw]
    // GUARD: Only when v2 (first entry) is set, run the global-object construction block. [source:raw]
    // CALL: Construct the first global object at unk_8D4370 (tag 0) via ObjectConstructorWithSEHVTableInitChain with vtable chain off_5E6748, guarded by a non-null check on unk_8D4370. [source:raw]
    // CALL: Construct the global object at unk_8D4248 (tag 1) via ObjectConstructorWithSEHVTableInitChain with vtable chain unk_5E6768, guarded by a non-null check. [source:raw]
    // CALL: Construct the global object at dword_8D4330 (tag 2) via ObjectConstructorWithVTableSetupAndSEH bound to the object at unk_8D4370, guarded by a non-null check. [source:raw]
    // CALL: Construct the locale-style object at unk_8D42A0 (tag 3) via LocaleObjectConstructorWithVtableInit bound to the object at unk_8D4248, guarded by a non-null check. [source:raw]
    // CALCULATION: Wire unk_8D42A0 into dword_8D4330: store the address of unk_8D42A0 at the vtable-derived offset (+vtable[1] + 44) of dword_8D4330. [source:raw]
    // CALL: Construct the global object at unk_8D42D8 (tag 4) via ObjectConstructorWithSEHVTableInitChain with vtable chain unk_5E6788, guarded by a non-null check. [source:raw]
    // CALL: Construct the locale-style object at dword_8D43C8 (tag 5) via LocaleObjectConstructorWithVtableInit bound to the object at unk_8D42D8, guarded by a non-null check. [source:raw]
    // CALCULATION: Wire unk_8D42A0 into dword_8D43C8 at the vtable-derived offset (+vtable[1] + 44) and set flag bit 2 at +vtable[1] + 12 of dword_8D43C8. [source:raw]
    // CALL: Construct the locale-style object at dword_8D4210 (tag 6) via LocaleObjectConstructorWithVtableInit bound to the object at unk_8D42D8, guarded by a non-null check. [source:raw]
    // CALCULATION: Wire unk_8D42A0 into dword_8D423C: store its address at the vtable-derived offset (+vtable[1]) of dword_8D423C. [source:raw]
    // RETURN: Return the saved frame slot value read from a1-20. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_587A50(int frame) {
    //     int saved = frame[-20];
    //     SEHHandlerInit(&unk_8D3E3D);
    //     frame[-16] = 0;
    //     sub_59A54D(&frame[-16]);
    //     char first;
    //     if (dword_5E9EF4 < 0) { dword_5E9EF4 = 1; first = 1; }
    //     else { ++dword_5E9EF4; first = 0; }
    //     sub_59A5E9(&frame[-16]);
    //     if (first) {
    //       if (unk_8D4370) ObjectConstructorWithSEHVTableInitChain(&off_5E6748);
    //       if (unk_8D4248) ObjectConstructorWithSEHVTableInitChain(&unk_5E6768);
    //       if (dword_8D4330) ObjectConstructorWithVTableSetupAndSEH(&unk_8D4370, 1, 1);
    //       if (unk_8D42A0) LocaleObjectConstructorWithVtableInit(&unk_8D4248, 1, 1, 1);
    //       wire dword_8D4330 vtable slot + 44 to &unk_8D42A0;
    //       if (unk_8D42D8) ObjectConstructorWithSEHVTableInitChain(&unk_5E6788);
    //       if (dword_8D43C8) LocaleObjectConstructorWithVtableInit(&unk_8D42D8, 1, 1, 1);
    //       wire dword_8D43C8 vtable slot + 44 to &unk_8D42A0; set bit 2 at vtable slot + 12;
    //       if (dword_8D4210) LocaleObjectConstructorWithVtableInit(&unk_8D42D8, 1, 1, 1);
    //       wire dword_8D423C vtable slot to &unk_8D42A0;
    //     }
    //     return saved;
    //   }
    // UNRESOLVED: The concrete type and runtime purpose of the constructed globals (unk_8D4370, unk_8D4248, dword_8D4330, unk_8D42A0, unk_8D42D8, dword_8D43C8, dword_8D4210, dword_8D423C) are unknown; the LocaleObjectConstructor* callee names suggest locale-style objects but that is not confirmed.
    // UNRESOLVED: Identity of the compiler guard/SEH helpers sub_59A54D and sub_59A5E9 is not grounded by the packet.
    // UNRESOLVED: Semantics of the module reference counter dword_5E9EF4 beyond the first-vs-subsequent distinction are unknown.
    // UNRESOLVED: The offset arithmetic (+vtable[1] + 44, +vtable[1] + 12, +vtable[1]) assumes vtable[1] stores a displacement; the exact object layout is unverified.
}
