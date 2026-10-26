// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D88B0
// Canonical corpus name: IteratorCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IteratorCheck_004d88b0.c

void UnknownObject::advanceIterator()
{
    // Advances a sequential iterator: reads the current index from this[0]; if it is not -1, resolves the entry object at this[this[0]+4] and calls its vtable slot +0x14 (offset 20) advance/done-check method; when that method returns 1 the index is reset to -1 (iteration complete). Returns the advance method result, or the raw index (-1 sentinel) when no iteration is active.
    // ASSIGNMENT: Load the current iterator index from this[0] into result. [field:this:0x00000000, source:raw]
    // GUARD: Guard on this[0] != -1: the advance path runs only while an active index is present; otherwise the function returns immediately. [guard:0, field:this:0x00000000]
    // CALL: Indirect __thiscall through the entry object's vtable slot +0x14 (offset 20); the entry object is resolved as this[this[0]+4]. [source:raw, function:0x004D88B0]
    // STATE_TRANSITION: When the advance/done-check method returns 1, reset this[0] to -1, marking the iteration complete. [field:this:0x00000000, source:raw]
    // RETURN: Return the advance method result when iteration is active; otherwise return the untouched index (the -1 sentinel). [source:raw]

    // Conservative worker pseudocode:
    //   result = this->index;                         // this[0]
    //   if (this->index != -1) {
    //       entry = this[this->index + 4];            // entry object at current position
    //       result = entry->vtbl_method_0x14(entry);  // advance / done-check
    //       if (result == 1) this->index = -1;
    //   }
    //   return result;
    // UNRESOLVED: Identity of the vtable slot +0x14 method and the object type behind this[this[0]+4] are unknown; the semantics of return value 1 (iteration complete) are inferred from the reset branch only.
    // UNRESOLVED: The relationship between this[0] and the this[0]+4 element index (indexed table of entry objects) is inferred from the raw source and not independently confirmed.
    // UNRESOLVED: The only known caller is CarSelectionStateMachine (0x00434460).
}
