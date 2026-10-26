// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5D10
// Canonical corpus name: AIStateMachineWithModeDispatch
// Owner: F1CPitMachine [CONFIRMED]
// Raw source: functions/AIStateMachineWithModeDispatch_004a5d10.c

void F1CPitMachine::AIStateMachineWithModeDispatch()
{
    // Main AI state-machine dispatcher. Reads the mode byte from event record a2+8; if this+0x184 differs, stores it and calls AIPitStrategyState on the vehicle pointer at this+0. Copies the float at a2+4 into this+0x188. Reads vehicle sub-state obj[3250] (obj+0x32C8); when it is 2 or 3 dispatches on the mode this+0x184: 2 -> sub_4A5EA0, 0 -> sub_4A5F20. Always calls ConditionalDispatch_55e0(this). Then for mode 1 or 2 queries VehicleControlEnabled(this) and, if this+8 is set, calls sub_4A3390(this+8, enabled==0); calls ConditionalDelegateDispatch(this+0, v14, v13); if this+0x10 is set calls sub_4A3320(this+0x10, v14, v13); if this+0xC is set returns sub_4A3320(this+0xC, v14, v13). For mode 0, if this+8 is set returns FlagBasedLoopConditionalCall(this+8). Otherwise returns the stored mode.
    // ASSIGNMENT: Read the mode byte v2 from a2+8 (event record). [source:raw]
    // GUARD: If this[97] (this+0x184) != v2, proceed to update the mode. [field:this:0x00000184, source:raw]
    // ASSIGNMENT: On mode change: this[97] (this+0x184) = v2. [field:this:0x00000184, source:raw]
    // CALL: On mode change: call AIPitStrategyState(this[0]), passing the vehicle pointer at this+0x0. [callee:0x0041A200, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Copy the event value: this[98] (this+0x188) = float at a2+4. [field:this:0x00000188, source:raw]
    // GUARD: Read the vehicle sub-state v5 = obj[3250] (obj+0x32C8) via the vehicle pointer at this+0; branch when v5 == 2 or v5 == 3. [field:obj:0x000032C8, field:this:0x00000000, source:raw]
    // GUARD: Within the 2-or-3 branch, read mode v6 = this[97] (this+0x184); dispatch when v6 == 0 or v6 == 2. [field:this:0x00000184, source:raw]
    // CALL: If mode v6 == 2: call sub_4A5EA0(this). [callee:0x004A5EA0, source:raw]
    // CALL: If mode v6 == 0: call sub_4A5F20(this). [callee:0x004A5F20, source:raw]
    // CALL: Always dispatch via ConditionalDispatch_55e0(this). [callee:0x004A55E0, source:raw]
    // GUARD: Re-read result = this[97] (this+0x184); proceed when result is nonzero, then branch on result == 1 or result == 2. [field:this:0x00000184, source:raw]
    // CALL: If mode is 1 or 2: query v9 = VehicleControlEnabled(this). [callee:0x004A6DB0, source:raw]
    // GUARD: If v10 = this[2] (this+0x8) is nonzero, call sub_4A3390(v10, v9 == 0). [callee:0x004A3390, field:this:0x00000008, source:raw]
    // CALL: If mode is 1 or 2: result = ConditionalDelegateDispatch(this[0], v14, v13). [callee:0x004D1100, field:this:0x00000000, source:raw]
    // GUARD: If v11 = this[4] (this+0x10) is nonzero, call sub_4A3320(v11, v14, v13) and store its result. [callee:0x004A3320, field:this:0x00000010, source:raw]
    // CALL: If v12 = this[3] (this+0xC) is nonzero, return sub_4A3320(v12, v14, v13). [callee:0x004A3320, field:this:0x0000000C, source:raw]
    // GUARD: Mode 0 path: if v8 = this[2] (this+0x8) is nonzero, return FlagBasedLoopConditionalCall(v8). [callee:0x004A3440, field:this:0x00000008, source:raw]
    // RETURN: Otherwise return result (the stored mode this+0x184). [field:this:0x00000184, source:raw]

    // Conservative worker pseudocode:
    //   int AIStateMachineWithModeDispatch(dispatcher* this, record* a2) {
    //     v2 = *(byte*)(a2 + 8);
    //     if (this[97] != v2) {
    //       this[97] = v2;
    //       AIPitStrategyState(this[0]);
    //     }
    //     this[98] = *(float*)(a2 + 4);
    //     v5 = this[0][3250];
    //     if (v5 == 2 || v5 == 3) {
    //       v6 = this[97];
    //       if (v6) { if (v6 == 2) sub_4A5EA0(this); }
    //       else sub_4A5F20(this);
    //     }
    //     ConditionalDispatch_55e0(this);
    //     result = this[97];
    //     if (result) {
    //       if (result == 1 || result == 2) {
    //         v9 = VehicleControlEnabled(this);
    //         if (this[2]) sub_4A3390(this[2], v9 == 0);
    //         result = ConditionalDelegateDispatch(this[0], v14, v13);
    //         if (this[4]) result = sub_4A3320(this[4], v14, v13);
    //         if (this[3]) return sub_4A3320(this[3], v14, v13);
    //       }
    //     } else {
    //       if (this[2]) return FlagBasedLoopConditionalCall(this[2]);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Globals dword_5EB978 and dword_8ACEE0 are listed as read (R) but do not appear in the raw source; their roles here are unclear.
    // UNRESOLVED: The event record a2 layout (mode byte at +8, value float at +4) is an out-of-packet parameter whose structure is only partially evidenced.
    // UNRESOLVED: The v14/v13 buffers are outputs of ConditionalDelegateDispatch consumed by sub_4A3320; their contents and semantics are unknown.
    // UNRESOLVED: The identification of sub_4A5EA0 as pits-under-red and the vehicle sub-state meaning of obj+0x32C8 is DERIVED from the existing analysis, not proven by this packet.
    // UNRESOLVED: Callers StateChangeNotify (004A5C80) and sub_4B3400 are known from the packet but their call context is not described by the raw source.
}
