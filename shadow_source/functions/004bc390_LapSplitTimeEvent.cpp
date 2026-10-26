// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC390
// Canonical corpus name: LapSplitTimeEvent
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LapSplitTimeEvent_004bc390.c

void UnknownObject::LapSplitTimeEvent()
{
    // Processes a lap/split timing event. Aborts early when a ride-height threshold is exceeded, reads an event-type flag via FlagPropertyGetter(2048), then routes on the resulting event type (0/1/2) against the current lap/sector state, returning without recording on any mismatch. On success it computes an intersection distance, derives a split-time delta (or -1.0), optionally writes an encoded event, allocates a ring-buffer slot, encodes a progress-bar event, and finalizes the lap/split via LapCompletion. Called from TimerFrameRateThrottle (004D3740).
    // GUARD: Early abort: if this[44] (float at offset 0xB0) exceeds 10.0, return without processing the event [field:this:0x000000B0, source:raw]
    // CALL: Read the flag-property bitmask: FlagPropertyGetter(&a2, 2048) overlays a2 with the value of the object flag field (offset 0x32C8) that selects the event type [callee:0x0054C150, field:obj:0x000032C8, source:raw]
    // GUARD: Event-type state routing: switch on the filtered a2 — case 0 requires this[3]==2, case 1 requires this[3]==0, case 2 requires this[3]==1; on any mismatch return without recording [field:this:0x0000000C, guard:0, guard:1, guard:2, source:raw]
    // CALL: Validation gate: sub_4BC340(this) must return nonzero before any event data is produced [callee:0x004BC340, source:raw]
    // CALL: Intersection distance: RayTriangleIntersectionWithBarycentricCoordinate(v3) returns the lap/split distance into v7 [callee:0x004EFBD0, source:raw]
    // CALCULATION: Split-time delta: when this[24] == 2 use v6 = intersection distance - this[25] (previous split time), otherwise set v6 = -1.0 [guard:3, field:this:0x00000060, field:this:0x00000064, source:raw]
    // GUARD: Recording gate: if the parent container flag at +13000 is clear and dword_8AD238 is set, write the encoded event via EncodedDataWriterWithXOR(a2, v7) [field:this:0x00000000, global:0x008AD238, callee:0x004D5900, source:raw]
    // STATE_TRANSITION: Ring-buffer slot allocation: when dword_83EE60 >= 1023 reuse the current write pointer dword_8AAE64, otherwise increment dword_83EE60 and advance dword_8AAE64 by 432 [global:0x0083EE60, global:0x008AAE64, source:raw]
    // CALL: Encode the progress-bar event: ProgressBarEventEncode(slot, 4, 8, 8, this[1], v7, a2 == 0) [callee:0x004B33B0, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write the event payload into the slot: float delta v6 at +8, event type a2 as a word at +12, and the word at this[4] (event parameter 2 low word) at +14 [field:this:0x00000008, source:raw]
    // CALL: Finalize the lap/split record: LapCompletion(v6, intersection distance, a2, this[2]) [callee:0x004BC4E0, field:this:0x00000008, source:raw]
    // CALL: Invoked by TimerFrameRateThrottle (004D3740) from the timing/frame path [caller:0x004D3740, source:raw]

    // Conservative worker pseudocode:
    //   if (this[44] > 10.0) return;
    //   FlagPropertyGetter(&a2, 2048);
    //   switch (a2) {
    //     case 0: if (this[3] != 2) return; break;
    //     case 1: if (this[3] != 0) return; break;
    //     case 2: if (this[3] != 1) return; break;
    //   }
    //   if (sub_4BC340(this)) {
    //     v7 = RayTriangleIntersectionWithBarycentricCoordinate(v3);
    //     v6 = (this[24] == 2) ? v7 - this[25] : -1.0;
    //     if (*(_DWORD*)*this + 13000 == 0 && dword_8AD238)
    //       EncodedDataWriterWithXOR(a2, v7);
    //     if (dword_83EE60 < 1023) { ++dword_83EE60; dword_8AAE64 += 432; }
    //     v5 = dword_8AAE64;
    //     ProgressBarEventEncode(v5, 4, 8, 8, this[1], v7, a2 == 0);
    //     *(float*)(v5 + 8) = v6;
    //     *(_WORD*)(v5 + 12) = a2;
    //     *(_WORD*)(v5 + 14) = *((_WORD*)this + 4);
    //     LapCompletion(v6, v7, a2, this[2]);
    //   }
    // UNRESOLVED: dbl_59EB48 appears in the packet global list but never in the raw source; a fill labels it a ride-height threshold, yet the raw source compares the literal 10.0, so the binding is not verifiable
    // UNRESOLVED: The default (unlisted) switch case of the event-type selector falls through to sub_4BC340 with no state check; the meaning of a2 values outside 0..2 is unstated
}
