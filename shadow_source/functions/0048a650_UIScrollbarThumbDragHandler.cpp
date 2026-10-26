// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048A650
// Canonical corpus name: UIScrollbarThumbDragHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIScrollbarThumbDragHandler_0048a650.c

void UnknownObject::UIScrollbarThumbDragHandler()
{
    // UI scrollbar input handler: reads a two-axis input position via DualFieldRead, clears the three interaction flags, then classifies the cursor against scrollbar track and arrow-zone boundaries obtained through virtual getters. Within the track, the cursor lands in the scroll-up arrow zone, the scroll-down/thumb zone, the page-up zone, the thumb area, or the page-down zone, each setting a flag and dispatching the matching navigation helper. Outside the track, when content navigation is enabled, computes a target content index via sub_489F40, walks the content item linked list, and updates the displayed strings via StringReverseCopyLookup and a content update virtual. Ends by dispatching a state-set virtual (1, 2, or 0) and a finalize virtual.
    // CALL: DualFieldRead(&v19, &v18) reads the two-axis input position (cursor X and Y). [callee:0x00498880, source:raw]
    // CALL: Dispatch the virtual method at vtable + 44 on this with argument 1 (UI enter/refresh). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear the scroll-up flag, scroll-down flag and thumb-drag flag at offsets 0x144, 0x145 and 0x146. [field:this:0x00000144, field:this:0x00000145, field:this:0x00000146, source:raw]
    // CALCULATION: Compute the track end boundary: use the virtual getter at vtable + 32 result, or fall back to this[4] (offset 0x10) when the getter returns non-positive. [field:this:0x00000010, field:this:0x00000000, source:raw]
    // CALCULATION: Read the track start boundary via the virtual getter at vtable + 24; these boundary values derive from the sub-object's track geometry fields at offsets 0x18 and 0x1C. [field:obj:0x00000018, field:obj:0x0000001C, field:this:0x00000000, source:raw]
    // GUARD: If the X input is beyond the track start and within the track end, the cursor is inside the scrollbar track. [source:raw]
    // CALCULATION: Read the scroll-up arrow zone boundary via the virtual getter at vtable + 28, sourced from sub-object offset 0x20. [field:obj:0x00000020, source:raw]
    // CALCULATION: Read the scroll-down/thumb zone boundary via the virtual getter at vtable + 36, sourced from sub-object offsets 0x24 and 0x2C. [field:obj:0x00000024, field:obj:0x0000002C, source:raw]
    // STATE_TRANSITION: If the Y input is at or beyond the thumb zone boundary, set the scroll-down flag at 0x145 and dispatch UINavigationAdvanceHandler. [field:this:0x00000145, callee:0x00489530, source:raw]
    // STATE_TRANSITION: If the Y input falls between the thumb top (this[84] at offset 0x150 plus the track start) and the thumb bottom (plus thumb size this[87] at offset 0x15C), set the thumb-drag flag at 0x146. [field:this:0x00000150, field:this:0x0000015C, field:this:0x00000146, source:raw]
    // STATE_TRANSITION: If the Y input is above the thumb top, dispatch StateUpdateWithDecrement followed by FloatToIntConversion. [callee:0x00489560, callee:0x00489E90, source:raw]
    // STATE_TRANSITION: If the Y input is below the thumb bottom, dispatch sub_4895B0 followed by FloatToIntConversion. [callee:0x004895B0, callee:0x00489E90, source:raw]
    // STATE_TRANSITION: If the Y input is above the up-arrow zone boundary, set the scroll-up flag at 0x144 and dispatch DecrementCounterVirtualCall. [field:this:0x00000144, callee:0x00489500, source:raw]
    // GUARD: Outside the track, proceed with content navigation only when the byte at offset 0xE0 is set and this[86] (offset 0x158) is non-zero. [field:this:0x000000E0, field:this:0x00000158, source:raw]
    // CALL: sub_489F40(this, v18, 1) computes the target content index; store the result into this[90] at offset 0x168. [callee:0x00489F40, field:this:0x00000168, source:raw]
    // LOOP: Walk the content item linked list starting at this[36] (offset 0x90) following the next-pointer field, decrementing the target index until it reaches zero or the list ends. [field:this:0x00000090, source:raw]
    // CALL: Look up and copy the content string via StringReverseCopyLookup using this[40] (offset 0xA0) and the selected item string, falling back to the global byte_5EA438 for null pointers. [field:this:0x000000A0, global:0x005EA438, callee:0x0049A490, source:raw]
    // CALL: Dispatch the content update virtual at vtable + 168 with the four sub-object string pointers (v9[40], v9[42] at offset 0xA8, v9[44], v9[46]), each falling back to the global byte_5EA438 when null. [field:obj:0x000000A8, global:0x005EA438, field:this:0x00000000, source:raw]
    // CALL: Dispatch the state-set virtual at vtable + 64 with argument 1 when the scroll-up flag is set, 2 when the scroll-down flag is set, otherwise 0. [field:this:0x00000144, field:this:0x00000145, field:this:0x00000000, source:raw]
    // CALL: Dispatch the finalize virtual at vtable + 152 and return its result. [field:this:0x00000000, source:raw]
    // RETURN: Return the result of the finalize virtual at vtable + 152. [source:raw]

    // Conservative worker pseudocode:
    //   int UIScrollbarThumbDragHandler(int* this) {
    //     int x, y;
    //     DualFieldRead(&y, &x);
    //     (*this + 44)(this, 1);
    //     this->byte324 = 0; this->byte325 = 0; this->byte326 = 0;
    //     int trackEnd = (*this + 32)(this);
    //     if (trackEnd <= 0) trackEnd = (*this + 32)(this); else trackEnd = this[4];
    //     int trackStart = (*this + 24)(this);
    //     if (y > trackStart && y <= trackEnd) {
    //       int upZone = (*this + 28)(this);
    //       int thumbZone = (*this + 36)(this);
    //       if (x >= upZone) {
    //         if (x >= thumbZone) { this->byte325 = 1; UINavigationAdvanceHandler(this); }
    //         else if (this[87]) {
    //           int thumbTop = this[84] + (*this + 28)(this);
    //           if (x < thumbTop) { StateUpdateWithDecrement(this); FloatToIntConversion(this); }
    //           else if (x > thumbTop + this[87]) { sub_4895B0(this); FloatToIntConversion(this); }
    //           else this->byte326 = 1;
    //         }
    //       } else { this->byte324 = 1; DecrementCounterVirtualCall(this); }
    //       goto done;
    //     }
    //     if (!this->byte224 || !this[86]) goto done;
    //     this[90] = sub_489F40(this, x, 1);
    //     _DWORD* node = this[36];
    //     int target = this[90];
    //     if (target > 0) { while (node) { node = node[35]; if (--target <= 0) break; } }
    //     if (node) {
    //       StringReverseCopyLookup(this[40] ? this[40] : byte_5EA438, node[44] ? node[44] : byte_5EA438);
    //       (*this + 168)(this, node[44] ? node[44] : byte_5EA438, node[46] ? node[46] : byte_5EA438, node[40] ? node[40] : byte_5EA438, node[42] ? node[42] : byte_5EA438);
    //     } else {
    //       StringReverseCopyLookup(this[40] ? this[40] : byte_5EA438, byte_5EA438);
    //     }
    //   done:
    //     if (this->byte324) { (*this + 64)(this, 1); return (*this + 152)(this); }
    //     if (this->byte325) { (*this + 64)(this, 2); return (*this + 152)(this); }
    //     (*this + 64)(this, 0);
    //     return (*this + 152)(this);
    //   }
    // UNRESOLVED: Sub-object fields at obj offsets 0x40 and 0x98 are not directly referenced in this function's raw body; they are listed by the deterministic extraction and their exact roles remain unknown.
    // UNRESOLVED: this offsets 0x130, 0x138, 0x140, 0x148 and 0x1A8 are listed in the packet fields but are not read by this function's raw body; their purposes are unresolved.
    // UNRESOLVED: The string member slots v9[40], v9[44] and v9[46] have no corresponding packet field evidence refs, so their semantics are inferred only from the raw body.
}
