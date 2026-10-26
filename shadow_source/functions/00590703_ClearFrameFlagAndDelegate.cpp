// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00590703
// Canonical corpus name: sub_590703
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_590703_00590703.c

void UnknownObject::ClearFrameFlagAndDelegate()
{
    // Frame-local flag helper (__usercall, a1 is the caller's frame pointer in ebp): clears bit 0 of the byte at a1 - 712, then delegates to sub_59070A() and returns whatever that call returned. Sits on the CRT float-display call path between sub_5906BB and Ctrandisp1CRTFloatDisplayFormat.
    // ASSIGNMENT: Clear bit 0 of the byte at frame offset a1 - 712: *(_BYTE *)(a1 - 712) &= ~1u. [source:raw]
    // CALL: Call sub_59070A() with no arguments and adopt its return value as this function's result. [source:raw]
    // RETURN: Return the value produced by sub_59070A(). [source:raw]
    // CALL: Invoked by sub_5906BB (0x005906BB) and Ctrandisp1CRTFloatDisplayFormat (0x0059083B), both CRT float-display helpers. [caller:0x005906BB, caller:0x0059083B]

    // Conservative worker pseudocode:
    //   int sub_590703(int a1) {
    //     *(unsigned char *)(a1 - 712) &= ~1u;
    //     return sub_59070A();
    //   }
    // UNRESOLVED: sub_59070A is called but is not present in the packet callees list; its identity, arguments and return contract are unresolved.
    // UNRESOLVED: Meaning of the cleared bit at a1 - 712 depends on the CRT float-display caller context and is not established here.
}
