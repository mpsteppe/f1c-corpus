// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048F1A0
// Canonical corpus name: sub_48F1A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_48F1A0_0048f1a0.c

void UnknownObject::UITileGridCursorInputHandler()
{
    // UI tile-grid cursor input handler: skips all processing when the byte getter ByteFieldGetterAt100 is non-zero. Otherwise reads the two-axis cursor position from a sub-object via DualFieldRead, flags the cursor as acknowledged, and records whether it is inside an outer pass-through rectangle. When the interaction state (this[65], offset 0x104) is not the disabled value 4, tests the cursor against two hover regions (setting state 2 or 3, resetting a sub-index and dispatching DecrementCounterWithClamp or sub_48FB30), refreshes the grid via UITileGrid, then tests an activation region: if the cursor is inside and the activation index this[92] is non-negative, stores it into this[93] and dispatches the vtable + 44 virtual. Ends by dispatching the state virtual at vtable + 64 with the current state and the finalize virtual at vtable + 152, returning 0.
    // GUARD: If ByteFieldGetterAt100 (byte field at offset 100) returns non-zero, skip all input processing and return 0. [callee:0x00486710, source:raw]
    // CALL: DualFieldRead(this[16], &v9, &v8) reads the cursor X/Y coordinates from the sub-object pointer at offset 0x40, sourced from the sub-object offsets 0x2C and 0x40. [callee:0x00498880, field:this:0x00000040, field:obj:0x0000002C, field:obj:0x00000040, source:raw]
    // ASSIGNMENT: Set the acknowledgement byte at offset 0x17D to 1. [field:this:0x0000017D, source:raw]
    // STATE_TRANSITION: If the cursor is inside the outer pass-through rectangle (X between 0x128 and 0x12C, Y between 0x148 and 0x14C), set the flag byte at offset 0x17E to 1. [field:this:0x00000128, field:this:0x0000012C, field:this:0x00000148, field:this:0x0000014C, field:this:0x0000017E, source:raw]
    // GUARD: The interaction state at offset 0x104 must not equal the disabled value 4 for region hover/activation processing to run. [guard:0, field:this:0x00000104, source:raw]
    // STATE_TRANSITION: If the cursor is inside region 1 (X between 0x110 and 0x114, Y between 0x130 and 0x134), set the state at 0x104 to 2, dispatch DecrementCounterWithClamp with -1, and reset the sub-index at 0x10C to 0. [field:this:0x00000110, field:this:0x00000114, field:this:0x00000130, field:this:0x00000134, field:this:0x00000104, field:this:0x0000010C, callee:0x0048FAF0, source:raw]
    // STATE_TRANSITION: If the cursor is inside region 2 (X between 0x118 and 0x11C, Y between 0x138 and 0x13C), set the state at 0x104 to 3, dispatch sub_48FB30 with -1, and reset the sub-index at 0x10C to 0. [field:this:0x00000118, field:this:0x0000011C, field:this:0x00000138, field:this:0x0000013C, field:this:0x00000104, field:this:0x0000010C, callee:0x0048FB30, source:raw]
    // CALL: Dispatch UITileGrid to refresh the tile grid layout. [callee:0x0048F870, source:raw]
    // STATE_TRANSITION: If the cursor is inside the activation region 3 (X between 0x120 and 0x124, Y between 0x140 and 0x144) and the activation index this[92] (offset 0x170) is non-negative, store it into this[93] (offset 0x174) and dispatch the virtual at vtable + 44 with argument 1. [field:this:0x00000120, field:this:0x00000124, field:this:0x00000140, field:this:0x00000144, field:this:0x00000170, field:this:0x00000174, field:this:0x00000000, source:raw]
    // CALL: Dispatch the state virtual at vtable + 64 with the current state value from offset 0x104. [field:this:0x00000000, field:this:0x00000104, source:raw]
    // CALL: Dispatch the finalize virtual at vtable + 152. [field:this:0x00000000, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int UITileGridCursorInputHandler(int* this) {
    //     if (ByteFieldGetterAt100(this)) return 0;
    //     int x, y;
    //     DualFieldRead(this[16], &y, &x);
    //     this->byte381 = 1;
    //     if (x > this[74] && x < this[75] && y > this[82] && y < this[83]) this->byte382 = 1;
    //     if (this[65] != 4) {
    //       if (x > this[68] && x < this[69] && y > this[76] && y < this[77]) {
    //         this[65] = 2; DecrementCounterWithClamp(this, -1); this[67] = 0;
    //       }
    //       if (x > this[70] && x < this[71] && y > this[78] && y < this[79]) {
    //         this[65] = 3; sub_48FB30(this, -1); this[67] = 0;
    //       }
    //       UITileGrid(this);
    //     }
    //     if (x > this[72] && x < this[73] && y > this[80] && y < this[81]) {
    //       if (this[92] >= 0) { this[93] = this[92]; (*this + 44)(this, 1); }
    //     }
    //     (*this + 64)(this, this[65]);
    //     (*this + 152)(this);
    //     return 0;
    //   }
    // UNRESOLVED: Sub-object offset 0x98 is listed in the packet fields but is not directly read by this function's raw body (it is read inside DualFieldRead); its role is unknown.
    // UNRESOLVED: The byte read by ByteFieldGetterAt100 is at this + 100 but has no packet field evidence ref; its identity is unresolved.
    // UNRESOLVED: The exact meaning of the states 2, 3 and 4 and of the counter operations in DecrementCounterWithClamp and sub_48FB30 is unresolved.
}
