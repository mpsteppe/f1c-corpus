// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058DA70
// Canonical corpus name: Trandisp1
// Owner: MSVCRTInternal [DERIVED]
// Raw source: functions/Trandisp1_0058da70.c

void MSVCRTInternal::FloatDisplayControlWordAndDispatch()
{
    // Legacy MSVC CRT float-display control-word and dispatch helper (ABI lead name 'trandisp1'). Selects an x87 FPU control word based on the format-mode byte at a1+14 (mode 5 selects control word 63, otherwise 4927), points EBX at the unk_5E6C6C translation table, examines ST0 with fxam, records caller state into a caller-provided buffer (a3), then builds a dispatch byte via ROL1((2 * byte(a3-159)) >> 1, 1) & 0xF and calls through the virtual table at a1+16 with argument a2 & 0x404. Part of CRT float-formatting infrastructure rather than game logic.
    // GUARD: Test the format-mode byte at this+0xE (a1+14) for equality with 5; the branch selects which FPU control word is installed. [guard:0, field:this:0x0000000E, source:raw]
    // ASSIGNMENT: Write the FPU control word to the caller buffer at (a3-162): when mode is 5, high byte is HIBYTE(*(a3-164)) & 0xFC | 2 with low byte 63; otherwise the word is 4927. [source:raw]
    // ASSIGNMENT: Set EBX to &unk_5E6C6C, the base of the xlat translation table used to map the dispatch byte to a vtable slot index. [global:0x005E6C6C, source:raw]
    // ASSIGNMENT: Store caller state into the buffer: a1 into (a3-148), FPU status word a4 into (a3-160), and byte 0 into (a3-144). [source:raw]
    // CALCULATION: Compute the dispatch byte as ROL1((char)(2 * *(a3-159)) >> 1, 1) then mask to the low nibble with a2 & 0xF; feed it to xlat using the unk_5E6C6C table. [global:0x005E6C6C, source:raw]
    // CALL: Indirect __thiscall through the virtual table at (a1+16), slot selected by the translated dispatch byte, with argument a2 & 0x404; return its result. [source:raw]
    // RETURN: Return the value produced by the vtable dispatch call. [source:raw]
    // CALL: Called by Cintrindisp1 (0x0059067E) and Ctrandisp1CRTFloatDisplayFormat (0x0059083B) as part of the CRT float-display path. [caller:0x0059067E, caller:0x0059083B]

    // Conservative worker pseudocode:
    //   int FloatDisplayControlWordAndDispatch(int a1, __int16 a2, int a3, __int16 fpcw, double st0) {
    //     __int16 cw;
    //     if (*(char*)(a1 + 14) == 5) {
    //       cw = (HIBYTE(*(short*)(a3 - 164)) & 0xFC | 2) << 8 | 63;
    //     } else {
    //       cw = 4927;
    //     }
    //     *(short*)(a3 - 162) = cw;
    //     EBX = &unk_5E6C6C;
    //     fxam;
    //     *(int*)(a3 - 148) = a1;
    //     *(short*)(a3 - 160) = fpcw;
    //     *(char*)(a3 - 144) = 0;
    //     unsigned char idx = ROL1((char)(2 * *(char*)(a3 - 159)) >> 1, 1) & 0xF;
    //     xlat idx via unk_5E6C6C;
    //     return (*(void (__thiscall **)(int))(idx + a1 + 16))(a2 & 0x404);
    //   }
    // UNRESOLVED: unk_5E6C6C is treated as an xlat translation table [DERIVED]; its layout and the meaning of translated slot indices are not established.
    // UNRESOLVED: Semantics of the virtual dispatch at (a1+16) and of the argument a2 & 0x404 are unknown; this is CRT float-formatting machinery.
    // UNRESOLVED: The exact role of the fxam on ST0 and how it interacts with the caller-provided buffer is not captured by the raw source snippet.
}
