// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042EAA0
// Canonical corpus name: AIGearSelectionSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIGearSelectionSet_0042eaa0.c

void UnknownObject::AIGearSelectionSet()
{
    // Sets a per-wheel gear selection inside a multi-dimensional indexed structure (index v5 = (a3 + 11*a2) << 6 into a per-driver/per-wheel matrix). If a4 > 0 clamps the new gear to a4 or maxGear-1 and writes it to slot+20; if a4 <= 0 zeroes the previous value at index+196. When the enable byte this+0x19A5 is non-zero, runs TrackConfig and fires EventTriggerOnStateChange into a related row. TrackConfig runs again unconditionally. If the new slot+20 gear differs from the saved value, sets the dirty flags this+0x19A4 and this+0x0 to 1. Returns the previously saved gear value. Invoked by IndexedCallWith1Increment per gear slot.
    // CALCULATION: v5 = (a3 + 11*a2) << 6: compute the row index into the per-driver/per-wheel matrix; v7 = &this[v5 + 176] is the slot base. [source:raw]
    // CALCULATION: v11 = *(DWORD*)&this[v5 + 196]: read and save the previously selected gear value. [source:raw]
    // GUARD: Positive-gear path: if a4 > 0, read max gear *(v5+192); if a4 < max write a4 to slot+20, otherwise write max-1, clamping the gear into the valid range. [source:raw]
    // ASSIGNMENT: Clear path: if a4 <= 0, write 0 into the saved-gear slot at index v5 + 196. [source:raw]
    // GUARD: Enable guard: only when the byte this+0x19A5 (index 6565) is non-zero do the track-config and event dispatch run. [field:this:0x000019A5, source:raw]
    // CALL: TrackConfig(this, a2, a3) runs inside the enable guard. [callee:0x0042E530, source:raw]
    // CALL: EventTriggerOnStateChange(this, v7, &this[704*v9 + 176 + 64*a3]) fires when the enable byte is set; v9 is a selector index derived from a2 (a2==0 -> 1, a2==1 -> 0, a2==2 -> 2). [callee:0x0042E470, source:raw]
    // CALL: TrackConfig(this, a2, a3) runs again unconditionally after the event block. [callee:0x0042E530, source:raw]
    // STATE_TRANSITION: If the new gear at slot+20 differs from the saved v11, mark the change: set this+0x19A4 (index 6564) to 1 and this+0x0 to 1. [field:this:0x000019A4, field:this:0x00000000, source:raw]
    // RETURN: Return the previously saved gear value v11; the function is called by IndexedCallWith1Increment (00467340). [function:0x0042EAA0, caller:0x00467340, source:raw]

    // Conservative worker pseudocode:
    //   v5 = (a3 + 11 * a2) << 6;
    //   v7 = &this[v5 + 176];
    //   v11 = *(DWORD*)&this[v5 + 196];
    //   if (a4 > 0) {
    //     v8 = *(DWORD*)&this[v5 + 192];
    //     *(DWORD*)(v7 + 20) = (a4 < v8) ? a4 : v8 - 1;
    //   } else {
    //     *(DWORD*)&this[v5 + 196] = 0;
    //   }
    //   if (this[6565]) {
    //     TrackConfig(this, a2, a3);
    //     // v9 = selector from a2
    //     EventTriggerOnStateChange(this, v7, &this[704*v9 + 176 + 64*a3]);
    //   }
    //   TrackConfig(this, a2, a3);
    //   if (*(DWORD*)(v7 + 20) != v11) { this[6564] = 1; *this = 1; }
    //   return v11;
    // UNRESOLVED: The matrix layout (11 rows, a2 vs a3 semantics, stride 64) is inferred from the index arithmetic only; row/driver meaning is unconfirmed.
    // UNRESOLVED: The v9 selector mapping and the target row of EventTriggerOnStateChange (704*v9 + 176 + 64*a3) are unconfirmed.
    // UNRESOLVED: Owner object identity and the meaning of the enable byte this+0x19A5 are not established by the packet.
}
