// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489600
// Canonical corpus name: UIMenuItemCreator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIMenuItemCreator_00489600.c

void UnknownObject::UIMenuItemCreator()
{
    // Creates and registers a new UI menu item: allocates a 232-byte object, sets its vtable, copies up to four text strings into it, inserts the item into the list controller, pops a list entry, then dispatches two controller vtable methods. Returns -1 when the required label string a2 is null, otherwise 0.
    // GUARD: Early-exit guard: if the required label string a2 is null, return -1 immediately without allocating. [source:raw]
    // CALL: Allocate the 232-byte item block via OperatorNewNhMallocWrapper(232). [callee:0x00587C03]
    // STATE_TRANSITION: When the allocation succeeded, initialize the object vtable through VTableSetWithFlag(v7); otherwise v8 stays null. [callee:0x00488F90]
    // CALL: Copy the label string a2 via StringCopyWithBufferRealloc(a2). [callee:0x00566650]
    // ASSIGNMENT: Resolve the fallback string v9: start with a3, and when a3 is null take this[46] (the list controller's stored fallback string pointer). [field:this:0x000000B8]
    // GUARD: When the fallback v9 is still null, substitute the global byte_5EA438 string. [global:0x005EA438]
    // CALL: Copy the resolved fallback string v9 via StringCopyWithBufferRealloc(v9). [callee:0x00566650]
    // GUARD: Conditional copy: when a4 is non-null, copy it via StringCopyWithBufferRealloc(a4). [callee:0x00566650]
    // GUARD: Conditional copy: when a5 is non-null, copy it via StringCopyWithBufferRealloc(a5). [callee:0x00566650]
    // CALL: Register the new item v8 into the list controller with flag a6 via sub_486340(this, v8, a6). [callee:0x00486340]
    // CALL: Pop an entry from the controller's internal list via PopListWithDestructor(this). [callee:0x00489480]
    // CALL: Dispatch the vtable method at offset 0x2C on the controller (this), passing argument 1. [field:this:0x00000000, field:obj:0x0000002C]
    // CALL: Dispatch the vtable method at offset 0xAC on the controller (this), passing the label string a2. [field:this:0x00000000, field:obj:0x000000AC]
    // RETURN: Return 0 on success. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_489600(this, a2, a3, a4, a5, a6) {
    //     if (!a2) return -1;
    //     v8 = VTableSetWithFlag(OperatorNewNhMallocWrapper(232));
    //     StringCopyWithBufferRealloc(a2);
    //     v9 = a3 ? a3 : (this[46] ? this[46] : byte_5EA438);
    //     StringCopyWithBufferRealloc(v9);
    //     if (a4) StringCopyWithBufferRealloc(a4);
    //     if (a5) StringCopyWithBufferRealloc(a5);
    //     sub_486340(this, v8, a6);
    //     PopListWithDestructor(this);
    //     (*this->vtable[0x2C / 4])(this, 1);
    //     (*this->vtable[0xAC / 4])(this, a2);
    //     return 0;
    //   }
    // UNRESOLVED: The destination object of the four StringCopyWithBufferRealloc calls is not visible in the raw source; they likely write into the newly created item v8, but that binding is inferred.
    // UNRESOLVED: Semantics of the two vtable dispatches (offsets 0x2C and 0xAC) depend on the owning list-controller class, which is not identified.
    // UNRESOLVED: Why PopListWithDestructor runs in the middle of item construction is unclear.
}
