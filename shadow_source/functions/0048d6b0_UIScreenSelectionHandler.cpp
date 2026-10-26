// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D6B0
// Canonical corpus name: UIScreenSelectionHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIScreenSelectionHandler_0048d6b0.c

void UnknownObject::UIScreenSelectionHandler()
{
    // Handles a UI screen selection. Retrieves the selected screen object via FieldGetterAt0x1570 applied to the object pointer stored at this+0x40 and caches it at this+0xEC. If the screen object is non-null, it reads the screen's path string (at screen+192, falling back to the global byte_5EA438 when the pointer is null), compares it with the stored reference through UIStringComparison, and emits a content-changed notification via virtual slot +44 with argument 1. Returns 0.
    // CALL: Retrieves the selected screen object by calling FieldGetterAt0x1570 on the object pointer stored at this+0x40 [callee:0x00495790, field:this:0x00000040, source:raw]
    // ASSIGNMENT: Caches the retrieved screen object at this[59] (this+0xEC) [field:this:0x000000EC, source:raw]
    // GUARD: When the retrieved screen object is null, the comparison and notification path is skipped and the function returns 0 [source:raw]
    // CALCULATION: Reads the screen object's path string pointer at screen+192; when that pointer is null it is replaced by the fallback global byte_5EA438 [source:raw]
    // ASSIGNMENT: Uses the global byte_5EA438 as the default screen path when the screen object's own path string is null [global:0x005EA438, source:raw]
    // CALL: Compares the screen path against the stored reference by calling UIStringComparison on this [callee:0x00488B40, source:raw]
    // CALL: Emits the content-changed notification through virtual slot +44 of the object pointed to by this (slot at obj+0x2C), passing argument 1 [field:obj:0x0000002C, field:this:0x00000000, source:raw]
    // RETURN: Returns constant 0 to the caller [source:raw]

    // Conservative worker pseudocode:
    //   screen = FieldGetterAt0x1570(*(this + 64));
    //   this[0xEC/4] = screen;
    //   if (screen) {
    //     path = *(char **)(screen + 192);
    //     if (!path) path = byte_5EA438;
    //     UIStringComparison(this, path);
    //     emit virtual slot +44 (this, 1);
    //   }
    //   return 0;
    // UNRESOLVED: The target of the virtual slot +44 dispatch is not identified; it is an indirect vtable call
    // UNRESOLVED: The semantics of UIStringComparison and what it does with the compared path are not established by this packet
    // UNRESOLVED: The screen object layout (path string at screen+192) is read from a foreign object not covered by this function's field list
    // UNRESOLVED: byte_5EA438 is a read-only global used as a fallback string, but its content is not available in this packet
}
