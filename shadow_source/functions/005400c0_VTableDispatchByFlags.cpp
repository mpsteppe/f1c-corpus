// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005400C0
// Canonical corpus name: VTableDispatchByFlags
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableDispatchByFlags_005400c0.c

void UnknownObject::VTableDispatchByFlags()
{
    // Flags-driven virtual dispatch through a descriptor at a2. Resolves the flag word from a4, or from a2+24 when a4 is zero, and derives a per-call argument flag of 16 when bit 0x100 is set (else 0). Selects one of two method-holder pointers by flag bit: bit 1 picks a2+8, bit 2 picks a2+12; if neither is set, flag bit 4 routes to the handler at *(a2+16). Each path invokes a stdcall vtable slot (36 for the a2+8/a2+12 holders, 64 for the *(a2+16) holder) with an output buffer v10, a zero argument, and the derived flag. The handler result is stored to this+0; when it is null the out-parameters v10[0]/v10[1] are committed to a2+40 and v10[1] is returned, otherwise 0 is returned.
    // ASSIGNMENT: Resolve the effective flag word v6: v6 takes the low byte of a4, or the default flag word at a2+24 when a4 is zero; bit 0x100 of a4 selects a derived argument flag v5 of 16 instead of 0 [source:raw]
    // GUARD: Flag bit 1 of the effective flag word selects the method-holder pointer at a2+8 [source:raw]
    // GUARD: Else when flag bit 2 is set, the method-holder pointer at a2+12 is selected; when neither bit is set control falls through to the flag-bit-4 path [source:raw]
    // CALL: When the selected holder v7 is non-null, invoke the stdcall vtable slot at offset 36 with (v7, v10, 0, v5); the returned value v8 flows into this+0 [source:raw]
    // GUARD: When no holder was selected and flag bit 4 is unset, return 0 without dispatching [source:raw]
    // CALL: Flag bit 4 path: invoke the stdcall vtable slot at offset 64 on the handler object *(a2+16) with (*(a2+16), a3, v10, 0, v5) [source:raw]
    // ASSIGNMENT: Store the handler return value v8 into this+0; a null v8 is treated as a failure signal that still commits out-parameters [field:this:0x00000000, source:raw]
    // ASSIGNMENT: When v8 is null, copy the output buffer into the descriptor: v10[0] is written to a2+40 and v10[1] is returned as the function result [source:raw]
    // RETURN: Return 0 when the dispatch produced a non-null result, or v10[1] when the result was null [function:0x005400C0, source:raw]
    // CALL: Invoked by ThunkWithArgReorder (00543210), which supplies the descriptor, forwarded argument and flag word [caller:0x00543210, source:raw]

    // Conservative worker pseudocode:
    //   flags = a4 ? a4 : *(a2 + 24);
    //   argFlag = (a4 & 0x100) ? 16 : 0;
    //   v8 = 0;
    //   if (flags & 1)
    //       v8 = holder(*(a2 + 8))->vtbl[36 / 4](*(a2 + 8), v10, 0, argFlag);
    //   else if (flags & 2)
    //       v8 = holder(*(a2 + 12))->vtbl[36 / 4](*(a2 + 12), v10, 0, argFlag);
    //   else if (flags & 4)
    //       v8 = holder(*(a2 + 16))->vtbl[64 / 4](*(a2 + 16), a3, v10, 0, argFlag);
    //   else
    //       return 0;
    //   *this = v8;
    //   if (!v8) {
    //       *(a2 + 40) = v10[0];
    //       return v10[1];
    //   }
    //   return 0;
    // UNRESOLVED: The dispatch descriptor layout at a2 (holder pointers at +8/+12/+16, default flags at +24, out slot at +40) and the semantics of the derived per-call argument flag (0 or 16) are not documented in the packet
    // UNRESOLVED: The return contract is asymmetric: the non-null path returns 0 while the null path returns v10[1], so a2+40/v10 act as out-parameters whose meaning is unknown
}
