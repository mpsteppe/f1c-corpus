// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DBAC3
// Canonical corpus name: HUDFlagRendererSecondary
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HUDFlagRendererSecondary_004dbac3.c

void UnknownObject::HUDFlagRendererSecondary()
{
    // HUD flag/status indicator composer. Builds a short status string into a stack buffer by appending one-character indicators: '>' (62) when the caller-supplied flag a1 is non-zero, 'A' (65) when VehicleFlagCheck() is true, 'f' (102) when PitStateFlagCheck() is true, '?' (63) when DisqualificationCheck() is true, and 'B' (66) when the race-phase global dword_7C56A8 equals 8. If any indicator was appended, the string is null-terminated and rendered with UITextRenderWithScale at (a3+5, a4) in white at scale 2.0; otherwise the DisqualificationCheck result is returned.
    // GUARD: If a1 (caller-supplied flag) is non-zero, write '>' (62) as the first indicator and set the append index to 1. [source:raw]
    // GUARD: If VehicleFlagCheck() returns true, append 'A' (65) to the indicator buffer. [callee:0x0049BB20, source:raw]
    // GUARD: If PitStateFlagCheck() returns true, append 'f' (102) to the indicator buffer. [callee:0x0049BA90, source:raw]
    // GUARD: If DisqualificationCheck() returns true, append '?' (63) to the indicator buffer. [callee:0x0049BAB0, source:raw]
    // GUARD: If the race-phase global dword_7C56A8 equals 8, append 'B' (66) to the indicator buffer. [global:0x007C56A8, source:raw]
    // GUARD: If any indicator was appended (append index greater than 0), null-terminate the buffer and render it via UITextRenderWithScale(buffer, a3+5, a4, white, alignment 0, style 3, scale 2.0, 2.0). [callee:0x004D7E40, source:raw]
    // RETURN: When nothing was appended, return the DisqualificationCheck result. [source:raw]

    // Conservative worker pseudocode:
    //   idx = 0;
    //   if (a1) { buf[0] = 62; idx = 1; }
    //   if (VehicleFlagCheck()) buf[idx++] = 65;
    //   if (PitStateFlagCheck()) buf[idx++] = 102;
    //   result = DisqualificationCheck();
    //   if (result) buf[idx++] = 63;
    //   if (dword_7C56A8 == 8) buf[idx++] = 66;
    //   if (idx > 0) { buf[idx] = 0; return UITextRenderWithScale(buf, a3 + 5, a4, 0xFFFFFF, 0, 3, 2.0, 2.0); }
    //   return result;
    // UNRESOLVED: flt_5ACF48, flt_5ACF4C and unk_7CE234 are listed as packet globals but are not read anywhere in this function's raw source; they appear only in the existing_analysis fill, so they are recorded here.
    // UNRESOLVED: The '>' (62), 'A' (65), 'f' (102), '?' (63) and 'B' (66) indicator meanings are inferred from the check function names and the fill.
    // UNRESOLVED: The UITextRenderWithScale color literal is written as 0xFFFFFF in the raw source; the exact color role is not named in the packet.
}
