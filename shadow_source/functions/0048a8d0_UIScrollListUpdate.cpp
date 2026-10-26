// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048A8D0
// Canonical corpus name: UIScrollListUpdate
// Owner: UIScrollList [DERIVED]
// Raw source: functions/UIScrollListUpdate_0048a8d0.c

void UIScrollList::UIScrollListUpdate()
{
    // Per-frame update for a UI scroll list. Reads two fields via DualFieldRead, recomputes the animation counter at this+0x148 from the value behind this+0x40 through FunctionCallWrapper_8940, then invokes the vtable refresh method at obj+0x2C with argument 1. When the byte flag at this+0x146 is set and the content dword at this+0x160 is greater than 0, clamps the pixel scroll position at this+0x150 into the range bounded by the vtable dimension getters at obj+0x1C (lower) and obj+0x24 (upper) and the offset at this+0x15C, then calls ShortComputation_9ee0. Finally, when the counter at this+0x148 exceeds 0.25 (source also shows a redundant comparison against 0.2), dispatches DecrementCounterVirtualCall if the byte flag at this+0x144 is set, or UINavigationAdvanceHandler if the byte flag at this+0x145 is set; otherwise returns 0.
    // CALL: DualFieldRead(v8, &v7) reads two fields into the locals v8 and v7, providing the timing/position inputs for the update. [callee:0x00498880, source:raw]
    // ASSIGNMENT: this+0x148 = FunctionCallWrapper_8940(this+0x40): recompute the animation timer/counter from the argument field behind this+0x40. [callee:0x00498940, field:this:0x00000040, field:this:0x00000148, source:raw]
    // CALL: Invoke the vtable refresh method at obj+0x2C (vtable pointer read from this+0x0) with argument 1. [field:this:0x00000000, field:obj:0x0000002C, source:raw]
    // GUARD: Run the scroll-position clamp only when the byte flag at this+0x146 is set AND the content dword at this+0x160 is greater than 0. [guard:0, field:this:0x00000146, field:this:0x00000160, source:raw]
    // CALL: Call the vtable method at obj+0x1C (offset 28) which returns the lower-bound dimension used in the clamp. [field:obj:0x0000001C, source:raw]
    // CALCULATION: this+0x150 = v7 - this+0x15C/2 - v2; when the result is negative, this+0x150 is reset to 0 (lower clamp). [field:this:0x00000150, field:this:0x0000015C, source:raw]
    // CALL: Call the vtable method at obj+0x24 (offset 36) which returns the upper-bound dimension used in the clamp. [field:obj:0x00000024, source:raw]
    // CALCULATION: Clamp this+0x150 so it does not exceed (vtable+0x24 result) - this+0x15C - (vtable+0x1C result), recomputing the upper bound. [field:this:0x00000150, field:this:0x0000015C, source:raw]
    // CALL: ShortComputation_9ee0(this) runs the follow-up short computation after the clamp. [callee:0x00489EE0, source:raw]
    // GUARD: Proceed to the navigation dispatch when the counter at this+0x148 is greater than 0.25; the source shows a second, redundant comparison against 0.2. The packet lists flt_59E7E8 and flt_59E7F8 as read globals, plausibly the constant pool behind these two thresholds. [global:0x0059E7E8, global:0x0059E7F8, field:this:0x00000148, source:raw]
    // GUARD: When the byte flag at this+0x144 is set, call DecrementCounterVirtualCall(this) and return 0 (scroll-backward dispatch). [callee:0x00489500, field:this:0x00000144, source:raw]
    // GUARD: Otherwise when the byte flag at this+0x145 is set, call UINavigationAdvanceHandler(this) (scroll-forward dispatch). [callee:0x00489530, field:this:0x00000145, source:raw]
    // RETURN: Return 0 from the update tick. [source:raw]

    // Conservative worker pseudocode:
    //   int UIScrollListUpdate(void* this) {
    //     DualFieldRead(v8, &v7);
    //     this[0x148] = FunctionCallWrapper_8940(this[0x40]);
    //     (obj->vtable[0x2C / 4])(this, 1);
    //     if (((byte*)this)[0x146] && *(int*)((char*)this + 0x160) > 0) {
    //       v2 = (obj->vtable[0x1C / 4])(this);
    //       this[0x150] = v7 - *(int*)((char*)this + 0x15C) / 2 - v2;
    //       if (this[0x150] < 0)
    //         this[0x150] = 0;
    //       v4 = (obj->vtable[0x24 / 4])(this) - *(int*)((char*)this + 0x15C);
    //       if (this[0x150] > v4 - v2) {
    //         v5 = (obj->vtable[0x24 / 4])(this) - *(int*)((char*)this + 0x15C);
    //         this[0x150] = v5 - v2;
    //       }
    //       ShortComputation_9ee0(this);
    //     }
    //     if (this[0x148] > 0.25 && this[0x148] > 0.2) {
    //       if (((byte*)this)[0x144]) {
    //         DecrementCounterVirtualCall(this);
    //         return 0;
    //       }
    //       if (((byte*)this)[0x145])
    //         UINavigationAdvanceHandler(this);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The exact mapping of globals flt_59E7E8 / flt_59E7F8 to the inline literals 0.25 and 0.2 in the raw source is inferred, not proven by the packet.
    // UNRESOLVED: The semantic roles of v7/v8 read by DualFieldRead and of this+0x40 as an animation argument are DERIVED from the surrounding arithmetic, not named by any evidence.
    // UNRESOLVED: The roles of vtable slots obj+0x1C / obj+0x24 (dimension getters) and obj+0x2C (refresh) come from the existing analysis, not from named semantic evidence.
    // UNRESOLVED: The object type UIScrollList is DERIVED from the ABI name UI_Scroll_List_Update (LEGACY trust) and the canonical function name; it is not runtime-proven.
}
