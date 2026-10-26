// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D9FE0
// Canonical corpus name: VehicleStateUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleStateUpdate_004d9fe0.c

void UnknownObject::VehicleStateUpdate()
{
    // Updates a per-vehicle lap-gap state object. Reads one of two time values through the player vehicle pointer dword_7C54E0 at offsets 16592 and 16596, records which source was chosen as a byte flag at this+0x18 and stores the chosen value at this+0x1C, then calls LapTimeGapCalculation to compute the gap written into the float at this+0x14. A non-zero gap-calculation return, a zero-or-negative gap at this+0x14, or a non-zero gap flag v6 each cause VTableDispatchWithFieldClear on this; otherwise the function falls through returning v6.
    // GUARD: Initialize the gap flag v6 to 0 before any comparison path runs. [source:raw]
    // GUARD: Select comparison source on the player vehicle pointer dword_7C54E0: a non-zero value at offset 16592 selects path A; otherwise path B is taken only when offset 16596 is non-zero, else flow jumps to LABEL_6 skipping the comparison. [global:0x007C54E0, source:raw]
    // ASSIGNMENT: Path A: set the byte flag at this+0x18 to 1 (comparing against offset 16592) and store the offset-16592 value into this+0x1C. [field:this:0x00000018, field:this:0x0000001C, global:0x007C54E0, source:raw]
    // CALL: Path A: LapTimeGapCalculation(offset-16592 value, dword_7C54E0, gap output at this+0x14, &v6) computes the gap and the v6 flag. [callee:0x0049B6D0, field:this:0x00000014, global:0x007C54E0, source:raw]
    // ASSIGNMENT: Path B: set the byte flag at this+0x18 to 0 (comparing against offset 16596) and store the offset-16596 value into this+0x1C. [field:this:0x00000018, field:this:0x0000001C, global:0x007C54E0, source:raw]
    // CALL: Path B: LapTimeGapCalculation(dword_7C54E0, offset-16596 value, gap output at this+0x14, &v6) computes the gap and the v6 flag. [callee:0x0049B6D0, field:this:0x00000014, global:0x007C54E0, source:raw]
    // GUARD: If v3 (the gap-calculation return) is non-zero, return VTableDispatchWithFieldClear(this). [callee:0x004D7E30, source:raw]
    // GUARD: At LABEL_6: if the float gap at this+0x14 is <= 0.0, return VTableDispatchWithFieldClear(this). [callee:0x004D7E30, field:this:0x00000014, source:raw]
    // GUARD: If the gap flag v6 is non-zero, return VTableDispatchWithFieldClear(this). [callee:0x004D7E30, source:raw]
    // RETURN: Fall-through path returns v6 (zero when no dispatch fired). [source:raw]
    // CALL: Invoked from sub_4D9F80 as the vehicle lap-gap state update step. [caller:0x004D9F80, source:raw]

    // Conservative worker pseudocode:
    //   int VehicleStateUpdate(this) {
    //     v6 = 0;
    //     if (*(DWORD*)(dword_7C54E0 + 16592)) {
    //       *(BYTE*)(this + 24) = 1;
    //       *(DWORD*)(this + 28) = *(DWORD*)(dword_7C54E0 + 16592);
    //       v3 = LapTimeGapCalculation(*(DWORD*)(dword_7C54E0 + 16592), dword_7C54E0, (float*)(this + 20), &v6);
    //     } else if (*(DWORD*)(dword_7C54E0 + 16596)) {
    //       *(BYTE*)(this + 24) = 0;
    //       *(DWORD*)(this + 28) = *(DWORD*)(dword_7C54E0 + 16596);
    //       v3 = LapTimeGapCalculation(dword_7C54E0, *(DWORD*)(dword_7C54E0 + 16596), (float*)(this + 20), &v6);
    //     } else goto LABEL_6;
    //     if (v3) return VTableDispatchWithFieldClear(this);
    //   LABEL_6:
    //     if (*(float*)(this + 20) <= 0.0) return VTableDispatchWithFieldClear(this);
    //     if (v6) return VTableDispatchWithFieldClear(this);
    //     return v6;
    //   }
    // UNRESOLVED: Semantics of the dword_7C54E0 offsets 16592 and 16596 (the two comparison time sources) are not named in the packet; they may be lap or segment time slots on the player vehicle.
    // UNRESOLVED: flt_59E440 appears in the packet global set but not in the raw source text; the existing analysis labels it a zero threshold, unconfirmed.
    // UNRESOLVED: unk_7CE234 appears in the packet global set but not in the raw source text; role unresolved.
    // UNRESOLVED: Polarity of the byte flag at this+0x18 (1 for offset 16592, 0 for offset 16596) and the exact purpose of the v6 gap flag are understood only at the structural level.
}
