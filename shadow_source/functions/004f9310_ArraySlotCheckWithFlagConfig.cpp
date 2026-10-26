// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9310
// Canonical corpus name: sub_4F9310
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F9310_004f9310.c

void UnknownObject::ArraySlotCheckWithFlagConfig()
{
    // Builds a configuration flag word from display/mode/player-state globals, stores the caller-supplied index into dword_8AFE74, then calls ArraySlotCheckConditionalCall with array and sizing globals plus the computed flag word. On a failure result, it composes a relocated path string and logs "CUBE error : %s" through the debug-message buffer. Returns 1 early when dword_8AFE68 is zero, else returns 0. Called by VidMan_Enter (004fa000).
    // GUARD: If dword_8AFE68 is zero, return 1 immediately without any check [global:0x008AFE68, source:raw]
    // CALCULATION: v2 = (byte_5EC4A4 == 0) + 1; base flag word derived from the player-display-state byte [global:0x005EC4A4, source:raw]
    // ASSIGNMENT: dword_8AFE7C = ((byte_5EC4A4 == 0) + 1) & 1; derived single-bit flag written to dword_8AFE7C [global:0x005EC4A4, global:0x008AFE7C, source:raw]
    // CALCULATION: switch on dword_5EC4B0: case 2 ORs 0x20, case 3 ORs 0x100, case 4 ORs 0x40, case 6 ORs 0x400, case 16 ORs 0x100000 into v2 [global:0x005EC4B0, source:raw]
    // CALCULATION: If byte_5EC4A6 is nonzero, OR 0x80 into v2 [global:0x005EC4A6, source:raw]
    // ASSIGNMENT: dword_8AFE74 = a1; store the caller-supplied index [global:0x008AFE74, source:raw]
    // CALL: Call ArraySlotCheckConditionalCall(dword_8AFE6C, dword_5D6D60, dword_5D6D64, dword_5D6D68, v2, dword_8AFE78) and branch on its result [callee:0x0055BFF0, global:0x008AFE6C, global:0x005D6D60, global:0x005D6D64, global:0x005D6D68, global:0x008AFE78, source:raw]
    // GUARD: If ArraySlotCheckConditionalCall returns nonzero, enter the error-reporting branch [callee:0x0055BFF0, source:raw]
    // CALL: StringRelocationCopy(0, v3) fills the local 256-byte buffer with a relocated path string [callee:0x0053C5B0, source:raw]
    // GUARD: If StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_26, 484) returns nonzero, log the composed message [callee:0x004D7A50, global:0x008AD25C, global:0x005D6DC4, source:raw]
    // CALL: DebugLogWrite(dword_8AD25C, "CUBE error : %s", v3) writes the formatted error into the debug-message buffer; the format string constant is aCubeErrorS_0 [callee:0x004D7AA0, global:0x008AD25C, global:0x005D6DB4, source:raw]
    // RETURN: Return 0 after the check/logging path completes [function:0x004F9310, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8AFE68 == 0) return 1;
    //   v2 = (byte_5EC4A4 == 0) + 1;
    //   dword_8AFE7C = ((byte_5EC4A4 == 0) + 1) & 1;
    //   switch (dword_5EC4B0) { case 2: v2 |= 0x20; break; case 3: v2 |= 0x100; break; case 4: v2 |= 0x40; break; case 6: v2 |= 0x400; break; case 16: v2 |= 0x100000; break; }
    //   if (byte_5EC4A6 != 0) v2 |= 0x80;
    //   dword_8AFE74 = a1;
    //   if (ArraySlotCheckConditionalCall(dword_8AFE6C, dword_5D6D60, dword_5D6D64, dword_5D6D68, v2, dword_8AFE78)) {
    //     StringRelocationCopy(0, v3);
    //     if (StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_26, 484))
    //       DebugLogWrite(dword_8AD25C, "CUBE error : %s", v3);
    //   }
    //   return 0;
    // UNRESOLVED: dword_8AFE64 is flagged as a read global by packet facts but never appears in the raw decompiled source; its role here is not verifiable
    // UNRESOLVED: Semantics of the flag bits in v2 and the dword_5D6D60/5D6D64/5D6D68 arguments to ArraySlotCheckConditionalCall are inferred from naming only
}
