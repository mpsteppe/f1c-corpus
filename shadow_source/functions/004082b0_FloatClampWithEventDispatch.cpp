// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004082B0
// Canonical corpus name: FloatClampWithEventDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatClampWithEventDispatch_004082b0.c

void UnknownObject::FloatClampWithEventDispatch()
{
    // Per-frame float widget update: computes a scaled fill amount from the current value and a scale factor, dispatches a conditional event when the value is zero versus non-zero (toggling a byte flag), renders two 2D fill rectangles onto a UI surface, then exponentially clamps the current value toward a target bound using a global cooling rate. Runs on the frame path; the ABI lead names it Float_Clamp_with_Event_Dispatch.
    // ASSIGNMENT: Compute v9 = flt_5BE8F8 * *this * this[4] and v10 = this[4] - v9, deriving a scaled fill amount and its complement from the current value and the scale factor field [field:this:0x00000000, field:this:0x00000010, global:0x005BE8F8, source:raw]
    // GUARD: Zero-value path: if *this == 0.0 and the byte flag at this+0x15 is set, dispatch the conditional event (ConditionalBranchByFlag with 1) and clear the flag [callee:0x004D8860, field:this:0x00000000, field:this:0x00000015, source:raw]
    // GUARD: Non-zero path: if dword_8AD2A0 != -1 (event dispatch enabled), dispatch the conditional event (ConditionalBranchByFlag with 0) and set the byte flag at this+0x15 [callee:0x004D8860, global:0x008AD2A0, field:this:0x00000015, source:raw]
    // CALL: UI rendering: two F_2DSurfaceBlitFill calls on the surface dword_8B8DC8, using CRTFtol conversions of this[0xC] and the v9/v10 fill amounts to draw the filled and remaining rectangle portions [callee:0x005404D0, callee:0x00587BDC, global:0x008B8DC8, field:this:0x0000000C, source:raw]
    // CALCULATION: Exponential clamp toward the bound: if *this < this[1], add dbl_8AFE90 * this[2] and cap at this[1]; if *this > this[1], subtract dbl_8AFE90 * this[2] and floor at this[1], so the value relaxes onto the target each frame [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, global:0x008AFE90, source:raw]
    // RETURN: Function returns void; invoked per frame by SafeDivisionWithZeroGuard (00408450) and ShortComputation_f070 (0049F070) [function:0x004082B0, caller:0x00408450, caller:0x0049F070, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   v9 = flt_5BE8F8 * value * scale; v10 = scale - v9;
    //   if (value == 0.0f) {
    //     if (eventFlag) { ConditionalBranchByFlag(1); eventFlag = 0; }
    //   } else {
    //     if (dword_8AD2A0 != -1) { ConditionalBranchByFlag(0); eventFlag = 1; }
    //     F_2DSurfaceBlitFill(dword_8B8DC8, 0, 0, ftol(this[0xC]), ftol(v9), 0);
    //     F_2DSurfaceBlitFill(dword_8B8DC8, 0, ftol(v10), ftol(this[0xC]), ftol(this[0x10] - v10 + 1.0), 0);
    //   }
    //   if (value > bound)      { value -= dbl_8AFE90 * cooling; if (value < bound) value = bound; }
    //   else if (value < bound) { value += dbl_8AFE90 * cooling; if (value > bound) value = bound; }
    // UNRESOLVED: Four read-only globals flagged by the packet (flt_59E43C, flt_59E440, dword_8AD298, dword_8B78A0) appear nowhere in the raw decompiled source; their roles are unverifiable from this packet
}
