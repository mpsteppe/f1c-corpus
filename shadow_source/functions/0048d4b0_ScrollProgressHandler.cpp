// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D4B0
// Canonical corpus name: ScrollProgressHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScrollProgressHandler_0048d4b0.c

void UnknownObject::ScrollProgressHandler()
{
    // Updates the scroll-bar thumb position for a UI scroll area. Gets the mutable scroll-value pointer through vtable entry +180, computes the scroll range span from this[62] - this[61], and when the pointer is valid and the span is positive normalizes the current scroll value to a 0..1 progress ratio (reading the value as int or float depending on the byte flag at this+0xF0). The progress is multiplied by the area span (vtable +32 result minus vtable +24 result) and converted by CRTFtol to a thumb pixel position; when it differs from the stored position this[56], the control signals a content change (vtable +44), stores the new position, runs ShortComputation_8970 and refreshes through vtable +176. When the range is empty the thumb is reset to 0.0 via the vtable +56 call and refreshed.
    // CALL: Obtain the mutable scroll-value pointer: call vtable entry at *(this)+180 (field obj+0xB4) and store the result in v2. [field:this:0x00000000, field:obj:0x000000B4, source:raw]
    // CALCULATION: Compute the scroll range span v8 = this[62] - this[61] (fields this+0xF8 minus this+0xF4). [field:this:0x000000F8, field:this:0x000000F4, source:raw]
    // GUARD: Range guard: only proceed when v2 is non-null and v8 > 0.0; otherwise take the zeroed-thumb path. [source:raw]
    // CALCULATION: Read the current scroll value as double: when the byte flag at this+0xF0 is set read *v2 as int, otherwise read *v2 as float; then normalize v9 = (value - this[61]) / v8. [field:this:0x000000F0, field:this:0x000000F4, source:raw]
    // CALCULATION: Compute the total area span v10 = (result of vtable +32, field obj+0x20) - (result of vtable +24, field obj+0x18). [field:obj:0x00000020, field:obj:0x00000018, source:raw]
    // CALCULATION: Convert progress to a thumb pixel position: v5 = CRTFtol(v10 * v9 + 0.5). [callee:0x00587BDC, source:raw]
    // GUARD: When the computed position differs from the stored thumb position this[56] (field this+0xE0): signal a content change via vtable +44 (field obj+0x2C) with argument 1, store v5 into this[56], run ShortComputation_8970(this), then refresh via vtable +176 (field obj+0xB0). [field:this:0x000000E0, field:obj:0x0000002C, callee:0x00488970, field:obj:0x000000B0, source:raw]
    // ASSIGNMENT: Zeroed-thumb path: reset this[56] (field this+0xE0) to 0.0 and call vtable entry at *(this)+56 with (this, 1) to propagate the reset. [field:this:0x000000E0, field:this:0x00000000, source:raw]
    // CALL: Refresh the control through vtable +176 (field obj+0xB0) on the fall-through path. [field:obj:0x000000B0, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   ptr = (*(this+180))(this);
    //   span = this[62] - this[61];
    //   if (ptr && span > 0.0) {
    //     value = flag(this+0xF0) ? (double)*ptr : (double)*(float*)ptr;
    //     progress = (value - this[61]) / span;
    //     total = (*(this+32))(this) - (*(this+24))(this);
    //     pos = CRTFtol(total * progress + 0.5);
    //     if (pos != this[56]) {
    //       (*(this+44))(this, 1);
    //       this[56] = pos;
    //       ShortComputation_8970(this);
    //       (*(this+176))(this);
    //     }
    //   } else {
    //     this[56] = 0.0;
    //     (*(this+56))(this, 1);
    //   }
    //   (*(this+176))(this);
    //   return 0;
    // UNRESOLVED: The read-only globals flt_59E440 and flt_59E450 are listed as accessed fields but are not directly referenced in the raw source; the existing analysis labels them ZeroThreshold (~0.0f) and DegreesToRadians (DERIVED) and they likely back the 0.0 / 0.5 constants, but that mapping is not evidenced by the packet and is not adopted here.
    // UNRESOLVED: The vtable call at *(this)+56 (used only in the zeroed-thumb path) has no dedicated field evidence reference; it is described from the raw source only.
    // UNRESOLVED: The identity of the scroll-area class and of the objects backing vtable entries +24/+32/+44/+56/+176/+180 is not evidenced by the packet.
    // UNRESOLVED: The legacy ABI name 'Scroll_Progress_Handler' (abi:lead) is consistent with the proposed name.
}
