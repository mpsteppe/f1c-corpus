// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048DF40
// Canonical corpus name: UIWidgetDragHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIWidgetDragHandler_0048df40.c

void UnknownObject::UIWidgetDragHandler()
{
    // Handles drag state transitions for a UI scroll region. Reads cursor position (x, y) via DualFieldRead and the current scroll state via ShortComputation_6720. When the cursor is inside the region defined by this+0x10C..0x110 (x) and this+0x11C..0x120 (y): if the state is 0, 6, or 7 it invokes the vtable method at offset 0x40 (64) with argument 3 (interpreted as start-drag), and if the state is 3, 8, or 9 it invokes the same vtable method with argument 0 (interpreted as stop-drag). Returns 0.
    // CALL: Calls DualFieldRead(&v6, &v7) to read the cursor position (x, y). [callee:0x00498880, source:raw]
    // CALL: Calls ShortComputation_6720(this) to retrieve the current drag/scroll state. [callee:0x00486720, function:0x0048DF40]
    // GUARD: If the current state is not 0, 6, or 7, skips the idle-region start-drag check and jumps to the active-state check (LABEL_9). [function:0x0048DF40, source:raw]
    // GUARD: Bounds check: cursor x must be greater than this+0x10C and less than this+0x110, and cursor y greater than this+0x11C and less than this+0x120. [field:this:0x0000010C, field:this:0x00000110, field:this:0x0000011C, field:this:0x00000120]
    // CALL: Invokes the vtable method at offset 0x40 (64) with argument 3 when the cursor enters the region while idle (state 0, 6, or 7); interpreted as start-drag. [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // GUARD: If the current state is 3, 8, or 9 and the cursor x/y are inside the same region, triggers the stop-drag path. [function:0x0048DF40, source:raw]
    // CALL: Invokes the vtable method at offset 0x40 (64) with argument 0; interpreted as stop-drag. [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // RETURN: Returns 0. [function:0x0048DF40, source:raw]

    // Conservative worker pseudocode:
    //   DualFieldRead(&cursor_x_slot, &cursor_y_slot);
    //   state = ShortComputation_6720(this);
    //   cursor_x = cursor_x_slot;
    //   in_region = cursor_x > this->field_0x10C && cursor_x < this->field_0x110 && cursor_y_slot > this->field_0x11C && cursor_y_slot < this->field_0x120;
    //   if ((state == 0 || state == 6 || state == 7) && in_region)
    //       vtable[0x40](this, 3);
    //   if ((state == 3 || state == 8 || state == 9) && in_region)
    //       vtable[0x40](this, 0);
    //   return 0;
    // UNRESOLVED: The semantics of the state values (0, 3, 6, 7, 8, 9) and of the vtable-argument literals 3 and 0 are not established by this packet; the start-drag/stop-drag reading is a DERIVED interpretation from the existing analysis fill.
}
