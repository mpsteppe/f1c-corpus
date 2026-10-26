// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0EB0
// Canonical corpus name: Options_Setup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Options_Setup_004a0eb0.c

void UnknownObject::Options_Setup()
{
    // Options/setup screen handler. Logs entry when the device-path string match succeeds, then dispatches on session state flags: if the init guard is set it forces init state and returns; if the sub-mode selector is set it either clears the setup flag or reports waiting; otherwise it runs the main setup processing loop (frame counter increment, state checks, overlay timer, timer arithmetic, session/queue processing) until the exit flag or a result of -1 or 1 is returned.
    // GUARD: Guard: when StringSplitLoop(2, aDDevF119992002_17, 1169) returns nonzero, options entry is detected. [callee:0x004D7A50, global:0x005CD064, source:raw]
    // CALL: DebugLogWrite(&dword_8AD25C, aEnteredOptions): log the options-entry message into the debug buffer. [callee:0x004D7AA0, global:0x008AD25C, global:0x005CD048, source:raw]
    // GUARD: Guard: if byte_7CE260 (init guard) is nonzero, take the early-setup path. [global:0x007CE260, source:raw]
    // ASSIGNMENT: byte_7C5690 = 1: set the init-state flag. [global:0x007C5690, source:raw]
    // RETURN: return 0 after forcing the init state. [source:raw]
    // GUARD: Guard: else if dword_7CE264 (sub-mode selector) is nonzero, take the session-state path. [global:0x007CE264, source:raw]
    // GUARD: Guard: within that path, if byte_5CCFE4 (setup flag) is set, clear it and finish. [global:0x005CCFE4, source:raw]
    // ASSIGNMENT: byte_5CCFE4 = 0: clear the setup flag. [global:0x005CCFE4, source:raw]
    // RETURN: return 0 after clearing the setup flag. [source:raw]
    // RETURN: return 1 when the setup flag is clear: report waiting for setup completion. [source:raw]
    // CALL: ShortComputation_4b50(&dword_5EA43C): perform the short computation on the setup-dir suffix before the loop. [callee:0x00404B50, global:0x005EA43C, source:raw]
    // LOOP: Infinite main processing loop; exits via the byte_7CE25C break guard or via v2 result checks. [source:raw]
    // CALL: ConditionalInit(&unk_8AFE18): (re)initialize the conditional timer state each iteration. [callee:0x004F9F00, global:0x008AFE18, source:raw]
    // ASSIGNMENT: v3 = dbl_8AFE90: read the double-precision rate constant into the float argument. [global:0x008AFE90, source:raw]
    // CALL: sub_4537B0(&ppvOut, v3): process the module pointer array with the rate value. [callee:0x004537B0, global:0x007CA590, source:raw]
    // CALCULATION: v1 = dword_7CE250++: post-increment the frame counter and pass the prior value. [global:0x007CE250, source:raw]
    // CALL: v2 = sub_485B90(v1, byte_7CE25F): session processing; returns a state result consumed by the loop. [callee:0x00485B90, global:0x007CE25F, source:raw]
    // CALL: TextOverlayDisplayTimer(&flt_5EA618): drive text overlay display timing from the pointer-table entry. [callee:0x004186F0, global:0x005EA618, source:raw]
    // CALL: ArithmeticComparison_9ad0(&unk_8AFE18): update the conditional timer state. [callee:0x004F9AD0, global:0x008AFE18, source:raw]
    // CALL: sub_404B60(&dword_5EA43C): process the setup-dir suffix data each iteration. [callee:0x00404B60, global:0x005EA43C, source:raw]
    // GUARD: Guard: if byte_7CE25C (exit flag) is set, break out of the loop. [global:0x007CE25C, source:raw]
    // RETURN: return 1 if v2 == -1 (pause/error result). [source:raw]
    // RETURN: return 0 if v2 == 1 (continue/complete result). [source:raw]
    // CALL: ConditionalStateReset(&unk_8AFE18): reset the conditional timer state before the next iteration. [callee:0x004F9F30, global:0x008AFE18, source:raw]
    // CALL: sub_4A1830(&unk_7CE2A4): process the session-queue object before the next iteration. [callee:0x004A1830, global:0x007CE2A4, source:raw]
    // ASSIGNMENT: byte_7CE25C = 0: clear the exit flag after the break before returning. [global:0x007CE25C, source:raw]
    // RETURN: return 0 after the loop exits normally. [source:raw]

    // Conservative worker pseudocode:
    //   int Options_Setup() {
    //     if (StringSplitLoop(2, aDDevF119992002_17, 1169))
    //       DebugLogWrite(&dword_8AD25C, aEnteredOptions);
    //     if (byte_7CE260) { byte_7C5690 = 1; return 0; }
    //     if (dword_7CE264) {
    //       if (byte_5CCFE4) { byte_5CCFE4 = 0; return 0; }
    //       return 1;
    //     }
    //     ShortComputation_4b50(&dword_5EA43C);
    //     while (1) {
    //       ConditionalInit(&unk_8AFE18);
    //       v3 = dbl_8AFE90;
    //       sub_4537B0(&ppvOut, v3);
    //       v1 = dword_7CE250++;
    //       v2 = sub_485B90(v1, byte_7CE25F);
    //       TextOverlayDisplayTimer(&flt_5EA618);
    //       ArithmeticComparison_9ad0(&unk_8AFE18);
    //       sub_404B60(&dword_5EA43C);
    //       if (byte_7CE25C) break;
    //       if (v2 == -1) return 1;
    //       if (v2 == 1) return 0;
    //       ConditionalStateReset(&unk_8AFE18);
    //       sub_4A1830(&unk_7CE2A4);
    //     }
    //     byte_7CE25C = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the v2 return values from sub_485B90 (-1 vs 1) are inferred only from the branch outcomes.
    // UNRESOLVED: Purpose of the byte_7CE25F argument passed to sub_485B90 is not established here.
    // UNRESOLVED: Meaning of dbl_8AFE90 and the float argument consumed by sub_4537B0 is unknown.
    // UNRESOLVED: The owner class of this handler is unproven; the ABI name Options_Setup is corpus-legacy, not runtime-confirmed.
}
