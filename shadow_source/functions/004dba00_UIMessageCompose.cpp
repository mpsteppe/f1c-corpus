// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DBA00
// Canonical corpus name: UIMessageCompose
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIMessageCompose_004dba00.c

void UnknownObject::UIMessageCompose()
{
    // Composes a HUD warning-icon string into an 8-byte local buffer by querying three warning conditions in order: a general warning indicator (sub_49B9A0, appends icon byte -126), a fuel/low-fuel warning (FuelWeightComputation, appends 'D' = 68), and a two-state indicator (sub_49BA30, appends -116 for state 1 or -115 for state 2). If any warning is active (v2 > 0) the buffer is null-terminated and rendered with UITextRenderWithScale at x = a1 + 275, y = a2; otherwise the function returns the last state code from sub_49BA30.
    // ASSIGNMENT: v2 = 0: initialize the warning-buffer write index [source:raw]
    // CALL: Calls sub_49B9A0 to query the general warning indicator state [callee:0x0049B9A0, source:raw]
    // GUARD: If sub_49B9A0 returned nonzero, the general warning indicator is active [callee:0x0049B9A0, source:raw]
    // ASSIGNMENT: v4[0] = -126 (general warning icon byte) and v2 = 1 when the general warning is active [source:raw]
    // CALL: Calls FuelWeightComputation to query the fuel/low-fuel warning state [callee:0x0049BA50, source:raw]
    // GUARD: If FuelWeightComputation returned nonzero, the fuel warning is active [callee:0x0049BA50, source:raw]
    // ASSIGNMENT: v4[v2++] = 68 ('D' fuel icon byte), advancing the write index [source:raw]
    // CALL: Calls sub_49BA30 to query the state indicator code, storing it into result [callee:0x0049BA30, source:raw]
    // GUARD: If result == 1, state indicator 1 is active [source:raw]
    // ASSIGNMENT: v4[v2] = -116 (state-1 icon byte) when result == 1 [source:raw]
    // CALL: Re-calls sub_49BA30 in the else path to re-query the state indicator code [callee:0x0049BA30, source:raw]
    // GUARD: In the else path, if result != 2 jump to the render check (no state icon appended) [source:raw]
    // ASSIGNMENT: v4[v2] = -115 (state-2 icon byte) when result == 2 [source:raw]
    // ASSIGNMENT: ++v2: advance the write index after the state-icon block [source:raw]
    // GUARD: If v2 > 0, at least one warning icon is present in the buffer [source:raw]
    // ASSIGNMENT: v4[v2] = 0: null-terminate the composed warning string [source:raw]
    // CALL: Renders the composed warning string with UITextRenderWithScale at x = a1 + 275, y = a2, color 0xFFFFFF, flags 1/3 and scale 2.0/2.0 [callee:0x004D7E40, source:raw]
    // RETURN: Returns the UITextRenderWithScale result when warnings were rendered [callee:0x004D7E40, source:raw]
    // RETURN: Returns result (the last sub_49BA30 value) when v2 <= 0, i.e. no warning is active [source:raw]

    // Conservative worker pseudocode:
    //   v2 = 0;
    //   if (sub_49B9A0()) {
    //     v4[0] = -126;
    //     v2 = 1;
    //   }
    //   if (FuelWeightComputation())
    //     v4[v2++] = 68;
    //   result = sub_49BA30();
    //   if (result == 1) {
    //     v4[v2] = -116;
    //   } else {
    //     result = sub_49BA30();
    //     if (result != 2) goto render_check;
    //     v4[v2] = -115;
    //   }
    //   ++v2;
    //   render_check:
    //   if (v2 > 0) {
    //     v4[v2] = 0;
    //     return UITextRenderWithScale((int)v4, a1 + 275, a2, 0xFFFFFF, 1, 3, 2.0, 2.0);
    //   }
    //   return result;
    // UNRESOLVED: Three read-only globals are flagged by packet facts (flt_5ACF50, flt_5ACF54, unk_7CE234) but do not appear in the raw decompiled source; the existing analysis suggests they are text-render parameters (likely consumed by UITextRenderWithScale), but their role is not verifiable from this function alone
    // UNRESOLVED: The on-screen meaning of the four icon bytes (-126, 68, -116, -115) and of the two state codes (1 and 2) is not established by this packet; interpretation is DERIVED from the existing analysis
}
